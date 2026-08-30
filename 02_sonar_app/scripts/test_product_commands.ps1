[CmdletBinding()]
param()

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

$productRoot = (Resolve-Path -LiteralPath (Join-Path $PSScriptRoot "..")).Path
$manifestPath = Join-Path $productRoot "product-commands.json"
$readmePath = Join-Path $productRoot "README.md"

function Get-OptionalProperty(
    [object]$Object,
    [string]$Name,
    [object]$DefaultValue) {
    $property = $Object.PSObject.Properties[$Name]
    if ($null -eq $property) {
        return $DefaultValue
    }
    return $property.Value
}

function Assert-ExactSequence(
    [object[]]$Actual,
    [string[]]$Expected,
    [string]$Reason) {
    $actualValues = @($Actual)
    if ($actualValues.Count -ne $Expected.Count) {
        throw "${Reason}_count_invalid"
    }
    for ($index = 0; $index -lt $Expected.Count; $index++) {
        if ([string]$actualValues[$index] -cne $Expected[$index]) {
            throw "${Reason}_value_invalid:$index"
        }
    }
}

function Get-RequiredCommand([object]$Manifest, [string]$Id) {
    $matches = @($Manifest.commands | Where-Object { $_.id -ceq $Id })
    if ($matches.Count -ne 1) {
        throw "product_command_missing_or_duplicate:$Id"
    }
    return $matches[0]
}

function Resolve-ManifestPath([string]$Path) {
    $expanded = $Path.Replace("{productRoot}", $productRoot)
    if (-not [IO.Path]::IsPathRooted($expanded)) {
        $expanded = Join-Path $productRoot $expanded
    }
    return [IO.Path]::GetFullPath($expanded)
}

function Get-ScriptParameters([string]$ScriptPath) {
    $tokens = $null
    $errors = $null
    $ast = [Management.Automation.Language.Parser]::ParseFile(
        $ScriptPath,
        [ref]$tokens,
        [ref]$errors)
    if (@($errors).Count -ne 0 -or $null -eq $ast.ParamBlock) {
        throw "product_command_script_parse_failed:$ScriptPath"
    }
    $parameters = @{}
    foreach ($parameter in @($ast.ParamBlock.Parameters)) {
        $parameters[$parameter.Name.VariablePath.UserPath] = $parameter
    }
    return $parameters
}

