//BF算法
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
		cout << "串匹配错误！" << endl;
	}
	else if (i == -1)
	{
		cout << "没有找到！" << endl;
	}
	else
	{
		cout << "该串在主串的第" << i << "处" << endl;
	}
	return 0;
}
#endif
//KMP算法
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
		//p[k]表示前缀，p[j]表示后缀  
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
		cout << "找到了！" << endl;
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
		cout << "串匹配错误！" << endl;
	}
	else if (i == -1)
	{
		cout << "没有找到！" << endl;
	}
	else
	{
		cout << "该串在主串的第" << i << "处" << endl;
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
		cout << "主串串长度小于子串" << endl;
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
			cout << "该串在主串的第" << i - j  << "处！" << endl;
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
		cout << "主串长度小于子串长度！" << endl;
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
			cout << "该串在主串的第" << i - j << "处！" << endl;
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
	//大小端存储
	//unsigned int a = 0x12345678;
	//printf("%x\n", *((unsigned char*)(&a) + 1) );
	int b = 0x01020304;
	char ch = 'a';
	printf("%d\n", int(&b) - int(&ch));
	return 0;
}
#endif 