#include <iostream>
#include <stdlib.h>
using namespace std;
#include<tuple>


void trocarElementos(int *elem1, int *elem2){
    int aux = *elem1;
    *elem1 = *elem2;
    *elem2 = aux;
}

void ImprimirVetor(int* vector, int tamanho){
    cout << "{ ";
    for (int i = 0; i < tamanho ; ++i) {
        cout << vector[i] << " ";
    }
    cout << "}" << endl;
}

int* partLomuto(int *inicio, int *fim, int *pivo){

    trocarElementos(inicio, pivo);

    int *i = inicio;
    int *j = i + 1;

    while(j != (fim + 1)){
        if(*j < *inicio){
            i = i +1;
            trocarElementos(i, j);
        }
        j = j + 1;
    }
    trocarElementos(i, inicio);
    return i;
}

void selecaoHoare(int *inicio, int *fim, int *i){

    int *pivo = inicio + (fim - inicio)/2 ;
    int *p = partLomuto(inicio, fim, pivo);

    if(p == i){
        exit;
    }else if(i < p){
        selecaoHoare(inicio, p - 1, i);
    }else{
        selecaoHoare(p+1, fim, i);
    }
}

tuple<int*, int*> partLomutoTriplo(int *inicio, int *fim, int *pivo){

    trocarElementos(inicio, pivo);

    int *m = inicio;
    int *i = inicio;
    int *j = inicio + 1;
    int aux;
    while(j != (fim + 1)){

        if(*j == *inicio){
            i = i + 1;
            trocarElementos(i, j);
        }else if(*j < *inicio){
            m = m + 1;
            aux = *m;
            *m = *j;

            i = i + 1;
            *j = *i;
            *i = aux;
        }

        j = j + 1;
    }
    trocarElementos(m, inicio);

    return make_tuple(m, i);

}

int* Bfprt(int *inicio, int *fim){

    int tamanho = (fim - inicio) + 1;

    if (tamanho < 6){
        int *pivo = fim + (inicio - fim)/2;
        selecaoHoare(inicio, fim, pivo);
        return pivo;
    }

    int *i = inicio, *j = inicio + 4, *posMedInicio = inicio;
    int qtdPart5 = abs(tamanho / 5);
    int *ultimoI = inicio + (5 * qtdPart5);

    for(i = inicio; i < ultimoI; i = i + 5){
        int *pivo = i + 2;
        selecaoHoare(i, j, pivo);
        trocarElementos(pivo, posMedInicio);
        posMedInicio++;
        j = j + 5;
    }

    if(tamanho % 5 != 0){
        j = fim;
        int *pivo = ultimoI + (j - ultimoI)/2;
        selecaoHoare(ultimoI, j, pivo);
        trocarElementos(pivo, posMedInicio);
    }

    int *posUltMed = inicio + qtdPart5;
    Bfprt(inicio, posUltMed);
}

void TesteBfrt(int *inicio, int *fim, int*pivo){
    

    int *p = Bfprt(inicio, fim);
    cout << *p << endl;

    tuple <int*, int*> pivos = partLomutoTriplo(inicio, fim, p);
    cout << "apos part triplo" << endl;
    ImprimirVetor(inicio, fim- inicio + 1);

    if (pivo >= get<0>(pivos) && get<1>(pivos) >= pivo){
        exit;
    }else if( pivo < get<0>(pivos)){
        int *fimEsq = get<0>(pivos) -1;
        TesteBfrt(inicio, fimEsq, pivo);
    }else if(pivo > get<1>(pivos)){
        int *inicioDir = get<1>(pivos) + 1;
        TesteBfrt(inicioDir, fim, pivo);
    }


}

void Quicksort(int *inicio, int *fim, int *pivo){

    if(inicio == fim){
        exit;
    }

    pivo = partLomuto(inicio, fim, pivo);

    if(pivo > inicio){
        int *inicioEsq = inicio;
        int *fimEsq = pivo -1;
        Quicksort(inicioEsq, fimEsq, fimEsq);
    }

    if(pivo < fim){
        int *inicioDir = pivo + 1;
        int *fimDir = fim;
        Quicksort(inicioDir, fimDir, fimDir);
    }
}


int main() {
    int vetor[] = {1, 2, 5, 2, 4, 20, 1, 3, 6, 5, 5, 4, 1, 2, 1}; 
    int vetor2[] = {1, 2, 5, 2, 4, 20, 1, 3, 6, 5, 5, 4, 1, 2, 1}; 

    //int vetor[] = {1, 2, 5, 2, 4, 20, 1, 3, 6, 5, 5};

    int * inicio = vetor;
    int * fim = vetor + 14;

    int * inicio2 = vetor2;
    int * fim2 = vetor2 + 14;

    int *init = inicio;

    cout << "Vetor Inicial: " << endl;

    ImprimirVetor(inicio, 15);

    int *pivo = inicio + (fim - inicio)/2;
    int *pivo2 = inicio2+ (fim2 - inicio2)/2;


    TesteBfrt(inicio, fim, pivo);
    Quicksort(inicio2, fim2, pivo2);

    cout << "pivo: " << *pivo << endl;

    ImprimirVetor(inicio, 15);
    ImprimirVetor(inicio2, 15);



}