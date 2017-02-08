/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtSql module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QSQL_SQLITE_H
#define QSQL_SQLITE_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtSql/qsqldriver.h>
#include <QtSql/qsqlresult.h>

struct sqlite3;

#ifndef QT_BUILD_SQLITE_LIB
#define Q_EXPORT_SQLDRIVER_SQLITE //Q_DECL_IMPORT
#else
#define Q_EXPORT_SQLDRIVER_SQLITE Q_DECL_EXPORT
#endif

QT_BEGIN_NAMESPACE

class GSQLiteDriverPrivate;
class GSQLiteDriver;

class Q_EXPORT_SQLDRIVER_SQLITE GSQLiteDriver : public QSqlDriver
{
    Q_OBJECT

    Q_DECLARE_PRIVATE(GSQLiteDriver)
    friend class QSQLiteResult;
public:
    explicit GSQLiteDriver(QObject *parent = 0);
    explicit GSQLiteDriver(sqlite3 *connection, QObject *parent = 0);
    ~GSQLiteDriver();
    virtual bool hasFeature(DriverFeature f) const;
    virtual bool open(const QString & db,
                    const QString & user,
                    const QString & password,
                    const QString & host,
                    int port,
                    const QString & connOpts);
    virtual void close();
    virtual QSqlResult *createResult() const;
    virtual bool beginTransaction();
    virtual bool commitTransaction();
    virtual bool rollbackTransaction();
    virtual QStringList tables(QSql::TableType) const;
    virtual QSqlRecord record(const QString& tablename) const;
    virtual QSqlIndex primaryIndex(const QString &table) const;
    virtual QVariant handle() const;
    virtual QString escapeIdentifier(const QString &identifier, IdentifierType) const;

signals:
    void dbLoaded(const QString & db);

};

QT_END_NAMESPACE

#endif // QSQL_SQLITE_H
