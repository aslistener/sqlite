#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlField>
#include <QtSql/QSqlError>
#include <QtDebug>
#include "SqliteTable.h"


SqliteTableProxy::SqliteTableProxy(QSqlTableModel* sqlModel, QObject *parent)
    : QObject(parent)
    , m_sqlTable(sqlModel)
{




}

void SqliteTableProxy::addRecord(const QSqlRecord &r)
{
    qDebug() << "current count " << m_sqlTable->rowCount();
    if(!m_sqlTable->insertRecord(m_sqlTable->rowCount(), r))
    {
        QSqlError &&error = m_sqlTable->database().lastError();
        qDebug() << "sqlite errorcode " << error.nativeErrorCode()
                 << "qt errorcode " << error.type();
    }
}

void SqliteTableProxy::addRecordList(const QSqlRecord &)
{

}

void SqliteTableProxy::addEmptyRecord(int count)
{

    int rowCount = m_sqlTable->rowCount();
    auto r = m_sqlTable->record();
    for(int i = 0; i < count; i++)
    {
        QSqlRecord record;
        for(int j = 0;j < r.count(); j++)
        {
            auto field = r.field(j);
            field.setValue(getfieldDefaultValue(field));
            record.append(field);
        }

        m_sqlTable->insertRecord(-1, record);
        //r.clear();
        //m_sqlTable->submit();

    }
}

void SqliteTableProxy::deleteRecord(const QSqlRecord &)
{

}

void SqliteTableProxy::deleteRecordList(const QSqlRecord &)
{

}

void SqliteTableProxy::getRecord(int index)
{

}

void SqliteTableProxy::getRecord(int index, int count)
{

}

void SqliteTableProxy::rollback(int step)
{

}

QVariant SqliteTableProxy::getfieldDefaultValue(QSqlField &field)
{
    switch(field.type())
    {
        case QVariant::Int:
            return 0;
        case QVariant::String:
            return "nullxxx";
        case QVariant::Double:
            return 0.0;
//        case QVariant::Int:
//            field.setValue(0);
//        break;
    }
    //field.defaultValue();
}
