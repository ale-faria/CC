/*
    AED1 - ED00 - EXTRAS - parte 2
    DATA: 25/02/2024
    AUTORIA: ALESSANDRA FARIA RODRIGUES
    NUM. MATRICULA: 828333
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef int TABELA [10];
void exemplo701(){
    // PROGRAMA PARA LER UMA TABELA DE INTEIROS
    // VARIAVEIS:
     TABELA V;
     int X = 0;
     printf ( "EXEMPLO701 - LER UM TABELA DE 10 INTEIROS\n" );
    // REPETIR PARA CADA POSICAO
     for ( X = 0; X < 10; X++ )
     { // a primeira posicao e' zero !
     printf ( "\nFORNECER O %d o. INTEIRO : ",(X+1) );
     scanf ( "%d", &V[ X ] );
     getchar( ); // limpar a entrada de dados
     } // FIM REPETIR
     printf ( "\nVETOR LIDO: \n" );
    // REPETIR PARA CADA POSICAO
     for ( X = 0; X < 10; X++ )
     {
     printf ( "%d ", V[ X ] );
     } // FIM REPETIR
     printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO701 - LER UM TABELA DE 10 INTEIROS

        FORNECER O 1 o. INTEIRO : 5

        FORNECER O 2 o. INTEIRO : 10

        FORNECER O 3 o. INTEIRO : 20

        FORNECER O 4 o. INTEIRO : 30

        FORNECER O 5 o. INTEIRO : 40

        FORNECER O 6 o. INTEIRO : 50

        FORNECER O 7 o. INTEIRO : 60

        FORNECER O 8 o. INTEIRO : 70

        FORNECER O 9 o. INTEIRO : 80

        FORNECER O 10 o. INTEIRO : 90

        VETOR LIDO:
        5 10 20 30 40 50 60 70 80 90

        PRESSIONAR <Enter> PARA TERMINAR
     */
}

void exemplo702(){
    // PROGRAMA PARA SOMAR UMA TABELA DE INTEIROS
    // VARIAVEIS :
     TABELA V;
     int X = 0,
     SOMA = 0;
     printf ( "EXEMPLO702 - SOMAR UM TABELA DE 10 INTEIROS\n" );
    // REPETIR PARA CADA POSICAO
     for ( X = 0; X < 10; X++ )
     {
     printf ( "\nFORNECER O %do. INTEIRO : ",(X+1) );
     scanf ( "%d", &V[ X ] );
     getchar( ); // limpar a entrada de dados
     } // FIM REPETIR
     SOMA = 0;
    // REPETIR PARA CADA POSICAO
     for ( X = 0; X < 10; X++ )
     SOMA = SOMA + V[ X ];
     printf ( "\nSOMA = %d",SOMA );
     printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO702 - SOMAR UM TABELA DE 10 INTEIROS

        FORNECER O 1o. INTEIRO : 1

        FORNECER O 2o. INTEIRO : 2

        FORNECER O 3o. INTEIRO : 3

        FORNECER O 4o. INTEIRO : 4

        FORNECER O 5o. INTEIRO : 5

        FORNECER O 6o. INTEIRO : 6

        FORNECER O 7o. INTEIRO : 7

        FORNECER O 8o. INTEIRO : 8

        FORNECER O 9o. INTEIRO : 9

        FORNECER O 10o. INTEIRO : 10

        SOMA = 55

        PRESSIONAR <Enter> PARA TERMINAR
     */
}

void exemplo703(){
    // PROGRAMA PARA CALCULAR A MEDIA DE UMA TABELA DE INTEIROS
    // VARIAVEIS :
     TABELA V;
     float MEDIA = 0.0;
     int X = 0 ,
     SOMA = 0 ;
     printf ( "EXEMPLO703 - MEDIA DE UMA TABELA DE 10 INTEIROS\n" );
    // REPETIR PARA CADA POSICAO
     for ( X = 0; X < 10; X++ )
     {
     printf ( "\nFORNECER O %do. INTEIRO : ",(X+1) );
     scanf ( "%d", &V[ X ] );
     getchar( ); // limpar a entrada de dados
     } // FIM REPETIR
     SOMA = 0;
    // REPETIR PARA CADA POSICAO
     for ( X = 0; X < 10; X++ )
     SOMA = SOMA + V[ X ];
     MEDIA = SOMA / 10.0;
     printf ( "\nMEDIA = %f\n", MEDIA );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR" );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO703 - MEDIA DE UMA TABELA DE 10 INTEIROS

        FORNECER O 1o. INTEIRO : 9

        FORNECER O 2o. INTEIRO : 8

        FORNECER O 3o. INTEIRO : 7

        FORNECER O 4o. INTEIRO : 6

        FORNECER O 5o. INTEIRO : 5

        FORNECER O 6o. INTEIRO : 4

        FORNECER O 7o. INTEIRO : 3

        FORNECER O 8o. INTEIRO : 2

        FORNECER O 9o. INTEIRO : 1

        FORNECER O 10o. INTEIRO : 0

        MEDIA = 4.500000

        PRESSIONAR <Enter> PARA TERMINAR
     */
}

