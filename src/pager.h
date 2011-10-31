#ifndef PAGER_H
#define PAGER_H
#include <QWidget>
#include <QButtonGroup>
#include <QPushButton>

class Pager : public QWidget
{
    Q_OBJECT
public:
    Pager(QWidget *parent = NULL);
    ~Pager(){};
};

#endif
