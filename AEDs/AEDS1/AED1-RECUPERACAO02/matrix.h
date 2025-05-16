#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct DadosMatrix{
    int linha;
    int coluna;
    int **valores;
}DadosMatrix;

DadosMatrix readMatrixFromFile(char *fileName){
    FILE *arquivo = fopen(fileName, "r");
    if(!arquivo){
        printf("Arquivo nao existe...\n");
        exit(1);
    }
    DadosMatrix dados;
    //lendo primeira linha do arquivo que contem a quantidade de linhas e colunas
    fscanf(arquivo, "%d", &dados.linha);
    fscanf(arquivo, "%d", &dados.coluna);
    //alocando memoria para o array
    dados.valores = (int **)malloc(dados.linha * sizeof(int));
    //lendo os elementos do arquivo
    for(int i = 0; i < dados.linha; i++){
        dados.valores[i] = (int *)malloc(dados.coluna * sizeof(int));
       for(int j = 0; j < dados.coluna; j++){
        fscanf(arquivo, "%d", &dados.valores[i][j]);
       }
    }

    fclose(arquivo);
    printf("Arquivo [%s] lido!\n", fileName);
    return dados;
}

//procedimento para printar na tela uma matriz
void printMatrix(DadosMatrix matrix){
    for(int i = 0; i < matrix.linha; i++){
        for(int j = 0; j < matrix.coluna; j++){
            printf("%d ", matrix.valores[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Fun��o para criar a matriz tridiagonal crescente
void criarMatrizTridiagonal(DadosMatrix *matrix) {
    int valor = 1;
    for (int i = 0; i < matrix->linha; i++) {
        for (int j = 0; j < matrix->linha; j++) {
            if (i == j || i == j - 1 || i == j + 1) {
                matrix->valores[i][j] = valor++;
            } else {
                matrix->valores[i][j] = 0;
            }
        }
    }
}

// Fun��o para gravar a matriz no arquivo
void gravarMatrizNoArquivo(DadosMatrix *matrix, char *fileName) {
    FILE *arquivo = fopen(fileName, "w");
    if (!arquivo) {
        fprintf(stderr, "Erro ao abrir o arquivo %s\n", fileName);
        exit(1);
    }

    fprintf(arquivo, "%d\n", matrix->linha);
    fprintf(arquivo, "%d\n", matrix->coluna);

    for (int i = 0; i < matrix->linha; i++) {
        for (int j = 0; j < matrix->coluna; j++) {
            fprintf(arquivo, "%d ", matrix->valores[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
    printf("Gravado no arquivo [%s]...\n", fileName);
}

// Fun��o para criar a matriz tridiagonal secund�ria decrescente
void criarMatrizTridiagonalSecundaria(DadosMatrix *matrix) {
    int n = matrix->linha;
    int valor = n * (n + 1) / 2; // O valor inicial para a sequ�ncia decrescente
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j == n - 1 || i + j == n - 2 || i + j == n) {
                matrix->valores[i][j] = valor--;
            } else {
                matrix->valores[i][j] = 0;
            }
        }
    }
}

// Fun��o l�gica para verificar se a matriz apresenta pot�ncias por linha
int verificarPotenciasPorLinha(DadosMatrix *matrix) {
    int n = matrix->linha;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix->valores[i][j] != pow(i + 1, j)) {
                return 0; // Falso se qualquer elemento n�o satisfizer a condi��o
            }
        }
    }
    return 1; // Verdadeiro se todos os elementos satisfizerem a condi��o
}

// Fun��o l�gica para verificar se a matriz apresenta pot�ncias por coluna
int verificarPotenciasPorColuna(DadosMatrix *matrix) {
    int n = matrix->linha;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (matrix->valores[i][j] != pow(j + 1, i)) {
                return 0; // Falso se qualquer elemento n�o satisfizer a condi��o
            }
        }
    }
    return 1; // Verdadeiro se todos os elementos satisfizerem a condi��o
}

#endif // MATRIX_H_INCLUDED
