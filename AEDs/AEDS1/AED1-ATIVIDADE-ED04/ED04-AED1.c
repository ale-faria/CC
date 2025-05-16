
/*
    AED1 - ED04 - 20/03/2024
    AUTORIA: ALESSANDRA FARIA RODRIGUES
    NUM. MATRICULA: 828333
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void metodo0411() {
  double a, b;
  int n;
  int contDentro = 0, contFora = 0;
  printf("VALORES DENTRO E FORA DO INTERVALO FECHADO [a,b]\n");
  printf("Digite o valor de a: ");
  scanf("%lf", &a);
  getchar();
  printf("Digite o valor de b: ");
  scanf("%lf", &b);
  getchar();
  printf("Digite a quantidade n: ");
  scanf("%d", &n);
  double vetor[n];

  // leitura dos valores
  for (int i = 0; i < n; i++) {
    printf("Digite o valor %d: ", i + 1);
    scanf("%lf", &vetor[i]);
    getchar();
  }

  // verificando condicoes
  for (int i = 0; i < n; i++) {
    if (vetor[i] >= a && vetor[i] <= b) {
      contDentro++;
    } else {
      contFora++;
    }
  }
  printf("Quantidade de valores que estao dentro do intervalo [%.2lf,%.2lf]: "
         "%d \n",
         a, b, contDentro);
  printf("Quantidade de valores que estao fora do intervalo [%.2lf,%.2lf]: %d",
         a, b, contFora);
}

//funcao que retorna apenas as letras maiusculas da palavra
char* apenasMaiuscula(char *palavra) {
  int tamanho = strlen(palavra);
  char* maiusculas;
  maiusculas = (char*)malloc(tamanho+1);
  int y = 0;
  for (int i = 0; i < tamanho; i++) {
    if (palavra[i] >= 'A' && palavra[i] <= 'Z') {
      maiusculas[y] = palavra[i];
      y++;
    }
  }
      maiusculas[y] = '\0';
  return (maiusculas);
}

void metodo0412() {
  char palavra[50];
  char* resultado;
  int cont = 0;
  printf("LETRAS MAIORES QUE 'L'\n");
  printf("Digite a palavra: ");
  scanf("%s", palavra);
  fflush(stdin);
  resultado = apenasMaiuscula(palavra);
  //printf("resultado: %s", resultado);
  printf("\nLetras maiusculas maiores que 'L': ");
  //printf("strlen resultado = %d", strlen(resultado));
  for(int i = 0; i < strlen(resultado); i++){
      if(resultado[i] > 'L' && resultado[i] <= 'Z'){
        printf("%c ", resultado[i]);
        cont++;
      }
 }
  printf("\nQuantidade total = %d\n", cont);
}

//funcao que conta as letras maiusculas maiores que L e retorna um inteiro
int contaMaiusculaMaiorL(char *palavra){
    int cont = 0;
    for(int i = 0; i < strlen(palavra); i++){
        if(palavra[i] > 'L' && palavra[i] <= 'Z'){
            cont++;
        }
    }
    return cont;
}

//funcao que retorna as letras maiusculas maiores que L
char* mostraMaiusculaMaiorL(char * palavra){
    char *resultado;
    int y = 0;
    int tamanho = strlen(palavra);
    resultado = (char*)malloc(tamanho+1);
    for(int i = 0; i < tamanho; i++){
        if(palavra[i] > 'L' && palavra[i] <= 'Z'){
            resultado[y] = palavra[i];
            y++;
        }
    }
    resultado[y] = '\0';
    return (resultado);
}
void metodo0413(){
    char palavra[50];
    int resultado;
    printf("QUANTIDADE DE LETRAS MAIORES QUE 'L'\n");
    printf("Digite a palavra: ");
    scanf("%s", palavra);
    fflush(stdin);
    resultado = contaMaiusculaMaiorL(palavra);
    printf("A quantidade de letras maiores que 'L' na palavra: %d", resultado);
}

void metodo0414(){
    char palavra[50];
    printf("Digite a palavra: ");
    scanf("%s", palavra);
    fflush(stdin);
    char* resultado = apenasMaiuscula(palavra);
    printf("Letras maiusculas na palavra: %s", resultado);
    resultado = mostraMaiusculaMaiorL(palavra);
    printf("\nLetras maiusculas maiores que 'L' na palavra: %s", resultado);
}

//funcao que retorna a quantidade de letras maiusculas menores q 'L'
int contaMaiusculaMenorL(char * palavra){
    int cont = 0;
    for(int i = 0; i < strlen(palavra); i++){
        if(palavra[i] >= 'A' && palavra[i] < 'L'){
            cont++;
        }
    }
    return cont;
}

//funcao que retorna a quantidade de letras minusculas menores q 'l'
int contaMinusculaMenorL(char * palavra){
    int cont = 0;
    for(int i = 0; i < strlen(palavra); i++){
        if(palavra[i] >= 'a' && palavra[i] < 'l'){
            cont++;
        }
    }
    return cont;
}

void metodo0415(){
    char palavra[50];
    int resultado;
    printf("Quantidade de letras (maiúsculas e minúsculas) menores que 'L' e 'l'\n\n");
    printf("Digite a palavra: ");
    scanf("%s", palavra);
    fflush(stdin);
    resultado = contaMaiusculaMenorL(palavra);
    printf("\nA quantidade de letras maiusculas menores que 'L' = %d\n", resultado);
    resultado = contaMinusculaMenorL(palavra);
    printf("A quantidade de letras minusculas menores que 'l' = %d\n", resultado);
}

//funcao que retorna as letras maiusculas menores que 'L'
char* mostraMaiusculaMenorL(char * palavra){
    int tamanho = strlen(palavra);
    char * resultado;
    resultado = (char*)malloc(tamanho+1);
    int y = 0;
    for(int i = 0; i < tamanho; i++){
        if(palavra[i] >= 'A' && palavra[i] < 'L'){
            resultado[y] = palavra[i];
            y++;
        }
    }
    resultado[y] = '\0';
    return resultado;
}

//funcao que retorna as letras minusculas menores que 'l'
char* mostraMinusculaMenorL(char * palavra){
    int tamanho = strlen(palavra);
    char * resultado;
    resultado = (char*)malloc(tamanho+1);
    int y = 0;
    for(int i = 0; i < tamanho; i++){
        if(palavra[i] >= 'a' && palavra[i] < 'l'){
            resultado[y] = palavra[i];
            y++;
        }
    }
    resultado[y] = '\0';
    return resultado;
}

void metodo0416(){
    char palavra[50];
    printf("Mostrar as letras (maiúsculas e minúsculas) menores que 'L' e 'l'\n\n");
    printf("Digite a palavra: ");
    scanf("%s", palavra);
    fflush(stdin);
    char * resultado;
    resultado = mostraMaiusculaMenorL(palavra);
    printf("\nLetras maiusculas menores que 'L' na palavra = %s", resultado);
    resultado = mostraMinusculaMenorL(palavra);
    printf("\nLetras minusculas menores que 'l' na palavra = %s\n", resultado);
}

//funcao que retorna a quantidade de digitos pares em um palavra
int contaPares(char * palavra){
    int cont = 0;
    for(int i = 0; i < strlen(palavra); i++){
        if(palavra[i] >= '0' && palavra[i] <= '9'){
            if((int)palavra[i] == 0 || (int)palavra[i]%2 == 0){
                cont++;
            }
        }
    }
    return cont;
}
void metodo0417(){
    int resultado;
    char palavra[50];
    printf("Mostrar a quantidade de dígitos pares\n\n");
    printf("Digite a palavra: ");
    scanf("%s", palavra);
    fflush(stdin);
    resultado = contaPares(palavra);
    printf("\nQuantidade de digitos pares na palavra = %d\n", resultado);
}

//funcao que retorna todos os simbolos nao alfanumericos
char* mostraSimbolosNaoAlfanumericos(char * palavra){
    int tamanho = strlen(palavra);
    char * resultado;
    int y = 0;
    resultado = (char*)malloc(tamanho+1);
    for(int i = 0; i < tamanho; i++){
        if(!((palavra[i] >= 'a' && palavra[i] <= 'z') || (palavra[i] >= 'A' && palavra[i] <= 'Z') || (palavra[i] >= '0' && palavra[i] <= '9') )){
           resultado[y] = palavra[i];
           y++;
        }
    }
    resultado[y] = '\0';
    return resultado;
}

void metodo0418(){
    char palavra[50];
    char * resultado;
    printf("Mostrar todos os simbolos nao alfanumericos\n\n");
    printf("Digite a palavra: ");
    scanf("%s", palavra);
    fflush(stdin);
    resultado = mostraSimbolosNaoAlfanumericos(palavra);
    printf("\nSimbolos nao alfanumericos da palavra = %s\n", resultado);

}

//funcao que retorna todos os simbolos alfanumericos
char* mostraSimbolosAlfanumericos(char * palavra){
    int tamanho = strlen(palavra);
    char * resultado;
    int y = 0;
    resultado = (char*)malloc(tamanho+1);
    for(int i = 0; i < tamanho; i++){
        if((palavra[i] >= 'a' && palavra[i] <= 'z') || (palavra[i] >= 'A' && palavra[i] <= 'Z') || (palavra[i] >= '0' && palavra[i] <= '9') ){
           resultado[y] = palavra[i];
           y++;
        }
    }
    resultado[y] = '\0';
    return resultado;
}

void metodo0419(){
    char palavra[50];
    char * resultado;
    printf("Mostrar todos os simbolos alfanumericos\n\n");
    printf("Digite a palavra: ");
    scanf("%s", palavra);
    fflush(stdin);
    resultado = mostraSimbolosAlfanumericos(palavra);
    printf("\nSimbolos alfanumericos da palavra = %s\n", resultado);
}

void metodo0420(){
    char palavra[50];
    int n;
    int contTotal = 0;
    char * resultado;
    printf("Mostrar e contar a quantidade de símbolos alfanuméricos\n\n");
    printf("Digite a quantidade n de palavras: ");
    scanf("%d", &n);
    fflush(stdin);
    for(int i = 0; i < n; i++){
        int cont = 0;
        printf("Digite a palavra: ");
        scanf("%s", palavra);
        fflush(stdin);
        resultado = mostraSimbolosAlfanumericos(palavra);
        printf("Simbolos alfanumericos da palavra = %s\n", resultado);
        cont = strlen(resultado);
        contTotal += cont;
        printf("Quantidade de simbolos alfanumericos = %d\n\n", cont);
    }
    printf("\n\nQuantidade TOTAL de simbolos alfanumericos = %d\n", contTotal);
}

char* mostraSimbolosAlfanumericosEEspaco(char * palavra){
    int tamanho = strlen(palavra);
    char * resultado;
    int y = 0;
    resultado = (char*)malloc(tamanho+1);
    for(int i = 0; i < tamanho; i++){
        if((palavra[i] >= 'a' && palavra[i] <= 'z') || (palavra[i] >= 'A' && palavra[i] <= 'Z') || (palavra[i] >= '0' && palavra[i] <= '9') || (palavra[i] == ' ') ){
           resultado[y] = palavra[i];
           y++;
        }
    }
    resultado[y] = '\0';
    return resultado;
}

void metodo04E1(){
    char palavra[50];
    int n;
    char * resultado;
    int contTotal = 0;

    printf("Contar a quantidade de símbolos alfanuméricos, incluindo espaços em branco\n\n");

    printf("Digite a quantidade n de palavras: ");
    scanf("%d", &n);
    fflush(stdin);

    for(int i = 0; i < n; i++){
        int cont = 0;
        printf("Digite a palavra: ");
        fgets(palavra, sizeof(palavra), stdin);

        //printf("%s", palavra);
        resultado = mostraSimbolosAlfanumericosEEspaco(palavra);
        printf("Simbolos alfanumericos e espacos da palavra = %s\n", resultado);
        cont = strlen(resultado);
        contTotal += cont;
        printf("Quantidade de simbolos alfanumericos/espacos = %d\n\n", cont);
    }
    printf("\nQuantidade TOTAL de simbolos alfanumericos/espacos = %d\n", contTotal);
}

int contaDigito(char * palavra){
    int cont = 0;
    for(int i = 0; i < strlen(palavra); i++){
        if(palavra[i] >= '0' && palavra[i] <= '9'){
            cont++;
        }
    }
    return cont;
}

void metodo04E2(){
    char palavra1[50];
    char palavra2[50];
    int cont1, cont2;

    printf("Digite a palavra 1: ");
    scanf("%s", palavra1);
    fflush(stdin);
    printf("Digite a palavra 2: ");
    scanf("%s", palavra2);
    fflush(stdin);

    cont1 = contaDigito(palavra1);
    cont2 = contaDigito(palavra2);
    if(cont1 < cont2){
        printf("\nA sequencia 1 possui menos digitos\n");
    } else if(cont2 < cont1){
        printf("\nA sequencia 2 possui menos digitos\n");
    } else {
        printf("\nAs duas sequencias possuem a mesma quantidade de digitos\n");
    }
}

int main(void) {
  int opcao;
  do{
    printf("\n\nEscolha uma das opcoes abaixo: \n");
    printf("\n\t0: Sair");
    printf("\n\t1: Metodo0411");
    printf("\n\t2: Metodo0412");
    printf("\n\t3: Metodo0413");
    printf("\n\t4: Metodo0414");
    printf("\n\t5: Metodo0415");
    printf("\n\t6: Metodo0416");
    printf("\n\t7: Metodo0417");
    printf("\n\t8: Metodo0418");
    printf("\n\t9: Metodo0419");
    printf("\n\t10: Metodo0420");
    printf("\n\t11: Metodo04E1");
    printf("\n\t12: Metodo04E2\n");
    scanf("%d", &opcao);

    switch(opcao){
        case 0:
            break;
        case 1:
            metodo0411();
            break;
        case 2:
            metodo0412();
            break;
        case 3:
            metodo0413();
            break;
        case 4:
            metodo0414();
            break;
        case 5:
            metodo0415();
            break;
        case 6:
            metodo0416();
            break;
        case 7:
            metodo0417();
            break;
        case 8:
            metodo0418();
            break;
        case 9:
            metodo0419();
            break;
        case 10:
            metodo0420();
            break;
        case 11:
            metodo04E1();
            break;
        case 12:
            metodo04E2();
            break;

        default:
            printf("Opcao invalida!\n");
            break;
    }

  } while(opcao != 0);

  return 0;
}
