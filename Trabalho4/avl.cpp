//
// Created by arinasanches on 27/06/19.
//
#include <iostream>

#include "avl.hpp"

using namespace std;

void inicializar(DicAVL &D){
    D.raiz = nullptr;
}

int calcularAltura(Noh *raiz){

    if(!raiz->dir) {
      if(!raiz->esq){
        return 1;
      }else{
          return raiz->esq->h + 1;
      }
    }else if(!raiz->esq) {
        if(!raiz->dir){
            return 1;
        }else{
            return raiz->dir->h + 1;
        }
    }else if(raiz->esq->h > raiz->dir->h){
        return raiz->esq->h + 1;
    } else{
        return raiz->dir->h +1;
    }
}

Noh * Esq(Noh *raiz){

    Noh* novaRaiz = raiz->dir;
    Noh* paiRaiz = raiz->pai;

    raiz->dir = novaRaiz->esq;

    novaRaiz->esq = raiz;

    raiz->h = calcularAltura(raiz);

    raiz->pai = novaRaiz;

    novaRaiz->h = calcularAltura(novaRaiz);

    novaRaiz->pai = paiRaiz;

    return novaRaiz;
}

Noh * rotacaoDir(Noh *raiz){

    Noh* subDir = raiz->esq->dir;
    Noh* novaRaiz = raiz->esq;
    Noh* paiRaiz = raiz->pai;

    raiz->esq = subDir;

    novaRaiz->dir = raiz;

    raiz->h = calcularAltura(raiz);

    raiz->pai = novaRaiz;

    novaRaiz->h = calcularAltura(novaRaiz);

    novaRaiz->pai = paiRaiz;

    return novaRaiz;
}

Noh* novoNoh(TC c, TV v, Noh *pai){
    Noh *no = new Noh;
    no->esq = nullptr;
    no->dir = nullptr;
    no->pai = pai;
    no->chave = c;
    no->valor = v;
    no->h = 1;
    return no;
}

int altura(Noh *no){
    if(!no){
        return 0;
    }
    return no->h;
}

int calcularDesbanciamento(Noh *no){
    if(!no){
        return 0;
    }

    return altura(no->esq) - altura(no->dir);
}

Noh* inserir(DicAVL &D, TC c, TV v){

    if(!D.raiz){
        D.raiz = novoNoh(c, v, nullptr);
        return D.raiz;
    }

    bool inserir = false;
    Noh *no = D.raiz;

    Noh *noInserido;

    while(!inserir){
        if(no->chave > c){
            if(!no->esq){
                noInserido = novoNoh(c, v, no);
                no->esq = noInserido;
                inserir = true;
            }else {
                no = no->esq;
            }
        }else if(no->chave < c){
            if(!no->dir){
                noInserido = novoNoh(c, v, no);
                no->dir = noInserido;
                inserir = true;
            }else {
                no = no->dir;
            }
        }else{
            return nullptr;
        }
    }


    /*no->h = calcularAltura(no);
    if(no->pai) {
        no->pai->h = calcularAltura(no->pai);
    }*/

    bool balancea = false;
    while(!balancea){
        no->h = calcularAltura(no);
        int balanceamaento = calcularDesbanciamento(no);

        if(balanceamaento > 1 && no->chave > c){
            cout << "subarvore esquerda maior, rot dir " << no->chave <<endl;
            Noh *paiNo = no->pai;
            no = rotacaoDir(no);
            if(!no->pai){
                D.raiz = no;
            }else{
                paiNo->esq = no;
            }
            return noInserido;
        }else if(balanceamaento < -1 && no->chave < c){
            cout << "subarvore direita maior, rot esq, " << no->chave << endl;
            Noh *paiNo = no->pai;
            no = Esq(no);
            if(!no->pai){
                D.raiz = no;
            }else{
                paiNo->dir = no;
            }
            return noInserido;
        }
        if(!no->pai){
            return noInserido;
        }else{
            no = no->pai;
        }
    }
}

Noh* procurar (DicAVL &D, TC c){

    bool inserir = false;

    Noh *no = D.raiz;

    while(!inserir){
        if(no->chave > c){
            if(!no->esq){
                return nullptr;
            }else {
                no = no->esq;
            }
        }else if(no->chave < c){
            if(!no->dir){
                return nullptr;
            }else {
                no = no->dir;
            }
        }else{
            return no;
        }
    }
}


/*
 Noh *raiz = D.raiz;
    bool balancea = false, ehraiz = true;
    while(!balancea){
        int balanceamaento = calcularDesbanciamento(raiz);

        if(balanceamaento > 1 && raiz->chave > c){
            cout << "subarvore esquerda maior, rot dir" << endl;
            raiz = rotacaoDir(raiz);
            if(ehraiz){
                D.raiz = raiz;
            }
            return raiz;
        }else if(balanceamaento < -1 && raiz->chave < c){
            cout << "subarvore direita maior, rot esq, " << raiz->chave << endl;
            raiz = Esq(raiz);
            if(ehraiz){
                D.raiz = raiz;
            }
            return raiz;
        }
        if(raiz->chave > c){
            raiz = raiz->esq;
        }else if(raiz->chave < c){
            raiz = raiz->dir;
        }else{
            balancea = true;
        }
    }
 */