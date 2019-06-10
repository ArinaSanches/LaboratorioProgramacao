//
// Created by Arina on 09/06/2019.
//

#ifndef HUFFMAN_HEAP_H
#define HUFFMAN_HEAP_H

#include <stdio.h>

using namespace std;

#include <map>

typedef map<char, int> dict;


struct noHeap{
    char letra;
    int freq;
    noHeap *esq;
    noHeap *dir;
};

class Heap {
public:

    int heapSize;

    struct noHeap** heap;

    void construir(dict ocorrencias, int pSize);
    void heapify(noHeap** pVector, int pIndex);

    int getParent(int pIndex);

    int getLeft(int pIndex);

    int getRight(int pIndex);

    void insert(noHeap* no);

    noHeap* minimum();

    noHeap* extractMinimum();

    void Swap(noHeap**, int pIndex, int largest);

    noHeap* buildHuffmanTree();

};




#endif //HUFFMAN_HEAP_H
