
// Serial Port AssistantDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Serial Port Assistant.h"
#include "Serial Port AssistantDlg.h"
#include "afxdialogex.h"
#include "Crc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSerialPortAssistantDlg dialog



CSerialPortAssistantDlg::CSerialPortAssistantDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSerialPortAssistantDlg::IDD, pParent)
	, m_line1(_T(""))
	, m_crc1(_T(""))
	, m_nPort(0)
	, m_strReceive(_T(""))
	, m_direction(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	bsend = FALSE;
	m_nPort = 1;
	m_RateMode = 3;
	CRCmode = true;
}

void CSerialPortAssistantDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_line1);
	DDX_Text(pDX, IDC_EDIT3, m_crc1);

	DDX_Control(pDX, IDC_MSCOMM1, m_Com);
	DDX_Text(pDX, IDC_EDIT66, m_nPort);
	DDX_Control(pDX, IDC_COMBO5, m_ctrlRate);
	DDX_Text(pDX, IDC_EDIT65, m_strReceive);

	DDX_Control(pDX, IDC_BUTTON1, m_CRCcontrol);
	DDX_Text(pDX, IDC_EDIT67, m_direction);
}

BEGIN_MESSAGE_MAP(CSerialPortAssistantDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDSEND, &CSerialPortAssistantDlg::OnBnClickedSend)
	ON_BN_CLICKED(IDSEND2, &CSerialPortAssistantDlg::OnBnClickedSend2)
	ON_BN_CLICKED(IDSEND3, &CSerialPortAssistantDlg::OnBnClickedSend3)
	ON_BN_CLICKED(IDSEND4, &CSerialPortAssistantDlg::OnBnClickedSend4)
	ON_BN_CLICKED(IDSEND5, &CSerialPortAssistantDlg::OnBnClickedSend5)
	ON_BN_CLICKED(IDSEND6, &CSerialPortAssistantDlg::OnBnClickedSend6)
	ON_BN_CLICKED(IDSEND7, &CSerialPortAssistantDlg::OnBnClickedSend7)
	ON_BN_CLICKED(IDSEND8, &CSerialPortAssistantDlg::OnBnClickedSend8)
	ON_BN_CLICKED(IDSEND9, &CSerialPortAssistantDlg::OnBnClickedSend9)
	ON_BN_CLICKED(IDSEND10, &CSerialPortAssistantDlg::OnBnClickedSend10)
	ON_BN_CLICKED(IDSEND11, &CSerialPortAssistantDlg::OnBnClickedSend11)
	ON_BN_CLICKED(IDSEND12, &CSerialPortAssistantDlg::OnBnClickedSend12)
	ON_BN_CLICKED(IDSEND13, &CSerialPortAssistantDlg::OnBnClickedSend13)
	ON_BN_CLICKED(IDSEND14, &CSerialPortAssistantDlg::OnBnClickedSend14)
	ON_BN_CLICKED(IDSEND15, &CSerialPortAssistantDlg::OnBnClickedSend15)
	ON_BN_CLICKED(IDSEND16, &CSerialPortAssistantDlg::OnBnClickedSend16)
	ON_BN_CLICKED(IDSEND17, &CSerialPortAssistantDlg::OnBnClickedSend17)
	ON_BN_CLICKED(IDSEND18, &CSerialPortAssistantDlg::OnBnClickedSend18)
	ON_BN_CLICKED(IDSEND19, &CSerialPortAssistantDlg::OnBnClickedSend19)
	ON_BN_CLICKED(IDSEND20, &CSerialPortAssistantDlg::OnBnClickedSend20)
	ON_BN_CLICKED(IDSEND21, &CSerialPortAssistantDlg::OnBnClickedSend21)
	ON_BN_CLICKED(IDSEND22, &CSerialPortAssistantDlg::OnBnClickedSend22)
	ON_BN_CLICKED(IDSEND23, &CSerialPortAssistantDlg::OnBnClickedSend23)
	ON_BN_CLICKED(IDSEND24, &CSerialPortAssistantDlg::OnBnClickedSend24)
	ON_BN_CLICKED(IDSEND25, &CSerialPortAssistantDlg::OnBnClickedSend25)
	ON_BN_CLICKED(IDSEND26, &CSerialPortAssistantDlg::OnBnClickedSend26)
	ON_BN_CLICKED(IDSEND27, &CSerialPortAssistantDlg::OnBnClickedSend27)
	ON_BN_CLICKED(IDSEND28, &CSerialPortAssistantDlg::OnBnClickedSend28)
	ON_BN_CLICKED(IDSEND29, &CSerialPortAssistantDlg::OnBnClickedSend29)
	ON_BN_CLICKED(IDSEND30, &CSerialPortAssistantDlg::OnBnClickedSend30)
	ON_BN_CLICKED(IDSEND31, &CSerialPortAssistantDlg::OnBnClickedSend31)
	ON_BN_CLICKED(IDSEND32, &CSerialPortAssistantDlg::OnBnClickedSend32)
	ON_BN_CLICKED(IDC_SETTING_BUTTON, &CSerialPortAssistantDlg::OnBnClickedSettingButton)
	ON_BN_CLICKED(IDC_CLEAR, &CSerialPortAssistantDlg::OnBnClickedClear)
	ON_BN_CLICKED(IDC_BUTTON1, &CSerialPortAssistantDlg::OnBnClickedButton1)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CSerialPortAssistantDlg message handlers

