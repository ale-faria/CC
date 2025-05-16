/*
    AED1 - ED08 - 23/04/2024
    AUTORIA: ALESSANDRA FARIA RODRIGUES
    NUM. MATRICULA: 828333
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void metodo0811(){
    int n;
    int y;
    printf("METODO 0811\n\n");
    //garantindo que o arranjo nao seja zero ou negativo
    do{
    printf("Digite o tamanho do arranjo: ");
    scanf("%d", &n);
    getchar();
    } while (n <= 0);

    printf("Tamanho do arranjo = %d\n\n", n);
    int vetor[n];

    //preenchendo arranjo com valores positivos pares
    for(int i = 0; i < n; i++){
        do{
            printf("Digite o valor da posicao %d: ", i+1);
            scanf("%d", &y);
            getchar();
        } while(y <= 0 || y%2!=0);

        vetor[i] = y;
    }

    printf("\nValores do arranjo = ");
    //mostrando arranjo
    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }

    printf("\n\nAperte enter para finalizar METODO0811...");
    getchar();
}

void auxiliar0812(char * fileName, int vetor[], int tamanhoDoVetor){
    //abrindo arquivo e gravando os valores do vetor
    FILE *arquivo = fopen(fileName, "w");

    if(!arquivo){
        printf("Arquivo nao existe...\n");
        return;
    }

    for(int i = 0; i < tamanhoDoVetor; i++){
        int y = vetor[i];
        fprintf(arquivo, "%d ", y);
    }

    //fechando arquivo
    fclose(arquivo);
    //abrindo o mesmo arquivo anterior, porém agora no modo de leitura
    FILE *arquivo2 = fopen(fileName, "r");
    //abrindo arquivoResposta para gravar o tamanho de vetor e os elementos pares positivos
    FILE *arquivoResposta = fopen("RESPOSTA_0812.txt", "w");

    if(!arquivo2 || !arquivoResposta){
        printf("Arquivo nao existe...\n");
        return;
    }

    fprintf(arquivoResposta, "%d\n", tamanhoDoVetor);
    for(int i = 0; i < tamanhoDoVetor; i++){
        int y;
        //pegando elementos do arquivo, se for par e positivo esse valor vai ser gravado no arquivoResposta
        fscanf(arquivo2, "%d", &y);
        if(y%2 == 0 && y > 0){
            fprintf(arquivoResposta, "%d\n", y);
        }
    }
    printf("Gravado no arquivo... Finalizado!\n");
    //fechando os arquivos
    fclose(arquivo2);
    fclose(arquivoResposta);
}

void metodo0812(){
    int tamanhoDoVetor;
    printf("METODO 0812\n\n");
    do{
        printf("Digite o tamanho do vetor: ");
        scanf("%d", &tamanhoDoVetor);
        getchar();
    } while (tamanhoDoVetor <= 0);

    int vetor[tamanhoDoVetor];

    //preenchendo vetor
    for(int i = 0; i < tamanhoDoVetor; i++){
        int y;
        printf("Digite o valor da posicao %d: ", i+1);
        scanf("%d", &y);
        getchar();
        vetor[i] = y;
    }

    //chamando procedimento e passando como paramentro o arquivo, vetor preenchido e o tamanho do vetor
    auxiliar0812("EXEMPLO_0812.txt", vetor, tamanhoDoVetor);
    printf("\n\nAperte enter para finalizar METODO0812...");
    getchar();
}

int geraNumeroAleatorio(int inicio, int fim){
    int numeroAleatorio;
    int y = fim - inicio;
    numeroAleatorio = inicio + (rand() % y);
    return numeroAleatorio;
}

void metodo0813(){
    int inicio, fim, n, resultado;
    printf("METODO 0813\n\n");

    do{
        printf("Digite o limite de inicio: ");
        scanf("%d", &inicio);
        getchar();
        printf("Digite o limite de fim: ");
        scanf("%d", &fim);
        getchar();
    } while (inicio > fim);

    do{
        printf("Digite a quantidade: ");
        scanf("%d", &n);
        getchar();
    } while (n <= 0);

    int vetor[n];
    printf("\n");
    for(int i = 0; i < n; i++){
        resultado = geraNumeroAleatorio(inicio, fim);
        printf("%d ", resultado);
        vetor[i] = resultado;
    }

    FILE *arquivo = fopen("DADOS.txt", "w");
    if(arquivo == NULL){
        printf("Arquivo nao existe...");
        return;
    }

    fprintf(arquivo, "%d\n", n);
    for(int i = 0; i < n; i++){
        int y = vetor[i];
        fprintf(arquivo, "%d\n", y);
    }
    fclose(arquivo);
    printf("\n\nGravado no arquivo com sucesso!\n\n");
    printf("Aperte enter para finalizar METODO0813...");
    getchar();
}

int lerArranjoDoArquivo(int y, char * fileName){
    FILE *arquivo = fopen(fileName, "r");
    if(!arquivo){
        printf("Arquivo nao existe...");
        return 0;
    }

    int valor;
    for(int i = 0; i <= y; i++){
        fscanf(arquivo, "%d", &valor);
    }
    fclose(arquivo);
    return valor;
}

int menorImparNoArranjo(int tamanho, int vetor[]){
  int menor = vetor[0];
  int cont = 0;
  for(int i = 0; i < tamanho; i++){
    int y = vetor[i];
    if(y <= menor && y%2 != 0){
      menor = y;
      cont++;
    }
  }
  if(cont == 0)
    return 0;
  else
    return menor;
}

void metodo0814(){
    printf("METODO 0814\n\n");
    FILE *arquivo = fopen("DADOS.txt", "r");
    if(!arquivo){
        printf("Arquivo nao existe...");
        return;
    }
    int n, resultado;
    int y = 1;
    fscanf(arquivo, "%d", &n);
    if(n > 0){
        int vetor[n];
        for(int i = 0; i < n; i++){
            resultado = lerArranjoDoArquivo(y, "DADOS.txt");
            y++;
            vetor[i] = resultado;
        }

        resultado = menorImparNoArranjo(n, vetor);

        if(resultado == 0){
            printf("Nao existe impar no arranjo\n");
        } else {
            printf("Menor impar no arranjo = %d\n", resultado);
        }
    } else {
        printf("Quantidade inicial é zero ou negativo\n");
    }
    fclose(arquivo);
    printf("Aperte enter para finalizar METODO0814...");
    getchar();
}

int maiorImparNoArranjo(int tamanho, int vetor[]){
  int maior = vetor[0];
  int cont = 0;
  for(int i = 0; i < tamanho; i++){
    int y = vetor[i];
    if(y >= maior && y%2 != 0){
      maior = y;
      cont++;
    }
  }
  if(cont == 0)
    return 0;
  else
    return maior;
}

void metodo0815(){
    printf("METODO 0815\n\n");
    FILE *arquivo = fopen("DADOS.txt", "r");
    if(!arquivo){
        printf("Arquivo nao existe...");
        return;
    }
    int n, resultado;
    int y = 1;
    fscanf(arquivo, "%d", &n);
    if(n > 0){
        int vetor[n];
        for(int i = 0; i < n; i++){
            resultado = lerArranjoDoArquivo(y, "DADOS.txt");
            y++;
            vetor[i] = resultado;
            //printf("%d ", resultado);
        }

        resultado = maiorImparNoArranjo(n, vetor);

        if(resultado == 0){
            printf("Nao existe impar no arranjo\n");
        } else {
            printf("Maior impar no arranjo = %d\n", resultado);
        }
    } else {
        printf("Quantidade inicial é zero ou negativo\n");
    }
    fclose(arquivo);
    printf("Aperte enter para finalizar METODO0815...");
    getchar();
}

int mediaArranjo(int n, int vetor[]){
    int media = 0;
    int y;
    for(int i = 0; i < n; i++){
        y = vetor[i];
        media += y;
    }
    media = media/n;
    return media;
}

void metodo0816(){
    printf("METODO 0816\n\n");
    FILE *arquivo = fopen("DADOS.txt", "r");
    if(!arquivo){
        printf("Arquivo nao existe...");
        return;
    }
    int n, resultado;
    int y = 1;
    if(fscanf(arquivo, "%d", &n) == EOF){
        printf("Arquivo vazio");
        return;
    }
    fscanf(arquivo, "%d", &n);
    if(n > 0){
        int vetor[n];
        for(int i = 0; i < n; i++){
            resultado = lerArranjoDoArquivo(y, "DADOS.txt");
            vetor[i] = resultado;
            y++;
        }

        int media = mediaArranjo(n, vetor);


        FILE * arquivoMediaMenor = fopen("MEDIA_MENOR.txt", "w");
        FILE * arquivoMediaMaior = fopen("MEDIA_MAIOR.txt", "w");

        if(!arquivoMediaMenor || !arquivoMediaMaior){
            printf("Arquivo nao existe...");
            return;
        }
        for(int i = 0; i < n; i++){
            y = vetor[i];
            if(y <= media){
                fprintf(arquivoMediaMenor, "%d\n", y);
            } else {
                fprintf(arquivoMediaMaior, "%d\n", y);
            }
        }
    fclose(arquivoMediaMenor);
    fclose(arquivoMediaMaior);
    printf("\n\nGravado no arquivo com sucesso!\n\n");
    } else {
        printf("Quantidade inicial é zero ou negativo\n");
    }
    fclose(arquivo);
    printf("Aperte enter para finalizar METODO0816...");
    getchar();
}

int estaOrdenadoDecrescente(int vetor[], int tamanho){
    int cont = 0;
    for(int i = 0; i < tamanho-1; i++){
        int atual = vetor[i];
        int proxima = vetor[i+1];
        if(atual < proxima){
            cont++;
            //para sair do loop sem usar break
            i = tamanho;
        }
    }
    return cont;
}

void metodo0817(){
    printf("METODO 0817\n\n");
    int vetor[] = {5,4,3,2,1};
    int resultado = estaOrdenadoDecrescente(vetor, 5);
    for(int i = 0; i < 5; i++){
        printf("[%d] ", vetor[i]);
    }
    printf("\nEsta ordenado decrescente? \n");
    if(resultado == 0){
        printf("Sim, esta ordenado\n");
    } else {
        printf("NAO esta ordenado\n");
    }
    printf("\nAperte enter para finalizar METODO0817...");
    getchar();
}

int acharValor(int procurado, int posicao, int tamanho, int vetor[]){
    int cont = 0;
    int resultado;
    int y;
    for(int i = posicao; i < tamanho; i++){
        y = vetor[i];
        if(y == procurado){
            cont++;
            resultado = i;
            //para sair do loop
            i = tamanho;
        }
    }
    if(cont > 0){
        return resultado;
    } else {
        return -1;
    }
}

int acharQuantidade(int procurado, int posicao, int tamanho, int vetor[]){
    int cont = 0;
    int y;
    for(int i = posicao; i < tamanho; i++){
        y = vetor[i];
        if(y == procurado){
            cont++;
        }
    }
    return cont;
}

//obs: 0818, 0819 e 0820 estao juntas no metodo0818
void metodo0818(){
    printf("METODO 0818\n\n");
    FILE *arquivo = fopen("DADOS.txt", "r");
    if(!arquivo){
        printf("Arquivo nao existe...");
        return;
    }
    int n;
    if(fscanf(arquivo, "%d", &n) == EOF){
        printf("Arquivo vazio");
        return;
    }
    fscanf(arquivo, "%d", &n);
    if(n > 0){
        int y = 1;
        int vetor[n];
        int procurado, posicao;
        //lendo o arquivo e colocando em um arranjo
        for(int i = 0; i < n; i++){
            int resultado = lerArranjoDoArquivo(y, "DADOS.TXT");
            vetor[i] = resultado;
            y++;
        }

        printf("Digite o valor a ser procurado: ");
        scanf("%d", &procurado);
        getchar();
        do{
            printf("A partir de qual posicao procurar? ");
            scanf("%d", &posicao);
            getchar();
        } while (posicao < 0 && posicao >= n);

        int existe = acharValor(procurado, posicao, n, vetor);
        int quantidade = acharQuantidade(procurado, posicao, n, vetor);
        if(existe == -1){
            printf("Nao encontrado\n");
        } else {
            printf("Encontrado na posicao %d e existem %d valores iguais\n", existe, quantidade);
        }
    } else {
        printf("Quantidade inicial é zero ou negativo\n");
    }
    fclose(arquivo);
    printf("\nAperte enter para finalizar METODO0818...");
    getchar();
}

int *divisoresImpares(int numero){
    int *vetor = (int*)malloc(numero * sizeof(int));
    int y = 0;
    for(int i = 1; i <= numero; i++){
        if(numero%i == 0 && i%2 != 0){
            vetor[y] = i;
            y++;
        }
}
    return vetor;
}

int quantidadeDivisoresImpares(int numero){
    int cont = 0;
    for(int i = 1; i <= numero; i++){
        if(numero%i == 0 && i%2 != 0){
            //printf("%d ", i);
            cont++;
        }
    }
    return cont;
}

void metodo08E1(){
    int numero;
    printf("METODO 08E1\n\n");
    printf("Digite um numero: ");
    scanf("%d", &numero);
    getchar();

    int quantidade = quantidadeDivisoresImpares(numero);
    printf("A quantidade de divisores impares do numero %d e = %d\n", numero, quantidade);
    int *vetorDividores = divisoresImpares(numero);
    printf("Divisores: ");
    for(int i = 0; i < quantidade; i++){
        printf("%d ", vetorDividores[i]);
    }
    printf("\n");

    FILE *arquivo = fopen("DIVISORES.txt", "w");
    fprintf(arquivo, "Numero = %d\n", numero);
    fprintf(arquivo, "Quantidade divisores = %d\n", quantidade);
    fprintf(arquivo, "Divisores: ");
    for(int i = 0; i < quantidade; i++){
        fprintf(arquivo, "%d ", vetorDividores[i]);
    }

    fclose(arquivo);
    free(vetorDividores);
    printf("\nAperte enter para finalizar METODO08E1...");
    getchar();
}

int funcao08E2(char *palavra){
    int tamanho = strlen(palavra);
    if(palavra[0] != 'c' && palavra[0] != 'C' && palavra[tamanho-1] != 'c' && palavra[tamanho-1] != 'C'){
        return 0;
    } else {
        return 1;
    }

}

void metodo08E2(){
    FILE *arquivo = fopen("PALAVRAS.txt", "r");
    int y = 0;
    char palavra[80];
    while(! feof (arquivo) && y < 10 ){
        fscanf(arquivo, "%s", &palavra);
        int resultado = funcao08E2(palavra);
        if(resultado == 0){
            printf("%s \n", palavra);
            y++;
        }
    }
    fclose(arquivo);
    printf("\nAperte enter para finalizar METODO08E2...");
    getchar();
}

int main(void){
   int opcao;
  do{
    printf("\n\nEscolha uma das opcoes abaixo: \n");
    printf("\n\t0: Sair");
    printf("\n\t1: Metodo0811");
    printf("\n\t2: Metodo0812");
    printf("\n\t3: Metodo0813");
    printf("\n\t4: Metodo0814");
    printf("\n\t5: Metodo0815");
    printf("\n\t6: Metodo0816");
    printf("\n\t7: Metodo0817");
    printf("\n\t8: Metodo0818");
    printf("\n\t9: Metodo0819");
    printf("\n\t10: Metodo0820");
    printf("\n\t11: Metodo08E1");
    printf("\n\t12: Metodo08E2\n");
    scanf("%d", &opcao);
    getchar();

    switch(opcao){
        case 0:
            break;
        case 1:
            metodo0811();
            break;
        case 2:
            metodo0812();
            break;
        case 3:
            metodo0813();
            break;
        case 4:
            metodo0814();
            break;
        case 5:
            metodo0815();
            break;
        case 6:
            metodo0816();
            break;
        case 7:
            metodo0817();
            break;
        case 8:
            metodo0818();
            break;
        case 9:
            metodo0818();
            break;
        case 10:
            metodo0818();
            break;
        case 11:
            metodo08E1();
            break;
        case 12:
            metodo08E2();
            break;

        default:
            printf("Opcao invalida!\n");
            break;
    }

  } while(opcao != 0);


return 0;
}
