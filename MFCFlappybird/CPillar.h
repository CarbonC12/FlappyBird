#pragma once
class CPillar
{
public:
	CPillar();
	~CPillar();
private:
	float m_Py;//最上方管子中心位置
	float m_Px;//管子的中心X坐标
	CImage m_PillarPic_Day[2];//白天上下两根管子的图像
	CImage m_PillarPic_Night[2];//晚上上下两根管子的图像
	int m_Pmove;//管子的移动速度

public:

	int Get_V();
	float Get_Py();//获取y坐标
	float Get_Px();//获取x坐标
	void set_Py();//改变y坐标
	void change_Px();//改变x标
	void set_Px(int x);//设置x坐标
	CImage &get_pillarPicDay(int num);
	CImage &get_pillarPicNight(int num);
	void restart();//重置参数
	void pillar_up(float up_v);//柱子上升
	void pillar_down(float down_v);//柱子下降
	int m_PillarRand;
	void Change_V();
	void Reset_v();


};

