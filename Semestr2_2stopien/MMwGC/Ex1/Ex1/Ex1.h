
// Ex1.h : main header file for the Ex1 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CEx1App:
// See Ex1.cpp for the implementation of this class
//

class CEx1App : public CWinApp
{
public:
	CEx1App();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CEx1App theApp;
