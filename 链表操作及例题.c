#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode {
	int val;
	struct ListNode* next;
}*List, ListNode;

List head;
List end;

List HeadPush_CreatList(List L,int List_lenth)//头插法是反着的
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
		printf("请输入：\n");
		scanf("%d", &(p->val));
		p->next = L->next;
		L->next = p;
	}
	return L->next;
}

List TailPush_CreatList(List L, int List_lenth)//尾插法是正序
{
	L = (List)malloc(sizeof(ListNode));
	if (L == NULL)
	{
		perror("TailPush_CreatList L");
		return NULL;
	}
	L->next = NULL;
	List tail = L;//尾指针
	List p = NULL;
	while (List_lenth--)
	{
		p = (List)malloc(sizeof(ListNode));
		if (p == NULL)
		{
			perror("TailPush_CreatList p");
			return NULL;
		}
		printf("请输入：");
		scanf("%d", &(p->val));
		p->next = NULL;
		tail->next = p;
		tail = p;
	}
	return L->next;
}

void PrintList(List L)//打印链表
{
	if (L == NULL)	return;
	List p = L;
	while (p != NULL)
	{
		printf("%d ", p->val);
		p = p->next;
	}
}

int Lenth_List(List L)//求链表长度
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

List PosListNode(List L, int pos)//删除结点
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

List PushListNode(List L, int position)//插入结点
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
	printf("输入要插入的信息：\n");
	List curr = (List)malloc(sizeof(ListNode));
	if (curr == NULL)	return NULL;
	scanf("%d", &(curr->val));
	curr->next = rear;
	prev->next = curr;
	return head->next;
}

List FilpList(List L, int position)//向右翻转链表
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

List DestroyList(List L)//销毁链表
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

List ModifyList(List L)//结点信息重新录入
{
	if (L == NULL)	return NULL;
	while (L!=NULL)
	{
		printf("请重新输入：");
		scanf("%d", &(L->val));
		L = L->next;
	}
	return L;
}


struct ListNode* swapPairs(struct ListNode* head) {//交换结点函数1
	if (head == NULL) return NULL;
	struct ListNode* Nhead = head->next;//新的头结点
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

struct ListNode* swapPairs1(struct ListNode* head) {//结点交换函数2
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
	printf("请输入链表L1长度\n");
	scanf("%d", &input);
	L1 = HeadPush_CreatList(L1, input);//头插法是反着的

	printf("请输入链表L2长度\n");
	scanf("%d", &(input));
	L2 = TailPush_CreatList(L2, input);

	
	int len = Lenth_List(L2);
	printf("链表长度%d\n", len);

	printf("输入要删除的结点：");
	scanf("%d", &(input));
	L2 = PosListNode(L2, input);//删除指定结点

	printf("输入要插入的节点位置：");
	scanf("%d", &(input));
	L2 = PushListNode(L2, input);

	printf("向右反转链表，输入要翻转的个数：");
	scanf("%d", &(input));
	L2 = FilpList(L2, input);

	printf("销毁链表：");
	L2 = DestroyList(L2);

	printf("修改链表内容：");
	ModifyList(L1);

	printf("前后两个结点进行交换：\n");
	L2 = swapPairs(L2);
	PrintList(L2);
	printf("前后两个结点进行交换：\n");
	L2 = swapPairs1(L2);
	PrintList(L2);
	PrintList(L1);
	return 0;
}