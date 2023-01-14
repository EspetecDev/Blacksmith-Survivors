@echo off
set argC=0
for %%x in (%*) do Set /A argC+=1
if %argC% NEQ 5 (goto end)
set filename=%1
set filename=%filename:~0,-4%
echo BMP2TIM %1 %filename%.tim 4 -clut=%2,%3 -org=%4,%5
goto end2
:end
echo haha me cago en tu puta mader
echo %argC%
:end2