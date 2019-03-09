#include <iostream>
using namespace std;

void trocarElementos(int *elem1, int *elem2){
    int aux = *elem1;
    *elem1 = *elem2;
    *elem2 = aux;
}


void partLomuto(int *inicio, int *fim, int *pivo){

    trocarElementos(inicio, pivo);

    int *i = inicio;
    int *j = i + 1;

    while(j != fim){
        if(*j < *inicio){
            i = i +1;
            trocarElementos(i, j);
        }
        j = j + 1;
    }

    trocarElementos(i, inicio);
}



int main() {

    int vetor[] = {3, 2 , 10, 4 , 5 , 6, 9 , 1, 7 , 7};

    int * inicio = vetor;
    int * fim = vetor + 10;
    int * pivo = vetor + 3;

    cout << "Pivo: " << *pivo << endl;

    partLomuto(inicio, fim, pivo);

    cout << "{ ";
    for(int i = 0; i < 10; i++){
        cout << vetor[i] << "  " ;
    }
    cout << "}";

}



