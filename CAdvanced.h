#pragma once

#include "Resource.h"

// CAdvanced dialog

class CAdvanced : public CDialogEx
{
	DECLARE_DYNAMIC(CAdvanced)

public:
	CAdvanced(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAdvanced();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_advanced };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
    afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeMfceditbrowse1();
	afx_msg void OnBnClickedOk();
	// Edit the manim directory path through advanced
	CString advanced_path;
	afx_msg void OnEnChangeRichedit21();
	CMFCEditBrowseCtrl advanced_manimpath;
};
