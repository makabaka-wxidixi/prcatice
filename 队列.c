#define MAXSIZE 100//最大队列长度
typedef struct {
	QElemType* base;//初始化的动态存储空间，头元素地址
	int front;	//头下标
	int rear;	//尾下标
}*SqQueue;
Status InitQueue(SqQueue* Q)
{
	Q->base = (QElemType*)malloc(sizeof(QElemType)*MAXSIZE);//申请空间
	if (Q->base == NULL)	return error;//判断内存是否申请成功
	Q->front = Q->rear = 0;//头下标和尾下标都指向0
	return OK;
}
int QueueLength(SqQueue Q)//求循环队列长度
{
	return (Q->rear - Q->front + MAXSIZE) % MAXSIZE;//括号里面加一个MAXSIZE相当于是绝对值，确保是正数
}

Status EnQueue(SqQueue& Q, QElemType e)//循环队列入队
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)//判断队列是否满，这是真满。假满是rear==MAXSIZE
		return error;
	Q->base[Q->rear] = e;//入列从队尾
	Q->rear = (Q->rear + 1) % MAXSIZE;//队尾最下标+1
	return OK;
}

Status DnQueue(SqQueue* Q, QElemType& e)//循环队列出队
{
	if (Q->front == Q->rear)//判断对空，队里面要是没有元素就不用出列
		return error;
	e = Q->base[Q->front];//保存对头元素
	Q->front = (Q->front + 1) % MAXSIZE;//队头指针加1
	return OK;
}

SElemType GetHead(SQueue Q)
{
	if (Q->front == Q->rear)//判断队空
		return errof;
	else
		return Q->base[Q->front];//队头元素出列
}

#define MAXSIZE 100//定义最大长度
typedef struct Qnode//队列结点
{
	QElemType data;
	struct Qnode* next;
}QNode,*QueuePtr;
typedef struct
{
	QueuePtr front;//队头指针，是指向结点的指针
	QueuePtr rear;//队尾指针，是指向结点的指针
}LinkQueue;

Status InitQueue(LinkQueue Q)//链队列初始化
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));//结点用两个指针指向（头结点）
	if (Q.front == NULL)	return error;
	Q.front->next = NULL;//结点指针域置为空
	return OK;
}

Status DestroyQueue(LinkQueue Q)//链表的销毁
{
	while (Q.front)//从头指针开始，依次往后销毁，直至头指针为NULL，证明销毁完了
	{
		QueuePtr P = Q.front->next;//存下一个结点地址
		free(Q.front);//销毁该节点
		Q.front = p;//头指针指向下一节点
		//或者这三步中的p可以用rear来代替
	}
	return OK;
}

Status EnQueue(LinkQueue Q, QElemType e)//链表入队
{
	QNode* p = (QueuePtr)malloc(sizeof(QNode));//建立一个新节点
	if (p == NULL) return error;//判断内存是否分配成功
	p->next = NULL;//指针域指向空
	p->data = e;//数据域放入数据
	Q.rear->next = p;//接入尾结点
	Q.rear = p;//尾指针指向新的节点
	return OK;
}
Status DeQueue(LinkQueue Q, QElemType& e)//出队
{
	if (Q.front == Q.rear)	return error;//判断队是否为空
	p = Q.front->next;//先存入要删除的节点（front是头结点）
	e = p->data;//将元素存入e中；
	Q.front->next = p->next;
	if (Q.rear == p)//当删除的结点刚好是尾结点的话，那么还需要将尾结点进行移动
		Q.rear = Q.front;//删除对后一个元素之后，首尾结点指向一个位置，都指向头结点
	free(p);
	return OK;
}