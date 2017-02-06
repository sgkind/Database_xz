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
    user.cpp \
    mydelegate.cpp \
    mymodel.cpp \
    changepwd.cpp \
    customwidget.cpp \
    schedulequerywidget.cpp \
    schedulequerytableview.cpp \
    newtasktableview.cpp \
    scheduletableview.cpp \
    informationtableview.cpp

HEADERS  += mainwindow.h \
    connect.h \
    login.h \
    mainwidget.h \
    user.h \
    mydelegate.h \
    mymodel.h \
    changepwd.h \
    customwidget.h \
    schedulequerywidget.h \
    schedulequerytableview.h \
    newtasktableview.h \
    scheduletableview.h \
    informationtableview.h

FORMS += \
    logindialog.ui \
    schedulequerywidget.ui

RESOURCES += \
    database.qrc
