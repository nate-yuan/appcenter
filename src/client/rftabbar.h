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
#ifndef _RFTABBAR_H_
#define _RFTABBAR_H_

#include <QTabBar>
#include <QTimer>
#include <QWeakPointer>

class QPropertyAnimation;

class RFTabBar : public QTabBar {
	Q_OBJECT
	Q_PROPERTY(qreal animValue READ animValue WRITE setAnimValue)

	public:
		RFTabBar(QWidget* parent = NULL);
		qreal animValue() const;

	protected:
		virtual QSize tabSizeHint(int index) const;
		virtual void paintEvent(QPaintEvent* event);
		virtual void leaveEvent(QEvent *event);
		virtual void mouseMoveEvent(QMouseEvent *event);
		virtual void resizeEvent(QResizeEvent* event);
		virtual void dragEnterEvent(QDragEnterEvent *event);

	protected slots:
		void switchToHoveredTab();
		void animationFinished();
		void startAnimation();
		void setAnimValue(qreal value);

	private:
		QPainterPath tabPath(const QRectF &r);
		void storeLastIndex();
		void setCurrentIndexWithoutAnimation(int index);
		int lastIndex() const;

		QTimer _tabSwitchTimer;
		QRectF _currentAnimRect;

		int _lastIndex[2];
		QWeakPointer<QPropertyAnimation> _animation;

		QImage* _tabbg;
		qreal _animProgress;
		int _hoveredTabIndex;
		bool _switchOnHover;
		bool _animateSwitch;
};

#endif // _RFTABBAR_H_
