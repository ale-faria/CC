/*
AED1 - RECUPERAÇÃO 02 - 17/06/2024
ALUNA: ALESSANDRA FARIA RODRIGUES
MATRICULA: 828333
*/

#include <stdio.h>
#include "array.h"
#include "matrix.h"


void exemplo01(){
    printf("EXEMPLO 01\n");
    Dados array;
    array = readArrayFromFile("DADOS1.txt");
    int decrescente = isArrayDecrescent(&array);
    if(decrescente == 1){ //ordenado de forma decrescente
        //grava valores no arquivo decrescente
        gravarValores(&array, "DECRESCENTE.txt");
    } else { //nao está ordenado
        //ordenando em ordem decrescente
        ordenaDecrescente(&array);
        //grava no arquivo decrescente os valores na ordem decrescente
        gravarValores(&array, "DECRESCENTE.txt");
    }

    printf("\nAperte enter para finalizar EXEMPLO 01\n");
    getchar();
}

void exemplo02(){
    printf("EXEMPLO 02\n");
    Dados array;
    //lendo arranjo do arquivo
    array = readArrayFromFile("DECRESCENTE.txt");
    //invertendo os valores do arranjo
    inverteArranjo(&array);
    //gravando no arquivo invertidos o arranjo com os valores invertidos
    gravarValores(&array, "INVERTIDOS.txt");

    printf("\nAperte enter para finalizar EXEMPLO 02\n");
    getchar();
}

void exemplo03(){
    printf("EXEMPLO 03\n");
    Dados array;
    array = readArrayFromFile("DADOS1.txt");
    printf("Arranjo: ");
    printArray(array);
    printf("\nMediana: %.2lf\n", calcularMediana(&array));
    printf("Moda: %d\n", calculaModa(&array));

    printf("\nAperte enter para finalizar EXEMPLO 03\n");
    getchar();
}

void exemplo04(){
    printf("EXEMPLO 04\n");
    Dados array1, array2, array3;
    array1 = readArrayFromFile("DADOS1.txt");
    array2 = readArrayFromFile("DADOS2.txt");
    printf("Arranjo 1: ");
    printArray(array1);
    printf("\nArranjo 2: ");
    printArray(array2);

    printf("Elementos comuns aos dois arranjos: ");
    filtrarComuns(&array1, &array2, &array3);
    printArray(array3);

    printf("\nAperte enter para finalizar EXEMPLO 04\n");
    getchar();
}

void exemplo05(){
    printf("EXEMPLO 05\n");
    int quantidade;
    char **cadeias = lerCadeias("BINARIOS1.TXT", &quantidade);

    // Contar e converter cadeias válidas
    int *numeros_decimais = (int*)malloc(quantidade * sizeof(int));
    int quantidade_validos = 0;

    for (int i = 0; i < quantidade; i++) {
        if (ehBinario(cadeias[i])) {
            numeros_decimais[quantidade_validos] = binarioParaDecimal(cadeias[i]);
            quantidade_validos++;
        }
    }

    // Exibir os números decimais resultantes
    printf("Numeros decimais:\n");
    for (int i = 0; i < quantidade_validos; i++) {
        printf("%d\n", numeros_decimais[i]);
    }

    // Liberação de memória
    for (int i = 0; i < quantidade; i++) {
        free(cadeias[i]);
    }
    free(cadeias);
    free(numeros_decimais);

    printf("\nAperte enter para finalizar EXEMPLO 05\n");
    getchar();
}

void exemplo06(){
    printf("EXEMPLO 06\n");

    DadosMatrix matrix;
    int n;
    printf("Digite o tamanho da matriz (N): ");
    scanf("%d", &n);
    getchar();

    matrix.linha = n;
    matrix.coluna = n;
    matrix.valores = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < matrix.linha; i++) {
        matrix.valores[i] = (int*)malloc(n * sizeof(int));
    }

    criarMatrizTridiagonal(&matrix);
    printMatrix(matrix);

    gravarMatrizNoArquivo(&matrix, "MATRIX2.txt");

    // Libera a memória alocada
    for (int i = 0; i < n; i++) {
        free(matrix.valores[i]);
    }
    free(matrix.valores);

    printf("\nAperte enter para finalizar EXEMPLO 06\n");
    getchar();
}

void exemplo07(){
    printf("EXEMPLO 07\n");

    DadosMatrix matrix;
    int n;
    printf("Digite o tamanho da matriz (N): ");
    scanf("%d", &n);
    getchar();

    matrix.linha = n;
    matrix.coluna = n;
    matrix.valores = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < matrix.linha; i++) {
        matrix.valores[i] = (int*)malloc(n * sizeof(int));
    }

    criarMatrizTridiagonalSecundaria(&matrix);
    printMatrix(matrix);

    gravarMatrizNoArquivo(&matrix, "MATRIX2.txt");

    // Libera a memória alocada
    for (int i = 0; i < n; i++) {
        free(matrix.valores[i]);
    }
    free(matrix.valores);

    printf("\nAperte enter para finalizar EXEMPLO 07\n");
    getchar();
}

