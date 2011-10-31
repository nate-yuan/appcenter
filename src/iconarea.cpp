#include <QPalette>
#include <QDebug>
#include <QPixmap>
#include "iconarea.h"

IconArea::IconArea(QWidget *parent)
    : QListWidget(parent)
{
    QPalette iconPal;
    QBrush brush(QColor(0,0,0,0));
    brush.setStyle(Qt::SolidPattern);
    iconPal.setBrush(QPalette::All, QPalette::Base, brush);
    setPalette(iconPal);
    setStyleSheet("QListView {border-width:0;border-style:outset}");

    setDragEnabled(true);
    setWrapping(true);
    setWordWrap(true);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setViewMode(QListView::IconMode);
    setIconSize(QSize(60, 60));
    setGridSize(QSize(80, 80));
    setSpacing(10);
    setMovement(QListView::Snap);
    setAcceptDrops(true);
    setDropIndicatorShown(true);
    setFlow(QListView::TopToBottom);

    addIcon(QPixmap("apps/web-browser.png"), QPoint(0,0));
    addIcon(QPixmap("apps/system-file-manager.png"), QPoint(0,0));
    addIcon(QPixmap("apps/utilities-terminal.png"), QPoint(100,100));
}

void IconArea::addIcon(QPixmap pixmap, QPoint location)
{
    QListWidgetItem *iconItem = new QListWidgetItem(this);
    iconItem->setIcon(QIcon(pixmap));
    iconItem->setData(Qt::UserRole, QVariant(pixmap));
    iconItem->setData(Qt::UserRole+1, location);
    iconItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable
        | Qt::ItemIsDragEnabled);
}

void IconArea::slideLeft()
{
}

void IconArea::slideRight()
{
}
