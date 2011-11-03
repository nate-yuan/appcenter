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

#include "titlebar.h"

class LineEdit : public QLineEdit {
	public:
		LineEdit(QWidget* parent = NULL): QLineEdit(parent){}
	protected:
		virtual void paintEvent(QPaintEvent* event);
};

void LineEdit::paintEvent(QPaintEvent* event)
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

TitleBar::TitleBar(QWidget* parent) :
	QWidget(parent)
{
	_et = new LineEdit;
	_et->setMinimumSize(270, 20);
	_et->setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed));

	QPushButton* bt = new QPushButton(tr("Search"));
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
	setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Minimum);
	setMinimumHeight(50);
	connect(_et, SIGNAL(textChanged(const QString&)), this, SIGNAL(searchChanged(const QString&)));
}

void TitleBar::clearSearch()
{
	_et->clear();
}

void TitleBar::setSearch(const QString& text)
{
	_et->setText(text);
	emit searchChanged(text);
}
