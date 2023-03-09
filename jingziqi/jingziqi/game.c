#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


//���̳�ʼ��
void InitBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			board[i][j] = ' ';
}


//���̵Ĵ�ӡ
/*ϣ��ʵ����������(�����ܽ������̴�С�ĸı�)
	   |   |
	---+---+---
	   |   |
	---+---+---
	   |   |    
*/
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (j == col - 1)//�����������ı仯
			{
				printf(" %c \n", board[i][j]);
				if (i != row - 1)//�������û�зָ���
					for (int k = 0; k < col; k++)
					{
						if (k != col - 1)//����ָ������ı仯
							printf("---+");
						else
							printf("---\n");
					}
			}
			else
				printf(" %c |", board[i][j]);
		}
		if(i == row - 1)
			printf("\n\n");
	}
}


//��������ʵ��
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("����ߣ�\n");
	printf("��������Ҫ�µ����꣺");
	while (1)
	{
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= col && y >= 1 && y <= row)
		{
			if (board[y - 1][x - 1] == ' ')
			{
				board[y - 1][x - 1] = 'O';
				break;
			}
			else
				printf("�����ѱ�ռ�ã�\n\n");
		}
		else
			printf("�Ƿ�����,���������룡\n\n");
	}
}



//���������ʵ��
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	srand((unsigned int)time(NULL));//�������������
	printf("�����ߣ�\n");	
	while(1)
	{
		x = rand() % col;
		y = rand() % row;
		if (board[y][x] == ' ')
		{
			board[y][x] = 'X';
			break;
		}
	}
}


/*�ж���Ӯ��ʵ��
���Ӯ--O
����Ӯ--X
ƽ��--Q
����--C
*/
char IsWin(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)//������
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
	for (int i = 0; i < col; i++)//������
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
			return board[0][i];
	//�Խ�����
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
		return board[0][0];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ')
		return board[2][0];
	//��������
	if (Full(board, row, col) == 1)
		return 'Q';
	//����δ��
	return 'C';
}


//�ж������Ƿ�����
int Full(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (board[i][j] == ' ')
				return 0;
	return 1;
}