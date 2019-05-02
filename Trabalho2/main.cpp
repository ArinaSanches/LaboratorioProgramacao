#include <iostream>
#include <time.h>

using namespace std;


void ImprimirVetor(int* vector){
    cout << "{ ";
    while(*vector != -1){
        cout << *vector << " ";
        vector ++;
    }
    cout << "}" << endl;
    cout << endl << endl;
}

void buscarForcaBruta(const char *texto, const char * padrao, int *saida){

    const char *pos_texto = texto;
    const char *pos_padrao = padrao;
    const char *i_texto = texto;

    while(*i_texto != '\0'){
        if(*i_texto == *pos_padrao){
            i_texto ++;
            pos_padrao ++;
        }else{
            if(*pos_padrao == '\0'){
                *saida = (i_texto - texto) - (pos_padrao - padrao);
                saida ++;
            }
            pos_texto ++;
            i_texto = pos_texto;
            pos_padrao = padrao;
        }
    }

    if(*pos_padrao == '\0'){
        *saida = (i_texto - texto) - (pos_padrao - padrao);
        saida ++;
     }
    *saida = -1;
}

void calcularPi(const char * padrao, int * pi){
    pi[0] = 0;
    int k, l;
    for(int i = 1; padrao[i] != '\0'; i++){
        k = i - 1;
        for(;;){
            l = pi[k];
            if(l == 0){
                if(padrao[0] == padrao[i]){
                    pi[i] = 1;
                    break;
                }else{
                    pi[i] = 0;
                    break;
                }
            }else{
                if(padrao[i] == padrao[l]){
                    pi[i] = l + 1;
                    break;
                }else{
                    k = l - 1;
                }

            }
        }
    }
}

void algoritmoKMP(const char *texto, const char *padrao, int *saida){

    int *pi = new int[sizeof(padrao)]();
    calcularPi(padrao, pi);
    int i = 0, j = 0;

    while(texto[i] != '\0'){

        if(texto[i] != padrao[j]){
            if(j == 0){
                i++;
            }else{
                j = pi[(j-1)];
            }
        }else{
            if(padrao[j + 1] == '\0'){
                *saida = i - j;
                saida ++;
                j = pi[j];
                i++;
            }else{
                i++;
                j++;
            }
        }
    }

    *saida = -1;
    free(pi);
}

const char * gerarStringAleatorioa(int tamanho, int l){
    srand (time(NULL));
    char * texto = new char[tamanho];
    for(int i=0; i<tamanho; i++)
        texto[i] = 'A' + (char)(rand()%l);
    texto[tamanho] = '\0';
    return texto;
}


int main() {

    //const char *texto =  "ABDABCDABCBABCC";
    //const char *padrao = "ABC";

    int n = 20;
    int l = 3;
    int m = 3;
    const char *texto = gerarStringAleatorioa(n, l);
    const char *padrao = gerarStringAleatorioa(m, l);

    /*const char *padrao = "AAA";
    const char *texto = "AAAAAAAAAAAAAAAAAAAA";*/

    int *saida = new int[sizeof(texto)]();
    int *saida2 = new int[sizeof(texto)]();

    cout << "kmp" << endl;
    algoritmoKMP(texto, padrao, saida);
    cout << texto << endl;
    cout << padrao << endl;
    ImprimirVetor(saida);

    cout << "forca bruta" << endl;

    buscarForcaBruta(texto, padrao, saida2);
    cout << texto << endl;
    cout << padrao << endl;
    ImprimirVetor(saida2);


    return 0;
}

