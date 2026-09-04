#include <stdio.h>
#include <stdlib.h>

int error =1;
int kPright;
int kPleft;
int velRight;
int velLeft;
int velInitRight = 180;
int velInitLeft = 180;

int main()
{
	printf("velocidade inicial de cada roda e 180\n");
	system("pause");
	while(error != 0)
	{
		system("cls");
		printf("digite um valor de erro:\n");
		scanf("%d",&error);
		kPright = error * 10 * -1;
		kPleft = error * 10;
		if ((error <= 7) && (error >= -7))
		{
			printf("\nvalor kP da roda direita: %d\n",kPright);
			printf("valor kP da roda esquerda: %d\n",kPleft);
			velRight = kPright + velInitRight;
			velLeft = kPleft + velInitLeft;
			printf("\nvelociade da roda direita: %d\n",velRight);
			printf("velociade da roda esquerda: %d\n",velLeft);
		}
			else {printf("\nnao e um erro valido\n");}
		system("pause");
	}
	printf("nao ha erro");
}