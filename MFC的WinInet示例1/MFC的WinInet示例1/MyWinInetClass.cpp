#include "stdafx.h"
#include "MyWinInetClass.h"


MyWinInetClass::MyWinInetClass()
{
}


MyWinInetClass::~MyWinInetClass()
{
}

CString MyWinInetClass::ConnectFtp(const CString sUrl)
{
	CString sResult;									//�洢������Ϣ���ַ���
	CFtpConnection *Ftpconnection = NULL;
	sResult = "";
	sResult += L"Trying to connect Ftp sites:" + sUrl + L"\r\n";
	sResult += L"Connection is established.\r\n";
	Ftpconnection = m_session.GetFtpConnection(sUrl);	//������Ftp������������
	if (Ftpconnection)
	{
		sResult += L"Connection established.\r\n";
		CString sCurDir;
		Ftpconnection->GetCurrentDirectory(sCurDir);	//�õ�Ftp�������ĵ�ǰĿ¼
		sResult += L"current directory is:" + sCurDir;
		sResult += L"\r\n�����Ǹ��ļ����µ��ļ��б�:\r\n";
		CFtpFileFind finder(Ftpconnection);
		BOOL bWorking = finder.FindFile(L"*");
		while (bWorking)
		{
			bWorking = finder.FindNextFile();
			sResult += L"\t" + finder.GetFileURL() + L"\r\n";							//�����е�����
		}
		Ftpconnection->Close();							//�ر�����
	}
	else sResult += L"There are some errors in finding this Ftp sites";
	return sResult;
}

CString MyWinInetClass::ConnectHttp(const CString sUrl)
{
	CString sResult;
	CInternetFile *hHttpFile = NULL;
	sResult = L"";
	sResult += L"Trying to connect Http sites:" + sUrl + L"\r\n";
	hHttpFile = (CInternetFile*)m_session.OpenURL(sUrl);	//�õ��ļ�ָ��
	if (hHttpFile)
	{
		sResult += L"Connection established.\r\n";
		CString sLine;
		while (hHttpFile->ReadString(sLine))				//��ȡHttp�������ϵ�����
		{
			sResult += sLine + L"\r\n";
		}
		hHttpFile->Close();									//�ر�����
	}
	else
	{
		sResult += L"There are some errors in finding this Http sites";
	}
	return sResult;
}

CString MyWinInetClass::ConnectGopher(const CString sUrl)
{
	CString sResult;
	CInternetFile *hGopherFile = NULL;
	sResult = L"";
	sResult += L"Trying to connect Gopher sites:" + sUrl + L"\r\n";
	hGopherFile = (CInternetFile*)m_session.OpenURL(sUrl);		//�õ��ļ�ָ��
	if (hGopherFile)
	{
		sResult += L"Connection established.\r\n";
		CString sLine;
		while (hGopherFile->ReadString(sLine))				//��ȡGopher�������ϵ�����
		{
			sResult += sLine + L"\r\n";
		}
		hGopherFile->Close();									//�ر�����
	}
	else
	{
		sResult += L"There are some errors in finding this Http sites";
	}
	return sResult;
}
