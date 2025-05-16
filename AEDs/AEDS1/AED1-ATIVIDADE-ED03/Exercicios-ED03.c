/*
    AED1 - ED03
    AUTORIA: ALESSANDRA FARIA RODRIGUES
    NUM. MATRICULA: 828333
*/
#include <stdio.h>
#include <string.h>

void mostrarMaiusculas() { // metodo0311
  char palavra[50];
  printf("MOSTRAR LETRAS MAIUSCULAS \n");
  printf("Digite uma palavra: ");
  scanf("%s", palavra);
  printf("Letras maiusculas na palavra: ");
  for (int i = 0; i < strlen(palavra); i++) {
    if (palavra[i] >= 'A' && palavra[i] <= 'Z') {
      printf("%c ", palavra[i]);
    }
  }
  printf("\n");
}

void mostraContaMaiusculas() { // metodo0312
  int cont = 0;
  char palavra[50];
  printf("MOSTRAR E CONTAR LETRAS MAIUSCULAS \n");
  printf("Digite uma palavra: ");
  scanf("%s", palavra);
  printf("Letras maiusculas na palavra: ");
  for (int i = 0; i < strlen(palavra); i++) {
    if (palavra[i] >= 'A' && palavra[i] <= 'Z') {
      printf("%c ", palavra[i]);
      cont++;
    }
  }
  printf("\nA quantidade de letras maiusculas e: %d", cont);
}

void mostraContaMaiusculasFim() { // metodo0313
  int cont = 0;
  char palavra[50];
  printf(
      "MOSTRAR E CONTAR LETRAS MAIUSCULAS(PERCORRENDO DO FIM PARA INICIO \n");
  printf("Digite uma palavra: ");
  scanf("%s", palavra);
  printf("Letras maiusculas na palavra: ");
  for (int i = strlen(palavra) - 1; i >= 0; i--) {
    if (palavra[i] >= 'A' && palavra[i] <= 'Z') {
      printf("%c ", palavra[i]);
      cont++;
    }
  }
  printf("O numero total de letras maiusculas na palavra e = %d", cont);
  // printf
}

void metodo0314() {
  int contMaiuscula = 0, contMinuscula = 0;
  char palavra[50];
  printf("MOSTRAR E CONTAR LETRAS MAIUSCULAS, MINUSCULAS\n");
  printf("Digite uma palavra: ");
  scanf("%s", palavra);

  printf("Letras maiusculas na palavra: ");
  for (int i = 0; i < strlen(palavra); i++) {
    if (palavra[i] >= 'A' && palavra[i] <= 'Z') {
      printf("%c ", palavra[i]);
      contMaiuscula++;
    }
  }
  printf("\nQuantidade total de letras maiusculas na palavra = %d",
         contMaiuscula);

  printf("\n\nLetras minusculas na palavra: ");
  for (int i = 0; i < strlen(palavra); i++) {
    if (palavra[i] >= 'a' && palavra[i] <= 'z') {
      printf("%c ", palavra[i]);
      contMinuscula++;
    }
  }
  printf("\nQuantidade total de letras minusculas na palavra = %d",
         contMinuscula);
}

void metodo0315(){
    int cont = 0;
    char palavra[50];
    printf("CONTAR E MOSTRAR OS DIGITOS(NUMEROS)\n");
    printf("Digite a palavra: ");
    scanf("%s", palavra);

    printf("Digitos na palavra: ");
    for(int i = strlen(palavra) - 1 ; i >= 0; i--){ //percorrendo do fim para inicio
        if(palavra[i] >= '0' && palavra[i] <= '9'){
            printf("%c ", palavra[i]);
            cont++;
        }
    }
    printf("\nA quantidade total de digitos na palavra = %d ", cont);

}

void metodo0316(){
    int cont = 0;
    char palavra[50];
    printf("CONTAR E MOSTRAR TUDO OQUE NAO FOR DIGITO(NUMERO) NEM LETRA\n");
    printf("Digite a palavra: ");
    scanf("%s", palavra);

    printf("O que nao e digito nem letra: ");
    for(int i = 0; i < strlen(palavra); i++){
        if(!((palavra[i] >= 'A' && palavra[i] <= 'Z') || (palavra[i] >='a' && palavra[i] <= 'z') || (palavra[i] >= '0' && palavra[i] <='9'))){
            printf("%c ", palavra[i]);
            cont++;
        }
    }
    printf("\nQuantidade total = %d", cont);
}

void metodo0317(){
    int a, b, n, cont = 0;
    printf("NUMEROS MULTIPLOS DE 6 QUE PERTENCAM AO INTERVALO [a,b]\n");
    printf("Digite o valor de a: ");
    scanf("%d", &a);
    printf("Digite o valor de b: ");
    scanf("%d", &b);
    printf("Digite a quantidade n: ");
    scanf("%d", &n);
    int vetor[n];

    //leitura dos valores
    for(int i = 0; i < n; i++){
        printf("Digite o valor %d: ", i+1);
        scanf("%d", &vetor[i]);
    }

    //verificando os multiplos de 6 que pertencem ao intervalo
    printf("Os numeros multiplos de 6 que pertencem ao intervalo [%d,%d] sao: ", a, b);
    for(int i = 0; i < n; i++){
        if((vetor[i] >= a && vetor[i] <= b) && vetor[i]%6 == 0){
            printf("%d ", vetor[i]);
            cont++;
        }
    }
    printf("\nO total de numeros que se enquadram na condicao e = %d", cont);
}

