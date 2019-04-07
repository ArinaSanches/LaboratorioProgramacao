#include <iostream>
#include "QuicksortIndice.h"
#include "QuicksortPonteiro.h"
#include "QuicksortBFPRT.h"
#include "QuicksortPivoAleatorio.h"
#include <time.h>
#include "FuncoesBasicas.h"
using namespace std;


void gerarVetorAleatorio(int vetor[], int tamanho, int intervalo) {

    srand (time(NULL));

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % (intervalo + 1);
    }
}


int main() {
    //int opcVetor = 1;
    //cout << "Digite 1 se deseja gerar um vetor aleatorio e 0 caso deseje usar o gerador de instancias do professor" << endl;
    //cin >> opcVetor;

    FuncoesBasicas funcoes;

    int tamanho;
    cout << "Digite o tamanho do vetor" << endl;
    cin >> tamanho;
    int intervalo;
    cout<< "Digite intervalo dos numeros aleatorios nele presentes" << endl;
    cin >> intervalo;

    int vetor[tamanho];
    gerarVetorAleatorio(vetor, tamanho, intervalo);

    // QUICKSORT INDICE
    cout << "Vetor Inicial: "<<  endl;
    funcoes.ImprimirVetor(vetor, tamanho);

    int vetorIndice[tamanho];
    funcoes.copiarVetor(vetor, vetorIndice, tamanho);

    QuicksortIndice quickIndice;
    quickIndice.Quicksort(vetorIndice, 0, (tamanho-1));

    cout << "Vetor apos ordenacao com quicksort usando indicess: "<<  endl;
    quickIndice.ImprimirVetor(vetorIndice, tamanho);

    //QUICKSORT PONTEIROS
    int vetorPont[tamanho];
    funcoes.copiarVetor(vetor, vetorPont, tamanho);
    QuicksortPonteiro quicksortPonteiro;
    quicksortPonteiro.Quicksort(vetorPont, vetorPont + (tamanho -1), vetorPont + (tamanho -1) );

    cout << "Vetor apos ordenacao com quicksort usando Ponteiros: "<<  endl;
    funcoes.ImprimirVetor(vetorPont, tamanho);

    //Quicksort BFPRT
    int vetorBFPRT[tamanho];
    funcoes.copiarVetor(vetor, vetorBFPRT, tamanho);
    QuicksortBFPRT quicksortBFPRT;
    quicksortBFPRT.Quicksort(vetorBFPRT, vetorBFPRT + (tamanho -1));

    cout << "Vetor apos ordenacao com quicksort usando algotimo BFPRT: "<<  endl;
    funcoes.ImprimirVetor(vetorBFPRT, tamanho);

    //Quicksort Pivo Aleatorio
    int vetorPivoAleatorio[tamanho];
    funcoes.copiarVetor(vetor, vetorPivoAleatorio, tamanho);
    QuicksortPivoAleatorio quicksortPivoAleatorio;
    quicksortPivoAleatorio.Quicksort(vetorPivoAleatorio, vetorPivoAleatorio + (tamanho -1));

    cout << "Vetor apos ordenacao com quicksort usando pivo aleatorio: "<<  endl;
    funcoes.ImprimirVetor(vetorPivoAleatorio, tamanho);

    cout << "Vetor Inicial: "<<  endl;
    funcoes.ImprimirVetor(vetor, tamanho);



    return 0;
}