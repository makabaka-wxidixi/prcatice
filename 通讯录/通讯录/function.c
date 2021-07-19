#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"funtion.h"

enum type
{
	name = 1, 
	age,
	tele,
	address,
	sex
};

static int search_people(const struct contact*pcon, char *name)//找人函数，找到返回下标，找不到返回-1
{
	int i = 0;
	for (i = 0; i < pcon->size; i++)
	{
		if (0 == strcmp(pcon->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}
void Addcontact(struct contact* pcon)
{
	if ((pcon->size) == MAX)
		printf("通讯录满了");
	else
	{
		printf("\n请输入名字：");
		scanf("%s", pcon->data[pcon->size].name);
		printf("\n请输入性别：");
		scanf("%s", pcon->data[pcon->size].sex);
		printf("\n请输入年龄：");
		scanf("%d", &(pcon->data[pcon->size].age));
		printf("\n请输入电话：");
		scanf("%s", pcon->data[pcon->size].tel);
		printf("\n请输入住址：");
		scanf("%s", pcon->data[pcon->size].address);
		(pcon->size)++;
	}
}

void Shocontact(const struct contact* pcon)
{	
	if (pcon->size==0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		printf("%-10s %-5s %-5s %-15s %-20s\n", "名字", "性别", "年龄", "电话", "住址");
		int i = 0;
		for (i = 0; i < pcon->size; i++)
		{
			printf("%-10s %-5s %-5d %-15s %-20s\n",
				pcon->data[i].name,
				pcon->data[i].sex,
				pcon->data[i].age,
				pcon->data[i].tel,
				pcon->data[i].address);
		}
	}
}

void Delcontact(struct contact* pcon)
{
	int i = 0;
	int pos = -1;
	char name[MAX_NAME] = { 0 };
	printf("请输入要删除的联系人\n");
	scanf("%s", name);
	pos = search_people(pcon, name);
	if (pos == -1)
	{
		printf("没有要找的联系人\n");
	}
	else
	{
		for (i = pos; i < pcon->size - 1; i++)
		{
			pcon->data[i] = pcon->data[i + 1];
		}
		pcon->size--;
	}

}

void Seacontact(const struct contact* pcon)
{
	int pos = -1;
	char name[MAX_NAME];
	printf("输入要查找的人\n");
	scanf("%s", name);
	pos = search_people(pcon, name);
	if (pos == -1)
	{
		printf("没找到该联系人\n");
	}
	else
	{
		printf("%-10s %-5s %-5s %-15s %-20s\n", "名字", "性别", "年龄", "电话", "住址");
		printf("%-10s %-5s %-5d %-15s %-20s\n",
			pcon->data[pos].name,
			pcon->data[pos].sex,
			pcon->data[pos].age,
			pcon->data[pos].tel,
			pcon->data[pos].address);
	}
}

void Modcontact(struct contact* pcon)
{
	int pos;//输入要修改联系人所在数组的位置
	char name[MAX_NAME];
	printf("输入要修改的联系人的名字\n");
	scanf("%s", name);
	pos = search_people(pcon, name);
	if (pos == -1)
	{
		printf("没有找到该联系人\n");
	}
	else
	{
		printf("\n请输入名字：");
		scanf("%s", pcon->data[pos].name);
		printf("\n请输入性别：");
		scanf("%s", pcon->data[pos].sex);
		printf("\n请输入年龄：");
		scanf("%d", &(pcon->data[pos].age));
		printf("\n请输入电话：");
		scanf("%s", pcon->data[pos].tel);
		printf("\n请输入住址：");
		scanf("%s", pcon->data[pos].address);
	}
}

int name_cmp(const void* a, const void* b)
{
	return strcmp(((struct contact*)a)->data->name, ((struct contact*)b)->data->name);
}
int age_cmp(const void* a, const void* b)
{
	return ((struct contact*)a)->data->age - ((struct contact*)b)->data->age;
}
int tele_cmp(const void* a, const void* b)
{
	return ((struct contact*)a)->data->tel - ((struct contact*)b)->data->tel;
}
int address_cmp(const void* a, const void* b)
{
	return strcmp(((struct contact*)a)->data->address , ((struct contact*)b)->data->address);
}
int sex_cmp(const void* a, const void* b)
{
	return strcmp(((struct contact*)a)->data->sex , ((struct contact*)b)->data->sex);
}
void Sorcontact(struct contact* pcon)
{
	int input = 0;
	printf("请输入要排序的方式\n1,名字\n2,年纪\n3,电话\n4,住址\n5,性别\n");
	scanf("%d", &input);
	switch (input)
	{
	case name:
		qsort(pcon->data, pcon->size, sizeof(pcon->data[0]), name_cmp);//name_cmp返回1，就颠倒顺序
		break;
	case age:
		qsort(pcon->data, pcon->size, sizeof(pcon->data[0]), age_cmp);
		break;
	case tele:
		qsort(pcon->data, pcon->size, sizeof(pcon->data[0]), tele_cmp);
		break;
	case address:
		qsort(pcon->data, pcon->size, sizeof(pcon->data[0]), address_cmp);
		break;
	case sex:
		qsort(pcon->data, pcon->size, sizeof(pcon->data[0]), sex_cmp);
		break;
	}
}