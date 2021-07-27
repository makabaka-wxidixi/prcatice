#include<stdio.h>	
#include<stdlib.h>
#include<assert.h>

typedef struct listnode
{
	int val;
	struct listnode* next;
}listnode;

listnode* initlist1(int count)//头插法
{
	int i = 0;
	listnode* head = (listnode*)malloc(sizeof(listnode));
	if (head == NULL)
	{
		perror("initlist1 head");
		return NULL;
	}
	head->next = NULL;
	for (i = 0; i < count; i++)
	{
		listnode* p = (listnode*)malloc(sizeof(listnode));
		if (p == NULL)
		{
			perror("initlist1 p");
			return NULL;
		}
		p->next = NULL;
		printf("输入第%d个结点的值:", i + 1);
		scanf("%d", &(p->val));
		p->next = head->next;
		head->next = p;
	}
	return head->next;
}

listnode* initlist2(int count)//尾插法
{
	int i = 0;
	listnode* head = (listnode*)malloc(sizeof(listnode));
	if (head == NULL)
	{
		perror("initlist2 head");
		return NULL;
	}
	head->next = NULL;
	listnode* rear = head;
	for (i = 0; i < count; i++)
	{
		listnode* p = (listnode*)malloc(sizeof(listnode));
		if (p == NULL)
		{
			perror("initlist2 p");
			return NULL;
		}
		printf("请输入第%d个结点的数值域:", i + 1);
		scanf("%d", &(p->val));
		p->next = NULL;
		rear->next = p;
		rear = p;
	}
	return head->next;
}
void printlist(listnode* l)//打印链表
{
	listnode* p = l;
	int i = 0;
	while (p != NULL)
	{
		printf("%d ", p->val);
		p = p->next;
	}
}
void glublist(listnode* l1, listnode* l2, int count)
{
	assert(l1 && l2);//断言
	listnode* p1 = l1;
	listnode* p2 = l2;
	while (p1->next != NULL)
		p1 = p1->next;//循环结束后p1是链表尾结点的地址
	while (--count)
		p2 = p2->next;//循环结束后p2第四个节点的地址
	p1->next = p2;//链接链表
}

int is_intersection(listnode* l1, listnode* l2)//判断公共结点，双指针
{
	listnode* p1 = l1;
	listnode* p2 = l2;
	while (p1 != p2)
	{
		if (p1 == NULL)//L1遍历完之后，再在L2上进行遍历
			p1 = l2;
		if (p2 == NULL)//L2遍历完之后，再在L1上进行遍历
			p2 = l1;
		p1 = p1->next;
		p2 = p2->next;
	}
	if (p1 == NULL)
		return 0;//遍历完两个链表后，如果返回值是NULL，就证明没有交点
	else
		return 1;//如果返回值不为NULL，就证明有交点
}

int main()
{
	int ret = 1;
	listnode* l1 = initlist1(3);//头插法
	listnode* l2 = initlist2(7);//尾插法
	printlist(l1);
	printf("\n");
	printlist(l2);
	printf("\n");
	ret = is_intersection(l1, l2);//判断是不是有公共结点
	if (ret == 1)
		printf("before两个链表相交\n");
	else
		printf("before两个链表不相交\n");
	glublist(l1, l2, 4);//把l1最后一个结点与l2第4个结点链接
	ret = is_intersection(l1, l2);//判断是不是有公共结点
	if (ret == 1)
		printf("after两个链表相交\n");
	else
		printf("after两个链表不相交\n");
	return 0;
}