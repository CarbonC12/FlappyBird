#pragma once
#include "BackGarundPic.h"
#include "Cbird.h"
#include "CPillar.h"
#include "CScore.h"
#include "Check.h"
#include <mmsystem.h>
#include "CHeart.h"
#include "DLA_HELPER.h"
#pragma comment( lib, "Winmm.lib" )

// DLA_GAME 对话框

class DLA_GAME : public CDialogEx
{
	DECLARE_DYNAMIC(DLA_GAME)

public:
	DLA_GAME(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DLA_GAME();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIA_GAME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
protected:
	int IsGameBegin = 0;
	int IsUserClick;
	int IsUserClickPic;
	CDC mem_Dc;
	CBitmap m_memBmp;
	HICON m_hIcon;
	int IsHit = 0;
	int IsHitHead = 0;
	int IsSound = 1;
	int m_VoiceTime = 0;
	int m_ReadScore = 0;
	int m_Rand1;
	int Game_Mode;//游戏模式选择
	int m_Rand2;
	int IsPillar_Up1;
	int IsPillar_Up2;
	int TimerRand;//让鸟动起来的参数
	int tmp_TimerRand;//让鸟动起来的参数2
	int RandD_or_N;//控制白天夜晚的参数
	int IsHeartOn;//控制心出现的概率
	int IsGameShunt;//游戏是否被暂停
	int IsGameShutTime;//参与管控是否被暂停
	int Life;//小鸟的生命
	int IsEat;//是否吃到了小心心
	int IsClickUse=0;//撞击是否有效
	int IsSkillQ;
	int IsSkillW;
	int IsSkillE;//检测技能是否使用
	int IsSkillWd;//检测是否无敌
	int tmp_TimerRand2;//光环动起来的参数
	int WriteTime;//控制写入数据次数
	int IsLevel_1;
	int IsLevel_2;
	int IsLevel_3;
	int IsLevel_4;
	int IsLevel_5;
	int IsLevel_6;//指示何时显示或者关闭关卡图片
	int IsLevel_1Use;
	int IsLevel_2Use;
	int IsLevel_3Use;
	int IsLevel_4Use;
	int IsLevel_5Use;
	int IsLevel_6Use;//指示显示或者关闭关卡图片的变量是否有效
	bool IsMouseQ;//指示鼠标是否悬停于Q技能
	bool IsMouseW;//指示鼠标是否悬停于W技能
	bool IsMouseE;//指示鼠标是否悬停于E技能
	CImage m_HaloPic[8];//载入光环图片
	CImage m_SoundOpen;//载入声音图片
	CImage m_SoundClose;//载入声音图片
	CImage m_Ok;//载入OK图片
	CImage m_NewRecord;//载入新纪录的NEW图片
	CImage m_Countinue;//载入继续图片
	CImage m_GameModePic[3];//载入游戏模式图片
	CImage m_Skill[3];//载入技能模式图片
	CImage m_SkillIntroduce[3];//载入技能介绍图片
	CImage m_LevelPic[6];//载入关卡图片
	CImage m_HelpPic;//载入帮助图片
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CBackGarundPic m_Backgraund;
	Cbird m_Bird;
	CPillar m_Pillar_1;
	CPillar m_Pillar_2;
	CScore m_Score;
	Check RW_Score;
	CHeart m_Heart;
	

	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
//	afx_msg void OnMouseHover(UINT nFlags, CPoint point);
//	afx_msg void OnNcMouseHover(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};
