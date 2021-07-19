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

static int search_people(const struct contact*pcon, char *name)//���˺������ҵ������±꣬�Ҳ�������-1
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
		printf("ͨѶ¼����");
	else
	{
		printf("\n���������֣�");
		scanf("%s", pcon->data[pcon->size].name);
		printf("\n�������Ա�");
		scanf("%s", pcon->data[pcon->size].sex);
		printf("\n���������䣺");
		scanf("%d", &(pcon->data[pcon->size].age));
		printf("\n������绰��");
		scanf("%s", pcon->data[pcon->size].tel);
		printf("\n������סַ��");
		scanf("%s", pcon->data[pcon->size].address);
		(pcon->size)++;
	}
}

void Shocontact(const struct contact* pcon)
{	
	if (pcon->size==0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		printf("%-10s %-5s %-5s %-15s %-20s\n", "����", "�Ա�", "����", "�绰", "סַ");
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
	printf("������Ҫɾ������ϵ��\n");
	scanf("%s", name);
	pos = search_people(pcon, name);
	if (pos == -1)
	{
		printf("û��Ҫ�ҵ���ϵ��\n");
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
	printf("����Ҫ���ҵ���\n");
	scanf("%s", name);
	pos = search_people(pcon, name);
	if (pos == -1)
	{
		printf("û�ҵ�����ϵ��\n");
	}
	else
	{
		printf("%-10s %-5s %-5s %-15s %-20s\n", "����", "�Ա�", "����", "�绰", "סַ");
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
	int pos;//����Ҫ�޸���ϵ�����������λ��
	char name[MAX_NAME];
	printf("����Ҫ�޸ĵ���ϵ�˵�����\n");
	scanf("%s", name);
	pos = search_people(pcon, name);
	if (pos == -1)
	{
		printf("û���ҵ�����ϵ��\n");
	}
	else
	{
		printf("\n���������֣�");
		scanf("%s", pcon->data[pos].name);
		printf("\n�������Ա�");
		scanf("%s", pcon->data[pos].sex);
		printf("\n���������䣺");
		scanf("%d", &(pcon->data[pos].age));
		printf("\n������绰��");
		scanf("%s", pcon->data[pos].tel);
		printf("\n������סַ��");
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
	printf("������Ҫ����ķ�ʽ\n1,����\n2,���\n3,�绰\n4,סַ\n5,�Ա�\n");
	scanf("%d", &input);
	switch (input)
	{
	case name:
		qsort(pcon->data, pcon->size, sizeof(pcon->data[0]), name_cmp);//name_cmp����1���͵ߵ�˳��
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