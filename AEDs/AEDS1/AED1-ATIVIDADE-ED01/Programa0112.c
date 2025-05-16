/*
    AED1 - ED01
    DATA: 26/02/2024
    AUTORIA: ALESSANDRA FARIA RODRIGUES
    NUM. MATRICULA: 828333
*/

#include <stdio.h>

/*- definir e ler um valor inteiro do teclado;
- supor que esse valor represente o lado de um quadrado,
 calcular e mostrar a área e o perímetro de um quadrado com a metade do tamanho do lado.*/

int main(void){
    float x;
    float area, perimetro;
    printf("AREA DE METADE DO QUADRADO\n");
    printf("Digite um numero inteiro: ");
    scanf("%f", &x);
    area = (x/2) * (x/2);
    perimetro = (x/2) * 4;
    printf("\nO valor digitado foi: %.2f \nUm quadrado com metade desse valor tem lado = %.2f, \ntem a area = %.2f \ne tem o perimetro = %2.f", x, x/2, area, perimetro);

return 0;
}
