//
// Created by Arina on 07/04/2019.
//

#include <iostream>
#include <time.h>
using namespace std;
#include "QuicksortPivoAleatorio.h"
#include "FuncoesBasicas.h"

FuncoesBasicas funcoes3;

void QuicksortPivoAleatorio::Quicksort(int *inicio, int *fim){

    srand (time(NULL));

    if(inicio == fim){
        exit;
    }

    int tamanho = (fim - inicio) + 1;
    int *pivo = inicio + (rand() % tamanho) ;

    pivo = funcoes3.partLomuto(inicio, fim, pivo);

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