void metodo0318(){
    int a, b, n, cont = 0;
    printf("NUMEROS MULTIPLOS DE 4 E QUE NAO SAO MULTIPLOS DE 5 QUE PERTENCAM AO INTERVALO [a,b]\n");
    printf("Digite o valor de a: ");
    scanf("%d", &a);
    printf("Digite o valor de b: ");
    scanf("%d", &b);
    printf("Digite a quantidade n: ");
    scanf("%d", &n);
    int vetor[n];

    //leitura dos valores
    for(int i = 0; i < n; i++){
        printf("Digite o valor %d: ", i+1);
        scanf("%d", &vetor[i]);
    }

    //verificando os multiplos de 6 que pertencem ao intervalo
    printf("Os numeros multiplos de 4 e que nao sao multiplos de 5 que pertencem ao intervalo [%d,%d] sao: ", a, b);
    for(int i = 0; i < n; i++){
        if(vetor[i]%4 == 0 && vetor[i]%5 != 0){
            printf("%d ", vetor[i]);
            cont++;
        }
    }
    printf("\nO total de numeros que se enquadram na condicao e = %d", cont);
}

void metodo0319(){
    int a, b, n, cont = 0;
    printf("NUMEROS REAIS PERTENCENTES AO INTERVALO (a,b) CUJAS PARTES INTERIAS SAO PARES\n");
    do{
        printf("Digite o valor de a: ");
        scanf("%d", &a);
        printf("Digite o valor de b: ");
        scanf("%d", &b);
    } while (a > b || a == b);
    printf("Digite a quantidade n: ");
    scanf("%d", &n);
    double vetor[n];

    //leitura dos valores
    for(int i = 0; i < n; i++){
        printf("Digite o valor %d: ", i+1);
        scanf("%lf", &vetor[i]);
    }

    printf("Os numeros pares (parte inteira) que pertencem ao intervalo [%d,%d] sao: ", a, b);
    for(int i = 0; i < n; i++){
        if((int)vetor[i]%2 == 0 && vetor[i] > a && vetor[i] < b){
            printf("%lf  ", vetor[i]);
            cont++;
        }
    }
    printf("\nO total de numeros que se enquadram na condicao e = %d", cont);
}

void metodo0320(){
int n, cont = 0;
double a, b;
    printf("NUMEROS REAIS PERTENCENTES AO INTERVALO (a,b) \n");
    do{
        printf("Digite o valor de a ( 0 < a < 1): ");
        scanf("%lf", &a);
        printf("Digite o valor de b ( 0 < b < 1): ");
        scanf("%lf", &b);
    }
    while((a < 0 || a > 1) || (b < 0 || b > 1) || (a > b) || (a == b));

    printf("Digite a quantidade n: ");
    scanf("%d", &n);
    double vetor[n];

    //leitura dos valores
    for(int i = 0; i < n; i++){
        printf("Digite o valor %d: ", i+1);
        scanf("%lf", &vetor[i]);
    }

    //verificacao da parte fracionaria
    printf("Os numeros cujas parte fracionaria nao esta entre o intervalo (%lf,%lf) sao: \n", a, b);
    for(int i = 0; i < n; i++){
        double vetorTemp = vetor[i] - ((int)vetor[i]);
        //printf("Parte fracionaria: %lf \n", vetor[i]);
        if (vetorTemp <= a || vetorTemp >= b){
            printf("\t%.2lf \n", vetor[i]);
        }
    }
}


int main(void) {
    int opcao;
  do{
    printf("\n\nEscolha uma das opcoes abaixo: \n");
    printf("\n\t0: Sair");
    printf("\n\t1: Procedimento0311");
    printf("\n\t2: Procedimento0312");
    printf("\n\t3: Procedimento0313");
    printf("\n\t4: Procedimento0314");
    printf("\n\t5: Procedimento0315");
    printf("\n\t6: Procedimento0316");
    printf("\n\t7: Procedimento0317");
    printf("\n\t8: Procedimento0318");
    printf("\n\t9: Procedimento0319");
    printf("\n\t10: Procedimento0320\n");
    scanf("%d", &opcao);

    switch(opcao){
        case 0:
            break;
        case 1:
            mostrarMaiusculas();
            break;
        case 2:
            mostraContaMaiusculas();
            break;
        case 3:
            mostraContaMaiusculasFim();
            break;
        case 4:
            metodo0314();
            break;
        case 5:
            metodo0315();
            break;
        case 6:
            metodo0316();
            break;
        case 7:
            metodo0317();
            break;
        case 8:
            metodo0318();
            break;
        case 9:
            metodo0319();
            break;
        case 10:
            metodo0320();
            break;

        default:
            printf("Opcao invalida!\n");
            break;
    }

  } while(opcao != 0);

  return 0;
}
