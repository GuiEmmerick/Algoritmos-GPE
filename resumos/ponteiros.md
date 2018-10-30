# Ponteiros
Ponteiro é uma variável que armazena um endereço de memória,são usadas por 3 razões básicas:
1. Permitir que funções alterem os valores de variáveis não globais ou não locais, passando o endereço de memória da variável como parâmetro para a função.
2. Alocar ou desalocar memória em tempo de execução(alocação dinâmica).
3. Aumento de eficiência, já que acessando diretamente uma variável, pode-se gerenciaar melhor o uso de memória. 

Porém, o uso de ponteiros trás consigo uma grande *responsabilidade*, já que existe acesso direto à memória, pode-se acidentalmente substituir a memória crítica do computador,
podendo ocasionar falhas em outros programas ou falhas sistémicas.


Sua declaração é formato * nome_da_variável e possui o uso de dois operadores:
1. *conteúdo do endereço apontado pelo ponteiro
1. **&** endereço de memória

Uma das aplicações mais específicas dos ponteiros é seu uso para criar estruturas encadeadas.



[Referência 1](http://www.di.ufpb.br/liliane/aulas/ponteiros.html)
[Referência 2](https://www.inf.pucrs.br/~pinho/PRGSWB/Ponteiros/ponteiros.html)
[Referência 3](http://ptcomputador.com/P/computer-programming-languages/88721.html)