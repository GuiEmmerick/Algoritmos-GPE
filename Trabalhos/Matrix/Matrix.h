#include <iostream>
#ifndef Matrix_h
#define Matrix_h

class Matrix{
protected:
    void allocate(int linha, int coluna);
    void deallocate();
    


public:
    Matrix(int linha, int coluna);
    ~Matrix();
    Matrix(const Matrix& objeto_a_copiar);
    int *operator[](int l);
    Matrix& operator = (const Matrix &objeto_a_copiar);
    Matrix operator+(Matrix &matrix);
    Matrix operator-(Matrix &matrix);
    Matrix operator*(Matrix &matrix);


    void preencher_zero();
    int getLinha();
    int getColuna();

private:
    int **matrix;
    int linha;
    int coluna;
};
#endif // Matriz_h
