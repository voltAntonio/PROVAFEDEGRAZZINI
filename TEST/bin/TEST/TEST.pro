QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH +=  ../../testlib/square ../../testlib/sum ../../testlib/soil  # Ogni .. che usi ti buttano fuori di una directory.

CONFIG(debug, debug|release) {
    LIBS += -L../../testlib/square/debug -lsquare \
            -L../../testlib/sum/debug -lsum \
            -L../../testlib/soil/debug -lsoil

} else {
    LIBS += -L../../testlib/square/release -lsquare \
            -L../../testlib/sum/release -lsum \
            -L../../testlib/soil/release -lsoil
}


SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += mainwindow.h

FORMS += mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
