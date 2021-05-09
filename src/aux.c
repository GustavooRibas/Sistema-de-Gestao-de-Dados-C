/*----------------------------------------------------------------
  	        	        TRABALHO FINAL AED-1
                                (aux.c)
 -----------------------------------------------------------------

 DESCRIÇÃO:
 ---------
 Implementação das funções da biblioteca "aux.h", que contêm os protótipos das funções 
 auxiliares.  

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
#include <string.h>
#include "aux.h"


/*********************************************
 *      IMPLEMENTAÇÃO DAS FUNÇÕES
 ********************************************/

//Gerador de códigos (Produtos | Fornecedoresi | Colaboradores)
unsigned long gerador_codigo(int tipo)
{
    unsigned long quant = 0; //guarda a quantidade de elementos no arquivo

    char buff_nome_arquivo[CARAC_A]; //Irá guardar o nome do arquivo

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

//Limpeza do "\n" das strings e dos caracteres excedentes
void clear(char str[])
{
    int c = strlen(str); //guarda o tamanho da string
    if (str[c - 1] == '\n') str[c - 1] = 0;
    else while(getchar() != '\n'); //limpeza do excedente, caso passe o tamanho da string
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
void print_colaboradores(colaborador aux_col)
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

