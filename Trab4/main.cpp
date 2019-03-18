#include <iostream>
using namespace std;
#include<tuple> 

void trocarElementos(int *elem1, int *elem2){
    int aux = *elem1;
    *elem1 = *elem2;
    *elem2 = aux;
}

void ImprimirVetor(int* vector, int tamanho){
    cout << "{ ";
    for (int i = 0; i < tamanho ; ++i) {
        cout << vector[i] << " ";
    }
    cout << "}" << endl;
}

tuple<int*, int*> partLomuto(int *inicio, int *fim, int *pivo){

    trocarElementos(inicio, pivo);

    int *m = inicio;
    int *i = inicio;
    int *j = inicio + 1;
    int aux;
    while(j != (fim + 1)){

        if(*j == *inicio){
            i = i + 1;
           trocarElementos(i, j);
        }else if(*j < *inicio){
            m = m + 1;
            aux = *m;
            *m = *j;

            i = i + 1;
            *j = *i;
            *i = aux;
        }

        j = j + 1;
    }
    trocarElementos(m, inicio);

    return make_tuple(m, i);

}


void Quicksort(int *inicio, int *fim, int *pivo){

    if(inicio == fim){
        exit;
    }

    tuple <int*, int*> pivos = partLomuto(inicio, fim, pivo);
    

    if(get<0>(pivos) > inicio){

        int *inicioEsq = inicio;
        int *fimEsq = get<0>(pivos) -1;
        Quicksort(inicioEsq, fimEsq, fimEsq);
    }

    if(get<1>(pivos) < fim){

        int *inicioDir = get<1>(pivos) + 1;
        int *fimDir = fim;
        Quicksort(inicioDir, fimDir, fimDir);
    }
}




int main() {

    //int vetor[] = {1, 2, 1, 3, 3, 2, 1, 3, 2, 4};

    int vetor[] = {10, 2, 6, 8, 6 , 6, 3, 4, 6, 5};



    int * inicio = vetor;
    int * fim = vetor + 9;
    int * pivo = vetor + 8;

    int *init = inicio;

    cout << "Vetor Inicial: " << endl;

    ImprimirVetor(inicio, 10);

    cout << "Pivo: " << *pivo << endl;

    Quicksort(inicio, fim, pivo);

    cout << "Vetor depois do Quicksort: " << endl;
    ImprimirVetor(init, 10);

}



