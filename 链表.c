˳��ջ���壨˳��ջ��
#define MAXSIZE 100
typedef struct stack {
	SElemType* base;//ջ��ָ�루�͵�ַ��
	SElemType* top;//ջ��ָ�루�ߵ�ַ��
	int stacksize;//ջ�����������
}SqStack;
ջ�ĳ�ʼ����˳��ջ��
Status InitStack(SqStack* S)//����һ��ջ//ջ�ĳ�ʼ��
{
	S->base = (SElemType*)malloc(MAXSIZE * sizeof(SElemType));//����Ӧ��ע�⣬base������ջ�д�����ݵ�����
	if (S->base == NULL) return EXIT;//�ڴ����ʧ��
	else
	{
		S->top = S->base;//ջ��ָ�����ջ��ָ��
		S->stacksize = MAXSIZE;//�������
		return OK
	}
}
��ջ�ĳ��ȣ�˳��ջ��
int StackLength(SqStack* S)
{
	return S->top - S->base;//����ջ�ĳ���
}
�ж�ջ�Ƿ�Ϊ�գ�˳��ջ��
Status StackEmpty(SqStack* S)
{
	if (S->top == S->base)
		return true;//ջΪ��
	else
		return false;//ջ��Ϊ��	
}
���˳��ջ��˳��ջ��
Status ClearStack(SqStack* S)
{
	if (S.base)//����Ҫ��֤ջҪ����
	{
		S->top = S->base;//��ջ��ָ���ϵ�ջ��
		return OK;//��ճɹ�
	}
	return EXIT;//���ʧ��
}
˳��ջ��ջ��˳��ջ��
Status Push(SqStack* S, SlemType e)//˳��ջ��ջ
{
	if (S->top - S->base == S->stacksize)//�ж�ջ��
		return error;
	*S->top++ = e;//��ջ����ʼ����ջ����ջ��Ԫ�ظ�ֵ��֮��ջ��ָ��++
	return OK;
}
˳��ջ��ջ��˳��ջ��
Status Pop(SqStack* S, SlemType& e)//˳��ջ��ջ
{
	if (S->top == S->base)
	{
		return error;
	}
	e = *--S->top;//�����ݴ���e�У�������
	return OK;
}
��ջ���壨��ջ��
typedef struct StackNode {//��㶨��
	SElemType data;
	struct StackNode* next;
}StackNode,*LinkStack;
LinkStack S;
��ջ��ʼ������ջ��
void InitStack(LinkStack S)//��ջ��ʼ��
{
	S = NULL;//ָ��ָ���
	return OK;
}
�ж�ջΪ�գ���ջ��
Status StackEmpty(LinkStack S)//�ж���ջ�Ƿ�Ϊ��
{
	if (S == NULL)
		return true;//ջΪ��
	else
		return false;//ջ��Ϊ��
}
��ջ����ջ��
Status Push(LinkStack S, SElemtype e)//��ջ
{
	LinkStack p = (LinkStack*)malloc(sizeof(LinkStack));//����һ���½ڵ�
	if (p == NULL) return error;//�ж��ڴ���Ч��
	p->next = S;//�½ڵ����ջ��
	p->data = e;//Ϊ�½ڵ�������ֵ
	S = p;//�޸�ջ��ָ��
	return OK;
}
��ջ����ջ��
Status Pop(LinkStack S, SElemtype& e)//��ջ
{
	if (S == NULL) return error;//�ж�ջ��
	e = S->data;//��e���洢Ҫɾ������ֵ
	p = S;//��p���洢Ҫɾ�����ĵ�ַ����������ͷŸýڵ㣩
	S = S->next;//ջ��Ԫ��ǰ��
	free(p);//�ͷ�pָ��Ľ��
	return OK;
}