void exemplo08(){
    printf("EXEMPLO 08\n");

    DadosMatrix matrix;
    matrix = readMatrixFromFile("MATRIX3.txt");

    printMatrix(matrix);

    if(verificarPotenciasPorLinha(&matrix)){
        printf("A matriz apresenta potencias por linha.\n");
    } else {
        printf("A matriz NÃO apresenta potências por linha.\n");
    }

    // Libera a memória alocada
    for (int i = 0; i < matrix.linha; i++) {
        free(matrix.valores[i]);
    }
    free(matrix.valores);

    printf("\nAperte enter para finalizar EXEMPLO 08\n");
    getchar();
}

void exemplo09(){
    printf("EXEMPLO 09\n");

    DadosMatrix matrix;
    matrix = readMatrixFromFile("MATRIX4.txt");

    printMatrix(matrix);

    if(verificarPotenciasPorColuna(&matrix)){
        printf("A matriz apresenta potencias por coluna.\n");
    } else {
        printf("A matriz NAO apresenta potencias por coluna.\n");
    }

    // Libera a memória alocada
    for (int i = 0; i < matrix.linha; i++) {
        free(matrix.valores[i]);
    }
    free(matrix.valores);

    printf("\nAperte enter para finalizar EXEMPLO 09\n");
    getchar();
}

/*QUESTAO 10*/
typedef struct {
    char nome[50];
    int codigo;
    float preco;
} Supermercado;

// Função para ler os dados do arquivo
Supermercado* lerDados(const char* nome_arquivo, int* N) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        fprintf(stderr, "Erro ao abrir o arquivo %s\n", nome_arquivo);
        exit(1);
    }

    fscanf(arquivo, "%d", N);
    Supermercado *supermercados = (Supermercado *)malloc(*N * sizeof(Supermercado));
    for (int i = 0; i < *N; i++) {
        fscanf(arquivo, "%s %d %f", supermercados[i].nome, &supermercados[i].codigo, &supermercados[i].preco);
    }

    fclose(arquivo);
    return supermercados;
}

// Função para calcular o preço médio
float calcularPrecoMedio(Supermercado *supermercados, int N) {
    float soma = 0;
    for (int i = 0; i < N; i++) {
        soma += supermercados[i].preco;
    }
    return soma / N;
}

// Função para mostrar supermercados com preços abaixo da média
void mostrarInferioresAMedia(Supermercado *supermercados, int N, float media) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (supermercados[i].preco < media) {
            printf("Supermercado: %s, Codigo: %d, Preco: %.2f\n", supermercados[i].nome, supermercados[i].codigo, supermercados[i].preco);
            count++;
        }
    }

    if (count < 2) {
        printf("Menos de dois supermercados tem precos abaixo da media.\n");
    }
}

void exemplo10(){
    int N;
    Supermercado *supermercados = lerDados("DADOS3.TXT", &N);

    // Calcula o preço médio
    float media = calcularPrecoMedio(supermercados, N);
    printf("Preco medio: %.2f\n", media);

    // Mostra supermercados com preços abaixo da média
    printf("Supermercados com preços abaixo da media:\n");
    mostrarInferioresAMedia(supermercados, N, media);

    // Libera a memória alocada
    free(supermercados);
}

int main(void){
    int opcao;
  do{
    printf("\n\nEscolha uma das opcoes abaixo: \n");
    printf("\n\t0: Sair");
    printf("\n\t1: EXEMPLO 01");
    printf("\n\t2: EXEMPLO 02");
    printf("\n\t3: EXEMPLO 03");
    printf("\n\t4: EXEMPLO 04");
    printf("\n\t5: EXEMPLO 05");
    printf("\n\t6: EXEMPLO 06");
    printf("\n\t7: EXEMPLO 07");
    printf("\n\t8: EXEMPLO 08");
    printf("\n\t9: EXEMPLO 09");
    printf("\n\t10: EXEMPLO 10\n");
    scanf("%d", &opcao);
    getchar();

    switch(opcao){
        case 0:
            break;
        case 1:
            exemplo01();
            break;
        case 2:
            exemplo02();
            break;
        case 3:
            exemplo03();
            break;
        case 4:
            exemplo04();
            break;
        case 5:
            exemplo05();
            break;
        case 6:
            exemplo06();
            break;
        case 7:
            exemplo07();
            break;
        case 8:
            exemplo08();
            break;
        case 9:
            exemplo09();
            break;
        case 10:
            exemplo10();
            break;


        default:
            printf("Opcao invalida!\n");
            break;
    }

  } while(opcao != 0);

return 0;
}
