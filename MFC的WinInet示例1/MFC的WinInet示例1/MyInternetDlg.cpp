// MyInternetDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC的WinInet示例1.h"
#include "MyInternetDlg.h"
#include "afxdialogex.h"


// MyInternetDlg 对话框

IMPLEMENT_DYNAMIC(MyInternetDlg, CDialogEx)

MyInternetDlg::MyInternetDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyInternetDlg::IDD, pParent)
{

}

MyInternetDlg::~MyInternetDlg()
{
}

void MyInternetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyInternetDlg, CDialogEx)
END_MESSAGE_MAP()


// MyInternetDlg 消息处理程序