typedef char STRING10[10];
void exemplo704(){
    // PROGRAMA PARA LER UMA PALAVRA
    // VARIAVEIS :
     STRING10 PALAVRA;
     int X = 0;
     printf ( "EXEMPLO704 - LER UMA PALAVRA\n" );
     printf ( "\nFORNECER UMA PALAVRA (NO MAXIMO 09 LETRAS) : " );
     gets ( PALAVRA );
     printf ( "\nLETRAS DA PALAVRA LIDA : " );
    // REPETIR PARA CADA POSICAO
     for ( X = 0; X < strlen( PALAVRA ); X++ )
     printf ( "%c ", PALAVRA[ X ] );
     printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //SAIDA
     /*
        EXEMPLO704 - LER UMA PALAVRA

        FORNECER UMA PALAVRA (NO MAXIMO 09 LETRAS) : ALE

        LETRAS DA PALAVRA LIDA : A L E

        PRESSIONAR <Enter> PARA TERMINAR
     */
}

void exemplo705(){
    // PROGRAMA PARA PROCURAR LETRA EM PALAVRA
    // VARIAVEIS :
     STRING10 PALAVRA;
     char LETRA = '_';
     int X = 0 ;
     bool ACHAR = false;
     printf ( "EXEMPLO705 - PROCURAR LETRA EM UMA PALAVRA\n" );
     printf ( "\nDIGITAR UMA PALAVRA (NO MAXIMO 09 LETRAS) : " );
     gets ( PALAVRA );
     printf ( "\nFORNECER A LETRA A SER PROCURADA : " );
     LETRA = getchar ( );
     getchar( ); // limpar a entrada de dados
     ACHAR = false;
     X = 0;
    // REPETIR PARA CADA POSICAO
     while ( X < strlen( PALAVRA ) && ! ACHAR )
     {
     if( PALAVRA[ X ] == LETRA )
     ACHAR = true;
     else
     X = X + 1;
     } // FIM REPETIR
     if( ACHAR )
     printf ( "LETRA ENCONTRADA" );
     else
     printf ( "LETRA NAO ENCONTRADA" );
     printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO705 - PROCURAR LETRA EM UMA PALAVRA

        DIGITAR UMA PALAVRA (NO MAXIMO 09 LETRAS) : LEGAL

        FORNECER A LETRA A SER PROCURADA : A
        LETRA ENCONTRADA

        PRESSIONAR <Enter> PARA TERMINAR
     */

     /*
        EXEMPLO705 - PROCURAR LETRA EM UMA PALAVRA

        DIGITAR UMA PALAVRA (NO MAXIMO 09 LETRAS) : LEGAL

        FORNECER A LETRA A SER PROCURADA : I
        LETRA NAO ENCONTRADA

        PRESSIONAR <Enter> PARA TERMINAR
     */

}

typedef float POLINOMIO[10+1]; // posicoes de 0:10
void exemplo706(){
    // PROGRAMA PARA AVALIAR UM POLINOMIO
    // VARIAVEIS :
     POLINOMIO P;
     int Y = 0 , N = 0 ;
     float X = 0.0, PX = 0.0;
     printf ( "EXEMPLO706 - LER COEFICIENTES DE UM POLINOMIO\n" );
     printf ( "\nFORNECER O GRAU DO POLINOMIO : " );
     scanf ( "%d", &N );
     getchar( ); // limpar a entrada de dados
    // REPETIR PARA CADA POSICAO
     for ( Y = 0; Y <= N; Y++ )
     {
     printf ( "\nFORNECER O %do. COEFICIENTE : ", (Y+1) );
     scanf ( "%f", &P[ Y ] );
     getchar( ); // limpar a entrada de dados
     } // FIM REPETIR
     printf ( "\nFORNECER O PONTO DE AVALIACAO : " );
     scanf ( "%f", &X );
     getchar( ); // limpar a entrada de dados
     PX = 0.0;
    // REPETIR PARA CADA POSICAO
    // DA ULTIMA ATE' A PRIMEIRA
     for ( Y = N; Y >= 0; Y-- )
     PX = PX * X + P[ Y ];
     printf ( "\nP%d = %f", X, PX );
     printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO706 - LER COEFICIENTES DE UM POLINOMIO

        FORNECER O GRAU DO POLINOMIO : 3

        FORNECER O 1o. COEFICIENTE : 4

        FORNECER O 2o. COEFICIENTE : 2

        FORNECER O 3o. COEFICIENTE : 1

        FORNECER O 4o. COEFICIENTE : 1

        FORNECER O PONTO DE AVALIACAO : 2

        P0 = 20.000000

        PRESSIONAR <Enter> PARA TERMINAR

     */
}

