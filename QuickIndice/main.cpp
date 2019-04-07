#include <iostream>
using namespace std;


void trocarElementos(int vetor[],int i, int j){
    int aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;

}

void ImprimirVetor(int vetor[], int tamanho){
    cout << "{ ";
    for (int i = 0; i <= tamanho; ++i) {
        cout << vetor[i] << " ";
    }
    cout << "}" << endl;
}

int partLomuto(int vetor[], int inicio, int tamanho){

    trocarElementos(vetor, inicio, tamanho);

    int i = inicio;
    int j =  inicio + 1;

    while(j <= tamanho){
        if(vetor[j] < vetor[inicio]){
            i = i +1;
            trocarElementos(vetor, i, j);
        }
        j = j + 1;
    }
    trocarElementos(vetor, i, inicio);
    return i;
}



void Quicksort(int vetor[], int inicio, int tamanho){

    if(inicio == tamanho){
        return;
    }

    int pivo = partLomuto(vetor, inicio, tamanho);

    int fimEsq;
    int inicioDir;

    if(pivo > inicio){
        fimEsq = pivo - 1;
        Quicksort(vetor, inicio, fimEsq);
    }

    if(pivo < tamanho){
        inicioDir = pivo + 1;
        Quicksort(vetor, inicioDir, tamanho);
    }

}


int main() {

    //int vetor[] = {1, 2, 5, 2, 4, 20, 1, 3, 6, 5, 5, 4, 1, 2, 1};
    int vetor[] = {1, 20, 1, 3, 3, 2, 1, 30, 2, 4};

    int tamanho = (sizeof(vetor)/ sizeof(int)) -1;

    ImprimirVetor(vetor, tamanho);
    Quicksort(vetor, 0, tamanho);
    ImprimirVetor(vetor, tamanho);


}
