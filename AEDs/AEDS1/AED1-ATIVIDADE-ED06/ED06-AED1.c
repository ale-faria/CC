/*
    AED1 - ED06 - 09/04/2024
    AUTORIA: ALESSANDRA FARIA RODRIGUES
    NUM. MATRICULA: 828333
*/


#include <stdio.h>
#include <string.h>
#include <math.h>



//PARA LIMPAR A ENTRADA DE DADOS
void limparBufferEntrada() {
    int c;
    // Lê todos os caracteres restantes até encontrar uma quebra de linha ou EOF
    while ((c = getchar()) != '\n' && c != EOF);
}


//printar n valores multiplos de 6 em ordem crescente usando recursao
void recursao0611(int n){
    if(n == 0){
        return;
    } else {
        //chama o metodo recursivo primeiro e printa depois
        //exemplo: o primeiro valor de n é 5 -> 5*6 = 30
        //exemplo: n = 1 -> 1*6 = 6
        //vai começar a printar do 6 até o 30
        recursao0611(n-1);
        printf("%d ", n * 6);
    }
}

void metodo0611(){
    int n;
    printf("QUANTIDADE n EM VALORES MULTIPLOS DE 6\n\n");
    printf("Digite a quantidade n: ");
    scanf("%d", &n);
    limparBufferEntrada();

    if(n <= 0){
        printf("Valor invalido\n");
    } else {
        printf("\n");
        recursao0611(n);
        printf("\n");
    }
}


//printar n valores multiplos de 6 em ordem DECRESCENTE usando recursao
void recursao0612(int n){
    if(n == 0){
        return;
    } else{
        printf("%d ", n * 6);
        recursao0612(n-1);
    }
}

void metodo0612(){
    int n;
    printf("QUANTIDADE n EM VALORES MULTIPLOS DE 6 EM ORDEM DECRESCENTE\n\n");
    printf("Digite a quantidade n: ");
    scanf("%d", &n);
    limparBufferEntrada();

    if(n <= 0){
        printf("Valor invalido\n");
    } else {
        printf("\n");
        recursao0612(n);
        printf("\n");
    }
}

void recursao0613(int n){
    if(n == 0){
        printf("1/1 ");
        return;
    } else {
        recursao0613(n-1);
        printf("1/%d ", n * 6);
    }
}

void metodo0613(){
    int n;
    printf("QUANTIDADE n EM VALORES MULTIPLOS DE 6 (INVERSO)\n\n");
    printf("Digite a quantidade n: ");
    scanf("%d", &n);
    limparBufferEntrada();

    if(n <= 0){
        printf("Valor invalido\n");
    } else {
        printf("\n");
        recursao0613(n-1);
        printf("\n");
    }
}

void recursao0614(int n){
    if(n == 0){
        printf("1/1 ");
        return;
    } else {
        printf("1/%d ", n * 6);
        recursao0614(n-1);
    }
}

void metodo0614(){
    int n;
    printf("QUANTIDADE n EM VALORES MULTIPLOS DE 6 (INVERSO DECRESCENTE)\n\n");
    printf("Digite a quantidade n: ");
    scanf("%d", &n);
    limparBufferEntrada();

    if(n <= 0){
        printf("Valor invalido\n");
    } else {
        printf("\n");
        recursao0614(n-1);
        printf("\n");
    }
}

//OK - TIRAR DUVIDA SOBRE ESSA AQUI
int recursao0615(int n, int cont, int numero, int resultado){
    if(n == 0){
        //printf("6 ");
        return resultado;
    } else {
        printf("%d ", numero);
        if(n > 1){
            printf("+ ");
        }
        resultado += numero;
        numero += cont;
        cont += 2;
        recursao0615(n-1, cont, numero, resultado);
    }
}

void metodo0615(){
    int n;
    printf("SOMA DA ADICAO DOS PARES POSITIVOS AO VALOR 6\n\n");
    printf("Digite a quantidade n: ");
    scanf("%d", &n);
    limparBufferEntrada();

    if(n <= 0){
        printf("Valor invalido\n");
    } else {
        printf("\n");
        int resultado = recursao0615(n, 2, 6, 0);
        printf("\nResultado da soma = %d \n", resultado);
    }
}

double recursao0616(int n, double resultado){
    if(n == 0){
        return resultado;
    } else {
        resultado += 1/(double)(n*6);
        printf("1/%d ", n*6);
        if(n > 1)
            printf("+ ");
        recursao0616(n-1, resultado);
    }
}

void metodo0616(){
    int n;
    printf("SOMA DOS INVERSOS (1/x) DOS MULTIPLOS DE 6\n\n");
    printf("Digite a quantidade n: ");
    scanf("%d", &n);
    limparBufferEntrada();

    if(n <= 0){
        printf("Valor invalido\n");
    } else {
        printf("\n");
        double resultado;
        resultado = recursao0616(n, 0.0);
        printf("\nResultado da soma = %lf \n", resultado);
    }
 //double resultado = 1/(double)(5*6);
 // printf("%lf ", resultado);
}

void recursao0617(char * palavra, int tamanho){
    if(tamanho == 0){
        return;
    } else {
        recursao0617(palavra, tamanho-1);
        printf("%c \n", palavra[tamanho-1]);
    }
}

void metodo0617(){
    char palavra[80];
    int tamanho;
    printf("MOSTRAR CADA SIMBOLO EM UMA LINHA\n\n");
    printf("Digite a palavra: ");
    scanf("%s", palavra);
    limparBufferEntrada();

    tamanho = strlen(palavra);
    recursao0617(palavra, tamanho);
}

