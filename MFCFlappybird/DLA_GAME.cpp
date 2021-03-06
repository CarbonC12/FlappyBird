// DLA_GAME.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCFlappybird.h"
#include "DLA_GAME.h"
#include "afxdialogex.h"
#include "BackGarundPic.h"
#include "Cbird.h"
#include "windows.h"
#include "Check.h"
#include "DLA_HELPER.h"


// DLA_GAME 对话框

IMPLEMENT_DYNAMIC(DLA_GAME, CDialogEx)

DLA_GAME::DLA_GAME(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIA_GAME, pParent)
{
	CBackGarundPic m_Backgraund;
	Cbird m_Bird;

}

DLA_GAME::~DLA_GAME()
{
}

void DLA_GAME::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DLA_GAME, CDialogEx)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_CREATE()
	ON_WM_ERASEBKGND()
	ON_WM_KEYDOWN()
//	ON_WM_MOUSEHOVER()
//ON_WM_NCMOUSEHOVER()
ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// DLA_GAME 消息处理程序


BOOL DLA_GAME::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	TimerRand = 0;
	IsUserClickPic = 0;
	//IsClickUse = 0;
	RandD_or_N = rand() % 2;
	Life = 1;
	WriteTime = 0;
	IsLevel_1Use = 0;
	IsLevel_2Use = 0;
	IsLevel_3Use = 0;
	IsLevel_4Use = 0;
	IsLevel_5Use = 0;
	IsLevel_6Use = 0;//指示显示或者关闭关卡图片的变量是否有效
	m_Pillar_1.set_Px(900);
	m_Pillar_2.set_Px(400);
	SetTimer(1, 20, NULL);//控制绘图刷新以及碰撞检测
	SetTimer(3, 20, NULL);//控制分数检测
	SetTimer(4, 20, NULL);//控制游戏暂停与否
	SetTimer(7, 20, NULL);//单独控制图片刷新
	m_SoundOpen.Load(_T("res\\sound.png"));
	m_SoundClose.Load(_T("res\\soundclose.png"));
	m_Ok.Load(_T("res\\button_ok.png"));
	m_NewRecord.Load(_T("res\\new.png"));
	m_Countinue.Load(_T("res\\button_play.bmp"));
	m_GameModePic[0].Load(_T("res\\GameMode1.png"));
	m_GameModePic[1].Load(_T("res\\GameMode2.png"));
	m_GameModePic[2].Load(_T("res\\GameMode3.png"));
	m_Skill[0].Load(_T("res\\skill_Q.jpg"));
	m_Skill[1].Load(_T("res\\skill_W.jpg"));
	m_Skill[2].Load(_T("res\\skill_E.jpg"));
	m_HaloPic[0].Load(_T("res\\Halo_1.png"));
	m_HaloPic[1].Load(_T("res\\Halo_2.png"));
	m_HaloPic[2].Load(_T("res\\Halo_3.png"));
	m_HaloPic[3].Load(_T("res\\Halo_4.png"));
	m_HaloPic[4].Load(_T("res\\Halo_5.png"));
	m_HaloPic[5].Load(_T("res\\Halo_6.png"));
	m_HaloPic[6].Load(_T("res\\Halo_7.png"));
	m_HaloPic[7].Load(_T("res\\Halo_8.png"));
	m_SkillIntroduce[0].Load(_T("res\\SkillIntro_Q.jpg"));
	m_SkillIntroduce[1].Load(_T("res\\Skillntro_W.jpg"));
	m_SkillIntroduce[2].Load(_T("res\\SkillIntro_E.jpg"));
	m_LevelPic[0].Load(_T("res\\Level_1.png"));
	m_LevelPic[1].Load(_T("res\\Level_2.png"));
	m_LevelPic[2].Load(_T("res\\Level_3.png"));
	m_LevelPic[3].Load(_T("res\\Level_4.png"));
	m_LevelPic[4].Load(_T("res\\Level_5.png"));
	m_LevelPic[5].Load(_T("res\\Level_6.png"));
	m_HelpPic.Load(_T("res\\Help.png"));
	//创建图标
	HICON icon;
	//加载图标
	icon = AfxGetApp()->LoadIcon(IDI_ICON_FlappyBird);
	SetIcon(icon, true);
	SetIcon(icon, false);

	//加载任务栏图标
	ModifyStyleEx(0, WS_EX_APPWINDOW);
	ShowWindow(SW_SHOW);
	// TODO:  在此添加额外的初始化
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void DLA_GAME::OnPaint()
{

		CPaintDC dc(this);
		//CDC mem_Dc;
		CRect Backwindow;
		CBitmap*OldBmp = NULL;
		GetClientRect(&Backwindow);
		mem_Dc.CreateCompatibleDC(&dc);
		//CBitmap m_memBmp;
		m_memBmp.CreateCompatibleBitmap(&dc, Backwindow.Width(), Backwindow.Height());
		OldBmp = mem_Dc.SelectObject(&m_memBmp);
		if (IsGameBegin == 0)
		{
			m_Backgraund.get_Bckimage(0).BitBlt(mem_Dc, 0, 0, Backwindow.Width(), Backwindow.Height(), 0, 0, SRCCOPY);//将游戏背景图片绘制到内存
			m_Bird.Get_MImage(tmp_TimerRand).Draw(mem_Dc, 35, 370, 96, 96);
			if (IsSound == 1)
				m_SoundOpen.Draw(mem_Dc, 780, 30, 50, 50);
			else
				m_SoundClose.Draw(mem_Dc, 780, 30, 50, 50);
			m_GameModePic[0].Draw(mem_Dc, -10, 700, 365, 80);
			m_GameModePic[1].Draw(mem_Dc, 275, 700, 365, 80);
			m_GameModePic[2].Draw(mem_Dc, 560, 700, 365, 80);
			m_Backgraund.get_landimage().BitBlt(mem_Dc, m_Backgraund.get_landx(), 800, Backwindow.Width(), Backwindow.Height(), 0, 0, SRCCOPY);//将地板图片绘制到内存
			m_Backgraund.get_landimage().BitBlt(mem_Dc, m_Backgraund.get_landx() + 310, 800, Backwindow.Width(), Backwindow.Height(), 0, 0, SRCCOPY);//将地板图片绘制到内存
			m_Backgraund.get_landimage().BitBlt(mem_Dc, m_Backgraund.get_landx() + 620, 800, Backwindow.Width(), Backwindow.Height(), 0, 0, SRCCOPY);//将地板图片绘制到内存
			m_HelpPic.Draw(mem_Dc, 20, 20, 50, 50);


		}
		else
		{
			m_Backgraund.get_Bckimage(RandD_or_N + 1).BitBlt(mem_Dc, 0, 0, Backwindow.Width(), Backwindow.Height(), 0, 0, SRCCOPY);//将游戏背景图片绘制到内存
			if (RandD_or_N == 0)
			{
				m_Pillar_1.get_pillarPicDay(0).BitBlt(mem_Dc, m_Pillar_1.Get_Px(), m_Pillar_1.Get_Py(), Backwindow.Width(), Backwindow.Height(), 0, 0, SRCCOPY);//绘制柱子
				m_Pillar_1.get_pillarPicDay(1).BitBlt(mem_Dc, m_Pillar_1.Get_Px(), 630 - m_Rand1 + m_Pillar_1.Get_Py(), Backwindow.Width(), Backwindow.Height(), 0, 0, SRCCOPY);
				m_Pillar_2.get_pillarPicDay(0).BitBlt(mem_Dc, m_Pillar_2.Get_Px(), m_Pillar_2.Get_Py(), Backwindow.Width(), Backwindow.Height(), 0, 0, SRCCOPY);
				m_Pillar_2.get_pillarPicDay(1).BitBlt(mem_Dc, m_Pillar_2.Get_Px(), 630 - m_Rand2 + m_Pillar_2.Get_Py(), Backwindow.Width(), Backwindow.Height(), 0, 0, SRCCOPY);
			}
			else
			{
				m_Pillar_1.get_pillarPicNight(0).BitBlt(mem_Dc, m_Pillar_1.Get_Px(), m_Pillar_1.Get_Py(), Backwindow.Width(), Backwindow.Height(), 0, 0, SRCCOPY);//绘制柱子
				m_Pillar_1.get_pillarPicNight(1).BitBlt(mem_Dc, m_Pillar_1.Get_Px(), 630 - m_Rand1 + m_Pillar_1.Get_Py(), Backwindow.Width(), Backwindow.Height(), 0, 0, SRCCOPY);
				m_Pillar_2.get_pillarPicNight(0).BitBlt(mem_Dc, m_Pillar_2.Get_Px(), m_Pillar_2.Get_Py(), Backwindow.Width(), Backwindow.Height(), 0, 0, SRCCOPY);
				m_Pillar_2.get_pillarPicNight(1).BitBlt(mem_Dc, m_Pillar_2.Get_Px(), 630 - m_Rand2 + m_Pillar_2.Get_Py(), Backwindow.Width(), Backwindow.Height(), 0, 0, SRCCOPY);
			}
			//绘制声音图标
			if (IsSound == 1)
				m_SoundOpen.Draw(mem_Dc, 780, 30, 50, 50);
			else
				m_SoundClose.Draw(mem_Dc, 780, 30, 50, 50);
			if ((Game_Mode == 3 || Game_Mode == 2))
			{
				m_Heart.Get_BHeartImage(Life).Draw(mem_Dc, 94, 40, 33, 30);
				m_Heart.Get_BHeartImage(Life - 1).Draw(mem_Dc, 54, 40, 33, 30);
				m_Heart.Get_BHeartImage(Life - 2).Draw(mem_Dc, 14, 40, 33, 30);

			}//绘制小鸟生命值

			if (Game_Mode == 2)
			{
				if (IsSkillQ == 0)
					m_Skill[0].Draw(mem_Dc, 620, 80, 63, 63);
				if (IsSkillW == 0)
					m_Skill[1].Draw(mem_Dc, 700, 80, 63, 63);
				if (IsSkillE == 0)
					m_Skill[2].Draw(mem_Dc, 780, 80, 63, 63);
			}
			//绘制技能图标
			if (IsSkillWd == 1 && Game_Mode == 2)
				m_HaloPic[tmp_TimerRand2].Draw(mem_Dc, m_Bird.Get_Px() - 12, m_Bird.Get_Py() - 12, 90, 90);
			//绘制光环
			m_Bird.get_Image(IsUserClickPic, tmp_TimerRand).Draw(mem_Dc, m_Bird.Get_Px(), m_Bird.Get_Py(), 70, 70);//Draw Bird


			m_Backgraund.get_landimage().BitBlt(mem_Dc, m_Backgraund.get_landx(), 800, Backwindow.Width(), Backwindow.Height(), 0, 0, SRCCOPY);//将地板图片绘制到内存
			m_Backgraund.get_landimage().BitBlt(mem_Dc, m_Backgraund.get_landx() + 310, 800, Backwindow.Width(), Backwindow.Height(), 0, 0, SRCCOPY);//将地板图片绘制到内存
			m_Backgraund.get_landimage().BitBlt(mem_Dc, m_Backgraund.get_landx() + 620, 800, Backwindow.Width(), Backwindow.Height(), 0, 0, SRCCOPY);//将地板图片绘制到内存

			if (IsHit == 0 && (Game_Mode == 3 || Game_Mode == 2))
				m_Heart.Get_HeartImage().Draw(mem_Dc, m_Heart.Get_Px(), m_Heart.Get_Py(), 33, 30);//绘制小心心

			m_Score.getImage(m_Score.get_score() % 10).Draw(mem_Dc, 94, 100, 30, 55);//分数绘制
			if (m_Score.get_score() >= 10 && m_Score.get_score() <= 99)
				m_Score.getImage((m_Score.get_score() - (m_Score.get_score() % 10)) / 10).Draw(mem_Dc, 62, 100, 30, 55);
			if (m_Score.get_score() >= 100 && m_Score.get_score() <= 999)
			{
				m_Score.getImage((m_Score.get_score() / 10) % 10).Draw(mem_Dc, 62, 100, 30, 55);
				m_Score.getImage(m_Score.get_score() / 100).Draw(mem_Dc, 30, 100, 30, 55);
			}


			if (IsGameShunt == 1)//游戏暂停画面
				m_Countinue.Draw(mem_Dc, 320, 345, 232, 140);

			if (IsHit == 1)//游戏结束界面
			{
				m_Backgraund.getGameOverimage().Draw(mem_Dc, 325, 150, 200, 60);
				m_Score.getpanel().Draw(mem_Dc, 185, m_Score.get_Py(), 476, 252);

				m_Score.getImage(m_Score.get_score() % 10).Draw(mem_Dc, 579, 315, 30, 55);
				if (m_Score.get_score() >= 10 && m_Score.get_score() <= 99)
					m_Score.getImage((m_Score.get_score() - (m_Score.get_score() % 10)) / 10).Draw(mem_Dc, 545, 315, 30, 55);
				if (m_Score.get_score() >= 100 && m_Score.get_score() <= 999)
				{
					m_Score.getImage((m_Score.get_score() / 10) % 10).Draw(mem_Dc, 545, 315, 30, 55);
					m_Score.getImage(m_Score.get_score() / 100).Draw(mem_Dc, 513, 315, 30, 55);
				}

				m_Ok.Draw(mem_Dc, 345, 515, 160, 56);
				if (WriteTime == 0)
				{
					RW_Score.WriteScore(m_Score.get_score());
					WriteTime++;
				}
				m_ReadScore = RW_Score.GetScore();
				m_Score.getImage(m_ReadScore % 10).Draw(mem_Dc, 579, 415, 30, 55);
				if (m_ReadScore >= 10 && m_ReadScore <= 99)
					m_Score.getImage((m_ReadScore - (m_ReadScore % 10)) / 10).Draw(mem_Dc, 545, 415, 30, 55);
				if (m_ReadScore >= 100 && m_ReadScore <= 999)
				{
					m_Score.getImage((m_ReadScore / 10) % 10).Draw(mem_Dc, 545, 415, 30, 55);
					m_Score.getImage(m_ReadScore / 100).Draw(mem_Dc, 513, 415, 30, 55);
				}
				if (m_ReadScore <= m_Score.get_score())
				{
					m_NewRecord.Draw(mem_Dc, 570, 260, 64, 28);
					m_Score.getmedal(1).Draw(mem_Dc, 248, 338, 88, 88);
				}
				else if ((m_ReadScore - 6) <= m_Score.get_score())
					m_Score.getmedal(0).Draw(mem_Dc, 248, 338, 88, 88);
				else if ((m_ReadScore - 6) >= m_Score.get_score())
					m_Score.getmedal(2).Draw(mem_Dc, 248, 338, 88, 88);

			}
			//指示创建关卡图片
			if (IsLevel_1 == 1)
			{
				m_LevelPic[0].Draw(mem_Dc, 280, 240, 320, 320);
				Sleep(300);
			}
			else if (IsLevel_2 == 1)
				m_LevelPic[1].Draw(mem_Dc, 280, 240, 320, 320);
			else if (IsLevel_3 == 1)
				m_LevelPic[2].Draw(mem_Dc, 280, 240, 320, 320);
			else if (IsLevel_4 == 1)
				m_LevelPic[3].Draw(mem_Dc, 280, 240, 320, 320);
			else if (IsLevel_5 == 1)
				m_LevelPic[4].Draw(mem_Dc, 280, 240, 320, 320);
			else if (IsLevel_6 == 1)
				m_LevelPic[5].Draw(mem_Dc, 280, 240, 320, 320);

			//绘制技能介绍
			if (IsMouseQ&&Game_Mode == 2)
				m_SkillIntroduce[0].Draw(mem_Dc, 10, 160, 676, 276);
			else if (IsMouseW&&Game_Mode == 2)
				m_SkillIntroduce[1].Draw(mem_Dc, 90, 160, 676, 276);
			else if (IsMouseE&&Game_Mode == 2)
				m_SkillIntroduce[2].Draw(mem_Dc, 170, 160, 676, 276);





		}
		dc.BitBlt(0, 0, Backwindow.Width(), Backwindow.Height(), &mem_Dc, 0, 0, SRCCOPY);//将内存的图片绘制到显示器
		mem_Dc.SelectObject(OldBmp);
		mem_Dc.DeleteDC();			//删除创建的内存DC
		m_memBmp.DeleteObject();	//删除创建的内存兼容位图
		CDialogEx::OnPaint();
}


