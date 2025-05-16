#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Dados{
    int quantidade;
    int *valores;
}Dados;

//função para ler um arranjo de arquivo
Dados readArrayFromFile(char * fileName){
    FILE *arquivo = fopen(fileName, "r");
    if(!arquivo){
        printf("Arquivo nao existe...\n");
        exit(1);
    }
    Dados dados;
    //lendo primeira linha do arquivo que contem a quantidade
    fscanf(arquivo, "%d", &dados.quantidade);
    //alocando memoria para o array
    dados.valores = (int *)malloc(dados.quantidade * sizeof(int));
    //lendo os elementos do arquivo
    for(int i = 0; i < dados.quantidade; i++){
        fscanf(arquivo, "%d", &dados.valores[i]);
    }
    fclose(arquivo);
    printf("Arquivo [%s] lido!\n", fileName);
    return dados;
}

//função para verificar se o arranjo está em ordem decrescente
int isArrayDecrescent(Dados *arranjo){
    int cont = 0;
    for(int i = 1; i < arranjo->quantidade; i++){
        if(arranjo->valores[i-1] < arranjo->valores[i]){
            cont++;
        }
    }

    if(cont == 0){
        return 1; //retorna 1 se estiver ordenado de forma decrescente
    } else {
        return 0; //retorna 0 se nao estiver ordenado
    }
}

//procedimento para printar um arranjo
void printArray(Dados arranjo){
    for(int i = 0; i < arranjo.quantidade; i++){
        printf("%d ", arranjo.valores[i]);
    }
    printf("\n");
}

// função para ordenar o arranjo em ordem decrescente
void ordenaDecrescente(Dados *arranjo){
    int tamanho = arranjo->quantidade;
    for(int i = 0; i < tamanho-1; i++){
        for(int j = i+1; j < tamanho; j++){
            if(arranjo->valores[i] < arranjo->valores[j]){
            int temp = arranjo->valores[i];
            arranjo->valores[i] = arranjo->valores[j];
            arranjo->valores[j] = temp;
        }
        }
    }
}

//função para ordenar o arranjo em ordem crescente
void ordenaCrescente(Dados *arranjo){
    int tamanho = arranjo->quantidade;
    for(int i = 0; i < tamanho-1; i++){
        for(int j = i+1; j < tamanho; j++){
            if(arranjo->valores[i] > arranjo->valores[j]){
            int temp = arranjo->valores[i];
            arranjo->valores[i] = arranjo->valores[j];
            arranjo->valores[j] = temp;
        }
        }
    }
}

//grava os valores em um arquivo
void gravarValores(Dados *dados, char *fileName){
    FILE *arquivo = fopen(fileName, "w");
    if(!arquivo){
        printf("Arquivo nao existe...\n");
        return;
    }

    fprintf(arquivo, "%d\n", dados->quantidade);
    for(int i = 0; i < dados->quantidade; i++){
        fprintf(arquivo, "%d\n", dados->valores[i]);
    }

    printf("Gravado no arquivo [%s]...\n", fileName);
    fclose(arquivo);
}

//função que recebe um arranjo como parametro e inverte seus valores
void inverteArranjo(Dados *arranjo){
    int tamanho = arranjo->quantidade;
    int temp;
    for(int i = 0; i < tamanho/2; i++){
        temp = arranjo->valores[i];
        arranjo->valores[i] = arranjo->valores[tamanho - 1 - i];
        arranjo->valores[tamanho - 1 - i] = temp;
    }
}

//função para calcular a mediana de um arranjo
double calcularMediana(Dados *arranjo){
    double mediana;
    int tamanho = arranjo->quantidade;

    ordenaCrescente(arranjo);

     // Calcular a mediana
    if (tamanho % 2 == 1) {
        // Se tamanho for ímpar
        mediana = arranjo->valores[tamanho / 2];
    } else {
        // Se tamanho for par
        int mid1 = arranjo->valores[tamanho / 2 - 1];
        int mid2 = arranjo->valores[tamanho / 2];
        mediana = (float)(mid1 + mid2) / 2.0;
    }

    return mediana;
}

int calculaModa(Dados *arranjo){
    int tamanho = arranjo->quantidade;

    ordenaCrescente(arranjo);

    int moda = arranjo->valores[0]; // Inicializar a moda com o primeiro elemento
    int max_frequencia = 1; // Inicializar a frequência máxima

    int atual = arranjo->valores[0];
    int contagem_atual = 1;

    // Percorrer o arranjo ordenado para encontrar a moda
    for (int i = 1; i < tamanho; i++) {
        if (arranjo->valores[i] == atual) {
            contagem_atual++;
        } else {
            if (contagem_atual > max_frequencia) {
                max_frequencia = contagem_atual;
                moda = atual;
            }
            atual = arranjo->valores[i];
            contagem_atual = 1;
        }
    }

    // Verificar a última sequência
    if (contagem_atual > max_frequencia) {
        max_frequencia = contagem_atual;
        moda = atual;
    }

    return moda;
}

int estaPresente(Dados *arranjo, int valor){
    for(int i = 0; i < arranjo->quantidade; i++){
         if (arranjo->valores[i] == valor) {
            return 1;
        }
    }
    return 0;
}

void filtrarComuns(Dados *arranjo1, Dados *arranjo2, Dados *arranjo3){
    int cont = 0;
    arranjo3->quantidade = arranjo1->quantidade;
    arranjo3->valores = (int*)malloc(arranjo1->quantidade * sizeof(int));
    for(int i = 0; i < arranjo1->quantidade; i++){
        for(int j = 0; j < arranjo2->quantidade; j++){
            if(arranjo1->valores[i] == arranjo2->valores[j] ){
                    if(!estaPresente(arranjo3, arranjo1->valores[i])){
                        arranjo3->valores[cont] = arranjo1->valores[i];
                        cont++;
                    }

            }
        }
    }
    arranjo3->quantidade = cont;
}

// Função para verificar se uma cadeia é binária (contém apenas '0' e '1')
int ehBinario(const char* cadeia) {
    for (int i = 0; cadeia[i] != '\0'; i++) {
        if (cadeia[i] != '0' && cadeia[i] != '1') {
            return 0;
        }
    }
    return 1;
}

// Função para converter uma cadeia binária em um número decimal
int binarioParaDecimal(const char* binario) {
    int decimal = 0;
    int comprimento = strlen(binario);
    for (int i = 0; i < comprimento; i++) {
        if (binario[i] == '1') {
            decimal += pow(2, comprimento - 1 - i);
        }
    }
    return decimal;
}

// Função para ler o arquivo e extrair as cadeias de caracteres
char** lerCadeias(const char* nome_arquivo, int* quantidade) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        fprintf(stderr, "Erro ao abrir o arquivo %s\n", nome_arquivo);
        exit(1);
    }

    // Contar a quantidade de linhas no arquivo
    char linha[256];
    *quantidade = 0;
    while (fgets(linha, sizeof(linha), arquivo)) {
        (*quantidade)++;
    }

    // Alocar memória para armazenar as linhas
    char **cadeias = (char**)malloc((*quantidade) * sizeof(char*));
    rewind(arquivo);

    // Ler as linhas e armazenar no array
    int i = 0;
    while (fgets(linha, sizeof(linha), arquivo)) {
        linha[strcspn(linha, "\n")] = '\0'; // Remover o caractere de nova linha
        cadeias[i] = (char*)malloc((strlen(linha) + 1) * sizeof(char));
        strcpy(cadeias[i], linha);
        i++;
    }

    fclose(arquivo);
    return cadeias;
}


#endif // ARRAY_H_INCLUDED
