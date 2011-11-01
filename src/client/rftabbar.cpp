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
#include "rftabbar.h"
#include <QIcon>
#include <QPainter>
#include <QMouseEvent>
#include <QPropertyAnimation>
#include <QDebug>
RFTabBar::RFTabBar(QWidget* parent) :
	QTabBar(parent)
	, _animProgress(1.0)
	, _hoveredTabIndex(-1)
	, _switchOnHover(true)
	, _animateSwitch(true)
{
	_lastIndex[0] = -1;

	setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum));
	setIconSize(QSize(48, 48));
	setShape(QTabBar::RoundedWest);

	connect(this, SIGNAL(currentChanged(int)), this, SLOT(startAnimation()));
	_tabSwitchTimer.setSingleShot(true);
	connect(&_tabSwitchTimer, SIGNAL(timeout()), this, SLOT(switchToHoveredTab()));
	setAcceptDrops(true);
	setMouseTracking(true);
	setUsesScrollButtons(false);

	addTab(QIcon("images/recommended.png"), tr("Recommended"));
	addTab(QIcon("images/warehouse.png"), tr("Warehouse"));
	addTab(QIcon("images/updates.png"), tr("Updates"));
	addTab(QIcon("images/uninstall"), tr("Uninstall"));
	//addTab(QIcon("images/community"), tr("Community"));

	_tabbg = new QImage("images/tabbg.png");

}

QSize RFTabBar::tabSizeHint(int index) const
{
	const QFontMetrics metrics(font());
	const QSize textSize = metrics.size(Qt::TextHideMnemonic, tabText(index));
	int width = qMax(iconSize().width(), textSize.width());
	int height = iconSize().height() + textSize.height();

	width = qMax(140, width);
	height = qMax(80, height);

	return QSize(width, height);
}
//#define RIGHT_ROUNDED
#ifndef RIGHT_ROUNDED
QPainterPath RFTabBar::tabPath(const QRectF &_r)
{
	const qreal radius = 6;
	QPainterPath path;
	QRectF r = _r;

	// Top right corner
	path.moveTo(r.topRight());
	// Top left corner
	path.lineTo(r.topLeft() + QPointF(radius, 0));
	path.quadTo(r.topLeft(), r.topLeft() + QPointF(0, radius));
	// Bottom left corner
	path.lineTo(r.bottomLeft() + QPointF(0, -radius));
	path.quadTo(r.bottomLeft(), r.bottomLeft() + QPointF(radius, 0));
	// Bottom right corner
	path.lineTo(r.bottomRight());
	return path;
}
#else //RIGHT_ROUNDED

QPainterPath RFTabBar::tabPath(const QRectF &_r)
{
	const qreal radius = 6;
	QPainterPath path;
	QRectF r = _r;

	r.adjust(3, 0, 1, 0);
	path.moveTo(r.topRight());
	// Top right corner
	path.lineTo(r.topRight());
	path.quadTo(r.topRight() + QPointF(0, radius), r.topRight() + QPointF(-radius, radius));
	// Top left corner
	path.lineTo(r.topLeft() + QPointF(radius, radius));
	path.quadTo(r.topLeft() + QPointF(0, radius), r.topLeft() + QPointF(0, radius * 2));
	// Bottom left corner
	path.lineTo(r.bottomLeft() + QPointF(0, -radius * 2));
	path.quadTo(r.bottomLeft() + QPointF(0, -radius), r.bottomLeft() + QPointF(radius, -radius));
	// Bottom right corner
	path.lineTo(r.bottomRight() + QPointF(-radius, -radius));
	path.quadTo(r.bottomRight() + QPointF(0, -radius), r.bottomRight());

	return path;
}
#endif //RIGHT_ROUNDED

