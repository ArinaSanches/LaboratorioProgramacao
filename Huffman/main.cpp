#include <iostream>
#include <map>
using namespace std;
typedef map<char, int> dict;
typedef map<char, string> encodingMap;

#include <chrono>
#include <time.h>


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

dict lerArquivo(const string nomeArquivo, ifstream &myfile){

    dict ocorrencias;

    char byteLido;

    while (myfile >> noskipws >> byteLido ) {
        if(myfile.eof()){
            break;
        }
        contarOcorrencias((ocorrencias), byteLido);
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

                if(numBitsLidos == 8){
                    if(arquivoEntrada.eof()){
                        break;
                    }
                    arquivoSaida.write(&bit_buffer, sizeof(char));
                    numBitsLidos = 0;
                    bit_buffer = 0;
                }

                bit_buffer = bit_buffer << 1;

                if(codificacao[posCodigo] == '1') {
                   bit_buffer = bit_buffer | (char) 1;
                }

                numBitsLidos ++;
                posCodigo ++;
            }
        }

        int qtdBits = numBitsLidos;

        while(numBitsLidos != 8){
            bit_buffer = bit_buffer << 1;
            numBitsLidos ++;
        }
        if(qtdBits != 8){
            arquivoSaida.write(&bit_buffer, sizeof(char));
        }

        arquivoSaida.seekp(posQtdUltBits);

        arquivoSaida.write((char *)&qtdBits, sizeof(int));

        arquivoEntrada.close();
    }else {
        cout << "Nao foi possivel abrir o arquivo!" << endl;
    }

}

void comprimir(string nomeArquivoEntrada, string nomeArquivoSaida){

    Heap heap;

    ifstream arquivoEntrada(nomeArquivoEntrada, std::ios::binary);

    if (arquivoEntrada) {

        dict ocorrencias = lerArquivo(nomeArquivoEntrada, arquivoEntrada);

        arquivoEntrada.close();

        noHeap *arvoreHuffman;

        if(!ocorrencias.empty()){

            heap.construir(ocorrencias, ocorrencias.size());

            arvoreHuffman = construirArvoreHuffman(heap);
        }else{
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
        

    }else {
        cout << "Nao foi possivel abrir o arquivo!" << endl;
    }

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

    if (arquivoEntrada) {

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

                numBitLidos++;

                if (!(no->esq) && !(no->dir)) {
                    arquivoSaida.write(&no->letra, sizeof(char));
                    if (arquivoEntrada.peek() == EOF && numBitLidos == qtdUltBits) {
                        break;
                    }
                    if(arquivoSaida.eof()){
                        break;
                    }
                    no = arvoreHuffman;
                }


                if (numBitLidos == 8) {
                    arquivoEntrada.read(&bytecorrente, sizeof(char));
                    numBitLidos = 0;
                }
            }
        }

        cout << "Descompressao realizada com sucesso!" << endl;

    }else {
        cout << "Nao foi possivel abrir o arquivo!" << endl;
    }
}


int main() {

    comprimir("inputs/books.txt", "comprimidos/booksComprimido.huf");
    descomprimir("comprimidos/booksComprimido.huf", "descomprimidos/booksDesComprimido.txt");

    comprimir("inputs/ch05-patterns.pdf", "comprimidos/ch05-patternsComprimido.huf");
    descomprimir("comprimidos/ch05-patternsComprimido.huf", "descomprimidos/ch05-patternsDesComprimido.pdf");

    comprimir("inputs/Stavechurch-heddal.bmp", "comprimidos/Stavechurch-heddalComprimido.huf");
    descomprimir("comprimidos/Stavechurch-heddalComprimido.huf", "descomprimidos/Stavechurch-heddalDesComprimido.bmp");

    comprimir("inputs/Huffman_coding_Wikipedia.tar", "comprimidos/Huffman_coding_WikipediaComprimido.huf");
    descomprimir("comprimidos/Huffman_coding_WikipediaComprimido.huf", "descomprimidos/Huffman_coding_WikipediaDesComprimido.tar");

    comprimir("inputs/empty_file.txt", "comprimidos/empty_fileComprimido.huf");
    descomprimir("comprimidos/empty_fileComprimido.huf", "descomprimidos/empty_fileDesComprimido.txt");


    // int opc = -1;

    // string nomeArquivoEntrada, nomeArquivoSaida;

    // cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl << endl;

    // cout << "Digite 0 para comprimir e 1 para descomprimir." << endl;

    // cin >> opc;

    // while(opc == 0 || opc ==1){

    //     if(opc == 0) {

    //         cout << "Digite o nome do arquivo a ser comprimido." << endl;
    //         cin >> nomeArquivoEntrada;
    //         cout << "Digite o nome do arquivo de saida." << endl;
    //         cin >> nomeArquivoSaida;

    //         auto inicio = std::chrono::high_resolution_clock::now();

    //         cout << endl;

    //         comprimir("inputs/"+nomeArquivoEntrada, "comprimidos/"+nomeArquivoSaida);

    //         auto fim = std::chrono::high_resolution_clock::now();
    //         std::chrono::duration<double>duracao = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);

    //         cout << "Tempo de execcao: " << duracao.count() << " microsegundos." << endl;

    //         opc = -1;

    //     }else if(opc == 1){

    //         cout << "Digite o nome do arquivo a ser descomprimido." << endl;
    //         cin >> nomeArquivoEntrada;
    //         cout << "Digite o nome do arquivo de saida." << endl;
    //         cin >> nomeArquivoSaida;

    //         auto inicio = std::chrono::high_resolution_clock::now();

    //         cout << endl;

    //         descomprimir("comprimidos/"+nomeArquivoEntrada, "descomprimidos/"+nomeArquivoSaida);

    //         auto fim = std::chrono::high_resolution_clock::now();
    //         std::chrono::duration<double>duracao = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);

    //         cout << "Tempo de execcao: " << duracao.count() << " microsegundos." << endl;

    //         opc = -1;

    //     }

    //     cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl << endl;
    //     cout << "Digite 0 para comprimir e 1 para descomprimir." << endl;
    //     cin >> opc;
        

    // }
    return 0;
}

