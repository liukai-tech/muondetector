How to build qwt on windows:
You have to download qwt and follow the instructions given.
When you are instructed to open qt terminal but you have no qt terminal:
it's only a standard terminal configured with the qt path variables etc.
You can just use for example the visual studio command prompt
(in visual studio "extras" then "command prompt")
then if you are running 64bit windows:
cd C:\Qt\5.11.2\msvc2017_64\bin
or any other folder with 64bit compiler...
"qtenv2.bat"
it will tell you to run vcvarsall.bat...
cd C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build
"vcvarsall.bat" x64
it will configure the compiler and I don't know what...
then just go to the directory where you unpacked qwt (go to the main folder where .pro file is located)
qmake qwt.pro
nmake
(wait for it to compile everything)
nmake install
(it will install qwt in C:\qwt-version...\bla

For Windows:
Look at myon_detector_gui.pro:
"win32{
include ( C:/Qwt-6.1.3/features/qwt.prf )
}"
tells qmake to include this file.
Qwt should be installed in this directory or you can change the path to the qwt.prf file where qwt is installed.