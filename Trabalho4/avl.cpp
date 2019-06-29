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

    if(novaRaiz->esq) {
        novaRaiz->esq->pai = raiz;
        cout << "AQUI  " << novaRaiz->esq->pai->chave << endl;
    }

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

    if(subDir){
        subDir->pai = raiz;
    }

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

        if(balanceamaento > 1 && no->esq->chave > c){
            cout << "subarvore esquerda maior, rot dir " << no->chave <<endl;
            Noh *paiNo = no->pai;
            no = rotacaoDir(no);
            if(!no->pai){
                D.raiz = no;
            }else{
                paiNo->esq = no;
            }
            return noInserido;
        }else if(balanceamaento < -1 && no->dir->chave < c){
            cout << "subarvore direita maior, rot esq, " << no->chave << endl;
            Noh *paiNo = no->pai;
            no = Esq(no);
            if(!no->pai){
                D.raiz = no;
            }else{
                paiNo->dir = no;
            }
            return noInserido;
        }else if(balanceamaento > 1 && no->esq->chave < c){
            Noh *paiNo = no;
            no->esq = Esq(no->esq);

            if(!no->esq->pai){
                D.raiz = no->esq;
            }else{
                paiNo->esq = no->esq;
            }

            paiNo = no->pai;
            no = rotacaoDir(no);
            if(!no->pai){
                D.raiz = no;
            }else{
                paiNo->esq = no;
            }
            return noInserido;
        }else if(balanceamaento < -1 && no->dir->chave > c){
            Noh *paiNo = no;
            no->dir = rotacaoDir(no->dir);

            if(!no->dir->pai){
                D.raiz = no->dir;
            }else{
                paiNo->dir = no->dir;
            }

            paiNo = no->pai;
            no = Esq(no);
            if(!no->pai){
                D.raiz = no;
            }else{
                paiNo->dir = no;
            }
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

void remover(DicAVL &D, Noh *no){

    bool inserir = false;

    Noh *raiz = D.raiz;


    int pai = 0;

    while(!inserir){
        if(raiz->chave > no->chave){
            pai = 0;
            raiz = raiz->esq;
        }else if(raiz->chave < no->chave){
            pai = 1;
            raiz = raiz->dir;
        }else{
            inserir = true;
        }
    }

    if(!raiz->esq || !raiz->dir){

        if(raiz->esq){
            if(raiz->pai->esq == raiz){
                raiz->pai->esq = raiz->esq;
            }else{
                raiz->pai->dir = raiz->esq;
            }
        }else if(raiz->dir){
            if(raiz->pai->dir == raiz){
                raiz->pai->dir = raiz->dir;
            }else{
                raiz->pai->esq = raiz->dir;
            }
        }else{
            if(raiz->pai->dir == raiz){
                raiz->pai->dir = nullptr;
            }else{
                raiz->pai->esq = nullptr;
            }
        }
        raiz = nullptr;
        free(raiz);
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