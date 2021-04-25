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

/*********************************************
 *          BIBLIOTECAS
 ********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********************************************
 *          DEFINES
 *******************************************/

//Limpeza da tela de acordo com o sistema operacional do usuário
#ifdef _WIN32
    #define CLS "cls"

#elif __linux__
    #define CLS "clear"

#endif

//Constantes de definição dos arquivos
#define FORN  0
#define PROD  1
#define COL   2

//Constantes para os nomes dos arquivos de fornecedores e produtos
#define A_PROD "Produtos"
#define A_FORN "Fornecedores"
#define A_COL  "Colaboradores"

/****************************************
 *          CONSTANTES
 ***************************************/
//Constantes Gerais
enum {NOM = 41, DESC = 101, EXC =  1, NEXC = 0, QUANT_PROD = 10, END = 41, UF = 3, CARAC_A = 15, NUM_CNPJ = 15 , NUM_CPF = 12 , CARG = 41};

/***************************************
 *          ESTRUTURAS
 **************************************/

//Estrutura para produtos
typedef struct
{
    unsigned long cod_produto;
    char nome_prod[NOM];
    float preco_prod;
    float venda_prod;
    char descricao[DESC];
    int valor_logico;

}produtos;

//Estrutura para data
typedef struct
{
    int dia;
    int mes;
    int ano;
}data;

//Estrutura para fornecedores
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

//Estrutura para colaboradores
typedef struct
{
    unsigned long cod_colaborador;
	char nome_col[NOM];
	char cargo[CARG];
	float salario;
	char CPF[NUM_CPF];
	char rua[END];
    char bairro[END];
    int CEP;
    char cidade[END];
    char UF[UF];
    int telefone;
    data inicio_cont;
    data final_cont;
	int valor_logico;
}colaborador;

/***********************************************
 *          PROTÓTIPOS
 **********************************************/

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
 * @fn gerador_codigo(int tipo)
 * @brief Gerador de códigos (Produtos | Fornecedores)
 * @param int tipo - Tipo do arquivo em que será contada a quantidade de elementos (structs), ou seja, arquivo de fornecedores, produtos ou colaboradores
 * @return Quantidade de elementos (structs) dentro do arquivo
*/
unsigned long gerador_codigo(int tipo);

/**
 * @fn logo_nmagalu(void)
 * @brief Apreseta na tela a logo da varejista "Não-Magalu"
*/
void logo_nmagalu(void);

/**
 * @fn clear(char str[])
 * @brief Limpeza do "\n" das strings e limpeza dos caracteres excedentes no buffer
 * @param char str[] - String em que se deseja retirar o "\n"
*/
void clear(char str[]);

/**
 * @fn confirmar(void)
 * @brief Apresenta um menu de confirmação para a exclusão ou atualização dos dados
 */
int confirmar(void);

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

/**
 * @fn inserir_fornecedor(void)
 * @brief Solicita ao usuário a inserção dos seguintes dados:  Nome do fornecedor, quantidade de produtos a serem cadastrados,
 * CNPJ, telefone , o endereço e data do início das relações com o fornecedor. Além disso, a função gera o código dos fornecedores e
 * dos produtos, chamando a função gerador_codigo tendo como parâmetro o tipo do arquivo (Fornecedor | Produto | Colaborador).
 * O código dos produtos é passado como argumento na função inserir_produto e, em seguida, ele atribui o valor 0 ao valor lógico
 * de exclusão, indicando que não está excluso. Por fim, ele escreve os dados do fornecedor em um arquivo de fornecedores.
*/
void inserir_fornecedor(void);

/**
 * @fn inserir_produto(void)
 * @brief A Função recebe como argumento o código do produto e solicita ao usuário a inserção dos seguintes dados:
 * nome do produto, preço de compra, preço de venda e descrição do produto a ser ofertado. Em seguida, ele
 * atribui o valor 0 ao valor lógico de exclusão, indicando que não está excluso e, por fim, escreve os
 * dados do produto em um arquivo de produtos.
 * @param int codigo - código do produto a ser ofertado
*/
void inserir_produto(int codigo);

