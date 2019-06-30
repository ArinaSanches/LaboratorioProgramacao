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

    cout << "inserindo 1" << endl;
    Noh *no = inserir(raiz, 1, 1);
    cout << endl;
    exibirArvore(raiz.raiz);

    cout << endl;
    cout << endl;
    cout << "inserindo 2" << endl;

    no = inserir(raiz, 2, 2);

    cout << endl;
    cout << endl;
    exibirArvore(raiz.raiz);
    cout << endl;
    cout << endl;
    cout << "inserindo 3" << endl;

    no = inserir(raiz, 3, 3);

    cout << endl;
    cout << endl;
    exibirArvore(raiz.raiz);
    cout << endl;
    cout << endl;
    cout << "inserindo 4" << endl;

    no = inserir(raiz, 4, 4);
    cout << endl;
    exibirArvore(raiz.raiz);
    cout << endl;
    cout << endl;
    cout << "inserindo 5" << endl;

    Noh *noRemovido3 = inserir(raiz, 5, 5);
    cout << endl;
    exibirArvore(raiz.raiz);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "inserindo 6" << endl;

    Noh *noRemovido5 = inserir(raiz, 6, 6);
    cout << endl;
    exibirArvore(raiz.raiz);

    cout << endl;
    cout << endl;
    cout << "inserindo 7" << endl;

    Noh *noRemovido4 = inserir(raiz, 7, 7);
    cout << endl;
    exibirArvore(raiz.raiz);

    cout << endl;
    cout << "inserindo 8" << endl;

    no = inserir(raiz, 8, 8);
    cout << endl;
    exibirArvore(raiz.raiz);
    cout << endl;
    cout << endl;
    cout << "inserindo 0" << endl;

    no = inserir(raiz, 0, 0);
    cout << endl;
    exibirArvore(raiz.raiz);
    cout << endl;
    cout << endl;
    no = inserir(raiz, -1, -1);
    cout << endl;
    exibirArvore(raiz.raiz);

    cout << endl;
    no = inserir(raiz, -2, -2);
    cout << endl;
    exibirArvore(raiz.raiz);
    cout << endl;
    cout << endl;
    no  = inserir(raiz, 9, 9);
    cout << endl;
    exibirArvore(raiz.raiz);

    cout << endl;
    Noh *noRemovido2 = inserir(raiz, 10, 10);
    cout << endl;
    exibirArvore(raiz.raiz);

    cout << endl;
    no = inserir(raiz, 8.1, 8.1);
    cout << endl;
    exibirArvore(raiz.raiz);

    cout << endl;

    Noh *noRemovido1 = inserir(raiz, 11, 11);
    cout << endl;
    exibirArvore(raiz.raiz);

    cout << endl;
    cout << endl;


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
 *    DicAVL raiz;

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