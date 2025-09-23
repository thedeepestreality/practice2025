@ECHO OFF
:loop
IF [%1]==[] (
  GOTO end
) ELSE (
  SET /P=%1 <NUL
)
SHIFT
GOTO loop
:end

:: echo %2
REM this is comment too