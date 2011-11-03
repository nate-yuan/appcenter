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
enum PackageStatus { ALLSTATUS, UNINSTALLED, DOWNLOADED, INSTALLED, OLD };
enum PackageClass { ALLCLASS, PROFESSIONAL, NETWORK, MEDIA, DRIVER, DEVELOP, OTHER }; 
enum Content { FavorColumn, NameColumn, DescrColumn, ButtonColumn };

class Node : public QObject
{
  Q_OBJECT
public:
	Node(const QString & name, const QString & descr, \
         PackageStatus stat, PackageClass pkg_class, bool favor) 
        : _name(name), _descr(descr), _status(stat), \
          _pkg_class(pkg_class), _favor(favor)
	{
	}

	void setIcon(QString pathname) 
    { 
        _icon.load(pathname); 
    }

    QPixmap & icon() 
    { 
        return _icon; 
    }

    void setStatus(PackageStatus stat);

    PackageStatus status() 
    { 
        return _status; 
    }

    PackageStatus  oldStatus() 
    { 
        return _oldstat; 
    }

    bool favor() 
    { 
        return _favor; 
    }

    PackageClass pkgClass() 
    { 
        return _pkg_class; 
    }

    QString name() 
    { 
        return _name; 
    }

    QString descr() 
    { 
        return _descr; 
    }

private:
	QPixmap _icon;
    QString _name;
    QString _descr;
    PackageStatus _status;
    PackageClass _pkg_class;
    PackageStatus _oldstat;
	int _progress;
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
    virtual ~ NodeList() {} ;
    int count() 
    { return _nodes.count(); }
    int refresh() 
    { return 0; }
    Node * at(int idx) { return _nodes[idx]; }
private:
    T_NODES _nodes;
    int _count;
	static NodeList *S_NODELIST;
};

#endif
