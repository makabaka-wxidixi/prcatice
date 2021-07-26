//������ϲ������
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

typedef struct listnode	//����ṹ��
{
	int val;
	struct listnode* next;//ָ����һ���ṹ���ָ��
}listnode;//������

listnode* initlist1(int count)//β�巨
{
	int i = 0;
	listnode* head = (listnode*)malloc(sizeof(listnode));
	if (head == NULL)
	{
		perror("initlist1 head");
		return NULL;
	}
	head->next = NULL;
	listnode* rear = head;//����βָ��
	for (i = 0; i < count; i++)
	{
		listnode* p = (listnode*)malloc(sizeof(listnode));
		if (p == NULL)
		{
			perror("initlist1 p");
			return NULL;
		}
		p->next = NULL;
		printf("������\n");
		scanf("%d", &(p->val));
		rear->next = p;
		rear = p;
	}
	return head;
}


listnode* initlist2(int count)//ͷ�巨
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
		printf("������\n");
		scanf("%d", &(p->val));
		p->next = head->next;
		head->next = p;
	}
	return head;
}

void printlist(listnode* l)//��ӡ����
{
	listnode* p = l->next;
	while (p != NULL)
	{
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");
}

listnode* lascsort(listnode* l1, listnode* l2)//�ϲ���������
{
	listnode* l3 = (listnode*)malloc(sizeof(listnode));//����һ���µ�ͷ���
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
	//��������
	listnode* l3 = NULL;
	listnode* l1 = initlist1(3);//β�巨
	printlist(l1);
	listnode* l2 = initlist2(4);//ͷ�巨
	printlist(l2);
	l3 = lascsort(l1, l2);//�ϲ�������������
	printlist(l3);
	return 0;
}