
// MFC��WinInetʾ��1Dlg.h : ͷ�ļ�
//

#pragma once


// CMFC��WinInetʾ��1Dlg �Ի���
class CMFC��WinInetʾ��1Dlg : public CDialogEx
{
// ����
public:
	CMFC��WinInetʾ��1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCWININET1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
