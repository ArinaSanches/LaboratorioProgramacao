#include <iostream>
#include "avl.hpp"
using namespace std;

void exibirArvore(Noh *raiz){

    if(raiz){
        cout << "|| " << raiz->chave << /*<< " h:" << raiz->h <<*/ " ";
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