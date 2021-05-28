/*----------------------------------------------------------------
  	        	        TRABALHO FINAL AED-1
                               (func.c)
 -----------------------------------------------------------------

 DESCRIÇÃO:
 ---------
 Implementação das funções da biblioteca "func.h", que contêm os protótipos das funções
 principais.

 DESENVOLVEDORES:
 ----------------
  Nome: Diego Enrique da Silva Lima
  E-mail: diegoenrique@discente.ufg.br

  Nome: Gustavo Rodrigues Ribeiro
  E-mail: ribeirogustavo@discente.ufg.br;

-----------------------------------------------------------------
 REPOSITÓRIO DO PROJETO: https://github.com/GustavooRibas/Trabalho-Final-AED1
-----------------------------------------------------------------
 DATA DA ÚLTIMA ALTERAÇÃO: 27 de Maio de 2021
----------------------------------------------------------------*/

/*********************************************
 *          BIBLIOTECAS
 ********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
#include "auxi.h"

/*********************************************
 *      IMPLEMENTAÇÃO DAS FUNÇÕES
 ********************************************/

//Inserir fornecedor
void inserir_fornecedor(void){

    printf("------------------------------------------------------\n\n");
    fornecedor aux_forn; //auxiliar para guardar os dados de fornecedores
    int x=0, i, quant_forn; //auxliares para o controle dos loops

    printf("Digite a quantidade de fornecedores a serem inseridos: ");
    scanf("%d", &quant_forn);
    getchar();

    system(CLS);

    for (i = 0; i < quant_forn; i++)
    {
        printf("\n");
        printf("------------------------------------------------------\n\n");

        memset(&aux_forn, 0, sizeof(fornecedor)); //limpeza da struct de fornecedores auxiliar

        //Escrita das informações a serem armazenadas no arquivo de fornecedores
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

        //Inserção e armazenamento dos produtos ("RELAÇÃO PRODUTO FORNECEDOR")
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


        aux_forn.valor_logico = NEXC; //Não excluso

        //Abertura do arquivo
        FILE *arq = fopen(A_FORN, "ab");
        if (!arq)
        {
            fprintf(stderr, "Arquivo de fornecedores nao pode ser encontrado\n");
            exit(1);
        }

        fwrite(&aux_forn, sizeof(fornecedor), 1, arq); //Armazenamento dos dados no arquivo

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

    //Abertura do arquivo
    FILE *arq = fopen(A_PROD, "ab");
    if (!arq)
    {
        fprintf(stderr, "Arquivo de produtos nao pode ser encontrado\n");
        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
        return;
    }

    memset(&aux_prod, 0, sizeof(produtos)); //limpeza da struct de produtos auxiliar

    //Escrita das informações a serem armazenadas no arquivo de produtos
    aux_prod.cod_produto = codigo;
    printf("Codigo do Produto: %lu\n", aux_prod.cod_produto);

    printf("Nome do produto: ");
    fgets(aux_prod.nome_prod, NOM, stdin);
    clear(aux_prod.nome_prod);

    printf("Valor de compra produto: R$");
    scanf("%f", &aux_prod.preco_prod);

    printf("Valor de venda do produto: R$");
    scanf("%f", &aux_prod.venda_prod);
    getchar();

    printf("Digite uma pequena descricao do produto (maximo 100 caracteres): \n");
    fgets(aux_prod.descricao, DESC, stdin);
    clear(aux_prod.descricao);

    aux_prod.valor_logico = NEXC; //Não excluso

    fwrite(&aux_prod, sizeof(produtos), 1, arq); //Escrita dos dados no arquivo

    printf("\n");

    fclose(arq);
}

//Inserir colaborador
void inserir_colaborador(void)
{
    printf("------------------------------------------------------\n\n");
    colaborador aux_col; //auxliar para guardar dados do colaborador
    int i, quant_col; //auxiliares para os loop's

    printf("Digite a quantidade de colaboradores a serem inseridos: ");
    scanf("%d", &quant_col);
    getchar();

    system(CLS);

    for (i = 0; i < quant_col; i++)
    {
        printf("\n");
        printf("------------------------------------------------------\n\n");

        memset(&aux_col, 0, sizeof(colaborador)); //limpeza da struct de colaboradores auxiliar

        //Escrita das informações a serem armazenadas no arquivo de colaboradores
        aux_col.cod_colaborador = gerador_codigo(COL);
        printf("# Codigo do colaborador: %lu\n", aux_col.cod_colaborador);
        printf("\n");

        printf("- Nome do colaborador: ");
        fgets(aux_col.nome_col, NOM, stdin);
        clear(aux_col.nome_col);

        printf("- Cargo do colaborador: ");
        fgets(aux_col.cargo, CARG, stdin);
        clear(aux_col.cargo);

        printf("- Salario do colaborador: R$");
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

        aux_col.valor_logico = NEXC; //Não excluso

        //Abertura do arquivo
        FILE *arq = fopen(A_COL, "ab");
        if (!arq)
        {
            fprintf(stderr, "Arquivo de colaboradores nao pode ser encontrado\n");
            exit(1);
        }

        fwrite(&aux_col, sizeof(colaborador), 1, arq); //Armazenamento dos dados no arquivo

        fclose(arq);
    }

    printf("\n\n (Aperte a tecla Enter para sair)\n\n");
    printf("------------------------------------------------------\n\n");
    getchar();
}

//Pesquisar fornecedor
void pesquisar_fornecedor(void)
{
    fornecedor aux_forn; //auxiliar para guardar os dados de fornecedor
    unsigned long aux = gerador_codigo(FORN) - 1; //guarda a quantidade de elementos no arquivo de fornecedores
    unsigned long codigo = 0; //guarda o código do fornecedor a ser pesquisado
    int posicao; //guarda a posição da struct no arquivo

    printf("------------------------------------------------------\n\n");
    printf("Digite o codigo a ser pesquisado: ");
    scanf("%lu", &codigo);
    getchar();
    printf("\n");

    system(CLS);

    //Abertura do arquivo
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
    fread(&aux_forn, sizeof(fornecedor), 1, arq); //Leitura dos dados desejados

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

        print_fornecedor(aux_forn); //Saída dos dados


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
    int posicao; //guarda a posição da struct no arquivo

    //Abertura do arquivo
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
    fread(&aux_prod, sizeof(produtos), 1, arq); //Leitura dos dados desejados

    //Teste de validade do código
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

        print_produto(aux_prod); //Apresentação dos dados

    }

    fclose(arq);
}

