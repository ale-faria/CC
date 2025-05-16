/*
    AED1 - ED01
    DATA: 27/02/2024
    AUTORIA: ALESSANDRA FARIA RODRIGUES
    NUM. MATRICULA: 828333
*/

#include <stdio.h>
#include <math.h>

/*- definir e ler três valores reais do teclado;
- supor que esses valores correspondam ao comprimento, à largura e à altura
 de um paralelepípedo, respectivamente,
- calcular e mostrar o volume do sólido com um oitavo desses valores.*/

int main(void){
    double comprimento, largura, altura, volume;
    printf("VOLUME DO PARALELEPIPEDO COM 1/8 DAS MEDIDAS\n\n");
    printf("Digite um valor (comprimeto): ");
    scanf("%lf", &comprimento);
    printf("Digite um valor (largura): ");
    scanf("%lf", &largura);
    printf("Digite um valor (altura): ");
    scanf("%lf", &altura);
    volume = (comprimento/8) * (largura/8) * (altura/8);
    printf("Um paralelepipedo com 1/8 das medidas informadas possui volume = %.2lf", volume);

return 0;
}
