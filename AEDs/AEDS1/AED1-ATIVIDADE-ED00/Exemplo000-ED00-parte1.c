/*
    AED1 - ED00 - parte 1
    DATA: 21/02/2024
    AUTORIA: ALESSANDRA FARIA RODRIGUES
    NUM. MATRICULA: 828333
*/

#include <stdio.h>
#include <stdlib.h>

void exemplo101(){
    printf ( "EXEMPLO101 - PRIMEIRO EXEMPLO EM C" );
    printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
    getchar ( ); // para esperar
    //return ( 0 );

    //saida
    /*
    EXEMPLO101 - PRIMEIRO EXEMPLO EM C
    PRESSIONAR <Enter> PARA TERMINAR.
    */

    //aqui precisa necessariamente clicar no enter pra encerrar
}

void exemplo102(){
    system ( "cls" ); // (Windows) para limpar a tela
    // system ( "clear" ); // (Linux ) para limpar a tela
     // (dependente do sistema operacional)
     printf ( "EXEMPLO102 - PRIMEIRO EXEMPLO EM C\n" );
     system ( "pause" ); // (Windows) para esperar
    // getchar( ); // para esperar
     // (dependente do sistema operacional)
     //return ( EXIT_SUCCESS );

//saida
/*
EXEMPLO102 - PRIMEIRO EXEMPLO EM C
Pressione qualquer tecla para continuar. . .
*/

//aqui clicando em qualquer tecla já encerra
}

void clrscr ( ) { system ( "cls" ); } // para Windows
void exemplo103(){
    clrscr ( ); // funcao para limpar a tela
     printf ( "EXEMPLO103 - PRIMEIRO EXEMPLO EM C" );
     printf ( "\n" ); // para mudar de linha
     printf ( "MATRICULA: 828333 ALUNO : ALESSANDRA FARIA RODRIGUES" );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
    EXEMPLO103 - PRIMEIRO EXEMPLO EM C
    MATRICULA: 828333 ALUNO : ALESSANDRA FARIA RODRIGUES
    PRESSIONAR <Enter> PARA TERMINAR.
     */

}

void exemplo104(){
    printf ( "EXEMPLO104 - PRIMEIRO EXEMPLO EM C" );
     printf ( "\n" ); // para mudar de linha (="\n")
     printf ( "MATRICULA: 828333 ALUNO : ALESSANDRA FARIA RODRIGUES" );
     printf ( "\n" ); // para mudar de linha
     printf ( "PRESSIONAR <Enter> PARA TERMINAR. " );
     getchar( ); // para esperar
     //return ( EXIT_SUCCESS );

     //SAIDA
     /*
    EXEMPLO104 - PRIMEIRO EXEMPLO EM C
    MATRICULA: 828333 ALUNO : ALESSANDRA FARIA RODRIGUES
    PRESSIONAR <Enter> PARA TERMINAR.
     */
}

void exemplo105(){
    printf ( "EXEMPLO105 - PRIMEIRO EXEMPLO EM C" );
     printf ( "\nMATRICULA: 828333 ALUNO : ALESSANDRA" );
     printf ( "\nEXEMPLOS DE VALORES : " );
     printf ( "\nCARACTERE : %c", 'A' ); // letra ou simbolo
     printf ( "\nINTEIRO : %d", 10 ); // valor sem parte fracionaria
     printf ( "\nREAL : %f", 3.1415 ); // valor com parte fracionaria
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR. " );
     getchar( ); // para esperar
     //return ( EXIT_SUCCESS );

     //SAIDA
     /*
     EXEMPLO105 - PRIMEIRO EXEMPLO EM C
    MATRICULA: 828333 ALUNO : ALESSANDRA
    EXEMPLOS DE VALORES :
    CARACTERE : A
    INTEIRO : 10
    REAL : 3.141500
    PRESSIONAR <Enter> PARA TERMINAR.
     */

}
void exemplo106(){
#define PI1 3.1415 // definicao de macro (nome para substituir valor)
    printf ( "EXEMPLO106 - PRIMEIRO EXEMPLO EM C " );
     printf ( "\nMATRICULA: 828333 ALUNO : ALESSANDRA" );
     printf ( "\nEXEMPLOS DE VALORES : " );
     printf ( "\nCARACTERE : %c", 'A' ); // letra ou simbolo
     printf ( "\nINTEIRO : %d", 10 ); // valor sem parte fracionaria
     printf ( "\nREAL : %f", PI1 ); // emprego de macro
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
     EXEMPLO106 - PRIMEIRO EXEMPLO EM C
    MATRICULA: 828333 ALUNO : ALESSANDRA
    EXEMPLOS DE VALORES :
    CARACTERE : A
    INTEIRO : 10
    REAL : 3.141500
    PRESSIONAR <Enter> PARA TERMINAR.
     */
}

