#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "testfunctions.h"
#include "../GSqlite/sqlite/qsql_sqlite_p.h"
#include "GSqlite/SqliteTable.h"

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlRecord>
#include <QTableView>
#include <QLabel>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    , m_db(new QSqlDatabase)

{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_db;
}

bool MainWindow::initUi()
{
    initTriggers();
    if(Utils::createDatabase(*m_db))
    {
        return initUiFromDb(*m_db);
    }
    return false;
}

bool MainWindow::initUiFromDb(QSqlDatabase &db)
{
    QStringList  tableNames = db.tables(QSql::Tables);

     QWidget *w = ui->tabWidget->widget(1);
     if(w)
     {
        delete w;
        w = nullptr;
     }
    initDbInfoTable(db);


    foreach(auto strName, tableNames)
    {
        if(!addTable(strName, db))
        {
            qDebug() << "table name  "<< strName;
            return false;
        }
    }
    return true;
}

bool MainWindow::addTable(const QString &tableName, QSqlDatabase &db)
{
    QSqlTableModel* tableModel = new QSqlTableModel(this, db);
    tableModel->setTable(tableName);

    SqliteTableProxy *modelProxy = new SqliteTableProxy(tableModel, this);
    modelProxy->setSqlModel(tableModel);

    ui->dbInfoView->addItem(tableName);
    QTableView *view  = new QTableView(this);
    view->setModel(tableModel);
    ui->tabWidget->addTab(view, tableName);
    m_tableProxyList.push_back(modelProxy);


    connect(tableModel, &QSqlTableModel::primeInsert, [&](int row, QSqlRecord &record){
        qDebug()<< "before insert "<< row;
    });

    connect(tableModel, &QAbstractItemModel::rowsInserted, [&](const QModelIndex &parent, int first, int last){
        qDebug()<< "after insert "<< first;
    });

    connect(tableModel, &QAbstractItemModel::dataChanged, [&](const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles){
        qDebug()<< "data changed "<< topLeft.row();
    });

//    connect(tableModel, &QAbstractItemModel::rowsInserted, [&](const QModelIndex &parent, int first, int last){
//        qDebug()<< "after insert "<< first;
//    });


    return true;
}

bool MainWindow::initDbInfoTable(QSqlDatabase &db)
{
    //QTableModel *model = new QTableModel(this);
    return true;
}

void MainWindow::answerDriverNotify(const QString &name, QSqlDriver::NotificationSource source, const QVariant &payload)
{
    qDebug()<< "driver event: " << name;
}

void MainWindow::answerDriverNotify(const QString &name)
{
    qDebug()<< "driver event: " << name;
}

void MainWindow::initTriggers()
{
    connect(m_db->driver()
            , SIGNAL(notification(const QString &)), this, SLOT(answerDriverNotify(const QString &)));
    connect(m_db->driver()
            , SIGNAL(notification(const QString &, QSqlDriver::NotificationSource , const QVariant &))
            , this, SLOT(answerDriverNotify(const QString &, QSqlDriver::NotificationSource , const QVariant &)));

    //static const ADD = 2;
    //static const ADD = 3;

    connect(ui->addButton, &QAbstractButton::clicked, [&](){
        int index = ui->tabWidget->currentIndex() - 1;
        if(index < 0)
            return ;
        m_tableProxyList[index]->sqlModel()->insertRows(0, 1);//addEmptyRecord(1);
    });

    connect(ui->deleteButton, &QAbstractButton::clicked, [&](){
        int index = ui->tabWidget->currentIndex() - 1;
        if(index < 0)
            return ;
        auto model = m_tableProxyList[index]->sqlModel();
        auto curRecord = model->record(0);
        m_tableProxyList[index]->sqlModel()->removeRows(0, 1);
    });

}

void MainWindow::initDriver()
{
    QSqlDatabase::registerSqlDriver("sqlite", new QSqlDriverCreator<GSQLiteDriver>);
}
