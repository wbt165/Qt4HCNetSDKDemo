#include "Qt4HCNetSDKDemo.h"
#include <QtGui/QApplication>
#include <QTextCodec>

#ifdef ARM
#include <QWSServer>
#endif //ARM

int main(int argc, char *argv[])
{
	QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
	QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));
	QApplication a(argc, argv);

#ifdef ARM
    QWSServer::setCursorVisible(false);
#endif //ARM

	Qt4HCNetSDKDemo w;
	w.show();
	return a.exec();
}
