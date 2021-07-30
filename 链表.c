顺序栈定义（顺序栈）
#define MAXSIZE 100
typedef struct stack {
	SElemType* base;//栈底指针（低地址）
	SElemType* top;//栈顶指针（高地址）
	int stacksize;//栈可用最大容量
}SqStack;
栈的初始化（顺序栈）
Status InitStack(SqStack* S)//接收一个栈//栈的初始化
{
	S->base = (SElemType*)malloc(MAXSIZE * sizeof(SElemType));//这里应该注意，base类型是栈中存的数据的类型
	if (S->base == NULL) return EXIT;//内存分配失败
	else
	{
		S->top = S->base;//栈顶指针等于栈底指针
		S->stacksize = MAXSIZE;//最大容量
		return OK
	}
}
求栈的长度（顺序栈）
int StackLength(SqStack* S)
{
	return S->top - S->base;//返回栈的长度
}
判断栈是否为空（顺序栈）
Status StackEmpty(SqStack* S)
{
	if (S->top == S->base)
		return true;//栈为空
	else
		return false;//栈不为空	
}
清空顺序栈（顺序栈）
Status ClearStack(SqStack* S)
{
	if (S.base)//首先要保证栈要存在
	{
		S->top = S->base;//将栈顶指针拖到栈底
		return OK;//清空成功
	}
	return EXIT;//清空失败
}
顺序栈入栈（顺序栈）
Status Push(SqStack* S, SlemType e)//顺序栈入栈
{
	if (S->top - S->base == S->stacksize)//判断栈满
		return error;
	*S->top++ = e;//从栈顶开始进入栈，给栈顶元素赋值，之后栈顶指针++
	return OK;
}
顺序栈出栈（顺序栈）
Status Pop(SqStack* S, SlemType& e)//顺序栈出栈
{
	if (S->top == S->base)
	{
		return error;
	}
	e = *--S->top;//将数据存入e中，并带回
	return OK;
}
链栈定义（链栈）
typedef struct StackNode {//结点定义
	SElemType data;
	struct StackNode* next;
}StackNode,*LinkStack;
LinkStack S;
链栈初始化（链栈）
void InitStack(LinkStack S)//链栈初始化
{
	S = NULL;//指针指向空
	return OK;
}
判断栈为空（链栈）
Status StackEmpty(LinkStack S)//判断链栈是否为空
{
	if (S == NULL)
		return true;//栈为空
	else
		return false;//栈不为空
}
入栈（链栈）
Status Push(LinkStack S, SElemtype e)//入栈
{
	LinkStack p = (LinkStack*)malloc(sizeof(LinkStack));//建立一个新节点
	if (p == NULL) return error;//判断内存有效性
	p->next = S;//新节点插入栈顶
	p->data = e;//为新节点数据域赋值
	S = p;//修改栈顶指针
	return OK;
}
出栈（链栈）
Status Pop(LinkStack S, SElemtype& e)//出栈
{
	if (S == NULL) return error;//判断栈空
	e = S->data;//用e来存储要删除结点的值
	p = S;//用p来存储要删除结点的地址（方便后序释放该节点）
	S = S->next;//栈顶元素前移
	free(p);//释放p指向的结点
	return OK;
}