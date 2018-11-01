#ifndef QT4HCNETSDKDEMO_H
#define QT4HCNETSDKDEMO_H

#include <QtGui/QWidget>
#include "ui_Qt4HCNetSDKDemo.h"
#include "HCNetSDK.h"

class Qt4HCNetSDKDemo : public QWidget
{
	Q_OBJECT

public:
	Qt4HCNetSDKDemo(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Qt4HCNetSDKDemo();

private:
	Ui::Qt4HCNetSDKDemoClass ui;
	//初始化完成标记
	BOOL m_bInit;
	//登陆返回的用户ID值
	LONG m_lUserID;
	//实时播放句柄参数
	LONG m_lRealPlayHandle;
};

#endif // QT4HCNETSDKDEMO_H
