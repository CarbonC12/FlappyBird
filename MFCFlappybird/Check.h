#pragma once
class Check
{
private:
	CString Uusername;
	CString Upassword;
	int Score;
	
	
public:
	bool IsUsmRight;//�û����Ƿ���ȷ���жϱ���
	bool IsPawRight;//�����Ƿ���ȷ���жϱ���
	Check(CString Inusn,CString Inpaw);
	Check();
	~Check();
	bool CheckRigth();	//����û���������ĺ���
	void Login();//���û�����������Ϣ�����ļ�
	bool IsNothing;//�ж��ļ��Ƿ����
	int Isrepeat = 0;//�ж��û����Ƿ��ظ�
	int GetScore();
	void WriteScore(int UserScore);
};

