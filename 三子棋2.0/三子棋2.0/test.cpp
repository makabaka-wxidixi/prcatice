#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include"function.h"
void game()
{
	char ret;
	char board[ROW][LIN] = { 0 };
	initialize_board(board, ROW, LIN);//��ʼ������
	print_board(board, ROW, LIN);//��ӡ����
	while (1)
	{
		player_move(board, ROW, LIN);//���߲�
		print_board(board, ROW, LIN);//��ӡ����
		ret = iswin(board, ROW, LIN);//�ж���Ӯ
		if (ret != 'C')
		{
			break;
		}
		computer_move(board, ROW, LIN);//�����߲�
		print_board(board, ROW, LIN);//��ӡ����
		ret = iswin(board, ROW, LIN);//�ж���Ӯ
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else if (ret == 'M')
	{
		printf("ƽ��\n");
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	do
	{
		int input;
		menu();
		printf("��ѡ��>:");
		scanf("%d", &input);
		if (input == 1)
			game();
		else if (input == 2)
		{
			printf("��Ϸ����\n");
			break;
		}
		else
			printf("����Ƿ�������������\n");
	}
	while (1);
	return 0;
}