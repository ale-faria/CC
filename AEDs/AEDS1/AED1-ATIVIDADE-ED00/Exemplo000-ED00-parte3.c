/*
    AED1 - ED00 - parte 3
    DATA: 22/02/2024
    AUTORIA: ALESSANDRA FARIA RODRIGUES
    NUM. MATRICULA: 828333
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void exemplo301(){
    // PROGRAMA PARA LER UM VALOR INTEIRO E VERIFICAR SE E' ZERO
    // VARIAVEL:
     int X = 0;
     printf ( "EXEMPLO301 - LER E TESTAR UM VALOR INTEIRO" );
     printf ( "\nFORNECER UM VALOR INTEIRO QUALQUER: " );
     scanf ( "%d", &X );
     getchar( ); // limpar a entrada de dados
     if ( X == 0 )
     printf ( "\nO VALOR DIGITADO FOI ZERO" );
     else
     printf ( "\nO VALOR DIGITADO NAO FOI ZERO" );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO301 - LER E TESTAR UM VALOR INTEIRO
        FORNECER UM VALOR INTEIRO QUALQUER: 2

        O VALOR DIGITADO NAO FOI ZERO
        PRESSIONAR <Enter> PARA TERMINAR.
     */

}

void exemplo302(){
    // PROGRAMA PARA LER UM REAL E TESTAR SE DIFERENTE DE ZERO
    // VARIAVEL:
     float X = 0.0;
     printf ( "EXEMPLO302 - LER E TESTAR UM VALOR REAL" );
     printf ( "\nFORNECER UM VALOR REAL DIFERENTE DE ZERO: " );
     scanf ( "%f", &X );
     getchar( ); // limpar a entrada de dados
     if( X != 0.0 )
     printf ( "\nO VALOR DIGITADO FOI DIFERENTE DE ZERO" );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO302 - LER E TESTAR UM VALOR REAL
        FORNECER UM VALOR REAL DIFERENTE DE ZERO: 1

        O VALOR DIGITADO FOI DIFERENTE DE ZERO
        PRESSIONAR <Enter> PARA TERMINAR.
     */

}

void exemplo303(){
    // PROGRAMA PARA LER CARACTERE E VERIFICAR SE E' UM ALGARISMO
    // VARIAVEL:
     char X = '0';
     printf ( "EXEMPLO303 - LER E TESTAR UM CARACTERE" );
     printf ( "\nFORNECER UM ALGARISMO QUALQUER: " );
     scanf ( "%c", &X );
     getchar( ); // limpar a entrada de dados
     if( X >= '0' && X <= '9' )
     {
     printf ( "\nO VALOR DIGITADO FOI UM ALGARISMO" );
     printf ( "\nO ALGARISMO DIGITADO FOI: %c", X );
     } // if ALGARISMO
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO303 - LER E TESTAR UM CARACTERE
        FORNECER UM ALGARISMO QUALQUER: 1

        O VALOR DIGITADO FOI UM ALGARISMO
        O ALGARISMO DIGITADO FOI: 1
        PRESSIONAR <Enter> PARA TERMINAR.
     */
}

void exemplo304(){
    // PROGRAMA PARA LER CARACTERE E TESTAR SE NAO E' ALGARISMO
    // VARIAVEL:
     char X = '0';
     printf ( "EXEMPLO304 - LER E TESTAR CARACTERE" );
     printf ( "\nFORNECER UM CARACTERE QUALQUER: " );
     scanf ( "%c", &X );
     getchar( ); // limpar a entrada de dados
     if( !( X >= '0' && X <= '9') )
     {
     printf ( "\nNAO FOI DIGITADO UM ALGARISMO" );
     printf ( "\nFOI DIGITADO O CARACTERE: %c", X );
     } // if NAO ALGARISMO
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO304 - LER E TESTAR CARACTERE
        FORNECER UM CARACTERE QUALQUER: 2

        PRESSIONAR <Enter> PARA TERMINAR.
     */
     /*
        EXEMPLO304 - LER E TESTAR CARACTERE
        FORNECER UM CARACTERE QUALQUER: a

        NAO FOI DIGITADO UM ALGARISMO
        FOI DIGITADO O CARACTERE: a
        PRESSIONAR <Enter> PARA TERMINAR.

     */

}

