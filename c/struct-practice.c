#include <stdio.h>
#include <stdlib.h>

struct cadastro
{
	char nome[30];
	int matricula;	
};

struct cadastro cad[3];

int main()
{
	int a=0;
	printf("esse programa cria 3 cadastros:\n");
	while(a<3)
	{
		system("pause");
		system ("cls");
		printf("cadastro %d:\n\n",a);
		printf("digite seu nome:\n");
		scanf("%s",&cad[a].nome);
		printf("digite sua matricula:\n");
		scanf("%d",&cad[a].matricula);
		a++;
	}
	system ("cls");
	for(a=0;a<3;a++)
	{
		printf("nome da matricula %d: %s\nnumero da matricula %d: %d\n\n",a,cad[a].nome,a,cad[a].matricula);
	}
}