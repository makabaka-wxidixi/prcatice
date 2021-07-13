#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#define ROW 9
#define LIN 9
#define ROWS ROW+2
#define LINS LIN+2
#define easy_mode 10
#include<stdlib.h>
#include<time.h>
void menu();

void initialize_board(char board[ROWS][LINS], int rows, int lins, char set);

void display_board(char board[ROWS][LINS], int row, int lin);
void set_mine(char board[ROWS][LINS], int row, int lin);
void mine_clearance(char inside[ROWS][LINS], char outside[ROWS][LINS], int row, int lin);