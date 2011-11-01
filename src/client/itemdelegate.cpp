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
	if (!index.isValid()) {
		return;
	}

	if (index.column() == NameColumn) {
		QFont font = option.font;
		QFontMetrics fm(font);

		font.setPointSize(font.pointSize() - 1);
		QRectF nameRectF(option.rect.x(), option.rect.y() + 5,
				option.rect.width(), option.rect.height() * 0.6);
		QRectF desRectF(option.rect.x(),
				option.rect.y() + option.rect.height() * 0.6,
				option.rect.width(), option.rect.height() * 0.4);
		painter->drawText(nameRectF, Qt::AlignLeft | Qt::AlignTop,
				index.data(Qt::DisplayRole).toString());
		painter->save();
		painter->setFont(font);
		painter->drawText(desRectF, Qt::AlignLeft | Qt::AlignTop,
				index.data(Qt::DecorationRole).toString());
		painter->restore();

	} else if (index.column() == SizeColumn) {
        //QModelIndex nameIndex = index(index.row(), 1);
        QString name = index.data(Qt::FontRole).toString();
        int s  = index.data(Qt::AccessibleTextRole).toInt();
        Node *node = static_cast<Node*>(index.internalPointer());
        cout << "66666666666666666666 " << node << endl;
		if (3 == s) {
			QStyleOptionProgressBar opt;
			opt.maximum  = 100;
			opt.minimum  = 0;
			opt.progress = index.data(Qt::UserRole).toInt();
			qDebug() << opt.progress;
			double adjust = option.rect.height() / 4;
			QRectF rt = option.rect;

			rt.adjust(0, adjust, 0, -adjust);
			opt.rect = rt.toRect();

            opt.text = trUtf8("Processing");

			QApplication::style()->drawControl(QStyle::CE_ProgressBar, &opt, painter, 0);
			QApplication::style()->drawControl(QStyle::CE_ProgressBarLabel, &opt, painter, 0);
		} else {
			QStyleOptionViewItem opt=option;
			opt.displayAlignment = Qt::AlignRight|Qt::AlignVCenter;
			QItemDelegate::paint(painter, opt, index);
		}
	} else if (index.isValid() && index.column() == ButtonColumn) {
		QStyleOptionButton opt;
        int stat = index.data(Qt::UserRole).toInt();
        switch(stat) {
          case 0:
            opt.text = trUtf8("Install");
            //opt.text = "Install";
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
	} else {
		QItemDelegate::paint(painter, option, index);
	}
}

bool ItemDelegate::editorEvent(QEvent * event,
		QAbstractItemModel * model,
		const QStyleOptionViewItem & option,
		const QModelIndex & index)
{

    if (!index.isValid() || index.column() != ButtonColumn)
	    return QItemDelegate::editorEvent(event, model, option, index);
 
    if (event->type() == QEvent::MouseButtonPress
        || event->type() == QEvent::MouseButtonDblClick) {

        int stat = index.data(Qt::UserRole).toInt();
        QModelIndex a = model->index(index.row(), 1);
        QString name = a.data(Qt::DisplayRole).toString(); 
        switch (stat){
        case 0:
            qDebug() << "install " << name;
            model->setData(index, QVariant(3), Qt::UserRole);
            break;
        case 1:
            qDebug() << "uninstall " << name;
            model->setData(index, QVariant(0), Qt::UserRole);
            break;
        case 2:
            qDebug() << "update " << name;
            model->setData(index, QVariant(3), Qt::UserRole);
            break;
        case 3:
            qDebug() << "uninstall " << name;
            model->setData(index, QVariant(0), Qt::UserRole);
        case 4:
            qDebug() << "cancel " << name;
            model->setData(index, QVariant(2), Qt::UserRole);
            break;
        }
    }
	return QItemDelegate::editorEvent(event, model, option, index);
}
