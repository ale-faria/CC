#include <stdio.h>
#include <string.h>

int sequencia(char *palavra){
    int tamanho = strlen(palavra);
    int contU = 0, contT = 0, contACG = 0, contOutros = 0;

//primeiro contando toda a sequencia
     for (int i = 0; i < tamanho; i++) {
        if (palavra[i] == 'T') {
            contT++;
        } else if (palavra[i] == 'U') {
            contU++;
        } else if (palavra[i] == 'A' || palavra[i] == 'C' || palavra[i] == 'G') {
            contACG++;
        } else {
            contOutros++;
        }
    }

//segundo fazendo as verificacoes e retornando o resultado
    if (contT > 0 && contU == 0) {
        return 1; // Tem 'T' e nenhum 'U'
    } else if (contU > 0 && contT == 0) {
        return 2; // Tem 'U' e nenhum 'T'
    } else if (contT == 0 && contU == 0) {
        return 0; // Não tem 'T' e nem 'U'
    } else {
        return -1; // Outra combinação
    }
}


int main(void){
    printf("%d ", sequencia("TACAGATA"));
return 0;
}
