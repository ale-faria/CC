/*
    AED1 - ED00 - parte 5
    DATA: 23/02/2024
    AUTORIA: ALESSANDRA FARIA RODRIGUES
    NUM. MATRICULA: 828333
*/
#include <stdio.h>
#include <stdlib.h>

void P1 ( void )
{
 printf ( "\n" );
 printf ( "\nCHAMADO O PROCEDIMENTO P1 SEM PARAMETROS" );
 printf ( "\n" );
} // fim procedimento P1

void exemplo501(){
    // PROGRAMA PARA CHAMADA DE PROCEDIMENTO SEM PARAMETROS
     printf ( "EXEMPLO0501 - CHAMADA A UM PROCEDIMENTO" );
     P1 ( ); // chamada ao procedimento
     printf ( "\n" );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO0501 - CHAMADA A UM PROCEDIMENTO

        CHAMADO O PROCEDIMENTO P1 SEM PARAMETROS


        PRESSIONAR <Enter> PARA TERMINAR.

     */

}

int X = 0; // VARIAVEL EM CONTEXTO GLOBAL
void P1_1 ( void )
{
printf ( "\n" );
printf ( "\nCHAMADO O PROCEDIMENTO P1 %d VEZ(ES)", X );
printf ( "\n" );
} // fim procedimento P1
void exemplo502(){
    // PROGRAMA PARA MOSTRAR PASSAGENS DE PARAMETROS
     printf ( "EXEMPLO0502 - CHAMADA COM VARIAVEL GLOBAL\n" );
     for ( X = 1; X <= 5; X = X + 1 )
     P1_1 ( ); // chamar 5 vezes
     printf ( "\n" );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO0502 - CHAMADA COM VARIAVEL GLOBAL


        CHAMADO O PROCEDIMENTO P1 1 VEZ(ES)


        CHAMADO O PROCEDIMENTO P1 2 VEZ(ES)


        CHAMADO O PROCEDIMENTO P1 3 VEZ(ES)


        CHAMADO O PROCEDIMENTO P1 4 VEZ(ES)


        CHAMADO O PROCEDIMENTO P1 5 VEZ(ES)


        PRESSIONAR <Enter> PARA TERMINAR.
     */
}

void P1_2 ( void )
    {
     X = X + 1; // AVANCAR O CONTEXTO
     printf ( "\nCHAMADO O PROCEDIMENTO P1 %d VEZ(ES)", X );
     printf ( "\n" );
     if ( X < 5 )
     P1_2 ( ); // CHAMAR O PROCEDIMENTO RECURSIVAMENTE
     printf ( "\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA %d", X );
     X = X - 1; // RETORNAR AO CONTEXTO ANTERIOR
     getchar ( ); // para esperar
    } // fim procedimento P1
void exemplo503(){
    // PROGRAMA PARA MOSTRAR PASSAGENS DE PARAMETROS
     printf ( "EXEMPLO0503 - CHAMADA/RETORNO COM VARIAVEL GLOBAL\n" );
     X = 0;
     P1_2 ( ); // OBSERVAR A RECURSIVIDADE !
     printf ( "\n" );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida

     /*
        EXEMPLO0503 - CHAMADA/RETORNO COM VARIAVEL GLOBAL

        CHAMADO O PROCEDIMENTO P1 1 VEZ(ES)

        CHAMADO O PROCEDIMENTO P1 2 VEZ(ES)

        CHAMADO O PROCEDIMENTO P1 3 VEZ(ES)

        CHAMADO O PROCEDIMENTO P1 4 VEZ(ES)

        CHAMADO O PROCEDIMENTO P1 5 VEZ(ES)

        RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 5

        RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 4

        RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 3

        RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 2

        RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 1


        PRESSIONAR <Enter> PARA TERMINAR.
     */
}


void P1_3 ( int X )
{
     printf ( "\nCHAMADO O PROCEDIMENTO P1 %d VEZ(ES)\n", X );
     if ( X < 5 )
     P1_3( X + 1 ); // chamar recursivamente com parametro
     printf ( "\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA %d", X );
     getchar ( ); // para esperar
} // fim procedimento P1
void exemplo504(){
    // PROGRAMA PARA MOSTRAR PASSAGENS DE PARAMETROS
     printf ( "EXEMPLO0904 - CHAMADA/RETORNO COM PARAMETRO\n" );
     P1_3 ( 1 ); // OBSERVAR REPETICAO FINITA, SEM VARIAVEL GLOBAL !
     printf ( "\n" );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO0904 - CHAMADA/RETORNO COM PARAMETRO

        CHAMADO O PROCEDIMENTO P1 1 VEZ(ES)

        CHAMADO O PROCEDIMENTO P1 2 VEZ(ES)

        CHAMADO O PROCEDIMENTO P1 3 VEZ(ES)

        CHAMADO O PROCEDIMENTO P1 4 VEZ(ES)

        CHAMADO O PROCEDIMENTO P1 5 VEZ(ES)

        RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 5

        RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 4

        RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 3

        RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 2

        RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 1


        PRESSIONAR <Enter> PARA TERMINAR.
     */
}

