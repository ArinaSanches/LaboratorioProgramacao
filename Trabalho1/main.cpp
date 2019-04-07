#include <iostream>
#include "QuicksortIndice.h"
//#include "QuicksortPonteiro.h"
#include "QuicksortBFPRT.h"
#include "QuicksortPivoAleatorio.h"
#include <time.h>


using namespace std;


void gerarVetorAleatorio(int vetor[], int tamanho, int intervalo) {

    srand (time(NULL));

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % (intervalo + 1);
    }
}

void ImprimirVetor(int vetor[], int tamanho){
    cout << "{ ";
    for (int i = 0; i < tamanho; ++i) {
        cout << vetor[i] << " ";
    }
    cout << "}" << endl;
}

void copiarVetor(int vetor1[], int vetor2[], int tamanho){
    for (int i = 0; i < tamanho; i++){
        vetor2[i] = vetor1[i];
    }
}


int main() {
    //int opcVetor = 1;
    //cout << "Digite 1 se deseja gerar um vetor aleatorio e 0 caso deseje usar o gerador de instancias do professor" << endl;
    //cin >> opcVetor;

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
    ImprimirVetor(vetor, tamanho);

    int vetorIndice[tamanho];
    copiarVetor(vetor, vetorIndice, tamanho);

    QuicksortIndice quickIndice;
    quickIndice.Quicksort(vetorIndice, 0, (tamanho-1));

    cout << "Vetor apos ordenacao com quicksort usando indicesS: "<<  endl;
    quickIndice.ImprimirVetor(vetorIndice, tamanho);
/*
    //QUICKSORT PONTEIROS
    int vetorPont[tamanho];
    copiarVetor(vetor, vetorPont, tamanho);
    QuicksortPonteiro quicksortPonteiro;
    quicksortPonteiro.Quicksort(vetorPont, vetorPont + (tamanho -1), vetorPont + (tamanho -1) );

    cout << "Vetor apos ordenacao com quicksort usando Ponteiros: "<<  endl;
    quickIndice.ImprimirVetor(vetorPont, tamanho);

    //Quicksort BFPRT
    int vetorBFPRT[tamanho];
    copiarVetor(vetor, vetorBFPRT, tamanho);
    QuicksortBFPRT quicksortBFPRT;
    quicksortBFPRT.Quicksort(vetorBFPRT, vetorBFPRT + (tamanho -1));

    cout << "Vetor apos ordenacao com quicksort usando algotimo BFPRT: "<<  endl;
    quicksortBFPRT.ImprimirVetor(vetorBFPRT, tamanho);*/

    //Quicksort Pivo Aleatorio
    int vetorPivoAleatorio[tamanho];
    copiarVetor(vetor, vetorPivoAleatorio, tamanho);
    QuicksortPivoAleatorio quicksortPivoAleatorio;
    quicksortPivoAleatorio.Quicksort(vetorPivoAleatorio, vetorPivoAleatorio + (tamanho -1));

    cout << "Vetor apos ordenacao com quicksort usando algotimo BFPRT: "<<  endl;
    quicksortPivoAleatorio.ImprimirVetor(vetorPivoAleatorio, tamanho);




    return 0;
}