#include "itemdelegate.h"
#include "itemmodel.h"
#include <QApplication>
#include <QPainter>
#include <QEvent>
ItemDelegate::ItemDelegate(QObject * parent):QItemDelegate(parent)
{
}

void ItemDelegate::paint(QPainter * painter,
		const QStyleOptionViewItem & option,
		const QModelIndex & index) const
{
    int column;
    int status;
    QString name;

	if (!index.isValid()) {
		return;
	}

    column = index.column();
    name = index.data(Qt::UserRole + 1).toString();
    status = index.data(Qt::UserRole + 2).toInt();

    if (column == FavorColumn) {
        return;
    }

    QFont font = option.font;
    QFontMetrics fm(font);
    font.setPointSize(font.pointSize() - 1);

    /*
	if (column == NameColumn) {
		QRectF nameRectF(option.rect.x(), option.rect.y() + 5,
				option.rect.width(), option.rect.height() * 0.6);
		painter->drawText(nameRectF, Qt::AlignLeft | Qt::AlignTop, name);
        return;
	} 

    if (column == DescrColumn) {
		QRectF nameRectF(option.rect.x(), option.rect.y() + 5,
				option.rect.width(), option.rect.height() * 0.6);
		painter->drawText(nameRectF, Qt::AlignLeft | Qt::AlignTop, \
            index.data(Qt::DisplayRole, DescrColumn));
        return;
    }
    */

    if (column == ButtonColumn) {
		QStyleOptionButton opt;
        switch(status) {
          case 0:
            opt.text = trUtf8("Install");
            break;
          case 1:
            opt.text = trUtf8("UnInstall");
            break;
          case 2:
            opt.text = trUtf8("Update");
            break;
          case 3:
            opt.text = trUtf8("Cancel");
        }
        opt.state |= QStyle::State_HasFocus;
		opt.rect = option.rect.adjusted(1, 1, -1, -1);

		QApplication::style()->drawControl(QStyle::CE_PushButton, &opt,
				painter, 0);
        return;
	}

    QItemDelegate::paint(painter, option, index);
}

bool ItemDelegate::editorEvent(QEvent * event,
		QAbstractItemModel * model,
		const QStyleOptionViewItem & option,
		const QModelIndex & index)
{
    int status;
    QString name;

    if (!index.isValid() || index.column() != ButtonColumn)
	    return QItemDelegate::editorEvent(event, model, option, index);

    name = index.data(Qt::UserRole + 1).toString();
    status = index.data(Qt::UserRole + 2).toInt(); 

    if (event->type() == QEvent::MouseButtonPress
        || event->type() == QEvent::MouseButtonDblClick) {
        //emit a singal with name parameter
    }
	return QItemDelegate::editorEvent(event, model, option, index);
}