/**
 * @fn inserir_colaborador(void)
 * @brief Solicita ao usuário a inserção dos seguintes dados:
 * nome do colaborador, CPF, telefone , o endereço e data do início do contrato com o colaborador.
 * Além disso, a função gera o código do colaborador, chamando a função gerador_codigo,
 * tendo como parâmetro o tipo do arquivo (Fornecedor | Produto | Colaborador). Em seguida, ele
 * atribui o valor 0 ao valor lógico de exclusão, indicando que não está excluso. Por fim, ele escreve os
 * dados do colaborador em um arquivo de colaboradores.
*/
void inserir_colaborador(void);

/**
 * @fn pesquisar_fornecedor(void)
 * @brief Faz chamada da função binary_search passando como argumento o código a ser pesquisado. Em seguida, caso o arquivo de fornecedores exista,
 * o código esteja cadastrado e o fornecedor não esteja excluso, ele imprime as suas informações na tela.
 * Caso o código não esteja cadastrado, ele informa que o código é inexistente.
*/
void pesquisar_fornecedor(void);

/**
 * @fn pesquisar_produto_forn(unsigned long codigo)
 * @brief A função recebe como argumento o codigo do produto, faz a chamada da função binary_search para encontrar o produto a ser pesquisado. Caso
 * o produto exista e não esteja excluso, ele informa seus dados, caso contrário ele informa que o código é inexistente.
 * @param unsigned long codigo - Código do produto a ser pesquisado.
*/
void pesquisar_produto_forn(unsigned long codigo);

/**
 * @fn pesquisar_produto(void)
 * @brief Faz chamada da função binary_search passando como argumento o código a ser pesquisado. Em seguida, caso o arquivo de produto exista,
 * o código esteja cadastrado e o profuto não esteja excluso, ele imprime as suas informações na tela.
 * Caso o código não esteja cadastrado, ele informa que o código é inexistente.
*/
void pesquisar_produto(void);

/**
 * @fn pesquisar_colaborador(void)
 * @brief Faz chamada da função binary_search passando como argumento o código a ser pesquisado. Em seguida, caso o arquivo de colaboradores exista,
 * o código esteja cadastrado e o colaborador não esteja excluso, ele imprime as suas informações na tela.
 * Caso o código não esteja cadastrado, ele informa que o código é inexistente.
*/
void pesquisar_colaborador(void);

/**
 * @fn atualizar_fornecedor(void)
 * @brief Pede para o usuário o código do fornecedor a ter seus dados atualizados, em seguida faz a chamada
 * da função binary_search para procurar seus dados no arquivo de fornecedores. Apresenta na tela uma confirmação chamando a função confirmar, se o usuário
 * digitar 's' ou 'S' a função solicita ao usuário os dados para serem atualizados, como: Nome do fornecedor, quantidade de produtos a serem cadastrados,
 * CNPJ, telefone , o endereço e data do início das relações com o fornecedor. Em seguida, insere os dados no arquivo, no local do dados anteriores.
 * Caso o usuário, na confirmação, digite 'n' ou 'N' a função irá retornar ao gerenciar_fornecedore.
*/
void atualizar_fornecedor(void);

/**
 * @fn atualizar_produto(void)
 * @brief Pede para o usuário o código do produto a ter seus dados atualizados, em seguida faz a chamada
 * da função binary_search para procurar seus dados no arquivo de produtos. Apresenta na tela uma confirmação chamando a função confirmar, se o usuário
 * digitar 's' ou 'S' a função solicita ao usuário os dados para serem atualizados, como: nome do produto, preço de compra, preço de venda
 * e descrição do produto a ser ofertado. Em seguida insere os dados no arquivo no local do dados anteriores.
 * Caso o usuário, na confirmação, digite 'n' ou 'N' a função irá retornar ao gerenciar_produtos.
*/
void atualizar_produto(void);

