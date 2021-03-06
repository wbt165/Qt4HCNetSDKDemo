# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

TEMPLATE = app
TARGET = Qt4HCNetSDKDemo

win32:DESTDIR = ./Win/bin
unix:DESTDIR = ./Linux/bin

QT += core gui
CONFIG += debug
DEFINES += QT_LARGEFILE_SUPPORT QT_DLL

INCLUDEPATH += ./GeneratedFiles \
    . \
    ./GeneratedFiles/Debug
win32:INCLUDEPATH += ./Win/include
unix:INCLUDEPATH += ./Linux/include

win32:LIBS += -L"./Win/lib" -lHCNetSDK
unix:LIBS += -L./Linux/bin -Wl,-rpath=./:./HCNetSDKCom:../bin -lhcnetsdk -lhpr -lHCCore
    
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/debug
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(Qt4HCNetSDKDemo.pri)
