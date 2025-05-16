/*
    AED1 - ED01
    DATA: 26/02/2024
    AUTORIA: ALESSANDRA FARIA RODRIGUES
    NUM. MATRICULA: 828333
*/

#include <stdio.h>

//- definir e ler um valor inteiro do teclado;
//- supor que esse valor represente o lado de um quadrado,
//calcular e mostrar a área de outro quadrado com o lado três vezes maior.

int main(void){
    const int x;
    int area;
    printf("AREA DO QUADRADO 3 VEZES MAIOR\n");
    printf("Digite um numero inteiro: ");
    scanf("%d", &x);
    area = (x * 3) * (x * 3);
    printf("O valor digitado foi: %d \nUm quadrado de lado 3 vezes maior tem lado = %d \ne tem a area = %d", x, x*3, area);
return 0;
}
