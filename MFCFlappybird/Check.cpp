#include "stdafx.h"
#include "Check.h"
#include "fstream"
#include <string>
#include <iostream>

using namespace std;




Check::Check(CString Inusn, CString Inpaw)
{
	Uusername = Inusn;
	Upassword = Inpaw;
}

Check::Check()
{
	Score = 0;
}

Check::~Check()
{
}

bool Check::CheckRigth()
{
	ifstream in("Users.txt");//���ļ�
	string line;
	string SUusername(CW2A(Uusername.GetString()));//���仰����ʵ����CString��string��ת��
	string SUpassword(CW2A(Upassword.GetString()));
	bool Username = 0;
	bool Password = 0;
	bool Right = 0;
	int time = 1;
	if (in) // �и��ļ�
	{
		IsNothing = false;
		while (getline(in, line, '|') && (Username != 1 || Password != 1)) // line�в�����ÿ�еı�ʶ��
		{

			if (time % 2 == 1)
			{
				if (line == SUusername)
					Username = 1;
				else
					Username = 0;
			}
			else
			{
				if (line == SUpassword)
					Password = 1;
				else
					Password = 0;

			}
			time++;
		}
	}
	else // û�и��ļ�
	{
		IsNothing = true;
	}
	if (Username&&Password)
		Right = true;
	return Right;
}

void Check::Login()
{
	string SUusername(CW2A(Uusername.GetString()));//ʵ����CString��strig��ת��
	string SUpassword(CW2A(Upassword.GetString()));//ʵ����CString��strig��ת��
	ifstream out("Users.txt");
	string line;
	int time = 1;
	bool Username=0;
	while (getline(out, line, '|') && Username != 1) // line�в�����ÿ�еĻ��з�
	{

		if (time % 2 == 1)
		{
			if (line == SUusername)
				Username = 1;
			else
				Username = 0;
		}
		time++;
	}
	if (Username != 1)
	{
		ofstream in("Users.txt", ios::app);
		in << SUusername << '|' << SUpassword << '|';//����Ϣ����txt�ļ���
	}
	else
		Isrepeat = 1;

}

int Check::GetScore()
{
	ifstream in("Score.txt");
	string Scoreline;
	if (in) // �и��ļ�
	{
		IsNothing = false;
		while (getline(in, Scoreline, '|')) // line�в�����ÿ�еı�ʶ��
		{
			int tmp_Score = atoi(Scoreline.c_str());
			if (tmp_Score >= Score)
				Score = tmp_Score;
		}
	}
	else // û�и��ļ�
	{
		Score = 0;
	}

	return Score;
}

void Check::WriteScore(int UserScore)
{
	ofstream WriteScore("Score.txt", ios::app);
	string line;
	line = to_string(UserScore);
	WriteScore << line << "|";
}





