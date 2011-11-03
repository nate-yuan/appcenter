#include "itemmodel.h"

bool SoftwareProxyModel::filterAcceptsRow(int sourceRow, \
        const QModelIndex &sourceParent) const
{
    QModelIndex sourceIndex;
    QString name;
    QString descr;
    PackageStatus status;
    PackageClass pclass;
    int recom;
    bool TEXT, STAT, CLASS, RECOM;

    sourceIndex = sourceModel()->index(sourceRow, NameColumn, sourceParent);
    name = sourceIndex.data(Qt::UserRole + 1).toString();
    descr = sourceIndex.data(Qt::UserRole + 2).toString();
    status = static_cast<PackageStatus>(sourceIndex.data(Qt::UserRole + 3).toInt());
    pclass = static_cast<PackageClass>(sourceIndex.data(Qt::UserRole + 4).toInt());
    recom = sourceIndex.data(Qt::UserRole + 5).toInt();

    TEXT = name.append(descr).contains(_pkg_search);
    STAT = (status == _pkg_stat);
    CLASS = (pclass == _pkg_class); 
    RECOM = true;
    if (_pkg_recom) //just show recommended
        RECOM = recom; 

    if (_pkg_both)
        STAT = (status == INSTALLED || status == OLD);

    if (_pkg_stat == ALLSTATUS)
        STAT = true;
    if (_pkg_class == ALLCLASS)
        CLASS = true;
    return STAT && CLASS && TEXT && RECOM;
}

ItemModel::ItemModel(QObject * parent)
	:QAbstractTableModel(parent)
{
    _nodeList = NodeList::instance();
}

QVariant ItemModel::data(
		const QModelIndex & index,
		int role) const
{
    int column;
    Node *node;
    QString name;

	column = index.column();
	node = (Node *)(index.internalPointer());
    name = node->name();

	if (NULL == node)
		return QVariant();

    if (role == Qt::UserRole + 1)
        return name;

    if (role == Qt::UserRole + 2)
        return node->descr();

    if (role == Qt::UserRole + 3)
        return node->status();

    if (role == Qt::UserRole + 4)
        return node->pkgClass();

    if (role == Qt::UserRole + 5)
        return node->favor();

	if (column == FavorColumn) {
	    if(role == Qt::ToolTipRole)
            return tr("Recommended");
        if (node->favor())
            return QPixmap("images/favourite.png")\
                .scaled(ICONWIDTH,ICONHEIGH);
        return QPixmap();
	}

	if (column == NameColumn)
        if (role == Qt::DisplayRole)
            return name; 

	if (column == DescrColumn)
        if (role == Qt::DisplayRole)
            return node->descr();

	return QVariant();
}

bool ItemModel::setData(const QModelIndex & index, const QVariant & value, int role )
{
	Q_UNUSED(role)
	return true;
}

QVariant ItemModel::headerData(int section,
		Qt::Orientation orientation,
		int role) const
{
    return "";
}

QModelIndex ItemModel::index(int row, int column, const QModelIndex & parent)const
{
	Q_UNUSED(parent)
	if(!hasIndex(row, column, parent))
		return QModelIndex();
    return createIndex(row, column, _nodeList->at(row));
}

int ItemModel::rowCount(const QModelIndex &parent)const
{
	Q_UNUSED(parent)
	return  _nodeList->count();

}

int ItemModel::columnCount(const QModelIndex &parent)const {
	Q_UNUSED(parent)
	return 4;
}

bool ItemModel::insertRows ( int row,int count, const QModelIndex & parent )
{
	Q_UNUSED(parent)
	beginInsertRows(QModelIndex(), row, row + count - 1);
	endInsertRows();
	return true;
}
