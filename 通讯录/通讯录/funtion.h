
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>


#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TEL 15
#define MAX_ADD 30
#define MAX 1000
enum function
{
	Exit,
	Add,
	Delete,
	Search,
	Modify,
	Show,
	Sort
};

struct peopledata
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tel[MAX_TEL];
	char address[MAX_ADD];
};

struct contact
{
	struct peopledata data[MAX];
	int size;
};

void Addcontact(struct contact* pcon);//������ϵ��

void Shocontact(const struct contact* pcon);//��ʾͨѶ¼����

void Delcontact(struct contact* pcon);//ɾ����ϵ��

void Seacontact(const struct contact* pcon);//������ϵ��

void Modcontact(struct contact* pcon);//�޸���ϵ��

void Sorcontact(struct contact* pcon);//����������ϵ��