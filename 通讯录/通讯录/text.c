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
	initcontact(&con);//��ʼ��ͨѶ¼����������ڴ�
	loadcontact(&con);//����ͨѶ¼����
	do
	{
		menu();
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case Add://������ϵ��
			Addcontact(&con);
			break;
		case Delete://ɾ����ϵ��
			Delcontact(&con);
			break;
		case Search://Ѱ����ϵ��
			Seacontact(&con);
			system("pause");
			break;
		case Modify://�޸���ϵ����Ϣ
			Modcontact(&con);
			break;
		case Show://��ӡͨѶ¼
			Shocontact(&con);
			system("pause");
			break;
		case Sort://������ϵ��
			Sorcontact(&con);
			Shocontact(&con);
			system("pause");
			break;
		case Save://����ͨѶ¼
			savecontact(&con);
			break;
		case Exit://�˳�ͨѶ¼
			savecontact(&con);
			breakcontact(&con);
			break;
		}
		system("cls");
	} while (input);
	return 0;
}