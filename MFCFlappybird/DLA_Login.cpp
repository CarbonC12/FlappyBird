// DLA_Login.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCFlappybird.h"
#include "DLA_Login.h"
#include "afxdialogex.h"
#include "Check.h"


// DLA_Login 对话框

IMPLEMENT_DYNAMIC(DLA_Login, CDialogEx)

DLA_Login::DLA_Login(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIA_REGISTER, pParent)
	, LOGUsername(_T(""))
	, LOGPassword(_T(""))
	, LOGPassword2(_T(""))
{

}

DLA_Login::~DLA_Login()
{
}



void DLA_Login::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_LOGUSERNAME, LOGUsername);
	DDX_Text(pDX, IDC_EDIT_LOGPASSWORD, LOGPassword);
	DDX_Text(pDX, IDC_EDIT_LOGPASSWORD2, LOGPassword2);
}


BEGIN_MESSAGE_MAP(DLA_Login, CDialogEx)
	ON_BN_CLICKED(IDC_BUT_REGISTER, &DLA_Login::OnBnClickedButRegister)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// DLA_Login 消息处理程序


void DLA_Login::OnBnClickedButRegister()//注册信息
{
	UpdateData(true);
	bool IsAlready;
	CString Username;
	CString Password;
	if (LOGUsername.IsEmpty() || LOGPassword.IsEmpty()|| LOGPassword2.IsEmpty())
	{
		MessageBox(_T("账号或者密码不能为空!"), _T("警告！"), MB_ICONERROR);
		return;
	}
	else
	{
		if (LOGPassword != LOGPassword2)
		{
			MessageBox(_T("两次密码不一致"), _T("警告！"), MB_ICONERROR);
		}
		else
		{
			Check Log(LOGUsername, LOGPassword);
			IsAlready = Log.CheckRigth();
			if (IsAlready)
				MessageBox(_T("请勿重复注册"), _T("警告！"), MB_ICONERROR);
			else
			{
				Log.Login();
				if (!Log.Isrepeat)
				{
					MessageBox(_T("注册成功!"), _T("提示"));
					this->EndDialog(0);
				}
				else
					MessageBox(_T("该用户名重复"), _T("警告"), MB_ICONERROR);
			}
		}
	}
	// TODO: 在此添加控件通知处理程序代码
}

void DLA_Login::OnPaint()//添加背景图片
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC   dc(this);
		CRect   rect;
		GetClientRect(&rect);    //获取对话框长宽      
		CDC   dcBmp;             //定义并创建一个内存设备环境
		dcBmp.CreateCompatibleDC(&dc);             //创建兼容性DC
		CBitmap   bmpBackground;
		bmpBackground.LoadBitmap(IDB_BITMAP1);    //载入资源中图片
		BITMAP   m_bitmap;                         //图片变量               
		bmpBackground.GetBitmap(&m_bitmap);       //将图片载入位图中
												  //将位图选入临时内存设备环境
		CBitmap  *pbmpOld = dcBmp.SelectObject(&bmpBackground);
		//调用函数显示图片StretchBlt显示形状可变
		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0, m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);
	}
}
