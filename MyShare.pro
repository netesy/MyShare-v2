#-------------------------------------------------
#
# Project created by QtCreator 2015-05-24T13:28:28
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyShare
TEMPLATE = app


## Generate the config.h file and add its path for inclusion
#config_h.input     = config.h.in
#config_h.output    = $$/config.h
#QMAKE_SUBSTITUTES += config_h


SOURCES += main.cpp\
        mainwindow.cpp \
    settings.cpp \
    about.cpp

HEADERS  += mainwindow.h \
    settings.h \
    about.h \
    config.h

FORMS    += mainwindow.ui \
    settings.ui \
    about.ui

RESOURCES += \
    images.qrc
include ("Myshare.pri");
#RC_ICONS = images/logo.png
