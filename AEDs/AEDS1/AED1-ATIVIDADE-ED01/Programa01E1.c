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
- supor que esse valor informe a área de uma circunferência,
- calcular e mostrar o raio um sétimo dessa área.

*/

int main(void){
    double area, raio;
    double pi = M_PI;
    printf("Digite o valor (area da circunferencia): ");
    scanf("%lf", &area);
    raio = sqrt(area/pi);
    printf("O raio dessa circunferencia e = %.2lf", raio);
    area = area / 7;
    printf("\n1/7 da area = %.2lf", area);
    raio = sqrt(area/pi);
    printf("\nO raio da nova circunferencia e = %.2lf\n", raio);

return 0;
}
