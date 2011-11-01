#include <QWidget>
#include <QHBoxLayout>
#include <QListWidget>
#include <QVBoxLayout>
#include "rftabbar.h"
#include "rftitlebar.h"
#include "center.h"
#include "packageWidget.h"

AppCenter::AppCenter(QWidget *parent)
    :QWidget(parent)
{
	RFTitleBar* titleBar = new RFTitleBar;
	titleBar->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

	pWidget = new PackageWidget;
    pWidget->setPictureFrameVisible(true);

	RFTabBar* leftBar = new RFTabBar;
	leftBar->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

	QWidget *tmp=new QWidget;
	tmp->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
	tmp->resize(792,496);
	tmp->setAutoFillBackground(true);
	QPalette palette;
	palette.setColor(QPalette::Background, QColor(255,255,255));
	tmp->setPalette(palette);
	tmp->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

	rightLayout = new QHBoxLayout;
	rightLayout->addWidget(pWidget);
	pWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

	QHBoxLayout *mainLayout = new QHBoxLayout(tmp);
	mainLayout->addLayout(rightLayout);
	tmp->setLayout(mainLayout);


	QVBoxLayout* leftvlayout = new QVBoxLayout;
	QLabel* logo = new QLabel("");
	logo->setPixmap(QPixmap("images/package.png"));
	leftvlayout->addWidget(logo);
	leftvlayout->addWidget(leftBar);
	QSpacerItem* spacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
	leftvlayout->addItem(spacer);

	QHBoxLayout* hlayout = new QHBoxLayout(this);
	hlayout->addLayout(leftvlayout);
	hlayout->addWidget(tmp);
	hlayout->setSpacing(0);

	QVBoxLayout* vlayout = new QVBoxLayout;
	vlayout->addWidget(titleBar);
	vlayout->addWidget(tmp);
	hlayout->addLayout(vlayout);

	leftvlayout->setSpacing(0);
	leftvlayout->setContentsMargins(0, 0, 0, 0);

	vlayout->setSpacing(0);
	vlayout->setContentsMargins(0, 0, 0, 0);

	hlayout->setSpacing(0);
	hlayout->setContentsMargins(5, 0, 5, 34);

	setMaximumWidth(902);
	setMinimumWidth(902);
	setMinimumHeight(580);

	connect(leftBar,SIGNAL(currentChanged(int)),this,SLOT(changeCurrentView(int)));

	connect(this, SIGNAL(clearSearch()), titleBar, SLOT(clearSearch()));

	connect(pWidget, SIGNAL(clearSearch()), titleBar, SLOT(clearSearch()));

	connect(pWidget, SIGNAL(searchChanged(const QString&)),
			titleBar, SLOT(setSearch(const QString&)));

	connect(titleBar, SIGNAL(searchChanged(const QString&)),
			this, SLOT(onTextChanaged(const QString&)));

    //setWindowFlags(windowFlags() | Qt::WindowStaysOnBottomHint | Qt::FramelessWindowHint);
    //setWindowFlags(Qt::WStyle_NoBorder | Qt::WStyle_Customize);
    showMaximized ();

}

AppCenter::~AppCenter()
{}

void AppCenter::changeCurrentView(int index)
{
	emit clearSearch();
	pWidget->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    switch(index) {
    case 0:
        pWidget->setPictureFrameVisible(true);
        pWidget->setButtonsVisible(true);
        pWidget->tableView->proxy()->filterPkgStatus(-1);
	    pWidget->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        break;
    case 1:
        pWidget->setPictureFrameVisible(false);
        pWidget->setButtonsVisible(true);
        pWidget->tableView->proxy()->filterPkgStatus(-1);
        break;
    case 2:
        pWidget->setPictureFrameVisible(false);
        pWidget->setButtonsVisible(false);
        pWidget->tableView->proxy()->filterPkgStatus(2);
        pWidget->tableView->proxy()->filterPkgClass(-1);
        break;
    case 3:
        pWidget->setPictureFrameVisible(false);
        pWidget->setButtonsVisible(false);
        pWidget->tableView->proxy()->filterPkgStatus(1);
        pWidget->tableView->proxy()->filterPkgClass(-1);
    }
}

void AppCenter::onTextChanaged(const QString& text)
{
	qDebug() << text;
    pWidget->tableView->proxy()->filterPkgSearch(text);
}

void AppCenter::resizeEvent(QResizeEvent *event)
{
	QPixmap background("images/bg.png");
	QPixmap resizeBackgroud=background.scaled(event->size());
	QPalette palette;
	palette.setBrush(backgroundRole(), QBrush(resizeBackgroud));
	setPalette(palette);
}
