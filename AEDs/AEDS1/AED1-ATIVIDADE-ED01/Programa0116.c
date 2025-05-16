/*
    AED1 - ED01
    DATA: 27/02/2024
    AUTORIA: ALESSANDRA FARIA RODRIGUES
    NUM. MATRICULA: 828333
*/

#include <stdio.h>
#include <math.h>

/*- definir e ler um valor real do teclado;
- supor que esse valor represente o lado de um triângulo equilátero,
 calcular e mostrar a altura, área e o perímetro do triângulo com o triplo do lado.*/

 int main(void){
     double lado;
     double altura, area, perimetro;
     printf("TRIANGULO EQUILATERO COM TRIPLO DE LADO");
     printf("\n\nDigite o valor (lado): ");
     scanf("%lf", &lado);
     lado = lado * 3; //triplicando o valor do lado
     perimetro = lado * 3; //achando o perimetro - detalhe que aqui o lado ja esta vezes 3
     altura = ((sqrt(3)) * lado) / 2;
     area = (lado * altura) / 2;
     printf("Um triangulo com o triplo de lado possui: \n\tlado = %.2lf", lado);
     printf("\n\taltura = %.2lf", altura);
     printf("\n\tarea = %.2lf", area);
     printf("\n\tperimetro = %.2lf", perimetro);

 return 0;
 }
