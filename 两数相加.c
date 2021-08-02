struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if(l1==NULL&&l2==NULL)//判断指针有效性
        return NULL;
    struct ListNode* sum=(struct ListNode*)malloc(sizeof(struct ListNode));
    if(sum==NULL)
        return NULL;
    sum->next=NULL;
    struct ListNode*rear=sum;//尾指针
    int carry=0;
    while(l1&&l2)
    {
        int add=l1->val+l2->val;
        struct ListNode*p=(struct ListNode*)malloc(sizeof(struct ListNode));
        if(p==NULL) return NULL;
        p->next=NULL;
        rear->next=p;
        rear=p;
        p->val=(add+carry)%10;
        carry=(l1->val+l2->val+carry)/10;//进位
        l1=l1->next;
        l2=l2->next;
    }
    if(carry==0)
        rear->next=l1?l1:l2;
    else
    {
        while(l1)//l1不为空
        {
            struct ListNode*p=(struct ListNode*)malloc(sizeof(struct ListNode));
            if(p==NULL) return NULL;
            p->next=NULL;
            rear->next=p;
            rear=p;
            p->val=(l1->val+carry)%10;
            carry=(l1->val+carry)/10;
            l1=l1->next;
        }
        while(l2)//l1不为空
        {
            struct ListNode*p=(struct ListNode*)malloc(sizeof(struct ListNode));
            if(p==NULL) return NULL;
            p->next=NULL;
            rear->next=p;
            rear=p;
            p->val=(l2->val+carry)%10;
            carry=(l2->val+carry)/10;
            l2=l2->next;
        }
    }
    if(carry==1)
    {
        struct ListNode*p=(struct ListNode*)malloc(sizeof(struct ListNode));
            if(p==NULL) return NULL;
        p->next=NULL;
        rear->next=p;
        rear=p;
        p->val=1;
    }
    return sum->next;
}