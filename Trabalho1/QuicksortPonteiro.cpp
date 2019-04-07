//
// Created by Arina on 07/04/2019.
//

#include <iostream>
using namespace std;
#include "QuicksortPonteiro.h"
#include "FuncoesBasicas.h"

FuncoesBasicas funcoes2;

void QuicksortPonteiro::Quicksort(int *inicio, int *fim, int *pivo){

    if(inicio == fim){
        exit;
    }

    pivo = funcoes2.partLomuto(inicio, fim, pivo);

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