void exemplo305(){
    // PROGRAMA PARA LER E TESTAR A IGUALDADE DE DOIS INTEIROS
    // VARIAVEIS:
     int X=0, Y=0;
     printf ( "EXEMPLO305 - LER E TESTAR DOIS VALORES INTEIROS" );
     printf ( "\nFORNECER UM VALOR INTEIRO QUALQUER: " );
     scanf ( "%d", &X );
     getchar( ); // limpar a entrada de dados
     printf ( "\nFORNECER OUTRO VALOR INTEIRO QUALQUER: " );
     scanf ( "%d", &Y );
     getchar( ); // limpar a entrada de dados
     if( X == Y )
     printf ( "\nDOIS VALORES IGUAIS" );
     else
     {
     printf ( "\n%d", X );
     printf ( " DIFERENTE DE " );
     printf ( "%d", Y );
     }
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO305 - LER E TESTAR DOIS VALORES INTEIROS
        FORNECER UM VALOR INTEIRO QUALQUER: 2

        FORNECER OUTRO VALOR INTEIRO QUALQUER: 3

        2 DIFERENTE DE 3
        PRESSIONAR <Enter> PARA TERMINAR.
     */
     /*
        EXEMPLO305 - LER E TESTAR DOIS VALORES INTEIROS
        FORNECER UM VALOR INTEIRO QUALQUER: 2

        FORNECER OUTRO VALOR INTEIRO QUALQUER: 2

        DOIS VALORES IGUAIS
        PRESSIONAR <Enter> PARA TERMINAR.
     */
}

void exemplo306(){
    // PROGRAMA PARA LER E TESTAR DOIS VALORES REAIS
    // VARIAVEIS:
     double X=0.0, Y=0.0;
     printf ( "EXEMPLO306 - LER E TESTAR DOIS VALORES REAIS" );
     printf ( "\nFORNECER UM VALOR REAL QUALQUER: " );
     scanf ( "%lf", &X );
     getchar( ); // limpar a entrada de dados
     printf ( "\nFORNECER OUTRO VALOR REAL QUALQUER: " );
     scanf ( "%lf", &Y );
     getchar( ); // limpar a entrada de dados
     if( ! (X == Y) )
     {
     printf ( "\n%lf", X );
     printf ( " DIFERENTE DE " );
     printf ( "%lf", Y );
     }
     else
     {
     printf ( "VALORES IGUAIS" );
     } // if VALORES DIFERENTES
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO306 - LER E TESTAR DOIS VALORES REAIS
        FORNECER UM VALOR REAL QUALQUER: 1

        FORNECER OUTRO VALOR REAL QUALQUER: 2

        1.000000 DIFERENTE DE 2.000000
        PRESSIONAR <Enter> PARA TERMINAR.
     */
     /*
        EXEMPLO306 - LER E TESTAR DOIS VALORES REAIS
        FORNECER UM VALOR REAL QUALQUER: 1

        FORNECER OUTRO VALOR REAL QUALQUER: 1
        VALORES IGUAIS
        PRESSIONAR <Enter> PARA TERMINAR.
     */
}

void exemplo307(){
    // PROGRAMA PARA TRATAR ALTERNATIVAS COM VALORES LOGICOS
    // VARIAVEIS:
     int X=0, Y=0;
     bool Z=false;
     printf ( "EXEMPLO307 - TRATAR VALORES LOGICOS" );
     printf ( "\nFORNECER UM VALOR INTEIRO QUALQUER: " );
     scanf ( "%d", &X );
     getchar( ); // limpar a entrada de dados
     printf ( "\nFORNECER OUTRO VALOR INTEIRO QUALQUER: " );
     scanf ( "%d", &Y );
     getchar( ); // limpar a entrada de dados
     Z = (X == Y);
     if( Z )
     printf ( "VALORES IGUAIS" );
     else
     printf ( "VALORES DIFERENTES" );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar( ); // para esperar
     return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO307 - TRATAR VALORES LOGICOS
        FORNECER UM VALOR INTEIRO QUALQUER: 1

        FORNECER OUTRO VALOR INTEIRO QUALQUER: 2
        VALORES DIFERENTES
        PRESSIONAR <Enter> PARA TERMINAR.
     */
     /*
        EXEMPLO307 - TRATAR VALORES LOGICOS
        FORNECER UM VALOR INTEIRO QUALQUER: 2

        FORNECER OUTRO VALOR INTEIRO QUALQUER: 2
        VALORES IGUAIS
        PRESSIONAR <Enter> PARA TERMINAR.
     */
}

void exemplo308(){
    // PROGRAMA PARA LER E TESTAR UMA LETRA
    // VARIAVEL:
     char X = '0';
     printf ( "EXEMPLO308 - LER E TESTAR UMA LETRA" );
     printf ( "\nFORNECER UMA LETRA QUALQUER: " );
     scanf ( "%c", &X );
     getchar( ); // limpar a entrada de dados
     if( X >= 'A' && X <= 'Z' )
     printf ( "FOI DIGITADA UMA LETRA MAIUSCULA" );
     else
     if( X >= 'a' && X <= 'z' )
     printf ( "FOI DIGITADA UMA LETRA MINUSCULA" );
     else
     printf ( "NAO FOI DIGITADA UMA LETRA" );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO308 - LER E TESTAR UMA LETRA
        FORNECER UMA LETRA QUALQUER: a
        FOI DIGITADA UMA LETRA MINUSCULA
        PRESSIONAR <Enter> PARA TERMINAR.
     */
     /*
        EXEMPLO308 - LER E TESTAR UMA LETRA
        FORNECER UMA LETRA QUALQUER: A
        FOI DIGITADA UMA LETRA MAIUSCULA
        PRESSIONAR <Enter> PARA TERMINAR.
     */

}

