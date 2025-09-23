@ECHO OFF
SET msg=Hello world
ECHO %msg%

::SET /P usr = "Input:"
::echo %usr%

::symbol op
SET x=1
SET y=2
SET z=%x% + %y%
ECHO %z%

::arithmetic op
SET /a z=x+y
echo %z%

SET str1=hello
SET str2=world
SET str=%str1% %str2%
echo %str%

ECHO %str:~0,3%
ECHO %str:~3%
ECHO %str:~-2%
SET url=http:://ya.ru
IF %url:~0,4%==http echo This is url

ECHO %str:l=L%
ECHO %str:o=%
ECHO %str:*lo=goodbye%

IF 1==1 (SET dummy=123)
ECHO %dummy%

SETLOCAL
  SET dummy=321
  SETLOCAL
    SET dummy = 213
  ENDLOCAL
  ECHO %dummy%
ENDLOCAL
ECHO %dummy%