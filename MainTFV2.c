#include <stdio.h>
#include <stdlib.h>

typedef struct{ //struct dos indices de disciplinas e alunos
    int posicao;
    int matricula;
    int situacao;
}indice;

typedef struct{ //struct de cadastro da disciplina
    int cod_disci;
    char nome_disc[60];
    char semestre[20];
    int ano;
    int situacao;
}disciplina;

typedef struct{ //struct de endereço
    char rua[40];
    char bairro[40];
    char CEP[13];
    char cidade[40];
    char UF[5];
}endereco;

typedef struct aluno{ //struct de cadastro de alunos
	int matricula;
	char nome[400];
	int idade;
	int quant_disc;
	int cod_disc[15];
	int situacao;
	endereco end;
}TAluno;

//Funcao para Inserir Aluno
void Inserir_Aluno();
//Funçao para Pesquisar Aluno
void Pesquisar_Aluno();
//Funçao para Inserir Disciplina
void Inserir_Disciplina();
//Função para Pesquisar Disciplina
void Pesquisar_Disciplina();
//Função para Alterar o Cadastro do Aluno
void Alterar_Aluno();
//Função para Alterar o Cadastro da Disciplina
void Alterar_Disciplina();
//Função para Deletar Disciplina
void Deletar_Disciplina();
//Função para Deletar Aluno
void Deletar_Aluno();


int main(){

    int opcao_principal, //Escolhe ação menu principal
        opcao_crud_disc, //Escolhe ação CRUD de Disciplina
        opcao_crud_alunos; //Escolhe ação CRUD de Alunos

    int aux_mprincipal=0, //Controla menu principal
        aux_crud_disc=0, //Controla gerenciar disciplinas
        aux_crud_alunos=0; //Controla gerenciar alunos


    while(aux_mprincipal==0){ // Retorno menu principal

        //Escolha das opções do menu principal
        printf("Digite o numero da opcao desejada:\n");
        printf("\n");
        printf("1 - Gerenciar disciplinas\n");
        printf("2 - Gerenciar alunos\n");
        printf("3 - Sair\n");
        printf("\n");
        scanf("%d", &opcao_principal);
        getchar();
        printf("\n");

        switch(opcao_principal){ //Opções do menu principal

            //--------------------------------------------------------------------------------------------

            case 1: //CRUD de Disciplina

            aux_crud_disc=0;

            while(aux_crud_disc==0){ // Retorno CRUD de Disciplina

                //Escolha das opções do CRUD de Disciplina
                printf("Digite o numero da opcao desejada:\n");
                printf("\n");
                printf("1 - Inserir disciplina\n");
                printf("2 - Pesquisar dados da disciplina\n");
                printf("3 - Atualizar dados da disciplina\n");
                printf("4 - Remover disciplina\n");
                printf("5 - Sair\n");
                printf("\n");
                scanf("%d", &opcao_crud_disc);
                getchar();
                printf("\n");

                switch(opcao_crud_disc){ //Opções do CRUD de Disciplina

                    case 1: //Inserir disciplina

                    Inserir_Disciplina();

                    break;

                    case 2: //Pesquisar disciplina

                    Pesquisar_Disciplina();

                    break;

                    case 3: //Atualizar dados da disciplina

                    Alterar_Disciplina();

                    break;

                    case 4: //Remover disciplina

                    Deletar_Disciplina();

                    break;

                    case 5: //Sair CRUD de Disciplina

                    aux_crud_disc=1;

                    break;

                    default:

                    printf("Opcao invalida!!\n");
                    printf("\n");

                    break;
                }
            }
            break;

            //--------------------------------------------------------------------------------------------

            case 2: //CRUD de Alunos

            aux_crud_alunos=0;

            while(aux_crud_alunos==0){ // Retorno CRUD de Alunos

                //Escolha das opções do CRUD de Alunos
                printf("Digite o numero da opcao desejada:\n");
                printf("\n");
                printf("1 - Inserir aluno\n");
                printf("2 - Pesquisar dados de um aluno\n");
                printf("3 - Atualizar os dados de um aluno\n");
                printf("4 - Remover aluno\n");
                printf("5 - Sair\n");
                printf("\n");
                scanf("%d", &opcao_crud_alunos);
                getchar();
                printf("\n");

                switch(opcao_crud_alunos){ //Opções do CRUD de Alunos

                    case 1: //Inserir aluno

                    Inserir_Aluno();

                    break;

                    case 2: //Pesquisar dados de um aluno

                    Pesquisar_Aluno();

                    break;

                    case 3: //Atualizar os dados de um aluno

                    Alterar_Aluno();

                    break;

                    case 4: //Remover aluno

                    Deletar_Aluno();

                    break;

                    case 5: //Sair CRUD de Alunos

                    aux_crud_alunos=1;

                    break;

                    default:

                    printf("Opcao invalida!!\n");
                    printf("\n");

                    break;
                }
            }
            break;

            //--------------------------------------------------------------------------------------------

            case 3: //Sair e fechar a main

            aux_mprincipal=1;

            break;

            default:

            printf("Opcao invalida!!\n");
            printf("\n");

            break;

        }
    }
}


