gcc EightQueen.cpp -o EightQueen.exe -g
@echo off   
choice /t 1 /d y /n >nul
@echo on
"EightQueen.exe" > Output/Answer.txt
@echo off   
choice /t 1 /d y /n >nul
@echo on
