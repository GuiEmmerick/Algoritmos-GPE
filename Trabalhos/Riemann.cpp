#include <iostream>
#include <vector>
#include <math.h>
#include <locale.h>
using namespace std;

double quadratica(double x, vector<double> parametros){
    return ((x*x*parametros[0]) + (parametros[1]*x) + parametros[2]);
}

double linear(double x, vector<double> parametros){
    return parametros[0]*x + parametros[1];
}


double Riemann(double (*func)(double, vector<double>), vector<double> parametros, double intervalo_a, double intervalo_b, int qtd_retangulos){
    double area=0;
    double incremento = fabs(intervalo_b-intervalo_a)/qtd_retangulos;
    if(intervalo_a < intervalo_b){
        for(double i=intervalo_a; i<=intervalo_b; i+=incremento){
        area += func(i, parametros)*incremento;

        }
        return area;
    }

    else{
        for(double i=intervalo_b; i<=intervalo_a; i+=incremento){
        area += func(i, parametros)*incremento;

        }
        return area;
    }


}

void digitaParametros(vector<double> &vec, double &intervalo_a, double &intervalo_b, int &retangulos ){
    int cont = 1;
    double param;

    cout<<"Entre com a quanditade de parametros desejados"<<endl;
    cin>>cont;
    cout<<endl;

    for(int i=0; i<cont;i++){
        cout<<"Parametro: "<<i+1<<endl;
        cin>>param;
        cout<<endl;
        vec.push_back(param);
    }

    cout<<"Entre com os intervalos desejados"<<endl;
    cin>>intervalo_b;;
    cin>>intervalo_a;

    cout<<"Entre com a quantidade de retangulos"<<endl;
    cin>>retangulos;;


}
int main()
{
    setlocale(LC_ALL, "Portuguese"); //acentuação em português
    double intervalo_a, intervalo_b;
    int retangulos, escolha;

    vector<double> vec;
    digitaParametros(vec, intervalo_a, intervalo_b, retangulos);
    cout<<"Escolha 1 para função quadrática -- 2 Para função linear"<<endl;
    cin>>escolha;
    switch (escolha){
        case 1:
            cout << "A área é de:"<<Riemann(quadratica, vec, intervalo_a, intervalo_b, retangulos) << endl;
            break;
        case 2:
            cout << "A área é de:"<<Riemann(linear, vec, intervalo_a, intervalo_b, retangulos) << endl;
            break;
    }

    return 0;
}
