#include<iostream>
#include<ctime>
using namespace std;
#define NUM 10
class Sort
{
public:
	void InsertSort(int a[], int n);
	void printArr(int a[], int n);
	void BubbleSort(int a[], int n);
	void BubbleSortPlus(int a[], int n);
	void QuickSort(int a[], int right,int left);
	void ShellSort(int a[], int n);
	void HeapSort(int a[], int n);
	void CreateHeap(int a[], int n);
};
void Sort::InsertSort(int a[], int n)
{
	int i, j;
	int temp;
	for (i = 1; i < n; i++)
	{
		temp = a[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (a[j]>temp)
			{
				a[j + 1] = a[j];
			}
			else
			{
				break;
			}
		}
		a[j + 1] = temp;
	}
}
void Sort::BubbleSort(int a[], int n)
{
	int i, j;
	int temp = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
void Sort::BubbleSortPlus(int a[], int n)
{
	int i, j;
	int temp = 0;
	bool flag;
	for (i = 0; i < n; i++)
	{
		flag = 1;
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flag = 0;
			}
		}
		if (flag)
			break;
	}
}
void Sort::QuickSort(int a[], int left, int right)
{
	if (left < right)
	{
	int X = a[left];
	int i = left;
	int j = right;
	while (i < j)
	{
		while (i < j && X <= a[j])
			--j;
		if (i<j)
		a[i] = a[j];
		while (i < j && X > a[i])
			++i;
		if (i<j)
		a[j] = a[i];
	}
	a[i] = X;
	QuickSort(a, left, i - 1);
	QuickSort(a, i + 1, right);
	}
}
void Sort::ShellSort(int a[], int n)
{
	int i, temp, port;
	port = n >> 1;
	while (port >= 1)
	{
		for (i = 0; (i + port) < n; i++)
		{
			if (a[i]>a[i + port])
			{
				temp = a[i];
				a[i] = a[i + port];
				a[i + port] = temp;
			}
		}
		--port;
	}
}
void Sort::printArr(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " " ;
	}
	cout << endl;
}
void Sort::CreateHeap(int a[], int n)//用于将最大的数放置在树根的位置；
{
	int temp, child, parent;
	for (parent = (n + 1) / 2 - 1; parent >= 0; parent--)
	{
		child = 2 * parent + 1;
		if ((child + 1) < n)
		{
			if (a[child + 1]>a[child])
			{
				child++;
			}
		}
		if (a[parent] < a[child])
		{
			temp = a[parent];
			a[parent] = a[child];
			a[child] = temp;
		}
	}
}
void Sort::HeapSort(int a[], int n)
{
	int i, temp;
	for (i = n - 1; i >= 0; i--){
		//创建堆，使最大的数位于树根
		CreateHeap(a, i);
		//将树根和最后一个节点交换
		temp = a[i];
		a[i] = a[0];
		a[0] = temp;
	}


}
int main()
{
	srand((unsigned)time(NULL));
	int	i;
	int a[NUM];
	for (i = 0; i < NUM; i++)
	{
		a[i] = rand() % 100;
	}
	Sort testS;
	cout << "Before sort!" << endl;
	testS.printArr(a, NUM);
	//testS.InsertSort(a, NUM);
	//testS.BubbleSort(a, NUM);
	//testS.BubbleSortPlus(a, NUM);
	//testS.QuickSort(a, 0, NUM - 1);
	//testS.ShellSort(a, NUM);
	//testS.HeapSort(a, NUM);
	cout << "After sort!" << endl;
	testS.printArr(a, NUM);
	return 0;
}
