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
	float B_a;//������¼��ٶȣ�һ����ֵΪ��
	float B_Px;//���X������
	float B_Py;//���Y������
	float B_Vy;//���Y�����ٶ�
public:
	float Get_Py();//������y����
	float Get_Px();//������x����
	void Set_Py();//�ı�С���y����
	void Set_BVy(int IsClick);//�ı�����ٶ�
	void Set_Die_Py();
	CImage &get_Image(int IsClick,int num);//����С��ǰ���е���Ƭ
	CImage &Get_MImage(int num);
	void restart();
};

