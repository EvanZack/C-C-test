#include<iostream>
#include<fstream>
#include<string>
#include <windows.h>
#include<cmath>
#include<ctime>

using namespace std;
#pragma warning(disable: 4996)
class OCppCountLine
{
public:
	int CountCodeLines();
	int CountCommentLines();
	int CountNullLines();
	int CountLines();
	void Getfile(int a);
protected:
	void  ShowInputFile();     //显示输入文件名界面 
	void  ShowStatic();        //显示统计结果 
	void  ShowMainMenu();    //显示主菜单 
	void  ShowSave();         //显示保存界面 
	void  ShowParameter();    //显示参数设置界面 
    string  _fileName;        //处理的文件名 
};
class MainFrame
{
public:         
	void MenuSetParameter();     //响应参数设置选项 
	void MenuSave();             //响应保存选项 
	void MenuFile(int a);             //响应文件选项 
	void MenuOpenFile(int a=0);    //响应打开文件选项 
	void MenuMain();             //响应进入主菜单选项 

	void  ShowInputFile();     //显示输入文件名界面 
	void  ShowStatic();        //显示统计结果 
	void  ShowSave();          //显示保存界面 
	void  ShowParameter();     //显示参数设置界面 
	string  _fileName;         //处理的文件名 

};
  OCppCountLine test;
  MainFrame pro;
void MainFrame::ShowStatic()         //显示统计结果 
{	
}
void MainFrame::ShowSave()
{
	cout << "该文件已经保存成功！" << endl;
}

  int isStr(char *s1, char *s2)
  {
	  int i = 0, j = 0;
	  while (s1[i] != '\0')
	  {
		  if (s1[i] == s2[j])
		  {
			  i++;
			  j++;
			  if (s2[j] == '\0')
				  return i - j;
			  continue;
		  }
		  i++;
		  j = 0;
	  }
	  return -1;

  }
void OCppCountLine:: Getfile(int a)
{
	ifstream infile;
	system("dir D:\\c++\\代码\\*.c*");
	cout << "请输入要操作的文件名: ";
	char filename[50];
	cin >> filename;
	fflush(stdin);
	char path[100] = "D:\\c++\\代码\\";
	strcat_s(path, 100, filename);
	infile.open(path);
	if (!infile)
	{
		cout << "open file error!" << endl;
		exit(1);
	}
	string s;
	static int  count = 0;
	static int commLines = 0;
	static int massiveline = 0;
	static int sub_commLines = 0;// 若"/*  */" 之间的//  应该减掉
	static int all_comm = 0;//只有注释
	static int nullcodeLines = 0;
	static int AccoutStar1 = 0;// 记录 /* 的次数
	//while (infile.read(&ch, 1))
	static int markslines = 0; //记录  双引号里面的注释行
	static bool marksflag = true;//匹配双引号
	while (getline(infile, s))
	{
		++count;
		int set;
		char* p;


		p = new char[s.length() + 1];
		strcpy_s(p, s.length() + 1, s.c_str());

		if (s.length() == 0)
			++nullcodeLines;

		//if (ch == ' ' || ch == '	')//忽略空格和tab
		set = isStr(p, "//");    //根据返回值判断注释行有没有代码。set是0  则全是注释
		if (set == 0)
			++all_comm;
		if (set >0)
			++commLines;

		int set2;
		set2 = isStr(p, "/*");/**/
		if (set2 != -1)
		{
			int set3;//比较先有//  还是/*
			set3 = isStr(p, "//");
			if (set3 != -1 && set3 < set2)
				continue;

			else if (set3 != -1 && set3>set2)
			{
				AccoutStar1 = 1;
				++sub_commLines;
			}
			else
				AccoutStar1 = 1;
		}

		if (AccoutStar1 == 1 && set != -1)
			++sub_commLines; //   这种情况应该把 //的注释记录减一  "// */   "
		if (AccoutStar1 == 1)
			++massiveline;
		int set4;// 记录 */
		set4 = isStr(p, "*/");
		if (set4 != -1 && AccoutStar1 == 1)
		{
			AccoutStar1 = 0;
		}


		int set6;  //记录另一半双引号
		set6 = isStr(p, "\"");
		if (marksflag == false && set6 != -1 && set == -1)
		{
			marksflag = true;
			markslines = 0;
		}

		int set5;//这种情况字符串里面出现 注释    "   //    /*   */          " //  "//"
		set5 = isStr(p, "\"");

		if (set5 != -1 && set6 != -1 && marksflag == true && set == -1)
		{
			marksflag = true;
			++markslines;
		}

		if (set5 != -1 && marksflag == true)
		{
			marksflag = false;
		}
		if (marksflag == false && set != -1 && set5>set)
			++markslines;

	}
	
	int code = abs(count - nullcodeLines - (commLines + massiveline - sub_commLines - markslines));
	int zhushi = all_comm +commLines+ massiveline - sub_commLines - markslines;
		system("cls");
		cout << "***************************************************" << endl;
		cout << "总行数为: " << count << endl;
		cout << "空格行为：" << nullcodeLines << endl;
		cout << "代码行数为：" << code << endl;
		cout << "注释行为: " << zhushi<<endl;
		cout << "其中有代码的注释行为：" << commLines<<endl;
		cout << "***************************************************";
		cout << endl;
		cout << "输入0返回主界面，按1退出！" << endl;
		count = 0;
		nullcodeLines = 0;
		code = 0;
		zhushi = 0;
		commLines = 0;

	int fla;
	cin >> fla;
	if (fla==0)
		pro.MenuMain();
	else if (fla == 1)
	{
		exit(0);
	}
	infile.close();
}

