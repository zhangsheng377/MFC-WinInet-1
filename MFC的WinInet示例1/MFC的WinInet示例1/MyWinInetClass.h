#pragma once

#include <afxinet.h>
#include <WinInet.h>

class MyWinInetClass
{
private:
	CInternetSession m_session;						//���� Internet �Ự
public:
	MyWinInetClass();
	~MyWinInetClass();
	CString ConnectFtp(const CString sUrl);			//������� Ftp ���ܵĺ���
	CString ConnectHttp(const CString sUrl);		//������� Http ���ܵĺ���
	CString ConnectGopher(const CString sUrl);		//������� Gopher ���ܵĺ���
};

