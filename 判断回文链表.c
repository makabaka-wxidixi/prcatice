#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* reversal(struct ListNode* head)
{
    struct ListNode* prev = NULL;//�б�βԪ��ָ��NULL
    struct ListNode* curr = head;
    while (curr)
    {
        struct ListNode* NEXT = curr->next;
        curr->next = prev;
        prev = curr;
        curr = NEXT;
    }
    return prev;//����������ͷ���
}
struct ListNode* Midnode(struct ListNode* head)
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;//�����м���
}
int isPalindrome(struct ListNode* head) {
    struct ListNode* p = head;
    struct ListNode* midnode = Midnode(head);//�ҵ��м���
    struct ListNode* firsthead = reversal(midnode);//��ת��벿�������������µ�ͷ���
    while (p!=NULL)
    {
        if (p->val != firsthead->val)
        {
            midnode->next = reversal(firsthead);
            return 0;
        }
        p = p->next;
        firsthead = firsthead->next;
    }
    midnode->next = reversal(firsthead);
    return 1;
}
struct ListNode* initlist(int count)
{
    int i = 0;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (head == NULL) return NULL;
    head->next = NULL;
    for (i = 0; i < count; i++)
    {
        struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (p == NULL) return NULL;
        p->next = NULL;
        printf("��%d������������ֵ\n",i+1);
        scanf("%d", &(p->val));
        p->next = head->next;
        head->next = p;
    }
    return head->next;
}
int main()
{
    int input = 0;
    printf("������Ҫ����������Ľ����\n");
    scanf("%d", &input);
    struct ListNode* L = initlist(input);
    int ret = isPalindrome(L);
    if (ret == 1)
        printf("�ǻ�������\n");
    else
        printf("���ǻ�������\n");
    return 0;
}