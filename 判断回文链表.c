#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* reversal(struct ListNode* head)
{
    struct ListNode* prev = NULL;//列表尾元素指向NULL
    struct ListNode* curr = head;
    while (curr)
    {
        struct ListNode* NEXT = curr->next;
        curr->next = prev;
        prev = curr;
        curr = NEXT;
    }
    return prev;//返回新链表头结点
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
    return slow;//返回中间结点
}
int isPalindrome(struct ListNode* head) {
    struct ListNode* p = head;
    struct ListNode* midnode = Midnode(head);//找到中间结点
    struct ListNode* firsthead = reversal(midnode);//翻转后半部分链表，并返回新的头结点
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
        printf("第%d个结点数据域的值\n",i+1);
        scanf("%d", &(p->val));
        p->next = head->next;
        head->next = p;
    }
    return head->next;
}
int main()
{
    int input = 0;
    printf("请输入要创建的链表的结点数\n");
    scanf("%d", &input);
    struct ListNode* L = initlist(input);
    int ret = isPalindrome(L);
    if (ret == 1)
        printf("是回文链表\n");
    else
        printf("不是回文链表\n");
    return 0;
}