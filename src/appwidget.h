#ifndef APPWIDGET_H
#define APPWIDGET_H
#include <QListWidget>
#include "localapps.h"
#include "client/center.h"

class AppCenter;

class AppWidget : public QListWidget
{
    Q_OBJECT
public:
    AppWidget(QWidget *parent = NULL);
    ~AppWidget();
public slots:
    void runApp(QListWidgetItem *item);
/*
signals:
    void itemClicked(QListWidgetItem * item);
*/
private:
    LocalAppList *_local;
    AppCenter *_center;
};

#endif
