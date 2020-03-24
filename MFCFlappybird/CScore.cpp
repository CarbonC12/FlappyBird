#include "stdafx.h"
#include "CScore.h"


CScore::CScore()
{
	m_score = 0;
	m_ScorePy = 650;


	m_panelPic.Load(TEXT("res\\score_panel.png"));
	m_scorePic[0].Load(TEXT("res\\font_0.png"));
	m_scorePic[1].Load(TEXT("res\\font_1.png"));
	m_scorePic[2].Load(TEXT("res\\font_2.png"));
	m_scorePic[3].Load(TEXT("res\\font_3.png"));
	m_scorePic[4].Load(TEXT("res\\font_4.png"));
	m_scorePic[5].Load(TEXT("res\\font_5.png"));
	m_scorePic[6].Load(TEXT("res\\font_6.png"));
	m_scorePic[7].Load(TEXT("res\\font_7.png"));
	m_scorePic[8].Load(TEXT("res\\font_8.png"));
	m_scorePic[9].Load(TEXT("res\\font_9.png"));
	m_medalPic[0].Load(TEXT("res\\medals_0.png"));
	m_medalPic[1].Load(TEXT("res\\medals_1.png"));
	m_medalPic[2].Load(TEXT("res\\medals_2.png"));
}


CScore::~CScore()
{
}

CImage & CScore::getImage(int num)
{
	return m_scorePic[num];
	// TODO: 在此处插入 return 语句
}

CImage & CScore::getpanel()
{
	return m_panelPic;
	// TODO: 在此处插入 return 语句
}

CImage & CScore::getmedal(int num)
{
	return m_medalPic[num];
	// TODO: 在此处插入 return 语句
}

int CScore::get_score()
{
	return m_score;
}

void CScore::change_score()
{
	m_score= m_score+ m_EScore;
}

void CScore::change_Py()
{
	if (m_ScorePy>250)
		m_ScorePy -= 10;
}

int CScore::get_Py()
{
	return m_ScorePy;
}

void CScore::restart()
{
	m_score = 0;
	m_ScorePy = 650;
}

void CScore::Change_EScore()
{
	m_EScore = 4;
}

void CScore::Reset_EScore()
{
	m_EScore = 1;
}
