# Ponteiros
Ponteiro � uma vari�vel que armazena um endere�o de mem�ria,s�o usadas por 3 raz�es b�sicas:
1. Permitir que fun��es alterem os valores de vari�veis n�o globais ou n�o locais, passando o endere�o de mem�ria da vari�vel como par�metro para a fun��o.
2. Alocar ou desalocar mem�ria em tempo de execu��o(aloca��o din�mica).
3. Aumento de efici�ncia, j� que acessando diretamente uma vari�vel, pode-se gerenciaar melhor o uso de mem�ria. 

Por�m, o uso de ponteiros tr�s consigo uma grande *responsabilidade*, j� que existe acesso direto � mem�ria, pode-se acidentalmente substituir a mem�ria cr�tica do computador,
podendo ocasionar falhas em outros programas ou falhas sist�micas.


Sua declara��o � formato * nome_da_vari�vel e possui o uso de dois operadores:
1. *conte�do do endere�o apontado pelo ponteiro
1. **&** endere�o de mem�ria

Uma das aplica��es mais espec�ficas dos ponteiros � seu uso para criar estruturas encadeadas.



[Refer�ncia 1](http://www.di.ufpb.br/liliane/aulas/ponteiros.html)
[Refer�ncia 2](https://www.inf.pucrs.br/~pinho/PRGSWB/Ponteiros/ponteiros.html)
[Refer�ncia 3](http://ptcomputador.com/P/computer-programming-languages/88721.html)