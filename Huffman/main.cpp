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


void contarOcorrencias(dict &dicionario, char &line){

    if(dicionario[line]){
        dicionario[line]++;
    }else{
        dicionario[line] = 1;
    }
}

dict lerArquivo(const string nomeArquivo){

    ifstream myfile(nomeArquivo, std::ios::binary);
    dict ocorrencias;

    int i = 0;
    if (myfile) {
        char byteLido;

        while (myfile >> noskipws >> byteLido ) {
            if(myfile.eof()){
                break;
            }
            contarOcorrencias((ocorrencias), byteLido);
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

    if(!root){
       return codigos;
    }
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
        arvore.push_back('%');
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

noHeap* construirArvoreHuffman(Heap heap){
    noHeap *esq, *dir, *top;

    while(heap.heapSize != 1 ){

        esq = heap.extractMinimum();
        dir = heap.extractMinimum();

        top = heap.novoNo('$', esq->freq + dir->freq);

        top->esq = esq;
        top->dir = dir;

        heap.insert(top);
    }

    return heap.extractMinimum();
};

void codificarArquivo(string nomeArquivoEntrada, noHeap *arvoreHuffman, ofstream &arquivoSaida){

    string saida = "";   

    encodingMap codigos;

    codigos = gerarCodigos(codigos, arvoreHuffman, saida);

    ifstream arquivoEntrada;

    arquivoEntrada.open(nomeArquivoEntrada, std::ios::binary);

    long posQtdUltBits = arquivoSaida.tellp();

    int qtdUltBits = 0;

    arquivoSaida.write((char *)&qtdUltBits, sizeof(int));

    int numBitsLidos = 0;

    char byteLido;

    char bit_buffer = 0;

    string codificacao = "";


    if (arquivoEntrada.is_open()) {
        while (arquivoEntrada >> noskipws >> byteLido ) {

            codificacao = codigos[byteLido];

            int posCodigo = 0;

            while(posCodigo < codificacao.length()){

                bit_buffer = bit_buffer << 1;

                if(codificacao[posCodigo] == '1') {
                   bit_buffer = bit_buffer | (char) 1;
                }

                numBitsLidos ++;
                posCodigo ++;

                if(numBitsLidos == 8){
                    arquivoSaida.write(&bit_buffer, sizeof(char));
                    numBitsLidos = 0;
                    bit_buffer = 0;
                }
            }
        }

        int qtdBits = numBitsLidos;

        while(numBitsLidos != 8){
            bit_buffer = bit_buffer << 1;
            numBitsLidos ++;
        }

        arquivoSaida.write(&bit_buffer, sizeof(char));

        arquivoSaida.seekp(posQtdUltBits);

        arquivoSaida.write((char *)&qtdBits, sizeof(int));

        arquivoEntrada.close();
    }else {
        cout << "Unable to open file" << endl;
    }

}

void comprimir(string nomeArquivoEntrada, string nomeArquivoSaida){

    Heap heap;

    dict ocorrencias = lerArquivo(nomeArquivoEntrada);

    noHeap *arvoreHuffman;


    if(!ocorrencias.empty()){

        heap.construir(ocorrencias, ocorrencias.size());

        arvoreHuffman = construirArvoreHuffman(heap);
    }else{
        cout << "entrou" << endl;
        arvoreHuffman = nullptr;
    }

    vector<char> arvore;
    escreverArvore(arvoreHuffman, arvore);

    ofstream arquivoSaida;

    arquivoSaida.open(nomeArquivoSaida, std::ios::binary);

    int tamanhoArvore = arvore.size();

    arquivoSaida.write((char *) &tamanhoArvore, sizeof(int));

    arquivoSaida.write(arvore.data(), tamanhoArvore);

    codificarArquivo(nomeArquivoEntrada, arvoreHuffman, arquivoSaida);

    arquivoSaida.close();

    cout << "Compressao realizada com sucesso!" << endl;

}

//ajeitar
noHeap* lerArvore(string arvore, int &pos, Heap heap, noHeap* no){
    if(arvore[pos] == '#'){
        pos ++;
        char letra = arvore[pos];
        pos ++;
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

void descomprimir(string nomeArquivoEntrada, string nomeArquivoSaida){
    //passos:
    //primeiro, ler tamnanho da arvore OK
    //depois ler a arvore OK
    //reconstruir a arvore OK
    //refazer o texto

    ifstream arquivoEntrada(nomeArquivoEntrada, std::ios::binary);

    ofstream arquivoSaida(nomeArquivoSaida, std::ios::binary);

    int tamanhoArvore = 0;

    arquivoEntrada.read((char *)&tamanhoArvore, sizeof(int));

    string arvore = "";

    char byteLido;

    int i = 0;

    while (i < tamanhoArvore ) {
        arquivoEntrada.read(&byteLido, sizeof(char));
        arvore += byteLido;
        i++;
    }

    noHeap* arvoreHuffman;

    Heap heap;

    int pos = 0;

    arvoreHuffman = lerArvore(arvore, pos, heap, arvoreHuffman);

    int qtdUltBits = 0;

    arquivoEntrada.read((char *)&qtdUltBits, sizeof(int));

    char bytecorrente;

    int numBitLidos = 0;

    noHeap* no = arvoreHuffman;

    arquivoEntrada.read(&bytecorrente, sizeof(char));

    if(tamanhoArvore != 1 && arvore != "%"){
        while (!arquivoEntrada.eof()) {

            int bit = bytecorrente >> (7 - numBitLidos) & (char) 1;

            if (bit == 1) {
                no = no->dir;
            } else {
                no = no->esq;
            }

            if (!(no->esq) && !(no->dir)) {
                arquivoSaida.write(&no->letra, sizeof(char));
                if (arquivoEntrada.peek() == EOF && numBitLidos == qtdUltBits) {
                    break;
                }
                no = arvoreHuffman;
            }

            numBitLidos++;

            if (numBitLidos == 8) {
                arquivoEntrada.read(&bytecorrente, sizeof(char));
                numBitLidos = 0;
            }
        }
    }

    cout << "Descompressao realizada com sucesso!" << endl;
}


int main() {

    comprimir("inputs/books.txt", "comprimidos/booksComprimido.txt");
    descomprimir("comprimidos/booksComprimido.txt", "descomprimidos/booksDesComprimido.txt");

    comprimir("inputs/ch05-patterns.pdf", "comprimidos/ch05-patternsComprimido.pdf");
    descomprimir("comprimidos/ch05-patternsComprimido.pdf", "descomprimidos/ch05-patternsDesComprimido.pdf");

    comprimir("inputs/Stavechurch-heddal.bmp", "comprimidos/Stavechurch-heddalComprimido.bmp");
    descomprimir("comprimidos/Stavechurch-heddalComprimido.bmp", "descomprimidos/Stavechurch-heddalDesComprimido.bmp");

    comprimir("inputs/Huffman_coding_Wikipedia.tar", "comprimidos/Huffman_coding_WikipediaComprimido.tar");
    descomprimir("comprimidos/Huffman_coding_WikipediaComprimido.tar", "descomprimidos/Huffman_coding_WikipediaDesComprimido.tar");

    comprimir("inputs/empty_file.txt", "comprimidos/empty_fileComprimido.txt");
    descomprimir("comprimidos/empty_fileComprimido.txt", "descomprimidos/empty_fileDesComprimido.txt");

    return 0;
}

