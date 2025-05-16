/*
Refação da avaliação 02
AED1 - 12/06/2024
ALUNA: ALESSANDRA FARIA RODRIGUES
MATRICULA: 828333
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//QUESTAO 06
int f06(char *nome){
    int tamanho = strlen(nome);
    int soma = 0;

    for(int i = 0; i < tamanho; i++){
        if(nome[i] == 'A' || nome[i] == 'J' || nome[i] == 'S'){
            soma += 1;
        } else if(nome[i] == 'B' || nome[i] == 'K' || nome[i] == 'T'){
            soma += 2;
        } else if(nome[i] == 'C' || nome[i] == 'L' || nome[i] == 'U'){
            soma += 3;
        } else if(nome[i] == 'D' || nome[i] == 'M' || nome[i] == 'V'){
            soma += 4;
        } else if(nome[i] == 'E' || nome[i] == 'N' || nome[i] == 'W'){
            soma += 5;
        } else if(nome[i] == 'F' || nome[i] == 'O' || nome[i] == 'X'){
            soma += 6;
        } else if(nome[i] == 'G' || nome[i] == 'P' || nome[i] == 'Y'){
            soma += 7;
        } else if(nome[i] == 'H' || nome[i] == 'Q' || nome[i] == 'R'){
            soma += 8;
        } else if(nome[i] == 'I' || nome[i] == 'R'){
            soma += 9;
        }
    }

    int num1, num2, resultado;
    if(soma > 9 && soma != 11 && soma != 22){
        while(soma > 9){
            num1 = soma%10;
            soma = soma / 10;
            num2 = soma%10;
            resultado = resultado + num1 + num2;
        }
        return resultado;
    } else if(soma < 10 || soma == 11 || soma == 22){
        return soma;
    }
}

//QUESTAO 07
struct Data {
    int dia, mes, ano;
};

struct Datas {
    int dias[3];
    struct Data data[3];
};

int calcular_dias_para_aniversario(int dias_vividos, struct Data aniversario) {
    int dia_atual = dias_vividos % 30;
    int mes_atual = (dias_vividos / 30) % 12;
    int ano_atual = dias_vividos / 365;

    int dias_ate_aniversario = (aniversario.dia - dia_atual) +
                               (aniversario.mes - mes_atual) * 30 +
                               (aniversario.ano - ano_atual) * 365;

    if (dias_ate_aniversario < 0) {
        dias_ate_aniversario += 365;
    }

    return dias_ate_aniversario;
}

void p07(){
struct Datas professores = {
        {9876, 8967, 6789},
        {
            {15, 6, 1990},
            {10, 7, 1988},
            {5, 8, 1992}
        }
    };

    int menor_tempo = calcular_dias_para_aniversario(professores.dias[0], professores.data[0]);
    int indice_professor = 0;

    for (int i = 1; i < 3; i++) {
        int tempo_ate_aniversario = calcular_dias_para_aniversario(professores.dias[i], professores.data[i]);
        if (tempo_ate_aniversario < menor_tempo) {
            menor_tempo = tempo_ate_aniversario;
            indice_professor = i;
        }
    }

    printf("O professor que fara aniversario primeiro e o professor %d\n", indice_professor + 1);
}

//QUESTAO 08
void p08(){
    FILE *arquivo = fopen("DADOS.TXT", "r");
    FILE *arquivoImpar = fopen("IMPAR.TXT", "w");
    FILE *arquivoPar = fopen("PAR.TXT", "w");

    int valor;
    while((fscanf(arquivo, "%d", &valor)) != EOF){
        if(valor%2 == 0){
            fprintf(arquivoPar, "%d\n", valor);
        } else {
            fprintf(arquivoImpar, "%d\n", valor);
        }
    }

    fclose(arquivo);
    fclose(arquivoImpar);
    fclose(arquivoPar);

    FILE *arquivoResultado = fopen("RESULTADO.TXT", "w");
    arquivoImpar = fopen("IMPAR.TXT", "r");

    while((fscanf(arquivoImpar, "%d", &valor)) != EOF){
        fprintf(arquivoResultado, "%d\n", valor);
    }
    fclose(arquivoImpar);

    arquivoPar = fopen("PAR.TXT", "r");

    while((fscanf(arquivoPar, "%d", &valor)) != EOF){
        fprintf(arquivoResultado, "%d\n", valor);
    }
    fclose(arquivoPar);
    fclose(arquivoResultado);
}

int main(void){
    printf("QUESTAO 06\n");
    int resultado = f06("ZIRALDO");
    printf("%d", resultado);

    printf("\n\nQUESTAO 07\n");
    p07();

    printf("\n\nQUESTAO 08\n");
    p08();
return 0;
}
