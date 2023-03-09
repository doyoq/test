#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"



//��Ϸ����---



//��Ϸ�˵�
void menu()
{
	printf("***************************************************\n");
	printf("*                                                 *\n");
	printf("*                     ������                      *\n");
	printf("*                                                 *\n");
	printf("*           1.PLAY             0.EXIT             *\n");
	printf("*                                                 *\n");
	printf("***************************************************\n\n");
	printf("***************************************************\n");
	printf("*                                                 *\n");
	printf("*                     ����                      *\n");
	printf("*                ���ΪO������ΪX                 *\n");
	printf("*          ��������������ᣬ����������           *\n");
	printf("*        ������1��ʼ�����һ������𽥼�һ          *\n");
	printf("*                                                 *\n");
	printf("***************************************************\n\n");
}






//��Ϸ��ʵ��
void game()
{
	char ret;//���ڽ�����Ӯָ��
	int select;
	printf("***************************************************\n");
	printf("*                                                 *\n");
	printf("*                 ��ѡ���Ⱥ���                    *\n");
	printf("*                                                 *\n");
	printf("*       1.�������            0.��������          *\n");
	printf("*                                                 *\n");
	printf("***************************************************\n\n");
	
	char board[ROW][COL] = { 0 };//����������
	InitBoard(board, ROW, COL);//��ʼ������Ϊ�ո�
	DisplayBoard(board, ROW, COL);//��ӡ����
	while (1)//����ʵ�ִ���ѡ�������Ⱥ��ֵ�ѭ��
	{
		scanf("%d", &select);//����ѡ���Ⱥ���
		if (select == 1)//�������--1
		{
			while (1)//�����ʵ��
			{
				//�������
				PlayerMove(board, ROW, COL);
				DisplayBoard(board, ROW, COL);
				//�ж�����Ƿ�Ӯ
				ret = IsWin(board, ROW, COL);
				if (ret != 'C')
					break;
				//��������
				ComputerMove(board, ROW, COL);
				DisplayBoard(board, ROW, COL);
				//�жϵ����Ƿ�Ӯ
				ret = IsWin(board, ROW, COL);
				if (ret != 'C')
					break;
			}
			break;
		}
		else if (select == 0)//��������--0
		{
			while (1)//�����ʵ��
			{
				//��������
				ComputerMove(board, ROW, COL);
				DisplayBoard(board, ROW, COL);
				//�жϵ����Ƿ�Ӯ
				ret = IsWin(board, ROW, COL);
				if (ret != 'C')
					break;
				//�������
				PlayerMove(board, ROW, COL);
				DisplayBoard(board, ROW, COL);
				//�ж�����Ƿ�Ӯ
				ret = IsWin(board, ROW, COL);
				if (ret != 'C')
					break;
			}
			break;
		}
		else
		{
			printf("***************************\n");
			printf("*  ѡ�����������ѡ�� *\n");
			printf("***************************\n\n");
		}
	}
	switch (ret)
	{
	case 'O':
		printf("***************\n");
		printf("*  ��һ�ʤ�� *\n"); 
		printf("***************\n\n");
		break;
	case 'X':
		printf("***************\n");
		printf("*  ���Ի�ʤ�� *\n");
		printf("***************\n\n");
		break;
	case 'Q':
		printf("***************\n");
		printf("*    ƽ�֣�   *\n");
		printf("***************\n\n");
		break;
	}
}






//��Ϸѡ�����
void test()
{
	int input;
	do 
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("***************\n");
			printf("*  ��Ϸ������ *\n");
			printf("***************\n\n");
			break;
		case 1:
			printf("***************\n");
			printf("*  ��Ϸ��ʼ�� *\n");
			printf("***************\n\n");
			game(); 
			break;
		default:
			printf("***************************\n");
			printf("*  ѡ�����������ѡ�� *\n");
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