void P1_4 ( int X )
    {
     printf ( "\nCHAMADO O PROCEDIMENTO P1 %d VEZ(ES)\n", X );
     if ( X > 1 )
     P1_4 ( X - 1 );
     printf ( "\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA %d", X );
     getchar ( ); // para esperar
    } // fim procedimento P1
void exemplo505(){
    // PROGRAMA PARA MOSTRAR PASSAGEM DE PARAMETRO POR VALOR
     printf ( "EXEMPLO0505 - CHAMADA/RETORNO COM PARAMETRO\n" );
     P1_4 ( 5 ); // OBSERVAR REPETICAO FINITA, SEM VARIAVEL GLOBAL !
     printf ( "\n" );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO0505 - CHAMADA/RETORNO COM PARAMETRO

        CHAMADO O PROCEDIMENTO P1 5 VEZ(ES)

        CHAMADO O PROCEDIMENTO P1 4 VEZ(ES)

        CHAMADO O PROCEDIMENTO P1 3 VEZ(ES)

        CHAMADO O PROCEDIMENTO P1 2 VEZ(ES)

        CHAMADO O PROCEDIMENTO P1 1 VEZ(ES)

        RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 1

        RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 2

        RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 3

        RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 4

        RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 5


        PRESSIONAR <Enter> PARA TERMINAR.
     */
}

void P2 (int X); // PROTOTIPO DE PROCEDIMENTO
void P1_5 (int X)
{
 printf ( "CHAMADO O PROCEDIMENTO P1 COM X = %d\n", X );
 if ( X < 5 )
 P2 ( X );
 printf ( "RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = %d\n", X );
 getchar ( ); // para esperar
} // fim do procedimento P1( )
void P2 (int X)
{
 printf ( "CHAMADO O PROCEDIMENTO P2 COM X = %d\n", X );
 X = X+1;
 printf ( "RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = %d\n", X );
 getchar ( ); // para esperar
 P1_5 ( X );
} // fim do procedimento P2
void exemplo506(){
    // PROGRAMA PARA MOSTRAR PASSAGENS DE PARAMETROS
     printf ( "EXEMPLO0506 - CHAMADA/RETORNO COM PARAMETRO\n\n" );
     P1_5 ( 1 ); // OBSERVAR RECURSIVIDADE INDIRETA !
     printf ( "\n" );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO0506 - CHAMADA/RETORNO COM PARAMETRO

        CHAMADO O PROCEDIMENTO P1 COM X = 1
        CHAMADO O PROCEDIMENTO P2 COM X = 1
        RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = 2

        CHAMADO O PROCEDIMENTO P1 COM X = 2
        CHAMADO O PROCEDIMENTO P2 COM X = 2
        RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = 3

        CHAMADO O PROCEDIMENTO P1 COM X = 3
        CHAMADO O PROCEDIMENTO P2 COM X = 3
        RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = 4

        CHAMADO O PROCEDIMENTO P1 COM X = 4
        CHAMADO O PROCEDIMENTO P2 COM X = 4
        RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = 5

        CHAMADO O PROCEDIMENTO P1 COM X = 5
        RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = 5

        RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = 4

        RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = 3

        RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = 2

        RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = 1



        PRESSIONAR <Enter> PARA TERMINAR.
     */
}

void P1_6 ( int* X )
{
 *X = *X + 1; // AVANCAR O CONTEXTO NA REFERENCIA
 printf ( "\nCHAMADO O PROCEDIMENTO P1 %d VEZ(ES)\n", *X );
 if ( *X < 5 )
 P1_6 ( X );
 printf ( "\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA %d", *X );
 *X = *X - 1; // RETORNAR AO CONTEXTO DA REFERENCIA ANTERIOR
 getchar ( ); // para esperar
} // fim procedimento P1
void exemplo507(){
    // PROGRAMA PARA MOSTRAR PASSAGEM DE PARAMETRO POR REFERENCIA
    // VARIAVEL LOCAL
     int X;
     printf ( "EXEMPLO0507 - CHAMADA/RETORNO COM REFERENCIA\n" );
     X = 0;
     P1_6 ( &X ); // OBSERVAR REPETICAO FINITA !
     printf ( "\n" );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar ( ); // para esperar
     // ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO0507 - CHAMADA/RETORNO COM REFERENCIA

        CHAMADO O PROCEDIMENTO P1 1 VEZ(ES)

        CHAMADO O PROCEDIMENTO P1 2 VEZ(ES)

        CHAMADO O PROCEDIMENTO P1 3 VEZ(ES)

        CHAMADO O PROCEDIMENTO P1 4 VEZ(ES)

        CHAMADO O PROCEDIMENTO P1 5 VEZ(ES)

        RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 5

        RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 4

        RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 3

        RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 2

        RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 1


        PRESSIONAR <Enter> PARA TERMINAR.
     */
}

