param(
    [string]$Label = "",
    [double]$Duration = 30,
    [double]$Countdown = 5,
    [double]$AutoStopIdle = 5,
    [ValidateSet("AD", "Arrows")]
    [string]$LabelKeys = "AD"
)

$ErrorActionPreference = "Stop"
$Root = Split-Path -Parent $PSScriptRoot
$Python = Join-Path $Root ".venv\Scripts\python.exe"

if (-not (Test-Path $Python)) {
    $PythonCommand = Get-Command python -ErrorAction SilentlyContinue
    if ($null -eq $PythonCommand) {
        throw "Python was not found. Create .venv first with scripts\install_venv_offline.ps1."
    }
    $Python = $PythonCommand.Source
}

$OutDir = Join-Path $Root "logs\reeling_direction_probes"
$Arguments = @(
    "-m",
    "sonar.tools.probe_reeling_direction",
    "--duration",
    "$Duration",
    "--countdown",
    "$Countdown",
    "--auto-stop-idle",
    "$AutoStopIdle",
    "--label-keys",
    $LabelKeys.ToLowerInvariant(),
    "--out-dir",
    "$OutDir"
)
if ($Label) {
    $Arguments += @("--label", $Label)
}

Push-Location $Root
try {
    & $Python @Arguments
    exit $LASTEXITCODE
}
finally {
    Pop-Location
}
