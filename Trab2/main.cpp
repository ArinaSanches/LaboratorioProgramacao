#include <iostream>
using namespace std;

void imprimirInteiros(){
    int tam = 1, qtd = 0;
    int num = 0, controll = 0;
    double *vetor = new(nothrow)double[tam];
    do{
        if(tam > qtd) {
            cout << "Digite um numero";
            cin >> num;
            if (num >= 0) {
                *vetor = num;
                ++vetor;
                qtd++;
            }else{
                for(double *p = vetor - qtd; p != vetor; ++p){
                    cout << *p << endl;
                }
                controll = 1;
            }
        }else{
            int novoTam = tam * 2;
            double *vetorAux = new(nothrow)double[novoTam];

            for(double *k = vetor - qtd; k != vetor; ++k){
                vetorAux = k;
                ++vetorAux;
            }

            delete [] vetor;

            vetor = vetorAux;
            tam = novoTam;
        }
    }while(controll == 0);
}

int main() {


}





