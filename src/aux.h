/*----------------------------------------------------------------
  	        	        TRABALHO FINAL AED-1
                                (aux.h)
 -----------------------------------------------------------------

 DESCRIÇÃO:
 ---------
 Bibiloteca que possui os protótipos das funções auxiliares.

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

#ifndef AUX_H
#define AUC_H

/*********************************************
 *          BIBLIOTECAS
 ********************************************/

#include "func.h" //para as estruturas
#include <stdio.h> //para o tipo FILE

/********************************************
 *          DEFINES
 *******************************************/

//Auxiliar para a limpeza da tela de acordo com o sistema operacional do usuário
#ifdef _WIN32 
    #define CLS "cls"//Para sistemas Windows

#elif __linux__ 
    #define CLS "clear"//Para sistemas UNIX/Linux

#endif

/***********************************************
 *          PROTÓTIPOS
 **********************************************/

/**
 * @fn gerador_codigo(int tipo)
 * @brief Gerador de códigos (Produtos | Fornecedores)
 * @param int tipo - Tipo do arquivo em que será contada a quantidade de elementos (structs), ou seja, arquivo de fornecedores, produtos ou colaboradores
 * @return Quantidade de elementos (structs) dentro do arquivo
*/
unsigned long gerador_codigo(int tipo);

/**
 * @fn binary_search(FILE *arq, int ini, int fim, unsigned long cod, int tipo)
 * @brief Pesquisa binária para os códigos
 * @param FILE *arq - Arquivo onde será procurada a struct desejada
 * @param int ini - Byte inicial do arquivo onde a pesquisa será feita
 * @param int fim - Byte final do arquivo onde a pesquisa será feita
 * @param unsigned long cod - Código da struct a ser procurada
 * @param int tipo - Tipo do arquivo a ser pesquisado, ou seja, arquivo de fornecedores, produtos ou colaboradores
 * @return Posição, dentro do arquivo, da struct procurada
*/
int binary_search(FILE *arq, int ini, int fim, unsigned long cod, int tipo);

/**
 * @fn logo_nmagalu(void)
 * @brief Apreseta na tela a logo da varejista "Não-Magalu"
*/
void logo_nmagalu(void);

/**
 * @fn clear(char str[])
 * @brief Limpeza do caractere de quebra de linha das strings e limpeza dos caracteres excedentes no buffer
 * @param char str[] - String em que se deseja retirar o "\n"
*/
void clear(char str[]);

/**
 * @fn print_fornecedor(fornecedor aux_forn)
 * @brief Esta é a função a ser chamada pelas outras funções para apresentar os dados
 * dos fornecedores.
*/
void print_fornecedor(fornecedor aux_forn);

/**
 * @fn print_produto(produtos aux_prod)
 * @brief Esta é a função a ser chamada pelas outras funções para apresentar os dados
 * de produtos.
*/
void print_produto(produtos aux_prod);

/**
 * @fn print_colaboradores(colaborador aux_col)
 * @brief Esta é a função a ser chamada pelas outras funções para apresentar os dados
 * de colaboradores.
*/
void print_colaboradores(colaborador aux_col);

/**
 * @fn confirmar(void)
 * @brief Apresenta um menu de confirmação para a exclusão ou atualização dos dados
 */
int confirmar(void);

#endif