
// Serial Port AssistantDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "mscomm1.h"


// CSerialPortAssistantDlg dialog
class CSerialPortAssistantDlg : public CDialogEx
{
// Construction
public:
	CSerialPortAssistantDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_SERIALPORTASSISTANT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_cmdType;
	afx_msg void OnBnClickedSend();
	afx_msg void OnBnClickedSend2();
	afx_msg void OnBnClickedSend3();
	afx_msg void OnBnClickedSend4();
	afx_msg void OnBnClickedSend5();
	afx_msg void OnBnClickedSend6();
	afx_msg void OnBnClickedSend7();
	afx_msg void OnBnClickedSend8();
	afx_msg void OnBnClickedSend9();
	afx_msg void OnBnClickedSend10();
	afx_msg void OnBnClickedSend11();
	afx_msg void OnBnClickedSend12();
	afx_msg void OnBnClickedSend13();
	afx_msg void OnBnClickedSend14();
	afx_msg void OnBnClickedSend15();
	afx_msg void OnBnClickedSend16();
	afx_msg void OnBnClickedSend17();
	afx_msg void OnBnClickedSend18();
	afx_msg void OnBnClickedSend19();
	afx_msg void OnBnClickedSend20();
	afx_msg void OnBnClickedSend21();
	afx_msg void OnBnClickedSend22();
	afx_msg void OnBnClickedSend23();
	afx_msg void OnBnClickedSend24();
	afx_msg void OnBnClickedSend25();
	afx_msg void OnBnClickedSend26();
	afx_msg void OnBnClickedSend27();
	afx_msg void OnBnClickedSend28();
	afx_msg void OnBnClickedSend29();
	afx_msg void OnBnClickedSend30();
	afx_msg void OnBnClickedSend31();
	afx_msg void OnBnClickedSend32();
	CString m_line1;
	CString m_crc1;
	CMscomm1 m_Com;
	DECLARE_EVENTSINK_MAP()
	void OnOncommMscomm1();
	bool bsend;
	//bool bReceive;
	int m_nPort;
	CComboBox m_ctrlRate;
	int m_RateMode;
	CString m_strReceive;
	afx_msg void OnBnClickedSettingButton();
	afx_msg void OnBnClickedClear();
	int String2Hex(CString str, CByteArray &senddata);
	unsigned char crcval;
	afx_msg void OnBnClickedButton1();
	bool CRCmode;
	CButton m_CRCcontrol;
	void sender(CString str, CString &crc_display);
	afx_msg void OnClose();
	CString m_direction;
	afx_msg void Reader(CString filename);
	afx_msg void Keeper(CString filename);
	void writting_helper(CString str,FILE* writting);
};
