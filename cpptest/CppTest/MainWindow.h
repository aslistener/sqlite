#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDriver>

namespace Ui {
class MainWindow;
}

class QSqlDatabase;
class QSqlTableModel;
class SqliteTableProxy;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool initUi();
    void initTriggers();
    void initDriver();

private:
    bool initUiFromDb(QSqlDatabase &);
    bool addTable(const QString &tableName, QSqlDatabase &db);
    bool initDbInfoTable(QSqlDatabase &);

private slots:
    void answerDriverNotify(const QString &name, QSqlDriver::NotificationSource source, const QVariant &payload);
    void answerDriverNotify(const QString &name);
//private:


private:
    Ui::MainWindow *ui;
    QSqlDatabase   *m_db;
    QList<SqliteTableProxy* > m_tableProxyList;
};

#endif // MAINWINDOW_H
