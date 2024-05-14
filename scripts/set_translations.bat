:: BAT script to update translations
:: WARNING: This script must be executed from its own folder.
@echo OFF

:: Example usage: .\update_translations.bat C:\Users\Ricardo\Qt\5.14.2\mingw73_32\bin
set USAGE_MSG=".\create_release_windows.bat <PATH_TO_QT_BIN> <PATH_TO_APP_EXE_FILE>

:: App PROJECT file
set TRANSLATIONS_FILE=../translations/app_en.ts

::Check argument 1
set QT_BIN_PATH=%1
if "%1"=="" (
    echo Invalid arguments number. Usage: %USAGE_MSG%
    exit
) else (
    echo -- Using QtEnv setup script: %QT_BIN_PATH%\qtenv2.bat
)

:: Source qtenv2 script to set up the Qt Enviroment
echo -- Setting up Qt Enviroment
cmd /C %QT_BIN_PATH%\qtenv2.bat

:: Open the GUI to write the translations
echo -- Openning Qt Linguist
cmd /C %QT_BIN_PATH%\linguist.exe %TRANSLATIONS_FILE%

endlocal
