#pragma once

#include "MyWinInetClass.h"

// MyInternetDlg �Ի���

class MyInternetDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MyInternetDlg)

public:
	MyInternetDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyInternetDlg();

// �Ի�������
	enum { IDD = IDD_MFCWININET1_DIALOG };

	MyWinInetClass m_WinInetClass;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
