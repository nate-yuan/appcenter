#include <QtSql>

#include "localapps.h"

#define QUERY_STATEMENT "select * from localapps;"
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

QString LocalApp::name()
{ return _name; }

void LocalApp::setName(QString &name)
{ _name = name; }

QString LocalApp::icon()
{ return _icon; }

void LocalApp::setIcon(QString &icon)
{ _icon = icon; }

QString LocalApp:version()
{ return _version; }

void LocalApp::setVersion(QString &version)
{ _version = version; }

QString LocalApp::execname()
{ return _execname; }

void LocalApp::setExecname(QString &name)
{ _execname = execname; }

QString LocalApp::uninstName()
{ return _uninstName; }

void LocalApp::setUninstName(QString _uninstName)
{ _uninstName = uninstName; }

Status LocalApp::status()
{ return _status; }

void LocalApp::setStatus(Status status)
{ _status = status; }

int LocalApp::x()
{ return _x; }

void LocalApp::setX(int x)
{ _x = x; }

int LocalApp::y()
{ return _y; }

void LocalApp::setY(int y)
{ _y = y; }

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
    while (query.next) {
        LocalApp *app = new LocalApp();
        app->setName(query.value(NAME).toString()); 
        app->setVersion(query.value(VERSION).toString()); 
        app->setExecname(query.value(EXEC).toString()); 
        app->setIcon(query.value(ICON).toString()); 
        app->setUninstName(query.value(UNINST).toString());
        app->setStatus(query.value(STATUS).toInt());
        app->setX(query.value(X).toInt());
        app->setY(query.value(Y).toInt());
        _list[whichPage(app->x(), app->y())].append(app);
}

LocalAppList::~LocalAppList()
{
    //TODO: delete every LocalApp
}

void LocalAppList::addApp(LocalApp *app)
{ 
    _list[whichPage(app->x(), app->y())].append(app);
}

void LocalAppList::delApp(int x, int y)
{
    int page = whichPage(x, y);

    for (int i = 0; i < _list[page].count(); i++) {
        if (_list[page].at(i)->x() == x &&
            _list[page].at(i)->y() == y) {
            _list[page].remove(i);
            break;
        }
    }
}

int LocalAppList::whichPage(int x, int y)
{
    return 0;
}
