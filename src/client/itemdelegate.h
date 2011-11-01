#ifndef ITEMDELEGATE
#define ITEMDELEGATE
#include <QItemDelegate>
#include "itemmodel.h"
class ItemDelegate:public QItemDelegate {
  Q_OBJECT
  public:
	 ItemDelegate(QObject * parent = 0);
	 virtual ~ ItemDelegate() {}
	 void paint(QPainter * painter,
				 const QStyleOptionViewItem & option,
				 const QModelIndex & index) const;
	bool editorEvent(QEvent * event,
					 QAbstractItemModel * model,
					 const QStyleOptionViewItem & option,
					 const QModelIndex & index);
signals:
	void needsUpdate(const QModelIndex &);
	void clicked(const QModelIndex &);
  private:
	QPixmap favouritePixmap;
	QPixmap notFavouritePixmap;
	QModelIndex m_lastUnderMouse;

};
#endif
