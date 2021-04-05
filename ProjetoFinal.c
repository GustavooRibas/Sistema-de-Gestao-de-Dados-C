/*----------------------------------------------
 * 	        	Trabalho final
 *---------------------------------------------
 * Nome: Diego Enrique da Silva Lima
 * Matrícula: 202003556;
 * E-mail: diegoenrique@discente.ufg.br
 *
 * Nome: Gustavo Rodrigues Ribeiro
 * Matrícula: 202003570;
 * E-mail:  ribeirogustavo@discente.ufg.br;
 *
 *--------------------------------------------
 * DATA DE FINALIZAÇÃO:
 * ------------------------------------------*/
//Bibiotecas
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//Constantes Gerais
enum {NOM = 41, DESC = 101, TRUE =  1, FALSE = 0, QUANT_PROD = 10, END = 41, UF = 3};

//Constantes bases para o funcionamento do sistema
#define WIN 0
#define LUX 1

#define LWIN system("cls")
#define LLUX system("clear")

//Constantes para os nomes dos arquivos de fornecedores e produtos
#define A_PROD "Produtos"
#define A_FORN "Fornecedores"

//Variaveis globais
int SO;

//---------------------------------------------------------------------------------
//Estruturas
typedef struct
{
    int cod_produto;
    char nome_prod[NOM];
    float preco_prod;
    float venda_prod;
    char descricao[DESC];
    int valor_logico;

}produtos;

typedef struct
{
	int cod_fornecedor;
	char nome_forn[NOM];
	int quant_produtos;
	int cod_produtos[QUANT_PROD];
	char rua[END];
    char bairro[END];
    int CEP;
    char cidade[END];
    char UF[UF];
	int valor_logico;

}fornecedor;

//-----------------------------------------------------------------------------
//Protótios das funções utilizadas

//Geranciador de códigos (Produtos | Fornecedores)
//Ainda falta o protótipo

//Logo do Projeto Não-Magalu
void logo_nmagalu(void);

//Limpeza do "\n" das strings
void clear(char str[]);

//Limpeza de tela
void limp_tela(void);

//Confirmação
int confirmar(void);

//Confirmação do Sistema Operaçional
int sistema(void);

//Menu Principal
int menu_principal(void);

//Gerenciar Fornecedores
void gerenciar_fornecedor(void);

//Gerenciar Produtos
void gerenciar_produtos(void);

//Inserir
void inserir_fornecedor(void);

void inserir_froduto(int codigo);

//Pesquisar
void pesquisar_fornecedor(void);

void pesquisar_produto(void);

//Atualizar
void atualizar_fornecedor(void);

void atualizar_produto(void);

//Remover
void remover_fornecedor(void);

void remover_produto(void);
//-------------------------------------------------------------------------------


int main(void)
{
  int resp;

    SO = sistema();
    resp = menu_principal();

    while (resp != 3)
    {
        switch (resp)
        {
            case 1:
                gerenciar_fornecedor();
                break;
            case 2:
                gerenciar_produtos();
                break;
        }

        resp = menu_principal();
    }


    exit(0);
}

//Logo do Projeto Não-Magalu
void logo_nmagalu(){

    printf("-----------------------------------------------------------------------------------\n\n");
    printf("           _   __                        __  ___                  __     \n");
    printf("          / | / /___ _____              /  |/  /___ _____ _____ _/ /_  __\n");
    printf("         /  |/ / __ `/ __ \\   ______   / /|_/ / __ `/ __ `/ __ `/ / / / /\n");
    printf("        / /|  / /_/ / /_/ /  /_____/  / /  / / /_/ / /_/ / /_/ / / /_/ / \n");
    printf("       /_/ |_/\\__,_/\\____/           /_/  /_/\\__,_/\\__, /\\__,_/_/\\__,_/  \n");
    printf("                                                  /____/                 \n");
    printf("-----------------------------------------------------------------------------------\n");

}

//Limpeza do "\n" das strings
void clear(char str[])
{
    int c = strlen(str);
    if (str[c - 1] == '\n') str[c - 1] = 0;
    else while(getchar() != '\n');
}

