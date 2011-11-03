#ifndef ITEMMODEL
#define ITEMMODEL

#include <QAbstractTableModel>
#include <QSortFilterProxyModel>
#include <QModelIndex>
#include <QDebug>
#include "appnode.h"
#define CLASSIFYPATH "./pkgClassify/"

enum State { Normal, Pressed, Hovered};

class SoftwareProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    SoftwareProxyModel()
        :_pkg_stat(ALLSTATUS), _pkg_class(ALLCLASS), \
         _pkg_search(QString("")){};

    ~SoftwareProxyModel(){};

    void filterPkgClass(PackageClass pkg_class) 
    { 
        _pkg_class = pkg_class; 
        invalidateFilter();
    }

    void filterPkgStatus(PackageStatus pkg_stat) 
    { 
        _pkg_stat = pkg_stat; 
        invalidateFilter(); 
    }

    void filterPkgSearch(const QString &pkg_search) 
    { 
        _pkg_search = pkg_search;
        invalidateFilter(); 
    }

    void getRecommended(bool recom) 
    { 
        _pkg_recom = recom;
        invalidateFilter(); 
    }

    void getAllInstalled(bool both) 
    { 
        _pkg_both = both;
        invalidateFilter(); 
    }
protected:
    bool filterAcceptsRow(int sourceRow, \
        const QModelIndex &sourceParent) const;
private:
    PackageClass _pkg_class;
    PackageStatus _pkg_stat;
    PackageStatus _pkg_stat_or;
    QString _pkg_search;
    bool _pkg_recom;
    bool _pkg_both;
};

class ItemModel : public QAbstractTableModel
{
	Q_OBJECT
public:
    ItemModel(QObject *parent = 0);
    virtual ~ ItemModel(){};

    QVariant data(const QModelIndex & index,
        int role=Qt::DisplayRole) const;

    QVariant headerData(int section,
        Qt::Orientation orientation,
        int role=Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent=QModelIndex()) const;
    int columnCount(const QModelIndex &parent=QModelIndex()) const;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole );
    bool insertRows ( int row,int count, const QModelIndex & parent = QModelIndex() );
    QModelIndex index(int row,int column,const QModelIndex & parent=QModelIndex()) const;
    void search(const QString& text);

protected:
    NodeList *                _nodeList;
    QString					  _searchString;
    QModelIndex               _currentIndex;
};

#endif
