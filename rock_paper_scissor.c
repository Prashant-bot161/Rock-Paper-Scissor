#include <stdio.h>
#include <stdlib.h>

int game(char object, char player[20], int *points_CPU, int *points_PLAYER)
{
	int k;
	k = rand() % 3;
	if ((k == 0 && object == 'R') || (k == 1 && object == 'P') || (k == 2 && object == 'S'))
	{
		printf(" RESULT : DRAW \n");
		printf(" points_CPU : %d          points_%s : %d\n", *points_CPU, player, *points_PLAYER);
	}
	else if ((k == 0 && object == 'P') || (k == 1 && object == 'S') || (k == 2 && object == 'R'))
	{
		*points_PLAYER += 10;
		printf(" RESULT : VICTORY \n");
		printf(" points_CPU : %d          points_%s : %d\n", *points_CPU, player, *points_PLAYER);
	}
	else
	{
		*points_CPU += 10;
		printf(" RESULT : DEFEAT \n");
		printf(" points_CPU : %d          points_%s : %d\n", *points_CPU, player, *points_PLAYER);
	}
	printf("\n");
}
int main(void)
{
	int round;
	char decision;
	char player[20];
	printf("       ROCK, PAPER AND SCISSOR'S   \n");
	printf("---------------------------------------\n    ");
	printf("    Made by:Prashant Singh      \n\n");
	printf(" ENTER YOUR NAME : ");
	scanf("%[^\n]", player); // this means ki jb tk apn enter nhi marnge tb tk vo aage proceed nhi krega.
	printf("\n");
	printf(" HELLO, %s !!  \n\n", player);

jump:
	printf(" ENTER THE NUMBER OF ROUND'S (Odd) YOU WANT TO PLAY : ");
	scanf("%d", &round);

	if (round % 2 != 0)
	{
		char choice;
		int points_CPU = 0, points_PLAYER = 0;
		for (int i = 0; i < round; i++)
		{
			char object;
			printf(" ROUND : %d\n", i + 1);
			printf(" R --> rock	\n");
			printf(" S --> scissor\n");
			printf(" P --> paper\n");
			printf(" ENTER : ");
			scanf(" %c", &object);
			game(object, player, &points_CPU, &points_PLAYER);
		}
		printf("\n");
		if (points_CPU > points_PLAYER)
		{
			printf(" OOPS!!, YOU LOOSE. WANT TO TRY AGAIN ? (Y/N) : ");
		}
		else if (points_CPU < points_PLAYER)
		{

			printf(" CONGRATS %s!!, YOU WON.\n DO YOU WANT TO PLAY AGAIN ? (Y/N) : ", player);
		}
		else
		{
			printf(" IT IS A TIE! BETTER LUCK NEXT TIME. \n DO YOU WANT TO PLAY AGAIN ? (Y/N) : ");
		}
		scanf(" %c", &choice);

		if (choice == 'Y' || choice == 'y')
		{

			goto jump;
		}
	}

	else if (round % 2 == 0)
	{
		printf(" OOPS!!, YOU ENTERED AN INVALID NUMBER OF ROUND'S\n");
		printf(" WANT TO TRY AGAIN (Y/N) \n");
		scanf(" %c", &decision); // space ka pta krna hai!!

		if (decision == 'Y' || decision == 'y')
		{
			goto jump;
		}
	}

	printf(" THANK YOU %s FOR PLAYING!! \n", player);
	system("pause"); // exe bnd nhi hoti without printing
	return 0;
}
