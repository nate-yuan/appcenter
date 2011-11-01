#include "packageWidget.h"
#include "tableview.h"
#include <QCheckBox>
class MyCheckBox : public QCheckBox {
	Q_OBJECT
  public:
	MyCheckBox( const QString & text, QWidget * parent = 0) :
		QCheckBox(text, parent){}

  protected:
	virtual void paintEvent(QPaintEvent* event);

};

void MyCheckBox::paintEvent(QPaintEvent* event)
{
	Q_UNUSED(event)

	QPainter painter(this);
	QRect rt = childrenRect();
	painter.setRenderHint(QPainter::Antialiasing);

	painter.setPen(QPen(Qt::black));
	painter.fillRect(rt, QBrush(QColor(255, 255, 255, 255)));
	rt = rt.adjusted(1, 1, -2, -1);
	painter.setRenderHint(QPainter::Antialiasing, false);
	painter.setPen(QPen(QColor(100,100,100)));
	painter.drawRect(rt);
}


/****************************************************************************/


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

	connect(buttonGroup,SIGNAL(buttonClicked(int)),this,SLOT(setCurrentButton(int)));
	connect(tableView,SIGNAL(finished()),this,SLOT(onFinished()));

	connect(pictureFrame, SIGNAL(searchChanged(const QString&)), this,
			SIGNAL(searchChanged(const QString&)));
    allResize();
}

void PackageWidget::setButtonsVisible(bool vis)
{
    int i;
    for (i = 0; i < buttonGroup->buttons().count(); i++)
        buttonGroup->buttons()[i]->setVisible(vis);
}

PackageWidget::~PackageWidget()
{
}

void PackageWidget::createGroupButton()
{
	networkApp=new QPushButton(tr("NetworkApp"));
	mediaApp=new QPushButton(tr("MediaApp"));
	gameApp=new QPushButton(tr("GameApp"));
	graphicsApp=new QPushButton(tr("GraphicsApp"));
	wordsApp=new QPushButton(tr("WordsApp"));
	devApp=new QPushButton(tr("DevApp"));
	hardwareApp=new QPushButton(tr("HardwareDriv"));
	professionalApp=new QPushButton(tr("ProfessionalApp"));
	otherApp=new QPushButton(tr("OtherApp"));

	networkApp->setCheckable(true);

	mediaApp->setCheckable(true);

	gameApp->setCheckable(true);

	graphicsApp->setCheckable(true);

	wordsApp->setCheckable(true);

	devApp->setCheckable(true);

	hardwareApp->setCheckable(true);

	professionalApp->setCheckable(true);

	otherApp->setCheckable(true);

	buttonWidget=new QWidget(_frame);
	QHBoxLayout *hlayout=new QHBoxLayout(buttonWidget);

	buttonGroup = new QButtonGroup(this);
	buttonGroup->addButton(networkApp,0);
	buttonGroup->addButton(mediaApp,1);
	buttonGroup->addButton(gameApp,2);
	buttonGroup->addButton(graphicsApp,3);
	buttonGroup->addButton(wordsApp,4);
	buttonGroup->addButton(devApp,5);
	buttonGroup->addButton(hardwareApp,6);
	buttonGroup->addButton(otherApp,7);
	classifyList <<"web.txt"
		<<"multimedia.txt"<<"game.txt"<<"graphics.txt"<<"word.txt"
		<<"programming.txt"<<"driver.txt"<<"others.txt";


	hlayout->addWidget(networkApp);
	hlayout->addWidget(mediaApp);
	hlayout->addWidget(gameApp);
	hlayout->addWidget(graphicsApp);
	hlayout->addWidget(wordsApp);
	hlayout->addWidget(devApp);
	hlayout->addWidget(hardwareApp);
	hlayout->addWidget(otherApp);

	hlayout->setSpacing(0);
	hlayout->setContentsMargins(0, 0, 0, 0);

	currentButton=networkApp;
	buttonGroup->setExclusive(true);
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
	currentButton = static_cast<QPushButton*>(buttonGroup->button(id));
    tableView->proxy()->filterPkgClass(id);
    allResize();
	emit clearSearch();
}

void PackageWidget::search(const QString& text)
{
	if (text.isEmpty())
        //my comment
		//tableView->resetModel(classifyList.at(buttonGroup->checkedId()));
        ;
	else
		tableView->search(text);
}
