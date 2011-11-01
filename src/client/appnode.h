#ifndef APPNODE
#define APPNODE
#include <iostream>
#include <QString>
#include <QPixmap>
#include <QDebug>
#include <QVariant>
#define NAMELENTH 128
#define DESCRIPTION 256
#define ICONWIDTH 32
#define ICONHEIGH 32
#define ICONCOLUMNWIDTH 42
#define BUTTONCOLUMNWIDTH 75
#define SIZECOLUMNWIDTH 120
#define VERTICALHEIGHT 40
#define ICONPATH "./AppIcon/%1.png"
using namespace std;
enum Content { IconColumn, NameColumn, SizeColumn, ButtonColumn };
//enum PackageStatus { UNINSTALLED, INSTALLED, OLD, INSTALLING, PAUSED};
class Node : public QObject{
  Q_OBJECT
  public:
	Node(const QString & name, const QString & descr, \
         int size, int stat, int pkg_class, bool favor) 
        : _name(name), _descr(descr), _size(size), \
          _status(stat), _pkg_class(pkg_class), _favor(favor)
	{
	}

	void setIcon(QString pathname) { _icon.load(pathname); }

    QPixmap & icon() { return _icon; }
    int status() { return _status; }
    int oldstat() { return _oldstat; }
    int progress() { return _progress; }
    int setProg(int prog) { 
        if (prog > 100 || prog < 0) 
            return -1; 
        _progress = prog; }
    int setStatus(int stat); 
    int stat() { return _status; }
    bool favor() { return _favor; }
    int pkgClass() { return _pkg_class; }
    QString name() { return _name; }
    QString descr() { return _descr; }
    int size() { return _size; }
  private:
	QPixmap _icon;
    QString _name;
    QString _descr;
    int _size;
    int _status;
    int _oldstat;
	int _progress;
    int _pkg_class;
    bool _favor;
};

/* A singleton class */
class NodeList:public QObject {
  Q_OBJECT 
  public:
     typedef QVector<Node *> T_NODES;
  protected:
	 NodeList();
  public:
	static NodeList *instance();
    virtual ~ NodeList() {
	} 
    void freeNode(Node *node);
    int count() { return _nodes.count(); }
    int refresh() { return 0; }
    Node * at(int idx) { 
        return _nodes[idx]; }
  private:
    T_NODES _nodes;
    int _count;
	static NodeList *S_NODELIST;
};

#endif
