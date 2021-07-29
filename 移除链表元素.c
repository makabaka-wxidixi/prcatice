#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct listnode {//定义结点
	int val;
	struct listnode* next;
}listnode;

listnode* initlist1(int count)//头插法
{
	int i = 0;
	listnode* head = (listnode*)malloc(sizeof(listnode));//头结点
	if (head == NULL)
	{
		perror("initlist1 head");
		return NULL;
	}
	head->next = NULL;
	for (i = 0; i < count; i++)
	{
		listnode* p = (listnode*)malloc(sizeof(listnode));
		printf("L1:请输入\n");
		scanf("%d", &(p->val));
		p->next = head->next;
		head->next = p;
	}
	return head->next;//输出的是首元结点
}

listnode* initlist2(int count)//尾插法
{
	int i = 0;
	listnode* head = (listnode*)malloc(sizeof(listnode));//建立头结点
	if (head == NULL)
	{
		perror("initlist2 head");
		return NULL;
	}
	head->next = NULL;
	listnode* rear = head;//尾指针
	for (i = 0; i < count; i++)
	{
		listnode* p = (listnode*)malloc(sizeof(listnode));
		if (p == NULL)
		{
			perror("initlist2 p");
			return NULL;
		}
		p->next = NULL;
		printf("L2:请输入\n");
		scanf("%d", &(p->val));
		rear->next = p;
		rear = p;
	}
	return head->next;
}
void printlist(listnode* l)//
{
	listnode* p = l;
	while (p != NULL)
	{
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");
}

listnode* removeval(listnode* l, int val)//传入的是首元结点
{
	assert(l);
	listnode* head = (listnode*)malloc(sizeof(listnode));
	if (head == NULL)
	{
		perror("removeval head");
		return;
	}
	head->next = l;
	listnode*p=head;
	while (p->next != NULL)
	{
		if (p->next->val == val)
		{
			p->next = p->next->next;
		}
		else
		{
			p = p->next;
		}
	}
	return head->next;
}
int main()
{
	listnode* L1 = initlist1(7);//头插法是倒序
	//printlist(L1);
	listnode* L2 = initlist2(7);//尾插法是正序
	//printlist(L2);
	L1=removeval(L1, 4);
	printlist(L1);
	L2=removeval(L2, 3);
	printlist(L2);
	return 0;
}