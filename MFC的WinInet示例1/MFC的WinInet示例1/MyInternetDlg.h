#pragma once

#include "MyWinInetClass.h"

// MyInternetDlg 对话框

class MyInternetDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MyInternetDlg)

public:
	MyInternetDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyInternetDlg();

// 对话框数据
	enum { IDD = IDD_MFCWININET1_DIALOG };

	MyWinInetClass m_WinInetClass;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
