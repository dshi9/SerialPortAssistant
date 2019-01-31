
// Serial Port Assistant.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CSerialPortAssistantApp:
// See Serial Port Assistant.cpp for the implementation of this class
//

class CSerialPortAssistantApp : public CWinApp
{
public:
	CSerialPortAssistantApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CSerialPortAssistantApp theApp;