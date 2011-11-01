#include "itemmodel.h"

bool SoftwareProxyModel::filterAcceptsRow(int sourceRow, \
        const QModelIndex &sourceParent) const
{
    QModelIndex pkgClassIndex = sourceModel()->index(sourceRow,3,sourceParent);
    Node *node = static_cast<Node*>(pkgClassIndex.internalPointer());

    bool TEXT = node->name().append(node->descr()).contains(_pkg_search);
    bool STAT = node->status() == _pkg_stat;
    bool CLASS = node->pkgClass() == _pkg_class; 
    if (_pkg_stat == -1)
        STAT = true;
    if (_pkg_class == -1)
        CLASS = true;
    return STAT && CLASS && TEXT;
}

    /*
QModelIndex SoftwareProxyModel::
index(int row,int column, const QModelIndex & parent) const
{
	//Q_UNUSED(parent)
	if(!hasIndex(row, column, parent))
		return QModelIndex();
    QModelIndex index = QSortFilterProxyModel::index(row, 1);
    QString name = index.data(Qt::FontRole).toString();
    Node *node = static_cast<ItemModel*>(sourceModel())->getNode(name);
    qDebug() << "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT" << node->descr();
    return createIndex(row, column, node);
}
    */

/*
Node * SoftwareProxyModel::getNode(QString name)
{
    return static_cast<ItemModel*>(SourceModel())->getNode(name);
}
*/

ItemModel::ItemModel(QObject * parent)
	:QAbstractTableModel(parent)
{
    _nodeList = NodeList::instance();
}

ItemModel::~ItemModel(){}

Node * ItemModel::getNode(QString name)
{
    int i;
    for (i = 0; i < _nodeList->count(); i++) {
        if (_nodeList->at(i)->name() == name) 
            return _nodeList->at(i);
        return NULL;
    }
}

bool ItemModel::insertRows ( int row,int count, const QModelIndex & parent )
{
	Q_UNUSED(parent)
	beginInsertRows(QModelIndex(), row, row + count - 1);
	endInsertRows();
	return true;
}

bool ItemModel::setData(const QModelIndex & index, const QVariant & value, int role )
{
	Q_UNUSED(role)
	Node *v= (Node *)index.internalPointer();
	v->setStatus(value.toInt());
	qDebug() << v->status();
	emit (dataChanged(index,index));
	return true;
}

QVariant ItemModel::data(
		const QModelIndex & index,
		int role) const
{
	int column = index.column();
	Node *node=(Node *)(index.internalPointer());
	if (NULL == node)
		return QVariant();

    if (role == Qt::FontRole)
        return node->name();
    if (role == Qt::AccessibleTextRole)
        return node->status();

	if(role == Qt::UserRole && column == ButtonColumn)
		return node->status();

	if (role == Qt::DisplayRole && column == NameColumn)
		return node->name();

	if (role == Qt::DecorationRole&& column == NameColumn)
		return node->descr();

	if (role == Qt::DecorationRole&&column == IconColumn) {
		if(!node->icon().isNull())
			return node->icon().scaled(ICONWIDTH,ICONHEIGH);
		else return QPixmap();
	}

	if (role == Qt::DisplayRole && column == SizeColumn) {
		if (node->size() > 0) {
			double size = node->size();
			QString sizeStr = QString("%1M").arg(size,0,'f',2);
			return sizeStr;
		}
		else
			return QString("Unknow");
	}
	if (role == Qt::UserRole && column == SizeColumn) {
        return node->progress();
	}
	if(role == Qt::ToolTipRole && column==IconColumn)
		return tr("Icons");
	return QVariant();
}

QVariant ItemModel::headerData(int section,
		Qt::Orientation orientation,
		int role) const
{
	if(section==0 && orientation==Qt::Horizontal){
		if(role==Qt::DecorationRole)
			return QPixmap(":/favourite.png");
		if(role==Qt::DisplayRole)
			return "";
		if(role==Qt::ToolTipRole)
			return tr("love");
	}
	return "header";
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

QModelIndex ItemModel::index(int row, int column, const QModelIndex & parent)const
{
	Q_UNUSED(parent)
	if(!hasIndex(row, column, parent))
		return QModelIndex();
    return createIndex(row, column, _nodeList->at(row));
}
