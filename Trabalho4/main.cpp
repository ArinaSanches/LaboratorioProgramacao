#include <iostream>
#include "avl.hpp"
using namespace std;

void exibirArvore(Noh *raiz){

    if(raiz){
        cout << "|| " << raiz->chave << " h:" << raiz->h <<" ";
        if(raiz->pai) {
            cout << " pai: " << raiz->pai->chave << " ";
        }if(raiz->esq){
            cout << " filho esq: " << raiz->esq->chave << " ";
        }if(raiz->dir){
            cout << " filho dir: " << raiz->dir->chave << "    ";
        }
        exibirArvore(raiz->esq);
        exibirArvore(raiz->dir);
    }
}

int main() {

    DicAVL raiz;

    inicializar(raiz);

    Noh *no;
    Noh *noR5 = inserir(raiz, 204, -21);

//    cout << endl;
//    exibirArvore(raiz.raiz);
//
//    cout << endl;

    Noh *noR9 = inserir(raiz, 169.75, 59.5);

//    cout << endl;
//    exibirArvore(raiz.raiz);
//
//    cout << endl;

    Noh *noR0 = inserir(raiz, 246.75, -60);

//    cout << endl;
//    exibirArvore(raiz.raiz);
//
//    cout << endl;

    Noh *noR8 = inserir(raiz, -98.75, 53.5);

//    cout << endl;
//    exibirArvore(raiz.raiz);
//
//    cout << endl;

    Noh *noR7 = inserir(raiz, -133.25, 10.5);

//    cout << endl;
//    exibirArvore(raiz.raiz);
//
//    cout << endl;

    Noh *noR6 = inserir(raiz, -13.5, 25.5);

//    cout << endl;
//    exibirArvore(raiz.raiz);
//
//    cout << endl;

    Noh *noR2 = inserir(raiz, -81, 2.5);

//    cout << endl;
//    exibirArvore(raiz.raiz);
//
//    cout << endl;

    Noh *noR1 = inserir(raiz, 271.25, 83);

//    cout << endl;
//    exibirArvore(raiz.raiz);
//
//    cout << endl;

    remover(raiz, noR0);

    Noh *noP = procurar(raiz, 246.75);

    if(!noP){
        cout << endl << "ok" << endl;
    }

    remover(raiz, noR1);


    noP = procurar(raiz, 271.25);

    if(!noP){
        cout << endl << "ok" << endl;
    }

    remover(raiz, noR2);


    noP = procurar(raiz, -81);

    if(!noP){
        cout << endl << "ok" << endl;
    }

    cout << endl;

    Noh *noR4 = inserir(raiz, 182.5, -68.5);

//    cout << endl;
//    exibirArvore(raiz.raiz);
//
//    cout << endl;

    Noh *noR10 = inserir(raiz, -59.25, -74);

//    cout << endl;
//    exibirArvore(raiz.raiz);
//
//    cout << endl;

    Noh *noR3 = inserir(raiz, -234.5, 99.5);

//    cout << endl;
//    exibirArvore(raiz.raiz);
//
//    cout << endl;

    cout << endl;

    remover(raiz, noR3);

    remover(raiz, noR4);

    remover(raiz, noR5);

    remover(raiz, noR6);

    remover(raiz, noR7);

    remover(raiz, noR8);

    remover(raiz, noR9);

    cout << endl;
    exibirArvore(raiz.raiz);

    cout << endl;

    remover(raiz, noR10);

    cout << "saiu" << endl;

    Noh *p = procurar(raiz, -59.25);

    if(!p){
        cout << endl << "ok" << endl;
    }

    cout << endl;
    exibirArvore(raiz.raiz);

    exibirArvore(raiz.raiz);

    return 0;
}


/*
    DicAVL raiz;

    inicializar(raiz);

    cout << "inserindo 1" << endl;
    Noh *no = inserir(raiz, 1, 1);

    cout << "inserindo 2" << endl;
    no = inserir(raiz, 2, 2);

    cout << "inserindo 3" << endl;
    no = inserir(raiz, 3, 3);

    cout << "inserindo 4" << endl;
    no = inserir(raiz, 4, 4);

    cout << "inserindo 5" << endl;
    no = inserir(raiz, 5, 5);

    cout << "inserindo 6" << endl;
    no = inserir(raiz, 6, 6);

    cout << "inserindo 7" << endl;
    no = inserir(raiz, 7, 7);

    cout << "inserindo 8" << endl;
    no = inserir(raiz, 8, 8);

    cout << "inserindo 0" << endl;
    no = inserir(raiz, 0, 0);

    cout << "inserindo -1" << endl;
    no = inserir(raiz, -1, -1);

    cout << "inserindo -1" << endl;
    no = inserir(raiz, -2, -2);

    exibirArvore(raiz.raiz);

    Noh* noProcurado = procurar(raiz, -20);

    if(noProcurado){
        cout << endl << "No encontrado: " << noProcurado->chave << endl;
    }else{
        cout << endl <<"Chave nao enontrada!"<< endl;
    }
 */


