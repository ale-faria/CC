#include <stdio.h>
#include <string.h>

int soma(char * palavra){
    int soma1 = 0, soma2 = 0;
    int tamanho = strlen(palavra);
    for(int i = 0; i < tamanho; i++){
        soma1 += (palavra[i]-48);
    }
    soma1 = soma1 * soma1;

    for(int i = 0; i < tamanho; i++){
        soma2 += (palavra[i]-48) * (palavra[i]-48) * (palavra[i]-48);
    }

    if(soma1 == soma2){
        return 1;
    } else {
        return 0;
    }
}

int main(void){
    char palavra[80];
    printf("Digite os algarismos: ");
    scanf("%s", palavra);

    int resultado = soma(palavra);
    if(resultado == 1){
        printf("Afirmativa correta\n");
    } else {
        printf("Nao corresponde\n");
    }
return 0;
}
