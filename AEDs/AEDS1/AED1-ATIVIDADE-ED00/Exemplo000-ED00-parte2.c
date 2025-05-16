/*
    AED1 - ED00 - parte 2
    DATA: 22/02/2024
    AUTORIA: ALESSANDRA FARIA RODRIGUES
    NUM. MATRICULA: 828333
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

void exemplo201(){
    // PROGRAMA PARA LER E IMPRIMIR UM VALOR INTEIRO
    // VARIAVEL:
     int X = 0;
     printf ( "EXEMPLO201 - LER E IMPRIMIR UM VALOR INTEIRO" );
     printf ( "\nFORNECER UM VALOR INTEIRO QUALQUER: " );
     scanf ( "%d", &X );
     getchar( ); // limpar a entrada de dados
     printf ( "\nO VALOR DIGITADO FOI: %d", X );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar( ); // para esperar
     //return ( EXIT_SUCCESS );

    //saida
    /*
        EXEMPLO201 - LER E IMPRIMIR UM VALOR INTEIRO
        FORNECER UM VALOR INTEIRO QUALQUER: 10

        O VALOR DIGITADO FOI: 10
        PRESSIONAR <Enter> PARA TERMINAR.
    */
}

void exemplo202(){
    // PROGRAMA PARA LER E IMPRIMIR UM VALOR REAL
    // VARIAVEL:
     double X = 0.0;
     printf ( "EXEMPLO202 - LER E IMPRIMIR UM VALOR REAL" );
     printf ( "\nFORNECER UM VALOR REAL QUALQUER: " );
     scanf ( "%lf", &X );
     getchar( ); // limpar a entrada de dados
     printf ( "\nO VALOR DIGITADO FOI: %lf", X );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO202 - LER E IMPRIMIR UM VALOR REAL
        FORNECER UM VALOR REAL QUALQUER: 12.2

        O VALOR DIGITADO FOI: 12.200000
        PRESSIONAR <Enter> PARA TERMINAR.
     */
}

void exemplo203(){
    // PROGRAMA PARA LER E IMPRIMIR UM CARACTERE
    // VARIAVEL:
     char X = '0';
     printf ( "EXEMPLO203 - LER E IMPRIMIR UM CARACTERE" );
     printf ( "\nFORNECER UM CARACTERE QUALQUER: " );
     scanf ( "%c", &X );
     getchar( ); // limpar a entrada de dados
     printf ( "\nO VALOR DIGITADO FOI: %c", X );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO203 - LER E IMPRIMIR UM CARACTERE
        FORNECER UM CARACTERE QUALQUER: a

        O VALOR DIGITADO FOI: a
        PRESSIONAR <Enter> PARA TERMINAR.
     */
}

void exemplo204(){
    // PROGRAMA PARA LER E IMPRIMIR, NO MAXIMO, 10 CARACTERES
    // VARIAVEL:
     char X [10];
     printf ( "EXEMPLO204 - LER E IMPRIMIR, NO MAXIMO, 09 CARACTERES" );
     printf ( "\nDIGITE, NO MAXIMO, 09 CARACTERES QUAISQUER: " );
     scanf ( "%s", X ); // OBS.: NAO usar o (&) para caracteres !
     getchar( ); // limpar a entrada de dados
     printf ( "\nFOI DIGITADO: %s", X );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO204 - LER E IMPRIMIR, NO MAXIMO, 09 CARACTERES
        DIGITE, NO MAXIMO, 09 CARACTERES QUAISQUER: abcd

        FOI DIGITADO: abcd
        PRESSIONAR <Enter> PARA TERMINAR.
     */
     //anotacao: quando é digitado mais de 9 caracteres, ainda sim é impresso todos os caacteres digitados
}

