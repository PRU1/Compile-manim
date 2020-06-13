
// manimCompile2Dlg.h : header file
//

#pragma once
#include<iostream>

// CmanimCompile2Dlg dialog
class CmanimCompile2Dlg : public CDialogEx
{
// Construction
public:
	CmanimCompile2Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MANIMCOMPILE2_DIALOG };
#endif

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
    afx_msg void OnBnClickedButtonadvanced();
    afx_msg void OnEnChangeMfceditbrowse1();
    CString file_location;
	afx_msg void OnBnClickedRadioslow();
	int render_speed;
	afx_msg void OnBnClickedButtonrender();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	CString& fileLine{ file_location };
};
