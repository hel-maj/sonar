using System.IO;
using System.Net;
using System.Net.Http;

namespace Sonar.Fishing.Host.UpdateRuntime;

internal sealed class HttpReleasePayloadSource : IReleasePayloadSource
{
    private readonly HttpClient httpClient;

    internal HttpReleasePayloadSource(HttpClient httpClient)
    {
        this.httpClient = httpClient ?? throw new ArgumentNullException(nameof(httpClient));
    }

    public async ValueTask<Stream> OpenReadAsync(
        ReleaseFileDescriptor descriptor,
        CancellationToken cancellationToken)
    {
        ArgumentNullException.ThrowIfNull(descriptor);
        using var request = new HttpRequestMessage(HttpMethod.Get, descriptor.DownloadUri);
        var response = await httpClient.SendAsync(
                request,
                HttpCompletionOption.ResponseHeadersRead,
                cancellationToken)
            .ConfigureAwait(false);
        try
        {
            if (response.StatusCode != HttpStatusCode.OK ||
                response.Content.Headers.ContentLength != descriptor.Bytes ||
                !IsSafeFinalUri(response.RequestMessage?.RequestUri))
            {
                throw new InvalidOperationException("release_payload_response_invalid");
            }

            var stream = await response.Content.ReadAsStreamAsync(cancellationToken)
                .ConfigureAwait(false);
            return new OwnedResponseStream(stream, response);
        }
        catch
        {
            response.Dispose();
            throw;
        }
    }

    private static bool IsSafeFinalUri(Uri? uri) =>
        uri is not null &&
        uri.IsAbsoluteUri &&
        string.Equals(uri.Scheme, Uri.UriSchemeHttps, StringComparison.OrdinalIgnoreCase) &&
        string.IsNullOrEmpty(uri.UserInfo) &&
        string.IsNullOrEmpty(uri.Fragment);

    private sealed class OwnedResponseStream : Stream
    {
        private readonly Stream inner;
        private readonly HttpResponseMessage response;
        private bool disposed;

        internal OwnedResponseStream(Stream inner, HttpResponseMessage response)
        {
            this.inner = inner;
            this.response = response;
        }

        public override bool CanRead => inner.CanRead;
        public override bool CanSeek => inner.CanSeek;
        public override bool CanWrite => false;
        public override long Length => inner.Length;
        public override long Position
        {
            get => inner.Position;
            set => inner.Position = value;
        }

        public override void Flush() => inner.Flush();
        public override int Read(byte[] buffer, int offset, int count) =>
            inner.Read(buffer, offset, count);
        public override long Seek(long offset, SeekOrigin origin) => inner.Seek(offset, origin);
        public override void SetLength(long value) => throw new NotSupportedException();
        public override void Write(byte[] buffer, int offset, int count) =>
            throw new NotSupportedException();
        public override ValueTask<int> ReadAsync(
            Memory<byte> buffer,
            CancellationToken cancellationToken = default) =>
            inner.ReadAsync(buffer, cancellationToken);

        protected override void Dispose(bool disposing)
        {
            if (disposing && !disposed)
            {
                inner.Dispose();
                response.Dispose();
                disposed = true;
            }
            base.Dispose(disposing);
        }

        public override async ValueTask DisposeAsync()
        {
            if (!disposed)
            {
                await inner.DisposeAsync().ConfigureAwait(false);
                response.Dispose();
                disposed = true;
            }
            GC.SuppressFinalize(this);
        }
    }
}
