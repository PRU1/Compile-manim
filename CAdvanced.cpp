// CAdvanced.cpp : implementation file
//

#include "pch.h"
#include "manimCompile2.h"
#include "CAdvanced.h"
#include "afxdialogex.h"
#include "resource.h"
#include "manimCompile2Dlg.h"
#include "CAboutDialog.h"
#include<iostream>
#include<fstream>
#include<string>
#include<chrono>
#include<ctime>
#include<thread>

// CAdvanced dialog

IMPLEMENT_DYNAMIC(CAdvanced, CDialogEx)
CAdvanced::CAdvanced(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_advanced, pParent)
{

}

CAdvanced::~CAdvanced()
{
}

void CAdvanced::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAdvanced, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CAdvanced::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CAdvanced::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE1, &CAdvanced::OnEnChangeMfceditbrowse1)
	ON_BN_CLICKED(IDOK, &CAdvanced::OnBnClickedOk)
END_MESSAGE_MAP()


// CAdvanced message handlers

std::string line2() {
	std::ifstream examplefile2("manimCompile2-manimPath.in");
	std::string temp;
	examplefile2.open("manimCompile2-manimPath.in");
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
	    examplefile.close();
	}
	return temp;
}
void CAdvanced::OnBnClickedButton1()
{
UpdateData(TRUE);
	CmanimCompile2Dlg manim_autopep;
	CString testing = manim_autopep.fileLine;
	std::string autopep_path(CW2A(manim_autopep.file_location.GetString(), CP_UTF8));
	std::string autopep = "/K TITLE autopepFormat & autopep8 -i " + autopep_path;
	UpdateData(TRUE);
		std::chrono::milliseconds dura(50);
		ShellExecute(NULL, _T("open"), _T("cmd.exe"), _T("/C taskkill /IM cmd.exe /FI \"WINDOWTITLE eq autopepFormat*\" "), NULL, SW_SHOWMINIMIZED); //Executes any open cmd
		std::this_thread::sleep_for(dura);
		ShellExecuteA(NULL, ("open"), ("cmd.exe"), LPCSTR(autopep.c_str()), LPCSTR(line2().c_str()), SW_SHOW); //Executes command
		//system("pause");
	// TODO: Add your control notification handler code here
}
void CAdvanced::OnBnClickedButton2()
{
	CAboutDialog open_about;
	open_about.DoModal();
	// TODO: Add your control notification handler code here
}

//void WriteToFile(CString& advanced_path) { //Passed as reference in case advance_path needs to be modified later
//	std::ofstream myfile;
//	std::string Manimpath(CW2A(advanced_path.GetString(), CP_UTF8));
//	myfile.open("manimCompile2-manimPath.in", std::fstream::app);
//	myfile << Manimpath;
//}
void CAdvanced::OnEnChangeMfceditbrowse1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CAdvanced::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
		ShellExecute(NULL, _T("open"), _T("cmd.exe"), _T("/C taskkill /IM cmd.exe /FI \"WINDOWTITLE eq autopepFormat*\" "), NULL, SW_SHOWMINIMIZED); //Executes any open cmd
	CDialogEx::OnOK();
}


void CAdvanced::OnEnChangeRichedit21()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
