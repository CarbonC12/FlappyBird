// DLA_HELPER.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCFlappybird.h"
#include "DLA_HELPER.h"
#include "afxdialogex.h"


// DLA_HELPER 对话框

IMPLEMENT_DYNAMIC(DLA_HELPER, CDialogEx)

DLA_HELPER::DLA_HELPER(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIA_HELLPER, pParent)
{

}

DLA_HELPER::~DLA_HELPER()
{
}

void DLA_HELPER::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DLA_HELPER, CDialogEx)
END_MESSAGE_MAP()


// DLA_HELPER 消息处理程序
