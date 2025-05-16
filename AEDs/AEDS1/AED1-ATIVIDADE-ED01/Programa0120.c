/*
    AED1 - ED01
    DATA: 27/02/2024
    AUTORIA: ALESSANDRA FARIA RODRIGUES
    NUM. MATRICULA: 828333
*/

#include <stdio.h>
#include <math.h>

/*- definir e ler um valor real do teclado;
- supor que esse valor represente o raio de uma esfera,
 calcular e mostrar o volume de uma esfera com três quartos do raio.
*/

int main(void){
    double raio, volumeEsfera;
    double pi = M_PI;
    printf("VOLUME DA ESFERA COM 3/4 DO RAIO\n\n");
    printf("Digite um valor (raio): ");
    scanf("%lf", &raio);
    volumeEsfera = (4 * pi * pow(raio*0.75 , 3)) / 3;
    printf("O volume da esfera com 3/4 de raio = %.2lf", volumeEsfera);

return 0;
}
