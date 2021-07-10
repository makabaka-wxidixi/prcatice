#pragma once
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define ROW 3
#define LIN 3
#include<time.h>
#include<stdlib.h>
void menu();//菜单
void initialize_board(char board[ROW][LIN], int row, int lin);//初始化数组
void print_board(char board[ROW][LIN], int row, int lin);//打印棋盘
void player_move(char board[ROW][LIN], int row, int lin);//人走步
char iswin(char board[ROW][LIN], int row, int lin);//判断输赢：输出*，玩家赢；输出#，电脑赢；输出M，平局；输出C，继续游戏
void computer_move(char board[ROW][LIN], int row, int lin);//电脑走步
int isfull_board(char board[ROW][LIN], int row, int lin);//棋盘是否填满：返回值为1时，未满；返回值为0时，满了
