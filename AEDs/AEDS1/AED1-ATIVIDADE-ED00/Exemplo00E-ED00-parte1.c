/*
    AED1 - ED00 - EXTRAS - parte 1
    DATA: 25/02/2024
    AUTORIA: ALESSANDRA FARIA RODRIGUES
    NUM. MATRICULA: 828333
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


void CONTAR ( int X )
    {
     if ( X > 0 )
     {
     CONTAR ( X-1 );
     printf ( "\n%d\n", X );
     }
    } // fim procedimento CONTAR

void exemplo601(){
    // PROGRAMA PARA CONTAR DE 1 ATE' 5, RECURSIVAMENTE
     printf ( "EXEMPLO601 - CONTAR DE 1 A 5 RECURSIVAMENTE\n" );
     CONTAR ( 5 );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR" );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO601 - CONTAR DE 1 A 5 RECURSIVAMENTE

        1

        2

        3

        4

        5

        PRESSIONAR <Enter> PARA TERMINAR
     */
}

void CONTAR_1 ( int X )
{
     if ( X > 0 )
     {
     printf ( "\n%d\n", X );
     CONTAR_1 ( X-1 );
 }
} // fim procedimento CONTAR
void exemplo602(){
    // PROGRAMA PARA CONTAR 5 10 ATE' 1, RECURSIVAMENTE
     printf ( "EXEMPLO602 - CONTAR DE 5 A 1 RECURSIVAMENTE\n" );
     CONTAR_1 ( 5 );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR" );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO602 - CONTAR DE 5 A 1 RECURSIVAMENTE

        5

        4

        3

        2

        1

        PRESSIONAR <Enter> PARA TERMINAR
     */
}


void PARES ( int X )
{
     if ( X > 0 )
     if ( X % 2 == 0 )
     {
     PARES ( X-2 );
     printf ( "\n%d\n", X );
     }
     else
     PARES ( X-1 );
} // fim procedimento PARES
void exemplo603(){
    // PROGRAMA RECURSIVO PARA MOSTRAR PARES
     printf ( "EXEMPLO603 - MOSTRAR OS PARES <= 10\n" );
     PARES ( 10 );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR" );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO603 - MOSTRAR OS PARES <= 10

        2

        4

        6

        8

        10

        PRESSIONAR <Enter> PARA TERMINAR
     */
}

void PARES_1 ( int X )
{
     if ( X > 0 )
     {
     PARES_1 ( X-1 );
     printf ( "\n%d%c%d\n", X, " ", 2*X );
 }
} // fim procedimento PARES
void exemplo604(){
    // PROGRAMA RECURSIVO PARA MOSTRAR PARES
     printf ( "EXEMPLO604 - MOSTRAR OS 5 PRIMEIROS PARES\n" );
     PARES_1 ( 5 );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR" );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO604 - MOSTRAR OS 5 PRIMEIROS PARES

        1 2

        2 4

        3 6

        4 8

        5 10

        PRESSIONAR <Enter> PARA TERMINAR
     */
}

void PARES_2 ( int X, int* S )
{
     if( X > 0 )
     { PARES_2 ( X-1, S ); *S = *S + 2*X; }
     else
     S = 0;
} // fim procedimento PARES
void exemplo605(){
    // PROGRAMA RECURSIVO PARA SOMAR PARES
    // DADO:
     int SOMA = 0;
     printf ( "EXEMPLO605 - SOMAR OS 5 PRIMEIROS PARES\n" );
     PARES_2 ( 5, &SOMA );
     printf ( "\nSOMA DOS 5 PRIMEIROS PARES = %d\n", SOMA );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR" );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO605 - SOMAR OS 5 PRIMEIROS PARES

        SOMA DOS 5 PRIMEIROS PARES = 30

        PRESSIONAR <Enter> PARA TERMINAR
     */
}

