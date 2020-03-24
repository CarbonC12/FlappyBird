#include "stdafx.h"
#include "CHeart.h"


CHeart::CHeart()
{
	m_Heart[0].Load(_T("res\\Heart.png"));
	m_BHeart[0].Load(_T("res\\NoHeart.png"));
	m_BHeart[1].Load(_T("res\\Heart.png"));
	H_Py = 100;
	H_Vy = 3;
	H_Px = 860;
}


CHeart::~CHeart()
{
}

float CHeart::Get_Py()
{
	return H_Py;
}

float CHeart::Get_Px()
{
	return H_Px;
}

void CHeart::Set_Py()
{
	if (H_Py < 160)
		IsDown = 1;
		//H_Py = H_Py + H_Vy;
	if (H_Py > 600)
		IsDown = 0;
	if(IsDown==1)
		H_Py = H_Py + H_Vy;
	else
		H_Py = H_Py - H_Vy;
}

void CHeart::Set_HVy(int v)
{
	H_Vy = v;
}

void CHeart::Set_Px(int pro,int life)
{
	if (H_Px > (-80))
		H_Px -= 8;
	else
		if (pro == 1 && life <= 2)
		{
			H_Px = 860;
			H_Py = 500;
		}
		else
			H_Py = -81;
}

void CHeart::Is_Eat(int m_IsEat)
{
	if (m_IsEat == 1)
		H_Px = -81;
}

CImage & CHeart::Get_HeartImage()
{
	return m_Heart[0];
	// TODO: 在此处插入 return 语句
}

CImage & CHeart::Get_BHeartImage(int state)
{
	if (state >= 1)
		return m_BHeart[1];
	else if (state <= 0)
		return m_BHeart[0];

	// TODO: 在此处插入 return 语句
}

void CHeart::restart()
{
	H_Py = 100;
	H_Vy = 3;
	H_Px = 860;
}
