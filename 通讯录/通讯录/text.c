#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include"funtion.h"

void menu()
{
	printf("************************************************\n");
	printf("******** 1.add                 2,delete ********\n");
	printf("******** 3,search              4,modify ********\n");
	printf("******** 5,show                  6,sort ********\n");
	printf("******** 0,exit                         ********\n");
	printf("************************************************\n");

}
int main()
{
	int input = 0;
	struct contact con = { 0 };
	do
	{
		menu();
		printf("«Î—°‘Ò\n");
		scanf("%d", &input);
		switch (input)
		{
		case Add:
			Addcontact(&con);
			break;
		case Delete:
			Delcontact(&con);
			break;
		case Search:
			Seacontact(&con);
			system("pause");
			break;
		case Modify:
			Modcontact(&con);
			break;
		case Show:
			Shocontact(&con);
			system("pause");
			break;
		case Sort:
			Sorcontact(&con);
			Shocontact(&con);
			system("pause");
			break;
		case Exit:
			break;
		}
		system("cls");
	} while (input);


	return 0;
}