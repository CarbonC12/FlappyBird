#pragma once
class CScore
{
public:
	CScore();
	~CScore();
private:


	int m_score;//����÷�
	int m_ScorePy;//�Ƿ��Ƶ�����
	CImage m_scorePic[10];//������ʮ��ͼƬ
	CImage m_panelPic;//�Ƿ��Ƶ�ͼƬ
	CImage m_medalPic[3];//���ֽ��Ƶ�ͼƬ
	int m_EScore;//ÿ�μӷ�



public:

	CImage & getImage(int num);
	CImage& getpanel();
	CImage& getmedal(int num);//��ȡ����ͼƬ
	int get_score();//��ȡ����
	void change_score();//���ӷ���
	void change_Py();//ʹ�Ƿ������������ƶ�
	int get_Py();//��ȡ�Ƿ���y����
	void restart();//���ò���
	void Change_EScore();
	void Reset_EScore();
};

