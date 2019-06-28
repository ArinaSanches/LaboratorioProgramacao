#include <iostream>
#include "avl.hpp"
using namespace std;

void exibirArvore(Noh *raiz){

    if(raiz){
        cout << raiz->chave << " h:" << raiz->h << " ";
        exibirArvore(raiz->esq);
        exibirArvore(raiz->dir);
    }
}

int main() {

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
    
    return 0;
}

/*
 raiz.raiz = new Noh;

    raiz.raiz->chave = 1;
    raiz.raiz->esq = nullptr;
    raiz.raiz->h = 3;

    Noh *y = new Noh;
    Noh *z = new Noh;

    y->chave = 2;
    y->esq = nullptr;
    y->h = 2;

    z->chave = 3;
    z->esq = nullptr;
    z->h = 3;

    raiz.raiz->dir = y;

    y->dir = z;

    rotacaoEsq(raiz.raiz);
    exibirArvore(y);
 */

/*
 DicAVL raiz;

    inicializar(raiz);

    cout << "inserindo 1" << endl;
    Noh *no = inserir(raiz, 1, 1);

    exibirArvore(raiz.raiz);

    cout << endl;
    cout << "inserindo 2" << endl;

    no = inserir(raiz, 2, 2);

    exibirArvore(raiz.raiz);

    cout << endl;

    cout << "inserindo 3" << endl;

    no = inserir(raiz, 3, 3);

    exibirArvore(raiz.raiz);

    cout << endl;

    cout << "inserindo 4" << endl;

    no = inserir(raiz, 4, 4);

    exibirArvore(raiz.raiz);

    cout << endl;

    cout << "inserindo 5" << endl;


    no = inserir(raiz, 5, 5);

    exibirArvore(raiz.raiz);

    cout << endl;

    cout << "inserindo 6" << endl;

    no = inserir(raiz, 6, 6);

    exibirArvore(raiz.raiz);

    cout << endl;


    cout << "inserindo 7" << endl;

    no = inserir(raiz, 7, 7);

    exibirArvore(raiz.raiz);

    cout << endl;


    cout << "inserindo 8" << endl;

    no = inserir(raiz, 8, 8);

    exibirArvore(raiz.raiz);

    cout << endl;

    cout << "inserindo 0" << endl;

    no = inserir(raiz, 0, 0);

    exibirArvore(raiz.raiz);

    cout << endl;

    cout << "inserindo -1" << endl;

    no = inserir(raiz, -1, -1);

    exibirArvore(raiz.raiz);

    cout << endl;

    cout << "inserindo -1" << endl;

    no = inserir(raiz, -2, -2);

    exibirArvore(raiz.raiz);
 */


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