/**
 * @fn atualizar_colaborador(void)
 * @brief Pede para o usuário o código do colaborador a ter seus dados atualizados, em seguida faz a chamada
 * da função binary_search para procurar seus dados no arquivo de colaboradores. Apresenta na tela uma confirmação chamando a função confirmar, se o usuário
 * digitar 's' ou 'S' a função solicita ao usuário os dados para serem atualizados, como: nome do colaborador, CPF, telefone ,
 * o endereço e data do início do contrato com o colaborador. Em seguida, insere os dados no arquivo, no local do dados anteriores.
 * Caso o usuário, na confirmação, digite 'n' ou 'N' a função irá retornar ao gerenciar_colaborador.
*/
void atualizar_colaborador(void);

/**
 * @fn remover_fornecedor(void)
 * @brief Pede para o usuário digitar o código do fornecedor a ser removido, em seguida
 * faz a busca do código chamando a função binary_search. Caso o código não esteja 
 * presente no arqivo de fornecedores ou o fornecedor já tenha sido excluído, é
 * apresentado na tela uma mesagen de código inexistente. Caso o código não esteja 
 * excluído, são apresentados os dados do fornecedor e pede uma confirmação 
 * da exclusão. Se o usúario informar que quer excluír o fornecedor,
 * a função pede para o usuário inserir a data do fim das relações e exclui logicamente, 
 * o fornecedor, trocando o valor lógico de exclusão.
*/
void remover_fornecedor(void);

/**
 * @fn remover_produto(void)
 * @brief Pede para o usuário digitar o código do produto a ser removido, em seguida
 * faz a busca do código chamando a função binary_search. Caso o código não esteja 
 * presente no arqivo de produtos ou o produto já tenha sido excluído, é
 * apresentado na tela uma mesagen de código inexistente. Caso o código não esteja 
 * excluído, são apresentados os dados do produto e pede para uma confirmação da 
 * exclusão. Se o usúario informar que quer excluír o produto, a função exclui
 * logicamente o item, trocando o valor lógico de exclusão.
*/
void remover_produto(void);

/**
 * @fn remover_colaborador(void)
 * @brief Pede para o usuário digitar o código do colaborador a ser removido, em seguida
 * faz a busca do código chamando a função binary_search. Caso o código não esteja 
 * presente no arqivo de colaboraboradores ou o colaborador já tenha sido excluído, é
 * apresentado na tela uma mesagen de código inexistente. Caso o código não esteja 
 * excluído, são apresentados os dados do colaborador e pede uma confirmação da 
 * exclusão. Se o usúario informar que quer excluír o colaborador, a função exclui
 * logicamente o item, trocando o valor lógico de exclusão.
*/
void remover_colaborador(void);

/**
 * @fn relatorio_geral_prod(void)
 * @brief Apresenta na tela todos os dados de produtos que foram obtidos até o momento
 * da sua chamada, além disso, exibe a sua situação cadastral (se está ou não
 * excluído).
*/
void relatorio_geral_prod(void);

/**
 * @fn relatorio_geral_forn(void)
 * @brief Exibe na tela todos os dados de fornecedores que foram obtidos até o 
 * momento da sua chamada, além disso, apresenta a sua situação cadastral (se está ou não
 * excluído).
*/
void relatorio_geral_forn(void);

/**
 * @fn relatorio_geral_col(void)
 * @brief Apresenta na tela todos os dados de colaboradores que foram obtidos até o 
 * momento da sua chamada, além disso, exibe a sua situação cadastral (se está ou não
 * excluído).
*/
void relatorio_geral_col(void);

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

