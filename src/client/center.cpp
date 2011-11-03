#include <QWidget>
#include <QHBoxLayout>
#include <QListWidget>
#include <QVBoxLayout>

#include "tabbar.h"
#include "titlebar.h"
#include "center.h"
#include "packageWidget.h"
#include "detailWidget.h"

AppCenter::AppCenter(QWidget *parent)
    :QWidget(parent)
{
    setFixedSize(902, 580);
    setWindowIcon(QIcon("images/applications-other.png"));
	TitleBar* titleBar = new TitleBar;
	titleBar->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

	pWidget = new PackageWidget;
    pWidget->setPictureFrameVisible(true);

    dWidget = new DetailWidget;

	TabBar* leftBar = new TabBar;
	leftBar->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

	QWidget *tmp=new QWidget;
	tmp->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
	tmp->resize(792,496);
	tmp->setAutoFillBackground(true);
	QPalette palette;
	palette.setColor(QPalette::Background, QColor(255,255,255));
	tmp->setPalette(palette);
	tmp->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

	stackedLayout = new QStackedLayout;
	stackedLayout->addWidget(pWidget);
    stackedLayout->addWidget(dWidget);
    stackedLayout->setCurrentIndex(0);
	pWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

	QHBoxLayout *mainLayout = new QHBoxLayout(tmp);
	mainLayout->addLayout(stackedLayout);
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

	connect(leftBar,SIGNAL(currentChanged(int)),pWidget,SLOT(showCurrent(int)));
	connect(leftBar,SIGNAL(currentChanged(int)),this,SIGNAL(clearSearch()));

	connect(this, SIGNAL(clearSearch()), titleBar, SLOT(clearSearch()));
	connect(pWidget, SIGNAL(clearSearch()), titleBar, SLOT(clearSearch()));

	connect(pWidget, SIGNAL(searchChanged(const QString&)),
			titleBar, SLOT(setSearch(const QString&)));
	connect(titleBar, SIGNAL(searchChanged(const QString&)),
			pWidget, SIGNAL(search(const QString&)));

    showMaximized ();
}

AppCenter::~AppCenter() 
{
}


void AppCenter::resizeEvent(QResizeEvent *event)
{
	QPixmap background("images/bg.png");
	QPixmap resizeBackgroud=background.scaled(event->size());
	QPalette palette;
	palette.setBrush(backgroundRole(), QBrush(resizeBackgroud));
	setPalette(palette);
}