BOOL CSerialPortAssistantDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_ctrlRate.AddString(_T("115200"));
	m_ctrlRate.AddString(_T("38400"));
	m_ctrlRate.AddString(_T("19200"));
	m_ctrlRate.AddString(_T("9600"));
	m_ctrlRate.SetCurSel(m_RateMode);
	CString directory(_T("D:\\keeper\\save.txt"));
	GetDlgItem(IDC_EDIT67)->SetWindowText(directory);
	Reader(directory);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSerialPortAssistantDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSerialPortAssistantDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSerialPortAssistantDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSerialPortAssistantDlg::OnBnClickedSend()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT1);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT3)->SetWindowText(crc_display);//CRC Display
}


void CSerialPortAssistantDlg::OnBnClickedSend2()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT2);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT4)->SetWindowText(crc_display);//CRC Display
}


void CSerialPortAssistantDlg::OnBnClickedSend3()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT5);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT6)->SetWindowText(crc_display);//CRC Display
}


void CSerialPortAssistantDlg::OnBnClickedSend4()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT7);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT8)->SetWindowText(crc_display);//CRC Display
}


void CSerialPortAssistantDlg::OnBnClickedSend5()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT9);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT10)->SetWindowText(crc_display);//CRC Display
}


void CSerialPortAssistantDlg::OnBnClickedSend6()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT11);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT12)->SetWindowText(crc_display);//CRC Display
}


void CSerialPortAssistantDlg::OnBnClickedSend7()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT13);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT14)->SetWindowText(crc_display);//CRC Display
}


void CSerialPortAssistantDlg::OnBnClickedSend8()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT15);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT16)->SetWindowText(crc_display);//CRC Display
}


void CSerialPortAssistantDlg::OnBnClickedSend9()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT17);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT18)->SetWindowText(crc_display);//CRC Display
}


void CSerialPortAssistantDlg::OnBnClickedSend10()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT19);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT20)->SetWindowText(crc_display);//CRC Display
}


void CSerialPortAssistantDlg::OnBnClickedSend11()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT21);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT22)->SetWindowText(crc_display);//CRC Display
}


void CSerialPortAssistantDlg::OnBnClickedSend12()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT23);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT24)->SetWindowText(crc_display);//CRC Display
}


void CSerialPortAssistantDlg::OnBnClickedSend13()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT25);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT26)->SetWindowText(crc_display);//CRC Display
}


void CSerialPortAssistantDlg::OnBnClickedSend14()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT27);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT28)->SetWindowText(crc_display);//CRC Display
}


void CSerialPortAssistantDlg::OnBnClickedSend15()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT29);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT30)->SetWindowText(crc_display);//CRC Display
}


void CSerialPortAssistantDlg::OnBnClickedSend16()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT31);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT32)->SetWindowText(crc_display);//CRC Display
}


void CSerialPortAssistantDlg::OnBnClickedSend17()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT33);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT34)->SetWindowText(crc_display);//CRC Display
}


void CSerialPortAssistantDlg::OnBnClickedSend18()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT35);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT36)->SetWindowText(crc_display);//CRC Display
}


void CSerialPortAssistantDlg::OnBnClickedSend19()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT37);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT38)->SetWindowText(crc_display);//CRC Display
}