int PARES_3 ( int X )
{
    // DADO:
     int S = 0;
     if ( X > 0 )
     S = 2*X + PARES_3( X-1 );
     else
     S = 0;
     return ( S );
} // fim funcao PARES
void exemplo606(){
    // PROGRAMA RECURSIVO PARA SOMAR PARES
    // DADO :
     int SOMA = 0;
     printf ( "EXEMPLO606 - SOMAR OS 5 PRIMEIROS PARES\n" );
     SOMA = PARES_3 ( 5 );
     printf ( "\nSOMA DOS 5 PRIMEIROS PARES = %d\n", SOMA );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR" );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO606 - SOMAR OS 5 PRIMEIROS PARES

        SOMA DOS 5 PRIMEIROS PARES = 30

        PRESSIONAR <Enter> PARA TERMINAR
     */
}

int PARES_4 ( int X )
{
    // DADO :
     int S = 0;
     if ( X > 0 )
     if ( X % 2 == 0 )
     S = 1 + PARES_4 ( X-2 );
     else
     S = PARES_4 ( X-1 );
     else
     S = 0;
     return ( S );
} // fim funcao PARES
void exemplo607(){
    // PROGRAMA RECURSIVO PARA CONTAR PARES
     printf ( "EXEMPLO607 - CONTAR OS PARES <= 10\n" );
     printf ( "\nPARES <= 10 = %d\n", PARES_4( 10 ) );
     printf ( "\nFORNECER <Enter> PARA TERMINAR" );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO607 - CONTAR OS PARES <= 10

        PARES <= 10 = 5

        FORNECER <Enter> PARA TERMINAR
     */
}

typedef char STRING30 [30];
bool PROCURAR ( char LETRA, STRING30 S, int POSICAO )
{
    // DADO :
     bool R = false;
     if ( POSICAO <= strlen( S ) )
     R = ( S [ POSICAO ] == LETRA) || PROCURAR ( LETRA,S,POSICAO+1 );
     else
     R = false;
     return ( R );
} // fim funcao PROCURAR
void exemplo608(){
    // PROGRAMA RECURSIVO PARA ACHAR A POSICAO DE UMA LETRA
    // DADO :
     char L = '_';
     STRING30 S = "";
     printf ( "EXEMPLO608 - PROCURAR UMA LETRA EM UMA SENTENCA\n" );
     printf ( "\nFORNECER UMA SENTENCA COM MENOS DE 30 CARACTERES : " );
     gets ( S );
     printf ( "\nFORNECER UMA LETRA PARA SER PROCURADA : " );
     L = getchar ( );
     getchar( ); // limpar a entrada de dados
     printf ( "\nRESPOSTA = %d\n", PROCURAR( L,S,0 ) );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR" );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //SAIDA
     /*
        EXEMPLO608 - PROCURAR UMA LETRA EM UMA SENTENCA

        FORNECER UMA SENTENCA COM MENOS DE 30 CARACTERES : ALESSANDRA

        FORNECER UMA LETRA PARA SER PROCURADA : A

        RESPOSTA = 1

        PRESSIONAR <Enter> PARA TERMINAR
     */

     /*
        EXEMPLO608 - PROCURAR UMA LETRA EM UMA SENTENCA

        FORNECER UMA SENTENCA COM MENOS DE 30 CARACTERES : ALESSANDRA

        FORNECER UMA LETRA PARA SER PROCURADA : I

        RESPOSTA = 0

        PRESSIONAR <Enter> PARA TERMINAR
     */
     //1 == TRUE / 0 == FALSE
}

int PROCURAR_1
 ( char LETRA, STRING30 S, int POSICAO )
{
    // DADO :
     int R = 0;
     if ( POSICAO <= strlen(S) )
     if ( S [ POSICAO ] == LETRA )
     R = POSICAO + 1; // a primeira posicao e' 0 !
     else
     R = PROCURAR_1 ( LETRA,S,POSICAO+1 );
     else
     R = 0;
     return ( R );
    } // fim funcao PROCURAR
