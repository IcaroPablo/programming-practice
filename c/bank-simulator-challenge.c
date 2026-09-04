#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CONTAS 50
int ultima_conta = 0; //Evitar usar variaveis globais para prevenir eventuais bugs
struct cliente
{
	char nome[30];
	float saldo;
	int conta;
	char situacao[40];
};
struct auxiliar //struct que sera usada para manter o quicksort organizado após a operação
{
	char nome[30];
	int conta;
	float saldo;
	char situacao[40];
};
struct cliente cadastro[NUM_CONTAS];
struct auxiliar usual[NUM_CONTAS];


void criacao_de_conta(int* c)
{
	int opc, conta = *c;
	for (;;)
	{
		fflush(stdin);
		cadastro[conta].conta = conta + 1;
		system("cls");
		printf("Criar uma nova conta\n\n");
		printf("Digite o nome completo:\n");
		gets(cadastro[conta].nome);
		printf("Qual sera o deposito inicial?\n");
		scanf("%f", &cadastro[conta].saldo);
		printf("Por favor, confirme os dados abaixo:\n");
		printf("Cliente: %s\n", cadastro[conta].nome);
		printf("Conta: %d\n", conta + 1);
		printf("Saldo: %.2f\n", cadastro[conta].saldo);
		printf("\nEsta tudo correto?\n1-sim\n2-nao\n");
		scanf("%d", &opc);
		switch(opc)
		{
		case 1:
			printf("Sua conta foi salva com sucesso!\n");
			sprintf(cadastro[conta].situacao, "Ativa");
			*c = conta + 1;
			system ("pause");
			system("cls");
			ultima_conta = *c;
			return;
			break;
		case 2:
			printf("Vamos tentar novamente!\n");
			system("pause");
			system("cls");
			break;
		default:
			printf("Opcao invalida!\n Cadastre a conta novamente!\n");
			system("pause");
			system("cls");
			break;
		}
	}
}

void consulta()
{
	int conta, opc;
	for(;;)
	{
		system("cls");
		fflush(stdin);
		printf("Consultar Conta\n\n");
		printf("Digite o numero da sua conta:\n");
		scanf("%d", &conta);
		printf("\n\nCliente: %s\n", cadastro[conta - 1].nome);
		printf("Conta: %d\n", conta);
		printf("Saldo: %.2f\n", cadastro[conta - 1].saldo);
		printf("\nStatus da conta: %s", cadastro[conta-1].situacao);
		printf("\n\n1-Alterar nome\n2-Desativar conta\n3-Retornar ao menu anterior\n");
		scanf("%d", &opc);
		switch(opc)
		{
		case 1:
			printf("Digite seu novo nome:\n");
			fflush(stdin);
			gets(cadastro[conta - 1].nome);
			printf("Nome alterado com sucesso! Seu novo nome e: \n%s\n", cadastro[conta - 1].nome);
			system("pause");
			return;
			break;
		case 2:
			cancelaConta(conta);
			return;
			break;
		case 3:
			system("cls");
			return;
			break;
		default:
			printf("Opcao invalida! Tente novamente.\n");
			system("pause");
			break;
		}
	}
}
void saque()
{
	int conta;
	float valor;
	system("cls");
	printf("Digite o numero da sua conta:\n");
	fflush(stdin);
	scanf("%d", &conta);
	chamaConta(conta);
	printf("Qual o valor do saque?\n");
	scanf("%f", &valor);
	if (valor <= cadastro[conta - 1].saldo)
	{
		printf("Saque realizado com sucesso!\n Retire o seu dinheiro!\n");
		cadastro[conta - 1].saldo = cadastro[conta - 1].saldo - valor;
		printf("Seu novo saldo e: %.2f\n", cadastro[conta - 1].saldo);
		system("pause");
	}
	else
	{
		printf("Voce nao tem saldo disponivel para essa operacao!\n");
		system("pause");
	}
}

