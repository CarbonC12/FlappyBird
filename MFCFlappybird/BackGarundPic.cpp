#include "stdafx.h"
#include "BackGarundPic.h"


CBackGarundPic::CBackGarundPic()
{
	m_Backimage[0].Load(_T("res\\Start.png"));
	m_Backimage[1].Load(_T("res\\bg_daytime_no.jpg"));
	m_Backimage[2].Load(_T("res\\bg_night.png"));
	m_landimage.Load(_T("res\\land.png"));
	p_landx = 0;
	p_landy = 480;
	m_GameOverimage.Load(_T("res\\text_game_over.png"));
	m_RePlayImage.Load(_T("res\\button_play.bmp"));
}


CBackGarundPic::~CBackGarundPic()
{
}

CImage & CBackGarundPic::get_Bckimage(int IsBegin)
{
	return m_Backimage[IsBegin];
	// TODO: �ڴ˴����� return ���
}

CImage & CBackGarundPic::get_landimage()
{
	return m_landimage;
	// TODO: �ڴ˴����� return ���
}

CImage & CBackGarundPic::getGameOverimage()
{
	return  m_GameOverimage;
	// TODO: �ڴ˴����� return ���
}

CImage & CBackGarundPic::getRePlayimage()
{
	return m_RePlayImage;
	// TODO: �ڴ˴����� return ���
}

int CBackGarundPic::get_landx()
{
	return p_landx;
}

int CBackGarundPic::get_landy()
{
	return p_landy;
}

void CBackGarundPic::change_landx()
{
	if (p_landx<-110)//�ذ�ˢ���ж�
		p_landx = 0;
	else
		p_landx -= 7;//�ذ��ƶ��ٶ�
}

void CBackGarundPic::restart()
{
	p_landx = 0;
	p_landy = 480;
}
