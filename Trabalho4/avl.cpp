//
// Created by arinasanches on 27/06/19.
//

#include "avl.hpp"

void inicializar(DicAVL &D){
    D.raiz = nullptr;
    D.raiz->h = 1;
}

int calcularAltura(Noh *raiz){

    if(!raiz->dir->h){
        return raiz->esq->h + 1;
    }else if(raiz->esq->h > raiz->dir->h){
        return raiz->esq->h + 1;
    } else{
        return raiz->dir->h +1;
    }
}

Noh* rotacaoEsq(Noh *raiz){

    Noh* novaRaiz = raiz->dir;

    raiz->dir = novaRaiz->esq;
    novaRaiz->esq = raiz;

    raiz->h = calcularAltura(raiz);

    novaRaiz->h = calcularAltura(novaRaiz);

    return novaRaiz;
}



Noh* inserir(DicAVL &D, TC c, TV v){

}