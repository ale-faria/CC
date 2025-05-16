/*
    AED1 - ED00 - parte 4
    DATA: 22/02/2024
    AUTORIA: ALESSANDRA FARIA RODRIGUES
    NUM. MATRICULA: 828333
*/
#include <stdio.h>
#include <stdlib.h>

void exemplo401(){
    // PROGRAMA PARA LER E IMPRIMIR 03 VALORES INTEIROS
    // VARIAVEIS :
     int X = 0,
     CONTADOR = 0;
     printf ( "EXEMPLO401 - LER E IMPRIMIR 03 VALORES INTEIROS" );
     printf ( "\n" ); // mudar de linha
     CONTADOR = 1;
     while ( CONTADOR <= 3 ) // REPETIR
     {
     printf ( "\n" ); // mudar de linha
     printf ( "%d. FORNECER UM VALOR INTEIRO : ", CONTADOR );
     scanf( "%d", &X );
     getchar( ); // limpar a entrada de dados
     printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
     CONTADOR = CONTADOR + 1;
     } // ENQUANTO ( CONTADOR <= 3 )
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO401 - LER E IMPRIMIR 03 VALORES INTEIROS

        1. FORNECER UM VALOR INTEIRO : 3

        O VALOR DIGITADO FOI : 3

        2. FORNECER UM VALOR INTEIRO : 5

        O VALOR DIGITADO FOI : 5

        3. FORNECER UM VALOR INTEIRO : 10

        O VALOR DIGITADO FOI : 10

        PRESSIONAR <Enter> PARA TERMINAR.
     */

}

void exemplo402(){
    // PROGRAMA PARA LER E IMPRIMIR (N) VALORES INTEIROS
    // VARIAVEIS :
     int X = 0, N = 0, CONTADOR = 0;
     printf ( "EXEMPLO402 - LER E IMPRIMIR (N) VALORES INTEIROS\n" );
     printf ( "\nFORNECER O NUMERO DE VEZES (N) : " );
     scanf ( "%d", &N );
     getchar( ); // limpar a entrada de dados
     CONTADOR = 1;
     while ( CONTADOR <= N )
     {
     printf ( "\n%d", CONTADOR );
     printf ( " FORNECER UM VALOR INTEIRO QUALQUER : " );
     scanf ( "%d", &X );
     getchar( ); // limpar a entrada de dados
     printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
     CONTADOR = CONTADOR + 1;
     } // ENQUANTO ( CONTADOR <= N )
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO402 - LER E IMPRIMIR (N) VALORES INTEIROS

        FORNECER O NUMERO DE VEZES (N) : 3

        1 FORNECER UM VALOR INTEIRO QUALQUER : 10

        O VALOR DIGITADO FOI : 10

        2 FORNECER UM VALOR INTEIRO QUALQUER : 20

        O VALOR DIGITADO FOI : 20

        3 FORNECER UM VALOR INTEIRO QUALQUER : 30

        O VALOR DIGITADO FOI : 30

        PRESSIONAR <Enter> PARA TERMINAR.
     */
}

void exemplo403(){
    // PROGRAMA PARA LER E IMPRIMIR (N) VALORES INTEIROS
    // VARIAVEIS :
     int X = 0, N = 0;
     printf ( "EXEMPLO403 - LER E IMPRIMIR (N) VALORES INTEIROS\n" );
     printf ( "\nFORNECER O NUMERO DE VEZES (N) : " );
     scanf ( "%d", &N );
     getchar( ); // limpar a entrada de dados
     while ( N > 0 ) // REPETIR
     {
     printf ( "\n%d", N );
     printf ( " FORNECER UM VALOR INTEIRO QUALQUER : " );
     scanf ( "%d", &X );
     getchar( ); // limpar a entrada de dados
     printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
     N = N - 1;
     } // ENQUANTO N > 0
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO403 - LER E IMPRIMIR (N) VALORES INTEIROS

        FORNECER O NUMERO DE VEZES (N) : 2

        2 FORNECER UM VALOR INTEIRO QUALQUER : 10

        O VALOR DIGITADO FOI : 10

        1 FORNECER UM VALOR INTEIRO QUALQUER : 20

        O VALOR DIGITADO FOI : 20

        PRESSIONAR <Enter> PARA TERMINAR.
     */
}

