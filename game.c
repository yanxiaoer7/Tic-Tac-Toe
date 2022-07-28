#include"game.h";

//��ά�����ʼ��
int init_game(char game[][3])
{
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			game[i][j] = ' ';
		}
	}
	printf_game(game);
}
//��ӡ
int printf_game(char game[][3])
{
	system("cls");
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			if (j < 2)
			{
				printf("%c |", game[i][j]);
			}
			else if (j == 2)
			{
				printf("%c", game[i][j]);
			}
		}
		if (i < 2)
		{
			printf("\n---------\n");
		}
	}
	printf("\n");
}
//������(o)
int human_in(char game[][3])
{
	printf("�������������λ�ã����磺1 1����");
	int i1 = 0, j1 = 0;
Scanf:
	scanf("%d %d", &i1, &j1);
	int i = i1 - 1;
	int j = j1 - 1;
	if ((i1 < 1 || i1 > 3) || (j1 < 1 || j1 > 3))
	{
		printf("���������������������룺");
		goto Scanf;
	}
	if (game[i][j] != ' ')
	{
		printf("��λ���������ݣ����������룺");
		goto Scanf;
	}
	game[i][j] = 'o';
	printf_game(game);
	printf("\n");
}
//��������(*)
int comp_in(char game[][3])
{
	Sleep(500);
	srand(time(NULL));
	int i = 0, j = 0;
re_init:
	i = rand() % 3;
	j = rand() % 3;
	if (game[i][j] != ' ')
	{
		goto re_init;
	}
	game[i][j] = '*';
	printf_game(game);
	printf("\n");
}
//�ж��Ƿ�ʤ��
int judge_game(char game[][3])
{
	//����
	for (int i = 0; i <= 2; i++)
	{
		if (game[i][0] == game[i][1] &&
			game[i][1] == game[i][2] &&
			game[i][2] != ' ')
		{
			return 0;
		}
	}
	//����
	for (int j = 0; j <= 2; j++)
	{
		if (game[0][j] == game[1][j] &&
			game[1][j] == game[2][j] &&
			game[2][j] != ' ')
		{
			return 0;
		}
	}
	//б��
	if (game[0][0] == game[1][1] &&
		game[1][1] == game[2][2] &&
		game[2][2] != ' ')
	{
		return 0;
	}
	//��б��
	if (game[0][2] == game[1][1] &&
		game[1][1] == game[2][0] &&
		game[2][0] != ' ')
	{
		return 0;
	}
}
//game����
int game(void)
{
	char game[3][3] = { 0 };
	init_game(game);
	int i = 0;
	while (1)
	{
		human_in(game);
		i++;
		if (judge_game(game) == 0)
		{
			printf("Human Win.");
			break;
		}
		if (i == 9)
		{
			printf("Game over.");
			break;
		}
		comp_in(game);
		i++;
		if (judge_game(game) == 0)
		{
			printf("Computer Win.");
			break;
		}
	}
}