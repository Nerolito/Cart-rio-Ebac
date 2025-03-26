#include <stdio.h>  //Biblioteca de comunicação com o usuário
#include <stdlib.h>  //Biblioteca de alocação espaço de memória
#include <locale.h>  //Biblioteca de alocações de texto por região
#include <string.h>  //Biblioteca responsável por cuidar das string
int registrar()  //Função secundaria que é carregada somente quando é chamada pela funçõa principal
{
    char arquivo[40];  // Definindo variáveis
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
	
    printf("Digite o CPF a ser cadastrado:");
	scanf("%s",cpf);  // O scanf armazena na variável cpf, o %s indica que é um numero uma string
	
    strcpy(arquivo,cpf);  // O strcpy copia o valor de uma string em outra
    
	FILE *file;  //O "FILE" é uma função pronta do programa e o file cria o programa
	file=fopen(arquivo,"w");  // O fopen abre o "file" com o nome da variavel "arquivo" e o comando "w" escreve no "file"
	fprintf(file,cpf);  // O "fprintf" insere dados da variável "cpf" no arquivo "file"
	fclose(file);  // O fclose fecha o arquivo "file"
	
	file=fopen(arquivo,"a");  // O fopen abre o "file" com o nome da variavel "arquivo" e o comando "a" atualiza/adiciona conteudo ao "file"
	fprintf(file,",");  // O "fprintf" insere os dados que estam entre as "aspas" no arquivo "file"
	fclose(file);  // O fclose fecha o arquivo "file"
	
	printf("digite o nome a ser cadastrado:");
	scanf("%s",nome);  // O scanf armazena na variável nome, o %s indica que é um numero uma string
	
	file=fopen(arquivo,"a");  // O fopen abre o "file" com o nome da variavel "arquivo" e o comando "a" atualiza/adiciona conteudo ao "file"
	fprintf(file,nome);  // O "fprintf" insere dados da variável "nome" no arquivo "file"
	fclose(file);  // O fclose fecha o arquivo "file"
	
	file=fopen(arquivo,"a");  // O fopen abre o "file" com o nome da variavel "arquivo" e o comando "a" atualiza/adiciona conteudo ao "file"
	fprintf(file,",");  // O "fprintf" insere os dados que estam entre as "aspas" no arquivo "file"
	fclose(file);  // O fclose fecha o arquivo "file"
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s",sobrenome);  // O scanf armazena na variável sobrenome, o %s indica que é um numero uma string
	
	  file=fopen(arquivo,"a");  // O fopen abre o "file" com o nome da variavel "arquivo" e o comando "a" atualiza/adiciona conteudo ao "file"
	fprintf(file,sobrenome);  // O "fprintf" insere dados da variável "sobrenome" no arquivo "file"
	fclose(file);  // O fclose fecha o arquivo "file"
	
	file=fopen(arquivo,"a");  // O fopen abre o "file" com o nome da variavel "arquivo" e o comando "a" atualiza/adiciona conteudo ao "file"
	fprintf(file,",");  // O "fprintf" insere os dados que estam entre as "aspas" no arquivo "file"
	fclose(file);  // O fclose fecha o arquivo "file"
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s",cargo);  // O scanf armazena na variável cargo, o %s indica que é um numero uma string
	
	file=fopen(arquivo,"a");  // O fopen abre o "file" com o nome da variavel "arquivo" e o comando "a" atualiza/adiciona conteudo ao "file"
	fprintf(file,cargo);  // O "fprintf" insere dados da variável "cargo" no arquivo "file"
	fclose(file);  // O fclose fecha o arquivo "file"
	
	system("pause");  // Comando para pausar a tela do programa
}

int consultar()  //Função secundaria que é carregada somente quando é chamada pela funçõa principal
{
	
	setlocale(LC_ALL, "portuguese"); // O setlocale define a linguagem
	
	char cpf[40];  // Definindo variáveis
	char conteudo[500];
	
	printf ("Digite o CPF a ser consultado:");
	scanf("%s",cpf);  // O scanf armazena na variável cpf, o %s indica que é um numero uma string
	
	FILE *file;  //O "FILE" é uma função pronta do programa e o file cria o programa
	file=fopen(cpf,"r");  // O fopen abre o "file" com o nome da variável "cpf" e o comando "r" lê o arquivo "file"
	
	if(file==NULL)  // Operação de comparação para o caso do arquivo não ser encontrado 
	{
		printf("CPF incerido não encontrado!.\n");
	}
	while(fgets(conteudo,200,file)!=NULL)  // Laço de repetição para armazenar o conteudo do "file" na variável conteudo
	{
		printf("\nEssas são as informações do usuario:");
		printf("%s",conteudo);  // O "printf" mostra na tela o que esta na variável conteudo
		printf("\n\n");
	}
	system("pause");  // Comando para pausar a tela do programa
}

int deletar()  //Função secundaria que é carregada somente quando é chamada pela funçõa principal
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40];
	
	printf ("digite o CPF do usuário a ser deletado! \n");
	scanf ("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file=fopen(cpf,"r");
	
	if(file==NULL)
	{
		printf("CPF do usuário não encontrado! \n");
		system("pause");
	}
	
	system("pause");
}

int main() // Função principal
{
	
	int opcao=0; // Definindo variáveis
	int x=1;
	
	
	for(x=1;x=1;)  //O "for" cria um loço de repetição
  { 
	system("cls");  // Comando para limpar a tela
	
	setlocale(LC_ALL, "portuguese"); // O setlocale define a linguagem 
	
	printf("####Cartório Nogueira####\n\n");   // Inicio do menu
	printf("Escolha a opção desejada\n\n");  // O \n pula uma linha na tela
	printf("\t1Registrar nomes\n");          // O \t da um espaçamento na tela
	printf("\t2Consultar nomes\n");
	printf("\t3Deletar nomes\n");
	printf("\t4Sair do sistema\n\n\n");
	printf("Opção:");                          // Fim do menu
	
	scanf("%d", &opcao);  //O scanf armazena na variavel opcao, o %d indica que é um numero inteiro
	
	system("cls");  // Comando para limpar a tela
	
	switch(opcao)  // Inicio da seleção||Operação de decisão  // O switch indica uma escolha
	{
		case 1:  // O case inicia a operação
			registrar();
		break;  // O break finaliza a operação
		
		case 2:
			consultar();
		break;
		
		case 3:
			deletar();
		break;
		
		case 4:
			printf("Obrigado por ultilizar o sistema!\n");
			return 0;
		
		default:
			printf("essa opção está indisponivel!\n");
			system("pause");  // Comando para pausar a tela do programa
		break;
		          // Fim da seleção
	}   
  }
}



