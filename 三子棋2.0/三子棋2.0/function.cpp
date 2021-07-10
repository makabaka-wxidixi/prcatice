#define _CRT_SECURE_NO_WARNINGS
#include"function.h"
void menu()//菜单函数
{
	printf("****************************************\n");
	printf("***************三子棋游戏***************\n");
	printf("*****************1.piay*****************\n");
	printf("*****************2.exit*****************\n");
	printf("****************************************\n");
	printf("*****   玩家棋子 *    电脑棋子 #   *****\n");
	printf("****************************************\n");
}

void initialize_board(char board[ROW][LIN], int row, int lin)//初始化数组
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < lin; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void print_board(char board[ROW][LIN], int row, int lin)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < lin; j++)
		{
			printf(" %c ",board[i][j]);
			if (j < lin - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		for (j = 0; j < lin; j++)
		{
			if (i < row - 1)
			{
				printf("---");
				if (j < lin - 1)
				{
					printf("|");
				}
			}	
		}
		printf("\n");
	}
}

void player_move(char board[ROW][LIN], int row, int lin)//人走步
{
	int i, j;
	while (1)
	{
		printf("输入坐标;");
		scanf("%d%d", &i, &j);
		if (i >= 1 && i <= row && j >= 1 && j <= lin)
		{
			if (board[i - 1][j - 1] == ' ')
			{
				board[i - 1][j - 1] = '*';
				break;
			}
			else
			{
				printf("该位置已有棋子,请重新输入\n");
			}
		}
		else
		{
			printf("输入非法,请重新输入\n");
		}
	}
	printf("玩家走步 * \n");
}

void computer_move(char board[ROW][LIN], int row, int lin)//电脑走步
{
	int i, j;
	while (1)
	{
		i = rand() % 3;
		j = rand() % 3;
		if (board[i][j] == ' ')
		{
			board[i][j] = '#';
			break;
		}
	}
	printf("电脑走步 # \n");
}

int isfull_board(char board[ROW][LIN], int row, int lin)
{
	int i, j;
	int c=0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < lin; j++)
		{
			if (board[i][j] == ' ')
			{
				c++;
			}
		}
	}
	if (c != 0)
	{
		return 1;//未满
	}
	else
	{
		return 0;//满了
	}
}

char iswin(char board[ROW][LIN], int row, int lin)//判断输赢
{
	int x, y;
	int i;
	for (x = 0; x < row; x++)
	{
		if (board[x][0] == board[x][1] && board[x][1] == board[x][2] && board[x][0] != ' ')//行三
		{
			return board[x][0];////玩家赢输出*，电脑赢输出#
			break;
		}
	}
	for (y = 0; y < lin; y++)
	{
		if (board[0][y] == board[1][y] && board[1][y] == board[2][y] && board[0][y] != ' ')//列三
		{
			return board[0][y];
			break;
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')//主对角线
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')//次对角线
	{
		return board[1][1];
	}
	i=isfull_board(board, ROW, LIN);
	if (i == 0)
	{
		return 'M';//平局
	}
	else
	{
		return 'C';//游戏继续
	}
}