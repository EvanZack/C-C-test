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
	void  ShowInputFile();     //��ʾ�����ļ������� 
	void  ShowStatic();        //��ʾͳ�ƽ�� 
	void  ShowMainMenu();    //��ʾ���˵� 
	void  ShowSave();         //��ʾ������� 
	void  ShowParameter();    //��ʾ�������ý��� 
    string  _fileName;        //������ļ��� 
};
class MainFrame
{
public:         
	void MenuSetParameter();     //��Ӧ��������ѡ�� 
	void MenuSave();             //��Ӧ����ѡ�� 
	void MenuFile(int a);             //��Ӧ�ļ�ѡ�� 
	void MenuOpenFile(int a=0);    //��Ӧ���ļ�ѡ�� 
	void MenuMain();             //��Ӧ�������˵�ѡ�� 

	void  ShowInputFile();     //��ʾ�����ļ������� 
	void  ShowStatic();        //��ʾͳ�ƽ�� 
	void  ShowSave();          //��ʾ������� 
	void  ShowParameter();     //��ʾ�������ý��� 
	string  _fileName;         //������ļ��� 

};
  OCppCountLine test;
  MainFrame pro;
void MainFrame::ShowStatic()         //��ʾͳ�ƽ�� 
{	
}
void MainFrame::ShowSave()
{
	cout << "���ļ��Ѿ�����ɹ���" << endl;
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
	system("dir D:\\c++\\����\\*.c*");
	cout << "������Ҫ�������ļ���: ";
	char filename[50];
	cin >> filename;
	fflush(stdin);
	char path[100] = "D:\\c++\\����\\";
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
	static int sub_commLines = 0;// ��"/*  */" ֮���//  Ӧ�ü���
	static int all_comm = 0;//ֻ��ע��
	static int nullcodeLines = 0;
	static int AccoutStar1 = 0;// ��¼ /* �Ĵ���
	//while (infile.read(&ch, 1))
	static int markslines = 0; //��¼  ˫���������ע����
	static bool marksflag = true;//ƥ��˫����
	while (getline(infile, s))
	{
		++count;
		int set;
		char* p;


		p = new char[s.length() + 1];
		strcpy_s(p, s.length() + 1, s.c_str());

		if (s.length() == 0)
			++nullcodeLines;

		//if (ch == ' ' || ch == '	')//���Կո��tab
		set = isStr(p, "//");    //���ݷ���ֵ�ж�ע������û�д��롣set��0  ��ȫ��ע��
		if (set == 0)
			++all_comm;
		if (set >0)
			++commLines;

		int set2;
		set2 = isStr(p, "/*");/**/
		if (set2 != -1)
		{
			int set3;//�Ƚ�����//  ����/*
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
			++sub_commLines; //   �������Ӧ�ð� //��ע�ͼ�¼��һ  "// */   "
		if (AccoutStar1 == 1)
			++massiveline;
		int set4;// ��¼ */
		set4 = isStr(p, "*/");
		if (set4 != -1 && AccoutStar1 == 1)
		{
			AccoutStar1 = 0;
		}


		int set6;  //��¼��һ��˫����
		set6 = isStr(p, "\"");
		if (marksflag == false && set6 != -1 && set == -1)
		{
			marksflag = true;
			markslines = 0;
		}

		int set5;//��������ַ���������� ע��    "   //    /*   */          " //  "//"
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
		cout << "������Ϊ: " << count << endl;
		cout << "�ո���Ϊ��" << nullcodeLines << endl;
		cout << "��������Ϊ��" << code << endl;
		cout << "ע����Ϊ: " << zhushi<<endl;
		cout << "�����д����ע����Ϊ��" << commLines<<endl;
		cout << "***************************************************";
		cout << endl;
		cout << "����0���������棬��1�˳���" << endl;
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
	cout << "                     ***         0 ��ʾ�˵�                 ***" << endl;
	cout << "                     ***         1 ֻ��Ϊ�����д���         ***" << endl;
	cout << "                     ***         2 �����к�ע���и�����һ�� ***" << endl;
	cout << "                     ***         3 ֻ��Ϊע���д���         ***" << endl;
	cout << "                     ******************************************" << endl;
	cout << "                     ����������Ҫ�Ĳ�����";
	cin >> a;
	switch (a)
	{
	case 0: pro.MenuMain(); break;
	case 1:
	{
			  system("cls");
			  cout << "�Ѿ����óɹ���" << endl;
			  cout << "׼�����д���ͳ�ƣ�" << endl;
			  pro.MenuOpenFile(a);
			  break;
	}
	case 2: 
	{
			  system("cls");
			  cout << "�Ѿ����óɹ���" << endl;
			  cout << "׼�����д���ͳ�ƣ�" << endl;
			  pro.MenuOpenFile(a);
			  break;
	}
	case 3: 
	{
				system("cls");
				cout << "�Ѿ����óɹ���" << endl;
				cout << "׼�����д���ͳ�ƣ�" << endl;
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
	char path[100] = "D:\\c++\\��־�ļ�\\logfile.txt";
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
		file << "�������˵�\n";
		
		break;

	case 1:
		strftime(tmp, sizeof(tmp), "%Y/%m/%d %X %A", localtime(&t));
		file << tmp << endl;
		file << "�鿴����־�ļ�\n";
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
		file << "ִ�д��ļ�\n";
		
		break;
	case 3:
		strftime(tmp, sizeof(tmp), "%Y/%m/%d %X %A", localtime(&t));
		file << tmp << endl;
		file << "����������\n";
		
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
	cout << "                     ***             0 ��ʾ�˵�             ***" << endl;
	cout << "                     ***             1 ��־�鿴             ***" << endl;
	cout << "                     ***             2 ���ļ�             ***" << endl;
	cout << "                     ***             3 ����                 ***" << endl;
	cout << "                     ***             4 ����                 ***" << endl;
	cout << "                     ***             5 �˳�                 ***" << endl;
	cout << "                     ******************************************" << endl;
	cout << "                     ����������Ҫ�Ĳ�����";
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
	cout << "                     ***             0 ��ʾ�˵�             ***" << endl;
	cout << "                     ***             1 ��־�鿴             ***" << endl;
	cout << "                     ***             2 ���ļ�             ***" << endl;
	cout << "                     ***             3 ����                 ***" << endl;
	cout << "                     ***             4 ����                 ***" << endl;
	cout << "                     ***             5 �˳�                 ***" << endl;
	cout << "                     ******************************************" << endl;
	cout << "                     ����������Ҫ�Ĳ�����";
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


