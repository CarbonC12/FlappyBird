#pragma once
class CPillar
{
public:
	CPillar();
	~CPillar();
private:
	float m_Py;//���Ϸ���������λ��
	float m_Px;//���ӵ�����X����
	CImage m_PillarPic_Day[2];//���������������ӵ�ͼ��
	CImage m_PillarPic_Night[2];//���������������ӵ�ͼ��
	int m_Pmove;//���ӵ��ƶ��ٶ�

public:

	int Get_V();
	float Get_Py();//��ȡy����
	float Get_Px();//��ȡx����
	void set_Py();//�ı�y����
	void change_Px();//�ı�x��
	void set_Px(int x);//����x����
	CImage &get_pillarPicDay(int num);
	CImage &get_pillarPicNight(int num);
	void restart();//���ò���
	void pillar_up(float up_v);//��������
	void pillar_down(float down_v);//�����½�
	int m_PillarRand;
	void Change_V();
	void Reset_v();


};

