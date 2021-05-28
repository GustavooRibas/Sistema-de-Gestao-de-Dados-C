/*----------------------------------------------------------------
  	        	        TRABALHO FINAL AED-1
                               (func.h)
 -----------------------------------------------------------------

 DESCRIÇÃO:
 ---------
 Biblioteca que possui os protótipos das funções principais do programa.

 DESENVOLVEDORES:
 ----------------
  Nome: Diego Enrique da Silva Lima
  E-mail: diegoenrique@discente.ufg.br

  Nome: Gustavo Rodrigues Ribeiro
  E-mail: ribeirogustavo@discente.ufg.br;

-----------------------------------------------------------------
 REPOSITÓRIO DO PROJETO: https://github.com/GustavooRibas/Trabalho-Final-AED1
-----------------------------------------------------------------
 DATA DA ÚLTIMA ALTERAÇÃO: 25 de Maio de 2021
----------------------------------------------------------------*/

#ifndef FUNC_H //include_guard (segurança na chamada do *.h)
#define FUNC_H

/********************************************
 *          DEFINES
 *******************************************/

//Constantes de definição dos arquivos
#define FORN  0 //Número que define o "tipo" fornecedor
#define PROD  1 //Número que define o "tipo" produto
#define COL   2 //Número que define o "tipo" colaborador

//Constantes para os nomes dos arquivos de fornecedores e produtos
#define A_PROD "Produtos" //Nome do arquivo de produtos
#define A_FORN "Fornecedores" //Nome do arquivo de fornecedores
#define A_COL  "Colaboradores" //Nome do arquivo de colaboradores

/****************************************
 *          CONSTANTES
 ***************************************/

//Constantes Gerais
enum {
    NOM = 41, //Quantidade de caracteres em cada nome (Produtos | Fornecedores | Colaboradores)
    DESC = 101, //Quantidade de caracteres na descrição do produto
    EXC =  1, //Valor lógico de exclusão (Excluído)
    NEXC = 0, //Valor lógico de exclusão (Não Excluído)
    QUANT_PROD = 20, //Quantidade máxima de produtos que um fornecedor pode ofertar
    END = 41, //Quantidade de caracteres nos endereços dos fornecedores e colaboradores
    UF = 3, //Quantidade de caracteres para a Unidade Federativa
    CARAC_A = 15,//Quantidade de carateres para os nomes dos arquivos (Produtos | Fornecedores | Colaboradores)
    NUM_CNPJ = 15 , //Quantidade de caracteres para o CNPJ do fornecedor
    NUM_CPF = 12 , //Quantidade de caracteres para o CPF do colaborador
    CARG = 41 //Quantidade de caracteres para o Cargo do colaborador
};

/***************************************
 *          ESTRUTURAS
 **************************************/

//Estrutura para produtos
typedef struct
{
    unsigned long cod_produto; //código do produto
    char nome_prod[NOM]; //nome do produto
    float preco_prod; //preço de compara do produto
    float venda_prod; //preço de venda do produto
    char descricao[DESC]; //descrição do produto
    int valor_logico; //valor lógico para a exclusão

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
	unsigned long cod_fornecedor; //código do fornecedor
	char nome_forn[NOM]; //nome do fornecedor
	int quant_produtos; //quantidade de produtos
	unsigned long cod_produtos[QUANT_PROD]; //código dos produtos
	char CNPJ[NUM_CNPJ]; //CNPJ do fornecedor
	char rua[END]; //Rua
    char bairro[END]; //bairro
    int CEP; //CEP
    char cidade[END]; //cidade
    char UF[UF]; //Unidade Federativa
    int telefone; //telefone para o contato
    data inicio_rel; //dada de inicio das relações
    data final_rel; //data de fim das relaçõess
	int valor_logico; //valor lógico de exclusão

}fornecedor;

//Estrutura para colaboradores
typedef struct
{
    unsigned long cod_colaborador; //código do colaborador
	char nome_col[NOM]; //nome do colaborador
	char cargo[CARG]; //cargo do colaborador
	float salario; //salário do colaborador
	char CPF[NUM_CPF];//CPF do colaborador
	char rua[END]; //rua
    char bairro[END];//Bairro
    int CEP; //CEP
    char cidade[END];//cidade
    char UF[UF]; //Unidade Federativa
    int telefone; //telefone para contato
    data inicio_cont; //data do inicio do contrato
    data final_cont; //data do fim do contrato
	int valor_logico; //valor lógico de exclusão
}colaborador;

