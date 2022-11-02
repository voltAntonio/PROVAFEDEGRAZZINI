#----------------------------------------------------
#
#   Test library
#
#   This project is a test project
#
#----------------------------------------------------

CONFIG -= core gui

TEMPLATE = lib
CONFIG += staticlib

#DEFINES += TESTLIB_LIBRARY

CONFIG += c++11

CONFIG += debug_and_release
QMAKE_CXXFLAGS += -std=c++11

unix:{
    CONFIG(debug, debug|release) {
        TARGET = debug/soil
    } else {
        TARGET = release/soil
    }
}
win32:{
    TARGET = soil
}

SOURCES += \
    soil.cpp

HEADERS += \
    soil.h

