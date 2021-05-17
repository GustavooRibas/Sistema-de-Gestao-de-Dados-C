/*----------------------------------------------------------------
  	        	        TRABALHO FINAL AED-1
                              (main.c)
 -----------------------------------------------------------------

 DESCRIÇÃO:
 ---------
 O projeto consiste no desenvolvimento de um sistema de gestão
 de dados de fornecedores, produtos e colaboradores de uma varejista (”Não-Magalu”).
 Elaborado para rodar em linha de comando, o sistema foi desenvolvido em linguagem C
 e permite, além da inserção, pesquisa, alteração e remoção dos dados, apresentar
 um relatório geral dos dados que foram obtidos.

 DESENVOLVEDORES:
 ----------------
  Nome: Diego Enrique da Silva Lima
  Matrícula: 202003556;
  E-mail: diegoenrique@discente.ufg.br

  Nome: Gustavo Rodrigues Ribeiro
  Matrícula: 202003570;
  E-mail: ribeirogustavo@discente.ufg.br;

-----------------------------------------------------------------
 REPOSITÓRIO DO PROJETO: https://github.com/GustavooRibas/Trabalho-Final-AED1
-----------------------------------------------------------------
 DATA DA ÚLTIMA ALTERAÇÃO: 08 de Maio de 2021
----------------------------------------------------------------*/

/*********************************************
 *          BIBLIOTECAS
 ********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "auxi.h"

/***********************************************
 *          PROTÓTIPOS
 **********************************************/

/**
 * @fn menu_principal(void)
 * @brief Display de ações a serem realizadas no menu principal
*/
int menu_principal(void);

/**
 * @fn gerenciar_fornecedores(void)
 * @brief Display de ações a serem realizadas no gerenciador de fornecedores, sendo elas:
 * Inserir, atualizar, remover, pesquisar e apresentar relatório geral de fornecedores. Apresenta
 * na tela uma opção de sair do menu de fornecedores.
*/
void gerenciar_fornecedor(void);

/**
 * @fn gerenciar_produtos(void)
 * @brief Display de ações a serem realizadas no menu gerenciador de produtos, sendo elas:
 * Atualizar, remover, pesquisar e apresentar relatório geral de produtos. Apresenta
 * na tela uma opção de sair do menu de produtos.
*/
void gerenciar_produtos(void);

/**
 * @fn gerenciar_colaborador(void)
 * @brief Display de ações a serem realizadas no menu gerenciador de colaboradores, sendo elas:
 * Inserir, atualizar, remover, pesquisar e apresentar relatório geral de colaboradores. Apresenta
 * na tela uma opção de sair do menu de colaboradores.
*/
void gerenciar_colaborador(void);

/********************************************
 *              MAIN
 *******************************************/

int main(void)
{
  int resp; //variável para obter a resposta do menu_principal

    system(CLS); //limpar a tela do usuário antes de iniciar de fato o código
    resp = menu_principal();

    while (resp != 4)
    {
        switch (resp)
        {
            case 1:
                gerenciar_fornecedor();
                break;
            case 2:
                gerenciar_produtos();
                break;
            case 3:
                gerenciar_colaborador();
        }

        resp = menu_principal();
    }


    exit(0);
}

/*********************************************
 *      IMPLEMENTAÇÃO DAS FUNÇÕES
 ********************************************/
//Menu Principal
int menu_principal(void)
{
    int res = -1; //variável para guardar a resposta

    while (res < 1 || res > 4)
    {
        logo_nmagalu();
        printf(" Escolha uma das seguintes opcoes:\n\n");
        printf(" 1 - Gerenciar Fornecedores\n");
        printf(" 2 - Gerenciar Produtos\n");
        printf(" 3 - Gerenciar Colaboradores\n");
        printf(" 4 - Sair\n");
        printf("-----------------------------------------------------------------------------------\n");
        printf("OPCAO: ");
        scanf("%d", &res);
        getchar();

        system(CLS);
    }

    return res;
}

//Gerenciar Fornecedores
void gerenciar_fornecedor(void)
{
    int res = 0; //variável para guardar a resposta

    while (res != 6)
    {
        res = 0;
        while (res < 1 || res > 6)
        {
            printf("--------------------------------------\n\n");
            printf("     GERENCIADOR DE FORNECEDORES     \n\n");
            printf("--------------------------------------\n");
            printf(" Escolha uma das seguintes opcoes:\n\n");
            printf(" 1 - INSERIR fornecedor \n");
            printf(" 2 - PESQUISAR fornecedor \n");
            printf(" 3 - ATUALIZAR fornecedor \n");
            printf(" 4 - REMOVER fornecedor \n");
            printf(" 5 - APRESENTAR RELATORIO GERAL \n");
            printf(" 6 - Sair\n");
            printf("--------------------------------------\n");
            printf("OPCAO: ");
            scanf("%d", &res);
            getchar();

	        system(CLS);
        }

        switch (res)
        {
            case 1:
                inserir_fornecedor();
                break;
            case 2:
                pesquisar_fornecedor();
                break;
            case 3:
                atualizar_fornecedor();
                break;
            case 4:
                remover_fornecedor();
                break;
            case 5:
                relatorio_geral_forn();
                break;
        }

    	system(CLS);
    }
}

//Gerenciar Produtos
void gerenciar_produtos(void)
{
    int res = 0; //variável para guardar a resposta

    while (res != 5)
    {
        res = 0;
        while (res < 1 || res > 5)
        {
            printf("--------------------------------------\n\n");
            printf("        GERENCIADOR DE PRODUTOS       \n\n");
            printf("--------------------------------------\n");
            printf(" Escolha uma das seguintes opcoes:\n\n");
            printf(" 1 - PESQUISAR produto \n");
            printf(" 2 - ATUALIZAR produto \n");
            printf(" 3 - REMOVER produto \n");
            printf(" 4 - APRESENTAR RELATORIO GERAL \n");
            printf(" 5 - Sair\n");
            printf("--------------------------------------\n");
            printf("OPCAO: ");
            scanf("%d", &res);
            getchar();


	        system(CLS);
        }


        switch (res)
        {
            case 1:
                pesquisar_produto();
                break;
            case 2:
                atualizar_produto();
                break;
            case 3:
                remover_produto();
                break;
            case 4:
                relatorio_geral_prod();
                break;
        }

	    system(CLS);
    }
}

//Gerenciar colaboradores
void gerenciar_colaborador(void)
{
    int res = 0; //variável para guardar a resposta

    while (res != 6)
    {
        res = 0;
        while (res < 1 || res > 6)
        {
            printf("--------------------------------------\n\n");
            printf("     GERENCIADOR DE COLABORADORES     \n\n");
            printf("--------------------------------------\n");
            printf(" Escolha uma das seguintes opcoes:\n\n");
            printf(" 1 - INSERIR colaborador \n");
            printf(" 2 - PESQUISAR colaborador \n");
            printf(" 3 - ATUALIZAR colaborador \n");
            printf(" 4 - REMOVER colaborador \n");
            printf(" 5 - APRESENTAR RELATORIO GERAL \n");
            printf(" 6 - Sair\n");
            printf("--------------------------------------\n");
            printf("OPCAO: ");
            scanf("%d", &res);
            getchar();

	        system(CLS);
        }

        switch (res)
        {
            case 1:
                inserir_colaborador();
                break;
            case 2:
                pesquisar_colaborador();
                break;
            case 3:
                atualizar_colaborador();
                break;
            case 4:
                remover_colaborador();
                break;
            case 5:
                relatorio_geral_col();
                break;
        }

    	system(CLS);
    }
}