//Funcao par Inserir Disciplina
void Inserir_Disciplina(){

    disciplina d; //Declarada a variavel do tipo struct disciplina, que armazena as informações do cadastro de disciplinas
    indice ind; //Declarada a variavel do tipo struct indice, que armazena o indice de disciplinas

    FILE *arq = fopen("disciplina.bin", "ab"); //Abertura do arquivo de disciplinas para escrita no final do arquivo
    if (arq == NULL){ //Checando se o arquivo foi aberto ou criado corretamente
        printf("Erro ao abrir arquivo");
        return;
    }

    FILE *arq2 = fopen("indicedisciplina.bin", "ab"); //Abertura do arquivo do indice de disciplinas para escrita no final do arquivo
    if (arq2 == NULL){ //Checando se o arquivo foi aberto ou criado corretamente
        printf("Erro ao abrir arquivo");
        exit(1);
    }

    setbuf(stdin,NULL); //Limpando o buffer do teclado

    printf("Digite o codigo da disciplina:\n"); //Alocando o codigo da disciplina
    setbuf(stdin,NULL); //Limpando o buffer do teclado
    scanf("%d", &d.cod_disci);
    getchar();
	printf("\n");

    printf("Digite o nome da disciplina:\n"); //Alocando o nome da disciplina
    setbuf(stdin,NULL); //Limpando o buffer do teclado
    scanf("%[^\n]", d.nome_disc);
    getchar();
	printf("\n");

    printf("Digite o semestre da disciplina:\n"); //Alocando o semestre da disciplina
    setbuf(stdin,NULL); //Limpando o buffer do teclado
    scanf("%[^\n]", d.semestre);
    getchar();
	printf("\n");

	printf("Digite o ano da disciplina:\n"); //Alocando o ano da disciplina
	setbuf(stdin,NULL); //Limpando o buffer do teclado
    scanf("%d", &d.ano);
    getchar();
	printf("\n");

	d.situacao=0; //Alocando a situção da disciplina: 0 para cadastrada e 1 para não cadastrada

	ind.posicao=ftell(arq); //Alocando a posição da struct do cadastro de disciplina no arquivo de indice de disciplinas
	ind.matricula=d.cod_disci; //Alocando o codigo da disciplina no arquivo de indice de disciplinas
	ind.situacao=0; //Alocando a situção da disciplina no indice de disciplinas: 0 para cadastrada e 1 para não cadastrada

	fwrite(&d,sizeof(disciplina),1,arq); //Escrevendo a struct do cadastro de disciplina no arquivo de disciplinas
	fwrite(&ind,sizeof(indice),1,arq2); //Escrevendo a struct do indice de disciplinas no arquivo de indice de disciplinas

	//Fechando os arquivos abertos na função
	fclose(arq);
	fclose(arq2);

    printf("Disciplina cadastrada com sucesso!!!\n");
    printf("\n");

	setbuf(stdin,NULL); //Limpando o buffer do teclado
}


//Funcao para Pesquisar Disciplina
void Pesquisar_Disciplina(){

    disciplina d; //Declarada a variavel do tipo struct disciplina, que armazena as informações do cadastro de disciplinas
    indice ind; //Declarada a variavel do tipo struct indice, que armazena o indice de disciplinas

    int aux_existe_disciplina=0; //Declarada a variavel auxiliar do tipo int para reconhecer se existe o cadastro da disciplina
    int codigo_disciplina=0; //Declarada a variavel do tipo int para armazenar o codigo da disciplina procurada

    FILE *arq = fopen("disciplina.bin", "rb"); //Abertura do arquivo de disciplinas para leitura
    if (arq == NULL){ //Checando se o arquivo foi aberto ou criado corretamente
        printf("O Arquivo selecionado nao existe.");
        exit(1);
    }

    FILE *arq2 = fopen("indicedisciplina.bin", "rb"); //Abertura do arquivo de indice de disciplinas para leitura
    if (arq2 == NULL){ //Checando se o arquivo foi aberto ou criado corretamente
        printf("Erro ao abrir arquivo");
        exit(1);
    }

    fseek(arq2, 0, SEEK_SET); //Deslocando os bytes de leitura do arquivo de indice de disciplinas para o inicio do arquivo

    setbuf(stdin,NULL); //Limpando o buffer do teclado

    printf("Digite o codigo da disciplina:\n"); //Escrita do codigo da disciplina a ser procurada
    setbuf(stdin,NULL); //Limpando o buffer do teclado
    scanf ("%d", &codigo_disciplina);
    getchar();
    printf("\n");

    while (!feof(arq2)){

        fread(&ind,sizeof(indice),1,arq2); //Leitura da struct do indice de disciplinas procurando o ID desejado

        if(ind.matricula==codigo_disciplina && ind.situacao==0){ //Comparação do ID desejado com o ID do indice de disciplinas

            fseek(arq, ind.posicao, SEEK_SET); //Deslocando o fluxo de leitura para o byte em que esta localizada a struct de informações da disciplina desejada

            fread(&d,sizeof(disciplina),1,arq); //Leitura da struct de informações da disciplina desejada

            //Impressão das informações da disciplina desejada
            printf("ID da Disciplina: %d\n", d.cod_disci);
            printf("Nome da Disciplina: %s\n", d.nome_disc);
            printf("Semestre da Disciplina: %s\n", d.semestre);
            printf("Ano da Disciplina: %d\n", d.ano);
            printf("\n");

            aux_existe_disciplina=1;

            break;
        }
    }

    if(aux_existe_disciplina==0){ //Mensagem para caso a disciplina procurada não esteja cadastrada

        printf("Disciplina nao cadastrada.\n");
        printf("\n");

    }

    setbuf(stdin,NULL); //Limpando o buffer do teclado

    //Fechando os arquivos abertos na função
    fclose(arq);
    fclose(arq2);
}


