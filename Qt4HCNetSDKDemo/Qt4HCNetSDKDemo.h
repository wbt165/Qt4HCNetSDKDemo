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
	//��ʼ����ɱ��
	BOOL m_bInit;
	//��½���ص��û�IDֵ
	LONG m_lUserID;
	//ʵʱ���ž������
	LONG m_lRealPlayHandle;
};

#endif // QT4HCNETSDKDEMO_H
