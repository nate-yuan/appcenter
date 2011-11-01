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
        :_pkg_stat(-1), _pkg_class(-1), _pkg_search(QString("")){};
    ~SoftwareProxyModel(){};
    void filterPkgClass(int pkg_class) { 
        _pkg_class = pkg_class; 
        invalidateFilter();}
    void filterPkgStatus(int pkg_stat) { 
        _pkg_stat = pkg_stat; 
        invalidateFilter(); }
    void filterPkgSearch(const QString &pkg_search) { 
        _pkg_search = pkg_search;
        invalidateFilter(); }
    //Node *getNode(QString name);
    //QModelIndex index(int row,int column, const QModelIndex & parent=QModelIndex()) const;
    //QModelIndex mapToSource(const QModelIndex &proxyIndex);
    //QModelIndex mapFromSource(const QModelIndex &sourceIndex);
protected:
    bool filterAcceptsRow(int sourceRow, \
        const QModelIndex &sourceParent) const;
private:
    int _pkg_class;
    int _pkg_stat;
    QString _pkg_search;
};

class ItemModel : public QAbstractTableModel
{
	Q_OBJECT
	public:
		ItemModel(QObject *parent = 0);
		virtual ~ ItemModel();

		QVariant data(const QModelIndex & index,
				int role=Qt::DisplayRole) const;

		QVariant headerData(int section,
				Qt::Orientation orientation,
				int role=Qt::DisplayRole) const;
        Node *getNode(QString name);
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