void exemplo205(){
    // PROGRAMA PARA LER E SOMAR DOIS VALORES INTEIROS
    // VARIAVEIS:
     int X=0, Y=0, Z=0;
     printf ( "EXEMPLO205 - LER E SOMAR DOIS VALORES INTEIROS" );
     printf ( "\nFORNECER UM VALOR INTEIRO QUALQUER: " );
     scanf ( "%d", &X );
     getchar( ); // limpar a entrada de dados
     printf ( "\nFORNECER OUTRO VALOR INTEIRO QUALQUER: " );
     scanf ( "%d", &Y );
     getchar( ); // limpar a entrada de dados
     Z = X + Y;
     printf ( "\nA SOMA DOS DOIS = %d", Z );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO205 - LER E SOMAR DOIS VALORES INTEIROS
        FORNECER UM VALOR INTEIRO QUALQUER: 2

        FORNECER OUTRO VALOR INTEIRO QUALQUER: 3

        A SOMA DOS DOIS = 5
        PRESSIONAR <Enter> PARA TERMINAR.
     */

}

void exemplo206(){
    // PROGRAMA PARA LER E SUBTRAIR DOIS VALORES REAIS
    // VARIAVEIS:
     float X=0.0, Y=0.0, Z=0.0;
     printf ( "EXEMPLO206 - LER E SUBTRAIR DOIS VALORES REAIS" );
     printf ( "\nFORNECER UM VALOR REAL QUALQUER: " );
     scanf ( "%f", &X );
     getchar( ); // limpar a entrada de dados
     printf ( "\nFORNECER OUTRO VALOR REAL QUALQUER: " );
     scanf ( "%f", &Y );
     getchar( ); // limpar a entrada de dados
     Z = X - Y;
     printf ( "\nA DIFERENCA ENTRE OS DOIS = %f", Z );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO206 - LER E SUBTRAIR DOIS VALORES REAIS
        FORNECER UM VALOR REAL QUALQUER: 5

        FORNECER OUTRO VALOR REAL QUALQUER: 2

        A DIFERENCA ENTRE OS DOIS = 3.000000
        PRESSIONAR <Enter> PARA TERMINAR.
     */
}

void exemplo207(){
    // PROGRAMA PARA OPERAR VALORES LOGICOS
    // VARIAVEIS:
     bool X=false, Y=false, Z=false;
     printf ( "EXEMPLO207 - OPERAR VALORES LOGICOS" );
     X = true;
     Y = false;
     Z = X || Y; // X ou Y
     printf ( "\nA DISJUNCAO ENTRE VERDADEIRO E FALSO = %d", Z );
     Z = X && Y; // X e Y
     printf ( "\nA CONJUNCAO ENTRE VERDADEIRO E FALSO = %d", Z );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO207 - OPERAR VALORES LOGICOS
        A DISJUNCAO ENTRE VERDADEIRO E FALSO = 1
        A CONJUNCAO ENTRE VERDADEIRO E FALSO = 0
        PRESSIONAR <Enter> PARA TERMINAR.
     */

}

void exemplo208(){
    // PROGRAMA PARA CALCULAR A VELOCIDADE DE UM VEICULO
    // VARIAVEIS:
     double D = 0.0, // Distancia
     T = 0.0, // Tempo
     V = 0.0; // Velocidade
     printf ( "EXEMPLO208 - CALCULAR A VELOCIDADE DE UM VEICULO" );
     printf ( "\nFORNECER UMA DISTANCIA QUALQUER EM METROS: " );
     scanf ( "%lf", &D );
     getchar( ); // limpar a entrada de dados
     printf ( "\nFORNECER O TEMPO PARA PERCORRE-LA EM SEGUNDOS: " );
     scanf ( "%lf", &T );
     getchar( ); // limpar a entrada de dados
     V = D / T;
     printf ( "\nV = D / T = %lf%s", V, " m/s " );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO208 - CALCULAR A VELOCIDADE DE UM VEICULO
        FORNECER UMA DISTANCIA QUALQUER EM METROS: 100

        FORNECER O TEMPO PARA PERCORRE-LA EM SEGUNDOS: 20

        V = D / T = 5.000000 m/s
        PRESSIONAR <Enter> PARA TERMINAR.
     */

}

