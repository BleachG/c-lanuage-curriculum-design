#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"
void menu()
{
	printf("***********************************************\n");
	printf("****************   1.play    ******************\n");
	printf("****************   0.exit    ******************\n");
	printf("***********************************************\n");

}
void game()
{   
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	initboard(mine,ROWS,COLS,'0');
	initboard(show, ROWS, COLS, '*');
	Displayboard(mine, ROW, COL);
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		menu();
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch(input)
		{   
			case 1:
				printf("����Ϸ\n");
				game();
				break;
			case 0:
				printf("�˳�\n");
				break;
			default:
				printf("�������,������ѡ��\n");
				break;
		}
	} while (input);
	return 0;
}