//pesquisar produto
void pesquisar_produto(void)
{
    produtos aux_prod; //auxiliar para guardar os dados de produtos
    unsigned long aux = gerador_codigo(PROD) - 1; //guarda a quantidade de elementos no arquivo de produtos
    unsigned long codigo = 0; //guarda o código a ser pesquisado
    int posicao; //guarda a posição da struct no arquivo

    printf("------------------------------------------------------\n\n");
    printf("Digite o codigo a ser pesquisado: ");
    scanf("%lu", &codigo);
    getchar();

    system(CLS);

    //Abertura do arquivo
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
    fread(&aux_prod, sizeof(produtos), 1, arq); //leitura dos dados

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

        print_produto(aux_prod); //Apresentação dos dados


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
    int posicao; //guarda a posição da struct no arquivo

    printf("------------------------------------------------------\n\n");
    printf("Digite o codigo a ser pesquisado: ");
    scanf("%lu", &codigo);
    getchar();
    printf("\n");

    system(CLS);

    //Abertura do arquivo
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
    fread(&aux_col, sizeof(colaborador), 1, arq); //Leitura dos dados

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

        print_colaboradores(aux_col);//Apresentação dos dados


        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
    }

    fclose(arq);
}

//Atualizar fornecedor
void atualizar_fornecedor(void)
{
    fornecedor aux_forn; //guarda os dados do fornecedor
    unsigned long codigo; //guarda o codigo a ser pesquisado;
    unsigned long aux = gerador_codigo(FORN) - 1; // guarda a quantidade de elementos no arquivo de fornecedores
    int resp,  x; //auxiliares
    int posicao; //guarda a posição da struct no arquivo

    memset(&aux_forn, 0, sizeof(fornecedor));//Limpeza da struct de fornecedores auxiliar

    printf("------------------------------------------------------\n\n");
    printf("Digite o codigo do fornecedor a ser atualizado: ");
    scanf("%lu", &codigo);
    getchar();

    system(CLS);

    //Abertura do arquivo
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
    fread(&aux_forn, sizeof(fornecedor), 1, arq); //Leitura dos dados

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

        print_fornecedor(aux_forn); //Apresentação dos dados

    }

    resp = confirmar(); //Confirmação da ação

    if (!resp) //Caso não deseje atualizar os dados
    {
        fclose(arq);
        return;
    }

    else
    {
        //Escrita dos dados a serem atualizados
        printf("------------------------------------------------------\n\n");
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

        //Chamada da nova inserção de produtos ("RELAÇÃO DE FORNECEDORES E PRODUTOS")
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

        aux_forn.valor_logico = NEXC; //Atribuição do valor lógico de não excluso;

        fseek(arq, posicao, SEEK_SET);

        fwrite(&aux_forn, sizeof(fornecedor), 1, arq); //Reescrita dos dados no arquivo

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
    unsigned long codigo;//guarda o código do produto a ser pesquisado;
    unsigned long aux = gerador_codigo(PROD) - 1;//guarda a quantidade de elementos no arquivo de produtos
    int resp,  x; //auxiliares
    int posicao; //guarda a posição da struct no arquivo

    memset(&aux_prod, 0, sizeof(produtos)); //Limpeza da struct de produtos auxiliar

    printf("------------------------------------------------------\n\n");
    printf("Digite o codigo do produto a ser atualizado: ");
    scanf("%lu", &codigo);
    getchar();

    system(CLS);

    //Abertura do arquivo
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
    fread(&aux_prod, sizeof(produtos), 1, arq); //Leitura dos dados

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

        print_produto(aux_prod); //Apresentação dos dados

    }

    resp = confirmar(); //Confirmação da ação

    if (!resp) //Caso não deseje atualizar os dados
    {
        fclose(arq);
        return;
    }

    else
    {
        //Escrita dos dados a serem atualizados

        printf("------------------------------------------------------\n\n");
        printf("* Insira as seguintes informacoes *\n\n");

        printf("Codigo do Produto: %lu\n", aux_prod.cod_produto);

        printf("Nome do produto: ");
        fgets(aux_prod.nome_prod, NOM, stdin);
        clear(aux_prod.nome_prod);

        printf("Valor de compra produto: R$");
        scanf("%f", &aux_prod.preco_prod);

        printf("Valor de venda do produto: R$");
        scanf("%f", &aux_prod.venda_prod);
        getchar();

        printf("Digite uma pequena descricao do produto: ");
        fgets(aux_prod.descricao, DESC, stdin);
        clear(aux_prod.descricao);

        aux_prod.valor_logico = NEXC; //Atribuição do valor lógico de não excluso;

        fseek(arq, posicao, SEEK_SET);

        fwrite(&aux_prod, sizeof(produtos), 1, arq); //Reescrita dos dados no arquivo

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
    unsigned long codigo; //guarda o código do colaborador;
    unsigned long aux = gerador_codigo(COL) - 1;//guarda a quantidade de elementos no arquivo de colaboradores
    int resp, x; //auxiliares
    int posicao; //guarda a posição da struct no arquivo

    memset(&aux_col, 0, sizeof(colaborador)); //Limpeza da struct de colaborador auxiliar

    printf("------------------------------------------------------\n\n");
    printf("Digite o codigo do colaborador a ser atualizado: ");
    scanf("%lu", &codigo);
    getchar();

    system(CLS);

    //Abertura do arquivo
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
    fread(&aux_col, sizeof(colaborador), 1, arq); //Leitura dos dados

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

        print_colaboradores(aux_col); //Apresentação dos dados

    }


    resp = confirmar(); //Confirmação da ação

    if (!resp) //Caso não deseje atualizar os dados
    {
        fclose(arq);
        return;
    }
    else
    {
        //Escrita dos dados a serem atualizados
        printf("------------------------------------------------------\n\n");
        printf("# Codigo do colaborador: %lu\n", aux_col.cod_colaborador);
        printf("\n");

        printf("- Nome do colaborador: ");
        fgets(aux_col.nome_col, NOM, stdin);
        clear(aux_col.nome_col);

        printf("- Cargo do colaborador: ");
        fgets(aux_col.cargo, CARG, stdin);
        clear(aux_col.cargo);

        printf("- Salario do colaborador: R$");
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

        aux_col.valor_logico = NEXC; //Atribuição do valor lógico de não excluso;

        fseek(arq, posicao, SEEK_SET);

        fwrite(&aux_col, sizeof(colaborador), 1, arq); //Reescrita dos dados no arquivo

        system(CLS);

        printf("------------------------------------------------------\n\n");
        printf("\n * Atualizacao de colaborador realizada !! *\n");

        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
    }

    fclose(arq);
}

