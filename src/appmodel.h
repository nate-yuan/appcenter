#ifndef APPMODEL_H
#define APPMODEL_H
#include "localapps.h"

class AppModel: public QAbstractListModel
{
    Q_OBJECT
public:
    AppModel(QObject *parent = NULL);
    ~AppModel() {};
private:
    LocalAppList *_list;
};
#endif