/*
 DicAVL raiz;

    inicializar(raiz);

    cout << "inserindo 1" << endl;
    Noh *no = inserir(raiz, 3, 3);

    cout << "inserindo 2" << endl;
    no = inserir(raiz, 1, 1);

    cout << "inserindo 3" << endl;
    no = inserir(raiz, 2, 2);

    exibirArvore(raiz.raiz);
 */

/*DicAVL raiz;

    inicializar(raiz);

    cout << "inserindo 1" << endl;
    Noh *no = inserir(raiz, 1, 1);

    cout << "inserindo 2" << endl;
    no = inserir(raiz, 3, 3);

    cout << "inserindo 3" << endl;
    no = inserir(raiz, 2, 2);

    exibirArvore(raiz.raiz);
*/

/*
  DicAVL raiz;

    inicializar(raiz);


    cout << endl << "inserindo 1" << endl;
    Noh *noRemovido = inserir(raiz, 1, 1);

    cout << endl;

    exibirArvore(raiz.raiz);

    cout << endl;

    cout << endl << "inserindo 2" << endl;
    Noh *no = inserir(raiz, 2, 2);

    cout << endl;

    exibirArvore(raiz.raiz);

    cout << endl;

    cout << endl << "inserindo 3" << endl;
    no = inserir(raiz, 3, 3);

    cout << endl;

    exibirArvore(raiz.raiz);

    cout << endl;

    cout << endl<< "inserindo 4" << endl;
    no = inserir(raiz, 4, 4);

    cout << endl;

    exibirArvore(raiz.raiz);
    cout << endl;


    cout << endl << "inserindo 5" << endl;
    no = inserir(raiz, 5, 5);

    cout << endl;

    exibirArvore(raiz.raiz);
    cout << endl;


    cout << endl << "inserindo 6" << endl;
    no = inserir(raiz, 6, 6);

    cout << endl;

    exibirArvore(raiz.raiz);
    cout << endl;


    cout << endl << "inserindo 7" << endl;
    no = inserir(raiz, 7, 7);
    cout << endl;

    exibirArvore(raiz.raiz);
    cout << endl;


    cout << endl << "inserindo 8" << endl;
    no = inserir(raiz, 8, 8);

    cout << endl;

    exibirArvore(raiz.raiz);

    cout << endl;

    cout<< endl << "inserindo 0" << endl;
    no = inserir(raiz, 0, 0);

    cout << endl;

    exibirArvore(raiz.raiz);

    cout << endl;

    cout << endl<< "inserindo -1" << endl;
    no = inserir(raiz, -1, -1);

    cout << endl;

    exibirArvore(raiz.raiz);
    cout << endl;


    cout << endl<< "inserindo -2" << endl;
    no = inserir(raiz, -2, -2);

    cout << endl;

    exibirArvore(raiz.raiz);

    cout << endl;
    cout << endl;

    //cout << endl << noRemovido->chave << endl;

    remover(raiz, noRemovido);
    exibirArvore(raiz.raiz);
 */

/*
 DicAVL raiz;

    inicializar(raiz);


    cout << endl << "inserindo 1" << endl;
    Noh *noRemovido  = inserir(raiz, 1, 1);

    cout << endl;

    exibirArvore(raiz.raiz);

    cout << endl;

    cout << endl << "inserindo 2" << endl;
    Noh *no = inserir(raiz, 2, 2);

    cout << endl;

    exibirArvore(raiz.raiz);

    cout << endl;

    //cout << endl << noRemovido->chave << endl;

    remover(raiz, noRemovido);
    exibirArvore(raiz.raiz);
 */