void DLA_GAME::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nIDEvent)
	{
	case 1://绘图重置
	{
		if (IsGameBegin == 1)
		{
			TimerRand++;
			tmp_TimerRand = TimerRand % 3;
			tmp_TimerRand2 = TimerRand % 8;//创建动起来的随机数
			if (IsHit == 0)
				m_Bird.Set_BVy(IsUserClick);
			if (IsHit == 0)
				m_Bird.Set_Py();
			else
				if (IsHitHead == 0)
					m_Bird.Set_Die_Py();

			IsUserClick = 0;
			if (IsHit == 0)//绘制心
			{
				IsHeartOn = rand() % 1000;
				m_Heart.Set_HVy(4);
				m_Heart.Set_Py();
				m_Heart.Set_Px(IsHeartOn, Life);
				m_Heart.Is_Eat(IsEat);
			}
			if (IsHit == 0 && IsHitHead == 0)//绘制地板和柱子
			{
				m_Pillar_1.change_Px();
				m_Pillar_1.set_Py();
				m_Rand1 = m_Pillar_1.m_PillarRand;
				m_Pillar_2.change_Px();
				m_Pillar_2.set_Py();
				m_Rand2 = m_Pillar_2.m_PillarRand;
				m_Backgraund.change_landx();//使地板移动
				if (m_Score.get_score() >= 20)
				{
					if (IsLevel_2Use == 0)
					{
						IsLevel_2 = 1;
						IsLevel_2Use++;
						SetTimer(12, 300, NULL);//控制关卡图片刷新
					}
					if (m_Pillar_1.Get_Py() < -350)
						IsPillar_Up1 = 0;
					if (m_Pillar_1.Get_Py() > -80)
						IsPillar_Up1 = 1;
					if (m_Pillar_2.Get_Py() < -350)
						IsPillar_Up2 = 0;
					if (m_Pillar_2.Get_Py() > -80)
						IsPillar_Up2 = 1;
					if (IsPillar_Up1 == 0)
					{
						m_Pillar_1.pillar_down(1.5);
					}
					else
					{
						m_Pillar_1.pillar_up(1.5);
					}
					if (IsPillar_Up2 == 0)
					{
						m_Pillar_2.pillar_down(1.5);
					}
					else
					{
						m_Pillar_2.pillar_up(1.5);
					}
				}
				if (m_Score.get_score() >= 60)
				{
					if (IsLevel_3Use == 0)
					{
						IsLevel_3 = 1;
						IsLevel_3Use++;
						SetTimer(12, 300, NULL);//控制关卡图片刷新
					}
					if (m_Pillar_1.Get_Py() < -350)
						IsPillar_Up1 = 0;
					if (m_Pillar_1.Get_Py() > -80)
						IsPillar_Up1 = 1;
					if (m_Pillar_2.Get_Py() < -350)
						IsPillar_Up2 = 0;
					if (m_Pillar_2.Get_Py() > -80)
						IsPillar_Up2 = 1;
					if (IsPillar_Up1 == 0)
					{
						m_Pillar_1.pillar_down(2);
					}
					else
					{
						m_Pillar_1.pillar_up(2);
					}
					if (IsPillar_Up2 == 0)
					{
						m_Pillar_2.pillar_down(2);
					}
					else
					{
						m_Pillar_2.pillar_up(2);
					}
				}
				if (m_Score.get_score() >= 100)
				{
					if (IsLevel_4Use == 0)
					{
						IsLevel_4 = 1;
						IsLevel_4Use++;
						SetTimer(12, 300, NULL);//控制关卡图片刷新
					}
					if (m_Pillar_1.Get_Py() < -350)
						IsPillar_Up1 = 0;
					if (m_Pillar_1.Get_Py() > -80)
						IsPillar_Up1 = 1;
					if (m_Pillar_2.Get_Py() < -350)
						IsPillar_Up2 = 0;
					if (m_Pillar_2.Get_Py() > -80)
						IsPillar_Up2 = 1;
					if (IsPillar_Up1 == 0)
					{
						m_Pillar_1.pillar_down(2.5);
					}
					else
					{
						m_Pillar_1.pillar_up(2.5);
					}
					if (IsPillar_Up2 == 0)
					{
						m_Pillar_2.pillar_down(2.5);
					}
					else
					{
						m_Pillar_2.pillar_up(2.5);
					}
				}
				if (m_Score.get_score() >= 150)
				{
					if (IsLevel_5Use == 0)
					{
						IsLevel_5 = 1;
						IsLevel_5Use++;
						SetTimer(12, 300, NULL);//控制关卡图片刷新
					}
					if (m_Pillar_1.Get_Py() < -350)
						IsPillar_Up1 = 0;
					if (m_Pillar_1.Get_Py() > -80)
						IsPillar_Up1 = 1;
					if (m_Pillar_2.Get_Py() < -350)
						IsPillar_Up2 = 0;
					if (m_Pillar_2.Get_Py() > -80)
						IsPillar_Up2 = 1;
					if (IsPillar_Up1 == 0)
					{
						m_Pillar_1.pillar_down(3);
					}
					else
					{
						m_Pillar_1.pillar_up(3);
					}
					if (IsPillar_Up2 == 0)
					{
						m_Pillar_2.pillar_down(3);
					}
					else
					{
						m_Pillar_2.pillar_up(3);
					}
				}
				if (m_Score.get_score() >= 250)
				{
					if (IsLevel_6Use == 0)
					{
						IsLevel_6 = 1;
						IsLevel_6Use++;
						SetTimer(12, 300, NULL);//控制关卡图片刷新
					}
					if (m_Pillar_1.Get_Py() < -350)
						IsPillar_Up1 = 0;
					if (m_Pillar_1.Get_Py() > -80)
						IsPillar_Up1 = 1;
					if (m_Pillar_2.Get_Py() < -350)
						IsPillar_Up2 = 0;
					if (m_Pillar_2.Get_Py() > -80)
						IsPillar_Up2 = 1;
					if (IsPillar_Up1 == 0)
					{
						m_Pillar_1.pillar_down(3.5);
					}
					else
					{
						m_Pillar_1.pillar_up(3.5);
					}
					if (IsPillar_Up2 == 0)
					{
						m_Pillar_2.pillar_down(3.5);
					}
					else
					{
						m_Pillar_2.pillar_up(3.5);
					}
				}
				if (m_Score.get_score() >= 990)
				{
					if (m_Pillar_1.Get_Py() < -350)
						IsPillar_Up1 = 0;
					if (m_Pillar_1.Get_Py() > -80)
						IsPillar_Up1 = 1;
					if (m_Pillar_2.Get_Py() < -350)
						IsPillar_Up2 = 0;
					if (m_Pillar_2.Get_Py() > -80)
						IsPillar_Up2 = 1;
					if (IsPillar_Up1 == 0)
					{
						m_Pillar_1.pillar_down(20);
					}
					else
					{
						m_Pillar_1.pillar_up(20);
					}
					if (IsPillar_Up2 == 0)
					{
						m_Pillar_2.pillar_down(20);
					}
					else
					{
						m_Pillar_2.pillar_up(20);
					}
				}
			}
			m_Score.change_Py();
		}
		else
			m_Backgraund.change_landx();//使地板移动
/*****************************************指示在这里进行绘图重置**********************************************/
        if ((m_Pillar_1.Get_Px() >= 175 && m_Pillar_1.Get_Px() <= 200) && (m_Bird.Get_Py() <= (460 + m_Pillar_1.Get_Py()) || m_Bird.Get_Py() >= (570 - m_Rand1 + m_Pillar_1.Get_Py())))
		{
			if (IsClickUse == 0 && IsSkillWd == 0)
			{
				Life--;
				IsClickUse = 5;
				SetTimer(6, 600, NULL);
			}
			if (Life == 0)
				IsHit = 1;
			if (m_VoiceTime == 0 && IsSound == 1 && Life == 0)
			{
				PlaySound(_T("res\\hit.wav"), NULL, SND_FILENAME | SND_ASYNC);
				Sleep(350);
				PlaySound(_T("res\\die.wav"), NULL, SND_FILENAME | SND_ASYNC);
				m_VoiceTime++;
			}
		}
		else if (m_Pillar_2.Get_Px() >= 175 && m_Pillar_2.Get_Px() <= 200 && (m_Bird.Get_Py() <= (460 + m_Pillar_2.Get_Py()) || m_Bird.Get_Py() >= (570 - m_Rand2 + m_Pillar_2.Get_Py())))
		{
			if (IsClickUse == 0 && IsSkillWd == 0)
			{
				Life--;
				IsClickUse = 5;
				SetTimer(6, 600, NULL);
			}
			if (Life == 0)
				IsHit = 1;
			if (m_VoiceTime == 0 && IsSound == 1 && Life == 0)
			{
				PlaySound(_T("res\\hit.wav"), NULL, SND_FILENAME | SND_ASYNC);
				Sleep(350);
				PlaySound(_T("res\\die.wav"), NULL, SND_FILENAME | SND_ASYNC);
				m_VoiceTime++;
			}
		}
		else if ((m_Pillar_1.Get_Px() - 140) <= 0 && (m_Pillar_1.Get_Px() - 150) >= -81 && (m_Bird.Get_Py() <= (460 + m_Pillar_1.Get_Py()) || m_Bird.Get_Py() >= (590 - m_Rand1 + m_Pillar_1.Get_Py())))
		{
			if (IsClickUse == 0 && IsSkillWd == 0)
			{
				Life--;
				IsClickUse = 5;
				SetTimer(6, 600, NULL);
			}
			if (Life == 0)
				IsHit = 1;
			if (m_VoiceTime == 0 && IsSound == 1 && Life == 0)
			{
				PlaySound(_T("res\\hit.wav"), NULL, SND_FILENAME | SND_ASYNC);
				Sleep(350);
				PlaySound(_T("res\\die.wav"), NULL, SND_FILENAME | SND_ASYNC);
				m_VoiceTime++;
			}
		}
		else if ((m_Pillar_2.Get_Px() - 140) <= 0 && (m_Pillar_2.Get_Px() - 150) >= -81 && (m_Bird.Get_Py() <= (460 + m_Pillar_2.Get_Py()) || m_Bird.Get_Py() >= (590 - m_Rand2 + m_Pillar_2.Get_Py())))
		{
			if (IsClickUse == 0 && IsSkillWd == 0)
			{
				Life--;
				IsClickUse = 5;
				SetTimer(6, 600, NULL);
			}
			if (Life == 0)
				IsHit = 1;
			if (m_VoiceTime == 0 && IsSound == 1 && Life == 0)
			{
				PlaySound(_T("res\\hit.wav"), NULL, SND_FILENAME | SND_ASYNC);
				Sleep(350);
				PlaySound(_T("res\\die.wav"), NULL, SND_FILENAME | SND_ASYNC);
				m_VoiceTime++;
			}
		}
		else if (m_Bird.Get_Py() <= 0)
		{
			if (IsClickUse == 0)
				Life--;
			IsClickUse = 5;
			SetTimer(6, 600, NULL);
			if (Life == 0)
				IsHit = 1;
			if (m_VoiceTime == 0 && IsSound == 1 && Life == 0)
			{
				PlaySound(_T("res\\hit.wav"), NULL, SND_FILENAME | SND_ASYNC);
				Sleep(350);
				PlaySound(_T("res\\die.wav"), NULL, SND_FILENAME | SND_ASYNC);
				m_VoiceTime++;
			}
		}
		if (m_Bird.Get_Py() >= 750)
		{
			if (IsClickUse == 0)
			{
				Life--;
				IsClickUse = 5;
				SetTimer(6, 600, NULL);
			}
			if (Life == 0)
			{
				IsHit = 1;
				IsHitHead = 1;
			}
			if (m_VoiceTime == 0 && IsSound == 1 && Life == 0)
			{
				PlaySound(_T("res\\hit.wav"), NULL, SND_FILENAME | SND_ASYNC);
				m_VoiceTime++;
			}
		}//撞地
/******************************************指示在这里进行碰撞检测*********************************************/
		break;
	}
	case 2://重置鼠标点击
	{
		IsUserClickPic = 0;
		break;
	}
	case 3://得分检测
	{
		if (IsHit == 0 && IsHitHead == 0)
		{
			if (m_Pillar_1.Get_V() == 14)

			{
				if (m_Pillar_2.Get_Px() == 71 || m_Pillar_2.Get_Px() == 69 || m_Pillar_1.Get_Px() == 69 || m_Pillar_1.Get_Px() == 67 || m_Pillar_2.Get_Px() == 76 || m_Pillar_1.Get_Px() == 76)
				{
					m_Score.change_score();
					if (IsSound == 1)
						PlaySound(_T("res\\point.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
			}
			else
			{
				if (m_Pillar_2.Get_Px() == 71 || m_Pillar_2.Get_Px() == 69 || m_Pillar_1.Get_Px() == 69 || m_Pillar_1.Get_Px() == 67)
				{
					m_Score.change_score();
					if (IsSound == 1)
						PlaySound(_T("res\\point.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}

			}
		}
		TimerRand++;
		tmp_TimerRand = TimerRand % 3;
		tmp_TimerRand2 = TimerRand % 8;

		if (m_Bird.Get_Px() >= m_Heart.Get_Px() - 60 && m_Bird.Get_Px() <= m_Heart.Get_Px() + 20 && m_Bird.Get_Py() >= m_Heart.Get_Py() - 60 && m_Bird.Get_Py() <= m_Heart.Get_Py() - 10 && (Game_Mode == 3 || Game_Mode == 2))
		{
			IsEat = 1;
			Life++;
		}

		break;

	}
	case 4://暂停检测
	{
		IsEat = 0;
		if (IsGameShunt == 1)
		{
			KillTimer(1);
			KillTimer(3);
			KillTimer(8);
			KillTimer(9);
			KillTimer(10);
			KillTimer(11);
			IsGameShutTime = 0;
		}
		else
		{
			if (IsGameShunt != 1 && IsGameShutTime == 0)
			{
				SetTimer(1, 20, NULL);//控制绘图刷新以及碰撞检测
				SetTimer(3, 20, NULL);//控制分数检测
				SetTimer(8, 50000, NULL);//控制Q技能冷却
				SetTimer(11, 5000, NULL);//控制无敌时间
				SetTimer(9, 10000, NULL);//控制W技能冷却
				SetTimer(10, 4000, NULL);//控制E技能冷却
				IsGameShutTime++;
			}
		}
		break;
	}
	case 6:
	{
		IsClickUse = 0;
		KillTimer(6);
		break;
	}
	case 7:
	{
		Invalidate();
		UpdateWindow();
		break;
	}
	case 8:
	{
		IsSkillQ = 0;
		break;
	}
	case 9:
	{
		IsSkillW = 0;
		break;
	}
	case 10:
	{
		IsSkillE = 0;
		m_Score.Reset_EScore();
		m_Pillar_1.Reset_v();
		m_Pillar_2.Reset_v();
		break;
	}
	case 11:
	{
		IsSkillWd = 0;
		break;
	}
	case 12:
	{
		IsLevel_1 = 0;
		IsLevel_2 = 0;
		IsLevel_3 = 0;
		IsLevel_4 = 0;
		IsLevel_5 = 0;
		IsLevel_6 = 0;
		break;
	}
	}
}


void DLA_GAME::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//指示何时开启关闭音乐
	if (IsGameBegin == 0)
	{
		IsLevel_1 = 1;
		SetTimer(12, 300, NULL);//控制关卡图片刷新
		if (point.x >= 20 && point.x <= 70 && point.y >= 20 && point.y <= 70)
		{
			DLA_HELPER Dlg;
			Dlg.DoModal();
		}
		if (point.x >= 0 && point.x <= 270 && point.y >= 700 && point.y <= 780)
		{
			IsGameBegin = 1;
			Game_Mode = 1;
			m_Bird.restart();
			IsUserClick = 0;
			IsUserClickPic = 0;
		}
		else if (point.x >= 275 && point.x <= 555 && point.y >= 700 && point.y <= 780)
		{
			IsGameBegin = 1;
			Game_Mode = 2;
			m_Bird.restart();
			IsUserClick = 0;
			IsUserClickPic = 0;
		}
		else if (point.x >= 560 && point.x <= 830 && point.y >= 700 && point.y <= 780)
		{
			IsGameBegin = 1;
			Game_Mode = 3;
			m_Bird.restart();
			IsUserClick = 0;
			IsUserClickPic = 0;
		}
	}
	else
	{
		IsUserClick = 1;
		IsUserClickPic = 1;
		if(IsSound == 1)
		PlaySound(_T("res\\fly.wav"), NULL, SND_FILENAME | SND_ASYNC);
		SetTimer(2, 400, NULL);

	}
	if (point.y>= 30 && point.y <= 80 && point.x >= 780 && point.x <= 830)
		if (IsSound == 1)
			IsSound = 0;
		else
			IsSound = 1;
	//指示何时重新开始
	if (point.y >= 515 && point.y <= 571 && point.x >= 345 && point.x <= 505 && IsGameBegin == 1 && IsHit == 1)
	{
		SetTimer(12, 300, NULL);//控制关卡图片刷新
		IsGameBegin = 0;
		IsHit = 0;
		IsHitHead = 0;
		Life = 1;
		WriteTime = 0;
		IsLevel_1Use = 0;
		IsLevel_2Use = 0;
		IsLevel_3Use = 0;
		IsLevel_4Use = 0;
		IsLevel_5Use = 0;
		IsLevel_6Use = 0;//指示显示或者关闭关卡图片的变量是否有效
		IsLevel_1 = 1;
		IsLevel_2 = 0;
		IsLevel_3 = 0;
		IsLevel_4 = 0;
		IsLevel_5 = 0;
		IsLevel_6 = 0;
		m_Bird.restart();
		m_Pillar_1.set_Px(900);
		m_Pillar_2.set_Px(400);
		m_Score.restart();
		m_Heart.restart();
		m_VoiceTime = 0;
		m_Pillar_1.restart();
		m_Pillar_2.restart();
		RandD_or_N = rand() % 2;
		IsSkillQ = 0;
		IsSkillW = 0;
		IsSkillE = 0;
		IsSkillWd = 0;
	}
	//指示何时暂停游戏
	if (IsGameShunt == 1 && point.y >= 345 && point.y <= 485 && point.x >= 320 && point.x <= 552  )
		IsGameShunt = 0;
		
	CDialogEx::OnLButtonDown(nFlags, point);
}


int DLA_GAME::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码

	return 0;
}


BOOL DLA_GAME::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	return FALSE;
}


void DLA_GAME::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == VK_SPACE)
		IsGameShunt = 1;
	else if (nChar == 'Q'&&IsSkillQ == 0)
	{
		IsSkillQ = 1;
		IsSkillWd = 1;
		SetTimer(8, 50000, NULL);//控制Q技能冷却
		SetTimer(11, 5000, NULL);//控制无敌时间
	}
	else if (nChar == 'W'&&IsSkillW == 0 && Life <= 2)
	{
		IsSkillW = 1;
		Life++;
		SetTimer(9, 10000, NULL);//控制W技能冷却
	}
	else if (nChar == 'E'&&IsSkillE == 0)
	{
		IsSkillE = 1;
		m_Pillar_1.Change_V();
		m_Pillar_2.Change_V();
		m_Score.Change_EScore();
		SetTimer(10, 4000, NULL);//控制E技能冷却
	}

	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}




void DLA_GAME::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (point.x >= 620 && point.x <= 683 && point.y >= 80 && point.y <= 143)
	{
		IsMouseQ = 1;
		IsMouseW = 0;
		IsMouseE = 0;
	}
	else if (point.x >= 700 && point.x <= 763 && point.y >= 80 && point.y <= 143)
	{
		IsMouseQ = 0;
		IsMouseW = 1;
		IsMouseE = 0;
	}
	else if (point.x >= 780 && point.x <= 843 && point.y >= 80 && point.y <= 143)
	{
		IsMouseQ = 0;
		IsMouseW = 0;
		IsMouseE = 1;
	}
	else
	{
		IsMouseQ = 0;
		IsMouseW = 0;
		IsMouseE = 0;
	}


	CDialogEx::OnMouseMove(nFlags, point);
}
