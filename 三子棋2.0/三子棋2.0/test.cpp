#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include"function.h"
void game()
{
	char ret;
	char board[ROW][LIN] = { 0 };
	initialize_board(board, ROW, LIN);//初始化数组
	print_board(board, ROW, LIN);//打印棋盘
	while (1)
	{
		player_move(board, ROW, LIN);//人走步
		print_board(board, ROW, LIN);//打印棋盘
		ret = iswin(board, ROW, LIN);//判断输赢
		if (ret != 'C')
		{
			break;
		}
		computer_move(board, ROW, LIN);//电脑走步
		print_board(board, ROW, LIN);//打印棋盘
		ret = iswin(board, ROW, LIN);//判断输赢
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else if (ret == 'M')
	{
		printf("平局\n");
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	do
	{
		int input;
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		if (input == 1)
			game();
		else if (input == 2)
		{
			printf("游戏结束\n");
			break;
		}
		else
			printf("输入非法，请重新输入\n");
	}
	while (1);
	return 0;
}