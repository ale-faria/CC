/*
    AED1 - ED01
    DATA: 27/02/2024
    AUTORIA: ALESSANDRA FARIA RODRIGUES
    NUM. MATRICULA: 828333
*/

#include <stdio.h>
#include <math.h>

/*
- definir e ler um valor real do teclado;
- supor que esse valor represente a medida de lados de um cubo,
 calcular e mostrar o volume do sólido com cinco vezes a medida do lado.
*/

int main(void){
    double lado, volume;
     printf("VOLUME DO CUBO COM 5 VEZES A MEDIDA DO LADO\n\n");
     printf("Digite um valor (lado): ");
     scanf("%lf", &lado);
     lado = lado * 5;
     volume = pow(lado, 3);
     printf("O cubo com 5 vezes o lado possui: \n\tlado = %.2lf cm \n\tvolume = %.2lf cm^3", lado, volume);

return 0;
}