//saída da logo
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
    char buff_arquiv[CARAC_A]; //vairável para guardar o nome do arquivo

    if (tipo == 1)
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
    if (tipo == 0)
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

            else
            {
                if (aux_forn.cod_fornecedor < cod)
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
        strcpy(buff_arquiv, A_COL);
        colaborador aux_col;


        while (fim >= ini)
        {
            int mid = (ini + fim) / 2;

            fseek(arq, mid * sizeof(colaborador), SEEK_SET);
            fread(&aux_col, sizeof(colaborador), 1, arq);

            if (aux_col.cod_colaborador == cod)
            {
                fseek(arq, sizeof(colaborador)*(-1), SEEK_CUR);
                return ftell(arq);

            }

            else
            {
                if (aux_col.cod_colaborador < cod)
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
    }

    return -1;
}

//Limpeza do "\n" das strings e dos caracteres excedentes 
void clear(char str[])
{
    int c = strlen(str); //guarda o tamanho da string
    if (str[c - 1] == '\n') str[c - 1] = 0;
    else while(getchar() != '\n');
}

//Confirmação e exclusão | remoção
int confirmar(void)
{
    char resp = ' '; //variável para guardar a resposta

    while (resp != 's' && resp != 'S' && resp != 'n' && resp != 'N')
    {
        printf("-----------------------------------------------------------------\n\n");
        printf("Tem certeza? - Os dados nao poderao ser recuperados [S-s/N-n]: ");
        scanf("%c", &resp);
        getchar();
        printf("\n");
        system(CLS);
    }
    if (resp == 'n' || resp == 'N') return 0;
    else return 1;
}

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

//gerenciar colaboradores
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

//Gerador de códigos (Produtos | Fornecedores)
unsigned long gerador_codigo(int tipo)
{
    unsigned long quant = 0; //guarda a quantidade de elementos no arquivo

    char buff_nome_arquivo[CARAC_A];

    if (tipo == 1)
    {
         strcpy(buff_nome_arquivo, A_PROD);
    }
    else if (tipo == 0)
    {
        strcpy(buff_nome_arquivo, A_FORN);
    }
    else
    {
        strcpy(buff_nome_arquivo, A_COL);
    }

    FILE *arquiv = fopen(buff_nome_arquivo, "rb");
    if (!arquiv)
    {
        //caso ainda não tenha um arquivo contendo os dados
        return 1;
    }

    if (tipo == 1)
    {
        produtos aux_prod;
        
        fseek(arquiv, sizeof(produtos)*(-1), SEEK_END);
        fread(&aux_prod, sizeof(produtos), 1, arquiv);
        quant = aux_prod.cod_produto + 1;
    }

    else
    {
        if (tipo == 0)
        {
            fornecedor aux_forn;
            
            fseek(arquiv, sizeof(fornecedor)*(-1), SEEK_END);
            fread(&aux_forn, sizeof(fornecedor), 1, arquiv);
            quant = aux_forn.cod_fornecedor + 1;
        }
        else
        {
            colaborador aux_col;
            
            fseek(arquiv,sizeof(colaborador)*(-1), SEEK_END);
            fread(&aux_col, sizeof(colaborador), 1, arquiv);
            quant = aux_col.cod_colaborador + 1;
        }
    }

    fclose(arquiv);

    return quant;
}

//Apresenta na tela os dados dos fornecedores
void print_fornecedor(fornecedor aux_forn)
{
        int x; //variável auxiliar para o for que será utilizado

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
            printf("\n");
        }

        printf("- Endereco do fornecedor:\n");

        printf(" Rua: %s\n", aux_forn.rua);
        printf(" Bairro: %s\n", aux_forn.bairro);
        printf(" CEP: %d\n", aux_forn.CEP);
        printf(" Cidade: %s\n", aux_forn.cidade);
        printf(" UF: %s\n", aux_forn.UF);
        printf("\n");

        printf("- Data do inicio das relacoes com o fornecedor: %d/%d/%d\n", aux_forn.inicio_rel.dia, aux_forn.inicio_rel.mes, aux_forn.inicio_rel.ano);
        printf("\n");
}

//Apresenta na tela os dados de produtos
void print_produto(produtos aux_prod)
{
        printf("Codigo do Produto: %lu\n", aux_prod.cod_produto);

        printf("Nome do produto: %s\n", aux_prod.nome_prod);

        printf("Valor de compra produto: %.2f\n", aux_prod.preco_prod);

        printf("Valor de venda do produto: %.2f\n", aux_prod.venda_prod);

        printf("Descricao do produto: %s\n", aux_prod.descricao);
}

