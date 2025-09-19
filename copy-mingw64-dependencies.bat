@echo off
setlocal
call :GetBatchFileDirectory _MyDir
set BIN_DIR=%_MyDir%\build\bin

copy /Y "C:\mingw64\bin\libstdc++-6.dll" "%BIN_DIR%"
copy /Y "C:\mingw64\bin\libgcc_s_seh-1.dll" "%BIN_DIR%"

copy /Y "%VCPKG_ROOT_MINGW64%\installed\x64-mingw-dynamic\bin\libexpat-1.dll" "%BIN_DIR%"
copy /Y "%VCPKG_ROOT_MINGW64%\installed\x64-mingw-dynamic\bin\libjpeg-62.dll" "%BIN_DIR%"
copy /Y "%VCPKG_ROOT_MINGW64%\installed\x64-mingw-dynamic\bin\liblzma.dll" "%BIN_DIR%"
copy /Y "%VCPKG_ROOT_MINGW64%\installed\x64-mingw-dynamic\bin\libpcre2-16.dll" "%BIN_DIR%"
copy /Y "%VCPKG_ROOT_MINGW64%\installed\x64-mingw-dynamic\bin\libpng16.dll" "%BIN_DIR%"
copy /Y "%VCPKG_ROOT_MINGW64%\installed\x64-mingw-dynamic\bin\libsharpyuv.dll" "%BIN_DIR%"
copy /Y "%VCPKG_ROOT_MINGW64%\installed\x64-mingw-dynamic\bin\libtiff.dll" "%BIN_DIR%"
copy /Y "%VCPKG_ROOT_MINGW64%\installed\x64-mingw-dynamic\bin\libwebp.dll" "%BIN_DIR%"
copy /Y "%VCPKG_ROOT_MINGW64%\installed\x64-mingw-dynamic\bin\libwebpdecoder.dll" "%BIN_DIR%"
copy /Y "%VCPKG_ROOT_MINGW64%\installed\x64-mingw-dynamic\bin\libwebpdemux.dll" "%BIN_DIR%"
copy /Y "%VCPKG_ROOT_MINGW64%\installed\x64-mingw-dynamic\bin\libzlib1.dll" "%BIN_DIR%"
copy /Y "%VCPKG_ROOT_MINGW64%\installed\x64-mingw-dynamic\bin\libzstd.dll" "%BIN_DIR%"
copy /Y "%VCPKG_ROOT_MINGW64%\installed\x64-mingw-dynamic\bin\wxbase331u_gcc_custom.dll" "%BIN_DIR%"
copy /Y "%VCPKG_ROOT_MINGW64%\installed\x64-mingw-dynamic\bin\wxbase331u_net_gcc_custom.dll" "%BIN_DIR%"
copy /Y "%VCPKG_ROOT_MINGW64%\installed\x64-mingw-dynamic\bin\wxbase331u_xml_gcc_custom.dll" "%BIN_DIR%"
copy /Y "%VCPKG_ROOT_MINGW64%\installed\x64-mingw-dynamic\bin\wxmsw331u_aui_gcc_custom.dll" "%BIN_DIR%"
copy /Y "%VCPKG_ROOT_MINGW64%\installed\x64-mingw-dynamic\bin\wxmsw331u_core_gcc_custom.dll" "%BIN_DIR%"
copy /Y "%VCPKG_ROOT_MINGW64%\installed\x64-mingw-dynamic\bin\wxmsw331u_gl_gcc_custom.dll" "%BIN_DIR%"
copy /Y "%VCPKG_ROOT_MINGW64%\installed\x64-mingw-dynamic\bin\wxmsw331u_html_gcc_custom.dll" "%BIN_DIR%"
copy /Y "%VCPKG_ROOT_MINGW64%\installed\x64-mingw-dynamic\bin\wxmsw331u_media_gcc_custom.dll" "%BIN_DIR%"
copy /Y "%VCPKG_ROOT_MINGW64%\installed\x64-mingw-dynamic\bin\wxmsw331u_propgrid_gcc_custom.dll" "%BIN_DIR%"
copy /Y "%VCPKG_ROOT_MINGW64%\installed\x64-mingw-dynamic\bin\wxmsw331u_ribbon_gcc_custom.dll" "%BIN_DIR%"
copy /Y "%VCPKG_ROOT_MINGW64%\installed\x64-mingw-dynamic\bin\wxmsw331u_richtext_gcc_custom.dll" "%BIN_DIR%"
copy /Y "%VCPKG_ROOT_MINGW64%\installed\x64-mingw-dynamic\bin\wxmsw331u_stc_gcc_custom.dll" "%BIN_DIR%"
copy /Y "%VCPKG_ROOT_MINGW64%\installed\x64-mingw-dynamic\bin\wxmsw331u_xrc_gcc_custom.dll" "%BIN_DIR%"

goto :EOF

::
:: GetBatchFileDirectory
::
:: Gets the name of the directory in which the batch file is located.  The directory name will not
:: have a final trailing \ character.
::
:: The directory name is stored in the environment variable specified by the first parameter of the
:: function.
::
:GetBatchFileDirectory
  set _dir=%~dp0
  set _dir=%_dir:~0,-1%
  if "%_dir%" EQU "" (
    set _dir=
    exit /b 1
  )
  set %1=%_dir%
  set _dir=
  exit /b 0
goto :EOF
