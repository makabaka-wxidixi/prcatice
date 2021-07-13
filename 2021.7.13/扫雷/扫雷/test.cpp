
#include"function.h"
void game()
{
	char inside[ROWS][LINS] = { 0 };
	char outside[ROWS][LINS] = { 0 };
	initialize_board(inside, ROWS, LINS, '0');
	initialize_board(outside, ROWS, LINS, '*');//初始化棋盘；
	//display_board(inside, ROW, LIN);
	display_board(outside, ROW, LIN);
	set_mine(inside, ROW, LIN);//设置雷
	mine_clearance(inside,outside, ROW, LIN);
}

int main()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}