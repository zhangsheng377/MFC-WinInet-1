
// MFC的WinInet示例1Dlg.h : 头文件
//

#pragma once

#include "MyWinInetClass.h"

// CMFC的WinInet示例1Dlg 对话框
class CMFC的WinInet示例1Dlg : public CDialogEx
{
// 构造
public:
	CMFC的WinInet示例1Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCWININET1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_Url;
	MyWinInetClass m_WinInetClass;
	afx_msg void OnBnClickedButtonHttp();
	CString m_EditResult;
	afx_msg void OnBnClickedButtonFtp();
	afx_msg void OnBnClickedButtonGopher();
};
