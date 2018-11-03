Create a situation where you have the compiled muondetector-gui.exe and all the additional resources in a folder (.exe and qml/mymap.qml ...).
Use the deploy.bat file: first open the deploy.bat file with a text editor of your choice.
Then change the first path to your "windeployqt.exe" file (probably C:\Qt\<Qt-version>\<compiler-version>\bin\windeployqt.exe).
This should work.
If not: make sure the second file in this line is the .exe file that you created before and that needs all the libraries.
You also need to copy qwt.dll from your qwt installation path and maybe Qt5OpenGL.dll from your qt path (for Qt5).
You may need to copy additional libraries from the qt directory to this directory, you can see which ones by trying to execute the .exe.
