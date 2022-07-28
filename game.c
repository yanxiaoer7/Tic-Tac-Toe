#include"game.h";

//二维数组初始化
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
//打印
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
//人输入(o)
int human_in(char game[][3])
{
	printf("请输入你下棋的位置（例如：1 1）：");
	int i1 = 0, j1 = 0;
Scanf:
	scanf("%d %d", &i1, &j1);
	int i = i1 - 1;
	int j = j1 - 1;
	if ((i1 < 1 || i1 > 3) || (j1 < 1 || j1 > 3))
	{
		printf("输入数据有误，请重新输入：");
		goto Scanf;
	}
	if (game[i][j] != ' ')
	{
		printf("该位置已有数据，请重新输入：");
		goto Scanf;
	}
	game[i][j] = 'o';
	printf_game(game);
	printf("\n");
}
//机器输入(*)
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
//判断是否胜利
int judge_game(char game[][3])
{
	//横列
	for (int i = 0; i <= 2; i++)
	{
		if (game[i][0] == game[i][1] &&
			game[i][1] == game[i][2] &&
			game[i][2] != ' ')
		{
			return 0;
		}
	}
	//纵列
	for (int j = 0; j <= 2; j++)
	{
		if (game[0][j] == game[1][j] &&
			game[1][j] == game[2][j] &&
			game[2][j] != ' ')
		{
			return 0;
		}
	}
	//斜线
	if (game[0][0] == game[1][1] &&
		game[1][1] == game[2][2] &&
		game[2][2] != ' ')
	{
		return 0;
	}
	//反斜线
	if (game[0][2] == game[1][1] &&
		game[1][1] == game[2][0] &&
		game[2][0] != ' ')
	{
		return 0;
	}
}
//game函数
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