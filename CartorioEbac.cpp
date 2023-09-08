#include <stdio.h> // Biblioteca de comunicaçõa com o usuário
#include <stdlib.h> // Biblioteca de alocação de memória
#include <locale.h> // Biblioteca de alocações de texto por região
#include <string.h> // Biblioteca das strings


int registroLogin()
{

}
	

int registro()
{
	char arquivo[40];  
	char cpf[11];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o cpf para cadastro: ");
	scanf("%s",cpf);
	
	strcpy(arquivo, cpf); // função para copiar os valores da string
	

	FILE *file;   // criando o arquivo
	file = fopen(arquivo, "w");   // abrindo e criando o arquivo
	fprintf(file," Cpf: ");
	fprintf(file,cpf);	  // salvando o valor da variável
	fclose(file);      // fechando o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n Nome:  ");
	fclose(file);
	
	printf("Digite o nome para cadastro: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n Sobrenome: ");
	fclose(file);
	
	printf("Digite o sobrenome para cadastro: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n Cargo:  ");
	fclose(file);
	
	printf("Digite o cargo para cadastro: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); 
	
	char cpf[11];
	char conteudo[200];
	
	printf("Digite o cpf para consulta: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Arquivo não encontrado! \n");
	}
	
	printf("\nEssas são as informações do usuário: \n\n");
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	

	
}

int deletar()
{
	char cpf[11];
	
	printf("Digite o cpf para exclusão: ");
	scanf("%s", cpf);
	

	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("Cpf não encontrado no sistema! \n");
		system("pause");
		
	}
	else
	{
		
		fclose(file);
    	remove(cpf);
		printf("Cpf deletado com sucesso!! \n");
		system("pause");
	  
	}
	

}

int main()
{
	
	int opcao=0; //Iniciando as variáveis
	int laco=1;
	int returnSenha;
	int returnLogin;
	
	
	printf("        ## Cartório EBAC ##    \n\n    ");
	
	char login[11];  
	char loginCpf[11];
	char loginCpf1[11];
	char senha[10];
	char loginSenha[10];

	
	printf("Digite o cpf para cadastro de login: "); // cadastro do login
	scanf("%s",loginCpf); 
	
	strcpy(login, loginCpf); // função para copiar os valores da string
	

	FILE *file;   // criando o arquivo
	file = fopen(login, "w");   // abrindo e criando o arquivo login
	fprintf(file," Cpf: ");
	fprintf(file,login);	  // salvando o valor da variável
	fclose(file);      // fechando o arquivo
	
	file = fopen(login, "a");
	fprintf(file,"\n Senha:");
	fclose(file);
	
	printf("Digite a senha: "); // Criando a senha
	scanf("%s",loginSenha);
	
	file = fopen(login, "a");  // salvando no arquivo
	fprintf(file,loginSenha);
	fclose(file);
	
	printf("Cadastro realizado com sucesso!! \n\n");
	
	system("pause");
	
	printf("Digite login: ");   // logando no sistema
	scanf("%s", loginCpf1);
	printf("\n Digite a senha: ");
	scanf("%s", senha);
	

	file = fopen(loginCpf1,"r");
	
	
	returnSenha = strcmp(senha,loginSenha);  // Validando login e senha
	returnLogin = strcmp(loginCpf,loginCpf1);
	
	if (returnSenha == 0 && returnLogin == 0)
	{
		for (laco=1;laco=1;)
		{
	
	
			system("cls");
	
			setlocale(LC_ALL, "Portuguese"); // início do menu
			printf("        ## Cartório EBAC ##    \n\n    ");
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 Registrar nomes\n");
			printf("\t2 Constular nomes\n");
			printf("\t3 Excluir nomes\n"); 
			printf("\t4 Sair do sistema \n");
			printf("opção: "); // fim do menu
	
	
			scanf("%d", &opcao); //armazenando a escolha do usuário
	
			system ("cls");
	
			switch (opcao)
			{
				case 1:
				registro();
				break;
			
				case 2:
				consultar();
				break;
			
				case 3:
				deletar();
				break;
			
				case 4:
				printf("Sistema encerrado!!\n");
				return(0);
				break;
			
				default:
				printf ("Esta opção não está disponível \n");
				system("pause");
				break;
			
			}
		
		}
	}
	else
	printf("Senha inválida!!");
	system("pause");
}