//Apresenta na tela os dados de colaboradores
void print_colaborador(colaborador aux_col)
{
        printf("# Codigo do colaborador: %lu\n", aux_col.cod_colaborador);
        printf("\n");

        printf("- Nome do colaborador: %s\n", aux_col.nome_col);

        printf("- Cargo do colaborador: %s\n", aux_col.cargo);

        printf("- Salario do colaborador: R$%.2f\n", aux_col.salario);

        printf("- CPF do colaborador: %s\n", aux_col.CPF);

        printf("- Telefone do colaborador: %d\n\n", aux_col.telefone);

        printf("- Endereco do colaborador:\n");

        printf(" Rua: %s\n", aux_col.rua);
        printf(" Bairro: %s\n", aux_col.bairro);
        printf(" CEP: %d\n", aux_col.CEP);
        printf(" Cidade: %s\n", aux_col.cidade);
        printf(" UF: %s\n", aux_col.UF);
        printf("\n");

        printf("- Data do inicio do contrato com o colaborador: %d/%d/%d\n", aux_col.inicio_cont.dia, aux_col.inicio_cont.mes, aux_col.inicio_cont.ano);
        printf("\n");

}

//Inserir fornecedor
void inserir_fornecedor(void){

    printf("------------------------------------------------------\n\n");
    fornecedor aux_forn; //auxiliar para guardar os dados de fornecedores
    int x=0, i, quant_forn; //auxliares

    printf("Digite a quantidade de fornecedores a serem inseridos: ");
    scanf("%d", &quant_forn);
    getchar();

    system(CLS);

    for (i = 0; i < quant_forn; i++)
    {
        printf("\n");
        printf("------------------------------------------------------\n\n");

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
    }

    printf("\n\n (Aperte a tecla Enter para sair)\n\n");
    printf("------------------------------------------------------\n\n");
    getchar();

}

//Inserir produto
void inserir_produto(int codigo)
{
    printf("----------------\n");
    produtos aux_prod; //auxiliar para guardar os dados de produtos

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

//Inserir colaborador
void inserir_colaborador(void)
{
    printf("------------------------------------------------------\n\n");
    colaborador aux_col; //auxliar para guardar dados do colaborador
    int i, quant_col; //auxiliares

    printf("Digite a quantidade de colaboradores a serem inseridos: ");
    scanf("%d", &quant_col);
    getchar();

    system(CLS);

    for (i = 0; i < quant_col; i++)
    {
        printf("\n");
        printf("------------------------------------------------------\n\n");

        memset(&aux_col, 0, sizeof(colaborador));

        aux_col.cod_colaborador = gerador_codigo(COL);
        printf("# Codigo do colaborador: %lu\n", aux_col.cod_colaborador);
        printf("\n");

        printf("- Nome do colaborador: ");
        fgets(aux_col.nome_col, NOM, stdin);
        clear(aux_col.nome_col);

        printf("- Cargo do colaborador: ");
        fgets(aux_col.cargo, CARG, stdin);
        clear(aux_col.cargo);

        printf("- Salario do colaborador: ");
        scanf("%f", &aux_col.salario);
        getchar();

        printf("- CPF do colaborador: ");
        fgets(aux_col.CPF, NUM_CPF, stdin);
        clear(aux_col.CPF);

        printf("- Telefone do colaborador: ");
        scanf("%d", &aux_col.telefone);
        printf("\n");

        printf("- Data do inicio do contrato com o colaborador:\n");

        printf("Dia: ");
        scanf("%d", &aux_col.inicio_cont.dia);

        printf("Mes: ");
        scanf("%d", &aux_col.inicio_cont.mes);

        printf("Ano: ");
        scanf("%d", &aux_col.inicio_cont.ano);
        getchar();
        printf("\n");

        printf("- Endereco do colaborador\n");

        printf("Rua: ");
        fgets(aux_col.rua, END, stdin);
        clear(aux_col.rua);

        printf("Bairro: ");
        fgets(aux_col.bairro, END, stdin);
        clear(aux_col.bairro);

        printf("CEP: ");
        scanf("%d", &aux_col.CEP);
        getchar();

        printf("Cidade: ");
        fgets(aux_col.cidade, END, stdin);
        clear(aux_col.cidade);

        printf("UF: ");
        fgets(aux_col.UF, UF, stdin);
        clear(aux_col.UF);

        aux_col.valor_logico = NEXC;

        FILE *arq = fopen(A_COL, "ab");
        if (!arq)
        {
            fprintf(stderr, "Arquivo de colaboradores nao pode ser encontrado\n");
            exit(1);
        }

        fwrite(&aux_col, sizeof(colaborador), 1, arq);

        fclose(arq);
    }

    printf("\n\n (Aperte a tecla Enter para sair)\n\n");
    printf("------------------------------------------------------\n\n");
    getchar();
}

//Pesquisar fornecedor
void pesquisar_fornecedor(void)
{
    fornecedor aux_forn; //auxiliaar para guardar os dados de fornecedor
    unsigned long aux = gerador_codigo(FORN) - 1; //guarda a quantidade de elementos no arquivo de fornecedores
    unsigned long codigo = 0; // guarda o código do fornecedor a ser pesquisado
    int posicao; //guarda a posição no arquivo
    int x = 0; //auxiliar

    printf("------------------------------------------------------\n\n");
    printf("Digite o codigo a ser pesquisado: ");
    scanf("%lu", &codigo);
    getchar();
    printf("\n");

    system(CLS);

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

        print_fornecedor(aux_forn);


        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
    }

    fclose(arq);
}

