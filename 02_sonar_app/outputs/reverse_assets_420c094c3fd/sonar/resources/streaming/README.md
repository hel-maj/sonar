Portable streaming binaries can be placed here before building a release.

Supported files:
- `ffmpeg.exe`
- `ffmpeg*.zip` containing `ffmpeg.exe`
- `cloudflared.exe`
- `cloudflared*.zip` containing `cloudflared.exe`

At runtime Sonar copies or extracts these files into a per-session temp
directory and runs them from there. If files are not bundled, Sonar can
download portable copies into the same temp directory when the stream starts.
