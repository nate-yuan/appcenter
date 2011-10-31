#include <QRect>
#include <QDesktopWidget>
#include <QPalette>
#include <QEvent>
#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include <QWidget>
#include <QX11Info>
#include <QResizeEvent>
#include <QHBoxLayout>
#include <QListWidget>
#include <QVBoxLayout>
#include <QApplication>
#include <QAction>
#include <QMenu>
#include <iostream>

#ifdef LINUX_X11
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>
#endif

#include "dashboard.h"
#include "iconarea.h"
#include "pager.h"

Dashboard::Dashboard(QWidget *parent)
    :QWidget(parent, 
             Qt::WindowStaysOnBottomHint | Qt::FramelessWindowHint | Qt::Tool)
{

#ifdef LINUX_X11
    Atom net_wm_state_skip_taskbar = XInternAtom(QX11Info::display(), 
                                        "_NET_WM_STATE_SKIP_TASKBAR", False);
    Atom net_wm_state_skip_pager = XInternAtom(QX11Info::display(), 
                                        "_NET_WM_STATE_SKIP_PAGER", False);
    Atom net_wm_state = XInternAtom(QX11Info::display(), "_NET_WM_STATE", False);
    XChangeProperty(QX11Info::display(), winId(), net_wm_state, 
                    XA_ATOM, 32, PropModeAppend, 
                    (unsigned char *)&net_wm_state_skip_taskbar, 1);
    XChangeProperty(QX11Info::display(), winId(), net_wm_state, 
                    XA_ATOM, 32, PropModeAppend, 
                    (unsigned char *)&net_wm_state_skip_pager, 1);

#endif


    QVBoxLayout *vLayout;
    QLabel *stubTop;
    QHBoxLayout *hLayout;
    QPushButton *lButton;
    QPushButton *rButton;
    //QLabel *stubBot;

    vLayout = new QVBoxLayout(this);
    vLayout->setSpacing(0);
    vLayout->setContentsMargins(0, 0, 0, 10);

    stubTop = new QLabel(this);
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(stubTop->sizePolicy().hasHeightForWidth());
    stubTop->setSizePolicy(sizePolicy);
    stubTop->setMaximumSize(QSize(0, 0));
    vLayout->addWidget(stubTop);

    hLayout = new QHBoxLayout();
    hLayout->setSpacing(0);
    hLayout->setContentsMargins(0, 0, 0, 0);

    lButton = new QPushButton(this);
    lButton->setText("<");
    sizePolicy.setHeightForWidth(lButton->sizePolicy().hasHeightForWidth());
    lButton->setSizePolicy(sizePolicy);
    lButton->setMinimumSize(QSize(15, 50));
    lButton->setMaximumSize(QSize(15, 50));
    lButton->setStyleSheet(\
        "QPushButton{border-width:2;border-style:outset;border-radius:5px;}");

    hLayout->addWidget(lButton);

    iarea = new IconArea(this);
    hLayout->addWidget(iarea);

    rButton = new QPushButton(this);
    rButton->setText(">");
    sizePolicy.setHeightForWidth(rButton->sizePolicy().hasHeightForWidth());
    rButton->setSizePolicy(sizePolicy);
    rButton->setMinimumSize(QSize(15, 20));
    rButton->setMaximumSize(QSize(15, 50));
    rButton->setStyleSheet(\
        "QPushButton{border-width:2;border-style:outset;border-radius:5px;}");
    hLayout->addWidget(rButton);


    vLayout->addLayout(hLayout);


    QHBoxLayout *bottomLayout = new QHBoxLayout();
    //stubBot = new QLabel(this);
    //pager = new Pager(this); 
    QPushButton *b1 = new QPushButton(QIcon("images/heart.svg"), "text");
    sizePolicy.setHorizontalPolicy(QSizePolicy::Fixed);
    sizePolicy.setVerticalPolicy(QSizePolicy::Fixed);
    sizePolicy.setHeightForWidth(b1->sizePolicy().hasHeightForWidth());
    b1->setSizePolicy(sizePolicy);
    //pager->setSizePolicy(sizePolicy);
    //pager->setMaximumSize(QSize(300, 40));
    //pager->setMinimumSize(QSize(300, 40));
    bottomLayout->addWidget(b1, Qt::AlignHCenter | Qt::AlignJustify);

    vLayout->addLayout(bottomLayout);

    quitAction = new QAction("Quit", this);
    showAction = new QAction("Show", this);
    hideAction = new QAction("Hide", this);
    QMenu *trayMenu = new QMenu(this);
    trayMenu->addAction(showAction);
    trayMenu->addAction(hideAction);
    trayMenu->addAction(quitAction);

    tray = new QSystemTrayIcon(this);
    QIcon icon("images/heart.svg");
    tray->setIcon(icon);
    tray->setContextMenu(trayMenu);
    tray->show();

    
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(showAction, SIGNAL(triggered()), this, SLOT(show()));
    connect(hideAction, SIGNAL(triggered()), this, SLOT(hide()));
    connect(tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
        this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));

    connect(lButton, SIGNAL(clicked()), iarea, SLOT(slideLeft()));
    connect(rButton, SIGNAL(clicked()), iarea, SLOT(slideRight()));

    setGeoProper();
}

void Dashboard::setGeoProper()
{
    QDesktopWidget *d = QApplication::desktop();
    QRect r = d->availableGeometry();
    setGeometry(0, 0, r.width(), r.height());
	setFixedSize(r.width(), r.height());
}

void Dashboard::iconActivated(QSystemTrayIcon::ActivationReason)
{ 
    showAction->setEnabled(true);
    hideAction->setEnabled(true);
    if (this->isVisible() && !isMinimized())
        showAction->setEnabled(false);
    else
        hideAction->setEnabled(false);
}

void Dashboard::closeEvent(QCloseEvent *event)
{
    event->ignore();
}

void Dashboard::resizeEvent(QResizeEvent *event)
{
    QPixmap background("pics/bg.png");
    QPixmap resizeBackgroud=background.scaled(event->size());
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(resizeBackgroud));
    setPalette(palette);
}


