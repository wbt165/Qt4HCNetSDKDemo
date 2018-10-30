#include "Qt4HCNetSDKDemo.h"
#include "HCNetSDK.h"
#include <QMessageBox>

Qt4HCNetSDKDemo::Qt4HCNetSDKDemo(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	ui.setupUi(this);


	//AT last need init SDK 
	if (!NET_DVR_Init())
	{
		QMessageBox::information(this,tr("��ʾ"), \
			tr("SDK_LAST_ERROR=%1").arg(NET_DVR_GetLastError()));
	}

	NET_DVR_SetConnectTime(10000, 1);

	ui.frameRealPlay->winId();

	//---------------------------------------
	// ע���豸
	LONG lUserID;

	//��¼�����������豸��ַ����¼�û��������
	NET_DVR_USER_LOGIN_INFO struLoginInfo = {0};
	struLoginInfo.bUseAsynLogin = 0; //ͬ����¼��ʽ
	strcpy(struLoginInfo.sDeviceAddress, "192.168.1.64"); //�豸IP��ַ
	struLoginInfo.wPort = 8000; //�豸����˿�
	strcpy(struLoginInfo.sUserName, "admin"); //�豸��¼�û���
	strcpy(struLoginInfo.sPassword, "98765432i"); //�豸��¼����

	//�豸��Ϣ, �������
	NET_DVR_DEVICEINFO_V40 struDeviceInfoV40 = {0};

	lUserID = NET_DVR_Login_V40(&struLoginInfo, &struDeviceInfoV40);
	if (lUserID < 0)
	{
		QMessageBox::information(this,tr("��ʾ"), \
			tr("��¼ʧ�ܣ�ʧ��ԭ��=%1").arg(NET_DVR_GetLastError()));
		exit(0);
	}


}

Qt4HCNetSDKDemo::~Qt4HCNetSDKDemo()
{

}
