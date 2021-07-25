#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
typedef struct listnode {
	int val;
	struct listnode* next;
}listnode;
listnode* initlist1()
{
	int i = 0;
	listnode* head = (listnode*)malloc(sizeof(listnode));//创建头结点
	if (head == NULL)
	{
		perror("head");
		return 0;
	}
	listnode* temp = head;//定义一个指向头结点的指针，用于遍历链表
	//生成链表
	for (i = 1; i < 4; i ++)
	{
		listnode* p = (listnode*)malloc(sizeof(listnode));
		p->val = i;
		p->next = NULL;
		temp->next = p;
		temp = p;
	}
	return head;
}
listnode* initlist2()
{
	int i = 0;
	listnode* head = (listnode*)malloc(sizeof(listnode));//创建头结点
	if (head == NULL)
	{
		perror("head");
		return 0;
	}
	listnode* temp = head;//定义一个指向头结点的指针，用于遍历链表
	//生成链表
	for (i = 0; i < 5; i++)
	{
		listnode* p = (listnode*)malloc(sizeof(listnode));
		p->val = i;
		p->next = NULL;
		temp->next = p;
		temp = p;
	}
	return head;
}
void lascsort(listnode* l1, listnode* l2)
{
	assert(l1 && l2);
	listnode* l3 = (listnode*)malloc(sizeof(listnode));
	listnode* p1 = l1->next;
	listnode* p2 = l2->next;
	listnode* p3 = l3 = l1;
	while (p1 && p2)
	{
		if (p1->val < p2->val)
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
	free(l2);
	l2 = NULL;
}
int main()
{
	//创建链表
	listnode* l1 = initlist1();
	listnode* l2 = initlist2();
	lascsort(l1, l1);//合并两个链表升序
	return 0;
}