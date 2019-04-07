//
// Created by Arina on 07/04/2019.
//

#include <iostream>
#include <time.h>
using namespace std;
#include "QuicksortPivoAleatorio.h"


void trocarElementos(int *elem1, int *elem2){
    int aux = *elem1;
    *elem1 = *elem2;
    *elem2 = aux;
}

void QuicksortPivoAleatorio::ImprimirVetor(int* vector, int tamanho){
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

void QuicksortPivoAleatorio::Quicksort(int *inicio, int *fim){

    srand (time(NULL));

    if(inicio == fim){
        exit;
    }

    int tamanho = (fim - inicio) + 1;
    int *pivo = inicio + (rand() % tamanho) ;

    pivo = partLomuto(inicio, fim, pivo);

    if(pivo > inicio){
        int *inicioEsq = inicio;
        int *fimEsq = pivo -1;
        Quicksort(inicioEsq, fimEsq);
    }

    if(pivo < fim){
        int *inicioDir = pivo + 1;
        int *fimDir = fim;
        Quicksort(inicioDir, fimDir);
    }
}


