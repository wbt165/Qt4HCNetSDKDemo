#include "Qt4HCNetSDKDemo.h"
#include <QMessageBox>
#include <stdio.h>

Qt4HCNetSDKDemo::Qt4HCNetSDKDemo(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	ui.setupUi(this);

	// ��ʼ�������
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
		QMessageBox::information(this,tr("��ʾ"), \
			tr("SDK_LAST_ERROR=%1").arg(NET_DVR_GetLastError()));
	}

	NET_DVR_SetConnectTime(10000, 1);

	//---------------------------------------
	// ע���豸
	//��¼�����������豸��ַ����¼�û��������
	NET_DVR_USER_LOGIN_INFO struLoginInfo = {0};
	struLoginInfo.bUseAsynLogin = 0; //ͬ����¼��ʽ
    strcpy(struLoginInfo.sDeviceAddress, "192.168.100.213"); //�豸IP��ַ
	struLoginInfo.wPort = 8000; //�豸����˿�
	strcpy(struLoginInfo.sUserName, "admin"); //�豸��¼�û���
    strcpy(struLoginInfo.sPassword, "12345"); //�豸��¼����

	//�豸��Ϣ, �������
	NET_DVR_DEVICEINFO_V40 struDeviceInfoV40 = {0};

	m_lUserID = NET_DVR_Login_V40(&struLoginInfo, &struDeviceInfoV40);
	if (m_lUserID < 0)
	{
		QMessageBox::information(this,tr("��ʾ"), \
			tr("��¼ʧ�ܣ�ʧ��ԭ��=%1").arg(NET_DVR_GetLastError()));
		exit(0);
	}

    on_pushButton_clicked();

}

Qt4HCNetSDKDemo::~Qt4HCNetSDKDemo()
{
	//�ر�Ԥ��
	if (m_lRealPlayHandle >= 0)
	{
		NET_DVR_StopRealPlay(m_lRealPlayHandle);
		m_lRealPlayHandle = -1;
	}
	//ע���û�
	if (m_lUserID >= 0)
	{
		NET_DVR_Logout(m_lUserID);
		m_lUserID = -1;
	}
	//�ͷ�SDK��Դ
	if (m_bInit)
	{
		NET_DVR_Cleanup();
		m_bInit = FALSE;
	}
}

void Qt4HCNetSDKDemo::on_pushButton_clicked()
{
    HWND hWnd = (HWND)ui.frame0->winId();     //��ȡ���ھ��
    printf("frame0.hWnd=0x%x\n", hWnd);
    NET_DVR_PREVIEWINFO struPlayInfo = {0};
    struPlayInfo.hPlayWnd = hWnd;         //��ҪSDK����ʱ�����Ϊ��Чֵ����ȡ��������ʱ����Ϊ��
    struPlayInfo.lChannel     = 1;       //Ԥ��ͨ����
    struPlayInfo.dwStreamType = 0;       //0-��������1-��������2-����3��3-����4���Դ�����
    struPlayInfo.dwLinkMode   = 0;       //0- TCP��ʽ��1- UDP��ʽ��2- �ಥ��ʽ��3- RTP��ʽ��4-RTP/RTSP��5-RSTP/HTTP
    struPlayInfo.bBlocked     = 0;       //0- ������ȡ����1- ����ȡ��

    m_lRealPlayHandle = NET_DVR_RealPlay_V40(m_lUserID, &struPlayInfo, NULL, NULL);
    if (m_lRealPlayHandle < 0)
    {
        printf("NET_DVR_RealPlay_V40 error\n");
        NET_DVR_Logout(m_lUserID);
        NET_DVR_Cleanup();
        return;
    }

    hWnd = (HWND)ui.frame1->winId();     //��ȡ���ھ��
    printf("frame1.hWnd=0x%x\n", hWnd);
    struPlayInfo = {0};
    struPlayInfo.hPlayWnd = hWnd;         //��ҪSDK����ʱ�����Ϊ��Чֵ����ȡ��������ʱ����Ϊ��
    struPlayInfo.lChannel     = 2;       //Ԥ��ͨ����
    struPlayInfo.dwStreamType = 0;       //0-��������1-��������2-����3��3-����4���Դ�����
    struPlayInfo.dwLinkMode   = 0;       //0- TCP��ʽ��1- UDP��ʽ��2- �ಥ��ʽ��3- RTP��ʽ��4-RTP/RTSP��5-RSTP/HTTP
    struPlayInfo.bBlocked     = 0;       //0- ������ȡ����1- ����ȡ��

    m_lRealPlayHandle = NET_DVR_RealPlay_V40(m_lUserID, &struPlayInfo, NULL, NULL);
    if (m_lRealPlayHandle < 0)
    {
        printf("NET_DVR_RealPlay_V40 error\n");
        NET_DVR_Logout(m_lUserID);
        NET_DVR_Cleanup();
        return;
    }

    hWnd = (HWND)ui.frame2->winId();     //��ȡ���ھ��
    printf("frame2.hWnd=0x%x\n", hWnd);
    struPlayInfo = {0};
    struPlayInfo.hPlayWnd = hWnd;         //��ҪSDK����ʱ�����Ϊ��Чֵ����ȡ��������ʱ����Ϊ��
    struPlayInfo.lChannel     = 3;       //Ԥ��ͨ����
    struPlayInfo.dwStreamType = 0;       //0-��������1-��������2-����3��3-����4���Դ�����
    struPlayInfo.dwLinkMode   = 0;       //0- TCP��ʽ��1- UDP��ʽ��2- �ಥ��ʽ��3- RTP��ʽ��4-RTP/RTSP��5-RSTP/HTTP
    struPlayInfo.bBlocked     = 0;       //0- ������ȡ����1- ����ȡ��

    m_lRealPlayHandle = NET_DVR_RealPlay_V40(m_lUserID, &struPlayInfo, NULL, NULL);
    if (m_lRealPlayHandle < 0)
    {
        printf("NET_DVR_RealPlay_V40 error\n");
        NET_DVR_Logout(m_lUserID);
        NET_DVR_Cleanup();
        return;
    }

    hWnd = (HWND)ui.frame3->winId();     //��ȡ���ھ��
    printf("frame3.hWnd=0x%x\n", hWnd);
    struPlayInfo = {0};
    struPlayInfo.hPlayWnd = hWnd;         //��ҪSDK����ʱ�����Ϊ��Чֵ����ȡ��������ʱ����Ϊ��
    struPlayInfo.lChannel     = 4;       //Ԥ��ͨ����
    struPlayInfo.dwStreamType = 0;       //0-��������1-��������2-����3��3-����4���Դ�����
    struPlayInfo.dwLinkMode   = 0;       //0- TCP��ʽ��1- UDP��ʽ��2- �ಥ��ʽ��3- RTP��ʽ��4-RTP/RTSP��5-RSTP/HTTP
    struPlayInfo.bBlocked     = 0;       //0- ������ȡ����1- ����ȡ��

    m_lRealPlayHandle = NET_DVR_RealPlay_V40(m_lUserID, &struPlayInfo, NULL, NULL);
    if (m_lRealPlayHandle < 0)
    {
        printf("NET_DVR_RealPlay_V40 error\n");
        NET_DVR_Logout(m_lUserID);
        NET_DVR_Cleanup();
        return;
    }
}
