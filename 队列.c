#define MAXSIZE 100//�����г���
typedef struct {
	QElemType* base;//��ʼ���Ķ�̬�洢�ռ䣬ͷԪ�ص�ַ
	int front;	//ͷ�±�
	int rear;	//β�±�
}*SqQueue;
Status InitQueue(SqQueue* Q)
{
	Q->base = (QElemType*)malloc(sizeof(QElemType)*MAXSIZE);//����ռ�
	if (Q->base == NULL)	return error;//�ж��ڴ��Ƿ�����ɹ�
	Q->front = Q->rear = 0;//ͷ�±��β�±궼ָ��0
	return OK;
}
int QueueLength(SqQueue Q)//��ѭ�����г���
{
	return (Q->rear - Q->front + MAXSIZE) % MAXSIZE;//���������һ��MAXSIZE�൱���Ǿ���ֵ��ȷ��������
}

Status EnQueue(SqQueue& Q, QElemType e)//ѭ���������
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)//�ж϶����Ƿ���������������������rear==MAXSIZE
		return error;
	Q->base[Q->rear] = e;//���дӶ�β
	Q->rear = (Q->rear + 1) % MAXSIZE;//��β���±�+1
	return OK;
}

Status DnQueue(SqQueue* Q, QElemType& e)//ѭ�����г���
{
	if (Q->front == Q->rear)//�ж϶Կգ�������Ҫ��û��Ԫ�ؾͲ��ó���
		return error;
	e = Q->base[Q->front];//�����ͷԪ��
	Q->front = (Q->front + 1) % MAXSIZE;//��ͷָ���1
	return OK;
}

SElemType GetHead(SQueue Q)
{
	if (Q->front == Q->rear)//�ж϶ӿ�
		return errof;
	else
		return Q->base[Q->front];//��ͷԪ�س���
}

#define MAXSIZE 100//������󳤶�
typedef struct Qnode//���н��
{
	QElemType data;
	struct Qnode* next;
}QNode,*QueuePtr;
typedef struct
{
	QueuePtr front;//��ͷָ�룬��ָ�����ָ��
	QueuePtr rear;//��βָ�룬��ָ�����ָ��
}LinkQueue;

Status InitQueue(LinkQueue Q)//�����г�ʼ��
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));//���������ָ��ָ��ͷ��㣩
	if (Q.front == NULL)	return error;
	Q.front->next = NULL;//���ָ������Ϊ��
	return OK;
}

Status DestroyQueue(LinkQueue Q)//���������
{
	while (Q.front)//��ͷָ�뿪ʼ�������������٣�ֱ��ͷָ��ΪNULL��֤����������
	{
		QueuePtr P = Q.front->next;//����һ������ַ
		free(Q.front);//���ٸýڵ�
		Q.front = p;//ͷָ��ָ����һ�ڵ�
		//�����������е�p������rear������
	}
	return OK;
}

Status EnQueue(LinkQueue Q, QElemType e)//�������
{
	QNode* p = (QueuePtr)malloc(sizeof(QNode));//����һ���½ڵ�
	if (p == NULL) return error;//�ж��ڴ��Ƿ����ɹ�
	p->next = NULL;//ָ����ָ���
	p->data = e;//�������������
	Q.rear->next = p;//����β���
	Q.rear = p;//βָ��ָ���µĽڵ�
	return OK;
}
Status DeQueue(LinkQueue Q, QElemType& e)//����
{
	if (Q.front == Q.rear)	return error;//�ж϶��Ƿ�Ϊ��
	p = Q.front->next;//�ȴ���Ҫɾ���Ľڵ㣨front��ͷ��㣩
	e = p->data;//��Ԫ�ش���e�У�
	Q.front->next = p->next;
	if (Q.rear == p)//��ɾ���Ľ��պ���β���Ļ�����ô����Ҫ��β�������ƶ�
		Q.rear = Q.front;//ɾ���Ժ�һ��Ԫ��֮����β���ָ��һ��λ�ã���ָ��ͷ���
	free(p);
	return OK;
}