#-------------------------------------------------
#
# Project created by QtCreator 2018-05-05T16:09:13
#
#-------------------------------------------------
win32{
include ( C:/qwt-6.1.3/features/qwt.prf )
}
VERSION = 1.0.2
QT       += core \
          widgets \
          gui \
          network
QT       += svg
QT       += quickwidgets

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += qwt
CONFIG += c++11

TARGET = muondetector-gui
TEMPLATE = app
CONFIG += warn_on
CONFIG += release

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DESTDIR = ../bin
UI_DIR = ../build/ui
MOC_DIR = ../build/moc
RCC_DIR = ../build/rcc
unix:OBJECTS_DIR = ../build/o/unix
win32:OBJECTS_DIR = ../build/o/win32
macx:OBJECTS_DIR = ../build/o/mac

INCLUDEPATH += . \
    main \
    qml

INCLUDEPATH += "$$PWD/../../muondetector-shared-1.0.2/src/"

INCLUDEPATH += /usr/local/qwt-6.1.3/include/

unix:INCLUDEPATH += /usr/lib/muondetector-shared
unix:LIBS += -L/usr/lib -lqwt-qt5
else:unix:LIBS += -L/usr/local/qwt-6.1.3/lib -lqwt
else:unix:LIBS += -L/usr/lib/muondetector-gui -lqwt
else:unix:LIBS += "$$PWD/../lib/libqwt.so.6.1.3"
else:unix:LIBS += -L/usr/lib/ -lqwt
unix:LIBS += -L/usr/lib/muondetector-shared -lmuondetector-shared
else:LIBS += -L./ -lmuondetector-shared
win32:LIBS += -L../lib -lmuondetector-shared
win32:INCLUDEPATH += ../bin/lib

SOURCES += \
    main/main.cpp \
    main/mainwindow.cpp \
    main/settings.cpp \
    main/status.cpp \
    main/map.cpp \
    main/plotcustom.cpp

HEADERS += \
    main/mainwindow.h \
    main/settings.h \
    main/status.h \
    main/map.h \
    main/plotcustom.h

FORMS += \
    main/mainwindow.ui \
    main/settings.ui \
    main/status.ui \
    main/map.ui

DISTFILES += \
    qml/mymap.qml
