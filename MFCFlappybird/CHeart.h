#pragma once
class CHeart
{
public:
	CHeart();
	~CHeart();
private:
	CImage m_Heart[1];
	CImage m_BHeart[2];
	float H_Py;//�ĵ�Y������
	float H_Vy;//�ĵ�Y�����ٶ�
	float H_Px;//�ĵ�X��������
	int IsDown;
public:
	float Get_Py();//������y����
	float Get_Px();//������X����
	void Set_Py();//�ı�С���y����
	void Set_HVy(int v);//�ı�����ٶ�
	void Set_Px(int pro,int life);//�ı����X����
	void Is_Eat(int m_IsEat);//�ж��Ƿ񱻳Ե�
	CImage &Get_HeartImage();
	CImage &Get_BHeartImage(int state);
	void restart();
};

