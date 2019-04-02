#include <iostream>
#include <stdlib.h>
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

void selecaoHoare(int *inicio, int *fim, int *i){

    int *pivo = inicio + (fim - inicio)/2 ;
    int *p = partLomuto(inicio, fim, pivo);

    if(p == i){
        exit;
    }else if(i < p){
        selecaoHoare(inicio, p - 1, i);
    }else{
        selecaoHoare(p+1, fim, i);
    }
}

int* Bfprt(int *inicio, int *fim){

    int tamanho = (fim - inicio) + 1;

    if (tamanho < 6){
        int *pivo = fim + (inicio - fim)/2;
        selecaoHoare(inicio, fim, pivo);
        return pivo;
    }

    int *i = inicio, *j = inicio + 4, *posMedInicio = inicio;
    int qtdPart5 = abs(tamanho / 5);
    int *ultimoI = inicio + (5 * qtdPart5);

    for(i = inicio; i < ultimoI; i = i + 5){
        int *pivo = i + 2;
        selecaoHoare(i, j, pivo);
        trocarElementos(pivo, posMedInicio);
        posMedInicio++;
        j = j + 5;
    }

    if(tamanho % 5 != 0){
        j = fim;
        int *pivo = ultimoI + (j - ultimoI)/2;
        selecaoHoare(ultimoI, j, pivo);
        trocarElementos(pivo, posMedInicio);
    }

    int *posUltMed = inicio + qtdPart5;
    Bfprt(inicio, posUltMed);
}


int main() {
    //    int vetor[] = {1, 2, 5, 2, 4, 20, 1, 3, 6, 5, 5, 4, 1, 2}; problema se pivo for o mais a esqueda
    int vetor[] = {1, 2, 5, 2, 4, 20, 1, 3, 6, 5, 5};

    int * inicio = vetor;
    int * fim = vetor + 10;

    int *init = inicio;

    cout << "Vetor Inicial: " << endl;

    ImprimirVetor(inicio, 11);

    int *i = Bfprt(inicio, fim);

    cout << *i << endl;


}