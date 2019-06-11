#include <iostream>
#include <map>
using namespace std;
typedef map<char, int> dict;
typedef map<char, string> encodingMap;

#include <fstream>
#include <string>
#include "Heap.h"


dict contarOcorrencias(dict dicionario, string line){

    for(int i = 0; line[i] != '\0';i++){
        if(dicionario.find(line[i]) == dicionario.end()){
            dicionario[line[i]] = 1;
        }else{
            dicionario[line[i]]++;
        }
    }

    return dicionario;
}

dict lerArquivo(string nomeArquivo){

    string line;
    ifstream myfile (nomeArquivo);
    dict ocorrencias;

    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            ocorrencias = contarOcorrencias(ocorrencias, line);

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

encodingMap gerarCodigos(encodingMap codigos, noHeap* root, string saida[], int top){

    if(root->esq){
        saida[top]="0";
        gerarCodigos(codigos, root->esq, saida, top+1);
    }

    if(root->dir){
        saida[top] = "1";
        gerarCodigos(codigos, root->dir, saida, top+1);
    }

    if(!(root->esq)&&!(root->dir)){
        string codigo = " ";
        for(int i = 0; i < top; i++){
            codigo.append(saida[i]);
        }
        codigos[root->letra] = codigo;
    }

    for(auto it = codigos.cbegin(); it != codigos.cend(); ++it){
        cout << it->first << it->second << endl;
    }

    return codigos;
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

int main() {

    dict ocorrencias = lerArquivo("example.txt");


    Heap heap;

    heap.construir(ocorrencias, ocorrencias.size());


    noHeap *res = buildHuffmanTree(heap);

    
    string *saida = new string[100];
    int top = 0;

    encodingMap codigos;

    codigos = gerarCodigos(codigos,res, saida, top);

    for(auto it = codigos.cbegin(); it != codigos.cend(); ++it){
        cout << it->first << it->second;
    }
    cout << codigos['a'];

    return 0;
}

/*
 +A aaaa b ccccc b cbef
bbeAAAAA
 */