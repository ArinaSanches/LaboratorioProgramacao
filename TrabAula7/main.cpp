#include <iostream>
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




void Quicksort(int *inicio, int *fim, int *pivo){

    if(inicio == fim){
        exit;
    }

    selecaoHoare(inicio, fim, pivo);
    //descobrir como calcular o meio do vetor! e mudar o fimEsq para o meio do vetor
    if(pivo > inicio){
        int *inicioEsq = inicio;
        int *fimEsq = pivo -1;
        int *pivoEsq = inicioEsq + (fimEsq - inicioEsq)/2;
        Quicksort(inicioEsq, fimEsq, pivoEsq);
    }

    if(pivo < fim){
        int *inicioDir = pivo + 1;
        int *fimDir = fim;
        int *pivoDir = inicioDir + (fimDir - inicioDir)/2;
        Quicksort(inicioDir, fimDir, pivoDir);
    }
}


int main() {

    int vetor[] = {1, 20, 1, 3, 3, 2, 1, 30, 2, 4};

    //int vetor[] = { 2, 9, 6, 3, 5, 4, 8, 1, 7};;



    int * inicio = vetor;
    int * fim = vetor + 9;
    int * pivo = vetor + 4;

    int *init = inicio;

    cout << "Vetor Inicial: " << endl;

    ImprimirVetor(inicio, 10);

    Quicksort(inicio, fim, pivo);

    cout << "Vetor depois do Quicksort: " << endl;
    ImprimirVetor(init, 10);


}