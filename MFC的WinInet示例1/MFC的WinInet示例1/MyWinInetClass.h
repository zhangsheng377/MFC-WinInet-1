#pragma once

#include <afxinet.h>
#include <WinInet.h>

class MyWinInetClass
{
private:
	CInternetSession m_session;						//建立 Internet 会话
public:
	MyWinInetClass();
	~MyWinInetClass();
	CString ConnectFtp(const CString sUrl);			//完成连接 Ftp 功能的函数
	CString ConnectHttp(const CString sUrl);		//完成连接 Http 功能的函数
	CString ConnectGopher(const CString sUrl);		//完成连接 Gopher 功能的函数
};

