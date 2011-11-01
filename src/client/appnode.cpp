/*
 *
 *  Portions Copyright (C) 2009 wind (lvlisong@redflag-linux.com)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#include <string>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include "appnode.h"

#define DB_HOST "localhost"
#define DB_NAME "PKGDB"
#define DB_USER "swcenter"
#define DB_PASSWORD "abc123"
#define DB_TABLE "pkgtable"

int Node::setStatus(int stat)
{
    _oldstat = _status;
    _status = stat;
}

/*TODO*/
NodeList* NodeList::S_NODELIST = NULL;

NodeList* NodeList::instance()
{
	if (NULL == S_NODELIST)
		S_NODELIST = new NodeList;
	return S_NODELIST;
}

NodeList::NodeList()
{
    qDebug() << "NODE LIST HERE" << endl;
    /*
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(DB_HOST);
    db.setDatabaseName(DB_NAME);
    db.setUserName(DB_USER);
    db.setPassword(DB_PASSWORD);
    if (!db.open()) qDebug() << "DB failed" << endl;
    QSqlQuery query;
    query.exec("SELECT * FROM "DB_TABLE);   
    while(query.next()) {
        QString name = query.value(0).toString();
        QString descr = query.value(1).toString();
        int size = query.value(2).toString().toInt();
        int status = query.value(3).toString().toInt();
        int pkg_class = query.value(4).toString().toInt();
        bool favor = query.value(5).toString().toInt();
        Node *node = new Node(name, descr, size, status, pkg_class, favor);
        QString iconPath = QString(ICONPATH).arg(name);
        node->icon().load(iconPath);
        _nodes.push_back(node);
    }
    */
}
