#pragma once
class CBackGarundPic
{
public:
	CBackGarundPic();
	~CBackGarundPic();
private:
	CImage m_Backimage[3];//��Ϸ��ʼǰ�Լ���Ϸ��ʼ������ֱ���
	CImage m_landimage;//�ذ�ͼƬ
	CImage m_GameOverimage;//��Ϸ����ͼƬ
	CImage m_RePlayImage;//����ͼƬ
	int p_landx;//�ذ��x����
	int p_landy;//�ذ��y����


public:
	CImage & get_Bckimage(int IsBegin);
	CImage& get_landimage();
	CImage& getGameOverimage();
	CImage& getRePlayimage();
	int get_landx();//��ȡ�ذ��x����
	int get_landy();//��ȡ�ذ��y����
	void change_landx();//�ı�ذ��x����
	void restart();
};

