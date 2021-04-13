/*----------------------------------------------
  	        	Trabalho final
 -----------------------------------------------
  Nome: Diego Enrique da Silva Lima
  Matrícula: 202003556;
  E-mail: diegoenrique@discente.ufg.br

  Nome: Gustavo Rodrigues Ribeiro
  Matrícula: 202003570;
  E-mail: ribeirogustavo@discente.ufg.br;

 --------------------------------------------
   DATA DE FINALIZAÇÃO:
 --------------------------------------------*/
//Bibiotecas
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Constantes Gerais
enum {NOM = 41, DESC = 101, EXC =  1, NEXC = 0, QUANT_PROD = 10, END = 41, UF = 3, CARAC_A = 13, NUM_CNPJ = 15};

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
    unsigned long cod_produto;
    char nome_prod[NOM];
    float preco_prod;
    float venda_prod;
    char descricao[DESC];
    int valor_logico;

}produtos;

typedef struct
{
    int dia;
    int mes;
    int ano;
}data;

typedef struct
{
	unsigned long cod_fornecedor;
	char nome_forn[NOM];
	int quant_produtos;
	unsigned long cod_produtos[QUANT_PROD];
	char CNPJ[NUM_CNPJ];
	char rua[END];
    char bairro[END];
    int CEP;
    char cidade[END];
    char UF[UF];
    int telefone;
    data inicio_rel;
    data final_rel;
	int valor_logico;

}fornecedor;

//-----------------------------------------------------------------------------
//Protótios das funções utilizadas

//Pesquisa binária para os códigos
int binary_search(FILE *arq, int ini, int fim, unsigned long cod, int tipo);

//Gerador de códigos (Produtos | Fornecedores)
unsigned long gerador_codigo(int tipo);

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

void pesquisar_produto_forn(unsigned long codigo);

void pesquisar_produto(void);

//Atualizar
void atualizar_fornecedor(void);

void atualizar_produto(void);

//Remover
void remover_fornecedor(void);

void remover_produto(void);

//Relatório geral
void relatorio_geral_prod(void);

void relatorio_geral_forn(void);

//-------------------------------------------------------------------------------


