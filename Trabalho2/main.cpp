#include <iostream>
#include <time.h>
#include "instancias_Reais_Trabalho_2.hpp"
#include <chrono>


using namespace std;


void ImprimirVetor(int* vector){
    cout << "{ ";
    while(*vector != -1){
        cout << *vector << " ";
        vector ++;
    }
    cout << "}" << endl;

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

const char* gerarStringAleatorioa(int tamanho, int l){
    srand (time(NULL));
    char * texto = new char[tamanho];
    for(int i=0; i<tamanho; i++)
        texto[i] = 'A' + (char)(rand()%l);
    texto[tamanho] = '\0';
    return texto;
}

const char* gerarVetorAs(int tamanho){
    char * texto = new char[tamanho];
    for(int i=0; i<tamanho; i++)
        texto[i] = 'A';
    texto[tamanho] = '\0';
    return texto;
}

const char* gerarPadraoPiorCaso1(int tamanho){
    char * texto = new char[tamanho];
    for(int i=0; i<tamanho - 1; i++)
        texto[i] = 'A';
    texto[tamanho -1] = 'B';
    texto[tamanho] = '\0';
    return texto;
}

void compararResultados(int *saidaForcaBruta, int *saidaKmp){

    int flag = 0;
    int *i = saidaForcaBruta;
    int *j = saidaKmp;
    while (*i != -1){

        if(*i != *j){
            cout << "Os algoritmos obtiveram resultados diferentes!" << endl << endl;
            cout << "Saida algoritmo forca bruta:  ";
            ImprimirVetor(saidaForcaBruta);
            cout << "Saida Algoritmo kmp        :  ";
            ImprimirVetor(saidaKmp);
            return;
        }
        i ++;
        j ++;
    }

    if(*j != -1){
        cout << "Os algoritmos obtiveram resultados diferentes!" << endl << endl;
        cout << "Saida algoritmo forca bruta:  ";
        ImprimirVetor(saidaForcaBruta);
        cout << "Saida Algoritmo kmp        :  ";
        ImprimirVetor(saidaKmp);
        return;
    }
    cout << "Os algoritmos obtiveram o mesmo resultados!" << endl << endl;
    cout << "Saida algoritmo forca bruta:  ";
    ImprimirVetor(saidaForcaBruta);
    cout << "Saida Algoritmo kmp        :  ";
    ImprimirVetor(saidaKmp);
}

int main() {

    int rodar = 1;
    clock_t t;
    const char *texto;
    const char *padrao;
    int n = 1;
    int m = 2;
    int l = 0;

    while (rodar != 0) {

        int opc_instancia;

        cout << "Escolha o tipo de instancia que deseja utilizar" << endl << "Digite: " << endl;
        cout << "1 - Para usar instancias aleatorias" << endl << "2 - Para usar o Pior caso 1" << endl
             << "3 - Para usar o Pior caso 2" << endl << "4 -Para usar Textos Reais";

        cin >> opc_instancia;

        int op = 0;

        while (op != 1) {

            if(opc_instancia > 4 || opc_instancia < 1) {
                cout << endl << endl;
                cout << "Opcao invalida" << endl;
                cout << "Escolha o tipo de instancia que deseja utilizar" << endl << "Digite: " << endl;
                cout << "1 - Para usar instancias aleatorias" << endl << "2 - Para usar o Pior caso 1" << endl
                     << "3 - Para usar o Pior caso 2" << endl << "4 -Para usar Textos Reais";
                cin >> opc_instancia;
            }else if(opc_instancia == 4) {

                int posPadrao = -1;

                while(posPadrao < 0 || posPadrao > 35129) {
                    cout << "Digite um numero entre 0 e 35129 que sera o numero do padrao";
                    cin >> posPadrao;
                    if (posPadrao < 0 || posPadrao > 35129)
                        cout << "Opcao invalida! O numero tem que estar entre 0 e 35129!" << endl << endl;
                }

                texto = Texto_Livros;
                padrao = Padroes_Palavras[posPadrao];
                op = 1;

            }else{
                while(m > n) {
                    cout << endl << "Digite o tamanho do texto" << endl;
                    cin >> n;
                    cout << "Digite o tamanho do padrao" << endl;
                    cin >> m;
                    if(m > n)
                        cout << "O tamanho do padrao deve ser menor ou igual ao tamanho do texto" << endl << endl;
                }

                while( l <= 0 || l > 26) {
                    cout << endl << "Digite o intervalo de 1 a 26 para gerar os caracteres aleatorios" << endl;
                    cin >> l;
                    if(m > n)
                        cout << "O tamanho do padrao deve ser menor ou igual ao tamanho do texto" << endl << endl;
                }

                if(opc_instancia == 1){
                    texto = gerarStringAleatorioa(n, l);
                    padrao = gerarStringAleatorioa(m, l);
                }else if(opc_instancia == 2){
                    texto = gerarVetorAs(n);
                    padrao = gerarPadraoPiorCaso1(m);
                }else{
                    texto = gerarVetorAs(n);
                    padrao = gerarVetorAs(m);
                }
                op = 1;
            }

        }


        cout << endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl << endl;
        cout << "Algoritmo forca bruta" << endl;

        int *saidaForcaBruta = new int[sizeof(texto)]();

        auto inicio = std::chrono::system_clock::now();

        buscarForcaBruta(texto, padrao, saidaForcaBruta);

        auto fim = std::chrono::system_clock::now();
        std::chrono::duration<double>duracao = fim - inicio;

        cout << "Tempo de execcao: " << duracao.count() << endl;

        cout << endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl << endl;

        cout << "Algoritmo kmp" << endl;

        int *saidaKmp = new int[sizeof(texto)]();

        inicio = std::chrono::system_clock::now();

        algoritmoKMP(texto, padrao, saidaKmp);

        fim = std::chrono::system_clock::now();
        duracao = fim - inicio;

        cout << "Tempo de execcao: " << duracao.count() << endl;

        cout << endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl << endl;

        cout << "COmparacao saida dos algoritmos" << endl << endl;

        compararResultados(saidaForcaBruta, saidaKmp);

        cout << endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl << endl;


        cout << "Digite 1 caso queira ordenar outro vetor e 0 caso contrario" << endl;
        cin >> rodar;

        cout << endl << endl << endl;

        if(rodar == 1){
            n = 1;
            m = 2;
            l = 0;
        }

    }

    return 0;
}


