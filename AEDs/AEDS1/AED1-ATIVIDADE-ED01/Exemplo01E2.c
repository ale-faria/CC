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
- supor que esse valor represente o volume de uma esfera;
- calcular e mostrar o raio de cinco oitavos do volume da esfera
 e a área de sua superfície.
*/

double calculaRaioEsfera(double volume){
    double pi = M_PI;
    double raio;
    raio = cbrt((3 * volume) / (4 * pi));
    return raio;
}

double calculaAreaEsfera(double raio){
    double pi = M_PI;
    double area;
    area = 4 * pi * pow(raio, 2);
    return area;
}

int main(void){
    double volume, raio, area;
    printf("Digite o valor (volume da esfera): ");
    scanf("%lf", &volume);
    raio = calculaRaioEsfera(volume);
    area = calculaAreaEsfera(raio);
    printf("\nO raio dessa esfera e = %.2lf", raio);
    printf("\nA area dessa esfera e = %.2lf", area);
    volume = volume * 0.625; //5/8 do volume inicial
    raio = calculaRaioEsfera(volume);
    area = calculaAreaEsfera(raio);
    printf("\n\nO novo volume agora e = %.2lf", volume);
    printf("\nO raio da nova esfera e = %.2lf", raio);
    printf("\nA area da nova esfera e = %.2lf", area);

    printf("\n\nFinalizando...\n");

return 0;
}
