/*
    AED1 - ED01
    DATA: 27/02/2024
    AUTORIA: ALESSANDRA FARIA RODRIGUES
    NUM. MATRICULA: 828333
*/

#include <stdio.h>
#include <math.h>

/*- definir e ler um valor real do teclado;
- supor que esse valor represente o raio de um círculo,
 calcular e mostrar a área de um semicírculo com um sexto do raio.*/

int main(void){
    double raio, areaSemicirculo;
    double pi = M_PI;
    printf("AREA DO SEMICIRCULO COM 1/6 DO RAIO\n\n");
    printf("Digite um valor (raio): ");
    scanf("%lf", &raio);
    areaSemicirculo = (pi * (pow(raio/6, 2))) / 2;
    printf("Um circulo com 1/6 de raio possui: \n\traio = %.2lf \n\tarea = %.2lf", raio/6, areaSemicirculo);

return 0;
}
