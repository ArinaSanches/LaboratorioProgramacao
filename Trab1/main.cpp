#include <iostream>
using namespace std;

bool sao_iguais (const char *r, const char *s){

    while(*r != '\0' && *s != '\0'){
        if(*r == *s){
            ++r;
            ++s;
        }else{
            break;
        }
    }

    if(*r == '\0' && *s == '\0'){
        return true;
    }else{
        return false;
    }
}

void inverter (int *v, int n){

    int *ultimaPos = v + (n -1);
    int *meio = v + (n/2);
    int aux;

    for(int *p = v; p!= meio; p++ ){
        aux = *ultimaPos;

        *ultimaPos = *p;
        *p = aux;
        --ultimaPos;
    }
}


int main() {
    /*char r[] = "     Arina";
    char s[] = "Arina";
    if(sao_iguais(r, s)){
        cout << "As strings sao iguais";
    }else{
        cout<<"As string nao sao iguais";
    }*/

    int vetor[] = {1, 2, 3, 4, 5};

    cout << vetor[0] << endl << vetor[1] << endl << vetor[2] << endl << vetor[3] << endl << vetor[4] << endl;

    inverter(vetor, 5);

    cout <<"invertido"<< endl << vetor[0] << endl << vetor[1] << endl << vetor[2] << endl << vetor[3] << endl << vetor[4];

}
