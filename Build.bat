@echo off
echo.
echo  [discord.gg/subz] Starting Build...
echo.
echo ___________________________________________
echo.
"C:\Program Files\Microsoft Visual Studio\2022\Community\Msbuild\Current\Bin\MSBuild.exe" subzero.vcxproj /p:configuration=Release /p:platform=x64
echo.
echo ___________________________________________
echo.
echo  [discord.gg/subz] Finished
echo.
pause