// Função para Alterar Cadastro da Disciplina
void Alterar_Disciplina(){

    disciplina d; //Declarada a variavel do tipo struct disciplina, que armazena as informações do cadastro de disciplinas
    indice ind; //Declarada a variavel do tipo struct indice, que armazena o indice de disciplinas

    int aux_existe_disciplina=0; //Declarada a variavel auxiliar do tipo int para reconhecer se existe o cadastro da disciplina
    int codigo_disciplina=0; //Declarada a variavel do tipo int para armazenar o codigo da disciplina procurada

    FILE *arq = fopen("disciplina.bin", "r+b"); //Abertura do arquivo de disciplinas para leitura e escrita
    if (arq == NULL){ //Checando se o arquivo foi aberto ou criado corretamente
        printf("O Arquivo selecionado nao existe.");
        exit(1);
    }

    FILE *arq2 = fopen("indicedisciplina.bin", "r+b"); //Abertura do arquivo de indice de disciplinas para leitura e escrita
    if (arq2 == NULL){ //Checando se o arquivo foi aberto ou criado corretamente
        printf("Erro ao abrir arquivo");
        exit(1);
    }

    fseek(arq2, 0, SEEK_SET); //Deslocando os bytes de leitura do arquivo de indice de disciplinas para o inicio do arquivo

    setbuf(stdin,NULL); //Limpando o buffer do teclado

    printf("Digite o codigo da disciplina:\n"); //Escrita do codigo da disciplina a ser procurada
    setbuf(stdin,NULL); //Limpando o buffer do teclado
    scanf ("%d", &codigo_disciplina);
    getchar();
    printf("\n");

    while (!feof(arq2)){

        fread(&ind,sizeof(indice),1,arq2); //Leitura da struct do indice de disciplinas procurando o ID desejado

        if(ind.matricula==codigo_disciplina && ind.situacao==0){ //Comparação do ID desejado com o ID do indice de disciplinas

            //É feito o mesmo processo da procura do cadastro da disciplina, para confirmar se o cadastro a ser atualizado é o correto
            fseek(arq, ind.posicao, SEEK_SET);

            fread(&d,sizeof(disciplina),1,arq);

            printf("Esta e a disciplina cadastrada que deseja alterar ?\n");
            printf("\n");

            printf("ID da Disciplina: %d\n", d.cod_disci);
            printf("Nome da Disciplina: %s\n", d.nome_disc);
            printf("Semestre da Disciplina: %s\n", d.semestre);
            printf("Ano da Disciplina: %d\n", d.ano);
            printf("\n");

            fseek(arq,sizeof(disciplina)*(-1), SEEK_CUR); //Deslocando o fluxo de leitura para o byte em que esta localizada a struct de informações da disciplina a ser atualizada

            printf("Digite o novo cadastro da disciplina:\n");
            printf("\n");

            printf("Digite o codigo da disciplina:\n"); //Alocando o codigo da disciplina
            setbuf(stdin,NULL);
            scanf("%d", &d.cod_disci);
            getchar();
            printf("\n");

            printf("Digite o nome da disciplina:\n"); //Alocando o nome da disciplina
            setbuf(stdin,NULL);
            scanf("%[^\n]", d.nome_disc);
            getchar();
            printf("\n");

            printf("Digite o semestre da disciplina:\n"); //Alocando o semestre da disciplina
            setbuf(stdin,NULL);
            scanf("%[^\n]", d.semestre);
            getchar();
            printf("\n");

            printf("Digite o ano da disciplina:\n"); //Alocando o ano da disciplina
            setbuf(stdin,NULL);
            scanf("%d", &d.ano);
            getchar();
            printf("\n");

            d.situacao=0; //0 cadastrado ou 1 não cadastrado

            fwrite(&d,sizeof(disciplina),1,arq); //Atualizando cadastro da disciplina
            fseek(arq, sizeof(disciplina)* 0, SEEK_END);

            fseek(arq2,sizeof(indice)*(-1), SEEK_CUR); //Atualizando cadastro do indice da disciplina
            ind.matricula=d.cod_disci;
            fwrite(&ind,sizeof(indice),1,arq2);
            fseek(arq2, sizeof(indice)*0, SEEK_END);

            printf("Cadastro da disciplina atualizado !!!!\n");
            printf("\n");

            aux_existe_disciplina=1;

            break;
        }
    }

    if(aux_existe_disciplina==0){ //Mensagem para caso a disciplina procurada não esteja cadastrada

        printf("Disciplina nao cadastrada.\n");
        printf("\n");

    }

    //Fechando os arquivos abertos na função
    fclose(arq);
    fclose(arq2);

    setbuf(stdin,NULL); //Limpando o buffer do teclado

}


