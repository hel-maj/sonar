using System.IO;
using Sonar.Fishing.Host.EngineIntegration;
using Sonar.Fishing.Ipc.Contracts.V1;

namespace Sonar.Fishing.Host.Tests;

internal static class EngineCommandDispatchTests
{
    public static IReadOnlyList<TestCase> Create() =>
    [
        new(
            "engine_command_dispatch_pre_cancelled_write_reports_no_bytes",
            PreCancelledWriteReportsNoBytes),
        new(
            "engine_command_dispatch_started_write_failure_reports_ambiguous_bytes",
            StartedWriteFailureReportsAmbiguousBytes),
    ];

    private static void PreCancelledWriteReportsNoBytes()
    {
        using var stream = new MemoryStream();
        using var cancellation = new CancellationTokenSource();
        cancellation.Cancel();
        var dispatchState = new EngineCommandDispatchState();

        var failure = TestAssert.Throws<EngineCommandDispatchException>(
            () => OfflineEngineSessionProtocol.WriteEnvelopeWithDispatchReceiptAsync(
                    stream,
                    CreateEnvelope(),
                    dispatchState,
                    cancellation.Token)
                .AsTask().GetAwaiter().GetResult(),
            "Pre-cancelled pipe write did not return a typed dispatch failure");

        TestAssert.True(!failure.BytesMayHaveBeenWritten,
            "Pre-cancelled pipe write was reported as ambiguous");
        TestAssert.Equal(0L, stream.Length,
            "Pre-cancelled pipe write emitted bytes");
    }

    private static void StartedWriteFailureReportsAmbiguousBytes()
    {
        using var stream = new ThrowAfterWriteStartStream();
        var dispatchState = new EngineCommandDispatchState();

        var failure = TestAssert.Throws<EngineCommandDispatchException>(
            () => OfflineEngineSessionProtocol.WriteEnvelopeWithDispatchReceiptAsync(
                    stream,
                    CreateEnvelope(),
                    dispatchState,
                    CancellationToken.None)
                .AsTask().GetAwaiter().GetResult(),
            "Failed pipe write did not return a typed dispatch failure");

        TestAssert.True(failure.BytesMayHaveBeenWritten,
            "Started pipe write was not reported as ambiguous");
        TestAssert.Equal(1, stream.WriteCount,
            "Dispatch fixture did not cross exactly one write boundary");
    }

    private static Envelope CreateEnvelope() => new()
    {
        ResetFishingSessionStatisticsRequest =
            new ResetFishingSessionStatisticsRequest(),
    };

    private sealed class ThrowAfterWriteStartStream : Stream
    {
        public int WriteCount { get; private set; }

        public override bool CanRead => false;

        public override bool CanSeek => false;

        public override bool CanWrite => true;

        public override long Length => throw new NotSupportedException();

        public override long Position
        {
            get => throw new NotSupportedException();
            set => throw new NotSupportedException();
        }

        public override void Flush()
        {
        }

        public override int Read(byte[] buffer, int offset, int count) =>
            throw new NotSupportedException();

        public override long Seek(long offset, SeekOrigin origin) =>
            throw new NotSupportedException();

        public override void SetLength(long value) =>
            throw new NotSupportedException();

        public override void Write(byte[] buffer, int offset, int count)
        {
            WriteCount++;
            throw new OperationCanceledException("post_write_fixture");
        }

        public override Task WriteAsync(
            byte[] buffer,
            int offset,
            int count,
            CancellationToken cancellationToken)
        {
            WriteCount++;
            return Task.FromException(
                new OperationCanceledException("post_write_fixture"));
        }

        public override ValueTask WriteAsync(
            ReadOnlyMemory<byte> buffer,
            CancellationToken cancellationToken = default)
        {
            WriteCount++;
            return ValueTask.FromException(
                new OperationCanceledException("post_write_fixture"));
        }
    }
}
