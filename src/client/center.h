#ifndef MAINWINDOW
#define MAINWINDOW
#include <QWidget>
#include <QStackedLayout>
#include "packageWidget.h"

class AppCenter : public QWidget {
    Q_OBJECT
public:
    AppCenter(QWidget * parent = NULL);
	~AppCenter();
public slots:
	void changeCurrentView(int index);
	void onTextChanaged(const QString& text);
signals:
	void clearSearch();
protected:
	void resizeEvent(QResizeEvent * event);
private:
	QStackedLayout * stackedLayout;
    PackageWidget * pWidget;
};
#endif