//Função para Deletar Disciplina
void Deletar_Disciplina(){

    disciplina d; //Declarada a variavel do tipo struct disciplina, que armazena as informações do cadastro de disciplinas
    indice ind; //Declarada a variavel do tipo struct indice, que armazena o indice de disciplinas

    int aux_existe_disciplina=0; //Declarada a variavel auxiliar do tipo int para reconhecer se existe o cadastro da disciplina
    int codigo_disciplina=0; //Declarada a variavel do tipo int para armazenar o codigo da disciplina procurada

    FILE *arq = fopen("disciplina.bin", "r+b"); //Abertura do arquivo de disciplinas para leitura e escrita
    if (arq == NULL){ //Checando se o arquivo foi aberto ou criado corretamente
        printf("O Arquivo selecionado nao existe.");
        exit(1);
    }

    FILE *arq2 = fopen("indicedisciplina.bin", "r+b"); //Abertura do arquivo de indice de disciplinas para leitura e escrita
    if (arq2 == NULL){ //Checando se o arquivo foi aberto ou criado corretamente
        printf("Erro ao abrir arquivo");
        exit(1);
    }

    fseek(arq2, 0, SEEK_SET); //Deslocando os bytes de leitura do arquivo de indice de disciplinas para o inicio do arquivo

    setbuf(stdin,NULL); //Limpando o buffer do teclado

    printf("Digite o codigo da disciplina:\n"); //Escrita do codigo da disciplina a ser procurada
    setbuf(stdin,NULL); //Limpando o buffer do teclado
    scanf ("%d", &codigo_disciplina);
    getchar();
    printf("\n");

    while (!feof(arq2)){

        fread(&ind,sizeof(indice),1,arq2); //Leitura da struct do indice de disciplinas procurando o ID desejado

        if(ind.matricula==codigo_disciplina && ind.situacao==0){ //Comparação do ID desejado com o ID do indice de disciplinas

            //É feito o mesmo processo da procura do cadastro da disciplina, para confirmar se o cadastro a ser excluido é o correto
            fseek(arq, ind.posicao, SEEK_SET);

            fread(&d,sizeof(disciplina),1,arq);

            printf("Esta e a disciplina cadastrada que deseja excluir ?\n");
            printf("\n");

            printf("ID da Disciplina: %d\n", d.cod_disci);
            printf("Nome da Disciplina: %s\n", d.nome_disc);
            printf("Semestre da Disciplina: %s\n", d.semestre);
            printf("Ano da Disciplina: %d\n", d.ano);
            printf("\n");

            fseek(arq2,sizeof(indice)*(-1), SEEK_CUR); //Excluindo logicamente o cadastro do indice da disciplina
            ind.situacao=1;
            fwrite(&ind,sizeof(indice),1,arq2);
            fseek(arq2, sizeof(indice)*0, SEEK_END);

            fseek(arq,sizeof(disciplina)*(-1), SEEK_CUR); //Excluindo logicamente o cadastro da disciplina
            d.situacao=1;
            fwrite(&d,sizeof(disciplina),1,arq);
            fseek(arq, sizeof(disciplina)*0, SEEK_END);

            printf("Disciplina excluida com sucesso!!!\n");
            printf("\n");

            aux_existe_disciplina=1;

            break;
        }
    }

    if(aux_existe_disciplina==0){ //Mensagem para caso a disciplina procurada não esteja cadastrada

        printf("Disciplina nao cadastrada.\n");
        printf("\n");

    }

    //Fechando os arquivos abertos na função
    fclose(arq);
    fclose(arq2);

    setbuf(stdin,NULL); //Limpando o buffer do teclado

}


//Funcao para Inserir Aluno
void Inserir_Aluno(){

    TAluno info; //Declarada a variavel do tipo struct TAluno, que armazena as informações do cadastro do aluno
    indice ind; //Declarada a variavel do tipo struct indice, que armazena o indice do aluno

    int x=0; //Variavel para o controle da alocação de disciplinas

    FILE *arq = fopen("alunos.bin", "ab"); //Abertura do arquivo de alunos para escrita no final do arquivo
    if (arq == NULL){ //Checando se o arquivo foi aberto ou criado corretamente
        printf("Erro ao abrir arquivo");
        exit(1);
    }

    FILE *arq2 = fopen("indicealuno.bin", "ab"); //Abertura do arquivo do indice de alunos para escrita no final do arquivo
    if (arq2 == NULL){ //Checando se o arquivo foi aberto ou criado corretamente
        printf("Erro ao abrir arquivo");
        exit(1);
    }

    setbuf(stdin,NULL); //Limpando o buffer do teclado

    printf("Digite a matricula do aluno:\n"); //Alocando a matricula aluno
    setbuf(stdin,NULL); //Limpando o buffer do teclado
    scanf("%d", &info.matricula);
    getchar();
	printf("\n");

    printf("Digite o nome do aluno:\n"); //Alocando o nome do aluno
    setbuf(stdin,NULL); //Limpando o buffer do teclado
    scanf("%[^\n]", info.nome);
    getchar();
    printf("\n");

    printf("Digite a idade do aluno:\n"); //Alocando a matricula do aluno
    setbuf(stdin,NULL); //Limpando o buffer do teclado
    scanf("%d", &info.idade);
    getchar();
	printf("\n");

	printf("Digite a quantidade de disciplinas em que o aluno esta matriculado:\n"); //Alocando a quantidade de disciplinas em que o aluno está matriculado
	setbuf(stdin,NULL); //Limpando o buffer do teclado
	scanf("%d", &info.quant_disc);
	getchar();
	printf("\n");

	printf("Digite o ID das disciplinas que o aluno esta matriculado:\n");

    for(x=0; x<info.quant_disc; x++){ //Controle da quantidade de disciplinas em que o aluno está matriculado

        printf("Digite o ID da disciplina %d:\n", x+1); //Alocando o ID das disciplinas em que o aluno está matriculado
        setbuf(stdin,NULL); //Limpando o buffer do teclado
        scanf("%d", &info.cod_disc[x]);
        getchar();
	    printf("\n");
    }

	printf("Digite o endereco do aluno:\n"); //Alocando o endereço do aluno

    printf("Rua:\n"); //Alocando a Rua do aluno
    setbuf(stdin,NULL); //Limpando o buffer do teclado
    scanf("%[^\n]", info.end.rua);
    getchar();
	printf("\n");

    printf("Bairro:\n"); //Alocando o Bairro do aluno
    setbuf(stdin,NULL); //Limpando o buffer do teclado
    scanf("%[^\n]", info.end.bairro);
    getchar();
	printf("\n");

	printf("CEP:\n"); //Alocando o CEP do aluno
	setbuf(stdin,NULL); //Limpando o buffer do teclado
    scanf("%[^\n]", info.end.CEP);
    getchar();
	printf("\n");

	printf("Cidade:\n"); //Alocando a Cidade do aluno
	setbuf(stdin,NULL); //Limpando o buffer do teclado
    scanf("%[^\n]", info.end.cidade);
    getchar();
	printf("\n");

	printf("UF:\n"); //Alocando o UF do aluno
	setbuf(stdin,NULL); //Limpando o buffer do teclado
    scanf("%[^\n]", info.end.UF);
    getchar();
	printf("\n");

	info.situacao=0; //Alocando a situção do aluno: 0 para matriculado e 1 para não matriculado

	ind.posicao=ftell(arq); //Alocando a posição da struct do cadastro de alunos no arquivo de indice do aluno
	ind.matricula=info.matricula; //Alocando a matricula do aluno no arquivo de indice do aluno
	ind.situacao=0; //Alocando a situção do aluno no arquivo de indice do aluno: 0 para matriculado e 1 para não matriculado

	fwrite(&info,sizeof(TAluno),1,arq); //Escrevendo a struct do cadastro de alunos no arquivo de alunos
	fwrite(&ind,sizeof(indice),1,arq2); //Escrevendo a struct do indice do aluno no arquivo de indice do aluno

	fclose(arq); //Fechando o arquivo de alunos
	fclose(arq2); //Fechando o arquivo de indice do aluno

    printf("Aluno cadastrado com sucesso!!!\n");
    printf("\n");

	setbuf(stdin,NULL); //Limpando o buffer do teclado
}


