
/*
    AED1 - ED05 - 03/04/2024
    AUTORIA: ALESSANDRA FARIA RODRIGUES
    NUM. MATRICULA: 828333
*/



#include <stdio.h>
#include <math.h>

void mostraMultiplosDeSeis(int n){
    int valor = 0;
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%d ", valor);
        valor += 6;
    }
    printf("\n");
}

int funcao0511(){
    int n;
    printf("MOSTRAR n MULTIPLOS DE 6\n\n");
    printf("Digite a quantidade n: ");
    scanf("%d", &n);
    fflush(stdin);

    if(n <= 0){
        printf("Valor invalido\n");
    } else {
        mostraMultiplosDeSeis(n);
    }

    return 0;
}

void mostraMultiplosDeTresECinco(int n){
    int valor = 0;
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%d ", valor);
        //obs: os multiplos de 3 e 5 (ao mesmo tempo) são os multiplos de 15
        valor += 15;
    }
    printf("\n");
}

int funcao0512(){
    int n;
    printf("MOSTRAR n MULTIPLOS DE 3 e 5\n\n");
    printf("Digite a quantidade n: ");
    scanf("%d", &n);
    fflush(stdin);

    if(n <= 0){
        printf("Valor invalido\n");
    } else {
        mostraMultiplosDeTresECinco(n);
    }

    return 0;
}

void mostraPotenciaDeQuatro(int n){
    double valor = 0;
    printf("\n");
    for(int i = n-1; i >= 0; i--){
        valor = pow(4, i);
        printf("%.0lf ", valor);
    }
    printf("\n");
}

int funcao0513(){
    int n;
    printf("MOSTRAR n POTENCIAS DE 4 (DECRESCENTE)\n\n");
    printf("Digite a quantidade n: ");
    scanf("%d", &n);
    fflush(stdin);

    if(n <= 0){
        printf("Valor invalido\n");
    } else {
        mostraPotenciaDeQuatro(n);
    }

    return 0;
}

void mostraMultiplosDeSeteNoDenominador(int n){
    int valor = 7;
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("1/%d ", valor);
        valor += 7;
    }
    printf("\n");
}

int funcao0514(){
    int n;
    printf("MOSTRAR n MULTIPLOS DE 7 NO DENOMINADOR\n\n");
    printf("Digite a quantidade n: ");
    scanf("%d", &n);
    fflush(stdin);

    if(n <= 0){
        printf("Valor invalido\n");
    } else {
        mostraMultiplosDeSeteNoDenominador(n);
    }

    return 0;
}

void metodo0515(int n, double x){
    int exp = 2;
    printf("\n");
    printf("[1] ");
    for(int i = 0; i < n; i++){
        printf("[1/%.2lf^%d] ", x, exp);
        exp += 2;
    }
    printf("\n");
    printf("Resultado: [1] ");
    exp = 2;
    for(int i = 0; i < n; i++){
        double resultado;
        resultado = 1/(pow(x, exp));
        exp += 2;
        printf("[%lf] ", resultado);
    }
     printf("\n");
}

int funcao0515(){
    double x;
    int n;
    printf("Mostrar n quantidade em valores pares crescentes nos denominadores\n\n");
    printf("Digite a quantidade n: ");
    scanf("%d", &n);
    fflush(stdin);
    printf("Digite o valor de x: ");
    scanf("%lf", &x);
    fflush(stdin);

    if(n <= 0 || x == 0){
        printf("Valor invalido\n");
    } else {
        metodo0515(n, x);
    }

    return 0;
}

void somaMultiploDeTresENaoMultiploDeCinco(int n){
    int soma = 3;
    int resultado = 0;
    printf("\n");
    for(int i = 0; i < n; i++){
        int temp = soma;
        if(temp%3 == 0 && !(temp%5 == 0)){
            printf("%d ", soma);
            resultado += soma;
            soma += 3;
            if(i < n-1){
                printf("+ ");
            }
        } else {
            soma += 3;
            printf("%d ", soma);
            if(i < n-1){
                printf("+ ");
            }
            resultado += soma;
            soma += 3;
        }
    }
    printf("\n\nResultado total da soma = %d\n", resultado);
}

int metodo0516(){
    int n;
    printf("Calcular a soma dos primeiros valores positivos começando no valor 3, múltiplos de 3 e não múltiplos de 5\n\n");
    printf("Digite a quantidade n: ");
    scanf("%d", &n);
    fflush(stdin);

    if(n <= 0){
        printf("Valor invalido\n");
    } else {
        somaMultiploDeTresENaoMultiploDeCinco(n);
    }

    //return 0;

}

double calculaSomaDosInversosMultiplosDeSeisNaoMultiplosDeCinco(int n){
    double resultado = 0;
    double denominador = 6;
    printf("\n");
    for(int i = 0; i < n; i++){
        if((int)denominador%6 == 0 && !((int)denominador%5 == 0)){
            printf("1/%.0lf ", denominador);
            resultado += (1/denominador);
            denominador += 6;
            if(i < n-1){
                printf("+ ");
            }
        } else {
            denominador += 6;
            printf("1/%.0lf ", denominador);
            resultado += (1/denominador);
            denominador += 6;
            if(i < n-1){
                printf("+ ");
            }
        }
    }
    return resultado;
    //printf("\n\nResultado total da soma = %lf\n", resultado);
}


