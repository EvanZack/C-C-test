#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#pragma warning(disable:4996)
#if 0
class Base
{
public:
	Base(int i) { cout << i; }
	~Base() {}
};
class Base1 : virtual public Base
{
public:
	Base1(int i, int j = 0) : Base(j) { cout << i; }
	~Base1() {}
};
class Base2 : virtual public Base
{
public:
	Base2(int i, int j = 0) : Base(j) { cout << i; }
	~Base2() {}
};
class Derived : public Base2, public Base1
{
public:
	Derived(int a, int b, int c, int d) : mem1(a), mem2(b), Base1(c),Base2(d), Base(a)	
	{
		cout << b;
	}
private:
	Base1 mem1;
	Base2 mem2;
};
void main()
{

	Derived objD(1, 2, 3, 4);
}
#endif
#if 0
//重载String类运算符
class String
{
public:
	String();
	String(const char * ch);
	String(const String& str);
	~String();
	int size()const;
	const char *c_str()const;
	String& operator=(const String& str);
	String& operator=(const char* ch);
	const char& operator[](int index)const;
	const bool operator==(const String& str)const;
	const bool operator==(const char* ch)const;
	const String operator+(const String& str);
	const String operator+(const char* ch);
	String& operator+=(const String& str);
	String& operator+=(const char* ch);
	friend ostream& operator << (ostream& os, const String& str);
	friend istream& operator >> (istream& is, String& str);
private:
	int _size;                                //字符串大小
	char* _string;                            //字符串
};
ostream& operator << (ostream& os, const String& str)
{
	os << str._string;
	return os;
}
istream& operator >> (istream& is, String& str)
{
	char strTemp[100];
	int len;
	if (str._string != NULL)
	{
		is >> strTemp;

		len = strlen(strTemp);
		if (len >= str._size)
		{
			delete[] str._string;
			str._string = new char[len + 1];
			str._size = len + 1;
		}

	}
	is >> str._string;
	return is;
}

String::String()                           //有NULL的话后面好多都要判断NULL的情况比较麻烦
:_size(1)
{
	_string = new char[_size];
	_string[0] = '\0';
}
String::String(const char *ch)
{
	if (ch != NULL)                        //指针都得判空
	{
		_size = strlen(ch) + 1;
		_string = new char[_size];
		strcpy_s(_string, _size, ch);                                                                                          
	}
	else
	{
		_size = 1;
		_string = new char[_size];
		_string[0] = '\0';
	}

}
String::String(const String& str)
{
	_size = str._size;
	_string = new char[_size];
	strcpy_s(_string, _size, str._string);
}
String::~String()
{
	//if ()   如果无名构造为NULL的话，就得判断一下                             
	delete[] _string;
}
int String::size(void)const
{
	return _size;
}
const char* String::c_str(void)const
{
	return _string;
}
String& String::operator=(const String& str)
{
	if (this == &str);
	else
	{
		//不用判空，因为创建的时候就没有空的
		delete[] _string;
		_size = str._size;
		_string = new char[_size];
		strcpy_s(_string, _size, str._string);
	}
	return *this;
}
String& String::operator=(const char* ch)
{
	delete[] _string;
	if (ch != NULL)
	{
		_size = strlen(ch) + 1;
		_string = new char[_size];
		strcpy_s(_string, _size, ch);
	}
	else
	{
		//如果赋值给string NULL,那以后不就得判空， 和之前把它设为_size = 1矛盾了
		//string 指向空 ，也就是什么都不放
		_size = 1;
		_string = new char[_size];
		_string[0] = '\0';
	}
	return *this;
}
const char& String::operator[](int index)const  //str[i]
{
	assert(index >= 0 && index < _size - 1);    //如果不用断言用什么？
	return _string[index];
}
const bool String::operator==(const String& str)const
{
	//bool ret;
	//ret = strcmp(_string, str._string);

	return (strcmp(_string, str._string) == 0);
}

const bool String::operator==(const char* ch)const
{
	//bool ret;
	//ret = strcmp(_string, ch);
	if (ch == NULL)
		return false;
	else
		return (strcmp(_string, ch) == 0);
}
const String String::operator+(const String& str)   //   str1 = str1 + str2
{
	String str3;
	delete[] str3._string;
	str3._size = _size + str._size - 1;
	str3._string = new char[str3._size];
	strcpy_s(str3._string, str3._size, _string);
	strcat(str3._string, str._string);
	return str3;          //调复制构造
}
const String String::operator+(const char* ch) //这些都不改变参数和调用的对象，用不用加const
{
	if (ch == NULL)
		return *this;
	String str3;
	delete[] str3._string;
	str3._size = _size + strlen(ch);
	str3._string = new char[str3._size];
	strcpy_s(str3._string, str3._size, _string);
	strcat(str3._string, ch);
	return str3;
}
String& String::operator+=(const String& str)
{
	return *this = *this + str;
}
String& String::operator+=(const char* ch)
{
	return *this = *this + ch;
}
int main()
{
	char *str = NULL;
	char *strr = "xixi";
	String str1("123");
	String str4("hello");
	str1 += str4;
	//	str1 = str1+str;
	//	str1 += strr;
	cout << str1.c_str();
	//	String str2;
	//	String str3(str);

	//	bool b;
	//	b = (str1 == str);
	//	b = (str1 == str1);
	return 0;
}
#endif

