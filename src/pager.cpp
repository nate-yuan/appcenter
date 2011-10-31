#include "pager.h"
#include <QHBoxLayout>
#include <QIcon>

Pager::Pager(QWidget *parent)
    :QWidget(parent)
{
    /*
    QPalette iconPal;
    QBrush brush(QColor(0,0,0,0));
    brush.setStyle(Qt::SolidPattern);
    iconPal.setBrush(QPalette::All, QPalette::Base, brush);
    setPalette(iconPal);
    //setStyleSheet("QTabBar{border-width:0;border-style:outset}");
    */
    QPushButton button("text");
    /*
    QHBoxLayout *hLayout = new QHBoxLayout();
    QButtonGroup *group = new QButtonGroup(); 
    QPushButton *b1 = new QPushButton(QIcon("images/heart.svg"), "1");
    QPushButton *b2 = new QPushButton(QIcon("images/heart.svg"), "2");
    QPushButton *b3 = new QPushButton(QIcon("images/heart.svg"), "3");
    QPushButton *b4 = new QPushButton(QIcon("images/heart.svg"), "4");
    group->addButton(b1, 0);
    group->addButton(b2, 1);
    group->addButton(b3, 2);
    group->addButton(b4, 3);
    hLayout->addWidget(b1, Qt::AlignHCenter);
    */
}
