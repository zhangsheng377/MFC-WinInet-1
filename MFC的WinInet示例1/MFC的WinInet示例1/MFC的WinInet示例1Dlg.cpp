
// MFC��WinInetʾ��1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC��WinInetʾ��1.h"
#include "MFC��WinInetʾ��1Dlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC��WinInetʾ��1Dlg �Ի���



CMFC��WinInetʾ��1Dlg::CMFC��WinInetʾ��1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC��WinInetʾ��1Dlg::IDD, pParent)
	, m_Url(_T(""))
	, m_EditResult(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC��WinInetʾ��1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_URL, m_Url);
	DDX_Text(pDX, IDC_EDIT_RESULT, m_EditResult);
}

BEGIN_MESSAGE_MAP(CMFC��WinInetʾ��1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_HTTP, &CMFC��WinInetʾ��1Dlg::OnBnClickedButtonHttp)
	ON_BN_CLICKED(IDC_BUTTON_FTP, &CMFC��WinInetʾ��1Dlg::OnBnClickedButtonFtp)
	ON_BN_CLICKED(IDC_BUTTON_GOPHER, &CMFC��WinInetʾ��1Dlg::OnBnClickedButtonGopher)
END_MESSAGE_MAP()


// CMFC��WinInetʾ��1Dlg ��Ϣ�������

BOOL CMFC��WinInetʾ��1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFC��WinInetʾ��1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFC��WinInetʾ��1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC��WinInetʾ��1Dlg::OnBnClickedButtonHttp()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_EditResult = L"";
	m_EditResult += m_WinInetClass.ConnectHttp(m_Url);
	UpdateData(FALSE);
}


void CMFC��WinInetʾ��1Dlg::OnBnClickedButtonFtp()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_EditResult = L"";
	m_EditResult += m_WinInetClass.ConnectFtp(m_Url);
	UpdateData(FALSE);
}


void CMFC��WinInetʾ��1Dlg::OnBnClickedButtonGopher()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_EditResult = L"";
	m_EditResult += m_WinInetClass.ConnectGopher(m_Url);
	UpdateData(FALSE);
}
