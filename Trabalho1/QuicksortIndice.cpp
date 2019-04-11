//
// Created by Arina on 07/04/2019.
//
#include <iostream>
using namespace std;
#include "QuicksortIndice.h"


void QuicksortIndice::ImprimirVetor(int vetor[], int tamanho){
    cout << "{ ";
    for (int i = 0; i < tamanho; ++i) {
        cout << vetor[i] << " ";
    }
    cout << "}" << endl;
    cout << endl << endl;
}

void trocarElementos(int vetor[],int i, int j){
    int aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}

int partLomuto(int vetor[], int inicio, int fim, int pivo){

    trocarElementos(vetor, inicio, pivo);

    int i = inicio;
    int j =  inicio + 1;

    while(j <= fim){
        if(vetor[j] < vetor[inicio]){
            i = i +1;
            trocarElementos(vetor, i, j);
        }
        j = j + 1;
    }
    trocarElementos(vetor, i, inicio);
    return i;
}

int escolherPivo (int primeiro, int ultimo){
    return (primeiro + ultimo)/2;
}

void QuicksortIndice::Quicksort(int vetor[], int inicio, int fim){

    if(inicio == (fim)){
        return;
    }

    int pivo = escolherPivo(inicio, fim);
    pivo = partLomuto(vetor, inicio, fim, pivo);

    int fimEsq;
    int inicioDir;

    if(pivo > inicio){
        fimEsq = pivo - 1;
        Quicksort(vetor, inicio, fimEsq);
    }

    if(pivo < (fim)){
        inicioDir = pivo + 1;
        Quicksort(vetor, inicioDir, (fim));
    }

}