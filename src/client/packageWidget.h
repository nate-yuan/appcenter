#ifndef RECOMMEND
#define RECOMMEND
#include <QScrollArea>
#include "pictureframe.h"
#include "tableview.h"

class PackageWidget : public QScrollArea {
  Q_OBJECT
  public:
    TableView *tableView;
	PackageWidget(QWidget * parent = NULL);
	~PackageWidget();
	void createGroupButton();
    void setPictureFrameVisible(bool vis);
    void setButtonsVisible(bool vis);
    void search(const QString &text);
  public slots:
    void setCurrentButton(int);
  protected:
  signals:
    void clearSearch();
    void searchChanged (const QString & text);
  private:
    void allResize();
    PictureFrame * pictureFrame;
    QWidget *buttonWidget;
    QButtonGroup *buttonGroup;
    QPushButton *networkApp;
    QPushButton *mediaApp;
    QPushButton *gameApp;
    QPushButton *graphicsApp;
    QPushButton *wordsApp;
    QPushButton *devApp;
    QPushButton *hardwareApp;
    QPushButton *professionalApp;
    QPushButton *otherApp;

    QPushButton *currentButton;
    QTimer      *timer;
    QWidget     *_frame;
    QStringList classifyList;
};
#endif
