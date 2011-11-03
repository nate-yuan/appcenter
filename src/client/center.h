#ifndef MAINWINDOW
#define MAINWINDOW
#include <QWidget>
#include <QStackedLayout>

class PackageWidget;
class DetailWidget;

class AppCenter : public QWidget {
    Q_OBJECT
public:
    AppCenter(QWidget * parent = NULL);
	~AppCenter();
signals:
	void clearSearch();
protected:
	void resizeEvent(QResizeEvent * event);
private:
	QStackedLayout * stackedLayout;
    PackageWidget * pWidget;
    DetailWidget * dWidget;
};
#endif