//Remover fornecedor
void remover_fornecedor(void)
{
    fornecedor aux_forn;//auxiliar par guardar os dados do fornecedor
    unsigned long codigo;//código a ser pesquisado;
    unsigned long aux = gerador_codigo(FORN) - 1;//quantidade de elementos no arquivo de fornecedores
    int resp,  x;//auxiliares
    int posicao; //guarda a posição da struct no arquivo

    printf("------------------------------------------------------\n\n");
    printf("Digite o codigo do fornecedor a ser excluido: ");
    scanf("%lu", &codigo);
    getchar();

    system(CLS);

    //Abertura do arquivo
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
    fread(&aux_forn, sizeof(fornecedor), 1, arq); //Leitura dos dados

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

       print_fornecedor(aux_forn); //Apresentação dos dados

    }

    resp = confirmar(); //Confirmação da ação

    if (!resp) //Caso não deseje remover os dados
    {
        fclose(arq);
        return;
    }
    else
    {
        //Escrita da data do fim das relações com o fornecedor
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

        aux_forn.valor_logico = EXC; //Atribuição do valor lógico de excluso;

        fwrite(&aux_forn, sizeof(fornecedor), 1, arq); //Reescrita dos dados no arquivo

        system(CLS);

        printf("------------------------------------------------------\n\n");

        printf("\n * Fornecedor Removido !! *\n");

        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
    }

    fclose(arq);
}

