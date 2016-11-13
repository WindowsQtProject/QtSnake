#-------------------------------------------------
#
# Project created by QtCreator 2016-10-27T21:15:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtSnake
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    Food.cpp \
    Snake.cpp \
    SnakeControl.cpp

HEADERS  += mainwindow.h \
    Food.h \
    Snake.h \
    SnakeControl.h \
    Constant.h

FORMS    += mainwindow.ui

DISTFILES +=
