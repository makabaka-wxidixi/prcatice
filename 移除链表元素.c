#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct listnode {//������
	int val;
	struct listnode* next;
}listnode;

listnode* initlist1(int count)//ͷ�巨
{
	int i = 0;
	listnode* head = (listnode*)malloc(sizeof(listnode));//ͷ���
	if (head == NULL)
	{
		perror("initlist1 head");
		return NULL;
	}
	head->next = NULL;
	for (i = 0; i < count; i++)
	{
		listnode* p = (listnode*)malloc(sizeof(listnode));
		printf("L1:������\n");
		scanf("%d", &(p->val));
		p->next = head->next;
		head->next = p;
	}
	return head->next;//���������Ԫ���
}

listnode* initlist2(int count)//β�巨
{
	int i = 0;
	listnode* head = (listnode*)malloc(sizeof(listnode));//����ͷ���
	if (head == NULL)
	{
		perror("initlist2 head");
		return NULL;
	}
	head->next = NULL;
	listnode* rear = head;//βָ��
	for (i = 0; i < count; i++)
	{
		listnode* p = (listnode*)malloc(sizeof(listnode));
		if (p == NULL)
		{
			perror("initlist2 p");
			return NULL;
		}
		p->next = NULL;
		printf("L2:������\n");
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

listnode* removeval(listnode* l, int val)//���������Ԫ���
{
	assert(l);
	listnode* head = (listnode*)malloc(sizeof(listnode));
	if (head == NULL)
	{
		perror("removeval head");
		return l;
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
	listnode* L1 = initlist1(7);//ͷ�巨�ǵ���
	//printlist(L1);
	listnode* L2 = initlist2(7);//β�巨������
	//printlist(L2);
	L1=removeval(L1, 4);
	printlist(L1);
	L2=removeval(L2, 3);
	printlist(L2);
	return 0;
}