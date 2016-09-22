#if 0
#include<iostream>
#include<stack>
using namespace std;
typedef struct BitNode
{
	char data;
	BitNode *lchild, *rchild;
}*BitTree;
void CreateBitTree(BitNode **root)
{
	char ch;
	cin >> ch;
	if (ch != '*')
	{
		*root = (BitNode *)malloc(sizeof(BitNode));
		(*root)->data = ch;
		cout << "���������ӣ�" << endl;
		CreateBitTree(&(*root)->lchild);
		cout << "�������Һ��ӣ�" << endl;
		CreateBitTree(&(*root)->rchild);
	}
	else
	{
		*root = NULL;
	}
}
void PreOrder(BitNode *root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		cout << root->data << " ";
		PreOrder(root->lchild);
		PreOrder(root->rchild);
	}
	cout << endl;
}
void PreOrderNR(BitTree T)
{
	if (T == NULL)
	{
		return;
	}
	stack<BitTree>s;
	s.push(T);
	BitTree temp;
	while (!s.empty())
	{
		temp = s.top();
		cout << temp->data << " ";
		s.pop();
		if (temp->rchild)
		{
			s.push(temp->rchild);
		}
		if (temp->lchild)
		{
			s.push(temp->lchild);
		}
	}
}
void InOrder(BitNode *root)
{
	
	if (root == NULL)
	{
		return;
	}
	else
	{
		InOrder(root->lchild);
		cout << root->data << " " ;
		InOrder(root->rchild);
	}
	cout << endl;
}
void InOrderNR(BitTree T)
{
	if (T == NULL)
	{
		return;
	}
	stack<BitTree> s;
	BitTree Curr = T->lchild;
	s.push(T);
	while (Curr || !s.empty())
	{
		while (Curr)
		{
			s.push(Curr);
			Curr = Curr->lchild;
		}
		Curr = s.top();
		s.pop();
		cout << Curr->data << " ";
		Curr = Curr->rchild;
	}
}
void PostOrder(BitNode *root)
{
	
	if (root == NULL)
	{
		return;
	}
	else
	{
		cout << root->data << " " ;
		PostOrder(root->lchild);
		PostOrder(root->rchild);
	}
	cout << endl;
}
void PostOrderNR(BitTree T)
{
	if (T == NULL)
	{
		return;
	}
	stack<BitTree>s1, s2;
	BitTree Curr;
	s1.push(T);
	while (!s1.empty())
	{
		Curr = s1.top();
		s1.pop();
		s2.push(Curr);
		if (Curr->lchild)
			s1.push(Curr->lchild);
		if (Curr->rchild)
			s2.push(Curr->rchild);
	}
}
int CountDepth(BitNode *root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		int Dp1 = CountDepth(root->lchild);
		int Dp2 = CountDepth(root->rchild);
		return (Dp1 > Dp2?Dp1:Dp2) + 1;
	}
}
int CountNode(BitNode *root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + CountNode(root->lchild) + CountNode(root->rchild);
	}
}
int main()
{
	BitNode *root = NULL;
	cout << "������������ĸ��ڵ㣡" << endl;
	CreateBitTree(&root);
	cout << "���������" << endl;
	PreOrder(root);
	cout << "�ǵݹ����������" << endl;
	PreOrderNR(root);
	cout << "���������" << endl;
	InOrder(root);
	cout << "�ǵݹ����������" << endl;
	InOrderNR(root);
	cout << "���������" << endl;
	PostOrder(root);
	cout << "�ǵݹ���������" << endl;
	PostOrderNR(root);
	cout << "�����Ķ�Ϊ" << CountDepth(root) <<"!"<< endl;
	cout << "������" << CountNode(root) <<"���ڵ�"<< endl;
	return 0;
}
#endif
