#include <iostream>
#include "QuicksortIndice.h"
#include "QuicksortPonteiro.h"
#include "QuicksortBFPRT.h"
#include "QuicksortPivoAleatorio.h"
#include <time.h>
#include "FuncoesBasicas.h"
#include "QuicksortLogN.h"
#include "instancias_ruins_Quicksort.h"

using namespace std;


void gerarVetorAleatorio(int vetor[], int tamanho, int intervalo) {

    srand (time(NULL));

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

    while (rodar != 0) {

        int tamanho;
        cout << "Digite o tamanho do vetor desejado" << endl;
        cin >> tamanho;
        int vetor[tamanho];

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

                bool sucesso = escrever_instancia(vetor, tamanho);
                cout << sucesso << endl;
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
        int vetorIndice[tamanho];
        funcoes.copiarVetor(vetor, vetorIndice, tamanho);
        QuicksortIndice quickIndice;
        quickIndice.Quicksort(vetorIndice, 0, (tamanho - 1));
        cout << "Quicksort usando indices:" << endl;
        testarOrdenacao(vetorIndice, tamanho);

        cout << endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl << endl;

        //QUICKSORT PONTEIROS
        int vetorPont[tamanho];
        funcoes.copiarVetor(vetor, vetorPont, tamanho);
        QuicksortPonteiro quicksortPonteiro;
        quicksortPonteiro.Quicksort(vetorPont, vetorPont + (tamanho - 1));
        cout << "Quicksort usando ponteiros: " << endl;
        testarOrdenacao(vetorPont, tamanho);

        cout << endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl << endl;

        //Quicksort log n
        int vetorlog[tamanho];
        funcoes.copiarVetor(vetor, vetorlog, tamanho);
        QuicksortLogN quicksortLogN;
        quicksortLogN.Quicksort(vetorlog, vetorlog + (tamanho - 1));
        cout << "Quicksort Log N: " << endl;
        testarOrdenacao(vetorlog, tamanho);

        cout << endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl << endl;

        //Quicksort BFPRT
        int vetorBFPRT[tamanho];
        funcoes.copiarVetor(vetor, vetorBFPRT, tamanho);
        QuicksortBFPRT quicksortBFPRT;
        quicksortBFPRT.Quicksort(vetorBFPRT, vetorBFPRT + (tamanho - 1));
        cout << "Quickort BFPRT: " << endl;
        testarOrdenacao(vetorBFPRT, tamanho);

        cout << endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl << endl;

        //Quicksort Pivo Aleatorio
        int vetorPivoAleatorio[tamanho];
        funcoes.copiarVetor(vetor, vetorPivoAleatorio, tamanho);
        QuicksortPivoAleatorio quicksortPivoAleatorio;
        quicksortPivoAleatorio.Quicksort(vetorPivoAleatorio, vetorPivoAleatorio + (tamanho - 1));
        cout << "Quicksort pivo aleatorio: " << endl;
        testarOrdenacao(vetorPivoAleatorio, tamanho);

        cout << endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl << endl;

        cout << "Digite 1 caso queira ordenar outro vetor e 0 caso contrario" << endl;
        cin >> rodar;

        cout << endl << endl << endl;

    }
    return 0;
}