//Remover produto
void remover_produto(void)
{
    produtos aux_prod; //auxiliar para guardar os ados do produto
    unsigned long codigo;//guardar o código a ser pesquisado;
    unsigned long  aux = gerador_codigo(PROD) - 1;//quantidade de elementos no arquivo de produtos
    int resp,  x; //auxiliares
    int posicao;//guarda a posição da struct no arquivo

    printf("------------------------------------------------------\n\n");
    printf("Digite o codigo do produto a ser excluido: ");
    scanf("%lu", &codigo);
    getchar();

    system(CLS);

    //Abertura do arquivo
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
    fread(&aux_prod, sizeof(produtos), 1, arq); //Leitura dos dados

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

        print_produto(aux_prod); //Apresentação dos dados

    }

    resp = confirmar(); //Confirmação da ação

    if (!resp) //Caso não deseje remover os dados
    {
        fclose(arq);
        return;
    }
    else
    {
        fseek(arq, posicao, SEEK_SET);

        aux_prod.valor_logico = EXC; //Atribuição do valor lógico de excluso;

        fwrite(&aux_prod, sizeof(produtos), 1, arq); //Reescrita dos dados no arquivo

        printf("------------------------------------------------------\n\n");

        printf("\n * Produto Removido !! *\n");

        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
    }

    fclose(arq);
}

//Remover colaborador
void remover_colaborador(void)
{
    colaborador aux_col;//guardar os dados do colaborador
    unsigned long codigo; //código a ser pesquisado;
    unsigned long aux = gerador_codigo(COL) - 1;//quantidade de elementos no arquivo de colaboradores
    int resp,  x;//auxiliares
    int posicao; //guarda a posição da struct no arquivo

    printf("------------------------------------------------------\n\n");
    printf("Digite o codigo do colaborador a ser excluido: ");
    scanf("%lu", &codigo);
    getchar();

    system(CLS);

    //Abertura do arquivo
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
    fread(&aux_col, sizeof(colaborador), 1, arq); //Leitura dos dados

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


       print_colaboradores(aux_col); //Apresentação dos dados

    }

    resp = confirmar(); //Confirmação da ação

    if (!resp) //Caso não deseje remover os dados
    {
        fclose(arq);
        return;
    }
    else
    {
        //Escrita da data do fim do contrato com o colaborador
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

        aux_col.valor_logico = EXC; //Atribuição do valor lógico de excluso;

        fwrite(&aux_col, sizeof(colaborador), 1, arq); //Reescrita dos dados no arquivo

        system(CLS);

        printf("------------------------------------------------------\n\n");

        printf("\n * Colaborador Removido !! *\n");

        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
    }

    fclose(arq);
}

