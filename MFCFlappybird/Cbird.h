#pragma once
class Cbird
{
public:
	Cbird();
	~Cbird();
private:
	CImage m_BirdUp[3];
	CImage m_BirdDown[3];
	CImage m_MBird[3];
	float B_a;//鸟的向下加速度，一般数值为正
	float B_Px;//鸟的X轴坐标
	float B_Py;//鸟的Y轴坐标
	float B_Vy;//鸟的Y方向速度
public:
	float Get_Py();//获得鸟的y坐标
	float Get_Px();//获得鸟的x坐标
	void Set_Py();//改变小鸟的y坐标
	void Set_BVy(int IsClick);//改变鸟的速度
	void Set_Die_Py();
	CImage &get_Image(int IsClick,int num);//返回小鸟当前该有的照片
	CImage &Get_MImage(int num);
	void restart();
};

