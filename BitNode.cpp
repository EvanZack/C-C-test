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
		cout << "请输入左孩子！" << endl;
		CreateBitTree(&(*root)->lchild);
		cout << "请输入右孩子！" << endl;
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
	cout << "请输入二叉树的根节点！" << endl;
	CreateBitTree(&root);
	cout << "先序遍历！" << endl;
	PreOrder(root);
	cout << "非递归先序遍历！" << endl;
	PreOrderNR(root);
	cout << "中序遍历！" << endl;
	InOrder(root);
	cout << "非递归中序遍历！" << endl;
	InOrderNR(root);
	cout << "后序遍历！" << endl;
	PostOrder(root);
	cout << "非递归后序遍历！" << endl;
	PostOrderNR(root);
	cout << "该树的度为" << CountDepth(root) <<"!"<< endl;
	cout << "该树有" << CountNode(root) <<"个节点"<< endl;
	return 0;
}
#endif
