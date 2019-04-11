#include <iostream>
using namespace std;
#include "QuicksortPonteiro.h"
#include "FuncoesBasicas.h"

FuncoesBasicas funcoes2;

void QuicksortPonteiro::Quicksort(int *inicio, int *fim){

    if(inicio == fim){
        exit;
    }

    int *pivo = funcoes2.escolherPivo(inicio, fim);
    pivo = funcoes2.partLomuto(inicio, fim, pivo);

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