function Assert-DeclaredScriptParameter(
    [hashtable]$Declared,
    [string]$Argument,
    [string]$ExpectedType,
    [string[]]$ExpectedOptions,
    [string]$Reason) {
    $name = $Argument.TrimStart("-")
    if (-not $Declared.ContainsKey($name)) {
        throw "${Reason}_script_parameter_missing:$Argument"
    }
    $parameter = $Declared[$name]
    if ($parameter.StaticType.FullName -cne $ExpectedType) {
        throw "${Reason}_script_parameter_type_invalid:$Argument"
    }
    if ($ExpectedOptions.Count -eq 0) {
        return
    }
    $validateSet = @($parameter.Attributes | Where-Object {
        $_.TypeName.Name -ceq "ValidateSet"
    })
    if ($validateSet.Count -ne 1) {
        throw "${Reason}_validate_set_missing:$Argument"
    }
    $actualOptions = @($validateSet[0].PositionalArguments | ForEach-Object {
        [string]$_.SafeGetValue()
    })
    Assert-ExactSequence $actualOptions $ExpectedOptions `
        "${Reason}_validate_set"
}

function Assert-CommandParameter(
    [object]$Command,
    [hashtable]$Declared,
    [hashtable]$Expected,
    [string]$Reason) {
    $matches = @($Command.parameters | Where-Object {
        $_.id -ceq $Expected.Id
    })
    if ($matches.Count -ne 1) {
        throw "${Reason}_parameter_missing_or_duplicate:$($Expected.Id)"
    }
    $parameter = $matches[0]
    if ($parameter.type -cne $Expected.Type -or
        $parameter.argument -cne $Expected.Argument -or
        [bool](Get-OptionalProperty $parameter "required" $false) -ne
            [bool]$Expected.Required) {
        throw "${Reason}_parameter_contract_invalid:$($Expected.Id)"
    }
    $actualDefault = Get-OptionalProperty `
        $parameter $Expected.DefaultProperty $null
    if ([string]$actualDefault -cne [string]$Expected.DefaultValue) {
        throw "${Reason}_parameter_default_invalid:$($Expected.Id)"
    }
    if ([string]::IsNullOrWhiteSpace([string]$parameter.label) -or
        [string]::IsNullOrWhiteSpace([string]$parameter.description)) {
        throw "${Reason}_parameter_copy_missing:$($Expected.Id)"
    }
    if ($Expected.Type -ceq "path") {
        if ((Get-OptionalProperty $parameter "pathKind" "") -cne "directory" -or
            [bool](Get-OptionalProperty $parameter "mustExist" $false) -ne
                [bool]$Expected.MustExist) {
            throw "${Reason}_path_contract_invalid:$($Expected.Id)"
        }
    }
    $actualOptions = @()
    if ($Expected.Options.Count -gt 0) {
        $actualOptions = @($parameter.options | ForEach-Object { [string]$_.value })
        Assert-ExactSequence $actualOptions $Expected.Options `
            "${Reason}_options:$($Expected.Id)"
    }
    Assert-DeclaredScriptParameter `
        $Declared `
        $Expected.Argument `
        $Expected.ScriptType `
        $Expected.Options `
        $Reason
}

function Assert-LocalAccessCommand(
    [object]$Manifest,
    [hashtable]$Expected) {
    $command = Get-RequiredCommand $Manifest $Expected.Id
    $reason = "product_command_$($Expected.Id)"
    if ($command.executable -cne "powershell.exe" -or
        $command.workingDirectory -cne "{productRoot}" -or
        [string]::IsNullOrWhiteSpace([string]$command.title) -or
        [string]::IsNullOrWhiteSpace([string]$command.description)) {
        throw "${reason}_shell_contract_invalid"
    }
    $scriptToken = "{productRoot}\scripts\$($Expected.Script)"
    $expectedArguments = @(
        "-NoProfile",
        "-ExecutionPolicy",
        "Bypass",
        "-File",
        $scriptToken
    ) + @($Expected.StaticArguments)
    Assert-ExactSequence @($command.arguments) $expectedArguments `
        "${reason}_arguments"

    $requiredPaths = @($command.requiredPaths)
    foreach ($required in @($Expected.RequiredPaths)) {
        if ($requiredPaths -cnotcontains $required) {
            throw "${reason}_required_path_missing:$required"
        }
    }
    foreach ($required in $requiredPaths) {
        if (-not (Test-Path -LiteralPath (Resolve-ManifestPath $required))) {
            throw "${reason}_required_path_invalid:$required"
        }
    }

    $scriptPath = Resolve-ManifestPath $scriptToken
    $declared = Get-ScriptParameters $scriptPath
    foreach ($staticArgument in @($Expected.StaticArguments)) {
        Assert-DeclaredScriptParameter `
            $declared $staticArgument `
            "System.Management.Automation.SwitchParameter" @() $reason
    }

    $expectedParameterIds = @($Expected.Parameters | ForEach-Object { $_.Id })
    Assert-ExactSequence @($command.parameters | ForEach-Object { $_.id }) `
        $expectedParameterIds "${reason}_parameters"
    foreach ($parameter in @($Expected.Parameters)) {
        Assert-CommandParameter $command $declared $parameter $reason
    }
    return $command
}

$manifestText = [IO.File]::ReadAllText($manifestPath, [Text.Encoding]::UTF8)
$manifest = $manifestText | ConvertFrom-Json
if ($manifest.schemaVersion -ne 1 -or $manifest.product -cne "fishing") {
    throw "product_command_manifest_identity_invalid"
}
$allIds = @($manifest.commands | ForEach-Object { [string]$_.id })
if (@($allIds | Sort-Object -Unique).Count -ne $allIds.Count) {
    throw "product_command_manifest_duplicate_id"
}

$bundlePath = "build\developer-full-access\bundle"
$localCommands = @(
    @{
        Id = "fishing-native-build-developer-full-access"
        Script = "build_developer_full_access.ps1"
        StaticArguments = @()
        RequiredPaths = @(
            "{productRoot}\scripts\build_developer_full_access.ps1",
            "{productRoot}\scripts\verify_developer_full_access.ps1"
        )
        Parameters = @(
            @{
                Id = "version"; Type = "text"; Argument = "-Version"
                Required = $true; DefaultProperty = "defaultValue"
                DefaultValue = "1.0.6-local"; ScriptType = "System.String"
                Options = @(); MustExist = $false
            },
            @{
                Id = "outputDirectory"; Type = "path"
                Argument = "-OutputDirectory"; Required = $true
                DefaultProperty = "defaultValue"; DefaultValue = $bundlePath
                ScriptType = "System.String"; Options = @(); MustExist = $false
            },
            @{
                Id = "skipOfflineTests"; Type = "bool"
                Argument = "-SkipOfflineTests"; Required = $false
                DefaultProperty = "defaultBoolean"; DefaultValue = $false
                ScriptType = "System.Management.Automation.SwitchParameter"
                Options = @(); MustExist = $false
            }
        )
    },
    @{
        Id = "fishing-native-verify-developer-full-access"
        Script = "run_developer_full_access.ps1"
        StaticArguments = @("-VerifyOnly")
        RequiredPaths = @(
            "{productRoot}\scripts\run_developer_full_access.ps1",
            "{productRoot}\scripts\admit_developer_full_access_launch.ps1"
        )
        Parameters = @(
            @{
                Id = "bundleDirectory"; Type = "path"
                Argument = "-BundleDirectory"; Required = $true
                DefaultProperty = "defaultValue"; DefaultValue = $bundlePath
                ScriptType = "System.String"; Options = @(); MustExist = $true
            }
        )
    },
    @{
        Id = "fishing-native-run-developer-full-access"
        Script = "run_developer_full_access.ps1"
        StaticArguments = @()
        RequiredPaths = @(
            "{productRoot}\scripts\run_developer_full_access.ps1",
            "{productRoot}\scripts\admit_developer_full_access_launch.ps1"
        )
        Parameters = @(
            @{
                Id = "bundleDirectory"; Type = "path"
                Argument = "-BundleDirectory"; Required = $true
                DefaultProperty = "defaultValue"; DefaultValue = $bundlePath
                ScriptType = "System.String"; Options = @(); MustExist = $true
            },
            @{
                Id = "wait"; Type = "bool"; Argument = "-Wait"
                Required = $false; DefaultProperty = "defaultBoolean"
                DefaultValue = $true
                ScriptType = "System.Management.Automation.SwitchParameter"
                Options = @(); MustExist = $false
            }
        )
    },
    @{
        Id = "fishing-native-developer-full-access-lifecycle"
        Script = "test_product_lifecycle.ps1"
        StaticArguments = @("-DeveloperFullAccess")
        RequiredPaths = @(
            "{productRoot}\scripts\test_product_lifecycle.ps1",
            "{productRoot}\scripts\release_common.ps1"
        )
        Parameters = @(
            @{
                Id = "bundleDirectory"; Type = "path"
                Argument = "-BundleDirectory"; Required = $true
                DefaultProperty = "defaultValue"; DefaultValue = $bundlePath
                ScriptType = "System.String"; Options = @(); MustExist = $true
            },
            @{
                Id = "durationSeconds"; Type = "enum"
                Argument = "-DurationSeconds"; Required = $true
                DefaultProperty = "defaultValue"; DefaultValue = "30"
                ScriptType = "System.Int32"; Options = @("30", "60", "120")
                MustExist = $false
            }
        )
    }
)

$resolvedCommands = @()
foreach ($expected in $localCommands) {
    $resolvedCommands += Assert-LocalAccessCommand $manifest $expected
}

$forbiddenCopy = [regex]::new(
    '(?i)(\u0434\u043e\u0441\u0442\u0443\u043f\u043d\p{L}*\s+' +
    '(?:\u0442\u043e\u043b\u044c\u043a\u043e\s+)?' +
    '\u043f\u043e\u0441\u043b\u0435\s+' +
    '(?:\u043f\u043e\u043b\u043d\u043e\u0433\u043e\s+)?' +
    '(?:\u043f\u0435\u0440\u0435\u0445\u043e\u0434\u0430|' +
    '\u043c\u0438\u0433\u0440\u0430\u0446\p{L}*)|' +
    '\b(?:offline|test|wpf|host|engine|manifest|hash(?:es)?|python|native|' +
    'internal|language)\b|c\+\+|c#|\.net|' +
    '\u043e\u0444\u043b\u0430\u0439\u043d|' +
    '\u0442\u0435\u0441\u0442\p{L}*)')
foreach ($command in $resolvedCommands) {
    $copy = @($command.title, $command.description)
    foreach ($parameter in @($command.parameters)) {
        $copy += @(
            [string]$parameter.label,
            [string](Get-OptionalProperty $parameter "description" ""))
    }
    foreach ($text in $copy) {
        if ($forbiddenCopy.IsMatch([string]$text)) {
            throw "product_command_internal_copy_exposed:$($command.id)"
        }
    }
}

$builderText = Get-Content -Raw -LiteralPath `
    (Join-Path $PSScriptRoot "build_developer_full_access.ps1")
if ($builderText -notmatch '(?m)^\s*DevelopmentUnsigned\s*=\s*\$true\s*$' -or
    $builderText -notmatch '(?m)^\s*DeveloperFullAccess\s*=\s*\$true\s*$' -or
    $builderText -notmatch 'verify_developer_full_access\.ps1') {
    throw "product_command_local_access_build_authority_invalid"
}
$runnerText = Get-Content -Raw -LiteralPath `
    (Join-Path $PSScriptRoot "run_developer_full_access.ps1")
if ($runnerText -notmatch 'admit_developer_full_access_launch\.ps1' -or
    $runnerText -notmatch '\.Arguments\s*=\s*"--developer-full-access"' -or
    $runnerText -notmatch '\[switch\]\$VerifyOnly') {
    throw "product_command_local_access_runner_authority_invalid"
}

$readme = [IO.File]::ReadAllText($readmePath, [Text.Encoding]::UTF8)
$requiredReadmeCommands = @(
    '.\scripts\build_developer_full_access.ps1',
    '.\scripts\run_developer_full_access.ps1 -VerifyOnly -BundleDirectory',
    '.\scripts\run_developer_full_access.ps1 -Wait -BundleDirectory',
    '.\scripts\test_product_lifecycle.ps1 -DeveloperFullAccess -BundleDirectory'
)
foreach ($command in $requiredReadmeCommands) {
    if (-not $readme.Contains($command)) {
        throw "product_command_readme_stage_missing:$command"
    }
}
$staleCopy = [regex]::new(
    '(?i)(\u0434\u043e\u0441\u0442\u0443\u043f\u043d\p{L}*\s+' +
    '(?:\u0442\u043e\u043b\u044c\u043a\u043e\s+)?' +
    '\u043f\u043e\u0441\u043b\u0435\s+' +
    '(?:\u043f\u043e\u043b\u043d\u043e\u0433\u043e\s+)?' +
    '(?:\u043f\u0435\u0440\u0435\u0445\u043e\u0434\u0430|' +
    '\u043c\u0438\u0433\u0440\u0430\u0446\p{L}*)|' +
    '\u043f\u043e\u0441\u043b\u0435\s+' +
    '(?:\u043f\u043e\u043b\u043d\u043e\u0433\u043e\s+)?' +
    '\u043f\u0435\u0440\u0435\u0445\u043e\u0434\u0430\s+' +
    '\u043d\u0430)')
if ($staleCopy.IsMatch($readme) -or $staleCopy.IsMatch($manifestText)) {
    throw "product_command_stale_migration_copy_exposed"
}
if ($readme -notmatch (
        '\u043d\u0435\s+\u0437\u0430\u043f\u0440\u0430\u0448\u0438' +
        '\u0432\u0430\u0435\u0442\s+\u043a\u043b\u044e\u0447') -or
    $readme -notmatch (
        '\u043d\u0435\s+\u043f\u043e\u0434\u043a\u043b\u044e\u0447' +
        '\u0430\u0435\u0442\u0441\u044f\s+\u043a\s+' +
        '\u0441\u0435\u0440\u0432\u0438\u0441\u0443\s+' +
        '\u043b\u0438\u0446\u0435\u043d\u0437\u0438\u0439')) {
    throw "product_command_readme_local_access_license_boundary_missing"
}

Write-Output "PASS Fishing Local Access product command and README contracts"
