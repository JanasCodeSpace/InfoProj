@ECHO OFF
ECHO Start Deployment

C:\Qt\6.5.1\msvc2019_64\bin\windeployqt6.exe RobPathCode.exe
del /q "CC:\Users\anche\Documents\Studium\InfoProjekt\Projekt\InfoProj\TestSoftware*"
FOR /D %%p IN ("C:\Users\anche\Documents\Studium\InfoProjekt\Projekt\InfoProj\TestSoftware*.*") DO rmdir "%%p" /s /q

xcopy C:\Users\anche\Documents\Studium\InfoProjekt\Projekt\InfoProj\RobPathGen\x64\Release\. C:\Users\anche\Documents\Studium\InfoProjekt\Projekt\InfoProj\TestSoftware /i /s /e

ECHO Deployment complete

PAUSE