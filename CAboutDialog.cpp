// CAboutDialog.cpp : implementation file
//

#include "pch.h"
#include "manimCompile2.h"
#include "CAboutDialog.h"
#include "afxdialogex.h"


// CAboutDialog dialog

IMPLEMENT_DYNAMIC(CAboutDialog, CDialogEx)

CAboutDialog::CAboutDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ABOUTBOX, pParent)
{

}

CAboutDialog::~CAboutDialog()
{
}

void CAboutDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAboutDialog, CDialogEx)
END_MESSAGE_MAP()


// CAboutDialog message handlers
