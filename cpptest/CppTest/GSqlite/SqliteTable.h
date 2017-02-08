#ifndef SQLITETABLE_H
#define SQLITETABLE_H

#include <QObject>

class QSqlTableModel;
class QSqlRecord;
class QSqlField;

class SqliteTableProxy : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QSqlTableModel* sqlModel READ getSqlModel WRITE setSqlModel)
public:
    explicit SqliteTableProxy(QSqlTableModel* sqlModel, QObject *parent);

    QSqlTableModel* sqlModel(){ return m_sqlTable; }
    void setSqlModel(QSqlTableModel* model){ m_sqlTable = model; }

    void addRecord(const QSqlRecord& );
    void addRecordList(const QSqlRecord& );
    void addEmptyRecord(int count);
    void deleteRecord(const QSqlRecord& );
    void deleteRecordList(const QSqlRecord& );
    void getRecord(int index);
    void getRecord(int index, int count);
    void rollback(int step);

    QVariant getfieldDefaultValue(QSqlField &);

signals:

public slots:

private:


private:
    QSqlTableModel* m_sqlTable;
};

#endif // SQLITETABLE_H
