#include "Qt4HCNetSDKDemo.h"
#include <QMessageBox>
#include <stdio.h>

Qt4HCNetSDKDemo::Qt4HCNetSDKDemo(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	ui.setupUi(this);

	// 初始化标记量
	m_bInit = FALSE;
	m_lUserID = -1;
	m_lRealPlayHandle = -1;
    show();

    NET_DVR_Cleanup();
 //   connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));

	//AT last need init SDK 
	m_bInit = NET_DVR_Init();
	if (!m_bInit)
	{
		QMessageBox::information(this,tr("提示"), \
			tr("SDK_LAST_ERROR=%1").arg(NET_DVR_GetLastError()));
	}

	NET_DVR_SetConnectTime(10000, 1);

	//---------------------------------------
	// 注册设备
	//登录参数，包括设备地址、登录用户、密码等
	NET_DVR_USER_LOGIN_INFO struLoginInfo = {0};
	struLoginInfo.bUseAsynLogin = 0; //同步登录方式
    strcpy(struLoginInfo.sDeviceAddress, "192.168.100.213"); //设备IP地址
	struLoginInfo.wPort = 8000; //设备服务端口
	strcpy(struLoginInfo.sUserName, "admin"); //设备登录用户名
    strcpy(struLoginInfo.sPassword, "12345"); //设备登录密码

	//设备信息, 输出参数
	NET_DVR_DEVICEINFO_V40 struDeviceInfoV40 = {0};

	m_lUserID = NET_DVR_Login_V40(&struLoginInfo, &struDeviceInfoV40);
	if (m_lUserID < 0)
	{
		QMessageBox::information(this,tr("提示"), \
			tr("登录失败，失败原因=%1").arg(NET_DVR_GetLastError()));
		exit(0);
	}

    on_pushButton_clicked();

}

Qt4HCNetSDKDemo::~Qt4HCNetSDKDemo()
{
	//关闭预览
	if (m_lRealPlayHandle >= 0)
	{
		NET_DVR_StopRealPlay(m_lRealPlayHandle);
		m_lRealPlayHandle = -1;
	}
	//注销用户
	if (m_lUserID >= 0)
	{
		NET_DVR_Logout(m_lUserID);
		m_lUserID = -1;
	}
	//释放SDK资源
	if (m_bInit)
	{
		NET_DVR_Cleanup();
		m_bInit = FALSE;
	}
}

void Qt4HCNetSDKDemo::on_pushButton_clicked()
{
    HWND hWnd = (HWND)ui.frame0->winId();     //获取窗口句柄
    printf("frame0.hWnd=0x%x\n", hWnd);
    NET_DVR_PREVIEWINFO struPlayInfo = {0};
    struPlayInfo.hPlayWnd = hWnd;         //需要SDK解码时句柄设为有效值，仅取流不解码时可设为空
    struPlayInfo.lChannel     = 1;       //预览通道号
    struPlayInfo.dwStreamType = 0;       //0-主码流，1-子码流，2-码流3，3-码流4，以此类推
    struPlayInfo.dwLinkMode   = 0;       //0- TCP方式，1- UDP方式，2- 多播方式，3- RTP方式，4-RTP/RTSP，5-RSTP/HTTP
    struPlayInfo.bBlocked     = 0;       //0- 非阻塞取流，1- 阻塞取流

    m_lRealPlayHandle = NET_DVR_RealPlay_V40(m_lUserID, &struPlayInfo, NULL, NULL);
    if (m_lRealPlayHandle < 0)
    {
        printf("NET_DVR_RealPlay_V40 error\n");
        NET_DVR_Logout(m_lUserID);
        NET_DVR_Cleanup();
        return;
    }

    hWnd = (HWND)ui.frame1->winId();     //获取窗口句柄
    printf("frame1.hWnd=0x%x\n", hWnd);
    struPlayInfo = {0};
    struPlayInfo.hPlayWnd = hWnd;         //需要SDK解码时句柄设为有效值，仅取流不解码时可设为空
    struPlayInfo.lChannel     = 2;       //预览通道号
    struPlayInfo.dwStreamType = 0;       //0-主码流，1-子码流，2-码流3，3-码流4，以此类推
    struPlayInfo.dwLinkMode   = 0;       //0- TCP方式，1- UDP方式，2- 多播方式，3- RTP方式，4-RTP/RTSP，5-RSTP/HTTP
    struPlayInfo.bBlocked     = 0;       //0- 非阻塞取流，1- 阻塞取流

    m_lRealPlayHandle = NET_DVR_RealPlay_V40(m_lUserID, &struPlayInfo, NULL, NULL);
    if (m_lRealPlayHandle < 0)
    {
        printf("NET_DVR_RealPlay_V40 error\n");
        NET_DVR_Logout(m_lUserID);
        NET_DVR_Cleanup();
        return;
    }

    hWnd = (HWND)ui.frame2->winId();     //获取窗口句柄
    printf("frame2.hWnd=0x%x\n", hWnd);
    struPlayInfo = {0};
    struPlayInfo.hPlayWnd = hWnd;         //需要SDK解码时句柄设为有效值，仅取流不解码时可设为空
    struPlayInfo.lChannel     = 3;       //预览通道号
    struPlayInfo.dwStreamType = 0;       //0-主码流，1-子码流，2-码流3，3-码流4，以此类推
    struPlayInfo.dwLinkMode   = 0;       //0- TCP方式，1- UDP方式，2- 多播方式，3- RTP方式，4-RTP/RTSP，5-RSTP/HTTP
    struPlayInfo.bBlocked     = 0;       //0- 非阻塞取流，1- 阻塞取流

    m_lRealPlayHandle = NET_DVR_RealPlay_V40(m_lUserID, &struPlayInfo, NULL, NULL);
    if (m_lRealPlayHandle < 0)
    {
        printf("NET_DVR_RealPlay_V40 error\n");
        NET_DVR_Logout(m_lUserID);
        NET_DVR_Cleanup();
        return;
    }

    hWnd = (HWND)ui.frame3->winId();     //获取窗口句柄
    printf("frame3.hWnd=0x%x\n", hWnd);
    struPlayInfo = {0};
    struPlayInfo.hPlayWnd = hWnd;         //需要SDK解码时句柄设为有效值，仅取流不解码时可设为空
    struPlayInfo.lChannel     = 4;       //预览通道号
    struPlayInfo.dwStreamType = 0;       //0-主码流，1-子码流，2-码流3，3-码流4，以此类推
    struPlayInfo.dwLinkMode   = 0;       //0- TCP方式，1- UDP方式，2- 多播方式，3- RTP方式，4-RTP/RTSP，5-RSTP/HTTP
    struPlayInfo.bBlocked     = 0;       //0- 非阻塞取流，1- 阻塞取流

    m_lRealPlayHandle = NET_DVR_RealPlay_V40(m_lUserID, &struPlayInfo, NULL, NULL);
    if (m_lRealPlayHandle < 0)
    {
        printf("NET_DVR_RealPlay_V40 error\n");
        NET_DVR_Logout(m_lUserID);
        NET_DVR_Cleanup();
        return;
    }
}
