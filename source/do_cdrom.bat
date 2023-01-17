cp .\MAIN.ps-exe ..\tools\cdrom\MAIN.EXE
cd cdrom
rm myimage.*
..\tools\mkpsxiso\mkpsxiso-2.02-win64\bin\mkpsxiso.exe -y ..\tools\cdrom\makeiso.xml
cd..