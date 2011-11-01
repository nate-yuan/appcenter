#ifndef MYTABLEVIEW_H
#define MYTABLEVIEW_H

#include<QTableView>
#include <QModelIndex>
#include<QPixmap>
#include <iostream>
#include <QtGui/QSortFilterProxyModel>
#include "appnode.h"
#include "itemmodel.h"
#include "itemdelegate.h"

class ItemDelegate;
class ItemModel;

class TableView : public QTableView
{
	Q_OBJECT
	public:
		TableView(QWidget* parent = NULL);
		virtual ~TableView(){}
		void search(const QString& text);
        int viewHeight();
		SoftwareProxyModel* proxy() {
            return _proxy;}
		ItemDelegate* delegate() { return _delegate; }
	protected:
		void mouseMoveEvent(QMouseEvent * event);
		void rearrange();

    private:
        SoftwareProxyModel *_proxy;
        ItemDelegate* _delegate;
        ItemModel * _model;
};

#endif
