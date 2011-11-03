#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

#include "detailWidget.h"

DetailWidget::DetailWidget(QWidget * parent) 
    : QWidget(parent)
{
    QVBoxLayout *mainLayout;
    QHBoxLayout *upperLayout;
    QVBoxLayout *labLayout;
    QSpacerItem *spacerUp;
    QSpacerItem *spacerMid;
    QHBoxLayout *midLayout;

    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);

    mainLayout = new QVBoxLayout(this);
    upperLayout = new QHBoxLayout();

    iconBox = new QGraphicsView(this);
    sizePolicy.setHeightForWidth(iconBox->sizePolicy().hasHeightForWidth());
    iconBox->setSizePolicy(sizePolicy);
    iconBox->setMinimumSize(QSize(96, 96));
    iconBox->setMaximumSize(QSize(96, 96));

    upperLayout->addWidget(iconBox);

    labLayout = new QVBoxLayout();
    nameLab = new QLabel(this);
    nameLab->setText("");
    sizePolicy.setHeightForWidth(nameLab->sizePolicy().hasHeightForWidth());
    nameLab->setSizePolicy(sizePolicy);
    labLayout->addWidget(nameLab);

    sizeLab = new QLabel(this);
    sizeLab->setText("");
    sizePolicy.setHeightForWidth(sizeLab->sizePolicy().hasHeightForWidth());
    sizeLab->setSizePolicy(sizePolicy);
    sizeLab->setMinimumSize(QSize(40, 60));
    labLayout->addWidget(sizeLab);

    briefLab = new QLabel(this);
    briefLab->setText("");
    sizePolicy.setHeightForWidth(briefLab->sizePolicy().hasHeightForWidth());
    briefLab->setSizePolicy(sizePolicy);
    labLayout->addWidget(briefLab);


    upperLayout->addLayout(labLayout);
    spacerUp = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    upperLayout->addItem(spacerUp);

    mainLayout->addLayout(upperLayout);

    midLayout = new QHBoxLayout();
    instButton = new QPushButton(this);
    instButton->setText("");
    sizePolicy.setHeightForWidth(instButton->sizePolicy().hasHeightForWidth());
    instButton->setSizePolicy(sizePolicy);
    midLayout->addWidget(instButton);

    progressBar = new QProgressBar(this);
    progressBar->setValue(0);
    progressBar->setVisible(false);
    midLayout->addWidget(progressBar);

    progressLab = new QLabel(this);
    progressLab->setText("");
    sizePolicy.setHeightForWidth(progressLab->sizePolicy().hasHeightForWidth());
    progressLab->setSizePolicy(sizePolicy);
    midLayout->addWidget(progressLab);

    spacerMid = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    midLayout->addItem(spacerMid);
    mainLayout->addLayout(midLayout);

    textBrowser = new QTextBrowser(this);
    mainLayout->addWidget(textBrowser);
};
