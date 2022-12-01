QT       += core gui widgets

TEMPLATE = app

CONFIG += debug_and_release

unix:{
    CONFIG(debug, debug|release) {
        TARGET = debug/WIDGET_TEST
    } else {
        TARGET = release/WIDGET_TEST
    }
}
macx:{
    CONFIG(debug, debug|release) {
        TARGET = debug/WIDGET_TEST
    } else {
        TARGET = release/WIDGET_TEST
    }
}
win32:{
    TARGET = WIDGET_TEST
}

INCLUDEPATH +=  ../../testlib/firstWidget ../../testlib/soil

CONFIG(debug, debug|release) {
    LIBS += -L../../testlib/firstWidget/debug -lfirstWidget
    LIBS += -L../../testlib/soil/debug -lsoil
} else {

    LIBS += -L../../testlib/firstWidget/release -lfirstWidget
    LIBS += -L../../testlib/soil/release -lsoil
}


SOURCES += \
        main.cpp


