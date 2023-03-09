#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


//棋盘初始化
void InitBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			board[i][j] = ' ';
}


//棋盘的打印
/*希望实现棋盘如下(并且能进行棋盘大小的改变)
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
			if (j == col - 1)//横向棋盘最后的变化
			{
				printf(" %c \n", board[i][j]);
				if (i != row - 1)//棋盘最后没有分割线
					for (int k = 0; k < col; k++)
					{
						if (k != col - 1)//横向分割线最后的变化
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


//玩家下棋的实现
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("玩家走！\n");
	printf("请输入您要下的坐标：");
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
				printf("坐标已被占用！\n\n");
		}
		else
			printf("非法坐标,请重新输入！\n\n");
	}
}



//电脑下棋的实现
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	srand((unsigned int)time(NULL));//设置随机数种子
	printf("电脑走！\n");	
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


/*判断输赢的实现
玩家赢--O
电脑赢--X
平局--Q
继续--C
*/
char IsWin(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)//行相连
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
	for (int i = 0; i < col; i++)//列相连
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
			return board[0][i];
	//对角相连
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
		return board[0][0];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ')
		return board[2][0];
	//棋盘已满
	if (Full(board, row, col) == 1)
		return 'Q';
	//棋盘未满
	return 'C';
}


//判断棋盘是否已满
int Full(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (board[i][j] == ' ')
				return 0;
	return 1;
}