#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode {
	int val;
	struct ListNode* next;
}*List, ListNode;

List head;
List end;

List HeadPush_CreatList(List L,int List_lenth)//ͷ�巨�Ƿ��ŵ�
{
	L = (List)malloc(sizeof(ListNode));
	if (L == NULL)
	{
		perror("HeadPush_CreatList L");
		return NULL;
	}
	L->next = NULL;
	List p = NULL;
	while (List_lenth--)
	{
		p = (List)malloc(sizeof(ListNode));
		if (p == NULL)
		{
			perror("HeadPush_CreatList p:");
			return NULL;
		}
		printf("�����룺\n");
		scanf("%d", &(p->val));
		p->next = L->next;
		L->next = p;
	}
	return L->next;
}

List TailPush_CreatList(List L, int List_lenth)//β�巨������
{
	L = (List)malloc(sizeof(ListNode));
	if (L == NULL)
	{
		perror("TailPush_CreatList L");
		return NULL;
	}
	L->next = NULL;
	List tail = L;//βָ��
	List p = NULL;
	while (List_lenth--)
	{
		p = (List)malloc(sizeof(ListNode));
		if (p == NULL)
		{
			perror("TailPush_CreatList p");
			return NULL;
		}
		printf("�����룺");
		scanf("%d", &(p->val));
		p->next = NULL;
		tail->next = p;
		tail = p;
	}
	return L->next;
}

void PrintList(List L)//��ӡ����
{
	if (L == NULL)	return;
	List p = L;
	while (p != NULL)
	{
		printf("%d ", p->val);
		p = p->next;
	}
}

int Lenth_List(List L)//��������
{
	if (L == NULL)	return -1;
	List p = L;
	int len = 0;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

List PosListNode(List L, int pos)//ɾ�����
{
	if (L == NULL)	
		return NULL;
	int lenth = Lenth_List(L);
	if (pos > lenth && pos <= 0)
		return NULL;

	head = (List)malloc(sizeof(ListNode));
	if (head == NULL)	return NULL;
	head->next = L;
	List prev = head;
	List curr = prev->next;
	while (--pos)
	{
		prev = prev->next;
		curr = prev->next;
	}
	prev->next = curr->next;
	free(curr);
	curr->next = NULL;
	curr = NULL;
	return head->next;
}

List PushListNode(List L, int position)//������
{
	if (L == NULL)	return NULL;
	head = (List)malloc(sizeof(ListNode));
	if (head == NULL)	return NULL;
	head->next = L;
	List prev = head;
	List rear = head->next;
	while (--position)
	{
		prev = prev->next;
		rear = rear->next;
	}
	printf("����Ҫ�������Ϣ��\n");
	List curr = (List)malloc(sizeof(ListNode));
	if (curr == NULL)	return NULL;
	scanf("%d", &(curr->val));
	curr->next = rear;
	prev->next = curr;
	return head->next;
}

List FilpList(List L, int position)//���ҷ�ת����
{
	if (L == NULL)	return NULL;
	int ListLenth = Lenth_List(L);
	position = (position) % ListLenth;
	if (position == 0)	return L;
	head = (List)malloc(sizeof(ListNode));
	if (head == NULL)	return NULL;
	head->next = L;

	List prev = head;
	List rear = head;
	while (position--)
	{
		rear = rear->next;
	}
	while (rear->next != NULL)
	{
		prev = prev->next;
		rear = rear->next;
	}
	List p = prev->next;
	prev->next = NULL;
	rear->next = head->next;
	return p;
}

List DestroyList(List L)//��������
{
	if (L == NULL)	return NULL;
	while (L != NULL)
	{
		List curr = L->next;
		free(L);
		L->next = NULL;
		L = NULL;
		L = curr;
	}
	return NULL;
}

List ModifyList(List L)//�����Ϣ����¼��
{
	if (L == NULL)	return NULL;
	while (L!=NULL)
	{
		printf("���������룺");
		scanf("%d", &(L->val));
		L = L->next;
	}
	return L;
}


struct ListNode* swapPairs(struct ListNode* head) {//������㺯��1
	if (head == NULL) return NULL;
	struct ListNode* Nhead = head->next;//�µ�ͷ���
	struct ListNode* ps = head;
	struct ListNode* pf = head->next;
	while (pf != NULL)
	{
		while (pf->next != NULL&& pf->next->next != NULL)
		{
			struct ListNode* p = pf->next;
			pf->next = ps;
			ps->next = p->next;
			ps = p;
			pf = p->next;
		}
		if (pf->next == NULL)
		{
			pf->next = ps;
			ps->next = NULL;
			break;
		}
		else
		{
			struct ListNode* w = pf->next;
			pf->next = ps;
			ps->next = w;
			break;
		}
	}
	if (Nhead == NULL)
		return head;
	else
		return Nhead;
}

struct ListNode* swapPairs1(struct ListNode* head) {//��㽻������2
	if (head == NULL)      return NULL;
	struct ListNode* NewHead = (struct ListNode*)malloc(sizeof(struct ListNode));
	if (NewHead == NULL)   return NULL;
	NewHead->next = head;
	struct ListNode* p = NewHead;
	struct ListNode* m = head;
	struct ListNode* r = head->next;
	while (r != NULL)
	{
		p->next = r;
		m->next = r->next;
		r->next = m;
		if (r->next != NULL && r->next->next != NULL)
		{
			p = m;
			m = p->next;
			r = m->next;
		}
		else
		{
			break;
		}
	}
	return NewHead->next;
}

int main()
{
	List L1 = NULL;
	List L2 = NULL;
	int input = 0;
	printf("����������L1����\n");
	scanf("%d", &input);
	L1 = HeadPush_CreatList(L1, input);//ͷ�巨�Ƿ��ŵ�

	printf("����������L2����\n");
	scanf("%d", &(input));
	L2 = TailPush_CreatList(L2, input);

	
	int len = Lenth_List(L2);
	printf("������%d\n", len);

	printf("����Ҫɾ���Ľ�㣺");
	scanf("%d", &(input));
	L2 = PosListNode(L2, input);//ɾ��ָ�����

	printf("����Ҫ����Ľڵ�λ�ã�");
	scanf("%d", &(input));
	L2 = PushListNode(L2, input);

	printf("���ҷ�ת��������Ҫ��ת�ĸ�����");
	scanf("%d", &(input));
	L2 = FilpList(L2, input);

	printf("��������");
	L2 = DestroyList(L2);

	printf("�޸��������ݣ�");
	ModifyList(L1);

	printf("ǰ�����������н�����\n");
	L2 = swapPairs(L2);
	PrintList(L2);
	printf("ǰ�����������н�����\n");
	L2 = swapPairs1(L2);
	PrintList(L2);
	PrintList(L1);
	return 0;
}