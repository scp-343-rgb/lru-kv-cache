param([switch]$Run)
$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent $MyInvocation.MyCommand.Path
$gxx  = 'C:/msys64/ucrt64/bin/g++.exe'
$srcs = Get-ChildItem -LiteralPath (Join-Path $root 'src') -Filter *.cpp | ForEach-Object { $_.FullName }
if (-not $srcs) { throw 'src 下没有 .cpp 文件' }
$out = Join-Path $root 'build\kv_cache.exe'
& $gxx -std=c++17 -Wall -Wextra -g -o $out @srcs
if ($LASTEXITCODE -ne 0) { Write-Host "编译失败 (exit=$LASTEXITCODE)" -ForegroundColor Red; exit $LASTEXITCODE }
Write-Host "编译成功: $out" -ForegroundColor Green
if ($Run) {
    & $out
    $code = $LASTEXITCODE
    Write-Host ("进程退出码: 0x{0:X}" -f $code)
}