typedef int VETOR[3]; // X,Y,Z
void exemplo707(){
    // PROGRAMA PARA AVALIAR O COMPRIMENTO DE UM VETOR
    // VARIAVEIS :
     VETOR V;
     int X = 0 ;
     float SOMA = 0.0;
     printf ( "EXEMPLO707 - COMPRIMENTO DE UM VETOR\n" );
     printf ( "\nFORNECER O VALOR DE X : " );
     scanf ( "%d", &V[0] );
     getchar( ); // limpar a entrada de dados
     printf ( "\nFORNECER O VALOR DE Y : " );
     scanf ( "%d", &V[1] );
     getchar( ); // limpar a entrada de dados
     printf ( "\nFORNECER O VALOR DE Z : " );
     scanf ( "%d", &V[2] );
     getchar( ); // limpar a entrada de dados
     SOMA = 0.0;
    // REPETIR PARA CADA POSICAO
     for( X = 0; X < 3; X++ )
     SOMA = SOMA + V[ X ]*V[ X ];
     printf ( "\nCOMPRIMENTO = %f", sqrt( SOMA ) );
     printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO707 - COMPRIMENTO DE UM VETOR

        FORNECER O VALOR DE X : 1

        FORNECER O VALOR DE Y : 2

        FORNECER O VALOR DE Z : 3

        COMPRIMENTO = 3.741657

        PRESSIONAR <Enter> PARA TERMINAR
     */
}

typedef int MATRIZ[2][2];
void exemplo708(){
    // PROGRAMA PARA LER UMA MATRIZ
    // VARIAVEIS :
     MATRIZ M;
     int X = 0, Y = 0;
     printf ( "EXEMPLO708 - LER UMA MATRIZ INTEIRA 2x2\n" );
    // REPETIR PARA CADA LINHA
     for ( X = 0; X < 2; X++ )
     { // REPETIR PARA CADA COLUNA
     for ( Y = 0; Y < 2; Y++ )
     {
     printf ( "\nFORNECER ELEMENTO %d, %d : ",(X+1), (Y+1) );
     scanf ( "%d", &M[ X ][ Y ] );
     getchar( ); // limpar a entrada de dados
     } // FIM REPETIR
     } // FIM REPETIR
     printf ( "\n" );
    // REPETIR PARA CADA LINHA
     for ( X = 0; X < 2; X++ )
     { // REPETIR PARA CADA COLUNA
     for ( Y = 0; Y < 2; Y++ )
     printf ( "%d ", M[ X ][ Y ] );
     printf ( "\n" );
     } // FIM REPETIR
     printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO708 - LER UMA MATRIZ INTEIRA 2x2

        FORNECER ELEMENTO 1, 1 : 5

        FORNECER ELEMENTO 1, 2 : 10

        FORNECER ELEMENTO 2, 1 : 40

        FORNECER ELEMENTO 2, 2 : 80

        5 10
        40 80


        PRESSIONAR <Enter> PARA TERMINAR
     */
}

