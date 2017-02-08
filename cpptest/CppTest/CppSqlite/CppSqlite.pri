DEFINES += SQLITECPP


CONFIG += c++11

include($$PWD/../../sqlite3.pri)
CppInclude = $$PWD/../../../sqlitecpp/headeronly_src

INCLUDEPATH += \
        $$CppInclude

HEADERS += \
    $$CppInclude/sqlite3pp.h \
    $$CppInclude/sqlite3pp.ipp \
    $$CppInclude/sqlite3ppext.h \
    $$CppInclude/sqlite3ppext.ipp \
    $$PWD/cppsqlite.h \
    $$PWD/CppSqlitePrivate.h

SOURCES += \
    $$PWD/cppsqlite.cpp \
    $$PWD/CppSqlitePrivate.cpp
