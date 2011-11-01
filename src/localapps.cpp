#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QVariant>

#include "localapps.h"

#define SQL_STATEMENT "select * from localapps;"

#define NAME    0
#define VERSION 1 
#define EXEC    2
#define ICON    3
#define UNINST  4
#define STATUS  5
#define X       6
#define Y       7

LocalApp::LocalApp()
{
}

LocalApp::~LocalApp()
{
}


LocalAppList::LocalAppList(QString dbname)
    :_db(dbname)
{
    QSqlDatabase dbconn = QSqlDatabase::addDatabase("QSQLITE");
    dbconn.setDatabaseName(_db);
    if (!dbconn.open()) {
        //TODO
    }
    QSqlQuery query;
    query.exec(SQL_STATEMENT);
    while (query.next()) {
        LocalApp *app = new LocalApp();
        app->setName(query.value(NAME).toString()); 
        app->setVersion(query.value(VERSION).toString()); 
        app->setExecname(query.value(EXEC).toString()); 
        app->setIcon(query.value(ICON).toString()); 
        app->setUninstName(query.value(UNINST).toString());
        app->setStatus(static_cast<Status>(query.value(STATUS).toInt()));
        app->setX(query.value(X).toInt());
        app->setY(query.value(Y).toInt());
        _list.append(app);
    }
}

LocalAppList::~LocalAppList()
{
    //TODO: delete every LocalApp
}

void LocalAppList::addApp(LocalApp *app)
{ 
    _list.append(app);
}

void LocalAppList::delApp(int x, int y)
{
    for (int i = 0; i < _list.count(); i++) {
        if (_list.at(i)->x() == x &&
            _list.at(i)->y() == y) {
            _list.remove(i);
            break;
        }
    }
}

LocalApp* LocalAppList::getAppByName(QString name)
{
    for (int i = 0; i < _list.count(); i++) {
        if (_list.at(i)->name() == name)
            return _list.at(i);
    }
    return NULL;
}

LocalApp* LocalAppList::at(int i)
{
    if (i >= _list.count() || i < 0)
        return NULL;
    return _list.at(i);
}

int LocalAppList::count()
{
    return _list.count();
}
