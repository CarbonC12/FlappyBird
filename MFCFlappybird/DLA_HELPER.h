#pragma once


// DLA_HELPER 对话框

class DLA_HELPER : public CDialogEx
{
	DECLARE_DYNAMIC(DLA_HELPER)

public:
	DLA_HELPER(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DLA_HELPER();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIA_HELLPER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
