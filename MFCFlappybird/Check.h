#pragma once
class Check
{
private:
	CString Uusername;
	CString Upassword;
	int Score;
	
	
public:
	bool IsUsmRight;//用户名是否正确的判断变量
	bool IsPawRight;//密码是否正确的判断变量
	Check(CString Inusn,CString Inpaw);
	Check();
	~Check();
	bool CheckRigth();	//检查用户名和密码的函数
	void Login();//将用户名和密码信息输入文件
	bool IsNothing;//判断文件是否存在
	int Isrepeat = 0;//判断用户名是否重复
	int GetScore();
	void WriteScore(int UserScore);
};

