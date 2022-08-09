# Projeto de implementação para a disciplina de Estrutura de Dados 1

![logo](https://user-images.githubusercontent.com/74943794/117087041-c1654700-ad24-11eb-898e-1563ddb32717.png)

## Descrição do Projeto

 O projeto consiste no desenvolvimento de um sistema de gestão
 de dados de fornecedores, produtos e colaboradores de uma varejista (”Não-Magalu”). Elaborado para rodar em linha de comando, o sistema foi desenvolvido em linguagem C e permite, além da inserção, pesquisa, alteração e remoção dos dados, apresentar um relatório geral dos dados que foram obtidos.

### Tabela de conteúdos

* [Descrição do Projeto](#descrição-do-Projeto)
* [Tabela de conteúdos](#tabela-de-conteúdos)
* [Como  compilar e rodar](#como-compilar-e-rodar)
* [Dados no cadastro](#dados-no-cadastro)
    * [1. Produtos](#1-produtos)
    * [2. Fornecedores](#2-fornecedores)
    * [3. Colaboradores](#3-colaboradores)
* [Features](#features)
* [Quem são os desenvolvedores](#quem-são-os-desenvolvedores)

### Como compilar e rodar

Para compilar o programa, primeiro você deve conferir se a sua máquina possui um compilador de C instalado com o seguinte comando: 

```
gcc -v
```

(No caso utilizamos o gcc, um compilador que já vem disponível para a maiorias das distribuições Linux e que pode ser instalada facilmente em compudatores com Windows e OSX)

Caso não apareça uma mensagem de erro, insira os seguintes  comando:

- Para entrar na pasta:
```
cd <Caminho para o diretório src>
```

- Para compilar:
```
gcc main.c auxi.c func.c -lm -o <Nome do executável>
```

Após isso, basta rodar com:
- No terminal do linux:
```
./<Nome do executável>
```

- No CMD do Windows:
```
<Nome do executável>
```

- No PowerShell:
```
./<Nome do executável>
```

### Dados no cadastro

Os dados que serão cadastrados no sistema são:

#### 1. Produtos

- Nome do produto;
- Código do produto;
- Valor de venda;
- Valor de compra;
- Pequena descrição do produto que está sendo vendido.

#### 2. Fornecedores

- Nome do fornecedor;
- Código do fornecedor;
- CNPJ;
- Endereço (Rua, Bairro, CEP, UF e Cidade);
- Telefone;
- Quantidade de produtos que são comprados;
- Data de início das relações;
- Data do fim das relações.

#### 3. Colaboradores

- Nome do colaborador;
- Código do colaborador; 
- Cargo que ocupa;
- Salário; 
- CPF;	
- Endereço (Rua, Bairro, Cep, Cidade, UF);
- Telefone de contato;
- Data de inicio do contrato;
- Data do fim do contrato; 

Os  CRUD's de fornecedores e colaboradores em si, devem conter as opções de inserção, remoção, alteração e consulta dos dados que foram obtidos e o CRUD de produtos as opções de pesquisar, atualizar e remover produtos. Foi colocado também uma opção, em cada um dos CRUD's, para apresentar um relatório geral dos dados que foram obtidos.

---
### Features

- [x] Função para limpeza de tela;
- [X] Menu principal;
- [X] Menu para Gerenciar Fornecedores;
- [X] Menu para Gerenciar Colaboradores;
- [X] Menu para Gerenciar Produtos;
- [X] Confirmação da exclusão | alteração;
- [X] Gerenciador de códigos;
- [X] Inserção de Produtos;
- [X] Inserção de Fornecedores;
- [X] Inserção de Colaboradores;
- [X] Pesquisar cadastro do Produto;
- [X] Pesquisar cadastro do Fornecedor;
- [X] Pesquisar cadastro do Colaborador;
- [X] Remoção do Produtos;
- [X] Remoção do Fornecedores;
- [X] Remoção do Colaborador;
- [X] Atualização do cadastro do Produto;
- [X] Atualização do cadastro do Fornecedor;
- [X] Atualização do cadastro do Colaborador;
- [X] Relatório Geral de Produtos;
- [x] Relatório Geral de Fornecedores;
- [X] Relatório Geral de Colaboradores;

---
### Quem são os desenvolvedores

A equipe de desenvolvimento é composta pelos alunos: 

__[Diego Enrique da Silva Lima](https://github.com/dgoenrique)__

- E-mail: diegoenrique@discente.ufg.br;
- Aluno de Ciência da Computação do INF-UFG.

__[Gustavo Rodrigues Ribeiro](https://github.com/GustavooRibas)__

- E-mail:  ribeirogustavo@discente.ufg.br;
- Aluno de Ciência da Computação do INF-UFG.

