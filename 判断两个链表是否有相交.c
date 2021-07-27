#include<stdio.h>	
#include<stdlib.h>
#include<assert.h>

typedef struct listnode
{
	int val;
	struct listnode* next;
}listnode;

listnode* initlist1(int count)//ͷ�巨
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
		printf("�����%d������ֵ:", i + 1);
		scanf("%d", &(p->val));
		p->next = head->next;
		head->next = p;
	}
	return head->next;
}

listnode* initlist2(int count)//β�巨
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
		printf("�������%d��������ֵ��:", i + 1);
		scanf("%d", &(p->val));
		p->next = NULL;
		rear->next = p;
		rear = p;
	}
	return head->next;
}
void printlist(listnode* l)//��ӡ����
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
	assert(l1 && l2);//����
	listnode* p1 = l1;
	listnode* p2 = l2;
	while (p1->next != NULL)
		p1 = p1->next;//ѭ��������p1������β���ĵ�ַ
	while (--count)
		p2 = p2->next;//ѭ��������p2���ĸ��ڵ�ĵ�ַ
	p1->next = p2;//��������
}

int is_intersection(listnode* l1, listnode* l2)//�жϹ�����㣬˫ָ��
{
	listnode* p1 = l1;
	listnode* p2 = l2;
	while (p1 != p2)
	{
		if (p1 == NULL)//L1������֮������L2�Ͻ��б���
			p1 = l2;
		if (p2 == NULL)//L2������֮������L1�Ͻ��б���
			p2 = l1;
		p1 = p1->next;
		p2 = p2->next;
	}
	if (p1 == NULL)
		return 0;//����������������������ֵ��NULL����֤��û�н���
	else
		return 1;//�������ֵ��ΪNULL����֤���н���
}

int main()
{
	int ret = 1;
	listnode* l1 = initlist1(3);//ͷ�巨
	listnode* l2 = initlist2(7);//β�巨
	printlist(l1);
	printf("\n");
	printlist(l2);
	printf("\n");
	ret = is_intersection(l1, l2);//�ж��ǲ����й������
	if (ret == 1)
		printf("before���������ཻ\n");
	else
		printf("before���������ཻ\n");
	glublist(l1, l2, 4);//��l1���һ�������l2��4���������
	ret = is_intersection(l1, l2);//�ж��ǲ����й������
	if (ret == 1)
		printf("after���������ཻ\n");
	else
		printf("after���������ཻ\n");
	return 0;
}