
// manimCompile2Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "manimCompile2.h"
#include "manimCompile2Dlg.h"
#include "afxdialogex.h"
#include "CAdvanced.h"
#include "resource.h"
#include<iostream>
#include<cstring>
#include<string>
#include<chrono>
#include<thread>
#include<fstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtonrender();
	CString Help_edit_browse_control;
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
, Help_edit_browse_control(_T("Pick the file to be compiled"))
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MFCEDITBROWSE1, Help_edit_browse_control);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CAboutDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_render, &CAboutDlg::OnBnClickedButtonrender)
END_MESSAGE_MAP()


// CmanimCompile2Dlg dialog



CmanimCompile2Dlg::CmanimCompile2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MANIMCOMPILE2_DIALOG, pParent)
	, file_location(_T("Enter file location"))
	, render_speed{}
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmanimCompile2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MFCEDITBROWSE1, file_location);
	DDX_Radio(pDX, IDC_RADIO_slow, render_speed);

}

BEGIN_MESSAGE_MAP(CmanimCompile2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_advanced, &CmanimCompile2Dlg::OnBnClickedButtonadvanced)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE1, &CmanimCompile2Dlg::OnEnChangeMfceditbrowse1)
	ON_BN_CLICKED(IDC_RADIO_slow, &CmanimCompile2Dlg::OnBnClickedRadioslow)
	ON_BN_CLICKED(IDC_BUTTON_render, &CmanimCompile2Dlg::OnBnClickedButtonrender)
	ON_BN_CLICKED(IDOK, &CmanimCompile2Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CmanimCompile2Dlg::OnBnClickedButton1)

END_MESSAGE_MAP()


// CmanimCompile2Dlg message handlers

BOOL CmanimCompile2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CmanimCompile2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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
void ReadFile(CString& strLine, std::string& line) //Read file
{
	CStdioFile readFile;
	CFileException fileException;
	CString strFilePath = _T("C:\\Users\\pranav\\testing.in");
	CString testing58;

	if (readFile.Open(strFilePath, CFile::modeRead, &fileException))
	{
		while (readFile.ReadString(strLine));

	}
	else
	{
		CString strErrorMsg;
		strErrorMsg.Format(_T("Can't open file %s , error : %u"), strFilePath, fileException.m_cause);
		AfxMessageBox(strErrorMsg);
	}
	line = (CW2A(strLine.GetString(), CP_UTF8));
	readFile.Close();
}
std::string line() {
	std::ifstream examplefile2("manimCompile2-manimPath.in");
	std::string temp;
	//examplefile2.open("manimCompile2-manimPath.in");
	if (examplefile2) {
		//(Just in case)
			if (!examplefile2.is_open())
			{
				std::cout << "File does not exist. Please try cloning this repository again.";
				ShellExecute(NULL, _T("open"), _T("cmd.exe"), NULL, NULL, NULL);
			}
		while (!examplefile2.eof())
		{
			examplefile2 >> temp;

		}
		examplefile2.close();
	}
	else {
		std::ofstream examplefile;
		examplefile.open("manimCompile2-manimPath.in", std::fstream::app);
			ShellExecute(NULL, _T("open"), _T("cmd.exe"), NULL, NULL, NULL);
		examplefile.close();
	}
	return temp;
}

void CmanimCompile2Dlg::OnPaint()
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
HCURSOR CmanimCompile2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CmanimCompile2Dlg::OnBnClickedButtonadvanced()
{
	UpdateData(TRUE);
	std::string autopep_path(CW2A(file_location.GetString(), CP_UTF8));
	std::string autopep = "/K TITLE autopepFormat & autopep8 -i " + autopep_path + "& echo.Formatting code complete complete";
	UpdateData(TRUE);
	std::chrono::milliseconds dura(50);
	ShellExecute(NULL, _T("open"), _T("cmd.exe"), _T("/C taskkill /IM cmd.exe /FI \"WINDOWTITLE eq autopepFormat*\" "), NULL, SW_SHOWMINIMIZED); //Executes any open cmd
	std::this_thread::sleep_for(dura);
	ShellExecuteA(NULL, ("open"), ("cmd.exe"), LPCSTR(autopep.c_str()), LPCSTR(line().c_str()), SW_SHOW); //Executes command
	//system("pause");
// TODO: Add your control notification handler code here
}
void CmanimCompile2Dlg::OnEnChangeMfceditbrowse1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CmanimCompile2Dlg::OnBnClickedRadioslow()
{
	// TODO: Add your control notification handler code here
}


