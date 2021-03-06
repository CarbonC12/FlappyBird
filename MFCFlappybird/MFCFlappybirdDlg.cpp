
// MFCFlappybirdDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCFlappybird.h"
#include "MFCFlappybirdDlg.h"
#include "afxdialogex.h"
#include "Check.h"
#include "DLA_Login.h"
#include "DLA_GAME.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCFlappybirdDlg 对话框



CMFCFlappybirdDlg::CMFCFlappybirdDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCFLAPPYBIRD_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON_FlappyBird);
}

void CMFCFlappybirdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCFlappybirdDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUT_SEEPASSWORD, &CMFCFlappybirdDlg::OnBnClickedButSeepassword)
	ON_BN_CLICKED(IDC_BUT_LOGIN, &CMFCFlappybirdDlg::OnBnClickedButLogin)
	ON_BN_CLICKED(IDC_BUT_REGISTER, &CMFCFlappybirdDlg::OnBnClickedButRegister)
END_MESSAGE_MAP()


// CMFCFlappybirdDlg 消息处理程序

BOOL CMFCFlappybirdDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCFlappybirdDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCFlappybirdDlg::OnPaint()
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
	else//创建背景图片
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

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCFlappybirdDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCFlappybirdDlg::OnBnClickedButSeepassword()
{
	CString Password;
	GetDlgItemText(IDC_EDIT_PASSWORD, Password);
	MessageBox(Password,_T("Flappy Bird"),MB_OK);
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCFlappybirdDlg::OnBnClickedButLogin()
{
	CString PutinUsername;
	CString PutinPassword;
	bool IsRight;
	bool Isthere;
	GetDlgItemText(IDC_EDIT_USERNAME, PutinUsername);
	GetDlgItemText(IDC_EDIT_PASSWORD, PutinPassword);
	if (PutinUsername.IsEmpty() || PutinPassword.IsEmpty())
	{
		MessageBox(_T("          登录失败！\n账号或者密码不能为空!"), _T("警告！"), MB_ICONERROR);
		return;
	}
	else
	{
		Check IsLogin(PutinUsername, PutinPassword);
		IsRight = IsLogin.CheckRigth();
		Isthere = IsLogin.IsNothing;
	}
	if (!Isthere)
	{
		if (IsRight)
		{
			//MessageBox(_T("登录成功！"));
			DLA_GAME Dlg;
			this->EndDialog(0);
			Dlg.DoModal();
		}
		else
			MessageBox(_T("用户名或者密码错误"),_T("警告！"), MB_ICONERROR);
	}
	else
		MessageBox(_T("请先注册!"), _T("警告！"), MB_ICONERROR);
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCFlappybirdDlg::OnBnClickedButRegister()
{
	DLA_Login Dlg;
	Dlg.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}