//Pesquisar produto no arquivo de fornecedores
void pesquisar_produto_forn(unsigned long codigo)
{
    produtos aux_prod;//auxiliar para guardar os dados de produtos
    unsigned long aux = gerador_codigo(PROD) - 1; //guarda a quantidade de elementos no arquivo de produtos
    int posicao;//guarda a posição no arquivo

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

        print_produto(aux_prod);

    }

    fclose(arq);
}

//pesquisar produto
void pesquisar_produto(void)
{
    produtos aux_prod; //auxiliar para guardar os dados de produtos
    unsigned long aux = gerador_codigo(PROD) - 1; //guarda a quantidade de elementos no arquivo de produtos
    unsigned long codigo = 0; //guarda o código a ser pesquisado
    int posicao;//guarda a posição no arquivo

    printf("------------------------------------------------------\n\n");
    printf("Digite o codigo a ser pesquisado: ");
    scanf("%lu", &codigo);
    getchar();

    system(CLS);

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

        print_produto(aux_prod);


        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
    }

    fclose(arq);
}

//pesquisar colaboradores
void pesquisar_colaborador(void)
{
    colaborador aux_col; //auxiliar para guardar os dados de colaboradores
    unsigned long aux = gerador_codigo(COL) - 1; //guarda a quantidade de elementos no arquivo de colaboradores
    unsigned long codigo = 0;//guarda o código a ser pesquisado
    int posicao; //guarda a posição no arquivo
    int x = 0; //auxiliar

    printf("------------------------------------------------------\n\n");
    printf("Digite o codigo a ser pesquisado: ");
    scanf("%lu", &codigo);
    getchar();
    printf("\n");

    system(CLS);

    FILE *arq = fopen(A_COL, "r+b");
    if (!arq)
    {

        printf("------------------------------------------------------\n\n");
        fprintf(stderr, "Arquivo de colaboradores nao pode ser encontrado\n");
        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
        return;
    }
    posicao = binary_search(arq, 0, aux, codigo, COL);

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
    fread(&aux_col, sizeof(colaborador), 1, arq);

    if (aux_col.valor_logico == EXC)
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

        print_colaborador(aux_col);


        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
    }

    fclose(arq);
}

//Atualizar fornecedor
void atualizar_fornecedor(void)
{
    fornecedor aux_forn; //guarda os dados do colaborador
    unsigned long codigo, aux = gerador_codigo(FORN) - 1; //guarda o codigo a ser pesquisado; guarda a quantidade de elementos no arquivo de fornecedores
    int resp, posicao, x; //auxiliares

    memset(&aux_forn, 0, sizeof(fornecedor));

    printf("------------------------------------------------------\n\n");
    printf("Digite o codigo do fornecedor a ser atualizado: ");
    scanf("%lu", &codigo);
    getchar();

    system(CLS);

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

        print_fornecedor(aux_forn);

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

        system(CLS);

        printf("------------------------------------------------------\n\n");
        printf("\n * Atualizacao de fornecedor realizada !! *\n");

        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
    }

    fclose(arq);
}

