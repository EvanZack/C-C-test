//BF�㷨
#if 0
#include<iostream>
#include<string>
using namespace std;
int BF(string Ms, string Ss)
{
	int LenM = Ms.length();
	int LenS = Ss.length();
	int i = 0;
	int j = 0;
	if (LenS > LenM)
	{
		return 0;
	}
	while (i < LenM&&j < LenS)
	{
		if (Ms[i] == Ss[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
		if (j ==LenS)
		{
			return i - LenS;
		}		
	}
	return -1;
}
int main()
{
	string M = "mainabcdabcdafk";
	string S = "fadfafab";
	int i = BF(M, S);
	if (i==0)
	{
		cout << "��ƥ�����" << endl;
	}
	else if (i == -1)
	{
		cout << "û���ҵ���" << endl;
	}
	else
	{
		cout << "�ô��������ĵ�" << i << "��" << endl;
	}
	return 0;
}
#endif
//KMP�㷨
#if 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void Calnext(vector<int> &next,string T)
{
	int pLen = T.length();
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j < pLen - 1)
	{
		//p[k]��ʾǰ׺��p[j]��ʾ��׺  
		if (k == -1 || T[j] == T[k])
		{
			++k;
			++j;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}
int Kmp(string Ms, string Ss)
{
	vector<int>next(Ss.length());
	Calnext(next,Ss);
	int i = 0;
	int j = 0;
	if (Ms.length() < Ss.length())
	{
		return 0;
	}
	while (i< Ms.length()&&j<Ss.length())
	{
		if (j==-1||Ms[i] == Ss[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];
		}
	}
	if (j == Ss.length())
	{
		return i - Ss.length();
		cout << "�ҵ��ˣ�" << endl;
	}
	return -1;
}
int main()
{
	string M = "mainabcdabcdafk";
	string S = "abc";
	int i = Kmp(M, S);
	if (i == 0)
	{
		cout << "��ƥ�����" << endl;
	}
	else if (i == -1)
	{
		cout << "û���ҵ���" << endl;
	}
	else
	{
		cout << "�ô��������ĵ�" << i << "��" << endl;
	}
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
int main()
{
	string s = "asdas";
	char s1[] = "asdsa";
	cout << s.length() << endl;
	cout << sizeof(s) << endl;
	cout << strlen(s1) << endl;
	return 0;
}
#endif 
#if 0
#include<iostream>
#include<string>
using namespace std;
void BF(string s,string temp)
{
	int Length_s = s.length();
	int Length_temp = temp.length();
	int i = 0;
	int j = 0;
	if (Length_s < Length_temp)
	{
		cout << "����������С���Ӵ�" << endl;
	}
	while (i < Length_s&&j < Length_temp)
	{
		if (s[i] == temp[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
		if (j == Length_temp - 1)
		{
			cout << "�ô��������ĵ�" << i - j  << "����" << endl;
		}
	}
}
int main()
{
	string s = "sadadadfdaffafassd";
	string temp = "daff";
	BF(s, temp);
	return 0;
}
#endif
#if 0
#include<iostream>
#include<string>
#include<vector>
using namespace std;
void next(vector<int> &a, string T)
{
	int pos = 2;
	int cn = 0;
	 a[0] = -1;
	 a[1] = 0;
	 while (pos < T.length())
	 {
		 if (T[pos - 1] == T[cn])
		 {
			 a[pos + 1] = ++cn;
		 }
		 else if (cn>0)
		 {
			 cn = a[cn];
		 }
		 else
		 {
			 a[pos++] = 0;
		 }
	 }


}
int Kmp(string S, string T)
{
	vector<int> n(T.length());
	next(n, T);
	int lenS = S.length();
	int lenT = T.length();
	int i = 0;
	int j = 0;
	if (lenS < lenT)
	{
		cout << "��������С���Ӵ����ȣ�" << endl;
	}
	while (i < lenS&&j < lenT)
	{
		if (j==-1||S[i] == T[j])
		{
			++i;
			++j;
		}
		else
		{
			j = n[j];
		}
		if (j == lenT)
		{
			cout << "�ô��������ĵ�" << i - j << "����" << endl;
		}
	}
	return 0;
}
int main()
{
	string s = "agagagadfasfsfaf";
	string t = "gadf";
	Kmp(s, t);
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
int main()
{
	/*char str[] = "abcdefghijklmnopqrstuvwxyz";
	char *pchar = str;
	int *pint = (int*)(str + 4);
	short int *pshort = (short int*)(str + 3);
	printf("%c%c%c\n", *(++pchar), *((char*)(++pint)), *((char*)(++pshort)));*/
	//��С�˴洢
	//unsigned int a = 0x12345678;
	//printf("%x\n", *((unsigned char*)(&a) + 1) );
	int b = 0x01020304;
	char ch = 'a';
	printf("%d\n", int(&b) - int(&ch));
	return 0;
}
#endif 