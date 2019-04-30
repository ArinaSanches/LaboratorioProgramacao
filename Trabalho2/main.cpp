#include <iostream>
using namespace std;

void buscarForcaBruta(const char *texto, const char * padrao, int *saida){

    const char *pos_texto = texto;
    const char *pos_padrao = padrao;
    const char *i_texto = texto;
    int match = 0;

    while(*i_texto != '\0'){
        if(*i_texto == *pos_padrao){
            i_texto ++;
            pos_padrao ++;
        }else{
            if(*pos_padrao == '\0'){
                *saida = (i_texto - texto) - (pos_padrao - padrao);
                pos_padrao = padrao;
                saida ++;
            }
            pos_texto ++;
            i_texto = pos_texto;
        }
    }

    if(*pos_padrao == '\0'){
        *saida = (i_texto - texto) - (pos_padrao - padrao);
        saida ++;
     }
    *saida = -1;
}

void ImprimirVetor(int* vector){
    cout << "{ ";
    while(*vector != -1){
        cout << *vector << " ";
        vector ++;
    }
    cout << "}" << endl;
    cout << endl << endl;
}


int main() {

    const char *texto =  "ABDABCDABCBABCC";
    const char *padrao = "ABC";

    int *saida =  new int[60];

    buscarForcaBruta(texto, padrao, saida);
    ImprimirVetor(saida);

    return 0;
}

