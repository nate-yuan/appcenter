#include "packageWidget.h"
#include "tableview.h"

PackageWidget::PackageWidget(QWidget *parent): QScrollArea(parent)
{

	_frame = new QWidget;
	pictureFrame   = new PictureFrame;
	tableView      = new TableView;
	tableView->setAutoScroll(false);
    tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	createGroupButton();
	QVBoxLayout *vlayout=new QVBoxLayout(_frame);
	vlayout->addWidget(pictureFrame);
    pictureFrame->setVisible(false);
	vlayout->addWidget(buttonWidget);
	vlayout->addWidget(tableView);
	vlayout->setSpacing(0);

	setMinimumWidth(750);
	setMaximumWidth(750);

	setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setWidget(_frame);
	_frame->setMinimumWidth(706);
	_frame->setMaximumWidth(706);

	connect(buttonGroup,SIGNAL(buttonClicked(int)),tableView,SLOT(classChange(int)));
	connect(buttonGroup,SIGNAL(buttonClicked(int)),this,SLOT(setCurrentButton(int)));

	connect(pictureFrame, SIGNAL(searchChanged(const QString&)), this,
			SIGNAL(searchChanged(const QString&)));
    connect(this, SIGNAL(search(const QString&)), tableView, SLOT(search(const QString&)));
    allResize();
}

void PackageWidget::showCurrent(int index)
{
    bool hasPic = false;
    bool hasBut = true;

    switch(index) {
    case 0:
        hasPic = true;
        tableView->showRecommended();
        break;
    case 1:
        tableView->showNormal();
        break;
    case 2:
        hasBut = false;
        tableView->showUpdates();
        break;
    case 3:
        hasBut = false;
        tableView->showInstalled();
    }
    setPictureFrameVisible(hasPic);
    setButtonsVisible(hasBut);
}

void PackageWidget::setButtonsVisible(bool vis)
{
    int i;
    for (i = 0; i < buttonGroup->buttons().count(); i++)
        buttonGroup->buttons()[i]->setVisible(vis);
}

void PackageWidget::createGroupButton()
{
    all = new QPushButton(tr("All"));
	professional = new QPushButton(tr("Professional"));
	network = new QPushButton(tr("Network"));
	media = new QPushButton(tr("Media"));
	driver = new QPushButton(tr("Driver"));
	develop = new QPushButton(tr("Develop"));
	other = new QPushButton(tr("Other"));

    all->setCheckable(true);
	professional->setCheckable(true);
	network->setCheckable(true);
	media->setCheckable(true);
	driver->setCheckable(true);
	develop->setCheckable(true);
	other->setCheckable(true);

	buttonWidget=new QWidget(_frame);
	QHBoxLayout *hlayout=new QHBoxLayout(buttonWidget);

	buttonGroup = new QButtonGroup(this);
	buttonGroup->addButton(all, 0);
	buttonGroup->addButton(professional, 1);
	buttonGroup->addButton(network, 2);
	buttonGroup->addButton(media, 3);
	buttonGroup->addButton(driver, 4);
	buttonGroup->addButton(develop, 5);
	buttonGroup->addButton(other, 6);

	hlayout->addWidget(all);
	hlayout->addWidget(professional);
	hlayout->addWidget(network);
	hlayout->addWidget(media);
	hlayout->addWidget(driver);
	hlayout->addWidget(develop);
	hlayout->addWidget(other);

	hlayout->setSpacing(0);
	hlayout->setContentsMargins(0, 0, 0, 0);

	buttonGroup->setExclusive(true);

    all->setChecked(true);
}

void PackageWidget::setPictureFrameVisible(bool vis)
{
    pictureFrame->setVisible(vis);
    allResize();
}

void PackageWidget::allResize()
{
    QSize size = _frame->size();
    int offset = size.height()
        - (pictureFrame->height() + buttonWidget->height() + tableView->height());
    int height = pictureFrame->height() + buttonWidget->height()
        + tableView->viewHeight() + offset + 14;
    size.setHeight(qMax(height, childrenRect().height() - 14));
    _frame->resize(size);
}

void PackageWidget::setCurrentButton(int id)
{
    allResize();
	emit clearSearch();
}