void MainFrame::MenuSetParameter()
{
	int a;
	pro.MenuFile(3);
	system("cls");
	cout << "                     ******************************************" << endl;
	cout << "                     ***         0 显示菜单                 ***" << endl;
	cout << "                     ***         1 只作为代码行处理         ***" << endl;
	cout << "                     ***         2 代码行和注释行各增加一行 ***" << endl;
	cout << "                     ***         3 只作为注释行处理         ***" << endl;
	cout << "                     ******************************************" << endl;
	cout << "                     请输入你想要的操作：";
	cin >> a;
	switch (a)
	{
	case 0: pro.MenuMain(); break;
	case 1:
	{
			  system("cls");
			  cout << "已经设置成功！" << endl;
			  cout << "准备进行代码统计！" << endl;
			  pro.MenuOpenFile(a);
			  break;
	}
	case 2: 
	{
			  system("cls");
			  cout << "已经设置成功！" << endl;
			  cout << "准备进行代码统计！" << endl;
			  pro.MenuOpenFile(a);
			  break;
	}
	case 3: 
	{
				system("cls");
				cout << "已经设置成功！" << endl;
				cout << "准备进行代码统计！" << endl;
				pro.MenuOpenFile(a);
				break;
	}
	default:
		pro.MenuSetParameter();
	}


}
void MainFrame::MenuSave()
{
	pro.ShowSave();
}
void MainFrame::MenuFile(int a)
{
	
	char ch;
	time_t t = time(0);
	char tmp[64];
	
	ofstream file;
	ifstream file1;
	char path[100] = "D:\\c++\\日志文件\\logfile.txt";
	file.open(path, ios_base::app | ios_base::out);
	
	if (!file)
	{
		cout << "open file error!" << endl;
		exit(1);
	}

	switch (a)
	{
	case 0:
		strftime(tmp, sizeof(tmp), "%Y/%m/%d %X %A", localtime(&t));
		file<<tmp<<endl;
		file << "进入主菜单\n";
		
		break;

	case 1:
		strftime(tmp, sizeof(tmp), "%Y/%m/%d %X %A", localtime(&t));
		file << tmp << endl;
		file << "查看了日志文件\n";
		file.close();
		file1.open(path, ios_base::app | ios_base::out);
		while (file1.read(&ch, 1))
		{
			cout << ch;
		}
		cout << endl;
		file1.close();
		
		break;
	case 2:
		strftime(tmp, sizeof(tmp), "%Y/%m/%d %X %A", localtime(&t));
		file << tmp << endl;
		file << "执行打开文件\n";
		
		break;
	case 3:
		strftime(tmp, sizeof(tmp), "%Y/%m/%d %X %A", localtime(&t));
		file << tmp << endl;
		file << "进行了设置\n";
		
	}
	
	file.close();
	
}
void MainFrame::MenuOpenFile(int b)
{
	
		test.Getfile(b);
		pro.MenuFile(2);
}
void MainFrame::MenuMain()
{
	int a;
	pro.MenuFile(0);
	system("cls");
	cout << "                     ******************************************" << endl;
	cout << "                     ***             0 显示菜单             ***" << endl;
	cout << "                     ***             1 日志查看             ***" << endl;
	cout << "                     ***             2 打开文件             ***" << endl;
	cout << "                     ***             3 设置                 ***" << endl;
	cout << "                     ***             4 保存                 ***" << endl;
	cout << "                     ***             5 退出                 ***" << endl;
	cout << "                     ******************************************" << endl;
	cout << "                     请输入你想要的操作：";
	cin >> a;
	switch (a)
	{
	case 0: pro.MenuMain();

		break;
	case 1: pro.MenuFile(1); break;
	case 2:
		pro.MenuOpenFile();
		break;
	case 3:
		pro.MenuSetParameter();
		break;
	case 4: pro.MenuSave(); break;
	case 5: exit(0);
	default: pro.MenuMain(); break;
	}
}

int main()
{
	int a;
	cout << "                     ******************************************" << endl;
	cout << "                     ***             0 显示菜单             ***" << endl;
	cout << "                     ***             1 日志查看             ***" << endl;
	cout << "                     ***             2 打开文件             ***" << endl;
	cout << "                     ***             3 设置                 ***" << endl;
	cout << "                     ***             4 保存                 ***" << endl;
	cout << "                     ***             5 退出                 ***" << endl;
	cout << "                     ******************************************" << endl;
	cout << "                     请输入你想要的操作：";
	cin >> a;
	switch (a)
	{
	case 0: pro.MenuMain();
		    
		break;
	case 1: pro.MenuFile(1); break;
	case 2: 
		pro.MenuOpenFile();
		break;
	case 3: 
		pro.MenuSetParameter();
		break;
	case 4: pro.MenuSave(); break;
	case 5: exit(0);
	default: pro.MenuMain(); break;
	}
	return 0;
}


