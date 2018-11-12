# Ponteiros
Ponteiro � uma vari�vel que armazena um endere�o de mem�ria,s�o usadas por 3 raz�es b�sicas:
1. Permitir que fun��es alterem os valores de vari�veis n�o globais ou n�o locais, passando o endere�o de mem�ria da vari�vel como par�metro para a fun��o.
2. Alocar ou desalocar mem�ria em tempo de execu��o(aloca��o din�mica).
3. Aumento de efici�ncia, j� que acessando diretamente uma vari�vel, pode-se gerenciaar melhor o uso de mem�ria. 

Por�m, o uso de ponteiros tr�s consigo uma grande *responsabilidade*, j� que existe acesso direto � mem�ria, pode-se acidentalmente substituir a mem�ria cr�tica do computador,
podendo ocasionar falhas em outros programas ou falhas sist�micas.


Sua declara��o � formato * nome_da_vari�vel e possui o uso de dois operadores:
1. *conte�do do endere�o apontado pelo ponteiro.
1. **&** endere�o de mem�ria.

```
#include <stdio.h>
void main()
{
  int a;
  int b;
  int c;
  int *ptr;  // declara um ponteiro para um inteiro
             // um ponteiro para uma vari�vel do tipo inteiro
  a = 90;
  b = 2;
  c = 3;
  ptr = &a;
  printf("Valor de ptr: %p, Conte�do de ptr: %d\n", ptr, *ptr);
  printf("B: %d, C: %d"), b, c);
} 
```

## Aloca�ao de mem�ria*
Durante a execu��o de um programa, pode-se alocar dinamicamente mem�ria para usar como vari�veis do programa. abaixo temos um exemplo de aloca��o de um vetor

```
#include <iostream>
using namespace std;

void main()
{
  int i;
  int *v;
  v = new int[10];  // 'v' � um ponteiro para uma �rea que
                    // tem 10 inteiros.
                    // 'v' funciona exatamente como um vetor
  v[0] = 10;
  v[1] = 11;
  v[2] = 12;
  // continua...
  v[9] = 19;

  for(i = 0; i < 10; i++)
    cout << "v[" << i << "]: " << v[i] << endl;

  cout << "Endere�o de 'v': " << v << endl; // imprime o endere�o da �rea alocada para 'v'
  delete[] v;
} 

```

Uma das aplica��es mais espec�ficas dos ponteiros � seu uso para criar **estruturas encadeadas**.
Abaixo temos um exemplo de como adicionar um n� no in�cio de uma lista

```
// (...)

TPESSOA *inicio, *ptr;

ptr = (TPESSOA*)malloc(sizeof(TPESSOA));
// Teste de aloca��o
if (ptr == NULL)
{
  printf("N�o foi poss�vel alocar mem�ria!\n");
  exit(1);
}

// L� os dados 
cin >>idade;
cin >>nome;

// Coloca os dados lidos na struct
P->idade = idade;
strcpy(P->nome, nome);

// Marca o nodo como �ltimo da lista  
P->prox = NULL;

//Insere no in�cio da lista
inicio = ptr;


*Podemos tamb�m ter vetores de ponteiros*


typedef struct temp
{
  int dado;
  struct temp *prox;
} TNODO;



TNODO *listas[5];

listas[0] = new TNODO;
listas[0]->prox = NULL;
aux = listas[0];
aux->prox = NULL;
```

##Ponteiros para fun��es

O uso de ponteiros para fun��es em C serve principalmente para definir, em tempo de execu��o, qual fun��o ser� executada, sem a necessidade de escrever o nome da fun��o, de forma expl�cita naquele ponto do c�digo. 
Em geral, a defini��o de qual fun��o ser� executada � feita em um outro ponto do c�digo, fazendo o ponteiro apontar para a fun��o desejada.

```
#include <stdio.h>

// ***************************************************
// O typedef a seguir cria um tipo chamado 'TipoFuncao' que define um 
// tipo de dado que � uma fun��o.
// O que determina o tipo, neste caso �:
// - o tipo de retorno da fun��o;
// - os par�metros usados na fun��o. Leva-se em conta a quantidade, 
//	 a ordem e o tipo destes par�metros 
typedef int TipoFuncao();


// ***************************************************
// As tr�s fun��es a seguir s�o do mesmo tipo de 'TipoFuncao'
// ***************************************************

int Load()
{
	// Veja o que significa a macro __FUNCTION__ em 
	// https://gcc.gnu.org/onlinedocs/cpp/Standard-Predefined-Macros.html#Standard-Predefined-Macros
	printf("%s\n", 	__FUNCTION__);
	return 10;
}

int Print()
{
	printf("%s\n", 	__func__);
	return 20;
}
int Quit()
{
	printf("%s\n", 	__func__);
	return 30;
}
// ***************************************************
//	Funcao que recebe um ponteiro para uma fun��o
//	'PonteiroParaUmaFuncao' e uma vari�vel que ir� 
//	armazenar o valor deste ponteiro 'GuardaEnderecoDeUmaFuncao'
// ***************************************************
void SetCallbackFunc(TipoFuncao **GuardaEnderecoDeUmaFuncao, TipoFuncao *PonteiroParaUmaFuncao)
{
	*GuardaEnderecoDeUmaFuncao = PonteiroParaUmaFuncao;
}

int main()
{
	int opcao, retorno;
	// Cria 3 ponteiros que ir�o apontar para fun��es do programa
	TipoFuncao *ptrF;

	// Faz cada um dos ponteiros apontar para uma fun��o diferente 
	
	do {
		printf("Digite sua opcao(1,2,3) :");
		scanf("%d", &opcao);
		switch(opcao) {
			case 1:
				ptrF = Load;
				break;
			case 2:
				ptrF = Print;
				break;
			case 3:
				SetCallbackFunc(&ptrF, Quit);
				break;
		}
		retorno = (*ptrF)(); // chama uma fun��o a partir de ptrF
							 // e obtem o retorno 
		printf ("Retorno da fun��o: %d\n\n", retorno);
	} while(opcao !=3);
}

```

[Refer�ncia 1](http://www.di.ufpb.br/liliane/aulas/ponteiros.html)
[Refer�ncia 2](https://www.inf.pucrs.br/~pinho/PRGSWB/Ponteiros/ponteiros.html)
[Refer�ncia 3](http://ptcomputador.com/P/computer-programming-languages/88721.html)
[Refer�ncia 4](https://www.inf.pucrs.br/~pinho/PRGSWB/PonteirosParaFuncoes/PonteirosParaFuncoes.html)

