QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH +=  ../../testlib/square ../../testlib/sum  # Ogni .. che usi ti buttano fuori di una directory.

CONFIG(debug, debug|release) {
    LIBS += -L../../testlib/square/debug -lsquare
    LIBS += -L../../testlib/sum/debug -lsum

} else {
    LIBS += -L../../testlib/square/debug -lsquare
    LIBS += -L../../testlib/sum/debug -lsum
}


SOURCES += \
    main.cpp

HEADERS +=

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