void RFTabBar::paintEvent(QPaintEvent *event)
{
	Q_UNUSED(event)
		QPainter painter(this);

	int currentTab = currentIndex();

	QRectF movingRect;
	if (_currentAnimRect.isNull()) {
		movingRect = tabRect(currentIndex());
	} else {
		movingRect = _currentAnimRect;
	}
	QPainterPath path = tabPath(movingRect);

	painter.save();
	painter.setPen(QPen(Qt::gray));
	painter.setRenderHint(QPainter::Antialiasing);
	painter.fillPath(path, QBrush(QColor(255, 255, 255, 255)));
	painter.drawImage(movingRect, *_tabbg, QRectF(0.0, 0.0, 0.0, 0.0));
	painter.restore();

	QFontMetrics metrics(painter.font());
	int textHeight = metrics.height();

	for (int i = 0; i < count(); i++) {
		QRect rect = tabRect(i).adjusted(10, 5, -10, -5);

		// draw tab icon
		QRectF iconRect = rect;
		iconRect.setBottom(iconRect.bottom() - textHeight);
		tabIcon(i).paint(&painter, iconRect.toRect());

		// draw tab text
		if (i != currentTab) {
			painter.setPen(Qt::white);
		} else {
			painter.setPen(Qt::black);
		}

		QRect textRect = rect;
		textRect.setTop(textRect.bottom() - textHeight);
		painter.drawText(textRect, Qt::AlignCenter | Qt::TextHideMnemonic, tabText(i));
	}
}

void RFTabBar::leaveEvent(QEvent *event)
{
	Q_UNUSED(event)
		_hoveredTabIndex = -1;
}

void RFTabBar::mouseMoveEvent(QMouseEvent *event)
{
	_hoveredTabIndex = tabAt(event->pos());
	if (_switchOnHover && _hoveredTabIndex > -1 && _hoveredTabIndex != currentIndex()) {
		_tabSwitchTimer.stop();
		_tabSwitchTimer.start(50);
	}
}


void RFTabBar::resizeEvent(QResizeEvent* event)
{
	QTabBar::resizeEvent(event);
	_currentAnimRect = tabRect(currentIndex());

	//background->resizeFrame(event->size());

	update();
}

void RFTabBar::dragEnterEvent(QDragEnterEvent *event)
{
	_hoveredTabIndex = tabAt(event->pos());
	_tabSwitchTimer.stop();
	_tabSwitchTimer.start(50);
	event->ignore();
}


void RFTabBar::storeLastIndex()
{
	// if first run
	if (_lastIndex[0] == -1) {
		_lastIndex[1] = currentIndex();
	}
	_lastIndex[0] = _lastIndex[1];
	_lastIndex[1] = currentIndex();
}

int RFTabBar::lastIndex() const
{
    return _lastIndex[0];
}

void RFTabBar::setCurrentIndexWithoutAnimation(int index)
{
    disconnect(this, SIGNAL(currentChanged(int)), this, SLOT(startAnimation()));
    setCurrentIndex(index);
    storeLastIndex();
    connect(this, SIGNAL(currentChanged(int)), this, SLOT(startAnimation()));
    animationFinished();
}


void RFTabBar::switchToHoveredTab()
{
	if (_hoveredTabIndex < 0 || _hoveredTabIndex == currentIndex())
		return;

	if (_animateSwitch)
		setCurrentIndex(_hoveredTabIndex);
	else
		setCurrentIndexWithoutAnimation(_hoveredTabIndex);
}

void RFTabBar::animationFinished()
{
	_currentAnimRect = QRect();
	update();
}

void RFTabBar::startAnimation()
{
	storeLastIndex();

	QPropertyAnimation *animation = _animation.data();
	if (animation) {
		animation->pause();
	} else {
		animation = new QPropertyAnimation(this, "animValue");
		animation->setProperty("easingCurve", QEasingCurve::InOutQuad);
		animation->setProperty("duration", 150);
		animation->setProperty("startValue", 0.0);
		animation->setProperty("endValue", 1.0);
	}

	animation->start(QAbstractAnimation::DeleteWhenStopped);
}

qreal RFTabBar::animValue() const
{
    return _animProgress;
}


void RFTabBar::setAnimValue(qreal value)
{
	if ((_animProgress = value) == 1.0) {
		animationFinished();
		return;
	}
	// animation rect
	QRect rect = tabRect(currentIndex());
	QRect lastRect = tabRect(lastIndex());
	int x = rect.x();
	int y = (int)(lastRect.y() - value * (lastRect.y() - rect.y()));
	QSizeF sz = lastRect.size() - value * (lastRect.size() - rect.size());
	_currentAnimRect = QRect(x, y, (int)(sz.width()), (int)(sz.height()));
	update();
}

