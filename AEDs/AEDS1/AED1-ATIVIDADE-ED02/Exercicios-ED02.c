/*
    AED1 - ED02
    DATA: 10/03/2024
    AUTORIA: ALESSANDRA FARIA RODRIGUES
    NUM. MATRICULA: 828333
*/

#include <stdio.h>

void procedimento0211() { //verificar se o numero e par ou impar
  int num;
  printf("Verificar se o numero e par ou impar\n");
  printf("Digite um valor: ");
  scanf("%d", &num);
  if (num % 2 == 0 || num == 0) {
    printf("O numero %d e par", num);
  } else {
    printf("O numero %d e impar", num);
  }
}

void procedimento0212() {
  int num;
  printf("Verificar se e impar e menor que -25, ou par e maior que 25\n");
  printf("Digite um valor: ");
  scanf("%d", &num);
  if (num % 2 == 0 && num > 25) {
    printf("O numero %d e par e tambem e maior que 25", num);
  } else if (num % 2 != 0 && num < -25) {
    printf("O numero %d e impar e tambem e menor do que -25", num);
  } else {
    printf("O numero digitado foi %d e nao se aplica a nenhuma das condicoes "
           "analisadas",
           num);
  }
}

void procedimento0213() {
  int num;
  printf("Verificar se pertence ao intervalo aberto entre (35:65)\n");
  printf("Digite um valor: ");
  scanf("%d", &num);
  if (num > 35 && num < 65) {
    printf("O numero %d pertence ao intervalo aberto entre 35 e 65", num);
  } else {
    printf("O numero %d NAO pertence ao intervalo aberto entre 35 e 65", num);
  }
}

void procedimento0214() {
  int num;
  printf("Verificar se pertence ao intervalo fechado entre [15:60]\n");
  printf("Digite um valor: ");
  scanf("%d", &num);
  if (num >= 15 && num <= 60) {
    printf("O numero %d pertence ao intervalo fechado 15 e 60", num);
  } else {
    printf("O numero %d NAO pertence ao intervalo fechado 15 e 60", num);
  }
}

void procedimento0215(){
    int num;
    printf("Dados os intervalos fechados [10:30] e (25:50), verificar se pertence a intersecao ou a apenas a um deles\n");
    printf("Digite um valor: ");
    scanf("%d", &num);
    if(num > 25 && num <= 30){ //interseccao
        printf("O numero %d pertence a interseccao\n", num);
    } else if(num >= 10 && num <= 30){ //intervalo fechado [10:30]
        printf("O numero %d pertence ao intervalo [10:30]\n", num);
    } else if(num > 25 && num < 50){ //interalo aberto (25:50)
        printf("O numero %d pertence ao intervalo (25:50)\n", num);
    } else {
        printf("O numero %d nao pertence a nenhum dos intervalos", num);
    }
}

void procedimento0216(){
    int num1, num2;
    printf("Verificar se o primeiro numero e impar e se o segundo e par\n");
    printf("Digite o primeiro valor: ");
    scanf("%d", &num1);
    printf("Digite o segundo valor: ");
    scanf("%d", &num2);
    if(num1%2 != 0 && num2%2 == 0) {//primeiro impar segundo par
        printf("%d e impar e %d e par", num1, num2);
}   else {
    printf("Nao se aplica");
}
}

void procedimento0217(){
    int num1, num2;
    printf("Verificar se o primeiro numero e par e negativo, e se o segundo e impar e positivo\n");
    printf("Digite o primeiro valor: ");
    scanf("%d", &num1);
    printf("Digite o segundo valor: ");
    scanf("%d", &num2);

    if(num1%2 == 0 && num1 < 0){ //par e negativo
        printf("O numero %d e par e negativo\n", num1);
    } else {
        printf("O numero %d nao e par e negativo\n", num1);
    }

    if(num2%2 != 0 && num2 > 0){ //impar e positivo
        printf("O numero %d e impar e positivo", num2);
    } else {
        printf("O numero %d nao e impar e positivo", num2);
    }
}

