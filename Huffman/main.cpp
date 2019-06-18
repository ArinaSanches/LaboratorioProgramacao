#include <iostream>
#include <map>
using namespace std;
typedef map<char, int> dict;
typedef map<char, string> encodingMap;

#define BYTE 8 //To make the code more clear, define a name to represent the size of a byte


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
            arvore.push_back('#');
            arvore.push_back(raiz->letra);
        } else {
            arvore.push_back('$');
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

void codificarArquivo(string nomeArquivo, noHeap *res, ofstream &myfile){

    string saida = "";   

    encodingMap codigos;

    codigos = gerarCodigos(codigos, res, saida);

    char byteLido;

    ifstream myfile2;

    myfile2.open(nomeArquivo, std::ios::binary);

    string codificacao = "";

    long posQtdUltBits = myfile.tellp();

    int qtdUltBits = 0;

    myfile.write((char *)&qtdUltBits, sizeof(int));

    int numBitsCorrente = 0;
    char bit_buffer = 0;


    if (myfile2.is_open()) {
        while (myfile2 >> noskipws >> byteLido ) {
            codificacao = codigos[byteLido];
            int posCodigo = 0;

            while(posCodigo < codificacao.length()){

                bit_buffer = bit_buffer << 1;

                if(codificacao[posCodigo] == '1') {
                   bit_buffer = bit_buffer | (char) 1;
                }

                numBitsCorrente ++;
                posCodigo ++;

                if(numBitsCorrente == 8){
                    myfile.write(&bit_buffer, sizeof(char));
                    numBitsCorrente = 0;
                    bit_buffer = 0;
                }
            }
        }

        int qtdBits = numBitsCorrente;

        while(numBitsCorrente != 8){
            bit_buffer = bit_buffer << 1;
            numBitsCorrente ++;
        }

        myfile.write(&bit_buffer, sizeof(char));

        myfile.seekp(posQtdUltBits);

        myfile.write((char *)&qtdBits, sizeof(int));

        myfile2.close();
    }else {
        cout << "Unable to open file";
    }

}

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

    myfile.write((char *) &tamanho, sizeof(int));

    myfile.write(arvore.data(), tamanho);

    codificarArquivo(nomeArquivo, res, myfile);

    myfile.close();


}

//ajeitar
noHeap* lerArvore(string arvore, int &pos, Heap heap, noHeap* no){
    if(arvore[pos] == '#'){
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

    if(arvore[pos] == '%'){
        return no;
    }

    no = heap.novoNo('$', 0);
    pos ++;
    no->esq = lerArvore(arvore, pos, heap, no);
    no->dir = lerArvore(arvore, pos, heap, no);
    return no;
}


void descomprimir(string nomeArquivo, string arquivoSaida){
    //passos:
    //primeiro, ler tamnanho da arvore OK
    //depois ler a arvore OK
    //reconstruir a arvore OK
    //refazer o texto

    ifstream myfile(nomeArquivo, std::ios::binary);

    ofstream arqSaida(arquivoSaida, std::ios::binary);


    int tamanho = 0;

    myfile.read((char *)&tamanho, sizeof(int));

    cout << tamanho << endl;

    string arvore = "";

    char byteLido;

    int i = 0;

    while (i < tamanho ) {
        myfile.read(&byteLido, sizeof(char));
        arvore += byteLido;
        i++;
    }

    cout << arvore << endl;

    noHeap* raiz;

    Heap heap;

    int pos = 0;

    raiz = lerArvore(arvore, pos, heap, raiz);

    int qtdUltBits = 0;

    myfile.read((char *)&qtdUltBits, sizeof(int));

    char bytecorrente;

    int numBitLido = 0;

    noHeap* no = raiz;

    myfile.read(&bytecorrente, sizeof(char));

    while(!myfile.eof()){

        int bit = bytecorrente >> (7 - numBitLido) & (char)1;

        if(bit == 1){
            no = no->dir;
        }else{
            no = no->esq;
        }

        if(!(no->esq)&&!(no->dir)){
            arqSaida.write(&no->letra, sizeof(char));
            if(myfile.peek() == EOF && numBitLido == qtdUltBits){
                break;
            }
            no = raiz;
        }
        numBitLido++;

        if(numBitLido == 8){
            myfile.read(&bytecorrente, sizeof(char));
            numBitLido = 0;
        }
    }
}


int main() {



    descomprimir("saida.txt", "arqdescomp.txt");


    return 0;
}

