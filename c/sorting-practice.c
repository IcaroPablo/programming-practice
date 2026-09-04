#include <stdio.h>
#include <string.h>
int main()
{
	int a,b,c,d,i,j,r,aux,vetor[10],vet2[10];
	for(a=0;a<10;a++)
	{
		printf("digite um valor inteiro:\n");
		scanf("%d",&vetor[a]);
	}
	for(b=0;b<10;b++)
	{
		vet2[b]=vetor[b];
	}
	printf("exibindo vetor:\n");
	for(c=0;c<10;c++)
	{
		printf("%d ",vetor[c]);//vetor fora de ordem
	}
	printf("\n");
	printf("orgnizando vetor por bubble sort:\n");
    for(i=9; i >= 1; i--)//bubble sort
    {  
        for(j=0; j < i ; j++) 
        {
            if(vetor[j]>vetor[j+1]) 
            {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
     for(r = 0; r < 10; ++r)
    {
        printf("%d ",vetor[r]);//vetor organizado
    }
    printf("\n");
    printf("exibindo vet2:\n");
	for(d=0;d<10;d++)
	{
		printf("%d ",vet2[d]);//vet2 fora de ordem
	}
	printf("\n");
	printf("organizando vet2 por selection sort:\n");
	for(i=0;i<10;i++)//selection sort
	{
		for(j=0;j<10;j++)
		{
			if(vet2[i]<vet2[j])
			{
				r=vet2[i];
				vet2[i]=vet2[j];
				vet2[j]=r;
			}
		}
	}
    for(r = 0; r < 10; ++r)
        {
        	printf("%d ",vet2[r]);//vet2 organizado
        }
	return 0;	
}