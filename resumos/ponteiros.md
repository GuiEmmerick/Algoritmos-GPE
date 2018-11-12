# Ponteiros
Ponteiro é uma variável que armazena um endereço de memória,são usadas por 3 razões básicas:
1. Permitir que funções alterem os valores de variáveis não globais ou não locais, passando o endereço de memória da variável como parâmetro para a função.
2. Alocar ou desalocar memória em tempo de execução(alocação dinâmica).
3. Aumento de eficiência, já que acessando diretamente uma variável, pode-se gerenciaar melhor o uso de memória. 

Porém, o uso de ponteiros trás consigo uma grande *responsabilidade*, já que existe acesso direto à memória, pode-se acidentalmente substituir a memória crítica do computador,
podendo ocasionar falhas em outros programas ou falhas sistémicas.


Sua declaração é formato * nome_da_variável e possui o uso de dois operadores:
1. *conteúdo do endereço apontado pelo ponteiro.
1. **&** endereço de memória.

```
#include <stdio.h>
void main()
{
  int a;
  int b;
  int c;
  int *ptr;  // declara um ponteiro para um inteiro
             // um ponteiro para uma variável do tipo inteiro
  a = 90;
  b = 2;
  c = 3;
  ptr = &a;
  printf("Valor de ptr: %p, Conteúdo de ptr: %d\n", ptr, *ptr);
  printf("B: %d, C: %d"), b, c);
} 
```

## Alocaçao de memória*
Durante a execução de um programa, pode-se alocar dinamicamente memória para usar como variáveis do programa. abaixo temos um exemplo de alocação de um vetor

```
#include <iostream>
using namespace std;

void main()
{
  int i;
  int *v;
  v = new int[10];  // 'v' é um ponteiro para uma área que
                    // tem 10 inteiros.
                    // 'v' funciona exatamente como um vetor
  v[0] = 10;
  v[1] = 11;
  v[2] = 12;
  // continua...
  v[9] = 19;

  for(i = 0; i < 10; i++)
    cout << "v[" << i << "]: " << v[i] << endl;

  cout << "Endereço de 'v': " << v << endl; // imprime o endereço da área alocada para 'v'
  delete[] v;
} 

```

Uma das aplicações mais específicas dos ponteiros é seu uso para criar **estruturas encadeadas**.
Abaixo temos um exemplo de como adicionar um nó no início de uma lista

```
// (...)

TPESSOA *inicio, *ptr;

ptr = (TPESSOA*)malloc(sizeof(TPESSOA));
// Teste de alocação
if (ptr == NULL)
{
  printf("Não foi possível alocar memória!\n");
  exit(1);
}

// Lê os dados 
cin >>idade;
cin >>nome;

// Coloca os dados lidos na struct
P->idade = idade;
strcpy(P->nome, nome);

// Marca o nodo como último da lista  
P->prox = NULL;

//Insere no início da lista
inicio = ptr;


*Podemos também ter vetores de ponteiros*


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

##Ponteiros para funções

O uso de ponteiros para funções em C serve principalmente para definir, em tempo de execução, qual função será executada, sem a necessidade de escrever o nome da função, de forma explícita naquele ponto do código. 
Em geral, a definição de qual função será executada é feita em um outro ponto do código, fazendo o ponteiro apontar para a função desejada.

```
#include <stdio.h>

// ***************************************************
// O typedef a seguir cria um tipo chamado 'TipoFuncao' que define um 
// tipo de dado que é uma função.
// O que determina o tipo, neste caso é:
// - o tipo de retorno da função;
// - os parâmetros usados na função. Leva-se em conta a quantidade, 
//	 a ordem e o tipo destes parâmetros 
typedef int TipoFuncao();


// ***************************************************
// As três funções a seguir são do mesmo tipo de 'TipoFuncao'
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
//	Funcao que recebe um ponteiro para uma função
//	'PonteiroParaUmaFuncao' e uma variável que irá 
//	armazenar o valor deste ponteiro 'GuardaEnderecoDeUmaFuncao'
// ***************************************************
void SetCallbackFunc(TipoFuncao **GuardaEnderecoDeUmaFuncao, TipoFuncao *PonteiroParaUmaFuncao)
{
	*GuardaEnderecoDeUmaFuncao = PonteiroParaUmaFuncao;
}

int main()
{
	int opcao, retorno;
	// Cria 3 ponteiros que irão apontar para funções do programa
	TipoFuncao *ptrF;

	// Faz cada um dos ponteiros apontar para uma função diferente 
	
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
		retorno = (*ptrF)(); // chama uma função a partir de ptrF
							 // e obtem o retorno 
		printf ("Retorno da função: %d\n\n", retorno);
	} while(opcao !=3);
}

```

[Referência 1](http://www.di.ufpb.br/liliane/aulas/ponteiros.html)
[Referência 2](https://www.inf.pucrs.br/~pinho/PRGSWB/Ponteiros/ponteiros.html)
[Referência 3](http://ptcomputador.com/P/computer-programming-languages/88721.html)
[Referência 4](https://www.inf.pucrs.br/~pinho/PRGSWB/PonteirosParaFuncoes/PonteirosParaFuncoes.html)

