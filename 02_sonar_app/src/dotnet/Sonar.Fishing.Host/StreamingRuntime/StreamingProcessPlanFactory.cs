using System.Globalization;

namespace Sonar.Fishing.Host.StreamingRuntime;

internal static class StreamingProcessPlanFactory
{
    internal static StreamingProcessRequest CreateEncoder(
        StreamingExecutableSet executables,
        StreamingCaptureDescriptor capture,
        StreamingNetworkDescriptor network,
        StreamingEncodingProfile encoding)
    {
        ArgumentNullException.ThrowIfNull(executables);
        ArgumentNullException.ThrowIfNull(capture);
        ArgumentNullException.ThrowIfNull(network);
        ArgumentNullException.ThrowIfNull(encoding);
        ValidateCapture(capture);

        var frameRate = encoding.FramesPerSecond.ToString(CultureInfo.InvariantCulture);
        var keyFrameInterval = checked(encoding.FramesPerSecond * 2)
            .ToString(CultureInfo.InvariantCulture);
        var size = $"{encoding.Width.ToString(CultureInfo.InvariantCulture)}:" +
            encoding.Height.ToString(CultureInfo.InvariantCulture);
        var arguments = new List<string>
        {
            "-hide_banner",
            "-loglevel",
            "warning",
            "-nostats",
            "-y",
        };
        arguments.AddRange(capture.InputArguments);
        arguments.AddRange(
        [
            "-f",
            capture.InputFormat,
            "-framerate",
            frameRate,
            "-i",
            capture.InputSpecifier,
            "-an",
            "-c:v",
            "libx264",
            "-preset",
            "veryfast",
            "-tune",
            "zerolatency",
            "-vf",
            $"scale={size}:force_original_aspect_ratio=decrease," +
                $"pad={size}:(ow-iw)/2:(oh-ih)/2",
            "-r",
            frameRate,
            "-g",
            keyFrameInterval,
            "-keyint_min",
            keyFrameInterval,
            "-sc_threshold",
            "0",
            "-b:v",
            encoding.Bitrate,
            "-maxrate",
            encoding.Bitrate,
            "-bufsize",
            DoubleBitrate(encoding.Bitrate),
            "-f",
            "hls",
            "-hls_time",
            "2",
            "-hls_list_size",
            "6",
            "-hls_flags",
            "delete_segments+independent_segments+omit_endlist",
            network.MediaPlaylistPath,
        ]);

        return new StreamingProcessRequest(
            StreamingProcessRole.Encoder,
            executables.EncoderPath,
            arguments,
            GracefulStopInput: "q",
            CaptureDiagnosticOutput: false);
    }

    internal static StreamingProcessRequest CreateTunnel(
        StreamingExecutableSet executables,
        StreamingNetworkDescriptor network)
    {
        ArgumentNullException.ThrowIfNull(executables);
        ArgumentNullException.ThrowIfNull(network);
        return new StreamingProcessRequest(
            StreamingProcessRole.Tunnel,
            executables.TunnelPath,
            [
                "tunnel",
                "--no-autoupdate",
                "--url",
                network.LocalBaseUri.AbsoluteUri,
            ],
            GracefulStopInput: null,
            CaptureDiagnosticOutput: true);
    }

    private static void ValidateCapture(StreamingCaptureDescriptor capture)
    {
        if (string.IsNullOrWhiteSpace(capture.InputFormat) ||
            string.IsNullOrWhiteSpace(capture.InputSpecifier) ||
            capture.InputArguments is null ||
            capture.InputArguments.Any(string.IsNullOrEmpty))
        {
            throw new StreamingRuntimeException("streaming_capture_descriptor_invalid");
        }
    }

    private static string DoubleBitrate(string bitrate)
    {
        if (bitrate.Length < 2 || bitrate[^1] != 'k' ||
            !int.TryParse(
                bitrate.AsSpan(0, bitrate.Length - 1),
                NumberStyles.None,
                CultureInfo.InvariantCulture,
                out var numeric) ||
            numeric <= 0)
        {
            throw new StreamingRuntimeException("streaming_bitrate_invalid");
        }
        return $"{checked(numeric * 2).ToString(CultureInfo.InvariantCulture)}k";
    }
}
