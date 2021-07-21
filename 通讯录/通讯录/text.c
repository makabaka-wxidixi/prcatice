#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include"funtion.h"

void menu()
{
	printf("************************************************\n");
	printf("******** 1.add                 2,delete ********\n");
	printf("******** 3,search              4,modify ********\n");
	printf("******** 5,show                  6,sort ********\n");
	printf("******** 7,save                  0,exit ********\n");
	printf("************************************************\n");

}
int main()
{
	int input = 0;
	struct contact con = { 0 };
	initcontact(&con);//初始化通讯录，赋予基础内存
	loadcontact(&con);//加载通讯录数据
	do
	{
		menu();
		printf("请选择\n");
		scanf("%d", &input);
		switch (input)
		{
		case Add://增加联系人
			Addcontact(&con);
			break;
		case Delete://删除联系人
			Delcontact(&con);
			break;
		case Search://寻找联系人
			Seacontact(&con);
			system("pause");
			break;
		case Modify://修改联系人信息
			Modcontact(&con);
			break;
		case Show://打印通讯录
			Shocontact(&con);
			system("pause");
			break;
		case Sort://排序联系人
			Sorcontact(&con);
			Shocontact(&con);
			system("pause");
			break;
		case Save://保存通讯录
			savecontact(&con);
			break;
		case Exit://退出通讯录
			savecontact(&con);
			breakcontact(&con);
			break;
		}
		system("cls");
	} while (input);
	return 0;
}