void P2_1 ( int X ); // PROTOTIPO DE PROCEDIMENTO
void P1_7 ( int X )
{
 X = X + 1;
 printf ( "CHAMADO O PROCEDIMENTO P1 COM X = %d\n", X );
 if ( X < 4 )
 {
 P1_7 ( X );
 P2_1 ( X );
 }
 printf ( "\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = %d\n", X );
 getchar ( ) ; // para esperar
} // fim do procedimento P1( )
void P2_1 ( int X )
{
 printf ( "CHAMADO O PROCEDIMENTO P2 COM X = %d\n", X );
 if ( X > 1 )
 P2_1 ( X - 1 );
 printf ( "RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = %d", X );
 getchar ( ); // para esperar
} // fim procedimento P2

void exemplo508(){
    // PROGRAMA PARA MOSTRAR PASSAGENS DE PARAMETROS
     printf ( "EXEMPLO0508 - MULTIPLAS CHAMADAS/RETORNOS\n\n" );
     P1_7 ( 1 );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO0508 - MULTIPLAS CHAMADAS/RETORNOS

        CHAMADO O PROCEDIMENTO P1 COM X = 2
        CHAMADO O PROCEDIMENTO P1 COM X = 3
        CHAMADO O PROCEDIMENTO P1 COM X = 4

        RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = 4

        CHAMADO O PROCEDIMENTO P2 COM X = 3
        CHAMADO O PROCEDIMENTO P2 COM X = 2
        CHAMADO O PROCEDIMENTO P2 COM X = 1
        RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = 1
        RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = 2
        RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = 3

        RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = 3

        CHAMADO O PROCEDIMENTO P2 COM X = 2
        CHAMADO O PROCEDIMENTO P2 COM X = 1
        RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = 1
        RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = 2

        RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = 2


        PRESSIONAR <Enter> PARA TERMINAR.
     */
}

#include "my_lib.h"
void exemplo509(){
    // PROGRAMA PARA MOSTRAR O USO DE MODULOS
     println ( "EXEMPLO0509 - USO DE MODULOS" );
     pause ( "PRESSIONAR <Enter> PARA TERMINAR." );
     //return ( EXIT_SUCCESS );

     //saida
     /*
     EXEMPLO0509 - USO DE MODULOS

        PRESSIONAR <Enter> PARA TERMINAR.

     */
}

#include "my_string.h"
void exemplo510(){
    // PROGRAMA PARA MOSTRAR O USO DE MODULOS
    // VARIAVEIS :
     chars text = "MUDAR DE LINHA";
     println ( "EXEMPLO0509 - USO DE MODULOS" );
     printf ( "%c", EOL );
     printf ( "%s%c", text, EOL );
     pause ( "PRESSIONAR <Enter> PARA TERMINAR." );
     //return ( EXIT_SUCCESS );

     //saida
/*
EXEMPLO0509 - USO DE MODULOS

MUDAR DE LINHA

PRESSIONAR <Enter> PARA TERMINAR.

*/

}

int main(void){
    int opcao;
    do{
        printf("\n\tMenu de opcoes: \n");
        printf("\t0) Sair\n");
        printf("\t1) Exemplo 501\n");
        printf("\t2) Exemplo 502\n");
        printf("\t3) Exemplo 503\n");
        printf("\t4) Exemplo 504\n");
        printf("\t5) Exemplo 505\n");
        printf("\t6) Exemplo 506\n");
        printf("\t7) Exemplo 507\n");
        printf("\t8) Exemplo 508\n");
        printf("\t9) Exemplo 509\n");
        printf("\t10) Exemplo 510\n");
        printf("\tDigite a opcao desejada: \n");
        scanf("%d", &opcao);

        switch(opcao){
            case 0: break;
            case 1:
                exemplo501();
                break;
            case 2:
                exemplo502();
                break;
            case 3:
                exemplo503();
                break;
            case 4:
                exemplo504();
                break;
            case 5:
                exemplo505();
                break;
            case 6:
                exemplo506();
                break;
            case 7:
                exemplo507();
                break;
            case 8:
                exemplo508();
                break;
            case 9:
                exemplo509();
                break;
            case 10:
                exemplo510();
                break;


            default:
                printf("Opcao invalida...");
                break;
        }


    } while(opcao != 0);
return 0;
}
