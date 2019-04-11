//
// Created by Arina on 07/04/2019.
//

#include "QuicksortBFPRT.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
#include<tuple>

#include <iostream>
#include <stdlib.h>
using namespace std;
#include<tuple>

#include "FuncoesBasicas.h"

FuncoesBasicas funcoes;


void Bfprt(int *inicio, int *fim, int*pivoInicial){

    int tamanho = (fim - inicio) + 1;

    if (tamanho < 6){
        funcoes.selecaoHoare(inicio, fim, pivoInicial);
        return;
    }

    int *i = inicio, *j = inicio + 4, *posMedInicio = inicio;
    int qtdPart5 = abs(tamanho / 5);
    int *ultimoI = inicio + (5 * qtdPart5) - 1;

    for(i = inicio; i < ultimoI; i = i + 5){
        int *pivo = i + 2;
        funcoes.selecaoHoare(i, j, pivo);
        funcoes.trocarElementos(pivo, posMedInicio);
        posMedInicio++;
        j = j + 5;
    }

    if(tamanho % 5 != 0){
        j = fim;
        int *pivo = ultimoI + (j - ultimoI)/2;
        funcoes.selecaoHoare(ultimoI, j, pivo);
        funcoes.trocarElementos(pivo, posMedInicio);
        posMedInicio++;
    }

    int *pivo = inicio + ((posMedInicio-1)-inicio)/2;
    Bfprt(inicio, (posMedInicio-1), pivo);

    tuple <int*, int*> pivos = funcoes.partLomutoTriplo(inicio, fim, pivo);

    if (pivoInicial >= get<0>(pivos) && get<1>(pivos) >= pivoInicial){
        pivoInicial = get<0>(pivos);
        return;
    }else if( pivoInicial < get<0>(pivos)){
        int *fimEsq = get<0>(pivos) -1;
        Bfprt(inicio, fimEsq, pivoInicial);
    }else if(pivoInicial > get<1>(pivos)){
        int *inicioDir = get<1>(pivos) + 1;
        Bfprt(inicioDir, fim, pivoInicial);
    }
}


void QuicksortBFPRT::Quicksort(int *inicio, int *fim){

    if(inicio == fim){
        exit;
    }

    int *pivo = funcoes.escolherPivo(inicio, fim);

    Bfprt(inicio, fim, pivo);

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


