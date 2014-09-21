#-------------------------------------------------
#
# Project created by QtCreator 2014-09-21T10:08:16
#
#-------------------------------------------------

QT       += core gui
QMAKE_MAC_SDK = macosx10.9
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = finpass
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    dialog.h

FORMS    += mainwindow.ui \
    dialog.ui
