/*
    AED1 - ED09 - 03/05/2024
    AUTORIA: ALESSANDRA FARIA RODRIGUES
    NUM. MATRICULA: 828333
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void readNegativeDoubleMatrix(int linha, int coluna, double matrix[linha][coluna]){
    if(linha <= 0 || coluna <= 0){
        printf("Dimensoes nao podem ser nulas ou negativas...\n");
        return;
    }

    printf("Digite os valores da matriz (apenas negativos):\n");
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            do{
                printf("Digite o valor da linha %d coluna %d: ", i+1, j+1);
                scanf("%lf", &matrix[i][j]);
                getchar();
            } while (matrix[i][j] > 0);
        }
    }
}

void printDoubleMatrix(int linha, int coluna, double matrix[linha][coluna]){
    printf("Matriz: \n");
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            printf("%.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

void metodo0911(){
    int m, n;
    printf("METODO 0911\n\n");

    printf("Digite a quantidade de linhas: ");
    scanf("%d", &m);
    getchar();
    printf("Digite a quantidade de colunas: ");
    scanf("%d", &n);
    getchar();

    if(m <= 0 || n <= 0){
        printf("Dimensoes nao podem ser nulas ou negativas...\n");
        return;
    }

    double negativeMatrix[m][n];

    readNegativeDoubleMatrix(m, n, negativeMatrix);
    printDoubleMatrix(m, n, negativeMatrix);

    printf("\nAperte enter para finalizar METODO0911...");
    getchar();
}

void fprintDoubleMatrix(char * fileName, int linha, int coluna, double matrix[linha][coluna]){
    FILE *arquivo = fopen(fileName, "w");
    if(!arquivo){
        printf("Arquivo nao existe...\n");
        return;
    }

    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            fprintf(arquivo, "%.2lf ", matrix[i][j]);
        }
        fprintf(arquivo, "\n");
    }
    fclose(arquivo);
    printf("Gravado no arquivo...\n");

}

void metodo0912(){
    int m, n;
    printf("METODO 0912\n\n");

    printf("Digite a quantidade de linhas: ");
    scanf("%d", &m);
    getchar();
    printf("Digite a quantidade de colunas: ");
    scanf("%d", &n);
    getchar();

    if(m <= 0 || n <= 0){
        printf("Dimensoes nao podem ser nulas ou negativas...\n");
        return;
    }

    double negativeMatrix[m][n];

    readNegativeDoubleMatrix(m, n, negativeMatrix);
    //metodo para gravar matriz no arquivo
    fprintDoubleMatrix("MATRIX_01.txt", m, n, negativeMatrix);

    printf("\nAperte enter para finalizar METODO0912...");
    getchar();
}

void printDiagonalDoubleMatrix(int linha, int coluna, double matrix[linha][coluna]){
    printf("Valores da diagonal principal: \n");
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            if(i == j){
                printf("%.2lf", matrix[i][j]);
            }
        }
        printf("\n");
        for(int k = 0; k <= i; k++){
            printf("\t");
        }
    }
}

void metodo0913(){
    int m, n;
    printf("METODO 0913\n\n");

    printf("Digite a quantidade de linhas: ");
    scanf("%d", &m);
    getchar();
    printf("Digite a quantidade de colunas: ");
    scanf("%d", &n);
    getchar();

    if(m <= 0 || n <= 0){
        printf("Dimensoes nao podem ser nulas ou negativas...\n");
        return;
    }

    if(m == n){
        double negativeMatrix[m][n];
        //lendo os valores da matriz
        readNegativeDoubleMatrix(m, n, negativeMatrix);
        //printando diagonal principal
        printDiagonalDoubleMatrix(m, n, negativeMatrix);
    } else {
        printf("A matriz nao e quadrada, entao nao possui diagonal principal...\n");
    }

     printf("\nAperte enter para finalizar METODO0913...");
     getchar();
}

void printSDiagonalDoubleMatrix(int linha, int coluna, double matrix[linha][coluna]){
     printf("Valores da diagonal secundaria: \n");
     for(int i = 0; i < linha; i++){
        printf("%.2lf", matrix[i][linha-i-1]);
        printf("\n");
    }
}

void metodo0914(){
    int m, n;
    printf("METODO 0914\n\n");

    printf("Digite a quantidade de linhas: ");
    scanf("%d", &m);
    getchar();
    printf("Digite a quantidade de colunas: ");
    scanf("%d", &n);
    getchar();

    if(m <= 0 || n <= 0){
        printf("Dimensoes nao podem ser nulas ou negativas...\n");
        return;
    }

     if(m == n){
        double negativeMatrix[m][n];
        //lendo os valores da matriz
        readNegativeDoubleMatrix(m, n, negativeMatrix);
        //printando diagonal secundaria
        printSDiagonalDoubleMatrix(m, n, negativeMatrix);
    } else {
        printf("A matriz nao e quadrada, entao nao possui diagonal principal...\n");
    }

     printf("\nAperte enter para finalizar METODO0914...");
     getchar();
}

void printLDTriangleDoubleMatrix(int linha, int coluna, double matrix[linha][coluna]){
    printf("Valores abaixo e na diagonal principal da matriz:\n");
    for(int i = 0; i < linha; i++){
        for(int j = 0; j <= i; j++){
            printf("%.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

void metodo0915(){
    int m, n;
    printf("METODO 0915\n\n");

    printf("Digite a quantidade de linhas: ");
    scanf("%d", &m);
    getchar();
    printf("Digite a quantidade de colunas: ");
    scanf("%d", &n);
    getchar();

    if(m <= 0 || n <= 0){
        printf("Dimensoes nao podem ser nulas ou negativas...\n");
        return;
    }

     if(m == n){
        double negativeMatrix[m][n];
        //lendo os valores da matriz
        readNegativeDoubleMatrix(m, n, negativeMatrix);
        //printando diagonal principal e valores abaixo
       printLDTriangleDoubleMatrix(m, n, negativeMatrix);
    } else {
        printf("A matriz nao e quadrada, entao nao possui diagonal principal...\n");
    }

     printf("\nAperte enter para finalizar METODO0915...");
     getchar();
}

void printLUTriangleDoubleMatrix(int linha, int coluna, double matrix[linha][coluna]){
    printf("Valores acima e na diagonal principal da matriz:\n");
    for (int i = 0; i < linha; i++) {
        for (int j = i; j < linha; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}


void metodo0916(){
    int m, n;
    printf("METODO 0916\n\n");

    printf("Digite a quantidade de linhas: ");
    scanf("%d", &m);
    getchar();
    printf("Digite a quantidade de colunas: ");
    scanf("%d", &n);
    getchar();

    if(m <= 0 || n <= 0){
        printf("Dimensoes nao podem ser nulas ou negativas...\n");
        return;
    }

     if(m == n){
        double negativeMatrix[m][n];
        //lendo os valores da matriz
        readNegativeDoubleMatrix(m, n, negativeMatrix);
        //printando diagonal principal e valores acima
       printLUTriangleDoubleMatrix(m, n, negativeMatrix);
    } else {
        printf("A matriz nao e quadrada, entao nao possui diagonal principal...\n");
    }

     printf("\nAperte enter para finalizar METODO0916...");
     getchar();
}

void printSLDTriangleDoubleMatrix(int linha, int coluna, double matrix[linha][coluna]){
     printf("Valores abaixo e na diagonal secundária da matriz:\n");
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < linha; j++) {
            if (i + j >= linha - 1) {
                printf("%.2f ", matrix[i][j]);
            }
        }
        printf("\n");
    }

}

void metodo0917(){
    int m, n;
    printf("METODO 0917\n\n");

    printf("Digite a quantidade de linhas: ");
    scanf("%d", &m);
    getchar();
    printf("Digite a quantidade de colunas: ");
    scanf("%d", &n);
    getchar();

    if(m <= 0 || n <= 0){
        printf("Dimensoes nao podem ser nulas ou negativas...\n");
        return;
    }

     if(m == n){
        double negativeMatrix[m][n];
        //lendo os valores da matriz
        readNegativeDoubleMatrix(m, n, negativeMatrix);
        //printando diagonal secundaria e valores abaixo
        printSLDTriangleDoubleMatrix(m, n, negativeMatrix);
    } else {
        printf("A matriz nao e quadrada, entao nao possui diagonal principal...\n");
    }

     printf("\nAperte enter para finalizar METODO0917...");
     getchar();
}

void printSLUTriangleDoubleMatrix(int linha, int coluna, double matrix[linha][coluna]){
    printf("Valores acima e na diagonal secundaria da matriz:\n");
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < linha; j++) {
            if (i + j <= linha - 2 || i == linha - 1 - j) {
                printf("%.2f ", matrix[i][j]);
            }
        }
        printf("\n");
    }
    }


void metodo0918(){
    int m, n;
    printf("METODO 0918\n\n");

    printf("Digite a quantidade de linhas: ");
    scanf("%d", &m);
    getchar();
    printf("Digite a quantidade de colunas: ");
    scanf("%d", &n);
    getchar();

    if(m <= 0 || n <= 0){
        printf("Dimensoes nao podem ser nulas ou negativas...\n");
        return;
    }

     if(m == n){
        double negativeMatrix[m][n];
        //lendo os valores da matriz
        readNegativeDoubleMatrix(m, n, negativeMatrix);
        //printando diagonal secundaria e valores acima
        printSLUTriangleDoubleMatrix(m, n, negativeMatrix);
    } else {
        printf("A matriz nao e quadrada, entao nao possui diagonal principal...\n");
    }

     printf("\nAperte enter para finalizar METODO0918...");
     getchar();
}

bool allZerosLTriangleDoubleMatrix(int linha, int coluna, double matrix[linha][coluna]) {
    for (int i = 1; i < linha; i++) {
        for (int j = 0; j < i; j++) {
            if (matrix[i][j] != 0.0) {
                return false;
            }
        }
    }
    return true;
}

void metodo0919(){
    int m, n;
    printf("METODO 0919\n\n");

    printf("Digite a quantidade de linhas: ");
    scanf("%d", &m);
    getchar();
    printf("Digite a quantidade de colunas: ");
    scanf("%d", &n);
    getchar();

    if(m <= 0 || n <= 0){
        printf("Dimensoes nao podem ser nulas ou negativas...\n");
        return;
    }

     if(m == n){
        double negativeMatrix[m][n];
        //lendo os valores da matriz
        readNegativeDoubleMatrix(m, n, negativeMatrix);
        //testando se sao zeros
        bool resultado = allZerosLTriangleDoubleMatrix(m, n, negativeMatrix);

        if(resultado){
            printf("Sao zeros\n");
        } else {
            printf("Existem valores diferentes de zero\n");
        }

    } else {
        printf("A matriz nao e quadrada, entao nao possui diagonal principal...\n");
    }

     printf("\nAperte enter para finalizar METODO0919...");
     getchar();
}

bool allZerosUTriangleDoubleMatrix(int linha, int coluna, double matrix[linha][coluna]) {
    for (int i = 0; i < linha; i++) {
        for (int j = i + 1; j < linha; j++) {
            if (matrix[i][j] != 0.0) {
                return false;
            }
        }
    }
    return true;
}

void metodo0920(){
    int m, n;
    printf("METODO 0920\n\n");

    printf("Digite a quantidade de linhas: ");
    scanf("%d", &m);
    getchar();
    printf("Digite a quantidade de colunas: ");
    scanf("%d", &n);
    getchar();

    if(m <= 0 || n <= 0){
        printf("Dimensoes nao podem ser nulas ou negativas...\n");
        return;
    }

     if(m == n){
        double negativeMatrix[m][n];
        //lendo os valores da matriz
        readNegativeDoubleMatrix(m, n, negativeMatrix);
        //testando se sao zeros
        bool resultado = allZerosUTriangleDoubleMatrix(m, n, negativeMatrix);

        if(resultado){
            printf("Sao zeros\n");
        } else {
            printf("Existem valores diferentes de zero\n");
        }

    } else {
        printf("A matriz nao e quadrada, entao nao possui diagonal principal...\n");
    }

     printf("\nAperte enter para finalizar METODO0920...");
     getchar();
}


void metodo09E1(){
    int m, n;
    printf("METODO 09E1\n\n");

    printf("Digite a quantidade de linhas: ");
    scanf("%d", &m);
    getchar();
    printf("Digite a quantidade de colunas: ");
    scanf("%d", &n);
    getchar();

    if(m <= 0 || n <= 0){
        printf("Dimensoes nao podem ser nulas ou negativas...\n");
        return;
    }

    int matrix[m][n];

    int y = 1;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            matrix[i][j] = y;
            y++;
        }
    }

    FILE *arquivo = fopen("EXTRA.txt", "w");
    if(!arquivo){
        printf("Arquivo nao existe...\n");
        return;
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            fprintf(arquivo, "%d ", matrix[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
    printf("Gravado no arquivo...\n");

    printf("\nAperte enter para finalizar METODO09E1...");
    getchar();
}

void metodo09E2(){
    int m, n;
    printf("METODO 09E2\n\n");

    printf("Digite a quantidade de linhas: ");
    scanf("%d", &m);
    getchar();
    printf("Digite a quantidade de colunas: ");
    scanf("%d", &n);
    getchar();

    if(m <= 0 || n <= 0){
        printf("Dimensoes nao podem ser nulas ou negativas...\n");
        return;
    }

    int matrix[m][n];

    int y = m * n;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            matrix[i][j] = y;
            y--;
        }
    }

    FILE *arquivo = fopen("EXTRA.txt", "w");
    if(!arquivo){
        printf("Arquivo nao existe...\n");
        return;
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            fprintf(arquivo, "%d ", matrix[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
    printf("Gravado no arquivo...\n");

    printf("\nAperte enter para finalizar METODO09E2...");
    getchar();
}

int main(void){
    int opcao;
  do{
    printf("\n\nEscolha uma das opcoes abaixo: \n");
    printf("\n\t0: Sair");
    printf("\n\t1: Metodo0911");
    printf("\n\t2: Metodo0912");
    printf("\n\t3: Metodo0913");
    printf("\n\t4: Metodo0914");
    printf("\n\t5: Metodo0915");
    printf("\n\t6: Metodo0916");
    printf("\n\t7: Metodo0917");
    printf("\n\t8: Metodo0918");
    printf("\n\t9: Metodo0919");
    printf("\n\t10: Metodo0920");
    printf("\n\t11: Metodo09E1");
    printf("\n\t12: Metodo09E2\n");
    scanf("%d", &opcao);
    getchar();

    switch(opcao){
        case 0:
            break;
        case 1:
            metodo0911();
            break;
        case 2:
            metodo0912();
            break;
        case 3:
            metodo0913();
            break;
        case 4:
            metodo0914();
            break;
        case 5:
            metodo0915();
            break;
        case 6:
            metodo0916();
            break;
        case 7:
            metodo0917();
            break;
        case 8:
            metodo0918();
            break;
        case 9:
            metodo0918();
            break;
        case 10:
            metodo0918();
            break;
        case 11:
            metodo09E1();
            break;
        case 12:
            metodo09E2();
            break;

        default:
            printf("Opcao invalida!\n");
            break;
    }

  } while(opcao != 0);


return 0;
}