void exemplo404(){
    // PROGRAMA PARA LER E IMPRIMIR 03 VALORES INTEIROS
    // VARIAVEIS :
     int X = 0,
     CONTADOR = 0;
     printf ( "EXEMPLO404 - LER E IMPRIMIR 03 VALORES INTEIROS\n" );
     for ( CONTADOR = 1; CONTADOR <= 3; CONTADOR = CONTADOR+1)
     {
     printf ( "\n%d. FORNECER UM VALOR INTEIRO : ", CONTADOR );
     scanf ( "%d", &X );
     getchar( ); // limpar a entrada de dados
     printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
     } // PARA CONTADOR EM [1:3]
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO404 - LER E IMPRIMIR 03 VALORES INTEIROS

        1. FORNECER UM VALOR INTEIRO : 2

        O VALOR DIGITADO FOI : 2

        2. FORNECER UM VALOR INTEIRO : 1

        O VALOR DIGITADO FOI : 1

        3. FORNECER UM VALOR INTEIRO : 2

        O VALOR DIGITADO FOI : 2

        PRESSIONAR <Enter> PARA TERMINAR.
     */

}

void exemplo405(){
    // PROGRAMA PARA LER E IMPRIMIR (N) VALORES INTEIROS
    // VARIAVEIS :
     int X = 0,
     N = 0,
     CONTADOR = 0;
     printf ( "EXEMPLO405 - LER E IMPRIMIR (N) VALORES INTEIROS\n" );
     printf ( "\nFORNECER O NUMERO DE VEZES (N) : " );
     scanf ( "%d", &N );
     getchar( ); // limpar a entrada de dados
     for ( CONTADOR = 1; CONTADOR <= N; CONTADOR++ )
     {
     printf ( "\n%d. FORNECER UM VALOR INTEIRO : ", CONTADOR );
     scanf ( "%d", &X );
     getchar( ); // limpar a entrada de dados
     printf ( "\nO VALOR DIGITADO FOI : %d", X );
     } // PARA CONTADOR EM [1:N]
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO405 - LER E IMPRIMIR (N) VALORES INTEIROS

        FORNECER O NUMERO DE VEZES (N) : 2

        1. FORNECER UM VALOR INTEIRO : 4

        O VALOR DIGITADO FOI : 4
        2. FORNECER UM VALOR INTEIRO : 5

        O VALOR DIGITADO FOI : 5
        PRESSIONAR <Enter> PARA TERMINAR.
     */
}

void exemplo406(){
    // PROGRAMA PARA LER E IMPRIMIR 03 VALORES INTEIROS
    // VARIAVEIS :
     int X = 0,
     CONTADOR = 0;
     printf ( "EXEMPLO406 - LER E IMPRIMIR 03 VALORES INTEIROS\n" );
     CONTADOR = 1;
     do // REPETIR
     {
     printf ( "\n%d. FORNECER UM VALOR INTEIRO : ", CONTADOR );
     scanf ( "%d", &X );
     getchar( ); // limpar a entrada de dados
     printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
     CONTADOR = CONTADOR + 1;
     }
     while ( CONTADOR <= 3 ); // ATE' ( CONTADOR > 3 )
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO406 - LER E IMPRIMIR 03 VALORES INTEIROS

        1. FORNECER UM VALOR INTEIRO : 1

        O VALOR DIGITADO FOI : 1

        2. FORNECER UM VALOR INTEIRO : 2

        O VALOR DIGITADO FOI : 2

        3. FORNECER UM VALOR INTEIRO : 3

        O VALOR DIGITADO FOI : 3

        PRESSIONAR <Enter> PARA TERMINAR.
     */
}

void exemplo407(){
    // PROGRAMA PARA LER E IMPRIMIR (N) VALORES INTEIROS
    // VARIAVEIS :
     int X = 0,
     CONTADOR = 0;
     printf ( "EXEMPLO407 - LER E IMPRIMIR (N) VALORES INTEIROS\n" );
     printf ( "\nFORNECER O NUMERO DE VEZES (N) : " );
     scanf ( "%d", &CONTADOR );
     getchar( ); // limpar a entrada de dados
     do // REPETIR
     {
     printf ( "\n%d. FORNECER UM VALOR INTEIRO : ", CONTADOR );
     scanf ( "%d", &X );
     getchar( ); // limpar a entrada de dados
     printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
     CONTADOR = CONTADOR - 1;
     }
     while ( CONTADOR > 0 ); // ATE' ( CONTADOR <= 3 )
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO407 - LER E IMPRIMIR (N) VALORES INTEIROS

        FORNECER O NUMERO DE VEZES (N) : 2

        2. FORNECER UM VALOR INTEIRO : 1

        O VALOR DIGITADO FOI : 1

        1. FORNECER UM VALOR INTEIRO : 2

        O VALOR DIGITADO FOI : 2

        PRESSIONAR <Enter> PARA TERMINAR.
     */
}

