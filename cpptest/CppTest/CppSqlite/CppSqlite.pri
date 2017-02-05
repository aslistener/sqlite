CppInclude = $$PWD/../../../sqlitecpp/headeronly_src
Sqlite3 = $$PWD/../../../sqlite/201701170010

INCLUDEPATH += \
        $$CppInclude \
        $$Sqlite3

LIBS += $$Sqlite3\sqlite3.lib

HEADERS += \
    $$CppInclude/sqlite3pp.h \
    $$CppInclude/sqlite3pp.ipp \
    $$CppInclude/sqlite3ppext.h \
    $$CppInclude/sqlite3ppext.ipp \
    $$Sqlite3/sqlite3.h \
    $$Sqlite3/sqlite3ext.h
