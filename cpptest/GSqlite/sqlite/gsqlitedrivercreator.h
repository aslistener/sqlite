#ifndef GSQLITEDRIVERCREATOR_H
#define GSQLITEDRIVERCREATOR_H

#include <QtSql/QSqlDriverCreator>

#ifndef QT_BUILD_SQLITE_LIB
#define Q_EXPORT_SQLDRIVER_SQLITE Q_DECL_IMPORT
#else
#define Q_EXPORT_SQLDRIVER_SQLITE Q_DECL_EXPORT
#endif

class Q_EXPORT_SQLDRIVER_SQLITE GSQLiteDriverCreator : public QSqlDriverCreator
{
    virtual QSqlDriver *createObject() const;
};



#endif // GSQLITEDRIVERCREATOR_H
