#include <iostream>
#include <map>
using namespace std;
typedef map<char, int> dict;
#include <fstream>
#include <string>
#include "Heap.h"


dict contarOcorrencias(dict dicionario, string line){

    for(int i = 0; line[i] != '\0';i++){
        if(dicionario.find(line[i]) == dicionario.end() && line[i] != ' ' ){
            dicionario[line[i]] = 1;
        }else if (line[i] != ' '){
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

int main() {

    dict ocorrencias = lerArquivo("example.txt");


    Heap heap;

    heap.construir(ocorrencias, ocorrencias.size());


    noHeap *res = heap.buildHuffmanTree();

    int *saida = new int[100], top = 0;

    exibirCodigos(res, saida, top);
    return 0;
}

/*
 +A aaaa b ccccc b cbef
bbeAAAAA
 */