void deposito()
{
	int conta;
	float valor;
	system("cls");
	fflush(stdin);
	printf("Deposito\n");
	printf("Se sua conta estiver desativada, isso ira reativar ela!\n Pressione Ctrl + C a qualquer momento para abortar a operacao\n");
	printf("Digite o numero da sua conta:\n");
	scanf("%d", &conta);
	chamaConta(conta);
	printf("Digite o valor a ser depositado:  ");
	scanf("%f", &valor);
	printf("Conferindo notas...");
	printf("Deposito realizado com sucesso!\n\n");
	cadastro[conta - 1].saldo = cadastro[conta - 1].saldo + valor;
	sprintf(cadastro[conta-1].situacao, "Ativa");
	printf("Seu novo saldo e: %.2f", cadastro[conta - 1].saldo);
	system("pause");
}

void transf()
{
	int conta, dest, opc;
	float valor;
	system("cls");
	fflush(stdin);
	printf("Tranferencia\n");
	printf("Digite o numero da sua conta:\n");
	scanf("%d", &conta);
	chamaConta(conta);
	printf("Digite o numero da conta destino:\n");
	scanf("%d", &dest);
	if((strcmp(cadastro[dest-1].situacao, cadastro[conta-1].situacao))==0)
	{
		
	 printf("Digite o valor a ser transferido:\n");
	 scanf("%f", &valor);
    	if (valor <= cadastro[conta - 1].saldo)
    	{
		printf("\n\nPor favar, confirme os dados abaixo:\n\n");
		printf("Conta destino:\n");
		printf("Titular: %s\nConta: %d\n", cadastro[dest - 1].nome, dest);
		printf("Valor da transferencia: %.2f\n", valor);
		printf("Confirmar transacao?\n1-Sim\n2-Nao\n");
		scanf("%d", &opc);
		switch(opc)
		{
		case 1:
			cadastro[conta - 1].saldo = cadastro[conta - 1].saldo - valor;
			cadastro[dest - 1].saldo = cadastro[dest - 1].saldo + valor;
			printf("Transacao efetuada com sucesso!\n");
			printf("Seu nome saldo e:  %.2f\n", cadastro[conta - 1].saldo);
			system("pause");
			break;
		case 2:
			printf("\nOperacao cancelada\n");
			system("pause");
			break;
		default:
			printf("Opcao invalida!\n");
			system("pause");
			break;
		}
	}
		else{
		printf("Voce nao tem saldo disponivel para essa operacao!\n");
		system("pause");
	   	}
	}
	else{
		printf("Essa conta encontra-se cancelada pelo usuario\n Impossivel realizar operacao\n");
		system("pause");
	}
}
void chamaConta(int conta)  //sempre os argumentos ficam dentro dos parenteses
{
	if (cadastro[conta - 1].conta) //isso vai prevenir a impressao de contas vazias do vetor
	{
		printf("Nome: %s\n", cadastro[conta - 1].nome);
		printf("Conta: %d\n", cadastro[conta - 1].conta);
		printf("Saldo: %.2f\n", cadastro[conta - 1].saldo);
		printf("Status: %s\n\n", cadastro[conta-1].situacao);
	}
}
void listaConta()  //verificar essa parte do cógido!
{
	int i;
	for(i=0;i<=NUM_CONTAS;i++){ //faz o backup das contas que serao usadas para o cadastro auxilir
		strcpy(usual[i].nome,cadastro[i].nome);
		usual[i].conta=cadastro[i].conta;
		usual[i].saldo=cadastro[i].saldo;
		strcpy(usual[i].situacao, cadastro[i].situacao);
	}
	system("cls");
	printf("Existem as seguintes contas cadastradas:\n");
	quick(cadastro, 0, NUM_CONTAS-1);
	for(i = 1; i <= NUM_CONTAS; i++) // vai imprimir qualquer valor diferente de zero
	{
		chamaConta(i);
	}
	system("pause");
	for(i=0;i<=NUM_CONTAS;i++){
		strcpy(cadastro[i].nome,usual[i].nome); //restaura o backup
		cadastro[i].conta=usual[i].conta;
		cadastro[i].saldo=usual[i].saldo;
        strcpy(cadastro[i].situacao, usual[i].situacao);
}
}