//Funcao para Pesquisar Aluno
void Pesquisar_Aluno(){

    TAluno info; //Declarada a variavel do tipo struct TAluno, que armazena as informações do cadastro do aluno
    disciplina d; //Declarada a variavel do tipo struct disciplina, que armazena as informações do cadastro de disciplinas
    indice ind_a , ind_d; //Declaradas as variaveis do tipo struct indice, que armazena, respectivamente, o indice do aluno e o indice de disciplinas

    int aux_existe_aluno=0; //Declarada a variavel auxiliar do tipo int para reconhecer se existe o cadastro do aluno
    int matricula_aluno=0; //Declarada a variavel do tipo int para armazenar a matricula procurada
    int x=0; //Variavel para o controle da impressão de disciplinas
    int aux=0 , e_disc=0; //Variaveis para o controle da impressão de disciplinas e reconhecimento da existencia da disciplina, respectivamente.

    FILE *arq = fopen("alunos.bin", "rb"); //Abertura do arquivo de alunos para leitura
    if (arq == NULL){ //Checando se o arquivo foi aberto corretamente
        printf("O Arquivo selecionado nao existe.");
        exit(1);
    }

    FILE *arq2 = fopen("disciplina.bin", "rb"); //Abertura do arquivo de disciplinas para leitura
    if (arq2 == NULL){ //Checando se o arquivo foi aberto corretamente
        printf("O Arquivo selecionado nao existe.");
        exit(1);
    }

    FILE *arq3 = fopen("indicealuno.bin", "rb"); //Abertura do arquivo de indice de alunos para leitura
    if (arq3 == NULL){ //Checando se o arquivo foi aberto corretamente
        printf("O Arquivo selecionado nao existe.");
        exit(1);
    }

    FILE *arq4 = fopen("indicedisciplina.bin", "rb"); //Abertura do arquivo de indice de disciplinas para leitura
    if (arq4 == NULL){ //Checando se o arquivo foi aberto corretamente
        printf("O Arquivo selecionado nao existe.");
        exit(1);
    }

    fseek(arq3, 0, SEEK_SET); //Deslocando os bytes de leitura do arquivo de indice de alunos para o inicio do arquivo

    setbuf(stdin,NULL); //Limpando o buffer do teclado

    printf("Digite a matricula do aluno:\n"); //Escrita da matricula do aluno a ser procurado
    scanf ("%d", &matricula_aluno);
    getchar();
    printf("\n");

    while (!feof(arq3)){

        fread(&ind_a,sizeof(indice),1,arq3); //Leitura da struct do indice de alunos procurando a matricula desejada

        if(ind_a.matricula==matricula_aluno && ind_a.situacao==0){ //Comparando a matricula desejada com a lida no indice

            fseek(arq, ind_a.posicao, SEEK_SET); //Deslocando o fluxo de leitura para o byte em que esta localizada a struct de informações do aluno desejado

            fread(&info,sizeof(TAluno),1,arq); //Leitura da struct de informações do aluno desejado

            printf("Matricula: %d\n", info.matricula); //Impressão da matricula do aluno
            printf("\n");

        	printf("Nome do Aluno: %s\n", info.nome); //Impressão do nome do aluno
        	printf("\n");

	        printf("Idade do Aluno: %d\n", info.idade); //Impressão da idade do aluno
	        printf("\n");

	        printf("Disciplinas Matriculadas:\n");
	        printf("\n");

	        for(x=0; x<info.quant_disc; x++){ //Impressão das disciplinas em que o aluno está matriculado

	            fseek(arq4, 0, SEEK_SET); //Deslocando os bytes de leitura do arquivo de indice de disciplinas para o inicio do arquivo

	            printf("ID da disciplina %d: %d\n", x+1, info.cod_disc[x]);

	            while(!feof(arq4) && aux!=1){ //Pesquisa das disciplinas em que o aluno esta matriculado, no arquivo de disciplinas

	                fread(&ind_d,sizeof(indice),1,arq4); //Leitura da struct do indice de disciplinas procurando o ID desejado

	                if(ind_d.matricula==info.cod_disc[x] && ind_d.situacao==0){ //Comparação das diciplinas em que o aluno esta matriculado com o indice de matriculas

	                    fseek(arq2, ind_d.posicao, SEEK_SET); //Deslocando o fluxo de leitura para o byte em que esta localizada a struct de informações da disciplina desejada

	                    fread(&d,sizeof(disciplina),1,arq2); //Leitura da struct de informações da disciplina desejada

	                    printf("Nome da Disciplina: %s\n", d.nome_disc);
	                    printf("Semestre da Disciplina: %s\n", d.semestre);
	                    printf("Ano da Disciplina: %d\n", d.ano);
	                    printf("\n");

	                    aux=1;
	                    e_disc=1;
	                }
	            }

	            if(e_disc==0){ //Mensagem para caso a disciplina em que o aluno está matriculado não esteja cadastrada no sistema
	                printf("Disciplina %d nao cadastrada. Recomenda-se que atualize o cadastro do aluno ou cadastre a disciplina no sistema.\n", x+1);
	                printf("\n");
	            }

	            aux=0;
	            e_disc=0;
	        }

	        printf("Endereco:\n"); //Impressão do endereço do aluno
            printf("Rua: %s Bairro: %s CEP: %s Cidade: %s UF: %s\n", info.end.rua, info.end.bairro, info.end.CEP, info.end.cidade, info.end.UF);
            printf("\n");

            aux_existe_aluno=1;

            break;
        }
    }

    if(aux_existe_aluno==0){ //Mensagem para caso o aluno procurado não esteja matriculado

        printf("Aluno nao matriculado.\n");
        printf("\n");

    }

    //Fechando os arquivos abertos na função
    fclose(arq);
    fclose(arq2);
    fclose(arq3);
    fclose(arq4);

    setbuf(stdin,NULL); //Limpando o buffer do teclado
}


