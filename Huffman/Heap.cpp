//
// Created by Arina on 09/06/2019.
//
#include <iostream>

#include <stdio.h>
#include <cstdlib>
#include "Heap.h"
#include <map>

typedef map<char, int> dict;


noHeap* Heap::novoNo(char letra, int freq){

    struct noHeap* no = (struct noHeap*)malloc(sizeof(struct noHeap));

    no->esq = nullptr;
    no->dir = nullptr;
    no->letra = letra;
    no->freq = freq;

    return no;
}

void Heap::construir(dict ocorrencias, int pSize){

    heapSize = pSize;

    heap = (struct noHeap**)malloc(pSize * sizeof(struct noHeap*));

    int i = 0;
    for(auto it = ocorrencias.cbegin(); it != ocorrencias.cend(); ++it){
        heap[i] = novoNo(it->first , it->second);
        i++;
    }

    for(int index = (pSize-1) / 2; index >=0; index--){
        heapify(heap, index);
    }
}

void Heap::heapify(noHeap** pVector , int pIndex) {
    int left = getLeft(pIndex);
    int right = getRight(pIndex);
    int largest;


    if (left < heapSize && pVector[left]->freq < pVector[pIndex]->freq) {
        largest = left;
    }else{
        largest = pIndex;
    }


    if(right < heapSize && pVector[right]->freq < pVector[largest]->freq) {
        largest = right;
    }

    if(largest != pIndex){
        Swap(pVector, pIndex, largest);
        heapify(pVector, largest);
    }
}

int Heap::getParent(int pIndex){
    return pIndex / 2;
}

int Heap::getLeft(int pIndex){
    return 2 * pIndex;
}

int Heap::getRight(int pIndex){
    return 2*pIndex + 1;
}

void Heap::Swap(noHeap** p, int pIndex, int largest){
    noHeap *aux;
    aux = p[pIndex];
    p[pIndex] = p[largest];
    p[largest] = aux;
}

/* Nao sei porque nao esta funcionando
void Heap::insert(char letra, int freq){

    noHeap* no = novoNo(letra, freq);
    heapSize = heapSize + 1;
    int k = heapSize;
    while(k > 1 && freq < heap[getParent(k)]->freq ){
        heap[k] = heap[getParent(k)];
        k = getParent(k);
    }
    heap[k] = no;
    cout << "tamanho" << heapSize << endl << endl;
    for(int i = 0; i < heapSize; i++){
        cout << heap[i]->freq << "  " << heap[i]->letra << endl;
    }
}*/

void Heap::insert(noHeap* no){

    heapSize = heapSize + 1;
    int k = heapSize - 1;
    while(k && no->freq < heap[(k - 1)/2]->freq ){
        heap[k] = heap[(k - 1)/2];
        k = (k - 1)/2;
    }
    heap[k] = no;
}



noHeap* Heap::minimum(){
    return heap[0];
}


noHeap* Heap::extractMinimum(){
    if (heapSize < 1){
        cout << "Heap underflow";
        return 0;
    }
    noHeap* max = heap[0];
    heap[0] = heap[heapSize-1];
    heapSize = heapSize -1;
    heapify(heap, 0);

    return max;
}







