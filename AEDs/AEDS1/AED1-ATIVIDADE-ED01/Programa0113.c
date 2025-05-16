/*
    AED1 - ED01
    DATA: 26/02/2024
    AUTORIA: ALESSANDRA FARIA RODRIGUES
    NUM. MATRICULA: 828333
*/

#include <stdio.h>
/*
- definir e ler dois valores inteiros do teclado;
- supor que esses dois valores representem lados de um retângulo,
 calcular e mostrar a área seis vezes maior.*/

 //interpretei que a AREA é 6 vezes maior, e não os lados
int main(void){
    int a, b;
    int area;
    printf("AREA 6 VEZES MAIOR DE UM RETANGULO\n");
    printf("Digite o primeiro valor: ");
    scanf("%d", &a);
    printf("Digite o segundo valor: ");
    scanf("%d", &b);
    area = a * b;
    printf("A area desse retangulo e igual a %d", area);
    area = area * 6;
    printf("\nA area 6 vezes maior desse mesmo retangulo e igual a %d", area);

return 0;
}
