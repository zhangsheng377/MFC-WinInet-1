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
	CString sResult;									//存储连接信息的字符串
	CFtpConnection *Ftpconnection = NULL;
	sResult = "";
	sResult += L"Trying to connect Ftp sites:" + sUrl + L"\r\n";
	sResult += L"Connection is established.\r\n";
	Ftpconnection = m_session.GetFtpConnection(sUrl);	//建立到Ftp服务器的连接
	if (Ftpconnection)
	{
		sResult += L"Connection established.\r\n";
		CString sCurDir;
		Ftpconnection->GetCurrentDirectory(sCurDir);	//得到Ftp服务器的当前目录
		sResult += L"current directory is:" + sCurDir;
		sResult += L"\r\n以下是该文件夹下的文件列表:\r\n";
		CFtpFileFind finder(Ftpconnection);
		BOOL bWorking = finder.FindFile(L"*");
		while (bWorking)
		{
			bWorking = finder.FindNextFile();
			sResult += L"\t" + finder.GetFileURL() + L"\r\n";							//好像有点问题
		}
		Ftpconnection->Close();							//关闭连接
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
	hHttpFile = (CInternetFile*)m_session.OpenURL(sUrl);	//得到文件指针
	if (hHttpFile)
	{
		sResult += L"Connection established.\r\n";
		CString sLine;
		while (hHttpFile->ReadString(sLine))				//读取Http服务器上的内容
		{
			sResult += sLine + L"\r\n";
		}
		hHttpFile->Close();									//关闭连接
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
	hGopherFile = (CInternetFile*)m_session.OpenURL(sUrl);		//得到文件指针
	if (hGopherFile)
	{
		sResult += L"Connection established.\r\n";
		CString sLine;
		while (hGopherFile->ReadString(sLine))				//读取Gopher服务器上的内容
		{
			sResult += sLine + L"\r\n";
		}
		hGopherFile->Close();									//关闭连接
	}
	else
	{
		sResult += L"There are some errors in finding this Http sites";
	}
	return sResult;
}
