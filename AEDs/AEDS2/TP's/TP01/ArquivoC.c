#include <stdio.h>
#include <stdlib.h>

int main(void){
    char *fileName = "valores.txt";
    FILE *arquivo;
    int n;
    double valor;

    //lendo o n�mero inteiro
    //printf("Digite a quantidade de valores: ");
    scanf("%d", &n);

    arquivo = fopen(fileName, "w");
    if(!arquivo){
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    //lendo valores e escrevendo no arquivo
    for(int i = 0; i < n; i++){
        scanf("%lf", &valor);
        //fun��o fwrite usado para gravar em arquivo bin�rio
        fwrite(&valor, sizeof(double), 1, arquivo);
    }

    fclose(arquivo);

    arquivo = fopen(fileName, "r");
    if(!arquivo){
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    //lendo valores do arquivo de tras pra frente
    for(int i = n-1; i >= 0; i--){
         // Mover o ponteiro de arquivo para a posi��o do i-�simo valor
        fseek(arquivo, i * sizeof(double), SEEK_SET);
        fread(&valor, sizeof(double), 1, arquivo);
        printf("%g\n", valor);
    }

    fclose(arquivo);


return 0;
}
