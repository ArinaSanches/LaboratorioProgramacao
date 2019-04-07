//
// Created by Arina on 07/04/2019.
//

#include "FuncoesBasicas.h"
#include <iostream>
#include<tuple>
using namespace std;


void FuncoesBasicas::trocarElementos(int *elem1, int *elem2){
    int aux = *elem1;
    *elem1 = *elem2;
    *elem2 = aux;
}

void FuncoesBasicas::ImprimirVetor(int* vector, int tamanho){
    cout << "{ ";
    for (int i = 0; i < tamanho ; ++i) {
        cout << vector[i] << " ";
    }
    cout << "}" << endl;
    cout << endl << endl;
}

int* FuncoesBasicas::partLomuto(int *inicio, int *fim, int *pivo){

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

void FuncoesBasicas::selecaoHoare(int *inicio, int *fim, int *i){

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

tuple<int*, int*> FuncoesBasicas:: partLomutoTriplo(int *inicio, int *fim, int *pivo){

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
            i = i +1;
            trocarElementos(i, j);
            m = m + 1;
            trocarElementos(m, i);
        }

        j = j + 1;
    }
    trocarElementos(m, inicio);

    return make_tuple(m, i);

}

void FuncoesBasicas:: copiarVetor(int vetor1[], int vetor2[], int tamanho){
    for (int i = 0; i < tamanho; i++){
        vetor2[i] = vetor1[i];
    }
}
