#define _CRT_SECURE_NO_WARNINGS
#include"function.h"
void menu()//�˵�����
{
	printf("****************************************\n");
	printf("***************��������Ϸ***************\n");
	printf("*****************1.piay*****************\n");
	printf("*****************2.exit*****************\n");
	printf("****************************************\n");
	printf("*****   ������� *    �������� #   *****\n");
	printf("****************************************\n");
}

void initialize_board(char board[ROW][LIN], int row, int lin)//��ʼ������
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

void player_move(char board[ROW][LIN], int row, int lin)//���߲�
{
	int i, j;
	while (1)
	{
		printf("��������;");
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
				printf("��λ����������,����������\n");
			}
		}
		else
		{
			printf("����Ƿ�,����������\n");
		}
	}
	printf("����߲� * \n");
}

void computer_move(char board[ROW][LIN], int row, int lin)//�����߲�
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
	printf("�����߲� # \n");
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
		return 1;//δ��
	}
	else
	{
		return 0;//����
	}
}

char iswin(char board[ROW][LIN], int row, int lin)//�ж���Ӯ
{
	int x, y;
	int i;
	for (x = 0; x < row; x++)
	{
		if (board[x][0] == board[x][1] && board[x][1] == board[x][2] && board[x][0] != ' ')//����
		{
			return board[x][0];////���Ӯ���*������Ӯ���#
			break;
		}
	}
	for (y = 0; y < lin; y++)
	{
		if (board[0][y] == board[1][y] && board[1][y] == board[2][y] && board[0][y] != ' ')//����
		{
			return board[0][y];
			break;
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')//���Խ���
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')//�ζԽ���
	{
		return board[1][1];
	}
	i=isfull_board(board, ROW, LIN);
	if (i == 0)
	{
		return 'M';//ƽ��
	}
	else
	{
		return 'C';//��Ϸ����
	}
}