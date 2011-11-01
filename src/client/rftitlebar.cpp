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

#include "rftitlebar.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <QDebug>
#include <QSpacerItem>
#include <QLineEdit>
#include <QPushButton>
#include <QPainter>
#include <QDebug>
#include <QApplication>
#include <QStyle>

class RFLineEdit : public QLineEdit {
	public:
		RFLineEdit(QWidget* parent = NULL): QLineEdit(parent){}
	protected:
		virtual void paintEvent(QPaintEvent* event);
};

void RFLineEdit::paintEvent(QPaintEvent* event)
{
	if (hasFocus())
		return QLineEdit::paintEvent(event);
	if (!text().isEmpty())
		return QLineEdit::paintEvent(event);

	QLineEdit::paintEvent(event);
	QPainter painter(this);
	QRect rt = rect();
	painter.setPen(Qt::gray);
	painter.drawText(rt, Qt::AlignCenter | Qt::TextHideMnemonic,
			"Please enter the name of the software");
}

//class RFFrame : public QWidget {
	//public:
		//RFFrame(QWidget* parent = NULL);
	//protected:
		//virtual void paintEvent(QPaintEvent* event);
//};

//RFFrame::RFFrame(QWidget* parent) :
	//QWidget(parent)
//{
	//QHBoxLayout* layout = new QHBoxLayout(this);
	////layout->setContentsMargins(1, 1, 1, 1);

	//QLineEdit* et = new RFLineEdit;
	//et->setMinimumWidth(300);
	//et->setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed));
	////et->setFrame(false);
	//layout->addWidget(et);

	//QPushButton* bt = new QPushButton("search");
	//et->setStyleSheet("border-radius:0px;border:0px solid black");
	//bt->setStyleSheet("border-radius:0px;border:0px solid black");
	//bt->setFocusPolicy(Qt::NoFocus);
	//layout->addWidget(bt);

	//layout->setSpacing(0);
	//setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Minimum);
//}

//void RFFrame::paintEvent(QPaintEvent* event)
//{
	//Q_UNUSED(event)

	//QWidget::paintEvent(event);
	//QPainter painter(this);
	//QRect rt = childrenRect().adjusted(-3, -3, 3, 3);
	////painter.setRenderHint (QPainter::SmoothPixmapTransform);
	//painter.setRenderHint(QPainter::Antialiasing);

	//painter.setPen(QPen(Qt::white));
	//painter.drawRoundedRect(rt, 2.0, 2.0);
	//painter.fillRect(rt, QBrush(QColor(255, 255, 255, 255)));
	//rt = rt.adjusted(1, 1, -2, -1);
	//painter.setRenderHint(QPainter::Antialiasing, false);
	//painter.setPen(QPen(QColor(100,100,100)));
	//painter.drawRect(rt);
//}

RFTitleBar::RFTitleBar(QWidget* parent) :
	QWidget(parent)
{
	//QWidget* fr = new RFFrame(this);
	_et = new RFLineEdit;
	//et->setMinimumWidth(270);
	_et->setMinimumSize(270, 20);
	_et->setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed));

	QPushButton* bt = new QPushButton(tr("Search"));
	//et->setStyleSheet("border-radius:0px;border:0px solid black");
	//bt->setStyleSheet("border-radius:0px;border:1px black");
	bt->setFocusPolicy(Qt::NoFocus);
	bt->setStyleSheet("QAbstractButton{border:1px solid #515151; "
			"border-bottom:2px solid #515151; border-radius: 0px;"
			" font-weight:450; height: 20px;}"
			" QAbstractButton:checked{ background-color: #515151; color: white;}"
			" QAbstractButton:pressed { background-color: #515151; color: white;}");

	QHBoxLayout* layout = new QHBoxLayout(this);

	QSpacerItem* spacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
	layout->addItem(spacer);
	layout->addWidget(_et);
	layout->addWidget(bt);
	layout->setSpacing(0);
	layout->setContentsMargins(0, 0, 0, 0);
	//bt->setContentsMargins(0, 0, 0, 0);
	//et->setContentsMargins(0, 0, 0, 0);
	setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Minimum);
	setMinimumHeight(50);
	connect(_et, SIGNAL(textChanged(const QString&)), this, SIGNAL(searchChanged(const QString&)));
}

void RFTitleBar::clearSearch()
{
	_et->clear();
}

void RFTitleBar::setSearch(const QString& text)
{
	_et->setText(text);
	emit searchChanged(text);
}