/*DicAVL raiz;

    inicializar(raiz);


    cout << endl << "inserindo 1" << endl;
    Noh *noRemovido = inserir(raiz, 1, 1);

    cout << endl;

    exibirArvore(raiz.raiz);

    cout << endl;

    cout << endl << "inserindo 2" << endl;
    Noh *no = inserir(raiz, 2, 2);

    cout << endl;

    exibirArvore(raiz.raiz);

    cout << endl;

    cout << endl << "inserindo 3" << endl;
    no = inserir(raiz, 3, 3);

    cout << endl;

    exibirArvore(raiz.raiz);

    cout << endl;

    cout << endl<< "inserindo 4" << endl;
    no = inserir(raiz, 4, 4);

    cout << endl;

    exibirArvore(raiz.raiz);
    cout << endl;


    cout << endl << "inserindo 5" << endl;
    no = inserir(raiz, 5, 5);

    cout << endl;

    exibirArvore(raiz.raiz);
    cout << endl;


    cout << endl << "inserindo 6" << endl;
    no = inserir(raiz, 6, 6);

    cout << endl;

    exibirArvore(raiz.raiz);
    cout << endl;


    cout << endl << "inserindo 7" << endl;
    no = inserir(raiz, 7, 7);
    cout << endl;

    exibirArvore(raiz.raiz);
    cout << endl;


    cout << endl << "inserindo 8" << endl;
    no = inserir(raiz, 8, 8);

    cout << endl;

    exibirArvore(raiz.raiz);

    cout << endl;

    cout<< endl << "inserindo 0" << endl;
    no = inserir(raiz, 0, 0);

    cout << endl;

    exibirArvore(raiz.raiz);

    cout << endl;

    cout << endl<< "inserindo -1" << endl;
    no = inserir(raiz, -1, -1);

    cout << endl;

    exibirArvore(raiz.raiz);
    cout << endl;


    cout << endl<< "inserindo -2" << endl;
    no = inserir(raiz, -2, -2);

    cout << endl;
    exibirArvore(raiz.raiz);
    cout << endl;

    cout << endl<< "inserindo 9" << endl;
    no = inserir(raiz, 9, 9);

    cout << endl;
    exibirArvore(raiz.raiz);
    cout << endl;

    cout << endl<< "inserindo 10" << endl;
    no = inserir(raiz, 10, 10);

    cout << endl;
    exibirArvore(raiz.raiz);
    cout << endl;

    cout << endl<< "inserindo 8.1" << endl;
    no = inserir(raiz, 8.1, 8.1);
    cout << endl;
    exibirArvore(raiz.raiz);
    cout << endl;

    cout << endl<< "inserindo 11" << endl;
    no = inserir(raiz, 11, 11);

    cout << endl;

    exibirArvore(raiz.raiz);

    cout << endl;
    cout << endl;
*/

//teste caso 1 deleçao
/*
 * DicAVL raiz;

    inicializar(raiz);

    Noh *no = inserir(raiz, 1, 1);
    no = inserir(raiz, 2, 2);
    no = inserir(raiz, 3, 3);
    no = inserir(raiz, 4, 4);
    no = inserir(raiz, 5, 5);
    no = inserir(raiz, 6, 6);
    Noh *noRemovido4 = inserir(raiz, 7, 7);
    Noh *noRemovido2 = inserir(raiz, 8, 8);
    no = inserir(raiz, 0, 0);
    no = inserir(raiz, -1, -1);
    no = inserir(raiz, -2, -2);
    Noh *noRemovido5  = inserir(raiz, 9, 9);
    Noh *noRemovido3 = inserir(raiz, 10, 10);
    no = inserir(raiz, 8.1, 8.1);
    Noh *noRemovido1 = inserir(raiz, 11, 11);
    cout << endl;
    exibirArvore(raiz.raiz);

    cout << endl;
    cout << endl;

    cout << endl << "Removendo " << noRemovido1->chave << endl;

    remover(raiz, noRemovido1);
    exibirArvore(raiz.raiz);

    cout << endl;
    cout << endl;

    cout << endl << "Removendo " <<  noRemovido2->chave << endl;

    remover(raiz, noRemovido2);
    exibirArvore(raiz.raiz);

    cout << endl;
    cout << endl;

    cout << endl << "Removendo " <<  noRemovido3->chave << endl;

    remover(raiz, noRemovido3);
    exibirArvore(raiz.raiz);

    cout << endl;
    cout << endl;

    cout << endl << "Removendo " <<  noRemovido4->chave << endl;

    remover(raiz, noRemovido4);
    exibirArvore(raiz.raiz);

    cout << endl;
    cout << endl;

    cout << endl << "Removendo " <<  noRemovido5->chave << endl;

    remover(raiz, noRemovido5);
    exibirArvore(raiz.raiz);
 */