void exemplo609(){
    // PROGRAMA RECURSIVO PARA PROCURAR UMA LETRA
    // DADO :
     char L = '_';
     STRING30 S = "";
     printf ( "EXEMPLO609 - POSICAO DE UMA LETRA EM UMA SENTENCA\n" );
     printf ( "\nFORNECER UMA SENTENCA COM MENOS DE 30 CARACTERES : " );
     gets ( S );
     printf ( "\nFORNECER UMA LETRA PARA SER PROCURADA : " );
     L = getchar ( );
     getchar( ); // limpar a entrada de dados
     printf ( "\nRESPOSTA = %d\n", PROCURAR_1 ( L,S,0 ) );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR" );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //SAIDA
     /*
        EXEMPLO609 - POSICAO DE UMA LETRA EM UMA SENTENCA

        FORNECER UMA SENTENCA COM MENOS DE 30 CARACTERES : ALESSANDRA

        FORNECER UMA LETRA PARA SER PROCURADA : S

        RESPOSTA = 4

        PRESSIONAR <Enter> PARA TERMINAR
     */

}

int PROCURAR_2
 ( char LETRA, STRING30 S, int POSICAO )
{
    // DADO :
     int R = 0;
     if ( POSICAO <= strlen(S) )
     if ( S [ POSICAO ] == LETRA )
     R = 1 + PROCURAR_2 ( LETRA, S, POSICAO+1 );
     else
     R = PROCURAR_2 ( LETRA,S,POSICAO+1 );
     else
     R = 0;
     return ( R );
} // fim funcao PROCURAR
void exemplo610(){
    // PROGRAMA RECURSIVO PARA PROCURAR OCORRENCIAS DE UMA LETRA
    // DADO :
     char L = '_';
     STRING30 S = "";
     printf ( "EXEMPLO610 - PROCURAR OCORRENCIAS DE UMA LETRA\n" );
     printf ( "\nFORNECER UMA SENTENCA COM MENOS DE 30 CARACTERES : " );
     gets ( S );
     printf ( "\nFORNECER UMA LETRA PARA SER PROCURADA : " );
     L = getchar ( );
     getchar( ); // limpar a entrada de dados
     printf ( "\nRESPOSTA = %d\n", PROCURAR_2( L,S,0 ) );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR" );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //SAIDA
     /*
        EXEMPLO610 - PROCURAR OCORRENCIAS DE UMA LETRA

        FORNECER UMA SENTENCA COM MENOS DE 30 CARACTERES : ALESSANDRA

        FORNECER UMA LETRA PARA SER PROCURADA : A

        RESPOSTA = 3

        PRESSIONAR <Enter> PARA TERMINAR
     */
}

int main(void){
    int opcao;
    do{
        printf("\n\tMenu de opcoes: \n");
        printf("\t0) Sair\n");
        printf("\t1) Exemplo 601\n");
        printf("\t2) Exemplo 602\n");
        printf("\t3) Exemplo 603\n");
        printf("\t4) Exemplo 604\n");
        printf("\t5) Exemplo 605\n");
        printf("\t6) Exemplo 606\n");
        printf("\t7) Exemplo 607\n");
        printf("\t8) Exemplo 608\n");
        printf("\t9) Exemplo 609\n");
        printf("\t10) Exemplo 610\n");
        printf("\tDigite a opcao desejada: \n");
        scanf("%d", &opcao);

        switch(opcao){
            case 0: break;
            case 1:
                exemplo601();
                break;
            case 2:
                exemplo602();
                break;
            case 3:
                exemplo603();
                break;
            case 4:
                exemplo604();
                break;
            case 5:
                exemplo605();
                break;
            case 6:
                exemplo606();
                break;
            case 7:
                exemplo607();
                break;
            case 8:
                exemplo608();
                break;
            case 9:
                exemplo609();
                break;
            case 10:
                exemplo610();
                break;


            default:
                printf("Opcao invalida...");
                break;
        }


    } while(opcao != 0);
return 0;
}
