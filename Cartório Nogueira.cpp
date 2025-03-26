#include <stdio.h>  //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h>  //Biblioteca de aloca��o espa�o de mem�ria
#include <locale.h>  //Biblioteca de aloca��es de texto por regi�o
#include <string.h>  //Biblioteca respons�vel por cuidar das string
int registrar()  //Fun��o secundaria que � carregada somente quando � chamada pela fun��a principal
{
    char arquivo[40];  // Definindo vari�veis
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
	
    printf("Digite o CPF a ser cadastrado:");
	scanf("%s",cpf);  // O scanf armazena na vari�vel cpf, o %s indica que � um numero uma string
	
    strcpy(arquivo,cpf);  // O strcpy copia o valor de uma string em outra
    
	FILE *file;  //O "FILE" � uma fun��o pronta do programa e o file cria o programa
	file=fopen(arquivo,"w");  // O fopen abre o "file" com o nome da variavel "arquivo" e o comando "w" escreve no "file"
	fprintf(file,cpf);  // O "fprintf" insere dados da vari�vel "cpf" no arquivo "file"
	fclose(file);  // O fclose fecha o arquivo "file"
	
	file=fopen(arquivo,"a");  // O fopen abre o "file" com o nome da variavel "arquivo" e o comando "a" atualiza/adiciona conteudo ao "file"
	fprintf(file,",");  // O "fprintf" insere os dados que estam entre as "aspas" no arquivo "file"
	fclose(file);  // O fclose fecha o arquivo "file"
	
	printf("digite o nome a ser cadastrado:");
	scanf("%s",nome);  // O scanf armazena na vari�vel nome, o %s indica que � um numero uma string
	
	file=fopen(arquivo,"a");  // O fopen abre o "file" com o nome da variavel "arquivo" e o comando "a" atualiza/adiciona conteudo ao "file"
	fprintf(file,nome);  // O "fprintf" insere dados da vari�vel "nome" no arquivo "file"
	fclose(file);  // O fclose fecha o arquivo "file"
	
	file=fopen(arquivo,"a");  // O fopen abre o "file" com o nome da variavel "arquivo" e o comando "a" atualiza/adiciona conteudo ao "file"
	fprintf(file,",");  // O "fprintf" insere os dados que estam entre as "aspas" no arquivo "file"
	fclose(file);  // O fclose fecha o arquivo "file"
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s",sobrenome);  // O scanf armazena na vari�vel sobrenome, o %s indica que � um numero uma string
	
	  file=fopen(arquivo,"a");  // O fopen abre o "file" com o nome da variavel "arquivo" e o comando "a" atualiza/adiciona conteudo ao "file"
	fprintf(file,sobrenome);  // O "fprintf" insere dados da vari�vel "sobrenome" no arquivo "file"
	fclose(file);  // O fclose fecha o arquivo "file"
	
	file=fopen(arquivo,"a");  // O fopen abre o "file" com o nome da variavel "arquivo" e o comando "a" atualiza/adiciona conteudo ao "file"
	fprintf(file,",");  // O "fprintf" insere os dados que estam entre as "aspas" no arquivo "file"
	fclose(file);  // O fclose fecha o arquivo "file"
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s",cargo);  // O scanf armazena na vari�vel cargo, o %s indica que � um numero uma string
	
	file=fopen(arquivo,"a");  // O fopen abre o "file" com o nome da variavel "arquivo" e o comando "a" atualiza/adiciona conteudo ao "file"
	fprintf(file,cargo);  // O "fprintf" insere dados da vari�vel "cargo" no arquivo "file"
	fclose(file);  // O fclose fecha o arquivo "file"
	
	system("pause");  // Comando para pausar a tela do programa
}

int consultar()  //Fun��o secundaria que � carregada somente quando � chamada pela fun��a principal
{
	
	setlocale(LC_ALL, "portuguese"); // O setlocale define a linguagem
	
	char cpf[40];  // Definindo vari�veis
	char conteudo[500];
	
	printf ("Digite o CPF a ser consultado:");
	scanf("%s",cpf);  // O scanf armazena na vari�vel cpf, o %s indica que � um numero uma string
	
	FILE *file;  //O "FILE" � uma fun��o pronta do programa e o file cria o programa
	file=fopen(cpf,"r");  // O fopen abre o "file" com o nome da vari�vel "cpf" e o comando "r" l� o arquivo "file"
	
	if(file==NULL)  // Opera��o de compara��o para o caso do arquivo n�o ser encontrado 
	{
		printf("CPF incerido n�o encontrado!.\n");
	}
	while(fgets(conteudo,200,file)!=NULL)  // La�o de repeti��o para armazenar o conteudo do "file" na vari�vel conteudo
	{
		printf("\nEssas s�o as informa��es do usuario:");
		printf("%s",conteudo);  // O "printf" mostra na tela o que esta na vari�vel conteudo
		printf("\n\n");
	}
	system("pause");  // Comando para pausar a tela do programa
}

int deletar()  //Fun��o secundaria que � carregada somente quando � chamada pela fun��a principal
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40];
	
	printf ("digite o CPF do usu�rio a ser deletado! \n");
	scanf ("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file=fopen(cpf,"r");
	
	if(file==NULL)
	{
		printf("CPF do usu�rio n�o encontrado! \n");
		system("pause");
	}
	
	system("pause");
}

int main() // Fun��o principal
{
	
	int opcao=0; // Definindo vari�veis
	int x=1;
	
	
	for(x=1;x=1;)  //O "for" cria um lo�o de repeti��o
  { 
	system("cls");  // Comando para limpar a tela
	
	setlocale(LC_ALL, "portuguese"); // O setlocale define a linguagem 
	
	printf("####Cart�rio Nogueira####\n\n");   // Inicio do menu
	printf("Escolha a op��o desejada\n\n");  // O \n pula uma linha na tela
	printf("\t1Registrar nomes\n");          // O \t da um espa�amento na tela
	printf("\t2Consultar nomes\n");
	printf("\t3Deletar nomes\n");
	printf("\t4Sair do sistema\n\n\n");
	printf("Op��o:");                          // Fim do menu
	
	scanf("%d", &opcao);  //O scanf armazena na variavel opcao, o %d indica que � um numero inteiro
	
	system("cls");  // Comando para limpar a tela
	
	switch(opcao)  // Inicio da sele��o||Opera��o de decis�o  // O switch indica uma escolha
	{
		case 1:  // O case inicia a opera��o
			registrar();
		break;  // O break finaliza a opera��o
		
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
			printf("essa op��o est� indisponivel!\n");
			system("pause");  // Comando para pausar a tela do programa
		break;
		          // Fim da sele��o
	}   
  }
}



