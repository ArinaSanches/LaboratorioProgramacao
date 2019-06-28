//
// Created by arinasanches on 27/06/19.
//

#ifndef TRABALHO4_AVL_HPP
#define TRABALHO4_AVL_HPP

typedef double TC; typedef float TV;

struct Noh { TC chave; TV valor; Noh *esq, *dir, *pai; int h; };

struct DicAVL { Noh *raiz; }; // Nulo quando ´arvore vazia.

void inicializar (DicAVL &D); // Inicializa D como uma ´arvore vazia.

//NAO MUDAR ENDEREÇO DO NO DE UMA CHAVEo TC
Noh* inserir (DicAVL &D, TC c, TV v); // Retorna um ponteiro para o
// n´o, ou nulo se erro de aloca¸c~ao

Noh* procurar (DicAVL &D, TC c); // Retorna um ponteiro para o n´o da
// chave procurada, ou nulo se a chave
// n~ao estiver em D.

//NAO MUDAR ENDEREÇO DO NO DE UMA CHAVE
void remover (DicAVL &D, Noh *n); // ’n’ aponta para o n´o a ser removido

void terminar (DicAVL &D); // Desaloca os n´os da ´arvore.

#endif //TRABALHO4_AVL_HPP

