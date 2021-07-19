
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

void Addcontact(struct contact* pcon);//增加联系人

void Shocontact(const struct contact* pcon);//显示通讯录内容

void Delcontact(struct contact* pcon);//删除联系人

void Seacontact(const struct contact* pcon);//查找联系人

void Modcontact(struct contact* pcon);//修改联系人

void Sorcontact(struct contact* pcon);//重新排序联系人