void CSerialPortAssistantDlg::OnBnClickedSend20()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT39);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT40)->SetWindowText(crc_display);//CRC Display
}


void CSerialPortAssistantDlg::OnBnClickedSend21()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT41);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT42)->SetWindowText(crc_display);//CRC Display
}


void CSerialPortAssistantDlg::OnBnClickedSend22()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT43);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT44)->SetWindowText(crc_display);//CRC Display
}


void CSerialPortAssistantDlg::OnBnClickedSend23()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT45);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT46)->SetWindowText(crc_display);//CRC Display
}


void CSerialPortAssistantDlg::OnBnClickedSend24()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT47);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT48)->SetWindowText(crc_display);//CRC Display
}


void CSerialPortAssistantDlg::OnBnClickedSend25()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT49);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT50)->SetWindowText(crc_display);//CRC Display
}


void CSerialPortAssistantDlg::OnBnClickedSend26()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT51);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT52)->SetWindowText(crc_display);//CRC Display
}


void CSerialPortAssistantDlg::OnBnClickedSend27()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT53);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT54)->SetWindowText(crc_display);//CRC Display
}


void CSerialPortAssistantDlg::OnBnClickedSend28()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT55);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT56)->SetWindowText(crc_display);//CRC Display
}


void CSerialPortAssistantDlg::OnBnClickedSend29()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT57);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT58)->SetWindowText(crc_display);//CRC Display
}


void CSerialPortAssistantDlg::OnBnClickedSend30()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT59);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT60)->SetWindowText(crc_display);//CRC Display
}


void CSerialPortAssistantDlg::OnBnClickedSend31()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT61);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT62)->SetWindowText(crc_display);//CRC Display
}


void CSerialPortAssistantDlg::OnBnClickedSend32()
{
	// TODO: Add your control notification handler code here
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT63);
	pBox->GetWindowText(str);
	CString crc_display;
	sender(str,crc_display);
	GetDlgItem(IDC_EDIT64)->SetWindowText(crc_display);//CRC Display
}

BEGIN_EVENTSINK_MAP(CSerialPortAssistantDlg, CDialogEx)
	ON_EVENT(CSerialPortAssistantDlg, IDC_MSCOMM1, 1, CSerialPortAssistantDlg::OnOncommMscomm1, VTS_NONE)
	END_EVENTSINK_MAP()


void CSerialPortAssistantDlg::OnOncommMscomm1()
{
	// TODO: Add your message handler code here
	VARIANT variant_inp;
	COleSafeArray safearray_inp;
	LONG len,k;
	BYTE rxdata[2048];
	CString strtemp;
	CString strspace(_T("_"));
	if(m_Com.get_CommEvent()==2)
	{
		variant_inp = m_Com.get_Input();
		safearray_inp = variant_inp;
		len = safearray_inp.GetOneDimSize();
		for(k=0;k<len;k++)
		{
			safearray_inp.GetElement(&k,rxdata+k);
		}
		for(k=0;k<len-1;k++)
		{
			BYTE bt =*(char*)(rxdata+k);
			strtemp.Format(_T("%c"),bt);
	
			if(k==3||k==5||k==7||k==12)
			{
				m_strReceive = m_strReceive+strspace;
			}

			m_strReceive = m_strReceive + strtemp;
		}
			
		m_strReceive += "\r\n";	
		}
		this->SetDlgItemTextW(IDC_EDIT65, m_strReceive);
}


void CSerialPortAssistantDlg::OnBnClickedSettingButton()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_RateMode = m_ctrlRate.GetCurSel();
	if(m_Com.get_PortOpen())
	{
		m_Com.put_PortOpen(FALSE);
	}
	m_Com.put_CommPort(m_nPort);
	if( !m_Com.get_PortOpen())
	{
		m_Com.put_PortOpen(TRUE);
	}
	else
	{
		AfxMessageBox(_T("Can not open Serial Port"));
	}

	if(m_RateMode==0)
	{
		m_Com.put_Settings(_T("115200,n,8,1"));
	}
	else if(m_RateMode==1)
	{
		m_Com.put_Settings(_T("19200,n,8,1"));
	}
	else if(m_RateMode==2)
	{
		m_Com.put_Settings(_T("38400,n,8,1"));
	}
	else if(m_RateMode==3)
	{
		m_Com.put_Settings(_T("9600,n,8,1"));
	}
	m_Com.put_RThreshold(1);
	m_Com.put_InputMode(1);
	m_Com.put_InputLen(0);
	m_Com.get_Input();
}


