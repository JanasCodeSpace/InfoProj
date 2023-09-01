# Roboter Path Generator (RobPathGen)
***
This program reads a .csv File with path data consisting from a timestemp, x, y, z and a euler matrix to generate a KUKA roboter krl file.
In the frontend the user a few options to choose from:
- An Input files
- An Output folder
- Douglas-Peuker distance
- Moving average window
- calculated or user choosen speed
- calculated or user choosen orientation
- a choosen offset
- detailed logging

When ready the desired output file or files are generated. If a detailed logging is choosen there are log.csv files after every mayor data transformation.
- 01_log after the moving average filter so smooth the path
- 02_log after the douglas-peuker to reduce the number of points
- 03_log after the different parts of the path are fused to one, if there is more then one
- 04_log after the final calculations where the user choosen options are integrated into the data

The output file has the name of the input file with the file ending .src.
It is highly advised to test the data before loding it into a real KUKA roboter.

## Building
***
The application is build in a Visual Studio 2022 enviroment with QT 6.5.2 and the mingw_64 compiler.
So to build the application QT needs to be installed as well as the VS QT extentions.
To include QT into the from VS generated executable you can copy the bash script "release.bat" into your release folder.
It works with the default installation path of QT

## Questions
***
When you have questions don't hesitate to reach out to lehmannjana@gmx.de
