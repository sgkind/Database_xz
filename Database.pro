#-------------------------------------------------
#
# Project created by QtCreator 2017-01-16T23:31:48
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Database
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    mainwidget.cpp \
    user.cpp

HEADERS  += mainwindow.h \
    connect.h \
    login.h \
    mainwidget.h \
    user.h

FORMS += \
    logindialog.ui
