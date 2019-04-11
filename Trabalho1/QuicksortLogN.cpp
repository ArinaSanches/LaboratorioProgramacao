//
// Created by Arina on 10/04/2019.
//

#include "QuicksortLogN.h"
#include <iostream>
using namespace std;
#include "FuncoesBasicas.h"

FuncoesBasicas funcoes5;

void QuicksortLogN::Quicksort(int *inicio, int *fim){
    while (inicio < fim) {

        int* pivo = funcoes5.escolherPivo(inicio, fim);
        pivo = funcoes5.partLomuto(inicio, fim, pivo);
        int tamanhoEsq = pivo - inicio;
        int tamanhoDir = fim - pivo;
        if( tamanhoEsq < tamanhoDir){
            if(pivo > inicio){
                int *fimEsq = pivo -1;
                Quicksort(inicio, fimEsq);
            }
            inicio = pivo + 1;
        }else{
            if(pivo < fim){
                int *inicioDir = pivo + 1;
                Quicksort(inicioDir, fim);
            }
            fim = pivo - 1;
        }

    }
}
