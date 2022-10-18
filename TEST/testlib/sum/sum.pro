CONFIG -= core gui

TEMPLATE = lib
CONFIG += staticlib

DEFINES += SOMMA_LIBRARY

CONFIG += c++11

CONFIG += debug_and_release
QMAKE_CXXFLAGS += -std=c++11

unix:{
    CONFIG(debug, debug|release) {
        TARGET = debug/somma
    } else {
        TARGET = release/somma
    }
}
win32:{
    TARGET = somma
}

SOURCES += \
    somma.cpp

HEADERS += \
    somma.h
