//用链表合并有序表
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

typedef struct listnode	//定义结构体
{
	int val;
	struct listnode* next;//指向下一个结构体的指针
}listnode;//重命名

listnode* initlist1(int count)//尾插法
{
	int i = 0;
	listnode* head = (listnode*)malloc(sizeof(listnode));
	if (head == NULL)
	{
		perror("initlist1 head");
		return NULL;
	}
	head->next = NULL;
	listnode* rear = head;//建立尾指针
	for (i = 0; i < count; i++)
	{
		listnode* p = (listnode*)malloc(sizeof(listnode));
		if (p == NULL)
		{
			perror("initlist1 p");
			return NULL;
		}
		p->next = NULL;
		printf("请输入\n");
		scanf("%d", &(p->val));
		rear->next = p;
		rear = p;
	}
	return head;
}


listnode* initlist2(int count)//头插法
{
	int i = 0;
	listnode* head = (listnode*)malloc(sizeof(listnode));
	if (head == NULL)
	{
		perror("head");
		return NULL;
	}
	head->next = NULL;
	for (i = 0; i < count; i++)
	{
		listnode* p = (listnode*)malloc(sizeof(listnode));
		printf("请输入\n");
		scanf("%d", &(p->val));
		p->next = head->next;
		head->next = p;
	}
	return head;
}

void printlist(listnode* l)//打印链表
{
	listnode* p = l->next;
	while (p != NULL)
	{
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");
}

listnode* lascsort(listnode* l1, listnode* l2)//合并升序链表
{
	listnode* l3 = (listnode*)malloc(sizeof(listnode));//建立一个新的头结点
	if (l3 == NULL)
	{
		perror("lascsort l3");
		return NULL;
	}
	l3->next = NULL;
	listnode* p3 = l3;
	listnode* p1 = l1->next;
	listnode* p2 = l2->next;
	while (p1 && p2)
	{
		if (p1->val <= p2->val)
		{
			p3->next = p1;
			p3 = p1;
			p1 = p1->next;
		}
		else
		{
			p3->next = p2;
			p3 = p2;
			p2 = p2->next;
		}
	}
	p3->next = p1 ? p1 : p2;
	free(l1);
	free(l2);
	l1 = NULL;
	l2 = NULL;
	return l3;
}
int main()
{
	//创建链表
	listnode* l3 = NULL;
	listnode* l1 = initlist1(3);//尾插法
	printlist(l1);
	listnode* l2 = initlist2(4);//头插法
	printlist(l2);
	l3 = lascsort(l1, l2);//合并两个链表升序
	printlist(l3);
	return 0;
}