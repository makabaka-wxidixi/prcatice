#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef struct TreeNode {//树结点
	char data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
 }TreeNode,*Tree;
Tree creatTree(Tree T)//创建树
{
	char input = 0;
	printf("请输入\n");
	scanf("%c", &input);
	getchar();//读取回车
	if (input == '#')
		return NULL;
	else
	{
		T = (Tree)malloc(sizeof(TreeNode));
		if (T == NULL)
			return NULL;
		T->data = input;
		T->lchild = creatTree(T->lchild);
		T->rchild = creatTree(T->rchild);
	}
	return T;
}
void PrevOrderBiTree(Tree T)//先序遍历
{
	if (T == NULL)	
		return;//空树
	printf("%c\t", T->data);
	PrevOrderBiTree(T->lchild);
	PrevOrderBiTree(T->rchild);
}
void MidOrderBiTree(Tree T)//中序遍历
{
	if (T == NULL)
		return;//树结点为空
	MidOrderBiTree(T->lchild);
	printf("%c\t", T->data);
	MidOrderBiTree(T->rchild);
}
void LastOrderBiTree(Tree T)//后序遍历
{
	if (T == NULL)
		return;
	LastOrderBiTree(T->lchild);
	LastOrderBiTree(T->rchild);
	printf("%c\t", T->data);
}
void PrevOrderByStack(Tree T)//先序非递归遍历
{
	if (T == NULL)
		return;
	Tree stack[10];//定义一个栈
	int stacktop = -1;//栈顶标记
	Tree pMove = T;
	while (stacktop != -1 || pMove)
	{
		while (pMove)
		{
			printf("%c\t", pMove->data);
			stack[++stacktop] = pMove;//该结点入栈
			pMove = pMove->lchild;//该节点访问左孩子
		}
		if (stacktop != -1)
		{
			pMove = stack[stacktop--];//指针返回上一结点
			pMove = pMove->rchild;//访问右孩子
		}
	}
}
void MidOrderByStack(Tree T)//中序非递归遍历
{
	if (T == NULL)
		return;
	Tree stack[10];//栈建立
	int stacktop = -1;//栈顶标记
	Tree pMove = T;
	while (stacktop != -1 || pMove)
	{
		while (pMove)
		{
			stack[++stacktop] = pMove;
			pMove = pMove->lchild;
		}
		if (stacktop != -1)
		{
			pMove = stack[stacktop--];
			printf("%c\t", pMove->data);
			pMove = pMove->rchild;
		}
	}
}
void LastOrderByStack(Tree T)//后序非递归遍历
{
	if (T == NULL)
		return;
	Tree stack[10];
	int stacktop = -1;
	Tree pMove = T;
	Tree plastvisit = NULL;//标记指针
	while (pMove)
	{
		stack[++stacktop] = pMove;//入栈
		pMove = pMove->lchild;
	}//@
	while (stacktop != -1)
	{
		pMove = stack[stacktop--];//出栈
		if (pMove->rchild == NULL || pMove->rchild == plastvisit)//右孩子为空，或者被访问过
		{
			printf("%c\t", pMove->data);
			plastvisit = pMove;
		}
		else//如果右孩子没有被访问过，并且不为空
		{
			stack[++stacktop] = pMove;//将该节点入栈
			pMove = pMove->rchild;
			while (pMove)
			{
				stack[++stacktop] = pMove;
				pMove = pMove->lchild;
			}//@
		}
	}
}
void LeaveOrder(Tree T)
{
	Tree p=NULL;
	Tree Q[6];//创建队列
	int front=0;//头坐标
	int rear=0;//尾坐标
	Q[rear]=T;//根结点入队
	rear=(rear+1)%6;
	while(front!=rear)//列表不为空
	{
		p=Q[front];
		printf("%c\t",p->data);//打印结点信息
		front=(front+1)%6;//出队
		if(p->lchild!=NULL)//左孩子是否为空
		{
			if((rear+1)%6!=front)//判满
			{
				Q[rear]=p->lchild;//入队
				rear=(rear+1)%6;//尾坐标加一
			}
		}
		if(p->rchild!=NULL)//有孩子是否为空
		{
			if((rear+1)%6!=front)//判断队列是不是满了
			{
				Q[rear]=p->rchild;//入队
				rear=(rear+1)%6;//尾坐标加一
			}
		}
	}
}

Tree CopyTree(Tree T)
{
	if (T == NULL)	return NULL;
	Tree C = (Tree)malloc(sizeof(TreeNode));
	if (C == NULL)	return NULL;
	C->data = T->data;
	C->lchild = CopyTree(T->lchild);
	C->rchild = CopyTree(T->rchild);
	return C;
}

int deapTree(Tree T)
{
	if (T == NULL)	return 0;
	else
	{
		int m = deapTree(T->lchild) + 1;
		int n = deapTree(T->rchild) + 1;
		return m > n ? m : n;
	}
}

int NodeCount(Tree T)
{
	if (T == NULL)	return 0;
	else return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}

int LeafCount(Tree T)
{
	if (T == NULL)
		return 0;
	if (T->lchild == NULL && T->rchild == NULL)
		return 1;//左右孩子都是空，就是叶子结点
	else
	{
		return LeafCount(T->lchild) + LeafCount(T->rchild);
	}
}

struct TreeNode* invertTree(struct TreeNode* root) {
	if (root == NULL)  return NULL;
	struct TreeNode* p = NULL;
	p = root->lchild;
	root->lchild = root->rchild;
	root->rchild = p;
	if (root->lchild)
		invertTree(root->lchild);
	if (root->rchild)
		invertTree(root->rchild);
	return root;
}

int main()
{
	int node;//树的结点
	int deap;//树的深度
	int leaf;//树的叶子
	Tree T1 = NULL;//建立一个根节点
	Tree T=NULL;
	T1 = creatTree(T1);//二叉树的构建
	T = CopyTree(T1);//复制树
	leaf = LeafCount(T);
	printf("树的叶子结点：%d\n", leaf);
	node = NodeCount(T);
	printf("树的结点：%d\n", node);
	deap = deapTree(T);
	printf("树的深度：%d\n", deap);
	PrevOrderBiTree(T);//先序递归遍历二叉树
	printf("\n");
	PrevOrderByStack(T);//先序非递归遍历
	printf("\n");
	MidOrderBiTree(T);//中序遍历二叉树
	printf("\n");
	T = invertTree(T);
	MidOrderByStack(T);//中序非递归遍历
	printf("\n");
	LastOrderBiTree(T);//后序遍历二叉树
	printf("\n");
	LastOrderByStack(T);//后序非递归遍历
	printf("\n"); 
	LeaveOrder(T);//层次遍历
	return 0;
}