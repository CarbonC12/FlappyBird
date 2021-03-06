#pragma once


// DLA_Login 对话框

class DLA_Login : public CDialogEx
{
	DECLARE_DYNAMIC(DLA_Login)

public:
	DLA_Login(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DLA_Login();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIA_REGISTER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButRegister();
	HICON m_hIcon;
	// 输入的用户名
	CString LOGUsername;
	// 第一次输入的注册密码
	CString LOGPassword;
	// 第二次输入的注册密码
	CString LOGPassword2;
	afx_msg void OnPaint();
};
