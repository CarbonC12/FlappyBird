#include "stdafx.h"
#include "CPillar.h"


CPillar::CPillar()
{
	m_Py = rand() % 350 - 380;
	m_Px = 860;
	m_PillarPic_Day[0].Load(_T("res\\pipe_down.png"));
	m_PillarPic_Day[1].Load(_T("res\\pipe_up.png"));
	m_PillarPic_Night[0].Load(_T("res\\pipe_night_down.png"));
	m_PillarPic_Night[1].Load(_T("res\\pipe_night_up.png"));
	m_Pmove = 7;
}


CPillar::~CPillar()
{
}

int CPillar::Get_V()
{
	return m_Pmove;
}

float CPillar::Get_Py()
{
	return m_Py;
}

float CPillar::Get_Px()
{
	return m_Px;
}

void CPillar::set_Py()
{
	if (m_Px == 860)
	{
		m_Py = rand() % 400 - 430;
		m_PillarRand = rand() % 45;
	}
}

void CPillar::change_Px()
{
	if (m_Px>(-80))
		m_Px -= m_Pmove;
	else
		m_Px = 860;
}

void CPillar::set_Px(int x)
{
	m_Px = x;
}

CImage & CPillar::get_pillarPicDay(int num)
{
	return m_PillarPic_Day[num];
	// TODO: 在此处插入 return 语句
}

CImage & CPillar::get_pillarPicNight(int num)
{
	return m_PillarPic_Night[num];
	// TODO: 在此处插入 return 语句
}

void CPillar::restart()
{
	m_Py = rand() % 400 - 430;
}

void CPillar::pillar_up(float up_v)
{
	m_Py -= up_v;
}

void CPillar::pillar_down(float down_v)
{
	m_Py += down_v;
}

void CPillar::Change_V()
{
	m_Pmove = 14;
}

void CPillar::Reset_v()
{
	m_Pmove = 7;
}
