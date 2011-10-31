#ifndef ICONAREA_H
#define ICONAREA_H
#include <QListWidget>

class QPixmap;
class QPoint;

class IconArea : public QListWidget
{
    Q_OBJECT
public:
    IconArea(QWidget *parent = NULL);
    virtual ~IconArea() {};
    void addIcon(QPixmap pixmap, QPoint location);

public slots:
    void slideLeft();
    void slideRight();
};

#endif
