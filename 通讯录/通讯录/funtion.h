
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>


#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TEL 15
#define MAX_ADD 30
#define initmem 3
#define incrmem 2


enum function
{
	Exit,
	Add,
	Delete,
	Search,
	Modify,
	Show,
	Sort,
	Save
};

enum type
{
	name = 1,
	age,
	tele,
	address,
	sex
};

typedef struct peopledata
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tel[MAX_TEL];
	char address[MAX_ADD];
}peopledata;

typedef struct contact
{
	struct peopledata *data;
	int size;
	int capacity;
}contact;
void initcontact(struct contact* pcon);//��ʼ��ͨѶ¼

void Addcontact(struct contact* pcon);//������ϵ��

void Shocontact(const struct contact* pcon);//��ʾͨѶ¼����

void Delcontact(struct contact* pcon);//ɾ����ϵ��

void Seacontact(const struct contact* pcon);//������ϵ��

void Modcontact(struct contact* pcon);//�޸���ϵ��

void Sorcontact(struct contact* pcon);//����������ϵ��

void breakcontact(struct contact* pcon);//ɾ��ͨѶ¼//�ͷŶ�̬�ռ�

void savecontact(struct contact* pcon);//��ͨѶ¼���浽�ļ�

void loadcontact(struct contact* pcon);//������ϵ����Ϣ

