#pragma once
#include <stdlib.h>
#include <time.h>
#define ROW 9
#define COL 9
#define ROWS 11
#define COLS 11
//չʾ������*��ʾ
// ����0��ʾ��1��ʾ
//��ʼ������
void initboard(char board[ROWS][COLS], int row, int col, char set);
//��ӡ����
void Displayboard(char board[ROWS][COLS], int row, int col);