void CSerialPortAssistantDlg::OnBnClickedClear()
{
	// TODO: Add your control notification handler code here
	m_strReceive=_T("");
	this->SetDlgItemTextW(IDC_EDIT65, m_strReceive);
}
int CSerialPortAssistantDlg::String2Hex(CString str, CByteArray &senddata)
{
	int len = str.GetLength();
	string sender = (CStringA) str;
	senddata.SetSize(len+1);
	for(int i=0; i<len; i++)
	{
		senddata[i] = sender[i];
	}
	senddata[len] = crcval;
	return len;
}


void CSerialPortAssistantDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	if(CRCmode==true)
	{
		CRCmode = false;
		m_CRCcontrol.SetWindowTextW(_T("CRC+1"));
	}
	else
	{
		CRCmode = true;
		m_CRCcontrol.SetWindowTextW(_T("CRC"));
	}
}
void CSerialPortAssistantDlg::sender(CString str, CString &crc_display)
{
	CRCcalculator crc_cal;
	CString sendstr;
	string pre_sendstr;
	string pre_addr_cmd;
	unsigned char a = 0x0D;
	unsigned char b = 0x0A;
	pre_addr_cmd = (CStringA)str;
	if(str.GetLength()==0)
	{
		AfxMessageBox(_T("Please input the Command !"));
		return;
	}
	crcval = crc_cal.getCRC(str);
	crc_display = crc_cal.Display(crcval);
	if(CRCmode == false)
	{
		pre_addr_cmd[2]=pre_addr_cmd[2]+1;
		crcval+=1;
	}
	pre_sendstr.push_back(a);
	pre_sendstr.append(pre_addr_cmd);
	pre_sendstr.push_back(b);
	sendstr = pre_sendstr.c_str();
	CByteArray hexdata;
	int len = String2Hex(sendstr,hexdata);
	m_Com.put_Output(COleVariant(hexdata));
	m_Com.get_Input();
}

void CSerialPortAssistantDlg::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT67);
	pBox->GetWindowText(str);
	Keeper(str);
	CDialogEx::OnClose();
}

