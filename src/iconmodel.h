#ifndef ICONMODEL_H
#define ICONMODEL_H

class IconModel : public QAbstractListModel
{
    Q_OBJECT
    IconModel(QObject *parent = NULL);
    ~IconModel() {};

#endif
