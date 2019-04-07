//
// Created by Arina on 07/04/2019.
//
/*
#include "QuicksortBFPRT.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
#include<tuple>

#include <iostream>
#include <stdlib.h>
using namespace std;
#include<tuple>


void trocarElementos(int *elem1, int *elem2){
    int aux = *elem1;
    *elem1 = *elem2;
    *elem2 = aux;
}

void QuicksortBFPRT::ImprimirVetor(int* vector, int tamanho){
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

tuple<int*, int*> partLomutoTriplo(int *inicio, int *fim, int *pivo){

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
void Imprimir(int* vector, int tamanho){
    cout << "{ ";
    for (int i = 0; i < tamanho ; ++i) {
        cout << vector[i] << " ";
    }
    cout << "}" << endl;
}

int* Bfprt(int *inicio, int *fim){

    int tamanho = (fim - inicio) + 1;

    if (tamanho < 6){
        int *pivo = inicio + (fim-inicio)/2;
        selecaoHoare(inicio, fim, pivo);
        return pivo;
    }

    int *i = inicio, *j = inicio + 4, *posMedInicio = inicio;
    int qtdPart5 = abs(tamanho / 5);
    int *ultimoI = inicio + (5 * qtdPart5) - 1;

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
        posMedInicio++;
    }

    Bfprt(inicio, (posMedInicio-1));
}

void AlgoritmoBfrt(int *inicio, int *fim, int *&pivo){

    int *p = Bfprt(inicio, fim);

    tuple <int*, int*> pivos = partLomutoTriplo(inicio, fim, p);

    if (pivo >= get<0>(pivos) || get<1>(pivos) >= pivo){
        pivo = get<0>(pivos);
        exit;
    }else if( pivo < get<0>(pivos)){
        int *fimEsq = get<0>(pivos) -1;
        AlgoritmoBfrt(inicio, fimEsq, pivo);
    }else if(pivo > get<1>(pivos)){
        int *inicioDir = get<1>(pivos) + 1;
        AlgoritmoBfrt(inicioDir, fim, pivo);
    }


}

void QuicksortBFPRT::Quicksort(int *inicio, int *fim){

    if(inicio == fim){
        exit;
    }

    int *pivo = inicio + (fim - inicio)/2;

    AlgoritmoBfrt(inicio, fim, pivo);

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

*/
