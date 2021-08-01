#include<stdio.h>
#include<assert.h>
typedef struct TreeNode {//�����
	char data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
 }TreeNode,*Tree;
Tree creatTree(Tree T)//������
{
	char input = 0;
	printf("������\n");
	scanf("%c", &input);
	getchar();//��ȡ�س�
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
void PrevOrderBiTree(Tree T)//�������
{
	if (T == NULL)	
		return NULL;//����
	printf("%c\t", T->data);
	PrevOrderBiTree(T->lchild);
	PrevOrderBiTree(T->rchild);
}
void MidOrderBiTree(Tree T)//�������
{
	if (T == NULL)
		return NULL;//�����Ϊ��
	MidOrderBiTree(T->lchild);
	printf("%c\t", T->data);
	MidOrderBiTree(T->rchild);
}
void LastOrderBiTree(Tree T)//�������
{
	if (T == NULL)
		return NULL;
	LastOrderBiTree(T->lchild);
	LastOrderBiTree(T->rchild);
	printf("%c\t", T->data);
}
void PrevOrderByStack(Tree T)//����ǵݹ����
{
	if (T == NULL)
		return NULL;
	Tree stack[10];//����һ��ջ
	int stacktop = -1;//ջ�����
	Tree pMove = T;
	while (stacktop != -1 || pMove)
	{
		while (pMove)
		{
			printf("%c\t", pMove->data);
			stack[++stacktop] = pMove;//�ý����ջ
			pMove = pMove->lchild;//�ýڵ��������
		}
		if (stacktop != -1)
		{
			pMove = stack[stacktop--];//ָ�뷵����һ���
			pMove = pMove->rchild;//�����Һ���
		}
	}
}
void MidOrderByStack(Tree T)//����ǵݹ����
{
	if (T == NULL)
		return NULL;
	Tree stack[10];//ջ����
	int stacktop = -1;//ջ�����
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
void LastOrderByStack(Tree T)//����ǵݹ����
{
	if (T == NULL)
		return NULL;
	Tree stack[10];
	int stacktop = -1;
	Tree pMove = T;
	Tree plastvisit = NULL;//���ָ��
	while (pMove)
	{
		stack[++stacktop] = pMove;//��ջ
		pMove = pMove->lchild;
	}//@
	while (stacktop != -1)
	{
		pMove = stack[stacktop--];//��ջ
		if (pMove->rchild == NULL || pMove->rchild == plastvisit)//�Һ���Ϊ�գ����߱����ʹ�
		{
			printf("%c\t", pMove->data);
			plastvisit = pMove;
		}
		else//����Һ���û�б����ʹ������Ҳ�Ϊ��
		{
			stack[++stacktop] = pMove;//���ýڵ���ջ
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
	Tree Q[6];//��������
	int front=0;//ͷ����
	int rear=0;//β����
	Q[rear]=T;//��������
	rear=(rear+1)%6;
	while(front!=rear)//�б�Ϊ��
	{
		p=Q[front];
		printf("%c\t",p->val);//��ӡ�����Ϣ
		front=(front+1)%6;//����
		if(p->lchild!=NULL)//�����Ƿ�Ϊ��
		{
			if((rear+1)%6!=front)//����
			{
				Q[rear]=p->lchild;//���
				rear=(rear+1)%6;//β�����һ
			}
		}
		if(p->rchild!=NULL)//�к����Ƿ�Ϊ��
		{
			if((rear+1)%6!=front)//�ж϶����ǲ�������
			{
				Q[rear]=p->rchild;//���
				rear=(rear+1)%6;//β�����һ
			}
		}
	}
}
int main()
{
	Tree T = NULL;//����һ�����ڵ�
	T = creatTree(T);//�������Ĺ���
	PrevOrderBiTree(T);//����ݹ����������
	printf("\n");
	PrevOrderByStack(T);//����ǵݹ����
	printf("\n");
	MidOrderBiTree(T);//�������������
	printf("\n");
	MidOrderByStack(T);//����ǵݹ����
	printf("\n");
	LastOrderBiTree(T);//�������������
	printf("\n");
	LastOrderByStack(T);//����ǵݹ����
	printf("\n"); 
	LeaveOrder(T);//��α���
	return 0;
}