/*
    AED1 - ED10 - 08/05/2024
    AUTORIA: ALESSANDRA FARIA RODRIGUES
    NUM. MATRICULA: 828333
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Dados{
    int quantidade;
    int *valores;
}Dados;

typedef struct DadosMatrix{
    int linha;
    int coluna;
    int **valores;
}DadosMatrix;

//função para gerar um valor aleatorio dentro de um intervalo
int geraNumeroAleatorio(int inicio, int fim){
    int numeroAleatorio;
    int y = fim - inicio;
    numeroAleatorio = inicio + (rand() % y);
    return numeroAleatorio;
}

//função para gerar os valores aleatorios e armazena-los na struct
void gerarValores(Dados *dados, int inicio, int fim){
    int quant;
    do{
        printf("Digite a quantidade: ");
        scanf("%d", &quant);
        getchar();
    } while(quant <= 0);

    dados->quantidade = quant;
    dados->valores = (int *)malloc(dados->quantidade * sizeof(int));

    for (int i = 0; i < dados->quantidade; i++) {
        dados->valores[i] = geraNumeroAleatorio(inicio, fim);
    }
}

//grava os valores em um arquivo
void gravarValores(Dados *dados){
    FILE *arquivo = fopen("DADOS.txt", "w");
    if(!arquivo){
        printf("Arquivo nao existe...\n");
        return;
    }

    fprintf(arquivo, "%d\n", dados->quantidade);
    for(int i = 0; i < dados->quantidade; i++){
        fprintf(arquivo, "%d\n", dados->valores[i]);
    }

    printf("Gravado no arquivo...\n");
    fclose(arquivo);
}

void metodo1011(){
    int inicio, fim, quant;
    Dados dados;
    printf("METODO 1011\n\n");

    do{
        printf("Digite o limite de inicio: ");
        scanf("%d", &inicio);
        getchar();
        printf("Digite o limite de fim: ");
        scanf("%d", &fim);
        getchar();
    } while (inicio > fim);

    gerarValores(&dados, inicio, fim);
    gravarValores(&dados);

    free(dados.valores); //limpar memoria alocada

    printf("\nAperte enter para finalizar METODO1011...");
    getchar();
}

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
    return dados;
}

//função para procurar um valor em um arranjo
int arraySearch(int valor, Dados arranjo){
    for(int i = 0; i < arranjo.quantidade; i++){
        if(arranjo.valores[i] == valor){
            return i; //retorna o indice do valor procurado
        }
    }
    return -1; //retorna -1 se o valor nao for encontrado
}

void metodo1012(){
    int procurado;
    printf("METODO 1012\n\n");

    printf("Digite o valor procurado: ");
    scanf("%d", &procurado);
    getchar();

    Dados arranjo;
    arranjo = readArrayFromFile("DADOS.txt");

    int resposta;
    resposta = arraySearch(procurado, arranjo);

    if(resposta == -1){
        printf("O valor %d nao foi encontrado no arranjo\n", procurado);
    } else {
        printf("O valor %d foi encontrado na posicao %d do arranjo\n", procurado, resposta);
    }

    free(arranjo.valores);

    printf("\nAperte enter para finalizar METODO1012...");
    getchar();
}

//função para comparar os valores de dois arranjos diferentes
int arrayCompare(Dados arranjo1, Dados arranjo2){
    int contDif = 0;
    if(arranjo1.quantidade == arranjo2.quantidade){ //tamanhos iguais
        for(int i = 0; i < arranjo1.quantidade; i++){
            if(arranjo1.valores[i] != arranjo2.valores[i]){
                contDif++;
            }
        }
        if(contDif == 0){
            return 1; //retorna 1 se tiverem tamanhos iguais e valores iguais
        }
    }

    return 0; //retorna 0 se tiverem tamanhos diferentes ou valores repetidos
}

void metodo1013(){
    printf("METODO 1013\n\n");

    Dados arranjo1, arranjo2;
    arranjo1 = readArrayFromFile("DADOS1.txt");
    arranjo2 = readArrayFromFile("DADOS2.txt");

    int resposta;
    resposta = arrayCompare(arranjo1, arranjo2);

    if(resposta){
        printf("Os arranjos sao iguais\n");
    } else {
        printf("Os arranjos sao diferentes\n");
    }

    free(arranjo1.valores);
    free(arranjo2.valores);

    printf("\nAperte enter para finalizar METODO1013...");
    getchar();
}

Dados arrayAdd(Dados *arranjo1, int constante, Dados *arranjo2){
    if(arranjo1->quantidade == arranjo2->quantidade){ //tamanhos iguais

        Dados arraySoma;
        arraySoma.quantidade = arranjo1->quantidade;
        arraySoma.valores = (int *)malloc(arraySoma.quantidade * sizeof(int));

        for(int i = 0; i < arraySoma.quantidade; i++){
            arraySoma.valores[i] = arranjo1->valores[i] + (constante * arranjo2->valores[i]);
        }

        return arraySoma;
    } else {
        exit(1);
    }
}

//procedimento para printar um arranjo
void printArray(Dados arranjo){
    for(int i = 0; i < arranjo.quantidade; i++){
        printf("%d ", arranjo.valores[i]);
    }
    printf("\n");
}

void metodo1014(){
    printf("METODO 1014\n\n");

    Dados arranjo1, arranjo2;
    arranjo1 = readArrayFromFile("DADOS1.txt");
    arranjo2 = readArrayFromFile("DADOS2.txt");

    printArray(arranjo1);
    printArray(arranjo2);

    Dados soma;
    soma = arrayAdd(&arranjo1, 1, &arranjo2);
    printArray(soma);

    free(arranjo1.valores);
    free(arranjo2.valores);
    free(soma.valores);

    printf("\nAperte enter para finalizar METODO1014...");
    getchar();
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

void metodo1015(){
    printf("METODO 1015\n\n");

    Dados arranjo;
    arranjo = readArrayFromFile("DADOS1.txt");

    int resposta;
    resposta = isArrayDecrescent(&arranjo);

    if(resposta){
        printf("O arranjo esta em ordem decrescente\n");
    }  else {
        printf("O arranjo nao esta ordenado\n");
    }

    printf("\nAperte enter para finalizar METODO1015...");
    getchar();
}

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

//cria matriz transposta
DadosMatrix matrixTranspose(DadosMatrix matrix){
    DadosMatrix resultado;
    resultado.linha = matrix.coluna;
    resultado.coluna = matrix.linha;
    resultado.valores = (int **)malloc(resultado.linha * sizeof(int));
    for(int i = 0; i < resultado.linha; i++){
        resultado.valores[i] = (int *)malloc(resultado.coluna * sizeof(int));
        for(int j = 0; j < resultado.coluna; j++){
            resultado.valores[i][j] = matrix.valores[j][i];
        }
    }

    return resultado;
}

void metodo1016(){
    printf("METODO 1016\n\n");

    DadosMatrix matrix1, matrix2;
    matrix1 = readMatrixFromFile("DADOSMATRIX.txt");
    printMatrix(matrix1);

    matrix2 = matrixTranspose(matrix1);
    printMatrix(matrix2);

    free(matrix1.valores);
    free(matrix2.valores);

    printf("\nAperte enter para finalizar METODO1016...");
    getchar();
}

//função para verificar se uma matriz possui apenas valores iguais a zero
int matrixZero(DadosMatrix *matrix){
    int cont = 0;
    for(int i = 0; i < matrix->linha; i++){
        for(int j = 0; j < matrix->coluna; j++){
            if(matrix->valores[i][j] != 0){
                cont++;
            }
        }
    }

    if(cont == 0){
        return 1; //matrix possui apenas zeros
    } else {
        return 0; //matrix possui valores diferentes de zero
    }
}

void metodo1017(){
    printf("METODO 1017\n\n");

    DadosMatrix matrix;
    matrix = readMatrixFromFile("DADOSMATRIX.txt");

    int resposta;
    resposta = matrixZero(&matrix);

    if(resposta){
        printf("A matriz possui apenas valores iguais a zero\n");
    } else {
        printf("A matriz possui valores diferentes de zero\n");
    }

    printf("\nAperte enter para finalizar METODO1017...");
    getchar();
}

//função para comparar os valores de duas matrizes diferentes
int matrixCompare(DadosMatrix *matrix1, DadosMatrix *matrix2){
    if(matrix1->linha != matrix2->linha || matrix1->coluna != matrix2->coluna){
        return 0; //retorna 0 se as matrizes tiverem dimensões diferentes
    }

    for(int i = 0; i < matrix1->linha; i++){
        for(int j = 0; j < matrix1->coluna; j++){
            if(matrix1->valores[i][j] != matrix2->valores[i][j]){
                return 0; //retorna 0 se os valores forem diferentes
            }
        }
    }

    return 1; //retorna 1 se tamanhos iguais e elementos iguais


}

void metodo1018(){
    printf("METODO 1018\n\n");

    DadosMatrix matrix1, matrix2;
    matrix1 = readMatrixFromFile("DADOSMATRIX.txt");
    matrix2 = readMatrixFromFile("DADOSMATRIX2.txt");

    int resposta;
    resposta = matrixCompare(&matrix1, &matrix2);
    if(resposta){
        printf("As matrizes sao iguais\n");
    } else {
        printf("As matrizes sao diferentes\n");
    }

    free(matrix1.valores);
    free(matrix2.valores);

    printf("\nAperte enter para finalizar METODO1018...");
    getchar();
}

DadosMatrix matrixAdd(DadosMatrix *matrix1, int constante, DadosMatrix *matrix2){
    if(matrix1->linha != matrix2->linha || matrix1->coluna != matrix2->coluna){
        exit(1); //em caso de tamanhos diferentes
    }

    DadosMatrix resultado;
    resultado.linha = matrix1->linha;
    resultado.coluna = matrix2->coluna;
    resultado.valores = (int **)malloc(resultado.linha * sizeof(int));
    for(int i = 0; i < matrix1->linha; i++){
        resultado.valores[i] = (int *)malloc(resultado.coluna * sizeof(int));
        for(int j = 0; j < matrix1->coluna; j++){
            resultado.valores[i][j] = matrix1->valores[i][j] + (constante * matrix2->valores[i][j]);
        }
    }

    return resultado;
}

void metodo1019(){
    printf("METODO 1019\n\n");

    DadosMatrix matrix1, matrix2, soma;
    matrix1 = readMatrixFromFile("DADOSMATRIX.txt");
    matrix2 = readMatrixFromFile("DADOSMATRIX2.txt");

    soma = matrixAdd(&matrix1, -1, &matrix2);

    printMatrix(matrix1);
    printMatrix(matrix2);
    printMatrix(soma);

    free(matrix1.valores);
    free(matrix2.valores);
    free(soma.valores);

    printf("\nAperte enter para finalizar METODO1019...");
    getchar();
}

DadosMatrix matrixProduct(DadosMatrix *matrix1, DadosMatrix *matrix2){
    if(matrix1->linha != matrix2->linha || matrix1->coluna != matrix2->coluna){
        exit(1);
    }

    DadosMatrix resultado;
    resultado.linha = matrix1->linha;
    resultado.coluna = matrix1->coluna;
    resultado.valores = (int**)malloc(resultado.linha * sizeof(int));
    for(int i = 0; i < resultado.linha; i++){
        resultado.valores[i] = (int*)malloc(resultado.coluna * sizeof(int));
        for(int j = 0; j < resultado.coluna; j++){
            resultado.valores[i][j] = matrix1->valores[i][j] * matrix2->valores[i][j];
        }
    }

    return resultado;
}

void metodo1020(){
    printf("METODO 1020\n\n");

    DadosMatrix matrix1, matrix2, soma;
    matrix1 = readMatrixFromFile("DADOSMATRIX.txt");
    matrix2 = readMatrixFromFile("DADOSMATRIX2.txt");
    soma = matrixProduct(&matrix1, &matrix2);

    printMatrix(matrix1);
    printMatrix(matrix2);
    printMatrix(soma);

    free(matrix1.valores);
    free(matrix2.valores);
    free(soma.valores);

    printf("\nAperte enter para finalizar METODO1020...");
    getchar();
}

Dados sortArrayDown(Dados arranjo){
    int temp;
    for(int i = 0; i < arranjo.quantidade - 1; i++){
        for(int j = i + 1; j < arranjo.quantidade; j++){
            if(arranjo.valores[i] < arranjo.valores[j]){
                temp = arranjo.valores[i];
                arranjo.valores[i] = arranjo.valores[j];
                arranjo.valores[j] = temp;
            }
        }
    }

    return arranjo;
}

void metodo10E1(){
    printf("METODO 10E1\n\n");

    Dados arranjo, ordenado;
    arranjo = readArrayFromFile("DADOS1.txt");
    printArray(arranjo);

    ordenado = sortArrayDown(arranjo);
    printArray(ordenado);

    free(arranjo.valores);

    printf("\nAperte enter para finalizar METODO10E1...");
    getchar();
}

int isIdentityMatrix(DadosMatrix *matrix) {
    if (matrix->linha != matrix->coluna) {
        return 0; // Se não for uma matriz quadrada, não pode ser a identidade
    }

    for (int i = 0; i < matrix->linha; i++) {
        for (int j = 0; j < matrix->coluna; j++) {
            if ((i == j && matrix->valores[i][j] != 1) || (i != j && matrix->valores[i][j] != 0)) {
                return 0; // Se algum elemento não está de acordo com a definição de identidade, retorna falso
            }
        }
    }

    return 1; // Se passou por todos os elementos e nenhum falhou, é a identidade
}

void metodo10E2(){
    printf("METODO 10E2\n\n");

    DadosMatrix matrix1, matrix2, produto;
    matrix1 = readMatrixFromFile("DADOSMATRIX.txt");
    matrix2 = readMatrixFromFile("DADOSMATRIX2.txt");

    produto = matrixProduct(&matrix1, &matrix2);

    int resposta = isIdentityMatrix(&produto);
    if(resposta){
        printf("E matriz identidade\n");
    } else{
        printf("Nao e matriz identidade\n");
    }

    printf("\nAperte enter para finalizar METODO10E2...");
    getchar();
}

int main(void){
    int opcao;
  do{
    printf("\n\nEscolha uma das opcoes abaixo: \n");
    printf("\n\t0: Sair");
    printf("\n\t1: Metodo1011");
    printf("\n\t2: Metodo1012");
    printf("\n\t3: Metodo1013");
    printf("\n\t4: Metodo1014");
    printf("\n\t5: Metodo1015");
    printf("\n\t6: Metodo1016");
    printf("\n\t7: Metodo1017");
    printf("\n\t8: Metodo1018");
    printf("\n\t9: Metodo1019");
    printf("\n\t10: Metodo1020");
    printf("\n\t11: Metodo10E1");
    printf("\n\t12: Metodo10E2\n");
    scanf("%d", &opcao);
    getchar();

    switch(opcao){
        case 0:
            break;
        case 1:
            metodo1011();
            break;
        case 2:
            metodo1012();
            break;
        case 3:
            metodo1013();
            break;
        case 4:
            metodo1014();
            break;
        case 5:
            metodo1015();
            break;
        case 6:
            metodo1016();
            break;
        case 7:
            metodo1017();
            break;
        case 8:
            metodo1018();
            break;
        case 9:
            metodo1018();
            break;
        case 10:
            metodo1018();
            break;
        case 11:
            metodo10E1();
            break;
        case 12:
            metodo10E2();
            break;

        default:
            printf("Opcao invalida!\n");
            break;
    }

  } while(opcao != 0);

return 0;
}
