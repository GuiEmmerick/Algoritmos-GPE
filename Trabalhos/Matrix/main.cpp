#include <iostream>
#include "Matrix.cpp"

int main()
{
    int linha;
    int coluna;
    cout<<"Entre com o número de linhas e colunas da matriz 1"<<endl;
    cin>>linha;
    cin>>coluna;
    cout<<endl;

    Matrix mat1(linha,coluna);
    preencherMatriz(mat1);
    printarMatriz(mat1);
    cout<<endl;

    printarMatriz(mat1);

    cout<<endl;

    cout<<"Entre com o número de linhas e colunas da matriz 2"<<endl;
    cin>>linha;
    cin>>coluna;
    cout<<endl;
    Matrix mat2(linha, coluna);
    mat2=mat1;
    printarMatriz(mat2);
    cout<<endl;

    Matrix mat3(mat2);
    printarMatriz(mat3);
    cout<<endl;

    Matrix mat4(mat2 + mat1);
    cout<<"Soma:";
    cout<<mat4<<endl;
    cout<<mat2<<endl;

    Matrix mat5(mat2 - mat1);
    cout<<"Subtracao:";
    cout<<mat5<<endl;

    Matrix mat6(mat2*mat1);
    cout<<"Multiplicacao:";
    cout<<mat6<<endl;


}
