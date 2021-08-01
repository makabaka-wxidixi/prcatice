#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef struct {
	int weight;//Ȩ��
	int parent, lchild, rchild;//˫�ף����ӣ��Һ����±�
}HTNode, * HuffmanTree;

int* Select(HuffmanTree HT, int n)//��ǰn������СȨ��
{
	int left = 1;
	int right = n;
	int arr[2] = { HT[left].weight,HT[right].weight };
	int ret[2] = { 0 };
	while (left != right)
	{
		if (HT[left].weight <= HT[right].weight)
		{
			if ((HT[left].parent) == 0 && (HT[right].parent) == 0)//�ж���Ч��
			{
				arr[0] = HT[left].weight;
				ret[0] = left;
				if (HT[right].weight <= arr[1])//����µ�ֵС��ԭ����arr[1]���Ž��н���
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
			if ( (HT[left].parent) == 0 && (HT[right].parent) == 0)//�ж���Ч��
			{
				arr[0] = HT[right].weight;
				ret[0] = right;
				if (HT[left].weight <= arr[1])//����µ�ֵС��ԭ����arr[1]���Ž��н���
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
	return ret;//�����±�
}
HuffmanTree CreatHFTree(HuffmanTree HT, int n)//������������
{
	assert(n);
	int m = 2 * n - 1;//�ܽ�����
	HT = (HuffmanTree)malloc(sizeof(HTNode) * (m + 1));
	for (int i = 1; i <= m; i++)//��ʼ��
	{
		HT[i].lchild = 0;
		HT[i].rchild = 0;
		HT[i].parent = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		printf("������Ȩ��\n");
		scanf("%d", &(HT[i].weight));
	}
	for (int i = n + 1; i <= m; i++)
	{
		int* ret = Select(HT, i - 1);//��������СȨ��
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
	printf("����0�˳�\n");
	do
	{
		printf("������Ҫ���ҵĽ���±�\n");
		scanf("%d", &input);
		if (input < 16 && input>0)
		{
			printf("Ȩ�أ�%d\n", HT[input].weight);
			printf("���ڵ��±꣺%d\n", HT[input].parent);
			printf("�����±꣺%d\n", HT[input].lchild);
			printf("�Һ����±꣺%d\n", HT[input].rchild);
		}
		else
			printf("���뷶Χ���ԣ�����������\n");
	}while (input);
}
int main()
{
	HuffmanTree HT = NULL;
	HT = CreatHFTree(HT, 8);//������ڵ��ַ��Ҷ�Ӹ���
	MidOrderHFTree(HT);//�����������ҽ��
	return 0;
}