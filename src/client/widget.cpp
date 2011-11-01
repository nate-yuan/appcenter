#include <QTimer>
#include <QImage>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>


#include "widget.h"


static QImage img_first("images/chromium-browser_small.png");
static QImage img_second("images/thunderbird_small.png");
static QImage img_third("images/firefox_small.png");
static QImage img_forth("images/chromium-browser_small.png");

Widget::Widget(QWidget *parent) : QWidget(parent)
{

	isEntered=false;

	startx=0;
	setMouseTracking(true);
	QString str;
	str="images/chromium-browser_small";
	imgList.append(str);
	str="images/thunderbird_small";
	imgList.append(str);
	str="images/firefox_small";
	imgList.append(str);
	imgPos=0;
	QSize size=img_first.size();
	size.setHeight(size.height()*3);
	resize(size);

	mask=mask.scaled(size);

	startpos = 0;
	resultImage = QImage(size, QImage::Format_ARGB32_Premultiplied);
	//resultImage = QImage(size, QImage::Format_ARGB32);
	//	bgImage=QImage(size,QImage::Format_ARGB32_Premultiplied);
	bgImage=QImage(size,QImage::Format_ARGB32);
	timer = new QTimer(this);
	connect(timer,SIGNAL(timeout()),this,SLOT(timedone()));
	timer->setInterval(50);
	timer->start();
	composeImage();

	//     QGraphicsScene *Scene = new QGraphicsScene;
	//     Scene->setSceneRect(-800,-800,800,800);
	//     Scene->setItemIndexMethod(QGraphicsScene::NoIndex);
	//
	//     butterfly = new Butterfly();
	//     butterfly->setPos(-50,50);
	//     Scene->addItem(butterfly);
	//
	//     QGraphicsView *View = new QGraphicsView(this);
	//     View->setScene(Scene);
	//     View->raise();

	//View.setRenderHint(QPainter::Antialiasing);
	//View.setBackgroundBrush(QPixmap("img"));
}

Widget::~Widget()
{

}

void Widget::composeImage()
{
	//get bgImage
	QPainter p;
	p.begin(&bgImage);
	p.fillRect(bgImage.rect(), Qt::black);
	p.drawImage(startx,0,img_first,0,startpos,img_first.width(),img_first.height()-startpos);
	p.drawImage(startx,img_second.height()*1-startpos,img_second,0,0,img_second.width(),img_second.height());
	p.drawImage(startx,img_third.height()*2-startpos,img_third,0,0,img_third.width(),img_third.height());
	p.drawImage(startx,img_forth.height()*3-startpos,img_forth,0,0,img_forth.width(),startpos);

	firstrect.setX(0);
	firstrect.setY(0);
	firstrect.setWidth(img_first.width());
	firstrect.setHeight(img_first.height()-startpos);

	secondrect.setX(0);
	secondrect.setY(firstrect.height());
	secondrect.setWidth(img_second.width());
	secondrect.setHeight(img_second.height());

	thirdrect.setX(0);
	thirdrect.setY(secondrect.y()+secondrect.height());
	thirdrect.setWidth(img_third.width());
	thirdrect.setHeight(img_third.height());

	forthrect.setX(0);
	forthrect.setY(img_forth.height()*3-startpos);
	forthrect.setWidth(img_forth.width());
	forthrect.setHeight(startpos);
	if(!isEntered)
		currentRect=secondrect;
	p.fillRect(currentRect,QColor(0,0,0,120));

	p.end();

	p.begin(&resultImage);
	p.drawImage(0, 0, bgImage);
	p.end();
}
void Widget::timedone()
{
	startpos += 3;
	if( startpos>img_first.height())
	{
		startpos = 0;
		imgPos++;
		img_first.load(imgList.at(imgPos%3));
		img_second.load(imgList.at((imgPos+1)%3));
		img_third.load(imgList.at((imgPos+2)%3));
		img_forth.load(imgList.at((imgPos+3)%3));

		emitCurrentChange(imgList.at((imgPos+1)%3));//second image

	}
	composeImage();
	//		currentRect=secondrect;
	update();
}



void Widget::paintEvent( QPaintEvent *e )
{
	Q_UNUSED(e)
	//if(mousePressed)
	//qDebug()<<"update paintEvent";
	QPainter p(this);



	p.save();
	p.drawImage(0,0,resultImage);
	p.restore();

	//p.begin(&resultImage);
	/*p.setCompositionMode(QPainter::CompositionMode_DestinationIn);
	  p.fillRect(rect(), QColor(0, 0, 0,254));
	  p.fillRect(currentRect, QColor(0, 0, 0,100));
	  */
	//p.end();


}

void Widget::mouseReleaseEvent(QMouseEvent *e)
{
	Q_UNUSED(e)
	mousePressed = false;

	int x=e->x();
	int y=e->y();
	if(firstrect.contains(x,y)) {
		QString current = imgList.at((imgPos) % 3);
		current.remove(0, 7);
		current.chop(6);
		emit mouseRelease(current);
		return;
	}

	if(secondrect.contains(x,y)) {
		QString current = imgList.at((imgPos+1) % 3);
		current.remove(0, 7);
		current.chop(6);
		emit mouseRelease(current);
		return;
	}

	if(thirdrect.contains(x,y)) {
		QString current = imgList.at((imgPos+2) % 3);
		current.remove(0, 7);
		current.chop(6);
		emit mouseRelease(current);
		return;
	}

	if(forthrect.contains(x,y)) {
		QString current = imgList.at((imgPos+3) % 3);
		current.remove(0, 7);
		current.chop(6);
		emit mouseRelease(current);
		return;
	}

}

void Widget::mousePressEvent(QMouseEvent *e)
{
	Q_UNUSED(e)
		mousePressed = true;
	//int x=e->x();
	//int y=e->y();
	/*		if(firstrect.contains(x,y))
			qDebug()<<"first rect";
			if(secondrect.contains(x,y))
			qDebug()<<"second rect";
	 */
	update();
}

void Widget::mouseMoveEvent(QMouseEvent *e)
{
	Q_UNUSED(e)
		int x=e->x();
	int y=e->y();
	if(firstrect.contains(x,y)) {
		emitCurrentChange(imgList.at((imgPos)%3));
		currentRect=firstrect;
		composeImage();
		update();
	}

	if(secondrect.contains(x,y)) {
		emitCurrentChange(imgList.at((imgPos+1)%3));
		currentRect=secondrect;
		composeImage();
		update();
	}

	if(thirdrect.contains(x,y)) {
		emitCurrentChange(imgList.at((imgPos+2)%3));
		currentRect=thirdrect;
		composeImage();
		update();
	}

	if(forthrect.contains(x,y)) {
		emitCurrentChange(imgList.at((imgPos+3)%3));
		currentRect=forthrect;
		composeImage();
		update();
	}
}

void Widget::enterEvent(QEvent *e)
{
	Q_UNUSED(e)
		isEntered = true;
	timer->stop();
}

void Widget::leaveEvent(QEvent *e)
{
	Q_UNUSED(e)
		isEntered=false;
	timer->start();
}

