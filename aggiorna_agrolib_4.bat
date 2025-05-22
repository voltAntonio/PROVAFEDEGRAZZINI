@echo off
setlocal enabledelayedexpansion

:: === CONFIG ===
set "GIT_EXE=C:\Users\avolta\AppData\Local\Programs\Git\bin\git.exe"
set "REPO_DIR=C:\Github\PROVAFEDEGRAZZINI"
set "COMMANDS_FILE=C:\Github\differenze.txt"

:: === VALIDAZIONI ===
if not exist "%GIT_EXE%" (
    echo ❌ Git non trovato in: %GIT_EXE%
    pause
    exit /b
)

if not exist "%COMMANDS_FILE%" (
    echo ❌ File comandi non trovato: %COMMANDS_FILE%
    pause
    exit /b
)

:: === ESECUZIONE COMANDI ===
pushd "%REPO_DIR%"
for /f "usebackq delims=" %%C in ("%COMMANDS_FILE%") do (
    echo ▶ Eseguo: %%C
    call "%GIT_EXE%" %%C
)
popd

echo ✅ Tutti i comandi sono stati eseguiti.
pause