int main(void)
{
  setlocale(LC_ALL, "portuguese-brazilian");
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
int binary_search(FILE *arq, int ini, int fim, unsigned long cod, int tipo)
{
    char buff_arquiv[CARAC_A];

    if (tipo)
    {
        strcpy(buff_arquiv, A_PROD);
        produtos aux_prod;

        while (fim >= ini)
        {
            int mid = (ini + fim) / 2;

            fseek(arq, mid * sizeof(produtos), SEEK_SET);
            fread(&aux_prod, sizeof(produtos), 1, arq);

            if (aux_prod.cod_produto == cod)
            {
                fseek(arq, sizeof(produtos)*(-1), SEEK_CUR);
                return ftell(arq);
            }

            else
            {
                if (aux_prod.cod_produto < cod)
                {
                    ini = mid + 1;
                }

                else
                {
                    fim = mid - 1;
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

            fseek(arq, mid * sizeof(fornecedor), SEEK_SET);
            fread(&aux_forn, sizeof(fornecedor), 1, arq);

            if (aux_forn.cod_fornecedor == cod)
            {
                fseek(arq, sizeof(fornecedor)*(-1), SEEK_CUR);
                return ftell(arq);

            }

            else if (aux_forn.cod_fornecedor < cod) ini = mid + 1;

            else fim = mid - 1;
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
        printf("Tem certeza? - Os dados nao poderao ser recuperados [S-s/N-n]: ");
        scanf("%c", &resp);
        getchar();
        printf("\n");
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
        getchar();

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
        printf(" Escolha uma das seguintes opcoes:\n\n");
        printf(" 1 - Gerenciar Fornecedores\n");
        printf(" 2 - Gerenciar Produtos\n");
        printf(" 3 - Sair\n");
        printf("-----------------------------------------------------------------------------------\n");
        printf("OPCAO: ");
        scanf("%d", &res);
        getchar();

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

	        limp_tela();
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


	        limp_tela();
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

	    limp_tela();
    }
}

//Gerador de códigos (Produtos | Fornecedores)
unsigned long gerador_codigo(int tipo)
{
    unsigned long quant = 0;

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

    return quant;
}

//Inserir
void inserir_fornecedor(void){

    printf("------------------------------------------------------\n\n");
    fornecedor aux_forn;
    int x=0;

    memset(&aux_forn, 0, sizeof(fornecedor));

    aux_forn.cod_fornecedor = gerador_codigo(FORN);
    printf("# Codigo do Fornecedor: %lu\n", aux_forn.cod_fornecedor);
    printf("\n");

    printf("- Nome do fornecedor: ");
    fgets(aux_forn.nome_forn, NOM, stdin);
    clear(aux_forn.nome_forn);

    printf("- CNPJ do fornecedor: ");
    fgets(aux_forn.CNPJ, NUM_CNPJ, stdin);
    clear(aux_forn.CNPJ);


    printf("- Telefone do fornecedor: ");
    scanf("%d", &aux_forn.telefone);
    printf("\n");

    printf("- Quantidade de produtos fornecidos: ");
    scanf("%d", &aux_forn.quant_produtos);
    getchar();
    printf("\n");

    for(x=0; x<aux_forn.quant_produtos; x++){

        printf("* Produto %d\n", x+1);
        aux_forn.cod_produtos[x] = gerador_codigo(PROD);
        inserir_produto(aux_forn.cod_produtos[x]);
    }

    printf("- Data do inicio das relacoes com o fornecedor:\n");

    printf("Dia: ");
    scanf("%d", &aux_forn.inicio_rel.dia);

    printf("Mes: ");
    scanf("%d", &aux_forn.inicio_rel.mes);

    printf("Ano: ");
    scanf("%d", &aux_forn.inicio_rel.ano);
    getchar();
    printf("\n");

    printf("- Endereco do fornecedor\n");

    printf("Rua: ");
    fgets(aux_forn.rua, END, stdin);
    clear(aux_forn.rua);

    printf("Bairro: ");
    fgets(aux_forn.bairro, END, stdin);
    clear(aux_forn.bairro);

    printf("CEP: ");
    scanf("%d", &aux_forn.CEP);
    getchar();

    printf("Cidade: ");
    fgets(aux_forn.cidade, END, stdin);
    clear(aux_forn.cidade);

    printf("UF: ");
    fgets(aux_forn.UF, UF, stdin);
    clear(aux_forn.UF);


    aux_forn.valor_logico = NEXC;

    FILE *arq = fopen(A_FORN, "ab");
    if (!arq)
    {
        fprintf(stderr, "Arquivo de fornecedores nao pode ser encontrado\n");
        exit(1);
    }

    fwrite(&aux_forn, sizeof(fornecedor), 1, arq);

    fclose(arq);

    printf("\n\n (Aperte a tecla Enter para sair)\n\n");
    printf("------------------------------------------------------\n\n");
    getchar();

}

void inserir_produto(int codigo)
{
    printf("----------------\n");
    produtos aux_prod;

    FILE *arq = fopen(A_PROD, "ab");
    if (!arq)
    {
        fprintf(stderr, "Arquivo de produtos nao pode ser encontrado\n");
        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
        return;
    }

    memset(&aux_prod, 0, sizeof(produtos));

    aux_prod.cod_produto = codigo;
    printf("Codigo do Produto: %lu\n", aux_prod.cod_produto);

    printf("Nome do produto: ");
    fgets(aux_prod.nome_prod, NOM, stdin);
    clear(aux_prod.nome_prod);

    printf("Valor de compra produto: ");
    scanf("%f", &aux_prod.preco_prod);

    printf("Valor de venda do produto: ");
    scanf("%f", &aux_prod.venda_prod);
    getchar();

    printf("Digite uma pequena descricao do produto: ");
    fgets(aux_prod.descricao, DESC, stdin);
    clear(aux_prod.descricao);

    aux_prod.valor_logico = NEXC;

    fwrite(&aux_prod, sizeof(produtos), 1, arq);

    printf("\n");

    fclose(arq);
}

//Pesquisar
void pesquisar_fornecedor(void)
{
    fornecedor aux_forn;
    unsigned long aux = gerador_codigo(FORN) - 1;
    unsigned long codigo = 0;
    int posicao;
    int x = 0;

    printf("------------------------------------------------------\n\n");
    printf("Digite o codigo a ser pesquisado: ");
    scanf("%lu", &codigo);
    getchar();
    printf("\n");

    limp_tela();

    FILE *arq = fopen(A_FORN, "r+b");
    if (!arq)
    {

        printf("------------------------------------------------------\n\n");
        fprintf(stderr, "Arquivo de fornecedores nao pode ser encontrado\n");
        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
        return;
    }
    posicao = binary_search(arq, 0, aux, codigo, FORN);

    if (posicao == -1)
    {

        printf("------------------------------------------------------\n\n");
        printf("Codigo inexistente\n");
        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        fclose(arq);
        getchar();
        return;
    }

    fseek(arq, posicao, SEEK_SET);
    fread(&aux_forn, sizeof(fornecedor), 1, arq);

    if (aux_forn.valor_logico == EXC)
    {
        printf("------------------------------------------------------\n\n");
        printf("Codigo inexistente\n");
        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
    }
    else
    {
        printf("------------------------------------------------------\n\n");

        printf("# Codigo do Fornecedor: %lu\n", aux_forn.cod_fornecedor);
        printf("\n");

        printf("- Nome do fornecedor: %s\n", aux_forn.nome_forn);

        printf("- CNPJ do fornecedor: %s\n", aux_forn.CNPJ);

        printf("- Telefone do fornecedor: %d\n\n", aux_forn.telefone);

        printf("- Quantidade de produtos fornecidos: %d\n", aux_forn.quant_produtos);
        printf("\n");

        for(x=0; x<aux_forn.quant_produtos; x++){

            printf("* Produto %d\n", x+1);
            pesquisar_produto_forn(aux_forn.cod_produtos[x]);
        }

        printf("- Data do inicio das relacoes com o fornecedor: %d/%d/%d\n", aux_forn.inicio_rel.dia, aux_forn.inicio_rel.mes, aux_forn.inicio_rel.ano);
        printf("\n");

        printf("- Endereco do fornecedor:\n");

        printf(" Rua: %s\n", aux_forn.rua);
        printf(" Bairro: %s\n", aux_forn.bairro);
        printf(" CEP: %d\n", aux_forn.CEP);
        printf(" Cidade: %s\n", aux_forn.cidade);
        printf(" UF: %s\n", aux_forn.UF);

        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
    }

    fclose(arq);
}

void pesquisar_produto_forn(unsigned long codigo)
{
    produtos aux_prod;
    unsigned long aux = gerador_codigo(PROD) - 1;
    int posicao;

    FILE *arq = fopen(A_PROD, "r+b");
    if (!arq)
    {
        fprintf(stderr, " Arquivo de produtos nao pode ser encontrado\n");
        printf("\n");
        return;
    }
    posicao = binary_search(arq, 0, aux, codigo, PROD);

    if (posicao == -1)
    {
        printf("------------\n");
        printf(" Codigo do Produto: %lu\n", codigo);
        printf(" Codigo inexistente\n");
        fclose(arq);
        printf("\n");
    }

    fseek(arq, posicao, SEEK_SET);
    fread(&aux_prod, sizeof(produtos), 1, arq);

    if (aux_prod.valor_logico == EXC)
    {
        printf("------------\n");
        printf(" Codigo do Produto: %lu\n", codigo);
        printf(" Codigo inexistente\n");
        printf("\n");
    }
    else
    {

        printf("------------\n");

        printf(" Codigo do Produto: %lu\n", aux_prod.cod_produto);

        printf(" Nome do produto: %s\n", aux_prod.nome_prod);

        printf(" Valor de compra produto: %.2f\n", aux_prod.preco_prod);

        printf(" Valor de venda do produto: %.2f\n", aux_prod.venda_prod);

        printf(" Descricao do produto: %s\n", aux_prod.descricao);
        printf("\n");

    }

    fclose(arq);
}

void pesquisar_produto(void)
{
    produtos aux_prod;
    unsigned long aux = gerador_codigo(PROD) - 1;
    unsigned long codigo = 0;
    int posicao;

    printf("------------------------------------------------------\n\n");
    printf("Digite o codigo a ser pesquisado: ");
    scanf("%lu", &codigo);
    getchar();

    limp_tela();

    FILE *arq = fopen(A_PROD, "r+b");
    if (!arq)
    {

        printf("------------------------------------------------------\n\n");
        fprintf(stderr, "Arquivo de produtos nao pode ser encontrado\n");
        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
        return;
    }
    posicao = binary_search(arq, 0, aux, codigo, PROD);

    if (posicao == -1)
    {
        printf("------------------------------------------------------\n\n");
        printf("Codigo inexistente\n");
        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        fclose(arq);
        getchar();
        return;
    }

    fseek(arq, posicao, SEEK_SET);
    fread(&aux_prod, sizeof(produtos), 1, arq);

    if (aux_prod.valor_logico == EXC)
    {
        printf("------------------------------------------------------\n\n");
        printf("Codigo inexistente\n");
        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
    }
    else
    {

        printf("------------------------------------------------------\n\n");

        printf("Codigo do Produto: %lu\n", aux_prod.cod_produto);

        printf("Nome do produto: %s\n", aux_prod.nome_prod);

        printf("Valor de compra produto: %.2f\n", aux_prod.preco_prod);

        printf("Valor de venda do produto: %.2f\n", aux_prod.venda_prod);

        printf("Descricao do produto: %s\n", aux_prod.descricao);

        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
    }

    fclose(arq);
}


//Atualizar
void atualizar_fornecedor(void)
{
    fornecedor aux_forn;
    unsigned long codigo, aux = gerador_codigo(FORN) - 1;
    int resp, posicao, x;

    memset(&aux_forn, 0, sizeof(fornecedor));

    printf("------------------------------------------------------\n\n");
    printf("Digite o codigo do fornecedor a ser atualizado: ");
    scanf("%lu", &codigo);
    getchar();

    limp_tela();

    FILE *arq = fopen(A_FORN, "r+b");
    if (!arq)
    {

        printf("------------------------------------------------------\n\n");
        fprintf(stderr, "Arquivo de fornecedores nao pode ser encontrado\n");
        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
        return;
    }
    posicao = binary_search(arq, 0, aux, codigo, FORN);

    if (posicao == -1)
    {

        printf("------------------------------------------------------\n\n");
        printf("Codigo inexistente\n");
        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        fclose(arq);
        getchar();
        return;
    }

    fseek(arq, posicao, SEEK_SET);
    fread(&aux_forn, sizeof(fornecedor), 1, arq);

    if (aux_forn.valor_logico == EXC)
    {
        printf("------------------------------------------------------\n\n");
        printf("Codigo inexistente\n");
        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        fclose(arq);
        getchar();
        return;
    }
    else
    {
        printf("------------------------------------------------------\n\n");


        printf("# Codigo do Fornecedor: %lu\n", aux_forn.cod_fornecedor);
        printf("\n");

        printf("- Nome do fornecedor: %s\n", aux_forn.nome_forn);

        printf("- CNPJ do fornecedor: %s\n", aux_forn.CNPJ);

        printf("- Telefone do fornecedor: %d\n\n", aux_forn.telefone);

        printf("- Quantidade de produtos fornecidos: %d\n", aux_forn.quant_produtos);
        printf("\n");

        for(x=0; x<aux_forn.quant_produtos; x++){

            printf("* Produto %d\n", x+1);
            pesquisar_produto_forn(aux_forn.cod_produtos[x]);
        }

        printf("- Data do inicio das relacoes com o fornecedor: %d/%d/%d\n\n", aux_forn.inicio_rel.dia, aux_forn.inicio_rel.mes, aux_forn.inicio_rel.ano);

        printf("- Endereco do fornecedor:\n");

        printf(" Rua: %s\n", aux_forn.rua);
        printf(" Bairro: %s\n", aux_forn.bairro);
        printf(" CEP: %d\n", aux_forn.CEP);
        printf(" Cidade: %s\n", aux_forn.cidade);
        printf(" UF: %s\n", aux_forn.UF);
    }


    resp = confirmar();

    if (!resp)
    {
        fclose(arq);
        return;
    }
    else
    {
        printf("# Codigo do Fornecedor: %lu\n", aux_forn.cod_fornecedor);
        printf("\n");

        printf("- Nome do fornecedor: ");
        fgets(aux_forn.nome_forn, NOM, stdin);
        clear(aux_forn.nome_forn);

        printf("- CNPJ do fornecedor: ");
        fgets(aux_forn.CNPJ, NUM_CNPJ, stdin);
        clear(aux_forn.CNPJ);

        printf("- Telefone do fornecedor: ");
        scanf("%d", &aux_forn.telefone);
        printf("\n");

        printf("- Quantidade de produtos fornecidos: ");
        scanf("%d", &aux_forn.quant_produtos);
        getchar();
        printf("\n");

        for(x=0; x<aux_forn.quant_produtos; x++){

            printf("* Produto %d\n", x+1);
            aux_forn.cod_produtos[x] = gerador_codigo(PROD);
            inserir_produto(aux_forn.cod_produtos[x]);
        }

        printf("- Data do inicio das relacoes com o fornecedor:\n");

        printf("Dia: ");
        scanf("%d", &aux_forn.inicio_rel.dia);

        printf("Mes: ");
        scanf("%d", &aux_forn.inicio_rel.mes);

        printf("Ano: ");
        scanf("%d", &aux_forn.inicio_rel.ano);
        getchar();
        printf("\n");

        printf("- Endereco do fornecedor\n");

        printf("Rua: ");
        fgets(aux_forn.rua, END, stdin);
        clear(aux_forn.rua);

        printf("Bairro: ");
        fgets(aux_forn.bairro, END, stdin);
        clear(aux_forn.bairro);

        printf("CEP: ");
        scanf("%d", &aux_forn.CEP);
        getchar();

        printf("Cidade: ");
        fgets(aux_forn.cidade, END, stdin);
        clear(aux_forn.cidade);

        printf("UF: ");
        fgets(aux_forn.UF, UF, stdin);
        clear(aux_forn.UF);

        aux_forn.valor_logico = NEXC;

        fseek(arq, posicao, SEEK_SET);

        fwrite(&aux_forn, sizeof(fornecedor), 1, arq);
    
        limp_tela();

        printf("------------------------------------------------------\n\n");
        printf("\n * Atualizacao de fornecedor realizada !! *\n");

        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
    }

    fclose(arq);
}

void atualizar_produto(void)
{
    produtos aux_prod;
    unsigned long codigo, aux = gerador_codigo(PROD) - 1;
    int resp, posicao, x;

    memset(&aux_prod, 0, sizeof(produtos));

    printf("------------------------------------------------------\n\n");
    printf("Digite o codigo do produto a ser atualizado: ");
    scanf("%lu", &codigo);
    getchar();

    limp_tela();

    FILE *arq = fopen(A_PROD, "r+b");
    if (!arq)
    {

        printf("------------------------------------------------------\n\n");
        fprintf(stderr, "Arquivo de produtos nao pode ser encontrado\n");
        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
        return;
    }
    posicao = binary_search(arq, 0, aux, codigo, PROD);

    if (posicao == -1)
    {
        printf("------------------------------------------------------\n\n");
        printf("Codigo inexistente\n");
        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        fclose(arq);
        getchar();
        return;
    }

    fseek(arq, posicao, SEEK_SET);
    fread(&aux_prod, sizeof(produtos), 1, arq);

    if (aux_prod.valor_logico == EXC)
    {
        printf("------------------------------------------------------\n\n");
        printf("Codigo inexistente\n");
        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        fclose(arq);
        getchar();
        return;
    }
    else
    {

        printf("------------------------------------------------------\n\n");

        printf("Codigo do Produto: %lu\n", aux_prod.cod_produto);

        printf("Nome do produto: %s\n", aux_prod.nome_prod);

        printf("Valor de compra produto: %.2f\n", aux_prod.preco_prod);

        printf("Valor de venda do produto: %.2f\n", aux_prod.venda_prod);

        printf("Descricao do produto: %s\n", aux_prod.descricao);

    }

    resp = confirmar();

    if (!resp)
    {
        fclose(arq);
        return;
    }
    else
    {

        printf("------------------------------------------------------\n\n");
        printf("* Insira as seguintes informacoes *\n\n");

        printf("Codigo do Produto: %lu\n", aux_prod.cod_produto);

        printf("Nome do produto: ");
        fgets(aux_prod.nome_prod, NOM, stdin);
        clear(aux_prod.nome_prod);

        printf("Valor de compra produto: ");
        scanf("%f", &aux_prod.preco_prod);

        printf("Valor de venda do produto: ");
        scanf("%f", &aux_prod.venda_prod);
        getchar();

        printf("Digite uma pequena descricao do produto: ");
        fgets(aux_prod.descricao, DESC, stdin);
        clear(aux_prod.descricao);

        aux_prod.valor_logico = NEXC;

        fseek(arq, posicao, SEEK_SET);

        fwrite(&aux_prod, sizeof(produtos), 1, arq);

        limp_tela();

        printf("------------------------------------------------------\n\n");

        printf("\n * Atualizacao de produto realizada !! *\n");

        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
    }

    fclose(arq);
}

//Remover
void remover_fornecedor(void)
{
    fornecedor aux_forn;
    unsigned long codigo, aux = gerador_codigo(FORN) - 1;
    int resp, posicao, x;

    printf("------------------------------------------------------\n\n");
    printf("Digite o codigo do fornecedor a ser excluido: ");
    scanf("%lu", &codigo);
    getchar();

    limp_tela();

    FILE *arq = fopen(A_FORN, "r+b");
    if (!arq)
    {

        printf("------------------------------------------------------\n\n");
        fprintf(stderr, "Arquivo de fornecedores nao pode ser encontrado\n");
        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
        return;
    }
    posicao = binary_search(arq, 0, aux, codigo, FORN);

    if (posicao == -1)
    {

        printf("------------------------------------------------------\n\n");
        printf("Codigo inexistente\n");
        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        fclose(arq);
        getchar();
        return;
    }

    fseek(arq, posicao, SEEK_SET);
    fread(&aux_forn, sizeof(fornecedor), 1, arq);

    if (aux_forn.valor_logico == EXC)
    {
        printf("------------------------------------------------------\n\n");
        printf("Codigo inexistente\n");
        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        fclose(arq);
        getchar();
        return;
    }
    else
    {
        printf("------------------------------------------------------\n\n");


        printf("# Codigo do Fornecedor: %lu\n", aux_forn.cod_fornecedor);
        printf("\n");

        printf("- Nome do fornecedor: %s\n", aux_forn.nome_forn);

        printf("- CNPJ do fornecedor: %s\n", aux_forn.CNPJ);

        printf("- Telefone do fornecedor: %d\n\n", aux_forn.telefone);

        printf("- Quantidade de produtos fornecidos: %d\n", aux_forn.quant_produtos);
        printf("\n");

        for(x=0; x<aux_forn.quant_produtos; x++){

            printf("* Produto %d\n", x+1);
            pesquisar_produto_forn(aux_forn.cod_produtos[x]);
        }

        printf("- Data do inicio das relacoes com o fornecedor: %d/%d/%d\n\n", aux_forn.inicio_rel.dia, aux_forn.inicio_rel.mes, aux_forn.inicio_rel.ano);

        printf("- Endereco do fornecedor:\n");

        printf(" Rua: %s\n", aux_forn.rua);
        printf(" Bairro: %s\n", aux_forn.bairro);
        printf(" CEP: %d\n", aux_forn.CEP);
        printf(" Cidade: %s\n", aux_forn.cidade);
        printf(" UF: %s\n", aux_forn.UF);

    }


    resp = confirmar();

    if (!resp)
    {
        fclose(arq);
        return;
    }
    else
    {
        printf("------------------------------------------------------\n\n");
        
        fseek(arq, posicao, SEEK_SET);

        printf("- Data do fim das relacoes com o fornecedor:\n");

        printf("Dia: ");
        scanf("%d", &aux_forn.final_rel.dia);

        printf("Mes: ");
        scanf("%d", &aux_forn.final_rel.mes);

        printf("Ano: ");
        scanf("%d", &aux_forn.final_rel.ano);
        getchar();
        printf("\n");

        aux_forn.valor_logico = EXC;

        fwrite(&aux_forn, sizeof(fornecedor), 1, arq);

        limp_tela();

        printf("------------------------------------------------------\n\n");

        printf("\n * Fornecedor Removido !! *\n");

        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
    }

    fclose(arq);
}

void remover_produto(void)
{
    produtos aux_prod;
    unsigned long codigo, aux = gerador_codigo(PROD) - 1;
    int resp, posicao, x;

    printf("------------------------------------------------------\n\n");
    printf("Digite o codigo do produto a ser excluido: ");
    scanf("%lu", &codigo);
    getchar();

    limp_tela();

    FILE *arq = fopen(A_PROD, "r+b");
    if (!arq)
    {

        printf("------------------------------------------------------\n\n");
        fprintf(stderr, "Arquivo de produtos nao pode ser encontrado\n");
        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
        return;
    }
    posicao = binary_search(arq, 0, aux, codigo, PROD);

    if (posicao == -1)
    {
        printf("------------------------------------------------------\n\n");
        printf("Codigo inexistente\n");
        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        fclose(arq);
        getchar();
        return;
    }

    fseek(arq, posicao, SEEK_SET);
    fread(&aux_prod, sizeof(produtos), 1, arq);

    if (aux_prod.valor_logico == EXC)
    {
        printf("------------------------------------------------------\n\n");
        printf("Codigo inexistente\n");
        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        fclose(arq);
        getchar();
        return;
    }
    else
    {

        printf("------------------------------------------------------\n\n");

        printf("Codigo do Produto: %lu\n", aux_prod.cod_produto);

        printf("Nome do produto: %s\n", aux_prod.nome_prod);

        printf("Valor de compra produto: %.2f\n", aux_prod.preco_prod);

        printf("Valor de venda do produto: %.2f\n", aux_prod.venda_prod);

        printf("Descricao do produto: %s\n", aux_prod.descricao);

    }

    resp = confirmar();

    if (!resp)
    {
        fclose(arq);
        return;
    }
    else
    {
        fseek(arq, posicao, SEEK_SET);

        aux_prod.valor_logico = EXC;

        fwrite(&aux_prod, sizeof(produtos), 1, arq);

        printf("------------------------------------------------------\n\n");

        printf("\n * Produto Removido !! *\n");

        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
    }

    fclose(arq);
}

////Relatório geral
void relatorio_geral_forn(void)
{

    printf("------------------------------------------------------\n\n");
    FILE *arq = fopen(A_FORN, "rb");
    if (!arq)
    {
        fprintf(stderr, "Arquivo de fornecedores nao pode ser encontrado\n");
        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
        return;
    }

    fornecedor aux_forn;

    fseek(arq, 0, SEEK_SET);

    printf("    * Relatorio Geral de Fornecedores *\n\n");

    while(fread(&aux_forn, sizeof(fornecedor), 1, arq))
    {
        printf("------------------------------------------------------\n\n");

        printf("# Codigo do Fornecedor: %lu\n", aux_forn.cod_fornecedor);
        printf("\n");

        printf("- Nome do fornecedor: %s\n", aux_forn.nome_forn);

        printf("- CNPJ do fornecedor: %s\n", aux_forn.CNPJ);

        printf("- Telefone do fornecedor: %d\n\n", aux_forn.telefone);

        printf("- Quantidade de produtos fornecidos: %d\n", aux_forn.quant_produtos);
        printf("\n");

        for(int i =0; i< aux_forn.quant_produtos; i++){

            printf("* Produto %d\n", i + 1);
            pesquisar_produto_forn(aux_forn.cod_produtos[i]);
        }

        printf("- Endereco do fornecedor:\n");

        printf(" Rua: %s\n", aux_forn.rua);
        printf(" Bairro: %s\n", aux_forn.bairro);
        printf(" CEP: %d\n", aux_forn.CEP);
        printf(" Cidade: %s\n", aux_forn.cidade);
        printf(" UF: %s\n\n", aux_forn.UF);

        printf("- Data do inicio das relacoes com o fornecedor: %d/%d/%d\n", aux_forn.inicio_rel.dia, aux_forn.inicio_rel.mes, aux_forn.inicio_rel.ano);

        if(!aux_forn.valor_logico){
            printf("\n- Fornecedor Cadastrado -\n\n");
        }
        else{

            printf("- Data do fim das relacoes com o fornecedor: %d/%d/%d\n", aux_forn.final_rel.dia, aux_forn.final_rel.mes, aux_forn.final_rel.ano);

            printf("\n- Fornecedor Excluido -\n\n");
        }
    }

    printf("\n\n (Aperte a tecla Enter para sair)\n\n");
    printf("------------------------------------------------------\n\n");
    getchar();

    fclose(arq);
}

void relatorio_geral_prod(void){

    printf("------------------------------------------------------\n\n");
    FILE *arq = fopen(A_PROD, "rb");
    if (!arq)
    {
        fprintf(stderr, "Arquivo de produtos nao pode ser encontrado\n");
        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
        return;
    }

    produtos aux_prod;

    fseek(arq, 0, SEEK_SET);

    printf("    * Relatorio Geral de Produtos *\n\n");

    while(fread(&aux_prod, sizeof(produtos), 1, arq)){

        printf("------------------------------------------------------\n\n");

        printf("Codigo do Produto: %lu\n", aux_prod.cod_produto);

        printf("Nome do produto: %s\n", aux_prod.nome_prod);

        printf("Valor de compra produto: %.2f\n", aux_prod.preco_prod);

        printf("Valor de venda do produto: %.2f\n", aux_prod.venda_prod);

        printf("Descricao do produto: %s\n", aux_prod.descricao);

        if(!aux_prod.valor_logico){
            printf("\n- Produto Cadastrado -\n\n");
        }
        else{
            printf("\n- Produto Excluido -\n\n");
        }

    }
    printf("\n\n (Aperte a tecla Enter para sair)\n\n");
    printf("------------------------------------------------------\n\n");
    getchar();


    fclose(arq);
}
