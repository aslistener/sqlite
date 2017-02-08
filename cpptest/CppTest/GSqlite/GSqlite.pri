QT += sql-private sql
QTPLUGIN.sqldrivers = -

SOURCES += \
    $$PWD/testfunctions.cpp \
    $$PWD/SqliteTable.cpp

HEADERS += \
    $$PWD/SqliteTable.h \
    $$PWD/../../GSqlite/sqlite/qsql_sqlite_p.h

LIBS += $$DESTDIR/GSqlite.lib

