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
		QMessageBox::information(this,tr("提示"), \
			tr("SDK_LAST_ERROR=%1").arg(NET_DVR_GetLastError()));
	}

	NET_DVR_SetConnectTime(10000, 1);

	ui.frameRealPlay->winId();

	//---------------------------------------
	// 注册设备
	LONG lUserID;

	//登录参数，包括设备地址、登录用户、密码等
	NET_DVR_USER_LOGIN_INFO struLoginInfo = {0};
	struLoginInfo.bUseAsynLogin = 0; //同步登录方式
	strcpy(struLoginInfo.sDeviceAddress, "192.168.1.64"); //设备IP地址
	struLoginInfo.wPort = 8000; //设备服务端口
	strcpy(struLoginInfo.sUserName, "admin"); //设备登录用户名
	strcpy(struLoginInfo.sPassword, "98765432i"); //设备登录密码

	//设备信息, 输出参数
	NET_DVR_DEVICEINFO_V40 struDeviceInfoV40 = {0};

	lUserID = NET_DVR_Login_V40(&struLoginInfo, &struDeviceInfoV40);
	if (lUserID < 0)
	{
		QMessageBox::information(this,tr("提示"), \
			tr("登录失败，失败原因=%1").arg(NET_DVR_GetLastError()));
		exit(0);
	}


}

Qt4HCNetSDKDemo::~Qt4HCNetSDKDemo()
{

}
