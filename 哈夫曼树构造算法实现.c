#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef struct {
	int weight;//权重
	int parent, lchild, rchild;//双亲，左孩子，右孩子下标
}HTNode, * HuffmanTree;

int* Select(HuffmanTree HT, int n)//找前n个的最小权重
{
	int left = 1;
	int right = n;
	int arr[2] = { HT[left].weight,HT[right].weight };
	int ret[2] = { 0 };
	while (left != right)
	{
		if (HT[left].weight <= HT[right].weight)
		{
			if ((HT[left].parent) == 0 && (HT[right].parent) == 0)//判断有效性
			{
				arr[0] = HT[left].weight;
				ret[0] = left;
				if (HT[right].weight <= arr[1])//如果新的值小于原来的arr[1]，才进行交换
				{
					arr[1] = HT[right].weight;
					ret[1] = right;
				}
				right--;
			}
			else
			{
				if (HT[left].parent != 0)
					left++;
				if (HT[right].parent != 0)
					right--; 
			}
		}
		else
		{
			if ( (HT[left].parent) == 0 && (HT[right].parent) == 0)//判断有效性
			{
				arr[0] = HT[right].weight;
				ret[0] = right;
				if (HT[left].weight <= arr[1])//如果新的值小于原来的arr[1]，才进行交换
				{
					arr[1] = HT[left].weight;
					ret[1] = left;
				}
				left++;
			}
			else 
			{
				if (HT[left].parent != 0)
					left++;
				if (HT[right].parent != 0)
					right--;
			}
			
		}
	}
	return ret;//返回下标
}

int* select_minnum1(HTree HT, int n)//移动指针来找两个最小权
{
	int arr[2] = { 0 };
	int ret[2] = { -1,-1 };
	int m = 2, p = 1, u = 2;
	while (p <= n)
	{
		if (!(HT[p].parent) && m == 2)//父节点为0
		{
			arr[0] = HT[p].weight;
			m--;
		}
		else if (!(HT[p].parent) && m == 1)
		{
			arr[1] = HT[p].weight;
			m--;
		}
		else if (!(HT[p].parent) && m == 0)
		{
			if (HT[p].weight < arr[0] && HT[p].weight < arr[1])//新结点权重小于arr其中一个或多个
			{
				if (arr[0] < arr[1])//arr[0]更小
					arr[1] = HT[p].weight;//对较大值赋值
				else
					arr[0] = HT[p].weight;
			}
			else//比两个数都大或者只比一个小
			{
				if (HT[p].weight < arr[0])
					arr[0] = HT[p].weight;
				else if (HT[p].weight < arr[1])
					arr[1] = HT[p].weight;
				else
					;
			}
		}
		else;
		p++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!(HT[i].parent) && HT[i].weight == arr[0] && ret[0] == -1)
			ret[0] = i;
		else if (!(HT[i].parent) && HT[i].weight == arr[1] && ret[1] == -1)
			ret[1] = i;
		else;
	}
	return ret;
}

HuffmanTree CreatHFTree(HuffmanTree HT, int n)//创建哈夫曼树
{
	assert(n);
	int m = 2 * n - 1;//总结点个数
	HT = (HuffmanTree)malloc(sizeof(HTNode) * (m + 1));
	for (int i = 1; i <= m; i++)//初始化
	{
		HT[i].lchild = 0;
		HT[i].rchild = 0;
		HT[i].parent = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		printf("请输入权重\n");
		scanf("%d", &(HT[i].weight));
	}
	for (int i = n + 1; i <= m; i++)
	{
		int* ret = Select(HT, i - 1);//找两个最小权重
		HT[ret[0]].parent = i;
		HT[ret[1]].parent = i;
		HT[i].lchild = ret[0];
		HT[i].rchild = ret[1];
		HT[i].weight = HT[ret[0]].weight + HT[ret[1]].weight;
	}
	return HT;
}

void MidOrderHFTree(HuffmanTree HT)
{
	int input = 0;
	do
	{
		printf("请输入要查找的结点下标\n");
		scanf("%d", &input);
		if (input < 16 && input>0)
		{
			printf("权重：%d\n", HT[input].weight);
			printf("父节点下标：%d\n", HT[input].parent);
			printf("左孩子下标：%d\n", HT[input].lchild);
			printf("右孩子下标：%d\n", HT[input].rchild);
		}
		else
			printf("输入范围不对，请重新输入\n");
	}while (input);
}
int main()
{
	HuffmanTree HT = NULL;
	HT = CreatHFTree(HT, 8);//输入根节点地址和叶子个数
	MidOrderHFTree(HT);//哈夫曼树查找结点
	return 0;
}