/*
    AED1 - ED01
    DATA: 27/02/2024
    AUTORIA: ALESSANDRA FARIA RODRIGUES
    NUM. MATRICULA: 828333
*/

#include <stdio.h>

/*- definir e ler dois valores inteiros do teclado;
- supor que esses dois valores representem lados de um retângulo,
 calcular e mostrar a área e o perímetro de um retângulo com um quarto dos
 tamanhos dos lados.*/

 int main(void){
     float b, h;
     float area, perimetro;
     printf("AREA E PERIMETRO DO RETANGULO DE LADO 1/4\n\n");
     printf("Digite o primeiro valor: ");
     scanf("%f", &b);
     printf("Digite o segundo valor: ");
     scanf("%f", &h);
     area = (b/4) * (h/4);
     perimetro = ((b/4) * 2) + ((h/4) * 2);
     printf("A area desse retangulo com 1/4 do tamanho dos lados = %.2f\n", area);
     printf("O perimetro desse retangulo com 1/4 do tamanho dos lados = %.2f\n", perimetro);
 return 0;
 }
