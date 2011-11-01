#ifndef LOCALAPPS_H
#define LOCALAPPS_H

#define PAGENUM 4
#include <QString>
#include <QVector>

enum Status {havenot, downloaded, installed, old};

class LocalApp
{
public:
    LocalApp();
    ~LocalApp();
    QString name()
        { return _name; }
    void setName(QString name) 
        { _name = name; }
    QString icon()
        { return _icon; }
    void setIcon(QString icon) 
        { _icon = icon; }
    QString version()
        { return _version; }
    void setVersion(QString version)
        { _version = version; }
    QString execname()
        { return _execname; }
    void setExecname(QString execname)
        { _execname = execname; }
    QString uninstName()
        { return _uninstName; }
    void setUninstName(QString uninstName)
        { _uninstName = uninstName;}
    Status status()
        { return _status; }
    void setStatus(Status status)
        { _status = status; }
    int x()
        { return _x; }
    void setX(int x)
        { _x = x; }
    int y()
        { return _y; }
    void setY(int y)
        { _y = y; }
    void addApp(LocalApp *app);
    void delApp(int x, int y);
private:
    QString _name;
    QString _icon;
    QString _version;
    QString _execname;
    QString _uninstName;
    Status _status;
    int _x;
    int _y;
};

class LocalAppList
{
public:
    LocalAppList(QString dbname);
    ~LocalAppList();
    void addApp(LocalApp*);
    void delApp(int x, int y);
    LocalApp * getAppByName(QString name);
    LocalApp* at(int i);
    int count();
private:
    QString _db;
    QVector<LocalApp*> _list;
};

#endif
