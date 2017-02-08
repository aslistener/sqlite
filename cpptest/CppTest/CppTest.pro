#-------------------------------------------------
#
# Project created by QtCreator 2017-02-05T22:45:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
DESTDIR = $$_PRO_FILE_PWD_/../../bin/cpptest

TARGET = CppTest
TEMPLATE = app

SOURCES += main.cpp \
        MainWindow.cpp

HEADERS  += MainWindow.h \
    testfunctions.h

FORMS    += MainWindow.ui

#include(CppSqlite/CppSqlite.pri)
include(GSqlite/GSqlite.pri)
include(../sqlite3.pri)
