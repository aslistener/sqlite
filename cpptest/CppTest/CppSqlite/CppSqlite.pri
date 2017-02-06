DEFINES += SQLITECPP

CONFIG += c++11


CppInclude = $$PWD/../../../sqlitecpp/headeronly_src
Sqlite3 = $$PWD/../../../sqlite/201701170010

qmakever = $$[QMAKE_SPEC]
contains($$qmakever, win32-msvc2010) {
    libsroot = $$Sqlite3/ms10
    #message($$libsroot)
} else:contains($$qmakever, win32-msvc2013) {
    libsroot = $$Sqlite3/ms12
} else:contains($$qmakever, win32-msvc2015) {
    libsroot = $$Sqlite3/ms15
}

contains(QMAKE_TARGET.arch, x86_64) {
    libsdir = $$libsroot/x64
} else {
    libsdir = $$libsroot/win32
}
message($$qmakever)
#message($$LIBS)

INCLUDEPATH += \
        $$CppInclude \
        $$Sqlite3

LIBS += $$libsdir\sqlite3.lib
#message($$LIBS)

HEADERS += \
    $$CppInclude/sqlite3pp.h \
    $$CppInclude/sqlite3pp.ipp \
    $$CppInclude/sqlite3ppext.h \
    $$CppInclude/sqlite3ppext.ipp \
    $$Sqlite3/sqlite3.h \
    $$Sqlite3/sqlite3ext.h
