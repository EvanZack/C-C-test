#include<stdio.h>
#include<windows.h>
#include<iostream>
#include<string>
#include<wchar.h>
using namespace std;

//���߳�����
#if 0
DWORD WINAPI Thread1(LPVOID PM)
{
	printf("���̵߳��̺߳�Ϊ%d", GetCurrentThreadId());
	wchar_t* path="haha";
	LPWSTR Pathload = (LPWSTR)path;
	PlaySound(Pathload, NULL, SND_FILENAME | SND_ASYNC);
	printf("\n");
	return 0;
}
int main()
{
	HANDLE handle = CreateThread(NULL, 0, Thread1, NULL, 0, NULL);
	WaitForSingleObject(handle, INFINITE);
	return 0;
}
#endif
//��дһ�����򣬿���3���̣߳���3���̵߳�ID�ֱ�ΪA��B��C��
//ÿ���߳̽��Լ���ID����Ļ�ϴ�ӡ10�飬
//Ҫ�����������밴ABC��˳����ʾ���磺ABCABC��.���ε��ơ�
/*
HANDLE HeventA = CreateEvent(NULL, FALSE, FALSE, NULL);
HANDLE HeventB = CreateEvent(NULL, FALSE, FALSE, NULL);
HANDLE HeventC = CreateEvent(NULL, FALSE, FALSE, NULL);
DWORD WINAPI ThrPro1(LPVOID lpParameter)
{
	for (int i = 0; i < 10; i++)
	{
		WaitForSingleObject(HeventA, INFINITE);
		printf("A\n");
        SetEvent(HeventB);
	}
	
	return 0;
}
DWORD WINAPI ThrPro2(LPVOID lpParameter)
{
	for (int i = 0; i < 10; i++)
	{
		WaitForSingleObject(HeventB, INFINITE);
		printf("B\n");
        SetEvent(HeventC);
	}
	
	return 0;
}
DWORD WINAPI ThrPro3(LPVOID lpParameter)
{
	for (int i = 0; i < 10; i++)
	{
		WaitForSingleObject(HeventC, INFINITE);
		printf("C\n");
		SetEvent(HeventA);
	}
	
	return 0;
}
int main()
{
	HANDLE handle[3];
	handle[0] = CreateThread(NULL, 0, ThrPro1, NULL, 0, NULL);
	handle[1] = CreateThread(NULL, 0, ThrPro2, NULL, 0, NULL);
	handle[2] = CreateThread(NULL, 0, ThrPro3, NULL, 0, NULL);
	SetEvent(HeventA);
	WaitForMultipleObjects(3, handle, TRUE, INFINITE);
	for (int i=0; i < 3; i++)
	{
		CloseHandle(handle[i]);
	}
	CloseHandle(HeventA);
	CloseHandle(HeventB);
	CloseHandle(HeventC);
	printf("\n");
	return 0;
}
*/
#if 0
class A
{
	int i;
	//���ڴ����,�����������������Ͷ��룻
	//union U
	//{
	//	char buff[13];
	//	int i;
	//}u;
	union U
	{
		char buff[17];
		double i;
	}u;
public:
	void foo()
	{
		cout << sizeof(u) << endl;
	}
	typedef char*(*f)(void*);
	
	enum{ red, blue, green }color;
}a;

int main()
{
	//char a='96';
	//printf("%d", sizeof(a));
	/*
	//const����
	char a[] = "hello";
	char b[] = "world";
	const char* p1 = a;
	char* const p2 = b;
	//p1[2] = 'w';����
	p2[2] = 'l';
	cout<<"NUM1 "<< p1++ << endl;
	cout << "NUM2 " << p2 << endl;
	*/
	//cout << "NUM3 " << p2++ << endl;����
	//a.foo();
	cout << sizeof(a) << endl;

}
#endif
#if 0
//�ٽ���ʵ�ֶ��̣߳�CRITICAL_SECTION��(�ؼ���)
volatile long g_nloginCount;//��½����
unsigned int _stdcall Fun(void* pPM);//�̺߳���
const DWORD TREAD_NUM = 50;//�����߳���
CRITICAL_SECTION gCsCount;
DWORD WINAPI ThreadFun(void *pPM)
{
	Sleep(100);
	//�����ٽ���
	EnterCriticalSection(&gCsCount);
	g_nloginCount++;
	//�뿪�ٽ���
	LeaveCriticalSection(&gCsCount);
	Sleep(50);
	return 0;
}
int main()
{	
	
	int num = 20;
	InitializeCriticalSection(&gCsCount);
	printf("ԭ�Ӳ���interlocked����ϵ�в�����ʹ�ã�\n");
	//�ظ����Ա�۲���̷߳���ͬһ��Դʱ�����µĳ�ͻ	
	
	while (num--)
	{
		g_nloginCount = 0;
		int i;
		HANDLE handle[TREAD_NUM];
		for (i = 0; i < TREAD_NUM; i++)
		{
			handle[i] = CreateThread(NULL, 0, ThreadFun, NULL, 0, NULL);
		}
		WaitForMultipleObjects(TREAD_NUM, handle, TRUE, INFINITE);
		printf("��%d���û���¼���¼���Ϊ%d\n", TREAD_NUM, g_nloginCount);
	}
	DeleteCriticalSection(&gCsCount);
	return 0;
}
#endif
#if 0
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
	//int m = 0256, n = 256;
	//printf("%o %o\n", m, n);
	int x = 2014;
	int n = fun(x);
	cout << n << endl;
}

#endif
#if 0
void func(char str_arg[100])
{
	cout << sizeof(str_arg) << endl;
}
int main(int argc, char* argv[])
{
	char str[] = "Hello";
	char *p = str;
	cout << sizeof(str) << endl;
	cout << sizeof(p) << endl;
	func("test");
	return 0;
}
#endif
