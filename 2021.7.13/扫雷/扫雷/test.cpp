
#include"function.h"
void game()
{
	char inside[ROWS][LINS] = { 0 };
	char outside[ROWS][LINS] = { 0 };
	initialize_board(inside, ROWS, LINS, '0');
	initialize_board(outside, ROWS, LINS, '*');//��ʼ�����̣�
	//display_board(inside, ROW, LIN);
	display_board(outside, ROW, LIN);
	set_mine(inside, ROW, LIN);//������
	mine_clearance(inside,outside, ROW, LIN);
}

int main()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}