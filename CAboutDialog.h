#pragma once


// CAboutDialog dialog

class CAboutDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CAboutDialog)

public:
	CAboutDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAboutDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