void exemplo107(){
       // definicao de constante
     const float PI = 3.14; // com nome e tipo (melhor)
     printf ( "EXEMPLO107 - PRIMEIRO EXEMPLO EM C" );
     printf ( "\nMATRICULA: 828333 ALUNO : ALESSANDRA" );
     printf ( "\nEXEMPLOS DE VALORES : " );
     printf ( "\nCARACTERE : %c", 'A' ); // letra ou simbolo
     printf ( "\nINTEIRO : %d", 10 ); // valor sem parte fracionaria
     printf ( "\nREAL : %f" , PI ); // constante real
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar( ); // para esperar
     //return ( EXIT_SUCCESS );

     //SAIDA
     /*
     EXEMPLO107 - PRIMEIRO EXEMPLO EM C
    MATRICULA: 828333 ALUNO : ALESSANDRA
    EXEMPLOS DE VALORES :
    CARACTERE : A
    INTEIRO : 10
    REAL : 3.140000
    PRESSIONAR <Enter> PARA TERMINAR.
     */
}

void exemplo108(){
    // definicao de constante
     const float PI = 3.14; // com nome e tipo (melhor)
    // definicao de variavel real
     float X = 10.01; // com atribuicao de valor inicial
     printf ( "EXEMPLO108 - PRIMEIRO EXEMPLO EM C" );
     printf ( "\nMATRICULA: 828333 ALUNO : ALESSANDRA" );
     printf ( "\nEXEMPLOS DE VALORES : " );
     printf ( "\nCARACTERE : %c", 'A' ); // letra ou simbolo
     printf ( "\nINTEIRO : %d", 10 ); // valor sem parte fracionaria
     printf ( "\nREAL : %f", PI ); // constante real
     printf ( "\nREAL : %f", X ); // variavel real
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar( ); // para esperar
     //return ( EXIT_SUCCESS );

     //SAIDA
     /*
     EXEMPLO108 - PRIMEIRO EXEMPLO EM C
    MATRICULA: 828333 ALUNO : ALESSANDRA
    EXEMPLOS DE VALORES :
    CARACTERE : A
    INTEIRO : 10
    REAL : 3.140000
    REAL : 10.010000
    PRESSIONAR <Enter> PARA TERMINAR.
     */
}

void exemplo109(){

    // definicao de constante
     const float PI = 3.14; // com nome e tipo (melhor)
    // definicao de variavel real
     float X = 10.01;
    // definicao de variavel inteira
     int I = 10;
     printf ( "EXEMPLO109 - PRIMEIRO EXEMPLO EM C" );
     printf ( "\nMATRICULA: 828333 ALUNO : ALESSANDRA" );
     printf ( "\nEXEMPLOS DE VALORES : " );
     printf ( "\nINTEIRO : %i" , I );
     printf ( "\nREAL : %f" , X );
     printf ( "\nREAL : %f" , PI );
     printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
     getchar( ); // para esperar
     //return ( EXIT_SUCCESS );

     //SAIDA
     /*
     EXEMPLO109 - PRIMEIRO EXEMPLO EM C
    MATRICULA: 828333 ALUNO : ALESSANDRA
    EXEMPLOS DE VALORES :
    INTEIRO : 10
    REAL : 10.010000
    REAL : 3.140000
    PRESSIONAR <Enter> PARA TERMINAR.
     */
}

void exemplo110(){
// definicao de constante
 const double PI = 3.14; // com nome e tipo (melhor)
// definicao de variavel real
 float X = 10.01;
// definicao de variavel inteira
 int I = 10;
// definicao de variavel caractere
 char N = '\n'; // mudar de linha
 printf ( "EXEMPLO110 - PRIMEIRO EXEMPLO EM C" );
 printf ( "\nMATRICULA: 828333 ALUNO : ALESSANDRA" );
 printf ( "%c%s", N, "EXEMPLOS DE VALORES : " );
 printf ( "%c%s%i" , N, "INTEIRO : " , I );
 printf ( "%c%s%f" , N, "REAL : " , X );
 printf ( "%c%s%lf", N, "REAL : " , PI );
 printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
 //return ( EXIT_SUCCESS );

    //saida
    /*
    EXEMPLO110 - PRIMEIRO EXEMPLO EM C
    MATRICULA: 828333 ALUNO : ALESSANDRA
    EXEMPLOS DE VALORES :
    INTEIRO : 10
    REAL : 10.010000
    REAL : 3.140000
    PRESSIONAR <Enter> PARA TERMINAR.
    */
}

int main(void){
    int opcao;
    do{
        printf("\n\tMenu de opcoes: \n");
        printf("\t0) Sair\n");
        printf("\t1) Exemplo 101\n");
        printf("\t2) Exemplo 102\n");
        printf("\t3) Exemplo 103\n");
        printf("\t4) Exemplo 104\n");
        printf("\t5) Exemplo 105\n");
        printf("\t6) Exemplo 106\n");
        printf("\t7) Exemplo 107\n");
        printf("\t8) Exemplo 108\n");
        printf("\t9) Exemplo 109\n");
        printf("\t10) Exemplo 110\n");
        printf("\tDigite a opcao desejada: \n");
        scanf("%d", &opcao);

        switch(opcao){
            case 0: break;
            case 1:
                exemplo101();
                break;
            case 2:
                exemplo102();
                break;
            case 3:
                exemplo103();
                break;
            case 4:
                exemplo104();
                break;
            case 5:
                exemplo105();
                break;
            case 6:
                exemplo106();
                break;
            case 7:
                exemplo107();
                break;
            case 8:
                exemplo108();
                break;
            case 9:
                exemplo109();
                break;
            case 10:
                exemplo110();
                break;


            default:
                printf("Opcao invalida...");
                break;
        }


    } while(opcao != 0);
return 0;
}