void exemplo209(){
    // PROGRAMA PARA COMPARAR CARACTERES COM UMA SENHA
    // CONSTANTE:
     const char SENHA[5] = "XXXX";
    // VARIAVEL:
     char S [10];
     printf ( "EXEMPLO209 - COMPARAR CARACTERES COM UMA SENHA" );
     printf ( "\nFORNECER UMA CADEIA DE CARACTERES QUALQUER: " );
     scanf ( "%s", S ); // OBS.: NAO usar o (&) para caracteres !
     getchar( ); // limpar a entrada de dados
     printf ( "\nA COMPARACAO COM A SENHA = %d", (strcmp(S,SENHA)==0)?1:0 );
    // strcmp(S1,S2) compara S1 com S2
    // igual a 0: S1 = S2 => 1 ( verdadeiro )
    // diferente: S1 <> S2 => 0 ( falso )
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar( ); // para esperar
     //return ( ( EXIT_SUCCESS ) );

     //SAIDA
     /*
        EXEMPLO209 - COMPARAR CARACTERES COM UMA SENHA
        FORNECER UMA CADEIA DE CARACTERES QUALQUER: XXXX

        A COMPARACAO COM A SENHA = 1
        PRESSIONAR <Enter> PARA TERMINAR.
     */
}

void exemplo210(){
    // PROGRAMA PARA CALCULAR O ARCO TRIGONOMETRICO DE UM SENO
    // CONSTANTE:
     const double PI = 3.14;
    // VARIAVEIS:
     double ARCO = 0.0,
     COSSENO = 0.0,
     SENO = 0.0,
     TANGENTE = 0.0;
     printf ( "EXEMPLO210 - CALCULAR O ARCO TRIGONOMETRICO DE UM SENO" );
     printf ( "\nFORNECER O VALOR DO SENO: " );
     scanf ( "%lf", &SENO );
     getchar( ); // limpar a entrada de dados
     COSSENO = sqrt( 1.0 - pow(SENO,2) );
     TANGENTE = SENO / COSSENO;
     ARCO = atan( TANGENTE );
     printf ( "\nO ARCO TRIGONOMETRICO EM GRAUS = %lf", (ARCO*180.0/PI) );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO210 - CALCULAR O ARCO TRIGONOMETRICO DE UM SENO
        FORNECER O VALOR DO SENO: 0.5

        O ARCO TRIGONOMETRICO EM GRAUS = 30.015216
        PRESSIONAR <Enter> PARA TERMINAR.
     */
}

int main(void){
    int opcao;
    do{
        printf("\n\tMenu de opcoes: \n");
        printf("\t0) Sair\n");
        printf("\t1) Exemplo 201\n");
        printf("\t2) Exemplo 202\n");
        printf("\t3) Exemplo 203\n");
        printf("\t4) Exemplo 204\n");
        printf("\t5) Exemplo 205\n");
        printf("\t6) Exemplo 206\n");
        printf("\t7) Exemplo 207\n");
        printf("\t8) Exemplo 208\n");
        printf("\t9) Exemplo 209\n");
        printf("\t10) Exemplo 210\n");
        printf("\tDigite a opcao desejada: \n");
        scanf("%d", &opcao);

        switch(opcao){
            case 0: break;
            case 1:
                exemplo201();
                break;
            case 2:
                exemplo202();
                break;
            case 3:
                exemplo203();
                break;
            case 4:
                exemplo204();
                break;
            case 5:
                exemplo205();
                break;
            case 6:
                exemplo206();
                break;
            case 7:
                exemplo207();
                break;
            case 8:
                exemplo208();
                break;
            case 9:
                exemplo209();
                break;
            case 10:
                exemplo210();
                break;


            default:
                printf("Opcao invalida...");
                break;
        }


    } while(opcao != 0);
return 0;
}