//Limpeza de tela
void limp_tela(void)
{
    if (SO) LLUX;
	else LWIN;
}

//Confirmação
int confirmar(void)
{
    char resp = ' ';

    while (resp != 's' && resp != 'S' && resp != 'n' && resp != 'N')
    {
        printf("-----------------------------------------------------------------\n\n");
        printf("Tem certeza? - Os dados não poderão ser recuperados [S-s/N-n]: ");
        scanf("%c", &resp);
        limp_tela();
    }
    if (resp == 'n' || resp == 'N') return 0;
    else return 1;
}

//Confirmação do Sistema Operaçional
int sistema(void)
{
    int res = -1;

    while (res < 1 || res > 2)
    {
        printf("--------------------------------------\n");
        printf("               AJUSTES                \n");
        printf("--------------------------------------\n");
        printf(" Escolha o Sistema Operacional:\n\n");
        printf(" 1 - Windows\n");
        printf(" 2 - UNIX/Linux\n");
        printf("--------------------------------------\n");
        printf("OPCAO: ");
        scanf("%d", &res);

    }
    res--;
    if (res == WIN)
    {
        LWIN;
        return 0;
    }
    LLUX;
    return 1;
}

//Menu Principal
int menu_principal(void)
{
    int res = -1;

    while (res < 1 || res > 3)
    {
        logo_nmagalu();
        printf(" Esolha uma das seguintes opçõess:\n\n");
        printf(" 1 - Gerenciar Fornecedores\n");
        printf(" 2 - Gerenciar Produtos\n");
        printf(" 3 - Sair\n");
        printf("-----------------------------------------------------------------------------------\n");
        printf("OPCAO: ");
        scanf("%d", &res);

        limp_tela();
    }

    return res;
}

//Gerenciar Fornecedores
void gerenciar_fornecedor(void)
{
    int res = 0;


    while (res != 6)
    {
        res = 0;
        while (res < 1 || res > 6)
        {
            printf("--------------------------------------\n\n");
            printf("     GERENCIADOR DE FORNECEDORES     \n\n");
            printf("--------------------------------------\n");
            printf(" Esolha uma das seguintes opções:\n\n");
            printf(" 1 - INSERIR fornecedor \n");
            printf(" 2 - PESQUISAR fornecedor \n");
            printf(" 3 - ATUALIZAR fornecedor \n");
            printf(" 4 - REMOVER fornecedor \n");
            printf(" 5 - APRESENTAR RELATÓRIO GERAL \n");
            printf(" 6 - Sair\n");
            printf("--------------------------------------\n");
            printf("OPCAO: ");
            scanf("%d", &res);


	        limp_tela();
        }

        switch (res)
        {
            case 1:

                break;
            case 2:
                break;
            case 3:

                break;
            case 4:
                break;
        }

    	limp_tela();
    }
}

//Gerenciar Produtos
void gerenciar_produtos(void)
{
    int res = 0;


    while (res != 5)
    {
        res = 0;
        while (res < 1 || res > 5)
        {
            printf("--------------------------------------\n\n");
            printf("        GERENCIADOR DE PRODUTOS       \n\n");
            printf("--------------------------------------\n");
            printf(" Esolha uma das seguintes opções:\n\n");
            printf(" 1 - PESQUISAR produto \n");
            printf(" 2 - ATUALIZAR produto \n");
            printf(" 3 - REMOVER produto \n");
            printf(" 4 - APRESENTAR RELATÓRIO GERAL \n");
            printf(" 5 - Sair\n");
            printf("--------------------------------------\n");
            printf("OPCAO: ");
            scanf("%d", &res);


	        limp_tela();
        }


        switch (res)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
        }

	    limp_tela();
    }
}

//Geranciador de códigos (Produtos | Fornecedores)
//Ainda falta o protótipo

//Inserir
void Inserir_Fornecedor(void);

void Inserir_Produto(int codigo);

//Pesquisar
void Pesquisar_Fornecedor(void);

void Pesquisar_Produto(void);

//Atualizar
void Atualizar_Fornecedor(void);

void Atualizar_Produto(void);

//Remover
void Remover_Fornecedor(void);

void Remover_Produto(void);
