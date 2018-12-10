#-------------------------------------------------
#
# Project created by QtCreator 2018-12-10T17:55:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Notepad
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    src/LocalConnect/local.cpp

HEADERS  += mainwindow.h \
    src/LocalConnect/local.h \
    src/utils/console.hpp \
    ui_mainwindow.h

FORMS    += mainwindow.ui
