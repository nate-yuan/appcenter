#ifndef LOCALAPPS_H
#define LOCALAPPS_H

#define PAGENUM 4
#include <QVector>

enum Status {havenot, downloaded, installed, old};

class LocalApp
{
public:
    LocalApp();
    ~LocalApp();
    QString name();
    void setName(QString &name) 
        {_name = name;}
    QString icon();
    void setIcon(QString &icon) 
        {_icon = icon;}
    QString version();
    void setVersion(QString &version)
        {_version = version;}
    QString execname();
    void setExecname(QString &execname)
        {_execname = execname;}
    QString uninstName();
    void setUninstName(QString &uninstName)
        {_uninstName = uninstName;}
    Status status();
    void setStatus(Status status)
        {_status = status;}
    int x();
    void setX(int x)
        { _x = x; }
    int y();
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
    LocalAppList();
    ~LocalAppList();
    addApp(LocalApp&);
    delApp(QString name);
    int whichPage(int x, int y);
private:
    QString _db;
    QVector<LocalApp*> _list[PAGENUM];
};

#endif