void exemplo309(){
    // PROGRAMA PARA COMPARAR CARACTERES < , = , >
    // VARIAVEL:
     char X = '0';
     printf ( "EXEMPLO309 - COMPARAR CARACTERES < , = , >" );
     printf ( "\nFORNECER UM DOS CARACTERES CITADOS: " );
     scanf ( "%c", &X );
     getchar( ); // limpar a entrada de dados
     switch( X )
     {
     case '>': printf ( "FOI DIGITADO O SINAL DE MAIOR" );
     break;
     case '=': printf ( "FOI DIGITADO O SINAL DE IGUAL" );
     break;
     case '<': printf ( "FOI DIGITADO O SINAL DE MENOR" );
     break;
     default : printf ( "FOI DIGITADO UM OUTRO CARACTERE QUALQUER" );
     } // COMPARACAO DE X COM < , = , >
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO309 - COMPARAR CARACTERES < , = , >
        FORNECER UM DOS CARACTERES CITADOS: =
        FOI DIGITADO O SINAL DE IGUAL
        PRESSIONAR <Enter> PARA TERMINAR.
     */
     /*
        EXEMPLO309 - COMPARAR CARACTERES < , = , >
        FORNECER UM DOS CARACTERES CITADOS: m
        FOI DIGITADO UM OUTRO CARACTERE QUALQUER
        PRESSIONAR <Enter> PARA TERMINAR.
     */

}

void exemplo310(){
    // PROGRAMA PARA IDENTIFICAR CARACTERES
    // VARIAVEL
     char X = '0';
     printf ( "EXEMPLO310 - IDENTIFICAR CARACTERES" );
     printf ( "\nFORNECER UM CARACTERE QUALQUER: " );
     scanf ( "%c", &X );
     getchar( ); // limpar a entrada de dados
     switch ( X )
     {
     case 'A':
     case 'E':
     case 'I':
     case 'O':
     case 'U': printf ( "FOI DIGITADO UMA VOGAL" );
     break;
     case '0':
     case '1':
     case '2':
     case '3':
     case '4':
     case '5':
     case '6':
     case '7':
     case '8':
     case '9': printf ( "FOI DIGITADO UM ALGARISMO" );
     printf ( "\nO NUMERO CORRESPONDENTE = %d", (X-48) );
     break;
     default: printf ( "FOI DIGITADO UM OUTRO CARACTERE QUALQUER" );
     } // IDENTIFICACAO DE UM CARACTERE
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO310 - IDENTIFICAR CARACTERES
        FORNECER UM CARACTERE QUALQUER: a
        FOI DIGITADO UM OUTRO CARACTERE QUALQUER
        PRESSIONAR <Enter> PARA TERMINAR.
     */
     /*
        EXEMPLO310 - IDENTIFICAR CARACTERES
        FORNECER UM CARACTERE QUALQUER: A
        FOI DIGITADO UMA VOGAL
        PRESSIONAR <Enter> PARA TERMINAR.
     */
     /*
        EXEMPLO310 - IDENTIFICAR CARACTERES
        FORNECER UM CARACTERE QUALQUER: 2
        FOI DIGITADO UM ALGARISMO
        O NUMERO CORRESPONDENTE = 2
        PRESSIONAR <Enter> PARA TERMINAR.
     */
}

int main(void){
    int opcao;
    do{
        printf("\n\tMenu de opcoes: \n");
        printf("\t0) Sair\n");
        printf("\t1) Exemplo 301\n");
        printf("\t2) Exemplo 302\n");
        printf("\t3) Exemplo 303\n");
        printf("\t4) Exemplo 304\n");
        printf("\t5) Exemplo 305\n");
        printf("\t6) Exemplo 306\n");
        printf("\t7) Exemplo 307\n");
        printf("\t8) Exemplo 308\n");
        printf("\t9) Exemplo 309\n");
        printf("\t10) Exemplo 310\n");
        printf("\tDigite a opcao desejada: \n");
        scanf("%d", &opcao);

        switch(opcao){
            case 0: break;
            case 1:
                exemplo301();
                break;
            case 2:
                exemplo302();
                break;
            case 3:
                exemplo303();
                break;
            case 4:
                exemplo304();
                break;
            case 5:
                exemplo305();
                break;
            case 6:
                exemplo306();
                break;
            case 7:
                exemplo307();
                break;
            case 8:
                exemplo308();
                break;
            case 9:
                exemplo309();
                break;
            case 10:
                exemplo310();
                break;


            default:
                printf("Opcao invalida...");
                break;
        }


    } while(opcao != 0);
return 0;
}
