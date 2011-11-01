#include "pictureframe.h"
//void PicLabel::mouseReleaseEvent(QMouseEvent* ev)
//{
	//Q_UNUSED(ev)
	//emit mouseRelease();
//}

PictureFrame::PictureFrame(QWidget *parent) : QWidget(parent)
{
	QHBoxLayout *layout = new QHBoxLayout(this);
	pictureLabel=new QLabel(this);
	//		QPushButton *pre=new QPushButton("pre",this);
	//		QPushButton *next=new QPushButton("next",this);
	//		pre->setWindowOpacity(0.5);

	sliderWidget=new Widget(this);

	QVBoxLayout *vl=new QVBoxLayout;
	//		vl->addWidget(pre);
	vl->addWidget(sliderWidget);
	//		vl->addWidget(next);
	pictureLabel->setPixmap(QPixmap("images/thunderbird.png"));
	layout->addWidget(pictureLabel);
	//layout->addWidget(sliderWidget);
	layout->addLayout(vl);

	connect(sliderWidget, SIGNAL(emitCurrentChange(const QString&)),
			this,SLOT(switchPic(const QString&)));
	connect(sliderWidget, SIGNAL(mouseRelease(const QString&)),
			this, SIGNAL(searchChanged(const QString&)));

	resize(708,250);
	setMinimumHeight(250);
	setMaximumHeight(250);
}

PictureFrame::~PictureFrame()
{
	delete sliderWidget;
	delete pictureLabel;
}

void PictureFrame::switchPic(const QString& pic)
{

	QPixmap pix("images/ppstream.png");
	QPixmap pix2("images/ppstream_small.png");
	QString bigpic=pic;
	bigpic.chop(6);
	pictureLabel->setPixmap(QPixmap(bigpic));
}

//void PictureFrame::onMouseRelease()
//{
//}