//Atualizar produto
void atualizar_produto(void)
{
    produtos aux_prod;//guarda os dados do produto
    unsigned long codigo, aux = gerador_codigo(PROD) - 1;//guarda o código do produto a ser pesquisado; guarda a quantidade de elementos no arquivo de produtos
    int resp, posicao, x; //auxiliares

    memset(&aux_prod, 0, sizeof(produtos));

    printf("------------------------------------------------------\n\n");
    printf("Digite o codigo do produto a ser atualizado: ");
    scanf("%lu", &codigo);
    getchar();

    system(CLS);

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

        print_produto(aux_prod);

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

        system(CLS);

        printf("------------------------------------------------------\n\n");

        printf("\n * Atualizacao de produto realizada !! *\n");

        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
    }

    fclose(arq);
}

//Atualizar colaborador
void atualizar_colaborador(void)
{
    colaborador aux_col;//guarda os dados do colaborador
    unsigned long codigo, aux = gerador_codigo(COL) - 1;//guarda o código do colaborador;guarda a quantidade de elementos no arquivo de colaboradores
    int resp, posicao, x; //auxiliares

    memset(&aux_col, 0, sizeof(colaborador));

    printf("------------------------------------------------------\n\n");
    printf("Digite o codigo do colaborador a ser atualizado: ");
    scanf("%lu", &codigo);
    getchar();

    system(CLS);

    FILE *arq = fopen(A_COL, "r+b");
    if (!arq)
    {

        printf("------------------------------------------------------\n\n");
        fprintf(stderr, "Arquivo de colaboradores nao pode ser encontrado\n");
        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
        return;
    }
    posicao = binary_search(arq, 0, aux, codigo, COL);

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
    fread(&aux_col, sizeof(colaborador), 1, arq);

    if (aux_col.valor_logico == EXC)
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

        print_colaborador(aux_col);

    }


    resp = confirmar();

    if (!resp)
    {
        fclose(arq);
        return;
    }
    else
    {
        printf("# Codigo do colaborador: %lu\n", aux_col.cod_colaborador);
        printf("\n");

        printf("- Nome do colaborador: ");
        fgets(aux_col.nome_col, NOM, stdin);
        clear(aux_col.nome_col);

        printf("- Cargo do colaborador: ");
        fgets(aux_col.cargo, CARG, stdin);
        clear(aux_col.cargo);

        printf("- Salario do colaborador: ");
        scanf("%f", &aux_col.salario);
        getchar();

        printf("- CPF do colaborador: ");
        fgets(aux_col.CPF, NUM_CPF, stdin);
        clear(aux_col.CPF);

        printf("- Telefone do colaborador: ");
        scanf("%d", &aux_col.telefone);
        printf("\n");

        printf("- Data do inicio do contrato com o colaborador:\n");

        printf("Dia: ");
        scanf("%d", &aux_col.inicio_cont.dia);

        printf("Mes: ");
        scanf("%d", &aux_col.inicio_cont.mes);

        printf("Ano: ");
        scanf("%d", &aux_col.inicio_cont.ano);
        getchar();
        printf("\n");

        printf("- Endereco do colaborador\n");

        printf("Rua: ");
        fgets(aux_col.rua, END, stdin);
        clear(aux_col.rua);

        printf("Bairro: ");
        fgets(aux_col.bairro, END, stdin);
        clear(aux_col.bairro);

        printf("CEP: ");
        scanf("%d", &aux_col.CEP);
        getchar();

        printf("Cidade: ");
        fgets(aux_col.cidade, END, stdin);
        clear(aux_col.cidade);

        printf("UF: ");
        fgets(aux_col.UF, UF, stdin);
        clear(aux_col.UF);

        aux_col.valor_logico = NEXC;

        fseek(arq, posicao, SEEK_SET);

        fwrite(&aux_col, sizeof(colaborador), 1, arq);

        system(CLS);

        printf("------------------------------------------------------\n\n");
        printf("\n * Atualizacao de colaborador realizada !! *\n");

        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
    }

    fclose(arq);
}