void exemplo709(){
    // PROGRAMA PARA MONTAR A TRANSPOSTA DE UMA MATRIZ
    // VARIAVEIS :
     MATRIZ M, // MATRIZ ORIGINAL
     MT; // MATRIZ TRANSPOSTA
     int X = 0, Y = 0;
     printf ( "EXEMPLO709 - TRANSPOR UMA MATRIZ INTEIRA 2x2\n" );
    // REPETIR PARA CADA LINHA
     for ( X = 0; X < 2; X++ )
     { // REPETIR PARA CADA COLUNA
     for ( Y = 0; Y < 2; Y++ )
     {
     printf ( "\nFORNECER ELEMENTO %d, %d : ",(X+1), (Y+1) );
     scanf ( "%d", &M[ X ][ Y ] );
     getchar( ); // limpar a entrada de dados
     MT[ Y ][ X ] = M[ X ][ Y ];
     } // FIM REPETIR
     } // FIM REPETIR
     printf ( "\n" );
    // REPETIR PARA CADA LINHA
     for ( X = 0; X < 2; X++ )
     { // REPETIR PARA CADA COLUNA
     for ( Y = 0; Y < 2; Y++ )
     printf ( "%d ", M[ X ][ Y ] );
     printf ( "\n" );
     } // FIM REPETIR
     printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO709 - TRANSPOR UMA MATRIZ INTEIRA 2x2

        FORNECER ELEMENTO 1, 1 : 2

        FORNECER ELEMENTO 1, 2 : 3

        FORNECER ELEMENTO 2, 1 : 8

        FORNECER ELEMENTO 2, 2 : 9

        2 3
        8 9


        PRESSIONAR <Enter> PARA TERMINAR
     */
}

#define ORDEM 3
typedef int MATRIZ1 [ ORDEM ][ ORDEM ];
void exemplo710(){
    // PROGRAMA PARA MOSTRAR A DIAGONAL DE UMA MATRIZ
    // VARIAVEIS :
     MATRIZ1 M;
     int X = 0, Y = 0;
     printf ( "EXEMPLO710 - MOSTRAR A DIAGONAL DE UMA MATRIZ\n" );
    // REPETIR PARA CADA LINHA
     for ( X = 0; X < ORDEM; X++ )
     { // REPETIR PARA CADA COLUNA
     for ( Y = 0; Y < ORDEM; Y++ )
     {
     printf ( "\nFORNECER ELEMENTO %d, %d : ",(X+1), (Y+1) );
     scanf ( "%d", &M[ X ][ Y ] );
     getchar( ); // limpar a entrada de dados
     } // FIM REPETIR
     } // FIM REPETIR
     printf ( "\n" );
    // REPETIR PARA CADA LINHA
     for ( X = 0; X < ORDEM; X++ )
     { // REPETIR PARA CADA COLUNA
     for ( Y = 0; Y < ORDEM; Y++ )
     {
     if ( X == Y ) // SE ESTIVER NA DIAGONAL
     printf ( "%d ", M[ X ][ Y ] );
     } // FIM REPETIR
     } // FIM REPETIR
     printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO710 - MOSTRAR A DIAGONAL DE UMA MATRIZ

        FORNECER ELEMENTO 1, 1 : 1

        FORNECER ELEMENTO 1, 2 : 2

        FORNECER ELEMENTO 1, 3 : 3

        FORNECER ELEMENTO 2, 1 : 4

        FORNECER ELEMENTO 2, 2 : 5

        FORNECER ELEMENTO 2, 3 : 6

        FORNECER ELEMENTO 3, 1 : 7

        FORNECER ELEMENTO 3, 2 : 8

        FORNECER ELEMENTO 3, 3 : 9

        1 5 9

        PRESSIONAR <Enter> PARA TERMINAR
     */
}

int main(void){
    int opcao;
    do{
        printf("\n\tMenu de opcoes: \n");
        printf("\t0) Sair\n");
        printf("\t1) Exemplo 701\n");
        printf("\t2) Exemplo 702\n");
        printf("\t3) Exemplo 703\n");
        printf("\t4) Exemplo 704\n");
        printf("\t5) Exemplo 705\n");
        printf("\t6) Exemplo 706\n");
        printf("\t7) Exemplo 707\n");
        printf("\t8) Exemplo 708\n");
        printf("\t9) Exemplo 709\n");
        printf("\t10) Exemplo 710\n");
        printf("\tDigite a opcao desejada: \n");
        scanf("%d", &opcao);

        switch(opcao){
            case 0: break;
            case 1:
                exemplo701();
                break;
            case 2:
                exemplo702();
                break;
            case 3:
                exemplo703();
                break;
            case 4:
                exemplo704();
                break;
            case 5:
                exemplo705();
                break;
            case 6:
                exemplo706();
                break;
            case 7:
                exemplo707();
                break;
            case 8:
                exemplo708();
                break;
            case 9:
                exemplo709();
                break;
            case 10:
                exemplo710();
                break;


            default:
                printf("Opcao invalida...");
                break;
        }


    } while(opcao != 0);
return 0;
}
