#include <QApplication>
#include <QTranslator>
#include <QRect>
#include <QDesktopWidget>

#include "dashboard.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	QFont font = app.font();
	font.setPointSize(10);
	app.setFont(font);

	//QTranslator translator;
	//translator.load(QObject::tr("./rfsoftwarecenter.qm"));
	//app.installTranslator(&translator);

	app.setStyleSheet("QAbstractButton{border:1px solid #515151; "
			"border-bottom:2px solid #515151; border-radius: 0px;"
			" font-weight:450; height: 28px;}"
			" QAbstractButton:checked{ background-color: #515151; color: white;}"
			" QAbstractButton:pressed { background-color: #515151; color: white;}"
			" QLineEdit{border:2px solid #515151;border-radius: 0px;}");

    QApplication::setQuitOnLastWindowClosed(false);
    QDesktopWidget *d = QApplication::desktop();
    QRect r = d->availableGeometry();
	Dashboard b;
    b.setFixedSize(r.width(), r.height());
	b.show();
	app.exec();
}