/*****************************************************
 *              TO DO
 ****************************************************/

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

    system(CLS);

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


       print_fornecedor(aux_forn);

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

        system(CLS);

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

    system(CLS);

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

        print_produto(aux_prod);

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

void remover_colaborador(void)
{
    colaborador aux_col;
    unsigned long codigo, aux = gerador_codigo(COL) - 1;
    int resp, posicao, x;

    printf("------------------------------------------------------\n\n");
    printf("Digite o codigo do colaborador a ser excluido: ");
    scanf("%lu", &codigo);
    getchar();

    system(CLS);

    FILE *arq = fopen(A_COL, "r+b");
    if (!arq)
    {

        printf("------------------------------------------------------\n\n");
        fprintf(stderr, "Arquivo de colaboradores nao pode ser encontrado\n");
        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
        return;
    }
    posicao = binary_search(arq, 0, aux, codigo, COL);

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
    fread(&aux_col, sizeof(colaborador), 1, arq);

    if (aux_col.valor_logico == EXC)
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


       print_colaborador(aux_col);

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

        printf("- Data do fim do contrato com o colaborador:\n");

        printf("Dia: ");
        scanf("%d", &aux_col.final_cont.dia);

        printf("Mes: ");
        scanf("%d", &aux_col.final_cont.mes);

        printf("Ano: ");
        scanf("%d", &aux_col.final_cont.ano);
        getchar();
        printf("\n");

        aux_col.valor_logico = EXC;

        fwrite(&aux_col, sizeof(colaborador), 1, arq);

        system(CLS);

        printf("------------------------------------------------------\n\n");

        printf("\n * Colaborador Removido !! *\n");

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

        print_fornecedor(aux_forn);

        if(!aux_forn.valor_logico){
            printf("\n\n    = Fornecedor Cadastrado =\n\n");
        }
        else{

            printf("- Data do fim das relacoes com o fornecedor: %d/%d/%d\n", aux_forn.final_rel.dia, aux_forn.final_rel.mes, aux_forn.final_rel.ano);

            printf("\n\n    = Fornecedor Excluido =\n\n");
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

        print_produto(aux_prod);

        if(!aux_prod.valor_logico){
            printf("\n\n    = Produto Cadastrado =\n\n");
        }
        else{
            printf("\n\n    = Produto Excluido =\n\n");
        }

    }
    printf("\n\n (Aperte a tecla Enter para sair)\n\n");
    printf("------------------------------------------------------\n\n");
    getchar();


    fclose(arq);
}

void relatorio_geral_col(void)
{
    printf("------------------------------------------------------\n\n");
    FILE *arq = fopen(A_COL, "rb");
    if (!arq)
    {
        fprintf(stderr, "Arquivo de Colaborador nao pode ser encontrado\n");
        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
        return;
    }

    colaborador aux_col;

    fseek(arq, 0, SEEK_SET);

    printf("    * Relatorio Geral de Colaborador *\n\n");

    while(fread(&aux_col, sizeof(colaborador), 1, arq))
    {
        printf("------------------------------------------------------\n\n");

        print_colaborador(aux_col);

        if(!aux_col.valor_logico){
            printf("\n\n    = Colaborador Cadastrado =\n\n");
        }
        else{

            printf("- Data do fim do contrato com o colaborador: %d/%d/%d\n", aux_col.final_cont.dia, aux_col.final_cont.mes, aux_col.final_cont.ano);

            printf("\n\n    = Colaborador Excluido =\n\n");
        }
    }

    printf("\n\n (Aperte a tecla Enter para sair)\n\n");
    printf("------------------------------------------------------\n\n");
    getchar();

    fclose(arq);
}
