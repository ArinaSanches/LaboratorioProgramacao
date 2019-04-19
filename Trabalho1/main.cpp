#include <iostream>
#include "QuicksortIndice.h"
#include "QuicksortPonteiro.h"
#include "QuicksortBFPRT.h"
#include "QuicksortPivoAleatorio.h"
#include <time.h>
#include "FuncoesBasicas.h"
#include "QuicksortLogN.h"
#include "instancias_ruins_Quicksort.h"
#include <ctime>
#include <chrono>
using namespace std::chrono;


void gerarVetorAleatorio(int vetor[], int tamanho, int intervalo) {

    //srand (time(NULL));

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % (intervalo + 1);
    }
}

int escolher_pivo (int primeiro, int ultimo){
    return (primeiro + ultimo)/2;
}


void testarOrdenacao(int *inicio, int tamanho){

    int flag = 0;
    for(int i = 0; i < tamanho - 1; i++){
        int j = i +1;
        if(inicio[j] < inicio[i]){
            cout << "vetor nao foi corretamente ordenado" << endl;
            return;
        }
    }
    cout << "vetor foi corretamente ordenado" << endl;
}


int main() {

    FuncoesBasicas funcoes;

    int rodar = 1;
    clock_t t;

    while (rodar != 0) {

        int tamanho;
        cout << "Digite o tamanho do vetor desejado" << endl;
        cin >> tamanho;
        int *vetor =  new int[tamanho];

        int opcVetor;
        cout << "Digite 0 caso queira usar um vetor aleatorio e 1 caso queira usar a instancia fornecida pelo professor"
             << endl;

        int op = 0;

        while (op != 1) {

            cin >> opcVetor;

            if (opcVetor == 0) {
                int intervalo;
                cout << "Digite intervalo dos numeros aleatorios nele presentes" << endl;
                cin >> intervalo;
                gerarVetorAleatorio(vetor, tamanho, intervalo);
                op = 1;

            } else if (opcVetor == 1) {

                bool sucesso = true;
                while(sucesso){
                    sucesso = escrever_instancia(vetor, tamanho);
                }
                op = 1;

            } else {
                cout << "Opcao invalida" << endl;
                cout
                        << "Digite 0 caso queira usar um vetor aleatorio e 1 caso queira usar a instancia fornecida pelo professor"
                        << endl;
            }

        }

        cout << endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;

        // QUICKSORT INDICE
        cout << endl;
        int *vetorIndice = new int[tamanho];
        funcoes.copiarVetor(vetor, vetorIndice, tamanho);
        QuicksortIndice quickIndice;
        auto inicio = std::chrono::system_clock::now();
        quickIndice.Quicksort(vetorIndice, 0, (tamanho - 1));
        auto fim = std::chrono::system_clock::now();
        std::chrono::duration<double>duracao = fim - inicio;
        cout << "Quicksort usando indices:" << endl;
        cout << "Tempo de execcao: " << duracao.count() << endl;
        testarOrdenacao(vetorIndice, tamanho);

        cout << endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl << endl;

        //QUICKSORT PONTEIROS
        funcoes.copiarVetor(vetor, vetorIndice, tamanho);
        QuicksortPonteiro quicksortPonteiro;
        inicio = std::chrono::system_clock::now();
        quicksortPonteiro.Quicksort(vetorIndice, vetorIndice + (tamanho - 1));
        fim = std::chrono::system_clock::now();
        duracao = fim - inicio;
        cout << "Quicksort usando ponteiros: " << endl;
        cout << "Tempo de execcao: " << duracao.count() << endl;
        testarOrdenacao(vetorIndice, tamanho);

        cout << endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl << endl;

        //Quicksort log n
        funcoes.copiarVetor(vetor, vetorIndice, tamanho);
        QuicksortLogN quicksortLogN;
        inicio = std::chrono::system_clock::now();
        quicksortLogN.Quicksort(vetorIndice, vetorIndice + (tamanho - 1));
        fim = std::chrono::system_clock::now();
        duracao = fim - inicio;
        cout << "Quicksort Log N: " << endl;
        cout << "Tempo de execcao: " << duracao.count() << endl;
        testarOrdenacao(vetorIndice, tamanho);

        cout << endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl << endl;

        //Quicksort BFPRT
        funcoes.copiarVetor(vetor, vetorIndice, tamanho);
        QuicksortBFPRT quicksortBFPRT;
        inicio = std::chrono::system_clock::now();
        quicksortBFPRT.Quicksort(vetorIndice, vetorIndice + (tamanho - 1));
        fim = std::chrono::system_clock::now();
        duracao = fim - inicio;
        cout << "Quickort BFPRT: " << endl;
        cout << "Tempo de execcao: " << duracao.count() << endl;
        testarOrdenacao(vetorIndice, tamanho);

        cout << endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl << endl;

        //Quicksort Pivo Aleatorio
        funcoes.copiarVetor(vetor, vetorIndice, tamanho);
        QuicksortPivoAleatorio quicksortPivoAleatorio;
        inicio = std::chrono::system_clock::now();
        quicksortPivoAleatorio.Quicksort(vetorIndice, vetorIndice + (tamanho - 1));
        fim = std::chrono::system_clock::now();
        duracao = fim - inicio;
        cout << "Quicksort pivo aleatorio: " << endl;
        cout << "Tempo de execcao: " << duracao.count() << endl;
        testarOrdenacao(vetorIndice, tamanho);

        cout << endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl << endl;


        cout << "Digite 1 caso queira ordenar outro vetor e 0 caso contrario" << endl;
        cin >> rodar;

        cout << endl << endl << endl;

    }
    return 0;
}