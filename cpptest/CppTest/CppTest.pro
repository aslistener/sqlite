#-------------------------------------------------
#
# Project created by QtCreator 2017-02-05T22:45:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CppTest
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    cppsqlite.cpp \
    CppSqlitePrivate.cpp

HEADERS  += MainWindow.h \
    cppsqlite.h \
    CppSqlitePrivate.h

FORMS    += MainWindow.ui

include(CppSqlite/CppSqlite.pri)
