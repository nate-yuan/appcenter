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
#ifndef _TITLEBAR_H_
#define _TITLEBAR_H_

#include <QWidget>
#include <QLineEdit>

class TitleBar : public QWidget {
	Q_OBJECT
	public:
		TitleBar(QWidget* parent = NULL);
	signals:
		void searchChanged (const QString & text);
	public slots:
		void clearSearch();
		void setSearch(const QString& text);
	private:
		QLineEdit* _et;

};


#endif // _TITLEBAR_H_
