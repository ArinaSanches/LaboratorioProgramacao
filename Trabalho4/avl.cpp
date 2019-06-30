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
            cout << "subarvore esquerda maior, rot dir, caso 1 " << no->chave <<endl;
            Noh *paiNo = no->pai;
            no = rotacaoDir(no);
            if(!no->pai){
                D.raiz = no;
            }else{
                paiNo->esq = no;
            }
            //return noInserido;
        }else if(balanceamaento < -1 && no->dir->chave < c){
            cout << "subarvore direita maior, rot esq, caso 2 " << no->chave << endl;
            Noh *paiNo = no->pai;
            no = Esq(no);
            if(!no->pai){
                D.raiz = no;
            }else{
                paiNo->dir = no;
            }
            //return noInserido;
        }else if(balanceamaento > 1 && no->esq->chave < c){
            Noh *paiNo = no;
            cout << "subarvore esquerda maior, rot esq, caso 3 " << no->chave << endl;
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
            //return noInserido;
        }else if(balanceamaento < -1 && no->dir->chave > c){
            cout << "subarvore direita maior, rot esq, caso 4 " << no->chave << endl;
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
            //return noInserido;
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

Noh* minimoDireito(Noh *no){
    Noh *minimo = no;
    while(minimo->esq){
        minimo = minimo->esq;
    }
    return minimo;
}

void remover(DicAVL &D, Noh *no){

    bool inserir = false;

    Noh *raiz = D.raiz;

    while(!inserir){

        if(raiz->chave > no->chave){
            raiz = raiz->esq;
        }else if(raiz->chave < no->chave){
            raiz = raiz->dir;
        }else{
            inserir = true;
        }
    }

    Noh *noDel;
    if(!raiz->esq || !raiz->dir){
        //caso tenha apenas filho esquerdo
        if(raiz->esq){
            if(raiz->pai) {
                if (raiz->pai->esq == raiz) {
                    raiz->pai->esq = raiz->esq;
                } else {
                    raiz->pai->dir = raiz->esq;
                }
                noDel = raiz->pai;
                raiz->esq->pai = raiz->pai;
            }else{
                raiz->esq->pai = nullptr;
                noDel = raiz->esq;
                D.raiz = raiz->esq;
            }
        }else if(raiz->dir){
            if(raiz->pai) {
                if (raiz->pai->dir == raiz) {
                    raiz->pai->dir = raiz->dir;
                } else {
                    raiz->pai->esq = raiz->dir;
                }
                noDel = raiz->pai;
                raiz->dir->pai = raiz->pai;
            }else{
                raiz->dir->pai = nullptr;
                noDel = raiz->dir;
                D.raiz = raiz->dir;
            }
        }else{
            if(raiz->pai) {
                if (raiz->pai->dir == raiz) {
                    raiz->pai->dir = nullptr;
                } else {
                    raiz->pai->esq = nullptr;
                }
                noDel= raiz->pai;
            }else{
                if(!noDel->esq && !noDel->dir) {
                    noDel = nullptr;
                    D.raiz = nullptr;
                }else{
                    noDel = raiz;
                }
            }
        }
        raiz = nullptr;
        free(raiz);
    }else{
        Noh *minimoDir = minimoDireito(raiz->dir);

        if(minimoDir->pai && minimoDir->pai != raiz) {
            noDel = minimoDir->pai;
        }else{
            noDel = minimoDir;
        }
        if(raiz->pai) {
            if (raiz->pai->dir == raiz) {
                raiz->pai->dir = minimoDir;
            } else {
                raiz->pai->esq = minimoDir;
            }
            if(minimoDir != raiz->dir) {
                minimoDir->pai->esq = nullptr;
            }
            minimoDir->pai = raiz->pai;

        }else{
            if(minimoDir!= raiz->dir) {
                minimoDir->pai->esq = nullptr;
            }
            minimoDir->pai = nullptr;
            D.raiz = minimoDir;
        }

        if(raiz->dir != minimoDir) {
            raiz->dir->pai = minimoDir;
            minimoDir->dir = raiz->dir;
        }
        raiz->esq->pai = minimoDir;
        minimoDir->esq = raiz->esq;
        raiz = nullptr;
        free(raiz);
    }

    bool balancea = false;


    if(!noDel){
        balancea = true;
    }

    while(!balancea){

        noDel->h = calcularAltura(noDel);

        int balanceamaento = calcularDesbanciamento(noDel);

        if(balanceamaento > 1 && calcularDesbanciamento(noDel->esq) >= 0){
            cout << "subarvore direita maior, rot esq, caso 1 " << noDel->chave << endl;
            Noh *paiNo = noDel->pai;
            noDel = rotacaoDir(noDel);
            if(!noDel->pai){
                D.raiz = noDel;
            }else{
                if(paiNo->esq == noDel)
                    paiNo->esq = noDel;
                else
                    paiNo->dir = noDel;
            }

        }else if(balanceamaento > 1 && calcularDesbanciamento(noDel->esq) < 0){
            cout << "subarvore esquerda maior, rot esq, caso 2 " << noDel->chave << endl;
            Noh *paiNo = noDel->pai;
            noDel->esq = Esq(noDel->esq);

            if(!noDel->esq->pai){
                D.raiz = noDel->esq;
            }else{
                if(paiNo->esq == noDel)
                    paiNo->esq = noDel;
                else
                    paiNo->dir = noDel;
            }

            paiNo = noDel->pai;
            noDel = rotacaoDir(noDel);
            if(!noDel->pai){
                D.raiz = noDel;
            }else{
                if(paiNo->esq == noDel)
                    paiNo->esq = noDel;
                else
                    paiNo->dir = noDel;
            }
        }else if(balanceamaento < -1 && calcularDesbanciamento(noDel->dir) <= 0){
            cout << "subarvore direita maior, rot esq, caso 3 " << noDel->chave << endl;
            Noh *paiNo = noDel->pai;
            noDel = Esq(noDel);
            if(!noDel->pai){
                D.raiz = noDel;
            }else{
                if(paiNo->esq == noDel)
                    paiNo->esq = noDel;
                else
                    paiNo->dir = noDel;
            }

        }else if(balanceamaento < -1 && calcularDesbanciamento(noDel->dir) > 0){
            cout << "subarvore direita maior, rot esq, caso 4 " << noDel->chave << endl;
            Noh *paiNo = noDel->pai;
            noDel->dir = rotacaoDir(noDel->dir);

            if(!noDel->dir->pai){
                D.raiz = noDel->dir;
            }else{
                paiNo->dir = noDel->dir;
            }

            paiNo = noDel->pai;
            noDel = Esq(noDel);
            if(!noDel->pai){
                D.raiz = noDel;
            }else{
                if(paiNo->esq == noDel)
                    paiNo->esq = noDel;
                else
                    paiNo->dir = noDel;
            }

        }
        if(!noDel->pai){
            noDel->h = calcularAltura(noDel);
            D.raiz = noDel;
            balancea = true;
        }else{
            noDel = noDel->pai;
        }
    }
}


