#include "stdafx.h"
#include "Cbird.h"


Cbird::Cbird()
{
	m_BirdUp[0].Load(_T("res\\bird0_3.png"));
	m_BirdUp[1].Load(_T("res\\bird0_2.png"));
	m_BirdUp[2].Load(_T("res\\bird0_1.png"));
	m_BirdDown[0].Load(_T("res\\Dbird2_3.png"));
	m_BirdDown[1].Load(_T("res\\Dbird2_2.png"));
	m_BirdDown[2].Load(_T("res\\Dbird2_1.png"));
	m_MBird[0].Load(_T("res\\bird2_2.png"));
	m_MBird[1].Load(_T("res\\bird2_1.png"));
	m_MBird[2].Load(_T("res\\bird2_0.png"));
	B_a = 0.5;
	B_Px = 150;
	B_Py = 280;
	B_Vy = 0;

}


Cbird::~Cbird()
{
}

float Cbird::Get_Py()
{
	return B_Py;//返回小鸟当前的Y坐标
}

float Cbird::Get_Px()
{
	return B_Px;
}

void Cbird::Set_Py()
{
	B_Py+=B_Vy;
}

void Cbird::Set_BVy(int IsClick)
{
	if (IsClick == 0)
		B_Vy = B_Vy + B_a;
	else
		B_Vy = -8;
}

void Cbird::Set_Die_Py()
{
	B_Py += 30;
}

CImage & Cbird::get_Image(int IsClick,int num)
{
	if (IsClick == 1)
		return m_BirdUp[num];
	else
		return m_BirdDown[num];
	// TODO: 在此处插入 return 语句
}

CImage & Cbird::Get_MImage(int num)
{
	return m_MBird[num];
	// TODO: 在此处插入 return 语句
}

void Cbird::restart()
{
	B_a = 0.5;
	B_Px = 150;
	B_Py = 280;
	B_Vy = 0;
}

