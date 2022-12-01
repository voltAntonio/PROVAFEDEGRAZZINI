QT  += widgets

CONFIG -= core gui

TEMPLATE = lib
CONFIG += staticlib

#DEFINES += SOMMA_LIBRARY

CONFIG += c++11

INCLUDEPATH +=  ../../testlib/soil

CONFIG += debug_and_release
QMAKE_CXXFLAGS += -std=c++11

unix:{
    CONFIG(debug, debug|release) {
        TARGET = debug/firstWidget
    } else {
        TARGET = release/firstWidget
    }
}
win32:{
    TARGET = firstWidget
}

SOURCES += \
    firstWidget.cpp

HEADERS += \
    firstWidget.h
