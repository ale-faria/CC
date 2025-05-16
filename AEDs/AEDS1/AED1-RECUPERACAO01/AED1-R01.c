/*
    AED1 - R01 - 30/04/2024
    AUTORIA: ALESSANDRA FARIA RODRIGUES
    NUM. MATRICULA: 828333
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int somaDosDivisoresImpares(int numero){
  int soma = 0;
  for(int i = 1; i <= numero; i++){
    if(numero%i == 0){ //divisores
      if(i%2 != 0){ //impares
      //printf("%d ", i);
      soma = soma + i;
      }
    }
  }
  return soma;
}

void exercicio01(){
  int n, numero;
  printf("EXERCICIO 01\n\n");
  printf("Digite a quantidade: ");
  scanf("%d", &n);
  getchar();
  if(n > 0){
    for(int i = 0; i < n; i++){
      printf("\nDigite o valor %d: ", i+1);
      scanf("%d", &numero);
      getchar();
      int resultado = somaDosDivisoresImpares(numero);
      printf("Resultado da soma dos divisores impares do numero %d = %d \n", numero, resultado);
    }
  } else {
    printf("Valor invalido...\n");
  }
    printf("\nAperte enter para finalizar...");
    getchar();
}

int primo(int numero){
  int contPrimo = 0;
  if(numero > 2){
    for(int i = 2; i < numero; i++){
      if(numero%i == 0){
        contPrimo++;
      }
    }
  }
  return contPrimo;

}

void exercicio02(){
  int n, numero;
  printf("EXERCICIO 02\n\n");
  printf("Digite a quantidade: ");
  scanf("%d", &n);
  getchar();
  if(n > 0){
    for(int i = 0; i < n; i++){
      printf("Digite o valor %d: ", i+1);
      scanf("%d", &numero);
      getchar();
      if(numero > 1){
          int resultado = primo(numero);
          if(resultado == 0){
            printf("E primo\n\n");
          } else {
            printf("NAO e primo\n\n");
      }
      } else {
        printf("Nao existe primo de numeros negativos, zero ou um\n\n");
      }
    }
  } else {
    printf("Valor invalido...\n");
  }
    printf("\nAperte enter para finalizar...");
    getchar();
}

// Função para verificar se um caractere é um operador lógico
int verficaOperadorLogico(char c){
    switch(c) {
        case '&':
        case '|':
        case '!':
            return 1;
        default:
            return 0;
    }
}

// Função para verificar se um caractere é um operador aritmético
int verificaOperadorAritmetico(char c) {
    switch(c) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            return 1;
        default:
            return 0;
    }
}

// Função para verificar se um caractere é um operador relacional
int verificaOperadorRelacional(char c) {
    switch(c) {
        case '>':
        case '<':
        case '=':
            return 1;
        default:
            return 0;
    }
}

// Função para verificar se um caractere é um separador
int verificaSeparador(char c) {
    switch(c) {
        case ' ':
        case '.':
        case ',':
        case ';':
        case ':':
        case '_':
            return 1;
        default:
            return 0;
    }
}

void exercicio03(){
    char string[80];
    printf("EXERCICIO 03\n\n");
    printf("Digite a cadeia de caracteres: ");
    fgets(string, sizeof(string), stdin);

    for(int i = 0; string[i] != '\0' && string[i] != '\n'; i++){
        char c = string[i];
        if(isalpha(c)){
            printf("%c e uma letra\n", c);
        } else if(isdigit(c)) {
            printf("%c e um digito\n", c);
        } else if(verficaOperadorLogico(c)) {
            printf("%c e um operador logico\n", c);
        } else if(verificaOperadorAritmetico(c)) {
            printf("%c e um operador aritmetico\n", c);
        } else if(verificaOperadorRelacional(c)) {
            printf("%c e um operador relacional\n", c);
        } else if(verificaSeparador(c)) {
            printf("%c e um separador\n", c);
        } else {
            printf("%c e outro simbolo qualquer\n", c);
        }
    }
    printf("\nAperte enter para finalizar...");
    getchar();
    }


void exercicio04(){
    char s[80];
    int contMaiuscula = 0, contMinuscula = 0, contDigito = 0, contOperador = 0, contSeparador = 0;
    printf("EXERCICIO 04\n\n");
    printf("Digite a cadeia de caracteres: ");
    fgets(s, sizeof(s), stdin);

    for(int i = 0; s[i] != '\0' && s[i] != '\n'; i++){
        char c = s[i];
        if(isupper(c)){
            printf("%c e uma letra maiuscula\n", c);
            contMaiuscula++;
        } else if(islower(c)){
            printf("%c e uma letra minuscula\n", c);
            contMinuscula++;
        } else if(isdigit(c)) {
            printf("%c e um digito\n", c);
            contDigito++;
        } else if(verficaOperadorLogico(c)) {
            printf("%c e um operador logico\n", c);
            contOperador++;
        } else if(verificaOperadorAritmetico(c)) {
            printf("%c e um operador aritmetico\n", c);
            contOperador++;
        } else if(verificaOperadorRelacional(c)) {
            printf("%c e um operador relacional\n", c);
            contOperador++;
        } else if(verificaSeparador(c)) {
            printf("%c e um separador\n", c);
            contSeparador++;
        } else {
            printf("%c e outro simbolo qualquer\n", c);
        }
    }
    printf("Quantidade de maiusculas = %d \nQuantidade de minusculas = %d \nQuantidade de digitos = %d \nQuantidade de operadores = %d \nQuantidade de separadores = %d\n", contMaiuscula, contMinuscula, contDigito, contOperador, contSeparador);
    printf("\nAperte enter para finalizar...");
    getchar();

}

double maiorNum(double a, double b, double c){
    double maior = a;

    if (b > maior) {
        maior = b;
    }

    if (c > maior) {
        maior = c;
    }

    return maior;
}

double menorNum(double a, double b, double c){
    double menor = a;

    if (b < menor) {
        menor = b;
    }

    if (c < menor) {
        menor = c;
    }

    return menor;
}

void exercicio05(){
    int n;
    double x, mediaMenor = 0.0, mediaMaior = 0.0, mediaEntre = 0.0;
    int contMenor = 0, contMaior = 0, contEntre = 0;

    printf("EXERCICIO 05\n\n");
    printf("Digite a quantidade: ");
    scanf("%d", &n);
    getchar();

    if(n <= 0)
        return;

    double vetor[n];

    //recebendo os valores
    for(int i = 0; i < n; i++){
        double y;
        printf("Digite um numero: ");
        scanf("%lf", &y);
        vetor[i] = y;
    }

//calculando as medias em cada intervalo
    for(int i = 0; i < n; i++){
        double y = vetor[i];
        if(y < -17.25){
            mediaMenor += y;
            contMenor++;
        } else if(y > 93.75){
            mediaMaior += y;
            contMaior++;
        } else if(y >= -17.25 && y <= 93.75){
            mediaEntre += y;
            contEntre++;
        }
    }

    mediaMenor = (contMenor != 0) ? mediaMenor / contMenor : 0;
    mediaMaior = (contMaior != 0) ? mediaMaior / contMaior : 0;
    mediaEntre = (contEntre != 0) ? mediaEntre / contEntre : 0;

    printf("Media dos valores menores que -17.25 = %lf\n", mediaMenor);
    printf("Media dos valores maiores que 93.75 = %lf\n", mediaMaior);
    printf("Media dos valores entre -17.25 e 93.75 = %lf\n", mediaEntre);

    double resultado = maiorNum(mediaMenor, mediaMaior, mediaEntre);
    printf("A maior media e = %lf\n", resultado);

    printf("\nAperte enter para finalizar...");
    getchar();

}

int verificaIntervalo(int x, int a, int b){
    if(x > a && x < b){
        return 1; //esta no intervalo definido
    } else {
        return 0; //NAO esta no intervalo
    }
}

double somaDosCubosImpares(int x){
    double soma;
    soma = 1 / pow(x, 3);
    return soma;
}

void exercicio06(){
    int a, b, x;
    double resultado = 0;
    printf("EXERCICIO 06\n\n");

    do{
        printf("Digite o valor de a: ");
        scanf("%d", &a);
        getchar();
        printf("Digite o valor de b: ");
        scanf("%d", &b);
        getchar();
    } while (a > b);

    printf("Digite um valor: ");
    scanf("%d", &x);
    getchar();

    while(x != -1){
        int intervalo = verificaIntervalo(x, a, b);
        if(intervalo == 1){
            if(x%2 != 0 && x != 0){ //impar e diferente de zero
                double soma = somaDosCubosImpares(x);
                resultado += soma;
            }
        }
    printf("Digite um valor: ");
    scanf("%d", &x);
    getchar();
    }
    printf("Resultado da soma = %lf\n", resultado);
    printf("\nAperte enter para finalizar...");
    getchar();
}

void exercicio07(){
    printf("EXERCICIO 07\n\n");
    int a, b, x;
    int contDentro = 0, contFora = 0;

    do{
        printf("Digite o valor de a: ");
        scanf("%d", &a);
        getchar();
        printf("Digite o valor de b: ");
        scanf("%d", &b);
        getchar();
    } while (a > b);

    printf("Digite um valor: ");
    scanf("%d", &x);
    getchar();

    while(x != 0){
        int intervalo = verificaIntervalo(x, a, b);
        if(intervalo == 1){
            contDentro++;
        } else {
            contFora++;
        }
        printf("Digite um valor: ");
        scanf("%d", &x);
        getchar();
    }
    printf("Quantidade de valores dentro do intervalo = %d\n", contDentro);
    printf("Quantidade de valores fora do intervalo = %d\n", contFora);
    printf("\nAperte enter para finalizar...");
    getchar();
}

int crescente(int x, int y, int z){
    if(x < y && x < z && y < z){
        return 1; //esta em ordem crescente
    } else {
        return 0; //NAO esta em ordem crescente
    }
}

int decrescente(int x, int y, int z){
    if(x > y && x > z && y > z){
        return 1; //esta em ordem decrescente
    } else {
        return 0; //NAO esta em ordem decrescente
    }

}

void exercicio08(){
    int x, y, z;
    printf("EXERCICIO 08\n\n");
    printf("Digite o primeiro numero: ");
    scanf("%d", &x);
    getchar();

    printf("Digite o segundo numero: ");
    scanf("%d", &y);
    getchar();

    printf("Digite o terceiro numero: ");
    scanf("%d", &z);
    getchar();

    if(crescente(x,y,z)){
        printf("Esta em ordem crescente\n");
    } else if(decrescente(x,y,z)){
        printf("Esta em ordem decrescente\n");
    } else {
        printf("Nao esta em nenhuma ordem\n");
        int maior = maiorNum(x,y,z);
        int menor = menorNum(x,y,z);
        printf("Numero maior = %d \nNumero menor = %d\n", maior, menor);

    }
    printf("\nAperte enter para finalizar...");
    getchar();
 }

 int sucessor(char x, char y) {
     if(x < y){
        return 1;
     } else {
        return 0;
     }
}


int crescenteChar(char x, char y, char z) {
    return sucessor(x, y) && sucessor(y, z);
}

int decrescenteChar(char x, char y, char z) {
    return sucessor(z, y) && sucessor(y, x);
}


 void exercicio09(){
    char x, y, z;
    printf("EXERCICIO 09\n\n");
    printf("Digite o primeiro caractere: ");
    scanf("%c", &x);
    getchar();

    printf("Digite o segundo caractere: ");
    scanf("%c", &y);
    getchar();

    printf("Digite o terceiro caractere: ");
    scanf("%c", &z);
    getchar();

    if(crescenteChar(x,y,z)){
        printf("Esta em ordem crescente\n");
    } else if(decrescenteChar(x,y,z)){
        printf("Esta em ordem decrescente\n");
    } else {
        printf("Nao esta em nenhuma ordem\n");
    }

    printf("\nAperte enter para finalizar...");
    getchar();

 }

 void exercicio10(){
    char s1[80], s2[80], s3[80];
    printf("EXERCICIO 10\n\n");
    printf("Digite a cadeia de caractere: ");
    scanf("%s", &s1);
    getchar;

    printf("Digite a cadeia de caractere: ");
    scanf("%s", &s2);
    getchar;

    printf("Digite a cadeia de caractere: ");
    scanf("%s", &s3);
    getchar;

    int resultado1 = strcmp(s1, s2);
    int resultado2 = strcmp(s2, s3);

    if(resultado1 < 0 && resultado2 < 0){
        printf("As cadeias estao em ordem crescente\n");
    } else if(resultado1 > 0 && resultado2 > 0){
        printf("As cadeias estao em ordem decrescente\n");
    } else {
        printf("Nao estao em nenhuma ordem\n");
        if (resultado1 < 0 && resultado2 > 0) {
            printf("A menor cadeia e: %s\n", s1);
            printf("A maior cadeia e: %s\n", s3);
        } else if (resultado1 > 0 && resultado2 < 0) {
            printf("A menor cadeia e: %s\n", s3);
            printf("A maior cadeia e: %s\n", s1);
        } else if (resultado1 == 0 && resultado2 != 0) {
            printf("A menor cadeia e: %s\n", s1);
            printf("A maior cadeia e: %s\n", s3);
        } else if (resultado1 != 0 && resultado2 == 0) {
            printf("A menor cadeia e: %s\n", s3);
            printf("A maior cadeia e: %s\n", s1);
        } else if (resultado1 == 0 && resultado2 == 0) {
            printf("As três cadeias são iguais.\n");
        }
    }

 }

int main(void) {
 int opcao;
  do{
    printf("\n\nEscolha uma das opcoes abaixo: \n");
    printf("\n\t0: Sair");
    printf("\n\t1: Exercicio 01");
    printf("\n\t2: Exercicio 02");
    printf("\n\t3: Exercicio 03");
    printf("\n\t4: Exercicio 04");
    printf("\n\t5: Exercicio 05");
    printf("\n\t6: Exercicio 06");
    printf("\n\t7: Exercicio 07");
    printf("\n\t8: Exercicio 08");
    printf("\n\t9: Exercicio 09");
    printf("\n\t10: Exercicio 10");
    scanf("%d", &opcao);
    getchar();

    switch(opcao){
        case 0:
            break;
        case 1:
            exercicio01();
            break;
        case 2:
            exercicio02();
            break;
        case 3:
            exercicio03();
            break;
        case 4:
            exercicio04();
            break;
        case 5:
            exercicio05();
            break;
        case 6:
            exercicio06();
            break;
        case 7:
            exercicio07();
            break;
        case 8:
            exercicio08();
            break;
        case 9:
            exercicio09();
            break;
        case 10:
            exercicio10();
            break;


        default:
            printf("Opcao invalida!\n");
            break;
    }

  } while(opcao != 0);



  return 0;
}
