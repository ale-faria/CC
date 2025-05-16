#include <stdio.h>

//QUESTAO 06
int primo(int numero){
    int contPrimo = 0;
    if(numero>2){
        for(int i = 2; i < numero; i++){
            if(numero%i == 0){
                contPrimo++;
            }
        }
    }

    if(contPrimo == 0){
        return 1; //É PRIMO
    } else {
        return 0; //NÃO é primo
    }
}

int inverte(int num){
    int invertido = 0;

    while (num != 0) {
        invertido = invertido * 10 + num % 10;
        num = num / 10;
    }

    return invertido;
}



int main(void){
    int contSheldon = 0;
    for(int i = 11; i <= 99; i++){
        int primo1 = i;
        int primo2 = inverte(i);
        int resultado1 = primo(primo1);
        int resultado2 = primo(primo2);

        if(resultado1 == 1 && resultado2 == 1){
            contSheldon++;
        }
    }
    printf("%d ", contSheldon);
return 0;
}
