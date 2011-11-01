#ifndef PIC
#define PIC
#include <QtGui>
#include "widget.h"

class PictureFrame:public QWidget {
  Q_OBJECT public:
	PictureFrame(QWidget * parent = NULL);
	~PictureFrame();

	public slots:
		void switchPic(const QString &);

	 signals:
	 void searchChanged(const QString & text);
  private:
	 Widget * sliderWidget;
	 QLabel *pictureLabel;
	 QString current;
};

class PicLabel : public QLabel {
	Q_OBJECT
	public:
		PicLabel(QWidget* parent):QLabel(parent){}
	signals:
		void mouseRelease();
		/*protected:*/
		/*void mouseReleaseEvent ( QMouseEvent * ev );*/
};

#endif
