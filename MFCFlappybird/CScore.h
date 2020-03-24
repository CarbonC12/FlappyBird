#pragma once
class CScore
{
public:
	CScore();
	~CScore();
private:


	int m_score;//计算得分
	int m_ScorePy;//记分牌的坐标
	CImage m_scorePic[10];//分数的十张图片
	CImage m_panelPic;//记分牌的图片
	CImage m_medalPic[3];//三种奖牌的图片
	int m_EScore;//每次加分



public:

	CImage & getImage(int num);
	CImage& getpanel();
	CImage& getmedal(int num);//获取奖牌图片
	int get_score();//获取分数
	void change_score();//增加分数
	void change_Py();//使记分牌慢慢往上移动
	int get_Py();//获取记分牌y坐标
	void restart();//重置参数
	void Change_EScore();
	void Reset_EScore();
};