//teste caso 3 deleção
/*
 *   DicAVL raiz;

    inicializar(raiz);

    Noh *no = inserir(raiz, 1, 1);
    no = inserir(raiz, 2, 2);
    no = inserir(raiz, 3, 3);
    no = inserir(raiz, 4, 4);
    Noh *noRemovido2 = inserir(raiz, 5, 5);
    no = inserir(raiz, 6, 6);
    Noh *noRemovido1 = inserir(raiz, 7, 7);
    no = inserir(raiz, 8, 8);
    no = inserir(raiz, 0, 0);
    no = inserir(raiz, -1, -1);
    no = inserir(raiz, -2, -2);
    no  = inserir(raiz, 9, 9);
    no = inserir(raiz, 10, 10);
    no = inserir(raiz, 8.1, 8.1);
    no = inserir(raiz, 11, 11);
    cout << endl;
    exibirArvore(raiz.raiz);

    cout << endl;
    cout << endl;

    cout << endl << "Removendo " << noRemovido1->chave << endl;

    remover(raiz, noRemovido1);
    exibirArvore(raiz.raiz);

    cout << endl;
    cout << endl;

    cout << endl << "Removendo " <<  noRemovido2->chave << endl;

    remover(raiz, noRemovido2);
    exibirArvore(raiz.raiz);

    cout << endl;
    cout << endl;
 */

//caso 2
/*
 *  DicAVL raiz;

    inicializar(raiz);

    Noh *no = inserir(raiz, 1, 1);
    no = inserir(raiz, 2, 2);
    no = inserir(raiz, 3, 3);
    no = inserir(raiz, 4, 4);
    Noh *noRemovido4 = inserir(raiz, 5, 5);
    no = inserir(raiz, 6, 6);
    no = inserir(raiz, 7, 7);
    no = inserir(raiz, 8, 8);
    no = inserir(raiz, 0, 0);
    no = inserir(raiz, -1, -1);
    no = inserir(raiz, -2, -2);
    Noh *noRemovido5  = inserir(raiz, 9, 9);
    Noh *noRemovido2 = inserir(raiz, 10, 10);
    Noh *noRemovido3 = inserir(raiz, 8.1, 8.1);
    Noh *noRemovido1 = inserir(raiz, 11, 11);
    cout << endl;
    exibirArvore(raiz.raiz);

    cout << endl;
    cout << endl;

    cout << endl << "Removendo " << noRemovido1->chave << endl;

    remover(raiz, noRemovido1);
    exibirArvore(raiz.raiz);

    cout << endl;
    cout << endl;

    cout << endl << "Removendo " <<  noRemovido2->chave << endl;

    remover(raiz, noRemovido2);
    exibirArvore(raiz.raiz);

    cout << endl;
    cout << endl;

    cout << endl << "Removendo " <<  noRemovido3->chave << endl;

    remover(raiz, noRemovido3);
    exibirArvore(raiz.raiz);

    cout << endl;
    cout << endl;

    cout << endl << "Removendo " <<  noRemovido4->chave << endl;

    remover(raiz, noRemovido4);
    exibirArvore(raiz.raiz);

    cout << endl;
    cout << endl;

    cout << endl << "Removendo " <<  noRemovido5->chave << endl;

    remover(raiz, noRemovido5);
    exibirArvore(raiz.raiz);
 */

//CASO 4