void procedimento0218(){
    double num1, num2;
    printf("Verificar se o segundo numero e menor, igual ou maior que um terco do primeiro\n");
    printf("Digite o primeiro valor: ");
    scanf("%lf", &num1);
    printf("Digite o segundo valor: ");
    scanf("%lf", &num2);
    num1 = num1/3;
    printf("1/3 do primeiro numero = %.2lf\n", num1);

    if(num2 == num1){
        printf("O segundo numero e igual a 1/3 do primeiro");
    } else if(num2 > num1){
        printf("O segundo numero e maior que 1/3 do primeiro");
    } else if(num2 < num1){
        printf("O segundo numero e menor que 1/3 do primeiro");
    }
}

void procedimento0219(){
    double num1, num2, num3;
    printf("Verificar se o primeiro está entre os dois últimos, quando esses dois forem diferentes entre si.\n");
    printf("Digite o primeiro valor: ");
    scanf("%lf", &num1);
    printf("Digite o segundo valor: ");
    scanf("%lf", &num2);
    printf("Digite o terceiro valor: ");
    scanf("%lf", &num3);

    if(num1 != num3){ //verificando se o primeiro e diferente do ultimo
        if((num2 < num1 && num1 < num3) || (num3 < num1 && num1 < num2) ){
            printf("O numero %.2lf esta entre os numeros %.2lf e %.2lf", num1, num2, num3);
        } else{
            printf("O numero %.2lf NAO esta entre os numeros %.2lf e %.2lf", num1, num2, num3);
        }
    } else {
        printf("O primeiro e o ultimo numero sao iguais");
    }
}

void procedimento0220(){
    double num1, num2, num3;
    printf("Verificar se o primeiro nao esta entre os dois ultimos, quando todos forem diferentes entre si\n");
    printf("Digite o primeiro valor: ");
    scanf("%lf", &num1);
    printf("Digite o segundo valor: ");
    scanf("%lf", &num2);
    printf("Digite o terceiro valor: ");
    scanf("%lf", &num3);

    if(num1 != num2 && num1 != num3 && num2 != num3){ //verifiando se todos os numeros sao diferentes
        if((num2 < num1 && num1 < num3) || (num3 < num1 && num1 < num2)){
            printf("O numero %.2lf esta entre os numeros %.2lf e %.2lf", num1, num2, num3);
        } else {
            printf("O numero %.2lf NAO esta entre os numeros %.2lf e %.2lf", num1, num2, num3);
        }
    } else {
        printf("Ha numeros repetidos");
    }
}

int main(void) {
    int opcao;
  do{
    printf("\n\nEscolha uma das opcoes abaixo: \n");
    printf("\n\t0: Sair");
    printf("\n\t1: Procedimento0211");
    printf("\n\t2: Procedimento0212");
    printf("\n\t3: Procedimento0213");
    printf("\n\t4: Procedimento0214");
    printf("\n\t5: Procedimento0215");
    printf("\n\t6: Procedimento0216");
    printf("\n\t7: Procedimento0217");
    printf("\n\t8: Procedimento0218");
    printf("\n\t9: Procedimento0219");
    printf("\n\t10: Procedimento0220\n");
    scanf("%d", &opcao);

    switch(opcao){
        case 0:
            break;
        case 1:
            procedimento0211();
            break;
        case 2:
            procedimento0212();
            break;
        case 3:
            procedimento0213();
            break;
        case 4:
            procedimento0214();
            break;
        case 5:
            procedimento0215();
            break;
        case 6:
            procedimento0216();
            break;
        case 7:
            procedimento0217();
            break;
        case 8:
            procedimento0218();
            break;
        case 9:
            procedimento0219();
            break;
        case 10:
            procedimento0220();
            break;

        default:
            printf("Opcao invalida!\n");
            break;
    }

  } while(opcao != 0);

  return 0;
}
