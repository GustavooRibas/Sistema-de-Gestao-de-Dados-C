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
enum {NOM = 41, DESC = 101, EXC =  1, NEXC = 0, QUANT_PROD = 10, END = 41, UF = 3, CARAC_A = 13};

//Constantes bases para o funcionamento do sistema
#define WIN 0
#define LUX 1

#define LWIN system("cls")
#define LLUX system("clear")


//Constantes de definição dos arquivos
#define FORN  0
#define PROD  1

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

//Pesquisa binária para os códigos
int binary_search(FILE *arq, int ini, int fim, int cod);

//Gerador de códigos (Produtos | Fornecedores)
int gerador_codigo(int tipo);

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

void inserir_produto(int codigo);

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

//Pesquisa binária dos códigos
int binary_search(FILE *arq, int ini, int fim, int cod, int tipo)
{
    buff_arquiv[CARAC_A];

    if (tipo)
    {
        strcpy(buff_arquiv, A_PROD);
        produtos aux_prod;

        while (fim >= ini)
        {
            int mid = (ini + fim) / 2;

            fseek(arq, mid, SEEK_SET);
            fread(&aux_prod, sizeof(produtos), 1, arq);

            if (aux_prod.cod_produto == cod)
            {
                fseek(arq, sizeof(produtos)*(-1), SEEK_CUR);
                return ftell(arq);
            }

            else
            {
                if (aux_prod.cod_produto > cod)
                {
                    mid = ini + 1;
                }

                else
                {
                    mid = fim - 1;
                }
            }

        }
    }

    else
    {
        strcpy(buff_arquiv, A_FORN);
        fornecedor aux_forn;

        while (fim >= ini)
        {
            int mid = (ini + fim) / 2;

            fseek(arq, mid, SEEK_SET);
            fread(&aux_forn, sizeof(fornecedor), 1, arq);

            if (aux_forn.cod_fornecedor == cod)
            {
                fseek(arq, sizeof(fornecedor)*(-1), SEEK_CUR);
                return ftell(arq);

            }

            else if (aux_forn.cod_fornecedor > cod) mid = ini + 1;

            else mid = fim - 1;
        }
    }

    return -1;
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

//Gerador de códigos (Produtos | Fornecedores)
int gerador_codigo(int tipo)
{
    int quant = 0;

    char buff_nome_arquivo[CARAC_A];

    if (tipo)
    {
         strcpy(buff_nome_arquivo, A_PROD);
    }
    else
    {
        strcpy(buff_nome_arquivo, A_FORN);
    }

    FILE *arquiv = fopen(buff_nome_arquivo, "rb");
    if (!arquiv)
    {
        //caso ainda não tenha um arquivo contendo os dados
        return 1;
    }

    if (tipo)
    {
        produtos aux_prod;

        while (!feof(arquiv))
        {
            quant++;
            fread(&aux_prod, sizeof(produtos), 1, arquiv);
        }
    }
    else
    {
        fornecedor aux_forn;
        while(!feof(arquiv))
        {
            quant++;
            fread(&aux_forn, sizeof(fornecedor), 1, arquiv);
        }
    }

    fclose(arquiv);

    return quant
}

//Inserir
void inserir_fornecedor(void);

void inserir_produto(int codigo)
{
    produtos aux_prod;
    int quant_prod;
 
    FILE *arq = fopen(A_PROD, "ab");
    if (!arq)
    {
        fprintf(stderr, "Arquivo de produtos não pode ser encontrado\n");
        exit(1);
    }   
   
    memset(&aux_prod, 0, sizeof(aux_prod));

    aux_prod.cod_produto = codigo;
    printf("Código do Produto: %d\n", aux_prod.cod_produto);

    printf("Nome do produto: ");
    fgets(aux_prod.nome_prod, NOM, stdin);
    clear(aux_prod.nome_prod);

    printf("Valor de compra produto: ");
    scanf("%f", &aux_prod.preco_prod);

    printf("Valor de venda do produto: ");
    scanf("%f", &aux_prod.venda_prod);
    getchar();

    printf("Digite uma pequena descrição do produto: ");
    fgets(aux_prod.descricao, DESC, stdin);
    clear(aux_prod.descricao);

    aux_prod.valor_logico = NEXC;

    fwrite(&aux_prod, sizeof(aux_prod), 1, arq);
    
    printf("\n");

    fclose(arq);
}

//Pesquisar
void pesquisar_fornecedor(void);

void pesquisar_produto(void);

//Atualizar
void atualizar_fornecedor(void);

void atualizar_produto(void);

//Remover
void remover_fornecedor(void);

void remover_produto(void);
