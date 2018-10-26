#-------------------------------------------------
#
# Project created by QtCreator 2018-05-05T16:09:13
#
#-------------------------------------------------
#win32{
#include ( C:/Qwt-6.1.3/features/qwt.prf )
#}

QT       += core \
          widgets \
          gui \
          network
QT       += quickwidgets

#system(qmake --version > qmakeVersion.txt)

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += qwt
CONFIG += c++11
#CONFIG += static

TARGET = myon_detector_gui
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += ../shared \
        src

SOURCES += \
        ../shared/tcpconnection.cpp \
        src/main.cpp \
        src/mainwindow.cpp \
    ../shared/tcpmessage.cpp \
    src/settings.cpp \
    src/status.cpp \
    src/map.cpp

HEADERS += \
        ../shared/tcpconnection.h \
        src/mainwindow.h \
    ../shared/tcpmessage.h \
    ../shared/ublox_messages.h \
    ../shared/gpio_pin_definitions.h \
    src/settings.h \
    ../shared/ubx_msg_key_name_map.h \
    ../shared/tcpmessage_keys.h \
    src/status.h \
    src/map.h

FORMS += \
        src/mainwindow.ui \
    src/settings.ui \
    src/status.ui \
    src/map.ui

OBJECTS_DIR += created_files

UI_DIR += created_files

MOC_DIR += created_files

DISTFILES += \
    qml/mymap.qml