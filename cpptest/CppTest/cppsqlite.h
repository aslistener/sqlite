#ifndef CPPSQLITE_H
#define CPPSQLITE_H

#include <QObject>

class CppSqlitePrivate;
class CppSqlite : public QObject
{
    Q_OBJECT
public:
    explicit CppSqlite(QObject *parent = 0);

signals:

public slots:


private:
    Q_DECLARE_PRIVATE(CppSqlite)
    CppSqlitePrivate *d_ptr;
};

#endif // CPPSQLITE_H
