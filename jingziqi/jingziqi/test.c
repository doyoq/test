#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"



//游戏测试---



//游戏菜单
void menu()
{
	printf("***************************************************\n");
	printf("*                                                 *\n");
	printf("*                     井字棋                      *\n");
	printf("*                                                 *\n");
	printf("*           1.PLAY             0.EXIT             *\n");
	printf("*                                                 *\n");
	printf("***************************************************\n\n");
	printf("***************************************************\n");
	printf("*                                                 *\n");
	printf("*                     规则：                      *\n");
	printf("*                玩家为O，电脑为X                 *\n");
	printf("*          坐标首先输入横轴，再输入纵轴           *\n");
	printf("*        坐标由1起始，向右或向下逐渐加一          *\n");
	printf("*                                                 *\n");
	printf("***************************************************\n\n");
}






//游戏的实现
void game()
{
	char ret;//用于接收输赢指令
	int select;
	printf("***************************************************\n");
	printf("*                                                 *\n");
	printf("*                 请选择先后手                    *\n");
	printf("*                                                 *\n");
	printf("*       1.玩家先手            0.电脑先手          *\n");
	printf("*                                                 *\n");
	printf("***************************************************\n\n");
	
	char board[ROW][COL] = { 0 };//数组存放棋盘
	InitBoard(board, ROW, COL);//初始化棋盘为空格
	DisplayBoard(board, ROW, COL);//打印棋盘
	while (1)//用以实现错误选择下棋先后手的循环
	{
		scanf("%d", &select);//用以选择先后手
		if (select == 1)//玩家先手--1
		{
			while (1)//下棋的实现
			{
				//玩家下棋
				PlayerMove(board, ROW, COL);
				DisplayBoard(board, ROW, COL);
				//判断玩家是否赢
				ret = IsWin(board, ROW, COL);
				if (ret != 'C')
					break;
				//电脑下棋
				ComputerMove(board, ROW, COL);
				DisplayBoard(board, ROW, COL);
				//判断电脑是否赢
				ret = IsWin(board, ROW, COL);
				if (ret != 'C')
					break;
			}
			break;
		}
		else if (select == 0)//电脑先手--0
		{
			while (1)//下棋的实现
			{
				//电脑下棋
				ComputerMove(board, ROW, COL);
				DisplayBoard(board, ROW, COL);
				//判断电脑是否赢
				ret = IsWin(board, ROW, COL);
				if (ret != 'C')
					break;
				//玩家下棋
				PlayerMove(board, ROW, COL);
				DisplayBoard(board, ROW, COL);
				//判断玩家是否赢
				ret = IsWin(board, ROW, COL);
				if (ret != 'C')
					break;
			}
			break;
		}
		else
		{
			printf("***************************\n");
			printf("*  选择错误，请重新选择！ *\n");
			printf("***************************\n\n");
		}
	}
	switch (ret)
	{
	case 'O':
		printf("***************\n");
		printf("*  玩家获胜！ *\n"); 
		printf("***************\n\n");
		break;
	case 'X':
		printf("***************\n");
		printf("*  电脑获胜！ *\n");
		printf("***************\n\n");
		break;
	case 'Q':
		printf("***************\n");
		printf("*    平局！   *\n");
		printf("***************\n\n");
		break;
	}
}






//游戏选择界面
void test()
{
	int input;
	do 
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("***************\n");
			printf("*  游戏结束！ *\n");
			printf("***************\n\n");
			break;
		case 1:
			printf("***************\n");
			printf("*  游戏开始！ *\n");
			printf("***************\n\n");
			game(); 
			break;
		default:
			printf("***************************\n");
			printf("*  选择错误，请重新选择！ *\n");
			printf("***************************\n\n");
			break;
		}
	} while (input != 0);
}


int main()
{
	test();
	return 0;
}