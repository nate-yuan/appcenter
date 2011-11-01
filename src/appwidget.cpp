#include <QDebug>

#include "appwidget.h"
#include "constants.h"

AppWidget::AppWidget(QWidget * parent)
    : QListWidget(parent), _center(NULL)
{
    QPalette iconPal;
    QBrush brush(QColor(0,0,0,0));
    brush.setStyle(Qt::SolidPattern);
    iconPal.setBrush(QPalette::All, QPalette::Base, brush);
    setPalette(iconPal);
    setStyleSheet("QListView {border-width:0;border-style:outset}");

    setDragEnabled(true);
    setViewMode(QListView::IconMode);
    setIconSize(QSize(64, 64));
    setGridSize(QSize(90, 90));
    setSpacing(10);
    setMovement(QListView::Snap);
    setAcceptDrops(true);
    setDropIndicatorShown(true);
    setFlow(QListView::TopToBottom);

    //_center = new AppCenter();
    //_center->hide();

    _local = new LocalAppList(LOCAL_DBFILE);
    for (int i = 0; i < _local->count(); i++) {
        QListWidgetItem *appItem = new QListWidgetItem(this);
        appItem->setIcon(QIcon(_local->at(i)->icon()));
        appItem->setText(_local->at(i)->name());
    } 
    connect(this, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(runApp(QListWidgetItem*)));
}

AppWidget::~AppWidget() {}

void AppWidget::runApp(QListWidgetItem *item)
{
    LocalApp *la = _local->getAppByName(item->text());
    if (!la)
        return;
    if (la->execname() == "/") {
        qDebug() << "fuck";
        if (_center)
            _center->show();
        else {
            _center = new AppCenter();
            _center->show();
        }
    }
}