/***********************************************
 *          PROTÓTIPOS
 **********************************************/

/**
 * @fn inserir_fornecedor(void)
 * @brief Solicita ao usuário a inserção dos seguintes dados:  Nome do fornecedor, quantidade de produtos a serem cadastrados,
 * CNPJ, telefone , o endereço e data do início das relações com o fornecedor. Além disso, a função gera o código dos fornecedores e
 * dos produtos, chamando a função gerador_codigo que possui como parâmetro o tipo do arquivo (Fornecedor | Produto | Colaborador).
 * Alem disso, é atribuido o valor 0 ao valor lógico de exclusão, indicando que não está excluso, por fim, ele escreve os dados
 * do fornecedor no final de um arquivo binário de fornecedores.
*/
void inserir_fornecedor(void);

/**
 * @fn inserir_produto(void)
 * @brief A Função recebe como argumento o código do produto e solicita ao usuário a inserção dos seguintes dados:
 * nome do produto, preço de compra, preço de venda e descrição do produto a ser ofertado. Em seguida, a função
 * atribui o valor 0 ao valor lógico de exclusão, indicando que não está excluso. Por fim, escreve os
 * dados do produto no final de um arquivo binário de produtos.
 * @param int codigo - código do produto a ser ofertado
*/
void inserir_produto(int codigo);

/**
 * @fn inserir_colaborador(void)
 * @brief Solicita ao usuário a inserção dos seguintes dados:
 * nome do colaborador, CPF, telefone , o endereço e data do início do contrato com o colaborador.
 * Além disso, a função gera o código do colaborador, chamando a função gerador_codigo,
 * que possui como parâmetro o tipo do arquivo (Fornecedor | Produto | Colaborador). Em seguida, ele
 * atribui o valor 0 ao valor lógico de exclusão, indicando que não está excluso. Por fim, ele escreve os
 * dados do colaborador no final de um arquivo binário de colaboradores.
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
 * Caso o usuário, na confirmação, digite 'n' ou 'N' a função irá retornar ao gerenciar_fornecedores.
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
 * digitar 's' ou 'S' a função solicita ao usuário os dados para serem atualizados, como: nome do colaborador, CPF, telefone,
 * o endereço e data do início do contrato com o colaborador. Em seguida, insere os dados no arquivo, no local do dados anteriores.
 * Caso o usuário, na confirmação, digite 'n' ou 'N' a função irá retornar ao gerenciar_colaborador.
*/
void atualizar_colaborador(void);

/**
 * @fn remover_fornecedor(void)
 * @brief Pede para o usuário digitar o código do fornecedor a ser removido, em seguida
 * faz a busca do código chamando a função binary_search. Caso o código não esteja
 * presente no arquivo de fornecedores ou o fornecedor já tenha sido excluído, é
 * apresentado na tela uma mensagen de código inexistente. Caso o código não esteja
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
 * presente no arquivo de produtos ou o produto já tenha sido excluído, é
 * apresentado na tela uma mensagen de código inexistente. Caso o código não esteja
 * excluído, são apresentados os dados do produto e pede para uma confirmação da
 * exclusão. Se o usúario informar que quer excluír o produto, a função exclui
 * logicamente o item, trocando o valor lógico de exclusão.
*/
void remover_produto(void);

/**
 * @fn remover_colaborador(void)
 * @brief Pede para o usuário digitar o código do colaborador a ser removido, em seguida
 * faz a busca do código chamando a função binary_search. Caso o código não esteja
 * presente no arquivo de colaboraboradores ou o colaborador já tenha sido excluído, é
 * apresentado na tela uma mensagen de código inexistente. Caso o código não esteja
 * excluído, são apresentados os dados do colaborador e pede uma confirmação da
 * exclusão. Se o usúario informar que quer excluír o colaborador, a função pede
 * para o usuário inserir a data do fim das relações e exclui logicamente o colaborador,
 * trocando o valor lógico de exclusão.
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

#endif //FUNC_H
