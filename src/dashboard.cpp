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
        Qt::WindowStaysOnBottomHint | Qt::FramelessWindowHint)
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

    QGridLayout *layout;
    QSpacerItem *vSpacer1;
    QSpacerItem *vSpacer2;
    QSpacerItem *vSpacer3;
    QSpacerItem *vSpacer4;
    QPushButton *lButton;
    QPushButton *rButton;

    layout = new QGridLayout(this);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);

    vSpacer1 = new QSpacerItem(20, 190, QSizePolicy::Minimum, QSizePolicy::Expanding);
    layout->addItem(vSpacer1, 0, 0, 1, 1);

    iarea = new IconArea(this);
    layout->addWidget(iarea, 0, 1, 4, 1);

    lButton = new QPushButton(this);
    lButton->setText("<");
    sizePolicy.setHeightForWidth(lButton->sizePolicy().hasHeightForWidth());
    lButton->setSizePolicy(sizePolicy);
    lButton->setMinimumSize(QSize(15, 50));
    lButton->setMaximumSize(QSize(15, 50));
    lButton->setStyleSheet(\
        "QPushButton{border-width:2;border-style:outset;border-radius:5px;}");
    layout->addWidget(lButton, 1, 0, 1, 1);

    rButton = new QPushButton(this);
    rButton->setText(">");
    sizePolicy.setHeightForWidth(rButton->sizePolicy().hasHeightForWidth());
    rButton->setSizePolicy(sizePolicy);
    rButton->setMinimumSize(QSize(15, 20));
    rButton->setMaximumSize(QSize(15, 50));
    rButton->setStyleSheet(\
        "QPushButton{border-width:2;border-style:outset;border-radius:5px;}");
    layout->addWidget(rButton, 1, 2, 1, 1);
    vSpacer2 = new QSpacerItem(20, 222, QSizePolicy::Minimum, QSizePolicy::Expanding);
    layout->addItem(vSpacer2, 2, 0, 2, 1);
    vSpacer3 = new QSpacerItem(20, 190, QSizePolicy::Minimum, QSizePolicy::Expanding);
    layout->addItem(vSpacer3, 2, 2, 1, 1);

    pager = new Pager(this); 
    sizePolicy.setHorizontalPolicy(QSizePolicy::Fixed);
    sizePolicy.setVerticalPolicy(QSizePolicy::Fixed);
    sizePolicy.setHeightForWidth(pager->sizePolicy().hasHeightForWidth());
    pager->setSizePolicy(sizePolicy);
    pager->setSizePolicy(sizePolicy);
    layout->addWidget(pager, 3, 2, 1, 1);


    vLayout->addLayout(hLayout);


    QHBoxLayout *bottomLayout = new QHBoxLayout();
    //pager->setMaximumSize(QSize(300, 40));
    //pager->setMinimumSize(QSize(800, 40));
    //bottomLayout->addWidget(pager, Qt::AlignRight | Qt::AlignJustify);

    //vLayout->addLayout(bottomLayout, Qt::AlignRight);

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
    connect(showAction, SIGNAL(triggered()), this, SLOT(showMaximized()));
    connect(hideAction, SIGNAL(triggered()), this, SLOT(hide()));
    connect(tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
        this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));

    connect(lButton, SIGNAL(clicked()), iarea, SLOT(slideLeft()));
    connect(rButton, SIGNAL(clicked()), iarea, SLOT(slideRight()));
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