/*
class A
{
	int a;
	short b;
	int c;
	char d;
};

class B
{
	double a;
	short c;
	int b;
	char d;
};
int main()
{
	A a;
	B b;
	cout<<sizeof(a);
	cout<<sizeof(b);
}*/
/*
char *myString()
{
	char buffer[6] = { 0 };
	char *s = "Hello World!";
	for (int i = 0; i < sizeof(buffer)-1; i++)
	{
		buffer[i] = *(s + i);
	}
	return buffer;
}
int main(int argc, char **argv)
{
	printf("%s\n", myString());
	return 0;
}*/
/*
int fun(unsigned int x)
{
	int n = 0;
	while ((x + 1))
	{
		n++;
		x = x | (x + 1);
	}
	return n;
}
int main()
{
	int n=fun(2014);
	cout << n;
}*/
/*
void example(char acWelcome[]){
	printf("%d", sizeof(acWelcome));
	return;
}
void main(){
	char acWelcome[] = "Welcome to Huawei Test";
	example(acWelcome);
	return;
}*/
/*
int main()
{
	cout << 2 * 3 * sizeof(1) << endl;
	cout << 3 << (2 < 1);
	cout << endl;
	cout << (unsigned long)(2 - 3) * 1;

}*/
/*
void foobar(int a, int *b, int **c)
{
	int *p = &a;
	*p = 101;
	*c = b;
	b = p;
}

int main()
{
	int a = 1;
	int b = 2;
	int c = 3;
	int *p = &c;
	foobar(a, &b, &p);
	printf("a=%d, b=%d, c=%d, *p=%d\n", a, b, c, *p);
	return (0);
}*/
/*
int main(void)
{
	vector<int>array;
	array.push_back(100);
	array.push_back(300);
	array.push_back(300);
	array.push_back(500);
	vector<int>::iterator itor;
	for (itor = array.begin(); itor != array.end(); itor++)
	{
		if (*itor == 300)
		{
			itor = array.erase(itor);
		}
	}
	for (itor = array.begin(); itor != array.end(); itor++)
	{
		cout << *itor << " ";
	}
	return 0;
}*/
/*
void fun(double *pl, double *p2, double *s)
{
	s = (double*)calloc(1, sizeof(double));
	*s = *pl + *(p2 + 1);
}
int main()
{
	double a[2] = { 1.1, 2.2 }, b[2] = { 10.0, 20.0 }, *s = a;
	fun(a, b, s);
	printf("%5.2f＼n", *s);
}*/
/*
int main()
{
	static char *s[] = { "black", "white", "pink", "violet" };
	char **ptr[] = { s + 3, s + 2, s + 1, s }, ***p;
	p = ptr;
	++p;
	printf("%s", **p + 1);
	return 0;
	}
*/
/*
char *myString()
{
	char buffer[6] = { 0 };
	char *s = "Hello World!";
	for (int i = 0; i < sizeof(buffer)-1; i++)
	{
		buffer[i] = *(s + i);
	}
	return buffer;
}
int main(int argc, char **argv)
{
	printf("%s\n", myString());
	return 0;
}

void main()
{
	const int number = 22;
	//先转为地址，再开始转化
	const int* p = &number;
	int* num = const_cast<int*>(p);
	*num = 21;
}
int f1=0, f2=1, t, i = 1;
class Solution {
public:
	
	
	int Fibonacci(int n) {

		while (true)
		{
			f1 += f2;
			i++;
			if (f1 >= n)
			{
				n = f1;
				break;
			}
			f2 += f1;
			i++;
			if (f2 >= n)
			{
				n = f2;
				break;
			}
		}
		cout << "该数在斐波那契数列的项数是:" << i << endl;
		system("pause");
		return 0;

	}
};
int main()
{
	int n;
	cin>> n;
	Solution test;
	test.Fibonacci(n);
}*/
/*
int main()
{
	int f1, f2, t, i = 1;
	f1 = 0;
	f2 = 1;
	cout << "请输入t:";
	cin >> t;
	while (true)
	{
		f1 += f2;
		i++;
		if (f1 >= t)
		{
			t = f1;
			break;
		}
		f2 += f1;
		i++;
		if (f2 >= t)
		{
			t = f2;
			break;
		}
	}
	cout << "大于等于它的斐波那契数:" << t << "该数在斐波那契数列的项数是:" << i << endl;
	system("pause");
	return 0;
}*/
int main()
{
	string line;
	while (getline(cin, line))
	{
		cout << line << endl;
	}
	return 0;
}