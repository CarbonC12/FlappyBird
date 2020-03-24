#pragma once
class CHeart
{
public:
	CHeart();
	~CHeart();
private:
	CImage m_Heart[1];
	CImage m_BHeart[2];
	float H_Py;//心的Y轴坐标
	float H_Vy;//心的Y方向速度
	float H_Px;//心的X方向坐标
	int IsDown;
public:
	float Get_Py();//获得鸟的y坐标
	float Get_Px();//获得鸟的X坐标
	void Set_Py();//改变小鸟的y坐标
	void Set_HVy(int v);//改变鸟的速度
	void Set_Px(int pro,int life);//改变鸟的X坐标
	void Is_Eat(int m_IsEat);//判断是否被吃掉
	CImage &Get_HeartImage();
	CImage &Get_BHeartImage(int state);
	void restart();
};