//Função para Alterar Cadastro do Aluno
void Alterar_Aluno(){

    TAluno info; //Declarada a variavel do tipo struct TAluno, que armazena as informações do cadastro do aluno
    disciplina d; //Declarada a variavel do tipo struct disciplina, que armazena as informações do cadastro de disciplinas
    indice ind_a , ind_d; //Declaradas as variaveis do tipo struct indice, que armazena, respectivamente, o indice do aluno e o indice de disciplinas

    int aux_existe_aluno=0; //Declarada a variavel auxiliar do tipo int para reconhecer se existe o cadastro do aluno
    int matricula_aluno=0; //Declarada a variavel do tipo int para armazenar a matricula procurada
    int x=0; //Variavel para o controle da impressão de disciplinas
    int aux=0 , e_disc=0; //Variaveis para o controle da impressão de disciplinas e reconhecimento da existencia da disciplina, respectivamente.

    FILE *arq = fopen("alunos.bin", "r+b"); //Abertura do arquivo de alunos para leitura e escrita
    if (arq == NULL){ //Checando se o arquivo foi aberto corretamente
        printf("O Arquivo selecionado nao existe.");
        exit(1);
    }

    FILE *arq2 = fopen("disciplina.bin", "rb"); //Abertura do arquivo de disciplinas para leitura
    if (arq2 == NULL){ //Checando se o arquivo foi aberto corretamente
        printf("O Arquivo selecionado nao existe.");
        exit(1);
    }

    FILE *arq3 = fopen("indicealuno.bin", "r+b"); //Abertura do arquivo de indice de alunos para leitura e escrita
    if (arq3 == NULL){ //Checando se o arquivo foi aberto corretamente
        printf("O Arquivo selecionado nao existe.");
        exit(1);
    }

    FILE *arq4 = fopen("indicedisciplina.bin", "rb"); //Abertura do arquivo de indice de disciplinas para leitura
    if (arq4 == NULL){ //Checando se o arquivo foi aberto corretamente
        printf("O Arquivo selecionado nao existe.");
        exit(1);
    }

    fseek(arq3, 0, SEEK_SET); //Deslocando os bytes de leitura do arquivo de indice de alunos para o inicio do arquivo

    setbuf(stdin,NULL); //Limpando o buffer do teclado

    printf("Digite a matricula do aluno:\n"); //Escrita da matricula do aluno a ser atualizado
    scanf ("%d", &matricula_aluno);
    getchar();
    printf("\n");

    while (!feof(arq3)){

        fread(&ind_a,sizeof(indice),1,arq3); //Leitura da struct do indice de alunos procurando a matricula desejada

        if(ind_a.matricula==matricula_aluno && ind_a.situacao==0){ //Comparando a matricula desejada com a lida no indice

            //É feito o mesmo processo da procura do cadastro do aluno, para confirmar se o cadastro a ser atualizado é o correto
            fseek(arq, ind_a.posicao, SEEK_SET);

            fread(&info,sizeof(TAluno),1,arq);

            printf("Este e o aluno cadastrado que deseja alterar ?\n");
            printf("\n");

            printf("Matricula: %d\n", info.matricula);
            printf("\n");

        	printf("Nome do Aluno: %s\n", info.nome);
        	printf("\n");

	        printf("Idade do Aluno: %d\n", info.idade);
	        printf("\n");

	        printf("Disciplinas Matriculadas:\n");
	        printf("\n");

	        for(x=0; x<info.quant_disc; x++){

	            fseek(arq4, 0, SEEK_SET);

	            printf("ID da disciplina %d: %d\n", x+1, info.cod_disc[x]);

	            while(!feof(arq4) && aux!=1){

	                fread(&ind_d,sizeof(indice),1,arq4);

	                if(ind_d.matricula==info.cod_disc[x] && ind_d.situacao==0){

	                    fseek(arq2, ind_d.posicao, SEEK_SET);

	                    fread(&d,sizeof(disciplina),1,arq2);

	                    printf("Nome da Disciplina: %s\n", d.nome_disc);
	                    printf("Semestre da Disciplina: %s\n", d.semestre);
	                    printf("Ano da Disciplina: %d\n", d.ano);
	                    printf("\n");

	                    aux=1;
	                    e_disc=1;
	                }
	            }

	            if(e_disc==0){
	                printf("Disciplina %d nao cadastrada. Recomenda-se que atualize o cadastro do aluno ou cadastre a disciplina no sistema.\n", x+1);
	                printf("\n");
	            }

	            aux=0;
	            e_disc=0;
	        }

	        printf("Endereco:\n");
            printf("Rua: %s Bairro: %s CEP: %s Cidade: %s UF: %s\n", info.end.rua, info.end.bairro, info.end.CEP, info.end.cidade, info.end.UF);
            printf("\n");

            fseek(arq,sizeof(TAluno)*(-1), SEEK_CUR); //Deslocando o fluxo de leitura para o byte em que esta localizada a struct de informações do aluno a ser atualizada

            printf("Digite o novo cadastro do aluno:\n");
            printf("\n");

            printf("Digite a matricula do aluno:\n"); //Alocando a matricula do alunol
            setbuf(stdin,NULL);
            scanf("%d", &info.matricula);
            getchar();
            printf("\n");

            printf("Digite o nome do aluno:\n"); //Alocando o nome do aluno
            setbuf(stdin,NULL);
            scanf("%[^\n]", info.nome);
            getchar();
            printf("\n");

            printf("Digite a idade do aluno:\n"); //Alocando a idade do aluno
            setbuf(stdin,NULL);
            scanf("%d", &info.idade);
            getchar();
            printf("\n");

            printf("Digite a quantidade de disciplinas em que o aluno esta matriculado:\n"); //Alocando a quantidade de disciplinas em que o aluno esta matriculado
            setbuf(stdin,NULL);
            scanf("%d", &info.quant_disc);
            getchar();
            printf("\n");

            printf("Digite o ID das disciplinas que o aluno esta matriculado:\n");

            for(x=0; x<info.quant_disc; x++){

                printf("Digite o ID da disciplina %d:\n", x+1); //Alocando o ID da disciplina
                setbuf(stdin,NULL);
                scanf("%d", &info.cod_disc[x]);
                getchar();
                printf("\n");
            }

            printf("Digite o endereco do aluno:\n"); //Alocando o endereço do aluno

            printf("Rua:\n"); //Alocando a Rua do aluno
            setbuf(stdin,NULL);
            scanf("%[^\n]", info.end.rua);
            getchar();
            printf("\n");

            printf("Bairro:\n"); //Alocando o Bairro do aluno
            setbuf(stdin,NULL);
            scanf("%[^\n]", info.end.bairro);
            getchar();
            printf("\n");

            printf("CEP:\n"); //Alocando o CEP do aluno
            setbuf(stdin,NULL);
            scanf("%[^\n]", info.end.CEP);
            getchar();
            printf("\n");

            printf("Cidade:\n"); //Alocando a Cidade do aluno
            setbuf(stdin,NULL);
            scanf("%[^\n]", info.end.cidade);
            getchar();
            printf("\n");

            printf("UF:\n"); //Alocando UF do aluno
            setbuf(stdin,NULL);
            scanf("%[^\n]", info.end.UF);
            getchar();
            printf("\n");

            info.situacao=0; //Alocando a situção do aluno: 0 para matriculado e 1 para não matriculado

            fwrite(&info,sizeof(TAluno),1,arq); //Atualizando cadastro do aluno
            fseek(arq, sizeof(TAluno)* 0, SEEK_END);

            fseek(arq3,sizeof(indice)*(-1), SEEK_CUR); //Atualizando cadastro do indice do aluno
            ind_a.matricula=info.matricula;
            fwrite(&ind_a,sizeof(indice),1,arq3);
            fseek(arq3, sizeof(indice)*0, SEEK_END);

            printf("Cadastro do aluno atualizado !!!!\n");
            printf("\n");

            aux_existe_aluno=1;

            break;
        }
    }

    if(aux_existe_aluno==0){ //Mensagem para caso o aluno procurado não esteja matriculado

        printf("Aluno nao matriculado.\n");
        printf("\n");

    }

    //Fechando os arquivos abertos na função
    fclose(arq);
    fclose(arq2);
    fclose(arq3);
    fclose(arq4);

    setbuf(stdin,NULL); //Limpando o buffer do teclado

}


