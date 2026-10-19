param([string]$File)
$root = Split-Path -Parent $MyInvocation.MyCommand.Path
$gxx  = 'C:/msys64/ucrt64/bin/g++.exe'
$inSrc = $File -and ($File.StartsWith((Join-Path $root 'src'), [System.StringComparison]::OrdinalIgnoreCase))
if ($inSrc) {
    & (Join-Path $root 'build.ps1') -Run
    return
}
$name = [System.IO.Path]::GetFileNameWithoutExtension($File)
$out  = Join-Path $root ("build\$name.exe")
& $gxx -std=c++17 -Wall -Wextra -g -o $out $File
if ($LASTEXITCODE -ne 0) { Write-Host "编译失败 (exit=$LASTEXITCODE)" -ForegroundColor Red; return }
& $out
Write-Host ("进程退出码: 0x{0:X}" -f $LASTEXITCODE)