void metodo0517(){
    int n;
    printf("Calcular a soma dos inversos (1/x) dos primeiros valores positivos, comecando no valor 6, multiplos de 6 e nao multiplos de 5\n\n");
    printf("Digite a quantidade n: ");
    scanf("%d", &n);
    fflush(stdin);

    if(n <= 0){
        printf("Valor invalido\n");
    } else {
        double resultado = calculaSomaDosInversosMultiplosDeSeisNaoMultiplosDeCinco(n);
        printf("\nnResultado = %lf\n\n", resultado);
    }
}

int somaDaAdicao(int n){
    int cont = 1;
    int numero = 6;
    int resultado = 0;
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%d ", numero);
        resultado += numero;
        numero += cont;
        cont++;
        if(i < n-1){
            printf("+ ");
        }
    }
    return resultado;
}

void metodo0518(){
    int n;
    printf("Calcular a soma da adicao dos primeiros numeros naturais comecando no valor 6\n\n");
    printf("Digite a quantidade n: ");
    scanf("%d", &n);
    fflush(stdin);

    if(n <= 0){
        printf("Valor invalido\n");
    } else {
        int resultado = somaDaAdicao(n);
        printf("\n\nResultado = %d\n", resultado);
    }
}

int somaDosQuadradosDaAdicao(int n){
    int cont = 1;
    int numero = 6;
    int resultado = 0;
    printf("\n");
    for(int i = 0; i < n; i++){
        int temp = 0;
        temp = numero;
        temp *= temp;
        printf("%d ", temp);
        resultado += temp;
        numero += cont;
        cont++;
        if(i < n-1){
            printf("+ ");
        }
    }
    return resultado;

}

void metodo0519(){
    int n;
    printf("Soma dos quadrados da adicao dos numeros naturais comecando no valor 6\n\n");
    printf("Digite a quantidade n: ");
    scanf("%d", &n);
    fflush(stdin);

    if(n <= 0){
        printf("Valor invalido\n");
    } else {
        int resultado = somaDosQuadradosDaAdicao(n);
        printf("\n\nResultado = %d\n", resultado);
    }
}

double somaDoInversoDaAdicao(int n){
    int cont = 1;
    double numero = 6;
    double resultado = 0;
    int vetor[n];
    printf("\n");
    for(int i = 0; i < n; i++){
        vetor[i] = numero;
        resultado += 1/numero;
        numero += cont;
        cont++;
    }
    for(int i = n-1; i >= 0; i--){
        printf("1/%d ", vetor[i]);
        if(i != 0){
            printf("+ ");
        }
        }

    return resultado;
}

void metodo0520(){
    int n;
    printf("Soma dos inversos (1/x) das adicoes de numeros naturais terminando no valor 6\n\n");
    printf("Digite a quantidade n: ");
    scanf("%d", &n);
    fflush(stdin);

    if(n <= 0){
        printf("Valor invalido\n");
    } else {
        double resultado = somaDoInversoDaAdicao(n);
        printf("\n\nResultado = %lf\n", resultado);
    }
}

int fatorial(int n){
    int resultado = 1;
    for(int i = 1; i <= n; i++){
        resultado *= i;
    }
    return resultado;
}

void metodo05E1(){
    int n;
    printf("Fatorial\n\n");
    printf("Digite a quantidade n: ");
    scanf("%d", &n);
    fflush(stdin);

    if(n <= 0){
        printf("Valor invalido\n");
    } else {
        int resultado = fatorial(n);
        printf("\nFatorial = %d\n", resultado);
    }
}

int main(void){
    int opcao;
  do{
    printf("\n\nEscolha uma das opcoes abaixo: \n");
    printf("\n\t0: Sair");
    printf("\n\t1: Metodo0511");
    printf("\n\t2: Metodo0512");
    printf("\n\t3: Metodo0513");
    printf("\n\t4: Metodo0514");
    printf("\n\t5: Metodo0515");
    printf("\n\t6: Metodo0516");
    printf("\n\t7: Metodo0517");
    printf("\n\t8: Metodo0518");
    printf("\n\t9: Metodo0519");
    printf("\n\t10: Metodo0520");
    printf("\n\t11: Metodo05E1");
    //printf("\n\t12: Metodo04E2\n");
    scanf("%d", &opcao);

    switch(opcao){
        case 0:
            break;
        case 1:
            funcao0511();
            break;
        case 2:
            funcao0512();
            break;
        case 3:
            funcao0513();
            break;
        case 4:
            funcao0514();
            break;
        case 5:
            funcao0515();
            break;
        case 6:
            metodo0516();
            break;
        case 7:
            metodo0517();
            break;
        case 8:
            metodo0518();
            break;
        case 9:
            metodo0519();
            break;
        case 10:
            metodo0520();
            break;
        case 11:
            metodo05E1();
            break;
       /* case 12:
            metodo04E2();
            break;*/

        default:
            printf("Opcao invalida!\n");
            break;
    }

  } while(opcao != 0);

  return 0;
}
