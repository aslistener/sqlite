#ifndef TESTFUNCTIONS_H
#define TESTFUNCTIONS_H

class QString ;

class QSqlDatabase;
class QSqlTableModel;
class QSqlRecord;
class QSqlField;


namespace Utils
{

typedef void (*BeforeOpenTrigger)(const QString &);
typedef void (*AfterOpenTrigger)(const QString &);

typedef void (*GeneralEventTrigger)(const QString &);


bool createDatabase(QSqlDatabase &db);
// open close
bool initTriggers(QSqlDatabase &db, GeneralEventTrigger generalEventTrigger);
bool initTriggers(QSqlTableModel &table);

}




#endif // TESTFUNCTIONS_H