void exemplo408(){
    // PROGRAMA PARA LER E IMPRIMIR INTEIROS DIFERENTES DE ZERO
    // VARIAVEL :
     int X = 0;
     printf ( "EXEMPLO408 - LER E IMPRIMIR INTEIROS NAO NULOS\n" );
     printf ( "\nFORNECER UM VALOR INTEIRO (0 = PARAR) : " );
     scanf ( "%d", &X );
     getchar( ); // limpar a entrada de dados
     while ( X != 0 ) // REPETIR
     {
     printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
     printf ( "\nDIGITE UM VALOR INTEIRO QUALQUER : " );
     scanf ( "%d", &X );
     getchar( ); // limpar a entrada de dados
     } // ENQUANTO X DIFERENTE DE ZERO
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO408 - LER E IMPRIMIR INTEIROS NAO NULOS

        FORNECER UM VALOR INTEIRO (0 = PARAR) : 1

        O VALOR DIGITADO FOI : 1

        DIGITE UM VALOR INTEIRO QUALQUER : 2

        O VALOR DIGITADO FOI : 2

        DIGITE UM VALOR INTEIRO QUALQUER : -3

        O VALOR DIGITADO FOI : -3

        DIGITE UM VALOR INTEIRO QUALQUER : 0

        PRESSIONAR <Enter> PARA TERMINAR.
     */
}

void exemplo409(){
    // PROGRAMA PARA LER UM INTEIRO DIFERENTE DE ZERO
    // VARIAVEL :
     int X = 0;
     printf ( "EXEMPLO409 - PARA LER UM INTEIRO NAO NULO\n" );
     printf ( "\nFORNECER UM VALOR DIFERENTE DE ZERO : " );
     scanf ( "%d", &X );
     getchar( ); // limpar a entrada de dados
     while ( X == 0 ) // REPETIR
     {
     printf ( "\nFORNECER UM VALOR DIFERENTE DE ZERO : " );
     scanf ( "%d", &X );
     getchar( ); // limpar a entrada de dados
     } // ENQUANTO X IGUAL A ZERO
     printf ( "\nDIGITADO UM NUMERO DIFERENTE DE ZERO\n" );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO409 - PARA LER UM INTEIRO NAO NULO

        FORNECER UM VALOR DIFERENTE DE ZERO : 1

        DIGITADO UM NUMERO DIFERENTE DE ZERO

        PRESSIONAR <Enter> PARA TERMINAR.
     */
     /*
        EXEMPLO409 - PARA LER UM INTEIRO NAO NULO

        FORNECER UM VALOR DIFERENTE DE ZERO : 0

        FORNECER UM VALOR DIFERENTE DE ZERO : 0

        FORNECER UM VALOR DIFERENTE DE ZERO : 1

        DIGITADO UM NUMERO DIFERENTE DE ZERO

        PRESSIONAR <Enter> PARA TERMINAR.
     */
}

void exemplo410(){
    // PROGRAMA PARA LER UM INTEIRO DIFERENTE DE ZERO
    // VARIAVEL :
     int X = 0;
     printf ( "EXEMPLO410 - LER UM INTEIRO NAO NULO\n" );
     do // REPETIR
     {
     printf ( "\nFORNECER UM VALOR DIFERENTE DE ZERO : " );
     scanf ( "%d", &X );
     getchar( ); // limpar a entrada de dados
     }
     while ( X == 0 ); // ATE' X DIFERENTE DE ZERO
     printf ( "\nDIGITADO UM NUMERO DIFERENTE DE ZERO\n" );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO410 - LER UM INTEIRO NAO NULO

        FORNECER UM VALOR DIFERENTE DE ZERO : 0

        FORNECER UM VALOR DIFERENTE DE ZERO : 1

        DIGITADO UM NUMERO DIFERENTE DE ZERO

        PRESSIONAR <Enter> PARA TERMINAR.
     */

}

int main(void){
    int opcao;
    do{
        printf("\n\tMenu de opcoes: \n");
        printf("\t0) Sair\n");
        printf("\t1) Exemplo 401\n");
        printf("\t2) Exemplo 402\n");
        printf("\t3) Exemplo 403\n");
        printf("\t4) Exemplo 404\n");
        printf("\t5) Exemplo 405\n");
        printf("\t6) Exemplo 406\n");
        printf("\t7) Exemplo 407\n");
        printf("\t8) Exemplo 408\n");
        printf("\t9) Exemplo 409\n");
        printf("\t10) Exemplo 410\n");
        printf("\tDigite a opcao desejada: \n");
        scanf("%d", &opcao);

        switch(opcao){
            case 0: break;
            case 1:
                exemplo401();
                break;
            case 2:
                exemplo402();
                break;
            case 3:
                exemplo403();
                break;
            case 4:
                exemplo404();
                break;
            case 5:
                exemplo405();
                break;
            case 6:
                exemplo406();
                break;
            case 7:
                exemplo407();
                break;
            case 8:
                exemplo408();
                break;
            case 9:
                exemplo409();
                break;
            case 10:
                exemplo410();
                break;


            default:
                printf("Opcao invalida...");
                break;
        }


    } while(opcao != 0);
return 0;
}
