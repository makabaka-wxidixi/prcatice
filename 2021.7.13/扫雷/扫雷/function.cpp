
#include"function.h"
void menu()
{
	printf("**************************************\n");
	printf("**********      1,play      **********\n");
	printf("**********      0,exit      **********\n");
	printf("**************************************\n");
}

void initialize_board(char board[ROWS][LINS], int rows, int lins, char set)
{
	int i;
	int j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < lins; j++)
		{
			board[i][j] = set;
		}
	}
}
void display_board(char board[ROWS][LINS], int row, int lin)
{
	int i = 0;
	int j = 0;
	int a = 0;
	for (i = 0; i <= row; i++)
	{
		if (i == 0)
		{
			while (a <= lin)
			{
				printf("%d ", a);
				a++;
			}	
			printf("\n");
		}
		else
		{
			for (j = 0; j <= lin; j++)
			{
				if (j == 0)
				{
					printf("%d ", i);
				}
				else
				printf("%c ", board[i][j]);
			}
			printf("\n");
		}
	}
}
void set_mine(char board[ROWS][LINS], int row, int lin)
{
	int i=0;
	while (i <= easy_mode)
	{
		int x = rand() % 9 + 1;
		int y = rand() % 9 + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			i++;
		}
	}
}
int mines_around(char inside[ROWS][LINS], int x, int y)
{
	return inside[x - 1][y - 1] +
		inside[x][y - 1] +
		inside[x + 1][y - 1] +
		inside[x + 1][y] +
		inside[x + 1][y + 1] +
		inside[x][y + 1] +
		inside[x - 1][y + 1] +
		inside[x - 1][y] - 8 * '0';
}
void spread(char outside[ROWS][LINS], int x, int y)
{
	outside[x - 1][y - 1] == 0;

	outside[x][y - 1] == 0;

	outside[x + 1][y - 1] == 0;

	outside[x + 1][y] == 0;

	outside[x + 1][y + 1] == 0;

	outside[x][y + 1] == 0;

	outside[x - 1][y + 1] == 0;

	outside[x - 1][y] == 0;
}


void mine_clearance(char inside[ROWS][LINS], char outside[ROWS][LINS], int row, int lin)
{
	int x, y;
	int a = 0;
	while (1)
	{
		printf("输入坐标->");
		scanf("%d%d", &y, &x);
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
		{
			if (inside[x][y] == '1')
			{
				printf("你被炸死了\n");
				display_board(inside, ROW, LIN);
				break;
			}
			else
			{
				outside[x][y] = mines_around(inside, x, y)+'0';
				spread(outside, x, y);
				display_board(outside, ROW, LIN);
				a++;
				if (a == ROW * LIN - easy_mode)
				{
					printf("排雷成功\n");
					break;
				}
			}
		}
		else
		{
			printf("输入非法，请重新输入\n");
		}
	}
	
}