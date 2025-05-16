/*
    AED1 - ED07 - 18/04/2024
    AUTORIA: ALESSANDRA FARIA RODRIGUES
    NUM. MATRICULA: 828333
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void metodo0711(){
    FILE * arquivo = fopen("EXEMPLO_0711.txt", "wt");
    int n;
    int par = 4;
    if(arquivo == NULL){
        printf("Arquivo nao existe...");
    } else {
        printf("METODO 0711\n\n");
        printf("GRAVAR n MULTIPLOS DE 4\n\n");
        printf("Digite a quantidade n: ");
        scanf("%d", &n);
        getchar();
        for(int i = 0; i < n; i++){
            fprintf(arquivo, "%d\n", par);
            par += 4;
        }
        printf("Finalizado!\n");
        fclose(arquivo);
    }
}

void metodo0712(){
    FILE *arquivo = fopen("EXEMPLO_0712.txt", "wt");
    int n;
    int impar = 25;
    if(arquivo == NULL){
        printf("Arquivo nao existe...");
    } else {
        printf("METODO 0712\n\n");
        printf("GRAVAR n MULTIPLOS DE 5 IMPARES\n\n");
        printf("Digite a quantidade n: ");
        scanf("%d", &n);
        getchar();
        int multiplosImpares[n];
        for(int i = 0; i < n; i++){
            multiplosImpares[i] = impar;
            impar += 10;
        }
        for(int i = n-1; i >= 0; i--){
            fprintf(arquivo, "%d\n", multiplosImpares[i]);
        }
        fclose(arquivo);
        printf("Finalizado!\n");
    }
}

void metodo0713(){
    FILE * arquivo = fopen("EXEMPLO_0713.txt", "wt");
    if(arquivo == NULL){
        printf("Arquivo nao existe...");
    } else {
        int n;
        double exp = 1;
        double p;
        printf("METODO 0713\n\n");
        printf("Digite a quantidade n: ");
        scanf("%d", &n);
        getchar();
        if(n > 0){
            for(int i = 0; i < n; i++){
                if(i == 0)
                    fprintf(arquivo, "1\n");
                else {
                    p = pow(5, exp);
                    //printf("%lf", p);
                    fprintf(arquivo, "%.0lf\n", p);
                    exp++;
                }
            }
            printf("Finalizado!\n");
        } else {
            printf("Valor invalido!\n");
        }
        fclose(arquivo);
    }
}
void metodo0714(){
    FILE *arquivo = fopen("EXEMPLO_0714.txt", "wt");
    FILE *arquivoResultado = fopen("RESULTADO_EXEMPLO_0714.txt", "wt");
    if(arquivo == NULL){
        printf("Arquivo nao existe...");
    } else {
        int n;
        double exp = 1;
        double p;
        printf("METODO 0714\n\n");
        printf("Digite a quantidade n: ");
        scanf("%d", &n);
        getchar();
        if(n > 0){
            int vetor[n];
            vetor[0] = 1;
            for(int i = 1; i < n; i++){
                p = pow(5, exp);
                vetor[i] = p;
                exp++;
            }
            for(int i = n-1; i >= 0; i--){
                if(i == 0){
                    fprintf(arquivo, "1\n");
                    fprintf(arquivoResultado, "1\n");
                }
                else {
                    double resultado;
                    resultado = 1/(double)vetor[i];
                    //printf("Resultado = %lf ", resultado);
                    fprintf(arquivo, "1/%d\n", vetor[i]);
                    fprintf(arquivoResultado, "%lf\n", resultado);
                }
            }
            printf("Finalizado!\n");
            } else {
                printf("Valor invalido!\n");
            }
        fclose(arquivo);
        fclose(arquivoResultado);
}}

void metodo0715(){
    FILE *arquivo = fopen("EXEMPLO_0715.txt", "wt");
    FILE *arquivoResultado = fopen("RESULTADO_EXEMPLO_0715.txt", "wt");
    if(arquivo == NULL){
        printf("Arquivo nao existe...");
    } else {
        int n, exp = 3;
        double x;
        double p;
        double resultado;
        printf("METODO 0715\n\n");
        printf("Digite a quantidade n: ");
        scanf("%d", &n);
        getchar();
        printf("Digite o valor de x: ");
        scanf("%lf", &x);
        getchar();
        if(n > 0){
            for(int i = 0; i < n; i++){
                if(i == 0){
                    fprintf(arquivo, "1\n");
                }
                else {
                    p = pow(x, exp);
                    //printf("p = %lf ", p);
                    resultado = (1/p);
                    //printf("resultado = %lf", resultado);
                    fprintf(arquivo, "1/%.0lf\n", p);
                    fprintf(arquivoResultado, "%lf", resultado);
                    exp += 2;
                }
        }
            printf("Finalizado!\n");
        } else {
            printf("Valor invalido!\n");
        }
        fclose(arquivo);
        fclose(arquivoResultado);
    }
}

double funcao0716(int n){
    //abrindo arquivo apenas para leitura
    FILE *arquivo = fopen("RESULTADO_EXEMPLO_0715.txt", "r");
    if(arquivo == NULL){
        printf("Arquivo nao existe...");
        return 1;
    } else {
        double num, soma = 0;
        int y = 0;
        while( ! feof (arquivo) && y < n){
            fscanf(arquivo, "%lf", &num);
            soma += num;
            //printf("%lf ", num);
            y++;
        }
        fclose(arquivo);
        return soma;
    }
}

void metodo0716(){
    FILE * arquivo = fopen("RESULTADO06.txt", "wt");
    if(arquivo == NULL){
        printf("Arquivo nao existe...");
    } else {
        int n;
        printf("METODO 0716\n\n");
        printf("Digite a quantidade n: ");
        scanf("%d", &n);
        getchar();
        if(n > 0){
            //chamando metodo0715 para que o arquivo desse metodo seja preenchido
            metodo0715();
            double resultado = funcao0716(n);
            printf("Resultado da soma = %lf\n", resultado);
            fprintf(arquivo, "%d \n%lf", n, resultado);
            printf("Finalizado!\n");
        } else {
            printf("Valor invalido!\n");
        }
            fclose(arquivo);
    }
}

double funcao0717(int n){
    //abrindo arquivo apenas para leitura
    FILE *arquivo = fopen("RESULTADO_EXEMPLO_0714.txt", "r");
    if(arquivo == NULL){
        printf("Arquivo nao existe...");
        return 1;
    } else {
        double num, soma = 0;
        int y = 0;
        while( ! feof (arquivo) && y < n){
            fscanf(arquivo, "%lf", &num);
            soma += num;
            printf("%lf ", num);
            y++;
        }
        fclose(arquivo);
        return soma;
    }
}

void metodo0717(){
    FILE * arquivo = fopen("RESULTADO07.txt", "wt");
    if(arquivo == NULL){
        printf("Arquivo nao existe...");
        return;
    } else {
        int n;
        printf("METODO 0717\n\n");
        printf("Digite a quantidade n: ");
        scanf("%d", &n);
        getchar();
        if(n > 0){
            //chamando metodo0714 para que o arquivo desse metodo seja preenchido
            metodo0714();
            double resultado = funcao0717(n);
            printf("Resultado da soma = %lf\n", resultado);
            fprintf(arquivo, "%d \n%lf", n, resultado);
            printf("Finalizado!\n");
        } else {
            printf("Valor invalido!\n");
        }
            fclose(arquivo);
    }
}

int fibo(int n){
  if(n <= 1)
    return n;

  return fibo(n-1) + fibo(n-2);
}

void fiboPares(int n, int termoAtual){
    FILE *arquivo = fopen("RESULTADO08.txt", "a");
    int fib = fibo(termoAtual);
    if(fib%2 == 0){
        //fseek( arquivo, 0, SEEK_END );
        fprintf(arquivo, "%d\n", fib);
        //soma += fib;
        n--;
        fclose(arquivo);
    }
    if (n > 0){
        fiboPares(n, termoAtual + 1);
    }
    else {
        fclose(arquivo);
        return;
    }
}

void metodo0718(){
    FILE *arquivo = fopen("RESULTADO08.txt", "wt");
    if(arquivo == NULL){
        printf("Arquivo nao existe...");
        return;
    } else {
        int n;
        printf("METODO 0718\n\n");
        printf("Digite a quantidade n: ");
        scanf("%d", &n);
        getchar();
        if(n > 0){
            fprintf(arquivo, "%d\n", n);
            fclose(arquivo);
            fiboPares(n, 1);
            printf("Finalizado!\n");
        } else {
            printf("Valor invalido!\n");
        }
    }
}

int funcao0719(char * texto){
    //FILE *arquivoTexto = fopen("TEXTO_0719.txt", "r");
    int tamanho = strlen(texto);
    int cont = 0;
    for(int i = 0; i < tamanho; i++){
        if(texto[i] >= 'A' && texto[i] <= 'Z'){
            cont++;
        }
    }
    return cont;
}

void metodo0719(){
    FILE *arquivoTexto = fopen("TEXTO_0719.txt", "r");
    FILE *arquivo = fopen("RESULTADO09.txt", "wt");
    if(arquivoTexto == NULL || arquivo == NULL){
        printf("Arquivo nao existe...");
        return;
    } else {
        int resultado;
        char texto[80];
        printf("METODO 0719\n\n");
        while(! feof (arquivoTexto)){
            fgets(texto, sizeof(texto), arquivoTexto);
            //printf("%s", texto);
            resultado = funcao0719(texto);
            //printf("%s = %d", texto, resultado);
            fprintf(arquivo, "%s = %d\n", texto, resultado);
        }
        printf("Finalizado!\n");
        fclose(arquivo);
        fclose(arquivoTexto);
    }
}

int funcao0720(char * texto){
    int tamanho = strlen(texto);
    int cont = 0;
    for(int i = 0; i < tamanho; i++){
        if(texto[i] >= '5' && texto[i] <= '9'){
            cont++;
        }
    }
    return cont;
}

void metodo0720(){
    FILE *arquivoTexto = fopen("TEXTO_0719.txt", "r");
    FILE *arquivo = fopen("RESULTADO10.txt", "wt");
    if(arquivoTexto == NULL || arquivo == NULL){
        printf("Arquivo nao existe...");
        return;
    } else {
        int resultado;
        char texto[80];
        printf("METODO 0710\n\n");
        while(! feof (arquivoTexto)){
            fgets(texto, sizeof(texto), arquivoTexto);
            resultado = funcao0720(texto);
            fprintf(arquivo, "%s = %d\n", texto, resultado);
        }
        printf("Finalizado!\n");
        fclose(arquivo);
        fclose(arquivoTexto);
    }
}

void metodo07E1(){
    FILE *arquivo = fopen("EXTRA1.txt", "wt");
    if(arquivo == NULL){
        printf("Arquivo nao existe...");
        return;
    } else {
        int x;
        printf("METODO 07E1\n\n");
        printf("Digite o valor de x: ");
        scanf("%d", &x);
        getchar();
        if(x > 0){
        for(int i = x; i >= 1; i--){
            if(x%i == 0){
                //nao esta printando no arquivo e eu nao sei o porque ta acontecendo isso
                fprintf(arquivo, "%d ", i);
                //printf("%d ", i);
            }
        }
            printf("Finalizado!\n");
        } else {
            printf("Valor invalido!\n");
        }
        fclose(arquivo);
    }
}

int funcao07E2(char * palavra){
    if(palavra[0] == 'c' || palavra[0] == 'C'){
        return 1;
    } else {
        return 0;
    }

}

void metodo07E2(){
    //FILE *arquivo = fopen("EXTRA2.txt", "wt");
    FILE *arquivoTexto = fopen("EXTRA2_TEXTO.txt", "r");
    if(arquivoTexto == NULL){
        printf("Arquivo nao existe...");
        return;
    } else {
        int contC = 0, total = 0;
        int resultado;
        char palavra[80];
        printf("METODO 07E2\n\n");
        while (! feof(arquivoTexto)){
            fscanf(arquivoTexto, "%s", palavra);
            //printf("%s\n", palavra);
            resultado = funcao07E2(palavra);
            if(resultado == 1){
                contC++;
            }
            total++;
        }
        printf("Total de palavras = %d \nPalavras que comecam com c ou C = %d\n", total, contC);
        printf("Finalizado!\n");
        fclose(arquivoTexto);
    }
}

int main(void){
   int opcao;
  do{
    printf("\n\nEscolha uma das opcoes abaixo: \n");
    printf("\n\t0: Sair");
    printf("\n\t1: Metodo0711");
    printf("\n\t2: Metodo0712");
    printf("\n\t3: Metodo0713");
    printf("\n\t4: Metodo0714");
    printf("\n\t5: Metodo0715");
    printf("\n\t6: Metodo0716");
    printf("\n\t7: Metodo0717");
    printf("\n\t8: Metodo0718");
    printf("\n\t9: Metodo0719");
    printf("\n\t10: Metodo0720");
    printf("\n\t11: Metodo07E1");
    printf("\n\t12: Metodo07E2\n");
    scanf("%d", &opcao);
    getchar();

    switch(opcao){
        case 0:
            break;
        case 1:
            metodo0711();
            break;
        case 2:
            metodo0712();
            break;
        case 3:
            metodo0713();
            break;
        case 4:
            metodo0714();
            break;
        case 5:
            metodo0715();
            break;
        case 6:
            metodo0716();
            break;
        case 7:
            metodo0717();
            break;
        case 8:
            metodo0718();
            break;
        case 9:
            metodo0719();
            break;
        case 10:
            metodo0720();
            break;
        case 11:
            metodo07E1();
            break;
        case 12:
            metodo07E2();
            break;

        default:
            printf("Opcao invalida!\n");
            break;
    }

  } while(opcao != 0);


return 0;
}