//Relatório geral de fornecedores
void relatorio_geral_forn(void)
{
    printf("------------------------------------------------------\n\n");

    //Abertura do arquivo
    FILE *arq = fopen(A_FORN, "rb");
    if (!arq)
    {
        fprintf(stderr, "Arquivo de fornecedores nao pode ser encontrado\n");
        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
        return;
    }

    fornecedor aux_forn; //guardar os dados do fornecedor

    fseek(arq, 0, SEEK_SET);

    printf("    * Relatorio Geral de Fornecedores *\n\n");

    while(fread(&aux_forn, sizeof(fornecedor), 1, arq)) //Leitura e impressão sequencial dos dados do fornecedor até o fim do arquivo
    {
        printf("------------------------------------------------------\n\n");

        print_fornecedor(aux_forn); //Apresentação dos dados

        //Teste de exclusão
        if(!aux_forn.valor_logico){ //Não excuído
            printf("\n\n    = Fornecedor Cadastrado =\n\n");
        }
        else{//Excluído

            printf("- Data do fim das relacoes com o fornecedor: %d/%d/%d\n", aux_forn.final_rel.dia, aux_forn.final_rel.mes, aux_forn.final_rel.ano);

            printf("\n\n    = Fornecedor Excluido =\n\n");
        }
    }

    printf("\n\n (Aperte a tecla Enter para sair)\n\n");
    printf("------------------------------------------------------\n\n");
    getchar();

    fclose(arq);
}

//Relatório geral de produtos
void relatorio_geral_prod(void){

    printf("------------------------------------------------------\n\n");

    //Abertura do arquivo
    FILE *arq = fopen(A_PROD, "rb");
    if (!arq)
    {
        fprintf(stderr, "Arquivo de produtos nao pode ser encontrado\n");
        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
        return;
    }

    produtos aux_prod; //guardar os dados do produto

    fseek(arq, 0, SEEK_SET);

    printf("    * Relatorio Geral de Produtos *\n\n");

    while(fread(&aux_prod, sizeof(produtos), 1, arq)){ //Leitura e impressão sequencial dos dados do produto até o fim do arquivo

        printf("------------------------------------------------------\n\n");

        print_produto(aux_prod); //Apresentação dos dados

        //Teste de exclusão
        if(!aux_prod.valor_logico){//Não excluído
            printf("\n\n    = Produto Cadastrado =\n\n");
        }
        else{//Excluído
            printf("\n\n    = Produto Excluido =\n\n");
        }

    }
    printf("\n\n (Aperte a tecla Enter para sair)\n\n");
    printf("------------------------------------------------------\n\n");
    getchar();


    fclose(arq);
}

//Relatório geral de colaboradores
void relatorio_geral_col(void)
{
    printf("------------------------------------------------------\n\n");

    //Abertura do arquivo
    FILE *arq = fopen(A_COL, "rb");
    if (!arq)
    {
        fprintf(stderr, "Arquivo de Colaborador nao pode ser encontrado\n");
        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("------------------------------------------------------\n\n");
        getchar();
        return;
    }

    colaborador aux_col; //guardar os dados do colaborador

    fseek(arq, 0, SEEK_SET);

    printf("    * Relatorio Geral de Colaborador *\n\n");

    while(fread(&aux_col, sizeof(colaborador), 1, arq)) //Leitura e impressão sequencial dos dados do colaborador até o fim do arquivo
    {
        printf("------------------------------------------------------\n\n");

        print_colaboradores(aux_col); //Apresentação dos dados

        //Teste de exclusão
        if(!aux_col.valor_logico){//Não excluído
            printf("\n\n    = Colaborador Cadastrado =\n\n");
        }
        else{//Excluído

            printf("- Data do fim do contrato com o colaborador: %d/%d/%d\n", aux_col.final_cont.dia, aux_col.final_cont.mes, aux_col.final_cont.ano);

            printf("\n\n    = Colaborador Excluido =\n\n");
        }
    }

    printf("\n\n (Aperte a tecla Enter para sair)\n\n");
    printf("------------------------------------------------------\n\n");
    getchar();

    fclose(arq);
}