void lerArq()
{
	FILE* arq = fopen("banco.bin", "r");
	if (arq)
	{
		fscanf(arq, "%d", &ultima_conta);
		fread(cadastro, sizeof(struct cliente), NUM_CONTAS, arq);
		fclose(arq);
	}
	else
	{
		printf("falha ao ler o arquivo! Será criado um novo\n");
		system("pause");
	}
}

void escArq()
{
	FILE* arq = fopen("banco.bin", "w");
	if (arq)
	{
		fprintf(arq, "%d", ultima_conta);
		fwrite(cadastro , sizeof(struct cliente), NUM_CONTAS, arq); 	//1° o nome da variavel, depois a funcao sizeof vai pegar
		fclose(arq);  	   	   	   	   	   	   	   	   	     	 // o tamanho, depois o lugar em que sera gravado
	}
	else
	{
		printf("Erro ao abrir arquivo\n");
		system("pause");
	}
}
void cancelaConta(int conta){
	int opc;
	fflush(stdin);
	printf("Voce esta prestes a desativar sua conta. Tem certeza que deseja continuar?\n");
	printf("1-Sim\n2-Nao\n");
	scanf("%d", &opc);
	switch(opc)
	{
		case 1:
			sprintf(cadastro[conta-1].situacao, "Desativada pelo usuario");
			printf("Sua conta foi desativada com sucesso! Se desejar, podera recuperar seu mesmo numero de conta novamente. Retire seu dinheiro, por favor.\n");
			cadastro[conta-1].saldo=0;
			system("pause");
			return;
			break;
		case 2:
			printf("Voltando ao menu principal!\n");
			system("pause");
			return;
			break;
		default:
			printf("Opcao invalida\n");
			return;
			break;
			
	}
}
void quick(struct cliente vet[], int esq, int dir) //estudar essa parte (quicksort-metodo de ordenação de vetores)
{
	struct cliente c;
	int pivo = esq, i, j;
	char ch[30];
	for(i = esq + 1; i <= dir; i++)
	{
		j = i;
		if(vet[j].conta && strcmp(vet[j].nome, vet[pivo].nome) < 0)
		{
			strcpy(ch, vet[j].nome);
			c=vet[j];
			while(j > pivo)
			{
				strcpy(vet[j].nome, vet[j - 1].nome);
				vet[j].saldo=vet[j-1].saldo;
				vet[j].conta=vet[j-1].conta;
				strcpy(vet[j].situacao, vet[j-1].situacao);
				j--;
			}
			strcpy(vet[j].nome, ch);
			vet[j].saldo=c.saldo;
			vet[j].conta=c.conta;
			strcpy(vet[j].situacao, c.situacao);
			pivo++;
		}
	}
	if(pivo - 1 >= esq)
	{
		quick(vet, esq, pivo - 1);
	}
	if(pivo + 1 <= dir)
	{
		quick(vet, pivo + 1, dir);
	}
}
int main()
{
	int opc, conta;
	lerArq();
	conta = ultima_conta;
	for(;;)
	{
		system("cls");
		printf("Bem vindo ao simulador de banco\n O que deseja fazer?\n");
		printf("1-Criar uma nova conta\n2-Consultar conta\n3-Realizar Saque\n4-Realizar Deposito\n5-Realizar transferencia\n6-Listar contas cadastradas\n7-Sair\n");
		scanf("%d", &opc);
		switch(opc)
		{
		case 1:
			criacao_de_conta(&conta);
			escArq();
			break;
		case 2:
			consulta();
			escArq();
			break;
		case 3:
			saque();
			escArq();
			break;
		case 4:
			deposito();
			escArq();
			break;
		case 5:
			transf();
			escArq();
			break;
		case 6:
			listaConta();
			break;
		case 7:
			return 0;
			break;
		default:
			printf("Operacao invalida! Por favor, leia novamente e escolha a opcao correta.");
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}
