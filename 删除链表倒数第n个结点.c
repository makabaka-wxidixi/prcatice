//删除链表倒数第n个结点
#include<stdio.h>
#include<stdlib.h>
typedef struct listnode {
	int val;
	struct listnode* next;
}listnode;
listnode* initlist(int count)//尾插法
{
	listnode* head = (listnode*)malloc(sizeof(listnode));
	if (head == NULL)
	{
		perror("initlist head");
		return NULL;
	}
	head->next = NULL;
	listnode* rear = head;
	while (count--)
	{
		listnode* p = (listnode*)malloc(sizeof(listnode));
		if (p == NULL)
		{
			perror("initlist p");
			return NULL;
		}
		p->next = NULL;
		printf("请输入值:");
		scanf("%d", &(p->val));
		rear->next = p;
		rear = p;
	}
	return head->next;
}

listnode* movenode(listnode* head, int n)
{
	listnode* prev = (listnode*)malloc(sizeof(listnode));
	if (prev == NULL)
	{
		perror("movenode prev");
		return NULL;
	}
	prev->next = head;
	prev->val = 0;
	listnode* slow = prev;
	listnode* fast = head;
	for (int i = 0; i < n; i++)//fast往前走n步
	{
		fast = fast->next;
	}
	if (fast == NULL)//移动n个位置之后刚好指向NULL，那就说明要删除的就是首结点
	{
		return head->next;
	}
	while (fast != NULL)//当fast指向NULL时，slow指向的刚好就是要删除结点的前驱
	{
		slow = slow->next;
		fast = fast->next;
	}
	slow->next = slow->next->next;//前驱结点的后继节点直接跳过要删除的节点
	free(prev);
	prev->next = NULL;
	prev = NULL;
	return head;
}
void printlist(listnode* l)
{
	listnode* p = l;
	while (p != NULL)
	{
		printf("%d ", p->val);
		p = p->next;
	}
}
int main()
{
	listnode* L = initlist(6);//建立链表
	L = movenode(L, 4);//删除链表倒数第n个结点
	printlist(L);
	return 0;
}