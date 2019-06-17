#include <iostream>
#include <map>
using namespace std;
typedef map<char, int> dict;
typedef map<char, string> encodingMap;

#include <fstream>
#include <string>
#include <vector>
#include "Heap.h"

#include <sstream>


dict contarOcorrencias(dict dicionario, char &line){

    if(dicionario.find(line) == dicionario.end()){
        dicionario[line] = 1;
    }else{
        dicionario[line]++;
    }

    return dicionario;
}

dict lerArquivo(string nomeArquivo){

    ifstream myfile(nomeArquivo, std::ios::binary);
    dict ocorrencias;

    char byteLido;

    if (myfile.is_open()) {
        while (myfile >> noskipws >> byteLido ) {
            ocorrencias = contarOcorrencias(ocorrencias, byteLido);

        }
        myfile.close();
    }else {
        cout << "Unable to open file";
    }

    return ocorrencias;

}

void exibirCodigos(noHeap* root, int saida[], int top){

    if(root->esq){
        saida[top]=0;
        exibirCodigos(root->esq, saida, top + 1);
    }

    if(root->dir){
        saida[top] = 1;
        exibirCodigos(root->dir, saida, top+1);
    }

    if(!(root->esq)&&!(root->dir)){
        cout << root->letra << ": ";
        for(int i = 0; i < top; i++){
            cout << saida[i];
        }
        cout << endl;
    }

}

encodingMap gerarCodigos(encodingMap codigos, noHeap* root, string codigo){

    if(!(root->esq)&&!(root->dir)) {
        codigos[root->letra] = codigo;
    }else {

        codigos = gerarCodigos(codigos, root->esq, codigo + '0');

        codigos = gerarCodigos(codigos, root->dir, codigo + '1');
    }

    return codigos;
}


void escreverArvore(noHeap* raiz, vector<char> &arvore){

    if(!raiz){
        arvore.push_back('%')     ;
    }else {
        if (!(raiz->esq) && !(raiz->dir)) {
            arvore.push_back('$');
            arvore.push_back(raiz->letra);
        } else {
            arvore.push_back('#');
            escreverArvore(raiz->esq, arvore);
            escreverArvore(raiz->dir, arvore);
        }
    }
}


noHeap* buildHuffmanTree(Heap heap){
    noHeap *left, *right, *top;

    while(heap.heapSize != 1 ){

        left = heap.extractMinimum();
        right = heap.extractMinimum();

        top = heap.novoNo('$', left->freq + right->freq);

        top->esq = left;
        top->dir = right;

        heap.insert(top);
    }

    return heap.extractMinimum();
};


void comprimir(string nomeArquivo, string arquivoSaida){

    Heap heap;

    dict ocorrencias = lerArquivo(nomeArquivo);

    heap.construir(ocorrencias, ocorrencias.size());

    noHeap *res = buildHuffmanTree(heap);

    int *saida3 = new int[100];

    exibirCodigos(res, saida3, 0);

    vector<char> arvore;
    escreverArvore(res, arvore);

    ofstream myfile;

    myfile.open(arquivoSaida, std::ios::binary);

    int tamanho = arvore.size();

    myfile.write((char *)&tamanho, sizeof(int));

    myfile.write(arvore.data(), tamanho);

    myfile.close();
}


//ajeitar
noHeap* lerArvore(string arvore, int &pos, Heap heap, noHeap* no){
    if(arvore[pos] == '$'){
        pos ++;
        char letra = arvore[pos];
        pos ++;
        /*string codigo = "";
        while(arvore[pos] != '#' && arvore[pos] != '$' ){
            codigo = codigo + arvore[pos];
            pos ++;
        }*/
        no = heap.novoNo(letra, 0);
        no->esq = nullptr;
        no->dir = nullptr;
        return no;
    }

    no = heap.novoNo('$', 0);
    pos ++;
    no->esq = lerArvore(arvore, pos, heap, no);
    no->dir = lerArvore(arvore, pos, heap, no);
    return no;
}


int main() {



    comprimir("example.txt", "saida.txt");

    ifstream myfile("saida.txt", std::ios::binary);
    



  /*  string saida = "";
    int top = 0;

    encodingMap codigos;
*/
    //codigos = gerarCodigos(codigos,res, saida);
    /*

    for(auto it = codigos.cbegin(); it != codigos.cend(); ++it){
        cout << it->first << it->second << endl;
    }
*/

    /*noHeap *arv;
    int pos = 0;
    arv = lerArvore(a, pos, heap, arv);

    int *saida2 = new int[100];
    exibirCodigos(arv, saida2, 0);*/

    return 0;
}

/*
 +A aaaa b ccccc b cbef
bbeAAAAA
 */