#-------------------------------------------------
#
# Project created by QtCreator 2016-12-19T19:40:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ArcanoidGame
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gamewindow.cpp \
    gamefield.cpp

HEADERS  += mainwindow.h \
    gamewindow.h \
    gamefield.h

FORMS    += mainwindow.ui \
    gamewindow.ui
