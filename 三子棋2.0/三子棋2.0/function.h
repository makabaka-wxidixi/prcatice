#pragma once
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define ROW 3
#define LIN 3
#include<time.h>
#include<stdlib.h>
void menu();//�˵�
void initialize_board(char board[ROW][LIN], int row, int lin);//��ʼ������
void print_board(char board[ROW][LIN], int row, int lin);//��ӡ����
void player_move(char board[ROW][LIN], int row, int lin);//���߲�
char iswin(char board[ROW][LIN], int row, int lin);//�ж���Ӯ�����*�����Ӯ�����#������Ӯ�����M��ƽ�֣����C��������Ϸ
void computer_move(char board[ROW][LIN], int row, int lin);//�����߲�
int isfull_board(char board[ROW][LIN], int row, int lin);//�����Ƿ�����������ֵΪ1ʱ��δ��������ֵΪ0ʱ������
