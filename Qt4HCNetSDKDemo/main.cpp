#include "Qt4HCNetSDKDemo.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
	QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
	QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));
	QApplication a(argc, argv);
	Qt4HCNetSDKDemo w;
	w.show();
	return a.exec();
}
