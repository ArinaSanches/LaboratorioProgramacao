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

void partLomuto(int *inicio, int *fim, int *pivo, int *&pontM, int *&pontI){

    trocarElementos(inicio, pivo);

    int *m = inicio;
    int *i = inicio;
    int *j = inicio + 1;

    while(j != (fim + 1)){

        if(*j == *inicio){
            i = i + 1;
           trocarElementos(i, j);
        }
        if(*j < *inicio){
            i = i + 1;
            m = m + 1;

            int aux = *m;
            int aux2 = *i;
            if(j > i && i > m) {
                *m = *j;
                *i = aux;
                *j = aux2;
            }else { // evitar problema m == i ou i == j
                *m = *j;
                *j = aux;
            }
        }
        j = j + 1;
    }
    trocarElementos(m, inicio);

    pontI = m;
    pontM = i;

}


void Quicksort(int *inicio, int *fim, int *pivo){

    if(inicio == fim){
        exit;
    }

    int *pontM;
    int *pontI;

    partLomuto(inicio, fim, pivo, pontI, pontM);

    if(pontI > inicio){
        int *inicioEsq = inicio;
        int *fimEsq = pontI -1;
        Quicksort(inicioEsq, fimEsq, fimEsq);
    }

    if(pontM < fim){
        int *inicioDir = pontM + 1;
        int *fimDir = fim;
        Quicksort(inicioDir, fimDir, fimDir);
    }
}




int main() {

    //int vetor[] = {1, 2, 1, 3, 3, 2, 1, 3, 2, 4};

    int vetor[] = {1, 2, 2, 2, 1, 3, 3, 3, 2, 4};



    int * inicio = vetor;
    int * fim = vetor + 9;
    int * pivo = vetor + 8;

    int *init = inicio;

    cout << "Vetor Inicial: " << endl;

    ImprimirVetor(inicio, 10);

    cout << "Pivo: " << *pivo << endl;

    int* p;
    int*v;

    Quicksort(inicio, fim, pivo);

    cout << "Vetor depois do Quicksort: " << endl;
    ImprimirVetor(init, 10);

}



