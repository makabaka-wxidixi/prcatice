#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
	char ch;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
}*Tree,TreeNode;

Tree CreatBinaryTree(Tree T)
{
	int input = 0;
	printf("请输入：");
	scanf("%c", &(input));
	getchar();
	if (input == '#')
		return NULL;
	else
	{
		T = (Tree)malloc(sizeof(TreeNode));
		if (T == NULL)	return NULL;
		T->ch = input;
		T->lchild = CreatBinaryTree(T->lchild);
		T->rchild = CreatBinaryTree(T->rchild);
	}
	return T;
}

void PreTraTree(Tree T)
{
	if (T == NULL)
		return;
	else
	{
		printf("%c ", T->ch);
		PreTraTree(T->lchild);
		PreTraTree(T->rchild);
	}
}
void MidTraTree(Tree T)
{
	if (T == NULL)	return;
	else
	{
		MidTraTree(T->lchild);
		printf("%c ", T->ch);
		MidTraTree(T->rchild);
	}
}

void TailTraTree(Tree T)
{
	if (T == NULL)	return;
	else
	{
		TailTraTree(T->lchild);
		TailTraTree(T->rchild);
		printf("%c ", T->ch);
	}
}

void PreTraByStack(Tree T)
{
	if (T == NULL)	return;
	Tree stack[10];
	int stacktop = 0;
	Tree p = T;
	while (stacktop != 0 || p)
	{
		while (p)
		{
			printf("%c ", p->ch);
			stack[stacktop++] = p;
			p = p->lchild;
		}
		if (stacktop != 0)
		{
			p = stack[--stacktop];
			p = p->rchild;
		}
	}
}

void MidTraByStack(Tree T)
{
	if (T == NULL)	return;
	Tree stack[10];
	int stacktop = 0;
	Tree p = T;
	while (stacktop != 0 || p)
	{
		while (p)
		{
			stack[stacktop++] = p;
			p = p->lchild;
		}
		if (stacktop != 0)
		{
			p = stack[--stacktop];
			printf("%c ", p->ch);
			p = p->rchild;
		}
	}
}

void TailTraByStack(Tree T)
{
	if (T == NULL)	return;
	Tree stack[10];
	int stacktop = 0;
	Tree p = T;
	Tree visited = NULL;
	while (p)
	{
		stack[stacktop++] = p;
		p = p->lchild;
	}
	while (stacktop != 0)
	{
		p = stack[--stacktop];
		if (p->rchild == NULL || p->rchild == visited)
		{
			printf("%c ", p->ch);
			visited = p;
		}
		else//第一个visited肯定是由NULL所产生
		{
			stack[stacktop++] = p;
			p = p->rchild;
			while (p)
			{
				stack[stacktop++] = p;
				p = p->rchild;
			}
		}
	}
}

void LevelOrderTree(Tree T)
{
	if (T == NULL)	return;
	Tree Q[10];
	int rear = 0;
	int front = 0;
	Tree p = NULL;
	Q[front] = T;
	front = (front + 1) % 10;
	while (front != rear)
	{
		p = Q[rear];
		rear = (rear + 1) % 10;
		printf("%c ", p->ch);
		if (p->lchild)
		{
			Q[front] = p->lchild;
			front = (front + 1) % 10;
		}
		if (p->rchild)
		{
			Q[front] = p->rchild;
			front = (front + 1) % 10;
		}
	}
}

Tree StraightTree(Tree T)
{
	if (T == NULL)
		return;
	Tree curr = T;
	while (curr != NULL)
	{
		while(curr->lchild != NULL)
		{
			Tree leftNode = curr->lchild;
			while (leftNode->rchild)
			{
				leftNode = leftNode->rchild;
			}
			leftNode->rchild = curr->rchild;
			curr->rchild = curr->lchild;
			curr->lchild = NULL;
		}
		curr = curr->rchild;
	}
	return T;
}

int DeapTree(Tree T)
{
	if (T == NULL)	return 0;
	else
	{
		int m = DeapTree(T->lchild) + 1;
		int n = DeapTree(T->rchild) + 1;
		return m > n ? m : n;
	}
}
int main()
{
	Tree BIT = NULL;
	BIT = CreatBinaryTree(BIT);
	PreTraTree(BIT);
	MidTraTree(BIT);
	TailTraTree(BIT);
	printf("\n");
	PreTraByStack(BIT);
	MidTraByStack(BIT);
	TailTraByStack(BIT);
	printf("\n");
	LevelOrderTree(BIT);
	printf("\n");
	BIT = StraightTree(BIT);
	int deap = DeapTree(BIT);
	printf("深度 %d \n", deap);
	return 0;
}