void CSerialPortAssistantDlg::Reader(CString filename)
{
	
	char fname[128];
	strcpy_s(fname,128,(CStringA)filename); 
	FILE* reading;
	fopen_s(&reading,fname,"r");
	if(reading == NULL)
	{
		return;
	}
	char mystring[33];
	fgets(mystring,33,reading);
	string tmp = mystring;
	CString com_display;
	com_display = tmp.c_str();
	GetDlgItem(IDC_EDIT66)->SetWindowText(com_display);

	if(fgets(mystring,33,reading)!=NULL)//1
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT1)->SetWindowText(com_display);
		}
	}

	if(fgets(mystring,33,reading)!=NULL)//2
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT2)->SetWindowText(com_display);
		}
	}

	if(fgets(mystring,33,reading)!=NULL)//3
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT5)->SetWindowText(com_display);
		}
	}

	if(fgets(mystring,33,reading)!=NULL)//4
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT7)->SetWindowText(com_display);
		}
	}

	if(fgets(mystring,33,reading)!=NULL)//5
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT9)->SetWindowText(com_display);
		}
	}

	if(fgets(mystring,33,reading)!=NULL)//6
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT11)->SetWindowText(com_display);
		}
	}

	if(fgets(mystring,33,reading)!=NULL)//7
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT13)->SetWindowText(com_display);
		}
	}

	if(fgets(mystring,33,reading)!=NULL)//8
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT15)->SetWindowText(com_display);
		}
	}

	if(fgets(mystring,33,reading)!=NULL)//9
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT17)->SetWindowText(com_display);
		}
	}

	if(fgets(mystring,33,reading)!=NULL)//10
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT19)->SetWindowText(com_display);
		}
	}

	if(fgets(mystring,33,reading)!=NULL)//11
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT21)->SetWindowText(com_display);
		}
	}

	if(fgets(mystring,33,reading)!=NULL)//12
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT23)->SetWindowText(com_display);
		}
	}

	if(fgets(mystring,33,reading)!=NULL)//13
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT25)->SetWindowText(com_display);
		}
	}

	if(fgets(mystring,33,reading)!=NULL)//14
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT27)->SetWindowText(com_display);
		}
	}

	if(fgets(mystring,33,reading)!=NULL)//15
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT29)->SetWindowText(com_display);
		}
	}

	if(fgets(mystring,33,reading)!=NULL)//16
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT31)->SetWindowText(com_display);
		}
	}

	if(fgets(mystring,33,reading)!=NULL)//17
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT33)->SetWindowText(com_display);
		}
	}

	if(fgets(mystring,33,reading)!=NULL)//18
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT35)->SetWindowText(com_display);
		}
	}

	if(fgets(mystring,33,reading)!=NULL)//19
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT37)->SetWindowText(com_display);
		}
	}

	if(fgets(mystring,33,reading)!=NULL)//20
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT39)->SetWindowText(com_display);
		}
	}

	if(fgets(mystring,33,reading)!=NULL)//21
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT41)->SetWindowText(com_display);
		}
	}

	if(fgets(mystring,33,reading)!=NULL)//22
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT43)->SetWindowText(com_display);
		}
	}

	if(fgets(mystring,33,reading)!=NULL)//23
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT45)->SetWindowText(com_display);
		}
	}

	if(fgets(mystring,33,reading)!=NULL)//24
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT47)->SetWindowText(com_display);
		}
	}

	if(fgets(mystring,33,reading)!=NULL)//25
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT49)->SetWindowText(com_display);
		}
	}

	if(fgets(mystring,33,reading)!=NULL)//26
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT51)->SetWindowText(com_display);
		}
	}

	if(fgets(mystring,33,reading)!=NULL)//27
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT53)->SetWindowText(com_display);
		}
	}

	if(fgets(mystring,33,reading)!=NULL)//28
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT55)->SetWindowText(com_display);
		}
	}

	if(fgets(mystring,33,reading)!=NULL)//29
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT57)->SetWindowText(com_display);
		}
	}

	if(fgets(mystring,33,reading)!=NULL)//30
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT59)->SetWindowText(com_display);
		}
	}

	if(fgets(mystring,33,reading)!=NULL)//31
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT61)->SetWindowText(com_display);
		}
	}

	if(fgets(mystring,33,reading)!=NULL)//32
	{
		if(mystring[0]!='\n')
		{
			tmp = mystring;
			com_display = tmp.c_str();
			GetDlgItem(IDC_EDIT63)->SetWindowText(com_display);
		}
	}
	fclose(reading);
}
void CSerialPortAssistantDlg::writting_helper(CString str, FILE* writting)
{
	string savestring;
	savestring = (CStringA)str;
	if(savestring.length()!=0)
	{
		for(size_t i=0;i<savestring.length();i++)
		{
			fprintf_s(writting,"%c",savestring[i]);
		}
		if(savestring[savestring.length()-1]!='\n')
		{
			fprintf_s(writting, "\n");
		}
	}
	else
	{
		fprintf_s(writting, "\n");
	}
}
void CSerialPortAssistantDlg::Keeper(CString filename)
{
	char fname[128];
	strcpy_s(fname,128,(CStringA)filename); 
	FILE* writting;
	fopen_s(&writting,fname,"w+");
	if(writting == NULL)
	{
		return;
	}

	CString str;
	CEdit* pBox;
	pBox = (CEdit*)GetDlgItem(IDC_EDIT66);
	pBox->GetWindowText(str);
	string savestring;
	savestring = (CStringA)str;
	for(size_t i=0;i<savestring.length();i++)
	{
		fprintf_s(writting,"%c",savestring[i]);
	}
	if(savestring[savestring.length()-1]!='\n')
	{
		fprintf_s(writting, "\n");
	}

	pBox = (CEdit*)GetDlgItem(IDC_EDIT1);//1
	pBox->GetWindowText(str);
	writting_helper(str,writting);

	pBox = (CEdit*)GetDlgItem(IDC_EDIT2);//2
	pBox->GetWindowText(str);
	writting_helper(str,writting);

	pBox = (CEdit*)GetDlgItem(IDC_EDIT5);//3
	pBox->GetWindowText(str);
	writting_helper(str,writting);

	pBox = (CEdit*)GetDlgItem(IDC_EDIT7);//4
	pBox->GetWindowText(str);
	writting_helper(str,writting);

	pBox = (CEdit*)GetDlgItem(IDC_EDIT9);//5
	pBox->GetWindowText(str);
	writting_helper(str,writting);

	pBox = (CEdit*)GetDlgItem(IDC_EDIT11);//6
	pBox->GetWindowText(str);
	writting_helper(str,writting);

	pBox = (CEdit*)GetDlgItem(IDC_EDIT13);//7
	pBox->GetWindowText(str);
	writting_helper(str,writting);

	pBox = (CEdit*)GetDlgItem(IDC_EDIT15);//8
	pBox->GetWindowText(str);
	writting_helper(str,writting);

	pBox = (CEdit*)GetDlgItem(IDC_EDIT17);//9
	pBox->GetWindowText(str);
	writting_helper(str,writting);

	pBox = (CEdit*)GetDlgItem(IDC_EDIT19);//10
	pBox->GetWindowText(str);
	writting_helper(str,writting);

	pBox = (CEdit*)GetDlgItem(IDC_EDIT21);//11
	pBox->GetWindowText(str);
	writting_helper(str,writting);

	pBox = (CEdit*)GetDlgItem(IDC_EDIT23);//12
	pBox->GetWindowText(str);
	writting_helper(str,writting);

	pBox = (CEdit*)GetDlgItem(IDC_EDIT25);//13
	pBox->GetWindowText(str);
	writting_helper(str,writting);

	pBox = (CEdit*)GetDlgItem(IDC_EDIT27);//14
	pBox->GetWindowText(str);
	writting_helper(str,writting);

	pBox = (CEdit*)GetDlgItem(IDC_EDIT29);//15
	pBox->GetWindowText(str);
	writting_helper(str,writting);

	pBox = (CEdit*)GetDlgItem(IDC_EDIT31);//16
	pBox->GetWindowText(str);
	writting_helper(str,writting);

	pBox = (CEdit*)GetDlgItem(IDC_EDIT33);//17
	pBox->GetWindowText(str);
	writting_helper(str,writting);

	pBox = (CEdit*)GetDlgItem(IDC_EDIT35);//18
	pBox->GetWindowText(str);
	writting_helper(str,writting);

	pBox = (CEdit*)GetDlgItem(IDC_EDIT37);//19
	pBox->GetWindowText(str);
	writting_helper(str,writting);

	pBox = (CEdit*)GetDlgItem(IDC_EDIT39);//20
	pBox->GetWindowText(str);
	writting_helper(str,writting);

	pBox = (CEdit*)GetDlgItem(IDC_EDIT41);//21
	pBox->GetWindowText(str);
	writting_helper(str,writting);

	pBox = (CEdit*)GetDlgItem(IDC_EDIT43);//22
	pBox->GetWindowText(str);
	writting_helper(str,writting);

	pBox = (CEdit*)GetDlgItem(IDC_EDIT45);//23
	pBox->GetWindowText(str);
	writting_helper(str,writting);

	pBox = (CEdit*)GetDlgItem(IDC_EDIT47);//24
	pBox->GetWindowText(str);
	writting_helper(str,writting);

	pBox = (CEdit*)GetDlgItem(IDC_EDIT49);//25
	pBox->GetWindowText(str);
	writting_helper(str,writting);

	pBox = (CEdit*)GetDlgItem(IDC_EDIT51);//26
	pBox->GetWindowText(str);
	writting_helper(str,writting);

	pBox = (CEdit*)GetDlgItem(IDC_EDIT53);//27
	pBox->GetWindowText(str);
	writting_helper(str,writting);

	pBox = (CEdit*)GetDlgItem(IDC_EDIT55);//28
	pBox->GetWindowText(str);
	writting_helper(str,writting);

	pBox = (CEdit*)GetDlgItem(IDC_EDIT57);//29
	pBox->GetWindowText(str);
	writting_helper(str,writting);

	pBox = (CEdit*)GetDlgItem(IDC_EDIT59);//30
	pBox->GetWindowText(str);
	writting_helper(str,writting);

	pBox = (CEdit*)GetDlgItem(IDC_EDIT61);//31
	pBox->GetWindowText(str);
	writting_helper(str,writting);

	pBox = (CEdit*)GetDlgItem(IDC_EDIT63);//32
	pBox->GetWindowText(str);
	writting_helper(str,writting);
}