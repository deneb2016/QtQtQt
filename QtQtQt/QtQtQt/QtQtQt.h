
// QtQtQt.h : QtQtQt ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CQtQtQtApp:
// �� Ŭ������ ������ ���ؼ��� QtQtQt.cpp�� �����Ͻʽÿ�.
//

class CQtQtQtApp : public CWinApp
{
public:
	CQtQtQtApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CQtQtQtApp theApp;
