#pragma once
class CBackGarundPic
{
public:
	CBackGarundPic();
	~CBackGarundPic();
private:
	CImage m_Backimage[3];//游戏开始前以及游戏开始后的两种背景
	CImage m_landimage;//地板图片
	CImage m_GameOverimage;//游戏结束图片
	CImage m_RePlayImage;//重玩图片
	int p_landx;//地板的x坐标
	int p_landy;//地板的y坐标


public:
	CImage & get_Bckimage(int IsBegin);
	CImage& get_landimage();
	CImage& getGameOverimage();
	CImage& getRePlayimage();
	int get_landx();//获取地板的x坐标
	int get_landy();//获取地板的y坐标
	void change_landx();//改变地板的x坐标
	void restart();
};