//Função para Deletar Aluno
void Deletar_Aluno(){

    TAluno info; //Declarada a variavel do tipo struct TAluno, que armazena as informações do cadastro do aluno
    disciplina d; //Declarada a variavel do tipo struct disciplina, que armazena as informações do cadastro de disciplinas
    indice ind_a , ind_d; //Declaradas as variaveis do tipo struct indice, que armazena, respectivamente, o indice do aluno e o indice de disciplinas

    int aux_existe_aluno=0; //Declarada a variavel auxiliar do tipo int para reconhecer se existe o cadastro do aluno
    int matricula_aluno=0; //Declarada a variavel do tipo int para armazenar a matricula procurada
    int x=0; //Variavel para o controle da impressão de disciplinas
    int aux=0 , e_disc=0; //Variaveis para o controle da impressão de disciplinas e reconhecimento da existencia da disciplina, respectivamente.

    FILE *arq = fopen("alunos.bin", "r+b"); //Abertura do arquivo de alunos para leitura e escrita
    if (arq == NULL){ //Checando se o arquivo foi aberto corretamente
        printf("O Arquivo selecionado nao existe.");
        exit(1);
    }

    FILE *arq2 = fopen("disciplina.bin", "rb"); //Abertura do arquivo de disciplinas para leitura
    if (arq2 == NULL){ //Checando se o arquivo foi aberto corretamente
        printf("O Arquivo selecionado nao existe.");
        exit(1);
    }

    FILE *arq3 = fopen("indicealuno.bin", "r+b"); //Abertura do arquivo de indice de alunos para leitura e escrita
    if (arq3 == NULL){ //Checando se o arquivo foi aberto corretamente
        printf("O Arquivo selecionado nao existe.");
        exit(1);
    }

    FILE *arq4 = fopen("indicedisciplina.bin", "rb"); //Abertura do arquivo de indice de disciplinas para leitura
    if (arq4 == NULL){ //Checando se o arquivo foi aberto corretamente
        printf("O Arquivo selecionado nao existe.");
        exit(1);
    }

    fseek(arq3, 0, SEEK_SET); //Deslocando os bytes de leitura do arquivo de indice de alunos para o inicio do arquivo

    setbuf(stdin,NULL); //Limpando o buffer do teclado

    printf("Digite a matricula do aluno:\n"); //Escrita da matricula do aluno a ser atualizado
    scanf ("%d", &matricula_aluno);
    getchar();
    printf("\n");

    while (!feof(arq3)){

        fread(&ind_a,sizeof(indice),1,arq3); //Leitura da struct do indice de alunos procurando a matricula desejada

        if(ind_a.matricula==matricula_aluno && ind_a.situacao==0){ //Comparando a matricula desejada com a lida no indice

            //É feito o mesmo processo da procura do cadastro do aluno, para confirmar se o cadastro a ser excluido é o correto
            fseek(arq, ind_a.posicao, SEEK_SET);

            fread(&info,sizeof(TAluno),1,arq);

            printf("Este e o aluno cadastrado que deseja excluir ?\n");
            printf("\n");

            printf("Matricula: %d\n", info.matricula);
            printf("\n");

        	printf("Nome do Aluno: %s\n", info.nome);
        	printf("\n");

	        printf("Idade do Aluno: %d\n", info.idade);
	        printf("\n");

	        printf("Disciplinas Matriculadas:\n");
	        printf("\n");

	        for(x=0; x<info.quant_disc; x++){

	            fseek(arq4, 0, SEEK_SET);

	            printf("ID da disciplina %d: %d\n", x+1, info.cod_disc[x]);

	            while(!feof(arq4) && aux!=1){

	                fread(&ind_d,sizeof(indice),1,arq4);

	                if(ind_d.matricula==info.cod_disc[x] && ind_d.situacao==0){

	                    fseek(arq2, ind_d.posicao, SEEK_SET);

	                    fread(&d,sizeof(disciplina),1,arq2);

	                    printf("Nome da Disciplina: %s\n", d.nome_disc);
	                    printf("Semestre da Disciplina: %s\n", d.semestre);
	                    printf("Ano da Disciplina: %d\n", d.ano);
	                    printf("\n");

	                    aux=1;
	                    e_disc=1;
	                }
	            }

	            if(e_disc==0){
	                printf("Disciplina %d nao cadastrada. Recomenda-se que atualize o cadastro do aluno ou cadastre a disciplina no sistema.\n", x+1);
	                printf("\n");
	            }

	            aux=0;
	            e_disc=0;
	        }

	        printf("Endereco:\n");
            printf("Rua: %s Bairro: %s CEP: %s Cidade: %s UF: %s\n", info.end.rua, info.end.bairro, info.end.CEP, info.end.cidade, info.end.UF);
            printf("\n");

            fseek(arq3,sizeof(indice)*(-1), SEEK_CUR); //Excluindo logicamente cadastro do indice do aluno
            ind_a.situacao=1;
            fwrite(&ind_a,sizeof(indice),1,arq3);
            fseek(arq3, sizeof(indice)*0, SEEK_END);

            fseek(arq,sizeof(TAluno)*(-1), SEEK_CUR); //Excluindo logicamente cadastro do aluno
            info.situacao=1;
            fwrite(&info,sizeof(TAluno),1,arq);
            fseek(arq, sizeof(TAluno)*0, SEEK_END);

            printf("Aluno excluido com sucesso!!!\n");
            printf("\n");

            aux_existe_aluno=1;

            break;
        }
    }

    if(aux_existe_aluno==0){ //Mensagem para caso o aluno procurado não esteja matriculado

        printf("Aluno nao matriculado.\n");
        printf("\n");

    }

    //Fechando os arquivos abertos na função
    fclose(arq);
    fclose(arq2);
    fclose(arq3);
    fclose(arq4);

    setbuf(stdin,NULL); //Limpando o buffer do teclado
}