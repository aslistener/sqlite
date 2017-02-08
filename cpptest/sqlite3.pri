Sqlite3 = $$PWD/../sqlite/201701170010

#if(win32-msvc2010) {
#    libsroot = $$Sqlite3/ms10
#} else:if(win32-msvc2013) {
#    libsroot = $$Sqlite3/ms12
#}

#contains(QMAKE_TARGET.arch, x86_64) {
#    libsdir = $$libsroot/x64
#} else {
#    libsdir = $$libsroot/win32
#}

INCLUDEPATH += \
        $$Sqlite3

HEADERS += \
    $$Sqlite3/sqlite3.h \
    $$Sqlite3/sqlite3ext.h

#LIBS += $$libsdir\sqlite3.lib
#message($$LIBS)

SOURCES += \
    $$Sqlite3/sqlite3.c
