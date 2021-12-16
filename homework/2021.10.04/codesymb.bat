@echo off
chcp 1251

for /l %%i in (33,1,255) do (	
	call :_tochar %%i
	cmd /c exit %%i
)
exit /b

:_tochar
setlocal
cmd /c exit %1
type "%1" "%=ExitCodeAscii%"
exit /b