void CmanimCompile2Dlg::OnBnClickedButtonrender()
{
	int render_btn_count{};
	std::string path(CW2A(file_location.GetString(), CP_UTF8));
	std::string slow_render = "/K TITLE manimCompile & python -m manim " + path + " -p";
	std::string faster_render = "/K TITLE manimCompile & python -m manim " + path + " -pm";
	std::string fast_render = "/K TITLE manimCompile & python -m manim " + path + " -pl";
	UpdateData(TRUE);
	//if (render_btn_count == 1) {
	//	switch (render_speed) {
	//	case 0:
	//		ShellExecute(NULL, _T("open"), _T("cmd.exe"), _T("/K taskkill /IM cmd.exe /FI \"WINDOWTITLE eq manimCompile*\" "), NULL, SW_SHOWMINIMIZED); //Executes any open cmd
	//		system("PAUSE"); //Stops next command from exiting
	//		ShellExecuteA(NULL, ("open"), ("cmd.exe"), LPCSTR(slow_render.c_str()), ("C:\\Users\\pranav\\manim"), SW_SHOW); //Executes command
	//		break;
	//	case 1:
	//		ShellExecute(NULL, _T("open"), _T("cmd.exe"), _T("/K taskkill /IM cmd.exe"), NULL, SW_SHOWMINIMIZED);
	//		system("PAUSE");
	//		ShellExecuteA(NULL, ("open"), ("cmd.exe"), LPCSTR(fast_render.c_str()), ("C:\\Users\\pranav\\manim"), SW_SHOW);
	//		break;
	//	}
	//}
	//else {
	//	switch (render_speed) {
	//	case 0:
	//		ShellExecuteA(NULL, ("open"), ("cmd.exe"), LPCSTR(slow_render.c_str()), ("C:\\Users\\pranav\\manim"), SW_SHOW); //Executes command
	//		break;
	//	case 1:
	//		ShellExecuteA(NULL, ("open"), ("cmd.exe"), LPCSTR(fast_render.c_str()), ("C:\\Users\\pranav\\manim"), SW_SHOW);
	//		break;
	//	}
	//}
		std::chrono::milliseconds dura(50);
	switch (render_speed) {
	case 0:
		ShellExecute(NULL, _T("open"), _T("cmd.exe"), _T("/C taskkill /IM cmd.exe /FI \"WINDOWTITLE eq manimCompile*\" "), NULL, SW_SHOWMINIMIZED); //Executes any open cmd
		std::this_thread::sleep_for(dura);
		ShellExecuteA(NULL, ("open"), ("cmd.exe"), LPCSTR(slow_render.c_str()), LPCSTR(line().c_str()), SW_SHOW); //Executes command
		break;
	case 1:
		ShellExecute(NULL, _T("open"), _T("cmd.exe"), _T("/C taskkill /IM cmd.exe /FI \"WINDOWTITLE eq manimCompile*\" "), NULL, SW_SHOWMINIMIZED); //Executes any open cmd
		std::this_thread::sleep_for(dura);
		ShellExecuteA(NULL, ("open"), ("cmd.exe"), LPCSTR(faster_render.c_str()), LPCSTR(line().c_str()), SW_SHOW);
		break;

	case 2:
		ShellExecute(NULL, _T("open"), _T("cmd.exe"), _T("/C taskkill /IM cmd.exe /FI \"WINDOWTITLE eq manimCompile*\" "), NULL, SW_SHOWMINIMIZED); //Executes any open cmd
		std::this_thread::sleep_for(dura);
		ShellExecuteA(NULL, ("open"), ("cmd.exe"), LPCSTR(fast_render.c_str()), LPCSTR(line().c_str()), SW_SHOW);
		break;
	}
}


void CmanimCompile2Dlg::OnBnClickedOk()
{
	ShellExecute(NULL, _T("open"), _T("cmd.exe"), _T("/C taskkill /IM cmd.exe /FI \"WINDOWTITLE eq manimCompile*\" "), NULL, SW_SHOWMINIMIZED); //Executes any open cmd
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void CmanimCompile2Dlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	std::chrono::milliseconds dura(50);
	CAdvanced pathForManim;
	std::string path(CW2A(file_location.GetString(), CP_UTF8));
	std::string last_frame= "/K TITLE manimCompile & python -m manim " + path + " -ps";
    ShellExecute(NULL, _T("open"), _T("cmd.exe"), _T("/C taskkill /IM cmd.exe /FI \"WINDOWTITLE eq manimCompile*\" "), NULL, SW_SHOWMINIMIZED); //Executes any open cmd
		std::this_thread::sleep_for(dura);
	ShellExecuteA(NULL, ("open"), ("cmd.exe"), LPCSTR(last_frame.c_str()), LPCSTR(line().c_str()), SW_SHOW);
	// TODO: Add your control notification handler code here
}


void CAboutDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
}


void CAboutDlg::OnBnClickedButtonrender()
{
	// TODO: Add your control notification handler code here
}
