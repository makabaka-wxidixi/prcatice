#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"funtion.h"


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

void initcontact(struct contact* pcon)//给通讯录赋予初始内存
{
	pcon->data = (struct peopledata*)malloc(sizeof(struct peopledata) * initmem);
	if (pcon->data == NULL)
	{
		printf("initcontact:%s\n", strerror(errno));
	}
	pcon->size = 0;
	pcon->capacity = initmem;
}

void expansion(struct contact* pcon)//扩容通讯录
{
	if (pcon->size == pcon->capacity)//内存满了
	{
		//扩容
		peopledata* paa = realloc(pcon->data, sizeof(peopledata) * (pcon->size + incrmem));
		if (paa == NULL)
		{
			printf("expansion:%s\n", strerror(errno));
			return;
		}
		pcon->data = paa;
		pcon->capacity = pcon->size + incrmem;
		printf("扩容成功\n");
	}
}

void Addcontact(struct contact* pcon)//增加联系人
{
	expansion(pcon);//判断内存是否满，满就扩容，不满就什么也不做
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

void Shocontact(const struct contact* pcon)//打印通讯录
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

void Delcontact(struct contact* pcon)//删除对应联系人
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

void Seacontact(const struct contact* pcon)//寻找联系人
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

void Modcontact(struct contact* pcon)//修改联系人信息
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

int name_cmp(const void* a, const void* b)//名字
{
	return strcmp(((peopledata*)a)->name, ((peopledata*)b)->name);
}
int age_cmp(const void* a, const void* b)//年龄
{
	return ((peopledata*)a)->age - ((peopledata*)b)->age;
}
int tele_cmp(const void* a, const void* b)//电话
{
	return ((peopledata*)a)->tel - ((peopledata*)b)->tel;
}
int address_cmp(const void* a, const void* b)//地址
{
	return strcmp(((peopledata*)a)->address, ((peopledata*)b)->address);
}
int sex_cmp(const void* a, const void* b)//性别
{
	return strcmp(((peopledata*)a)->sex, ((peopledata*)b)->sex);
}

void Sorcontact(struct contact* pcon)//给联系人排序
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

void breakcontact(struct contact* pcon)//退出通讯录
{
	free(pcon->data);
	pcon->data = NULL;
}

void savecontact(struct contact* pcon)//通讯录保存到文件
{
	//打开文件
	FILE* pfwrite = fopen("contact.tat", "wb");
	if (pfwrite == NULL)
	{
		printf("savecontact:%s\n", strerror(errno));
		return;
	}
	int i = 0;
	for (i = 0; i < pcon->size; i++)
	{
		fwrite(&(pcon->data[i]), sizeof(peopledata), 1, pfwrite);
	}
	//关闭文件
	fclose(pfwrite);
	pfwrite = NULL;
}

void loadcontact(struct contact* pcon)//加载联系人信息
{
	peopledata tmp = { 0 };//创建一个临时变量来存储数据
	//打开文件
	FILE* pfread = fopen("contact.tat", "rb");
	if (pfread == NULL)
	{
		printf("loadcontact:%s\n", strerror(errno));
		return;
	}
	while (fread(&tmp, sizeof(peopledata), 1, pfread))
	{
		expansion(pcon);
		system("cls");
		pcon->data[pcon->size] = tmp;
		pcon->size++;
	}
	//关闭文件
	fclose(pfread);
	pfread = NULL;
}