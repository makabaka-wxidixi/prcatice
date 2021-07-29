//ɾ����������n�����
#include<stdio.h>
#include<stdlib.h>
typedef struct listnode {
	int val;
	struct listnode* next;
}listnode;
listnode* initlist(int count)//β�巨
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
		printf("������ֵ:");
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
	for (int i = 0; i < n; i++)//fast��ǰ��n��
	{
		fast = fast->next;
	}
	if (fast == NULL)//�ƶ�n��λ��֮��պ�ָ��NULL���Ǿ�˵��Ҫɾ���ľ����׽��
	{
		return head->next;
	}
	while (fast != NULL)//��fastָ��NULLʱ��slowָ��ĸպþ���Ҫɾ������ǰ��
	{
		slow = slow->next;
		fast = fast->next;
	}
	slow->next = slow->next->next;//ǰ�����ĺ�̽ڵ�ֱ������Ҫɾ���Ľڵ�
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
	listnode* L = initlist(6);//��������
	L = movenode(L, 4);//ɾ����������n�����
	printlist(L);
	return 0;
}