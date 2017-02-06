#ifndef CPPSQLITEPRIVATE_H
#define CPPSQLITEPRIVATE_H

#ifdef SQLITECPP
#include "sqlite3pp.h"
#include "sqlite3ppext.h"
#elif


#endif

#include "CppSqlite.h"



class CppSqlitePrivate
{
public:
    CppSqlitePrivate();

#ifdef SQLITECPP

//#elif

#endif
    Q_DECLARE_PUBLIC(CppSqlite)
    CppSqlite *q_ptr;

    #ifdef SQLITECPP

    #elif


    #endif
};

#endif // CPPSQLITEPRIVATE_H
