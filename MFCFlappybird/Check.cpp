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
	ifstream in("Users.txt");//打开文件
	string line;
	string SUusername(CW2A(Uusername.GetString()));//两句话都是实现了CString和string的转化
	string SUpassword(CW2A(Upassword.GetString()));
	bool Username = 0;
	bool Password = 0;
	bool Right = 0;
	int time = 1;
	if (in) // 有该文件
	{
		IsNothing = false;
		while (getline(in, line, '|') && (Username != 1 || Password != 1)) // line中不包括每行的标识符
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
	else // 没有该文件
	{
		IsNothing = true;
	}
	if (Username&&Password)
		Right = true;
	return Right;
}

void Check::Login()
{
	string SUusername(CW2A(Uusername.GetString()));//实现了CString与strig的转化
	string SUpassword(CW2A(Upassword.GetString()));//实现了CString与strig的转化
	ifstream out("Users.txt");
	string line;
	int time = 1;
	bool Username=0;
	while (getline(out, line, '|') && Username != 1) // line中不包括每行的换行符
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
		in << SUusername << '|' << SUpassword << '|';//将信息存入txt文件中
	}
	else
		Isrepeat = 1;

}

int Check::GetScore()
{
	ifstream in("Score.txt");
	string Scoreline;
	if (in) // 有该文件
	{
		IsNothing = false;
		while (getline(in, Scoreline, '|')) // line中不包括每行的标识符
		{
			int tmp_Score = atoi(Scoreline.c_str());
			if (tmp_Score >= Score)
				Score = tmp_Score;
		}
	}
	else // 没有该文件
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





