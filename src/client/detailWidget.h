#ifndef DETAILWIDGET_H
#define DETAILWIDGET_H

#include <QtGui>

class QWidget;
class QHBoxLayout;
class QVBoxLayout;
class QSpacerItem;
class QProgressBar;
class QGraphicsView;
class QLabel;

class DetailWidget : public QWidget
{
    Q_OBJECT
public:
    DetailWidget(QWidget *parent = NULL);
    ~DetailWidget(){};

private:
    QGraphicsView *iconBox;
    QLabel *nameLab;
    QLabel *sizeLab;
    QLabel *briefLab;
    QPushButton *instButton;
    QProgressBar *progressBar;
    QLabel *progressLab;
    QTextBrowser *textBrowser;
};

#endif