int recursao0618(char * palavra, int tamanho){
    if(tamanho == 0){
        return 0;
    } else {
        char temp = palavra[tamanho - 1];
        if(temp >= '0' && temp <= '9'){
            if((int)temp%2 == 0){
              return 1 + recursao0618(palavra, tamanho-1);
            } else {
              return recursao0618(palavra, tamanho-1);
            }
        } else {
            return recursao0618(palavra, tamanho-1);
        }
    }
}

void metodo0618(){
    char palavra[80];
    int tamanho;
    printf("CONTAR PARES EM UMA CADEIA DE CARACTERES\n\n");
    printf("Digite a palavra: ");
    scanf("%s", palavra);
    limparBufferEntrada();
  //printf("palavra = %s", palavra);

    tamanho = strlen(palavra);
    int resultado = recursao0618(palavra, tamanho);
    printf("\nQuantidade de pares = %d \n", resultado);
}

int recursao0619(char * palavra, int tamanho){
  if(tamanho == 0){
    return 0;
  } else {
    char temp = palavra[tamanho-1];
    if(temp >= 'A' && temp <= 'L'){
      return 1 + recursao0619(palavra, tamanho-1);
    } else {
      return recursao0619(palavra, tamanho-1);
    }
  }
}

void metodo0619(){
  char palavra[80];
  int tamanho;
  printf("QUANTIDADE DE MAIUSCULAS MENORES QUE 'L'\n\n");
  printf("Digite a palavra: ");
  scanf("%s", palavra);
  limparBufferEntrada();

  tamanho = strlen(palavra);
  int resultado = recursao0619(palavra, tamanho);
  printf("\nQuantidade de maiusculas menores que 'L' = %d \n", resultado);
}

int fibo(int n){
  if(n <= 1)
    return n;

  return fibo(n-1) + fibo(n-2);
}

int fiboPares(int n, int termoAtual, int soma){
    int fib = fibo(termoAtual);
    if(fib%2 == 0){
        printf("%d ", fib);
        soma += fib;
        n--;
    }

    if (n > 0)
        fiboPares(n, termoAtual + 1, soma);
    else
        return soma;
}

void metodo0620(){
  int n;
  int resultado;
  printf("SOMA DOS n TERMOS PARES DA SERIE DE FIBBONACCI\n\n");
  printf("Digite a quantidade n: ");
  scanf("%d", &n);
  limparBufferEntrada();
  int vetor[n];

  printf("\n\nSequencia de Fibonacci(pares): ");
  if(n <= 0){
    printf("Valor invalido\n");
  } else {
    //mostrando a sequencia de fibonacci
    int resultado = fiboPares(n, 1, 0);
    printf("\nResultado da soma = %d \n", resultado);
    }

}

double funcao06E1(int n, int x, int exp, double soma){
    if(n == 0){
        return soma;
    } else {
        double calc;
        calc = pow(x, exp);
        soma += calc;
        funcao06E1(n-1, x, exp+2, soma);
    }
}

void metodo06E1(){
    int x, n;
    printf("Digite o valor de x: ");
    scanf("%d", &x);
    getchar();
    printf("Digite a quantidade n: ");
    scanf("%d", &n);
    getchar();

    double resultado = funcao06E1(n, x, 3, 1);
    printf("Resultado = %lf ", resultado);
}

int fatorial(int numero){
    int fatorial = 1;
    for(int i = 1; i <= numero; i++){
        fatorial *= i;
    }
    return fatorial;
}

double funcao06E2(int n, int impar, int par, double soma){
    if(n == 0){
        return soma;
    } else {
        int denominador = fatorial(par);
        //printf("%d\n", denominador);
        soma += (impar/(double)denominador);
        funcao06E2(n-1, impar+2, par+2, soma);
    }
}

void metodo06E2(){
    int n;
    printf("Digite a quantidade n: ");
    scanf("%d", &n);
    getchar();

    double resultado = funcao06E2(n, 3, 2, 1);
    printf("Resultado = %lf", resultado);
}
int main(void){
int opcao;
  do{
    printf("\n\nEscolha uma das opcoes abaixo: \n");
    printf("\n\t0: Sair");
    printf("\n\t1: Metodo0611");
    printf("\n\t2: Metodo0612");
    printf("\n\t3: Metodo0613");
    printf("\n\t4: Metodo0614");
    printf("\n\t5: Metodo0615");
    printf("\n\t6: Metodo0616");
    printf("\n\t7: Metodo0617");
    printf("\n\t8: Metodo0618");
    printf("\n\t9: Metodo0619");
    printf("\n\t10: Metodo0620");
    printf("\n\t11: Metodo06E1");
    printf("\n\t12: Metodo06E2\n");
    scanf("%d", &opcao);
    getchar();

    switch(opcao){
        case 0:
            break;
        case 1:
            metodo0611();
            break;
        case 2:
            metodo0612();
            break;
        case 3:
            metodo0613();
            break;
        case 4:
            metodo0614();
            break;
        case 5:
            metodo0615();
            break;
        case 6:
            metodo0616();
            break;
        case 7:
            metodo0617();
            break;
        case 8:
            metodo0618();
            break;
        case 9:
            metodo0619();
            break;
        case 10:
            metodo0620();
            break;
        case 11:
            metodo06E1();
            break;
        case 12:
            metodo06E2();
            break;

        default:
            printf("Opcao invalida!\n");
            break;
    }

  } while(opcao != 0);

  return 0;
}

//fib(n) = 1 se n = 1,2
//fib(n) = fib(n-1) + fib(n-2), se n > 2
