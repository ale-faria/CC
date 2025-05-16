/*
    AED1 - ED01
    DATA: 27/02/2024
    AUTORIA: ALESSANDRA FARIA RODRIGUES
    NUM. MATRICULA: 828333
*/

#include <stdio.h>

/*- definir e ler dois valores reais do teclado;
- supor que esses dois valores representem base e altura de um triângulo,
 calcular e mostrar a área de um triângulo com o dobro da altura do mesmo.*/

 int main(void){
     float b, h;
     float area;
     printf("TRIANGULO COM O DOBRO DE ALTURA\n\n");
     printf("Digite o primeiro valor (base): ");
     scanf("%f", &b);
     printf("Digite o segundo valor (altura): ");
     scanf("%f", &h);
     area = (b * (h*2)) / 2;
     printf("A area desse triangulo com o dobro de altura = %.2f", area);
 return 0;
 }
