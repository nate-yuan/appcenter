#ifndef MAINWINDOW
#define MAINWINDOW
#include <QWidget>
#include <QSize>
#include <QStackedLayout>
#include <QSystemTrayIcon>

class AppWidget;
class QAction;

class Dashboard : public QWidget{
    Q_OBJECT
public:
    Dashboard(QWidget * parent = NULL);
	~Dashboard() {};
    QSize size;
  public slots:
    void iconActivated(QSystemTrayIcon::ActivationReason);
  signals:
  protected:
    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent * event);

  private:
    void setGeoProper();
    QSystemTrayIcon *tray;
    QAction *quitAction;
    QAction *hideAction;
    QAction *showAction;
    AppWidget *awidget;
};
#endif
