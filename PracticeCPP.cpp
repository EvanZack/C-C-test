#if 0
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
inline void NEXT(const string &T, vector<int>&next)
{
	//按模式串生成vector,next(T.size())
	next[0] = -1;
	for (int i = 1; i<T.size(); i++){
		int j = next[i - 1];
		while (T[i] != T[j + 1] && j >= 0)
			j = next[j];//递推计算
		if (T[i] == T[j + 1])
			next[i] = j + 1;
		else next[i] = 0;//
	}
}
inline string::size_type COUNT_KMP(const string&S,const string&T)
{
	//利用模式串T的next函数求T在主串S中的个数count的KMP算法
	//其中T非空，
	vector<int>next(T.size());
	NEXT(T, next);
	string::size_type index, count = 0;
	for (index = 0; index<S.size(); ++index)
	{
		int pos = 0;
		string::size_type iter = index;
		while (pos<T.size() && iter<S.size())
		{
			if (S[iter] == T[pos]){
				++iter; 
				++pos;
			}
			else{
				if (pos == 0)
					++iter;
				else pos = next[pos - 1] + 1;
			}
		}//whileend
		if (pos == T.size() && (iter - index) == T.size())
			++count;
	}//forend
	return count;

}
int main(int argc, char*argv[])
{
	string S = "acbaabcacabaabcacabaabcacabaabcacabaabcac";
	string T = "abcab";
	string::size_type count = COUNT_KMP(S, T);
	cout << count << endl;
	system("PAUSE");
	return 0;
}
#endif
#if 0
#include<iostream>
#include<string>
using namespace std;
#pragma warning(disable:4996)
int main()
{
	char buffer[20];
	memset(buffer, 0, sizeof(char)* 20);
	strcpy(buffer,"liu");
	cout << buffer << endl;
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
class A
{
public:
	void foo()
	{
		printf("1");
	}
	virtual void fun()
	{
		printf("2");
	}
};
class B : public A
{
public:
	void foo()
	{
		printf("3");
	}
	void fun()
	{
		printf("4");
	}
};
int main(void)
{
	A a;
	B b;
	A *p = &a;
	p->foo();
	p->fun();
	p = &b;
	p->foo();
	p->fun();
	A *ptr = (A *)&b;
	ptr->foo();
		ptr->fun();
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
int main()
{
	int *p = (int*)0x500;
	int *q = (int*)0x518;
	printf("%d\n", q - p);
	return 0;
}
#endif
#if 0
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string IP;
	cout << "输入一个IP" << endl;
	cin >> IP;
	char Ip[15]="\0";
	int i = 0;
	for (; IP[i] != '\0'; i++)
	{
		Ip[i] = IP[i];
	}
	puts(Ip);
	char *tok;
	char sep[] = ".";
	int L = 0;
	char IPS[4];
	for (tok = strtok(Ip, sep); tok != NULL; tok = strtok(NULL, sep))
	{
		strcpy(IPS+L, tok);
		L += 1;
	}
	for (; i < 4; i++)
	{
		cout << IPS[i] << endl;
	}
	
	
	return 0;
}
#endif
//将一个n*n二维数组逆时针旋转45度打印
//print_rotate_matrix(int []matrix,int n);
#if 0
#include<iostream>
using namespace std;
void print_rotate_matrix(int matrix[], int n)
{

}
int *resize(int* a,int N)
{
	return(a);
}
int main()
{
	cout << "请输入一个数组" << endl;
	int N = 1;
	int *a;
	int i=0,num=0;
	while ((cin >> a[i])!='\n')
	{
		
		if (i >= num-1)
		{
			N += 1;
			num = N*N;
			a=resize(a,num);
		}
		;
		if (a[i] == '\n')
			break;
		++i;
			
	}
	for (i = 0; i < N; i++)
	{
		cout << a[i];
	}
	return 0;
}
#endif
#if 1
#include<iostream>
using namespace std;
int main()
{
	char* a;
	char *b,c;
	cout << sizeof(a) << endl;
	cout << sizeof(c) << endl;
	return 0;
}
#endif
//回调函数的使用
#if 0
#include<iostream>
using namespace std;
void printf723(int num)
{
	printf("%d 723", num);
	printf("\n");
}
void printf722(int num)
{
	printf("%d 722",num);
	printf("\n");
}
void callback(int num, void(*print)(int))
{
	int i = 0;
	for (; i < num; i++)
	{
		print(i);
	}
}
int main()
{
	callback(5, printf723);
	callback(5, printf722);
	printf723(5);
}
#endif
#if 0
#include<iostream>
using namespace std;
void quickSort(int a[], int F, int L)
{
	if (F < L)
	{
		int i = F;
		int r = L;
		int X = a[F];
		while (i < r)
		{
			while (i < r&&X <= a[r])
				--r;
			if (i < r)
			   a[i] = a[r];
			while (i < r&&X >a[i])
			   ++i;
			if (i < r)
			  a[r] = a[i];
		}
		
		a[i] = X;
		quickSort(a, F, i-1);
		quickSort(a, i + 1, L);
	}

}
int main()
{
	int n;
	cout << "Please enter the number of numbers" << endl;
	cin >> n;
	int *p = new int(n);
	cout << "Please enter the member of the vector!" << endl;
	int i = 0;
	for (; i < n; i++)
	{
		cin >> p[i];
	}
	cout << "before sort!" << endl;
	for (i = 0; i < n; i++)
	{
		cout << p[i] << " " ;
	}
	cout << endl;
	cout << "after sort" << endl;
	quickSort(p, 0, n-1);
	for (i = 0; i < n; i++)
	{
		cout << p[i] << " " ;
	}
	cout << endl;
	system("pause");
	delete []p; 
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
void BubbleSort(int a[],int n)
{
	int i, j, t;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
}
int main()
{
	int n;
	cout << "Please enter the number of numbers" << endl;
	cin >> n;
	int *p = new int(n);
	cout << "Please enter the member of the vector!" << endl;
	int i = 0;
	for (; i < n; i++)
	{
		cin >> p[i];
	}
	cout << "before sort!" << endl;
	for (i = 0; i < n; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
	cout << "after sort" << endl;
	BubbleSort(p,n);
	for (i = 0; i < n; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
	system("pause");
	delete[]p;
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
typedef struct student
{
	int score;
	char name[20];
	struct student* next;
}stu;
stu* ListCreate()
{
	stu* head=NULL;
	stu *p1=NULL, *p2=NULL;
	p1 = (stu*)malloc(sizeof(student));
	p1->next = NULL;
	//int score;
	char name[20] = "\0";
	if (p1 == NULL)
	{
		cout << "malloc error!" << endl;
	}
	else
	{
		cout << "Please input Student Score，name" << endl;
		cin >> p1->score;
		cin >> p1->name;
	}
	while (p1->score > 0)
	{
		if (head == NULL)
		{
			head = p1;
		}
		else
		{
			p2->next = p1;
		}
		p2 = p1;
		p1 = (stu*)malloc(sizeof(student));
		cout << "Please input next node!" << endl;
		cin >> p1->score;
		cin >> p1->name;
	}
	p2->next = NULL;
	free(p1);
	p1 = NULL;
	return head;
}
void print(stu *head)
{
	stu *p1 = head;
	while (p1 != NULL)
	{
		cout << p1->name << " " << p1->score << endl;
		p1 = p1->next;
	}

}
stu *ListDel(stu *head, char *name)
{
	stu *p1;
	stu *p2=NULL;
	if (head == NULL)
	{
		cout << "This list node is NULL!Delete fail!" << endl;
		return head;
	}
	p1 = head;
	while (strcmp(p1->name, name) == 1 && p1 != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (strcmp(p1->name, name) == 0)
	{
		if (p1 == head)
		{
			head = p1->next;
		}
		else
		{
			p2->next = p1->next;
		}
		free(p1);
		p1 = NULL;
		cout << "Delete Success" << endl;
	}
	else
	{
		cout << "Node not found" << endl;
	}
	return head;
}
stu *insertList(stu *head, char *name, stu *node)
{
	stu *p1=NULL;
	if (head == NULL)
	{
		head = node;
		node->next = NULL;
		return head;
	}
	p1 = head;
	while (strcmp(p1->name, name) == 1 && p1 != NULL)
	{
		p1 = p1->next;
	}
	if (strcmp(p1->name, name) == 0)
	{
		node->next = p1->next;
		p1->next = node;
	}
	else
	{
		cout << "Node not found!" << endl;
	}
	return head;
}
stu *reverse(stu *head)
{
	stu *p1,*p2,*rem;
	p1 = NULL;
	p2 = head;
	while (p2 != NULL)
	{
		rem = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = rem;
	}
	head = p1;
	return head;
}
stu *sort(stu *head)
{
	stu *first,*tail=NULL,*rem_f=NULL,*min,*p;
	first = NULL;
	while (head != NULL)
	{
		for (p = head, min = head; p->next != NULL; p = p->next)
		{
			if (p->next->score < min->score)
			{
				rem_f = p;
				min = p->next;
			}
		}
		if (first == NULL)                    //对新链表的操作
		{
			first = min;
			tail = min;
		}
		else
		{
			tail->next = min;
			tail = tail->next;
		}
		if (head == min)                     //对原始链表的操作
		{
			head = head->next;
		}
		else
		{
			rem_f->next = min->next;
		}
	}
	if (first != NULL)
	{
		tail->next = NULL;
	}
	head = first;
	return head;
}
int main()
{
	stu *head = NULL;
	stu *node;
	char name[20]="\0";
	node = (stu*)malloc(sizeof(student));
	head = ListCreate();
	print(head);
	//char a[20]="\0";
	//cout << "please enter a name that you want to delete!" << endl;
	//cin >> a;
	//ListDel(head, a);
	//print(head);


	//cout << "Please enter a node that you want to insert!" << endl;
	//cin >> node->score;
	//cin >> node->name;
	//cout << "Please enter the place that you want to insert!" << endl;
	//cin >> name;
	//insertList(head, name, node);
	//print(head);
	//free(node);


	cout << "reverse List!" << endl;
	head=reverse(head);
	print(head);

	cout << "Sort by Score!" << endl;
	head = sort(head);
	print(head);
}
#endif
#if 0
#include<iostream>
using namespace std;
class Base { 
public:  
	virtual void f(float x){ cout << "Base::f(float) " << x << endl; }
		 void g(float x){ cout << "Base::g(float) " << x << endl; }   
		 void h(float x){ cout << "Base::h(float) " << x << endl; } 
};
class Derived : public Base { 
public:  
	virtual void f(float x){ cout << "Derived::f(float) " << x << endl; }
	void g(int x){ cout << "Derived::g(int) " << x << endl; }    
	void h(float x){ cout << "Derived::h(float) " << x << endl; } 
};
int main()
{
	Derived test;
	Base * test1 = &test;
	float a = 1.0;
	int b = 10;
	float c = 15;
	test.f(a);
	test.g(b);
	test.h(c);
	test1->f(a);
	test1->g(b);
	test1->h(c);
	return 0;
}
#endif 
#if 0
#include<iostream>
using namespace std;
int main()
{
	/*int arr[] = { 1, 2, 3 };
	double *p = (double*)arr;
	*p = 12.25;
	cout << arr[0] << " "
		 << arr[1] << " "
		 << arr[2] << endl;*/

	int a = 50;
	//float f = a;
	//00 00 00 32
	//32 00 00 00
	/*float* f = (float*)&a;
	cout << f << endl;*/
	char* p = (char*)&a;                  //0 48 1 49 2 50
	cout << *p << endl;
	return 0;
}
#endif
#if 0
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	cin >> str;
	cout << str << endl;
	cin.get();
	cout << str << endl;
	//cin.getline();
	::getline(cin, str, '#');
	cout << str << endl;
	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;

struct Test1
{
	char c1;
	double d;
	int i;
	char str[14];
	char c2;
	float f;
	char c3;
};

int main()
{ 
	/*int a = 0x31323334;
	char* pC = (char*)&a;
	cout << *pC << endl;
	return 0;*/

	cout << sizeof(Test1) << endl;
	
}
#endif
//循环单链表实现约瑟夫环
#if 0
#include<iostream>
using namespace std;
static int NUMBER = 0;
typedef struct Node
{
	int num;
	Node *next;
}node;
void Josephus(int n, int k, int m)
{
	node *p, *r, *curr;
	p = (node*)malloc(sizeof(Nod
		e));
	p->num = 0;
	p->next = p;
	curr = p;
	for (int i = 1; i < n; i++)
	{
		node *t = (node*)malloc(sizeof(Node));
		t->num = i;
		t->next = curr->next;
		curr->next = t;
		curr = t;
	}
	r = curr;
	while (k--)
	{
		r = p;
		p = p->next;
	}
	while (n--)
	{
		for (int s = m - 1; s--; r = p, p = p->next);
		r->next = p->next;
		cout << "Delete Node" << ++NUMBER << "  " << p->num << endl;
		free(p);
		p = r->next;
	}
}
int main()
{
	Josephus(50, 3, 5);
	return 0;
}
#endif
//string类的运算符重载
#if 0
#include<iostream>
#include<cassert>
#include<string>
using namespace std;
#pragma warning(disable:4996)
class String
{
public:
	String();
	String(const String &str);
	String(const char *str);
	~String();
	String& operator =(const String& str);
	String& operator =(const char* str);
	String& operator +(const String& str);
	String& operator +(const char* str);
	String& operator +=(const String& str);
	String& operator +=(const char* str);
	friend ostream& operator <<(ostream& os, const String& str);
	friend istream& operator >>(istream& is, String& str);

private:
	int _size;
	char *_string;
};
String::String() :_size(1)
{
	_string = new char(_size);
	_string[0] = '\0';
}
String::String(const String &str)
{
	_size = str._size;
	_string = new char(_size);
	strncpy(_string,str._string,_size);
}
String::String(const char *str)
{
	if (str != NULL)
	{
		_size = strlen(str) + 1;
		_string = new char(_size);
		strncpy(_string, str, _size);
	}
	else
	{
		_string = new char(1);
		_string[0] = '\0';
	}
}
String::String()
{
	delete []_string;
}
String& String::operator=(const String& str)
{

}
int main()
{

	return 0;
}
#endif  
#if 0
#include<iostream>
using namespace std;
class A
{
public:
	void FuncA()
	{
		printf("FuncA called\n");
	}
	virtual void FuncB()
	{
		printf("FuncB called\n");
	}
};
class B : public A
{
public:
	void FuncA()
	{
		A::FuncA();
		printf("FuncAB called\n");
	}
	virtual void FuncB()
	{
		printf("FuncBB called\n");
	}
};
void main(void)
{
	B  b;
	A  *pa;
	pa = &b;
	A *pa2 = new A;
	pa->FuncA(); 
		pa->FuncB(); 
		pa2->FuncA(); 
		pa2->FuncB();
	delete pa2;
}
#endif

#if 0
#include<iostream>
using namespace std;
#pragma warning(disable:4996)
int FindSubString(char* pch)
{
	int   count = 0;
	char  * p1 = pch;
	while (*p1 != '\0')
	{
		if (*p1 == p1[1] - 1)
		{
			p1++;
			count++;
		}
		else  {
			break;
		}
	}
	int count2 = count;
	while (*p1 != '\0')
	{
		if (*p1 == p1[1] + 1)
		{
			p1++;
			count2--;
		}
		else  {
			break;
		}
	}
	if (count2 == 0)
		return(count);
	return(0);
}
void ModifyString(char* pText)
{
	char  * p1 = pText;
	char  * p2 = p1;
	while (*p1 != '\0')
	{
		int count = FindSubString(p1);
		if (count > 0)
		{
			*p2++ = *p1;
			sprintf(p2, "%i", count);
			while (*p2 != '\0')
			{
				p2++;
			}
			p1 += count + count + 1;
		}
		else  {
			*p2++ = *p1++;
		}
	}
}
void main(void)
{
	char text[32] = "XYBCDCBABABA";
	ModifyString(text);
	printf(text);
}
#endif
#if 0
#include<iostream>
using namespace std;
char *myString()
{
	char buffer[6] = { 0 };
	char *s = "Hello World!";
	for (int i = 0; i < sizeof(buffer)-1; i++)
	{
		buffer[i] = *(s + i);
	}
	//buffer[5] = '\0';
	printf("%s\n", buffer);
	printf("%s\n", s);
	return buffer;
}
int main(int argc, char **argv)
{
	char *s = myString();
	printf("%c\n", *s);
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
int main()
{
	char a[] = "hello";
	a[0] = 'X'; 
	cout << a << endl;
	char *p = "world";      //常量字符串，指针无法修改
	p[0] = 'X';            
	cout << p << endl; 
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
char *GetString2(void) 
{ 
	char p[] = "hello world"; 
	return p; 
}
void main(void) 
{ 
	char *str = NULL;  
	str = GetString2();  
	cout << str << endl; 
}
#endif
#if 0
#include<iostream>
#include<vector>
using namespace std;
int BinSearch(vector<int>a, int key, int n)
{
	int low = 0;
	int high = n - 1;
	int mid;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (a[mid] == key)
			return mid;
		else if (a[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}
int main()
{
	vector<int>a{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int num = BinSearch(a, 6, 9);
	cout << "该数是数组中第" << num << "个数！" << endl;
	return 0;
}
#endif 
#if 0
#include<iostream>
using namespace std;
int main()
{
    http://www.tamll.com
	cout << "Good morning!" << endl;
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
typedef struct text
{
	int a, b;
	text* next;
};
int main()
{
	text test1;
	test1.a = 12;
	test1.b = 24;
	text* test2;
	test2->a = 10;
	test2->b = 20;
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
typedef struct student
{
	char name[20];
	int score;
	student* next;
}stu;
stu* Create()
{
	stu* head=NULL;
	stu *p1, *p2;
	p2 = NULL;
	p1 = (stu*)malloc(sizeof(student));
	p1->next = NULL;
	cout << "Please Enter Name And Score!" << endl;
	cin >> p1->name;
	cin >> p1->score;
	while (p1->score >= 0)
	{
		if (head == NULL)
		{
			head = p1;
		}
		else
		{
			p2->next = p1;
		}
		p2 = p1;
		p1 = (stu*)malloc(sizeof(student));
		cout << "Please Enter Next Student!" << endl;
		cin >> p1->name;
		cin >> p1->score;
	}
	p2->next = NULL;
	free(p1);
	p1 = NULL;
	return head;
}
void Print(stu* list)
{
	stu* head;
	head = list;
	while (head != NULL)
	{
		cout << head->name << "  " << head->score << endl;
		head = head->next;
	}
}
stu* Reverse(stu* list)
{
	stu *rem, *p1, *p2;
	p1 = NULL;
	p2 = list;
	rem = NULL;
	while (p2!=NULL)
	{
		rem = p2->next;
		p2->next = p1;
		p1 = p2;
	    p2=rem;
	}
	list = p1;
	return list;
}
int main()
{
	stu* head = NULL;
	head = Create();
	Print(head);
	head = Reverse(head);
	Print(head);
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
typedef struct Stack
{
	int data;
	Stack* next;
};
Stack* initStack()
{
	Stack* top;
	top = (Stack*)malloc(sizeof(Stack));
	top->next = NULL;
	return top;
}
void PushNode(Stack* top, int num)
{
	Stack* node;
	node = (Stack*)malloc(sizeof(Stack));
	if (!node)
	{
		cout << "Node空间申请失败！" << endl;
	}
	node->data = num;
	node->next = top->next;
	top->next = node;
	cout << "新加入元素" << node->data << endl;
}
void PopNode(Stack* top)
{
	Stack* p;
	if (top->next == NULL)
	{
		cout << "栈为空！操作错误！" << endl;
		return;
	}
	p = top->next;
	top->next = p->next;
	cout << "出栈元素为" << p->data << endl;
	free(p);
	p = NULL;
}
int main()
{
	Stack* top;
	top = initStack();
	
	PushNode(top, 1);
	PushNode(top, 2);
	PushNode(top, 3);
	PushNode(top, 4);
	PushNode(top, 5);
	PopNode(top);
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
union test
{
	int a;
	short b;
};
int main()
{
	test t;
	t.a = 0x12345678;
	if (t.b ==0x1234 )
		printf("big_endian");   //Little_endian
	else if (t.b==0x5678)
		printf("little_endian");   //Big_endian
}
# endif 
#if 0
#include<iostream>
using namespace std;
int Strlen(char* a)
{
	//return (sizeof(a));
	int n = strlen(a);
	return n;
}
int main()
{
	char a[] = "hellosadasfafaf";
	//char a[5] = "hello";
	//char a[][] = { "H", "e", "l", "l", "o" };
	int n=Strlen(a);
	//int b[n];
	cout << n << endl;
	return 0;
}
#endif
#if 0
#include<iostream>
#include<string>
using namespace std;
int main()
{
	char str[20] = "abcd12efg34hi5jk6";
	int num[20];
	int i;
	int j = 0;
	int n = strlen(str);
	for (i = 0; i<n; i++)
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			num[j] = str[i] - '0';
			++j;
		}
	}
	return 0;
}
#endif 
#if 0
#include<iostream>
#include<string>
#pragma warning(disable:4996)
using namespace std;
int main()
{
	char *str = new char[100];
	strcpy(str, "hello!");
	delete(str);
	if (str != NULL)
	{
	   cout << "1" << endl;
	}
	
}
#endif
#if 0
#include<iostream>
using namespace std;
#pragma warning(disable:4996)
void mem(char **p, int num)
{
	*p = (char *)malloc(num);
}
int main()
{
	char *p;
	mem(&p, 100);
	strcpy(p,"hello");
	cout << p << endl;
	return 0;
}
#endif 
#if 0
#include<iostream>
#include<vector>
#include<iterator>
using namespace std;
int main()
{
	vector <int> test;
	int num;
	while (cin >> num)
		test.push_back(num);
	copy(test.begin(), test.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}
#endif