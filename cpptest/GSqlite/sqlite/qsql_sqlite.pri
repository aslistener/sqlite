CONFIG += qt
QT += sql-private core-private
INCLUDEPATH += $$[QT_INSTALL_HEADERS]/QtSql

DEFINES += QT_BUILD_SQLITE_LIB
include(../../sqlite3.pri)

HEADERS += $$PWD/qsql_sqlite_p.h
#\
#    $$PWD/gsqlitedrivercreator.h
SOURCES += $$PWD/qsql_sqlite.cpp
#\
#    $$PWD/gsqlitedrivercreator.cpp




