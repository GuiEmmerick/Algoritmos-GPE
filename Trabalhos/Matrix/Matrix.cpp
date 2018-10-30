#include "Matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix(int linha, int coluna){ // construtor normal
        this->linha = linha;
        this->coluna = coluna;

        allocate(linha, coluna);
}

Matrix::~Matrix(){ //destrutor

        deallocate();
}

Matrix::Matrix(const Matrix& objeto_a_copiar){ // construtor por cópia
        cout<<"Construtor por cópia"<<endl;
        linha = objeto_a_copiar.linha;
        coluna = objeto_a_copiar.coluna;

        allocate(linha, coluna);
         for(unsigned i=0; i< linha; i++){
            for(unsigned j=0; j< coluna; j++){
               matrix[i][j] = objeto_a_copiar.matrix[i][j];
            }
        }


}
void Matrix::preencher_zero(){
    for(int i=0; i<linha; i++){
        for(int j=0; j<coluna; j++){
            matrix[i][j]=0;
        }
    }
}

Matrix Matrix::operator*(Matrix &mat){
    int l = mat.linha;
    int c = mat.coluna;

    int l2 = linha;
    int c2 = coluna;

    if(c!= l2){
        throw invalid_argument("Numero de linhas e colunas diferentes");
    }

    else{
         Matrix aux (l,c);
         aux.preencher_zero();


    for(int i = 0; i < l; i++){
        for(int j = 0; j < c2; j++){
            for(int k = 0; k < c; k++){
                aux.matrix[i][j] += matrix[i][k] * mat.matrix[k][j];
            }
        }
    }

    return aux;


    }



}


Matrix Matrix::operator+(Matrix &mat){
    int l = mat.linha;
    int c = mat.coluna;

    Matrix aux (l,c);

    if(linha != this->linha || coluna != this->coluna){
        throw invalid_argument("Matrizes de dimensoes diferentes");
    }
    else{

        for(int i=0; i<mat.linha; i++){
            for(int j=0; j<mat.coluna; j++){
                aux.matrix[i][j]= matrix[i][j]+mat[i][j];
            }
        }
    }
    return aux;

}

Matrix Matrix::operator-(Matrix &mat){
    int l = mat.linha;
    int c = mat.coluna;

    Matrix aux (l,c);

    if(linha != this->linha || coluna != this->coluna){
        throw invalid_argument("Matrizes de dimensoes diferentes");
    }
    else{

        for(int i=0; i<mat.linha; i++){
            for(int j=0; j<mat.coluna; j++){
                aux.matrix[i][j]= matrix[i][j]-mat[i][j];
            }
        }
    }

    return aux;

}

int *Matrix::operator[](int l){
        return matrix[l];
}

Matrix &Matrix::operator = (const Matrix &objeto_a_copiar){ // operador assignment
        cout<<"Operador assignmet"<<endl;
        int l = objeto_a_copiar.linha;
        int c = objeto_a_copiar.coluna;

        deallocate();
        allocate(l, c);


        for(unsigned i=0; i< l; i++){
            for(unsigned j=0; j< c; j++){
               matrix[i][j] = objeto_a_copiar.matrix[i][j];
            }
        }
        this->linha = l;
        this->coluna = c;
        return *this;
}

ostream& operator<<(ostream &io,Matrix &matrix){
    for(int i = 0; i < matrix.getLinha(); i++){
        for(int j = 0; j < matrix.getColuna(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;;
    }
    return io;
}

void Matrix::allocate(int linha, int coluna){
      matrix = new int*[linha];
      for(unsigned i=0;i<linha;i++){
        matrix[i]=new int[coluna];
      }
      cout<<"Matriz alocada"<<endl;

    }

void Matrix::deallocate(){
      for(unsigned i=0;i<linha;i++){
        delete[] matrix[i];
      }
      delete[] matrix;
      cout<<"Matriz desalocada com sucesso!"<<endl;
    }
int Matrix::getLinha(){
    return linha;
}
int Matrix::getColuna(){
    return coluna;
}

    void preencherMatriz(Matrix &mat){
        int l = mat.getLinha();
        int c = mat.getColuna();
        for(int i=0; i < l; i++){
            for(int j=0; j < c; j++){
                mat[i][j] =1;
            }
        }
    }


    void printarMatriz(Matrix &mat){
        int l = mat.getLinha();
        int c = mat.getColuna();
        for(int i=0; i < l; i++){
            for(int j=0; j < c; j++){
                cout<<mat[i][j] << " ";
            }
            cout<<endl;
        }
    }

