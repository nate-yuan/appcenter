#ifndef WIDGET
#define WIDGET
#include <QtGui>
class Widget:public QWidget
{
		Q_OBJECT
		public:
		Widget(QWidget *parent=NULL);
		~Widget();
		void composeImage();
		public slots:
				void timedone();
signals:
		void emitCurrentChange(const QString&);
		void mouseRelease(const QString&);

		protected:
		void paintEvent(QPaintEvent *);
		void mouseReleaseEvent(QMouseEvent *);
		void mousePressEvent(QMouseEvent *);
		void enterEvent(QEvent *e);
		void mouseMoveEvent(QMouseEvent *e);
		void leaveEvent(QEvent *event);
		private:
		QStringList imgList;
		int imgPos,startpos;
		QImage resultImage;
		QImage bgImage;
		QPixmap mask;
		QRect firstrect;
		QRect secondrect;
		QRect thirdrect;
		QRect forthrect;
		bool mousePressed;
		int startx;
		QTimer *timer;
		QRect currentRect;
		bool isEntered;
};
#endif
