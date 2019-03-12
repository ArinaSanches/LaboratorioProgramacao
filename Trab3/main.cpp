#include <iostream>
using namespace std;

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

int* partLomuto(int *inicio, int *fim, int *pivo){

    trocarElementos(inicio, pivo);

    int *i = inicio;
    int *j = i + 1;

    while(j != (fim + 1)){
        if(*j < *inicio){
            i = i +1;
            trocarElementos(i, j);
        }
        j = j + 1;
    }
    trocarElementos(i, inicio);
    return i;
}



void Quicksort(int *inicio, int *fim, int *pivo){

    if(inicio == fim){
        exit;
    }

    pivo = partLomuto(inicio, fim, pivo);

    if(pivo > inicio){
        int *inicioEsq = inicio;
        int *fimEsq = pivo -1;
        Quicksort(inicioEsq, fimEsq, fimEsq);
    }

    if(pivo < fim){
        int *inicioDir = pivo + 1;
        int *fimDir = fim;
        Quicksort(inicioDir, fimDir, fimDir);
    }
}


int main() {

    int vetor[] = {10, 2 , 9, 8 , 8 , 6, 3 , 4, 1 , 5};

    int * inicio = vetor;
    int * fim = vetor + 9;
    int * pivo = vetor + 5;

    int *init = inicio;

    cout << "Vetor Inicial: " << endl;

    ImprimirVetor(inicio, 10);

    Quicksort(inicio, fim, pivo);

    cout << "Vetor depois do Quicksort: " << endl;
    ImprimirVetor(init, 10);

}