/*
 *   DicAVL raiz;

    inicializar(raiz);

    Noh *no = inserir(raiz, 1, 1);
    no = inserir(raiz, 2, 2);
    no = inserir(raiz, 3, 3);
    no = inserir(raiz, 4, 4);
    Noh *noRemovido3 = inserir(raiz, 5, 5);
    Noh *noRemovido5 = inserir(raiz, 6, 6);
    Noh *noRemovido4 = inserir(raiz, 7, 7);
    no = inserir(raiz, 8, 8);
    no = inserir(raiz, 0, 0);
    no = inserir(raiz, -1, -1);
    no = inserir(raiz, -2, -2);
    no  = inserir(raiz, 9, 9);
    Noh *noRemovido2 = inserir(raiz, 10, 10);
    no = inserir(raiz, 8.1, 8.1);
    Noh *noRemovido1 = inserir(raiz, 11, 11);
    cout << endl;
    exibirArvore(raiz.raiz);

    cout << endl;
    cout << endl;

    cout << endl << "Removendo " << noRemovido1->chave << endl;

    remover(raiz, noRemovido1);
    exibirArvore(raiz.raiz);

    cout << endl;
    cout << endl;

    cout << endl << "Removendo " <<  noRemovido2->chave << endl;

    remover(raiz, noRemovido2);
    exibirArvore(raiz.raiz);

    cout << endl;
    cout << endl;

    cout << endl << "Removendo " <<  noRemovido3->chave << endl;

    remover(raiz, noRemovido3);
    exibirArvore(raiz.raiz);

    cout << endl;
    cout << endl;

    cout << endl << "Removendo " <<  noRemovido4->chave << endl;

    remover(raiz, noRemovido4);
    exibirArvore(raiz.raiz);

    cout << endl;
    cout << endl;

    cout << endl << "Removendo " <<  noRemovido5->chave << endl;

    remover(raiz, noRemovido5);
    exibirArvore(raiz.raiz);
 */


/* DicAVL raiz;

    inicializar(raiz);

    Noh *no;
    Noh *noR5 = inserir(raiz, 204, -21);

    cout << endl;
    exibirArvore(raiz.raiz);

    cout << endl;

    Noh *noR9 = inserir(raiz, 169.75, 59.5);

    cout << endl;
    exibirArvore(raiz.raiz);

    cout << endl;

    Noh *noR0 = inserir(raiz, 246.75, -60);

    cout << endl;
    exibirArvore(raiz.raiz);

    cout << endl;

    Noh *noR8 = inserir(raiz, -98.75, 53.5);

    cout << endl;
    exibirArvore(raiz.raiz);

    cout << endl;

    Noh *noR7 = inserir(raiz, -133.25, 10.5);

    cout << endl;
    exibirArvore(raiz.raiz);

    cout << endl;

    Noh *noR6 = inserir(raiz, -13.5, 25.5);

    cout << endl;
    exibirArvore(raiz.raiz);

    cout << endl;

    Noh *noR2 = inserir(raiz, -81, 2.5);

    cout << endl;
    exibirArvore(raiz.raiz);

    cout << endl;

    Noh *noR1 = inserir(raiz, 271.25, 83);

    cout << endl;
    exibirArvore(raiz.raiz);

    cout << endl;

    remover(raiz, noR0);

    Noh *noP = procurar(raiz, 246.75);

    if(!noP){
        cout << endl << "ok" << endl;
    }

    remover(raiz, noR1);


    noP = procurar(raiz, 271.25);

    if(!noP){
        cout << endl << "ok" << endl;
    }

    remover(raiz, noR2);


    noP = procurar(raiz, -81);

    if(!noP){
        cout << endl << "ok" << endl;
    }

    cout << endl;

    Noh *noR4 = inserir(raiz, 182.5, -68.5);

    cout << endl;
    exibirArvore(raiz.raiz);

    cout << endl;

    no = inserir(raiz, -59.25, -74);

    cout << endl;
    exibirArvore(raiz.raiz);

    cout << endl;

    Noh *noR3 = inserir(raiz, -234.5, 99.5);

    cout << endl;
    exibirArvore(raiz.raiz);

    cout << endl;

    cout << endl;


    remover(raiz, noR4);

    remover(raiz, noR5);

    remover(raiz, noR6);

    remover(raiz, noR7);

    remover(raiz, noR8);

    remover(raiz, noR9);

    cout << endl;
    exibirArvore(raiz.raiz);

    cout << endl;*/


/*
 *  DicAVL raiz;

    inicializar(raiz);

    Noh *no;
    Noh *noR5 = inserir(raiz, 160.75, -44);

    cout << endl;
    exibirArvore(raiz.raiz);

    Noh *noP = procurar(raiz, 160.75);

    if(noP){
        cout <<endl << noP->valor << endl;
    }
    cout << endl;


    Noh *noR9 = inserir(raiz, 32.25, -4.5);

    cout << endl;
    exibirArvore(raiz.raiz);

    noP = procurar(raiz, 32.25);

    if(noP){
        cout <<endl << noP->valor << endl;
    }
    cout << endl;
 */