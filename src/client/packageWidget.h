#ifndef RECOMMEND
#define RECOMMEND
#include <QScrollArea>
#include "pictureframe.h"
#include "tableview.h"

class PackageWidget : public QScrollArea {
  Q_OBJECT
  public:
	PackageWidget(QWidget * parent = NULL);
	~PackageWidget(){};
	void createGroupButton();
    void setPictureFrameVisible(bool vis);
    void setButtonsVisible(bool vis);
  public slots:
    void setCurrentButton(int);
    void showCurrent(int);
  protected:
  signals:
    void clearSearch();
    void search(const QString & text);
    void searchChanged (const QString & text);
  private:
    void allResize();
    PictureFrame * pictureFrame;
    QWidget *buttonWidget;
    TableView *tableView;

    QButtonGroup *buttonGroup;
    QPushButton *all;
    QPushButton *professional;
    QPushButton *network;
    QPushButton *media;
    QPushButton *driver;
    QPushButton *develop;
    QPushButton *other;

    QTimer      *timer;
    QWidget     *_frame;
};
#endif
