#ifndef QT4HCNETSDKDEMO_H
#define QT4HCNETSDKDEMO_H

#include <QtGui/QWidget>
#include "ui_Qt4HCNetSDKDemo.h"

class Qt4HCNetSDKDemo : public QWidget
{
	Q_OBJECT

public:
	Qt4HCNetSDKDemo(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Qt4HCNetSDKDemo();

private:
	Ui::Qt4HCNetSDKDemoClass ui;
};

#endif // QT4HCNETSDKDEMO_H
