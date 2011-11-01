#include<QPainter>
#include<QMouseEvent>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QtGui>
#include <QStyledItemDelegate>
#include "tableview.h"
#include "itemdelegate.h"
#include "itemmodel.h"

#ifndef NDEBUG
#include<QDebug>
#endif

TableView::TableView(QWidget * parent) :QTableView(parent)
{
	setEditTriggers(QAbstractItemView::NoEditTriggers);
	setAlternatingRowColors(true);
	setStyleSheet("alternate-background-color: rgb(227, 255, 214);");
	setSelectionMode(QAbstractItemView::NoSelection);
		setMouseTracking(true);//important
	installEventFilter(this);
    _delegate = new ItemDelegate;
    _proxy = new SoftwareProxyModel;
    _model = new ItemModel(this);
    _proxy->setSourceModel(_model);
    _proxy->setDynamicSortFilter(true);
    setModel(_proxy);
    setItemDelegate(_delegate);
    //_proxy->filterPkgStatus(1);
    /*
    QString searchstr = QString("eog");
    _proxy->setFilterRegExp(QRegExp(searchstr, Qt::CaseInsensitive));
    _proxy->setFilterKeyColumn(1);
    */
    rearrange();
}

void TableView::rearrange()
{
	horizontalHeader()->setResizeMode(1, QHeaderView::Stretch);
	setShowGrid(false);
	setColumnWidth(0,ICONCOLUMNWIDTH);
	setColumnWidth(2,SIZECOLUMNWIDTH);
	setColumnWidth(3,BUTTONCOLUMNWIDTH);
	verticalHeader()->setDefaultSectionSize(VERTICALHEIGHT);
}

void TableView::mouseMoveEvent(QMouseEvent * event)
{
	int column = columnAt(event->x());
	int row = rowAt(event->y());
	if (column == ButtonColumn && row != -1) {
		setCursor(Qt::PointingHandCursor);
	}
	else {
		setCursor(Qt::ArrowCursor);
	}

}

int TableView::viewHeight()
{
	return	_model->rowCount() * VERTICALHEIGHT;
}

void TableView::search(const QString &txt)
{
}
