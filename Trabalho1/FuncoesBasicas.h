//
// Created by Arina on 07/04/2019.
//

#ifndef TRABALHO1_FUNCOESBASICAS_H
#define TRABALHO1_FUNCOESBASICAS_H
#include<tuple>
using namespace std;



class FuncoesBasicas{
public:
    void trocarElementos(int *elem1, int *elem2);
    void ImprimirVetor(int* vector, int tamanho);
    int* partLomuto(int *inicio, int *fim, int *pivo);
    void selecaoHoare(int *inicio, int *fim, int *i);
    tuple<int*, int*> partLomutoTriplo(int *inicio, int *fim, int *pivo);
    void copiarVetor(int vetor1[], int vetor2[], int tamanho);
};

#endif //TRABALHO1_FUNCOESBASICAS_H
