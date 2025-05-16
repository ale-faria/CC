/*
    AED1 - ED00 - EXTRAS - parte 3
    DATA: 25/02/2024
    AUTORIA: ALESSANDRA FARIA RODRIGUES
    NUM. MATRICULA: 828333
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef
 struct SPONTOS
 {
 double X,Y,Z;
 }
PONTOS;
void exemplo801(){
    // PROGRAMA PARA CALCULAR A DISTANCIA ENTRE PONTOS
    // DADOS:
     PONTOS P1, P2, P3;
     double D = 0.0;
     printf ( "EXEMPLO801 - DISTANCIA ENTRE PONTOS\n" );
     printf ( "\n ENTRE COM O PRIMEIRO PONTO : \n " );
     scanf ( "%lf %lf %lf", &P1.X, &P1.Y, &P1.Z );
     getchar( ); // limpar a entrada de dados
     printf ( "\n ENTRE COM O SEGUNDO PONTO : \n " );
     scanf ( "%lf %lf %lf", &P2.X, &P2.Y, &P2.Z );
     getchar( ); // limpar a entrada de dados
     P3.X = P2.X - P1.X;
     P3.Y = P2.Y - P1.Y;
     P3.Z = P2.Z - P1.Z;
     D = sqrt ( pow(P3.X, 2.0) +
     pow(P3.Y, 2.0) +
     pow(P3.Z, 2.0) );
     printf ( "\n DISTANCIA = %lf", D );
     printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO801 - DISTANCIA ENTRE PONTOS

         ENTRE COM O PRIMEIRO PONTO :
         2
        3
        4

         ENTRE COM O SEGUNDO PONTO :
         5 7 6

         DISTANCIA = 5.385165

        PRESSIONAR <Enter> PARA TERMINAR
     */
}

void exemplo802(){
    // PROGRAM PARA CALCULAR A DISTANCIA ENTRE PONTOS
    // DADOS:
     PONTOS P1, P2;
     double D = 0.0;
     printf ("EXEMPLO802 - DISTANCIA ENTRE PONTOS\n" );
     printf ( "\n ENTRE COM O PRIMEIRO PONTO : \n " );
     scanf ( "%lf %lf %lf", &P1.X, &P1.Y, &P1.Z );
     getchar( ); // limpar a entrada de dados
     printf ( "\n ENTRE COM O SEGUNDO PONTO : \n " );
     scanf ( "%lf %lf %lf", &P2.X, &P2.Y, &P2.Z );
     getchar( ); // limpar a entrada de dados
     D = sqrt ( pow(P2.X-P1.X, 2.0) +
     pow(P2.Y-P1.Y, 2.0) +
     pow(P2.Z-P1.Z, 2.0) );
     printf ( "\n DISTANCIA = %lf", D );
     printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO802 - DISTANCIA ENTRE PONTOS

         ENTRE COM O PRIMEIRO PONTO :
         1 1 1

         ENTRE COM O SEGUNDO PONTO :
         3 3 3

         DISTANCIA = 3.464102

        PRESSIONAR <Enter> PARA TERMINAR
     */
}

typedef PONTOS VETOR[2];
void exemplo803(){
    // PROGRAMA PARA CALCULAR A DISTANCIA ENTRE PONTOS
    // DADOS:
     VETOR V;
     double D = 0.0;
     printf ( "EXEMPLO803 - DISTANCIA ENTRE PONTOS\n" );
     printf ( "\n ENTRE COM O PRIMEIRO PONTO : \n " );
     scanf ( "%lf %lf %lf", &V[0].X, &V[0].Y, &V[0].Z );
     getchar( ); // limpar a entrada de dados
     printf ( "\n ENTRE COM O SEGUNDO PONTO : \n " );
     scanf ( "%lf %lf %lf", &V[1].X, &V[1].Y, &V[1].Z );
     getchar( ); // limpar a entrada de dados
     D = sqrt ( pow(V[1].X-V[0].X, 2.0) +
     pow(V[1].Y-V[0].Y, 2.0) +
     pow(V[1].Z-V[0].Z, 2.0) );
     printf ("\n DISTANCIA = %lf", D );
     printf ("\n\nPRESSIONAR <Enter> PARA TERMINAR" );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     /*
     EXEMPLO803 - DISTANCIA ENTRE PONTOS

         ENTRE COM O PRIMEIRO PONTO :
         1 1 1

         ENTRE COM O SEGUNDO PONTO :
         3 3 3

         DISTANCIA = 3.464102

        PRESSIONAR <Enter> PARA TERMINAR
     */
}

typedef double PONTOS_1[3]; // X, Y, Z
typedef
 struct SVETOR_1
 { PONTOS_1 P1, P2; }
VETOR_1;
void exemplo804(){
    // PROGRAMA PARA CALCULAR A DISTANCIA ENTRE PONTOS
    // DADOS:
     VETOR_1 V;
     double D = 0.0;
     printf ( "EXEMPLO804 - DISTANCIA ENTRE PONTOS\n" );
     printf ( "\n ENTRE COM O PRIMEIRO PONTO : \n " );
     scanf ( "%lf %lf %lf", &V.P1[0], &V.P1[1], &V.P1[2] );
     getchar( ); // limpar a entrada de dados
     printf ( "\n ENTRE COM O SEGUNDO PONTO : \n " );
     scanf ( "%lf %lf %lf", &V.P2[0], &V.P2[1], &V.P2[2] );
     getchar( ); // limpar a entrada de dados
     D = sqrt ( pow(V.P2[0]-V.P1[0], 2.0)+
     pow(V.P2[1]-V.P1[1], 2.0)+
     pow(V.P2[2]-V.P1[2], 2.0) );
     printf ( "\n DISTANCIA = %lf", D );
     printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO804 - DISTANCIA ENTRE PONTOS

         ENTRE COM O PRIMEIRO PONTO :
         1 1 1

         ENTRE COM O SEGUNDO PONTO :
         2 2 2

         DISTANCIA = 1.732051

        PRESSIONAR <Enter> PARA TERMINAR
     */
}

typedef struct SPONTO { double X,Y,Z; } PONTO ;
typedef struct SPONTOS_3 { PONTO P1,P2; } PONTOS_3;
void exemplo805(){
    // PROGRAMA PARA CALCULAR A DISTANCIA ENTRE PONTOS
    // DADOS:
     PONTOS_3 P;
     double D = 0.0;
     printf ( "EXEMPLO805 - DISTANCIA ENTRE PONTOS\n" );
     printf ( "\n ENTRE COM O PRIMEIRO PONTO : \n " );
     scanf ( "%lf %lf %lf", &P.P1.X, &P.P1.Y, &P.P1.Z );
     getchar( ); // limpar a entrada de dados
     printf ( "\n ENTRE COM O SEGUNDO PONTO : \n " );
     scanf ( "%lf %lf %lf", &P.P2.X, &P.P2.Y, &P.P2.Z );
     getchar( ); // limpar a entrada de dados
     D = sqrt ( pow(P.P2.X-P.P1.X, 2.0) +
     pow(P.P2.Y-P.P1.Y, 2.0) +
     pow(P.P2.Z-P.P1.Z, 2.0) );
     printf ( "\n DISTANCIA = %lf", D );
     printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO805 - DISTANCIA ENTRE PONTOS

         ENTRE COM O PRIMEIRO PONTO :
         2
        2
        2

         ENTRE COM O SEGUNDO PONTO :
         6
        6
        6

         DISTANCIA = 6.928203

        PRESSIONAR <Enter> PARA TERMINAR
     */
}

//typedef double VETOR[3];// X, Y, Z
typedef
 struct SPONTOS_2
 { PONTO P1; VETOR P2; }
PONTOS_2;
void exemplo806(){
    // PROGRAMA PARA CALCULAR A DISTANCIA ENTRE PONTOS
    // DADOS:
     PONTOS_2 P;
     double D = 0.0;
     printf ( "EXEMPLO806 - DISTANCIA ENTRE PONTOS\n" );
     printf ( "\n ENTRE COM O PRIMEIRO PONTO : \n " );
     scanf ( "%lf %lf %lf", &P.P1.X, &P.P1.Y, &P.P1.Z );
     getchar( ); // limpar a entrada de dados
     printf ( "\n ENTRE COM O SEGUNDO PONTO : \n " );
     scanf ( "%lf %lf %lf", &P.P2[0], &P.P2[1], &P.P2[2] );
     getchar( ); // limpar a entrada de dados
     D = sqrt ( pow(P.P2[0]-P.P1.X, 2.0) +
     pow(P.P2[1]-P.P1.Y, 2.0) +
     pow(P.P2[2]-P.P1.Z, 2.0) );
     printf ( "\n DISTANCIA = %lf", D );
     printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO806 - DISTANCIA ENTRE PONTOS

         ENTRE COM O PRIMEIRO PONTO :
         1
        2
        3

         ENTRE COM O SEGUNDO PONTO :
         4
        5
        6

         DISTANCIA = 5.196152

        PRESSIONAR <Enter> PARA TERMINAR
     */
}

typedef VETOR PONTOS[2];
void exemplo807(){
    // PROGRAMA PARA CALCULAR
    // A DISTANCIA ENTRE PONTOS
    // DADOS:
     PONTOS P;
     double D = 0.0;
     printf ( "EXEMPLO807 - DISTANCIA ENTRE PONTOS\n" );
     printf ( "\n ENTRE COM O PRIMEIRO PONTO : \n " );
     scanf ( "%lf %lf %lf", &P[0][0], &P[0][1], &P[0][2] );
     getchar( ); // limpar a entrada de dados
     printf ( "\n ENTRE COM O SEGUNDO PONTO : \n " );
     scanf ( "%lf %lf %lf", &P[1][0], &P[1][1], &P[1][2] );
     getchar( ); // limpar a entrada de dados
     D = sqrt ( pow(P[1][0]-P[0][0], 2.0) +
     pow(P[1][1]-P[0][1], 2.0) +
     pow(P[1][2]-P[0][2], 2.0) );
     printf ( "\n DISTANCIA = %lf", D );
     printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO807 - DISTANCIA ENTRE PONTOS

         ENTRE COM O PRIMEIRO PONTO :
         1
        2
        3

         ENTRE COM O SEGUNDO PONTO :
         7
        7
        7

         DISTANCIA = 8.774964

        PRESSIONAR <Enter> PARA TERMINAR
     */
}

typedef double VETOR1[3];// X, Y, Z
typedef VETOR1 VETOR [2];
void exemplo808(){
    // PROGRAMA PARA CALCULAR A DISTANCIA ENTRE PONTOS
    // DADOS:
     VETOR P;
     double D = 0.0;
     printf ( "EXEMPLO808 - DISTANCIA ENTRE PONTOS\n" );
     printf ( "\n ENTRE COM O PRIMEIRO PONTO : \n " );
     scanf ( "%lf %lf %lf", &P[0][0], &P[0][1], &P[0][2] );
     getchar( ); // limpar a entrada de dados
     printf ( "\n ENTRE COM O SEGUNDO PONTO : \n " );
     scanf ( "%lf %lf %lf", &P[1][0], &P[1][1], &P[1][2] );
     getchar( ); // limpar a entrada de dados
     D = sqrt( pow(P[1][0]-P[0][0], 2.0) +
     pow(P[1][1]-P[0][1], 2.0) +
     pow(P[1][2]-P[0][2], 2.0) );
     printf ( "\n DISTANCIA = %lf", D );
     printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO808 - DISTANCIA ENTRE PONTOS

         ENTRE COM O PRIMEIRO PONTO :
         1
        2
        3

         ENTRE COM O SEGUNDO PONTO :
         8
        8
        8

         DISTANCIA = 10.488088

        PRESSIONAR <Enter> PARA TERMINAR
     */
}

typedef PONTO VETOR[2];// X, Y, Z
void exemplo809(){
    // PROGRAMA PARA CALCULAR A DISTANCIA ENTRE PONTOS
    // DADOS:
     VETOR P;
     double D = 0.0;
     printf ( "EXEMPLO809 - DISTANCIA ENTRE PONTOS\n" );
     printf ( "\n ENTRE COM O PRIMEIRO PONTO : \n " );
     scanf ( "%lf%lf%lf", &(P[0].X), &(P[0].Y), &(P[0].Z));
     getchar( ); // limpar a entrada de dados
     printf ( "\n ENTRE COM O SEGUNDO PONTO : \n " );
     scanf ( "%lf%lf%lf", &(P[1].X), &(P[1].Y), &(P[1].Z));
     getchar( ); // limpar a entrada de dados
     D = sqrt ( pow(P[1].X-P[0].X, 2.0) +
     pow(P[1].Y-P[0].Y, 2.0) +
     pow(P[1].Z-P[0].Z, 2.0) );
     printf ( "\n DISTANCIA = %lf", D );
     printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO809 - DISTANCIA ENTRE PONTOS

         ENTRE COM O PRIMEIRO PONTO :
         1
        1
        1

         ENTRE COM O SEGUNDO PONTO :
         9
        9
        9

         DISTANCIA = 13.856406

        PRESSIONAR <Enter> PARA TERMINAR

     */
    }

void exemplo810(){
    // PROGRAMA PARA CALCULAR A DISTANCIA ENTRE PONTOS
    // DADOS:
     PONTOS P;
     double D = 0.0;
     printf ( "EXEMPLO810 - DISTANCIA ENTRE PONTOS\n");
     printf ( "\n ENTRE COM O PRIMEIRO PONTO : \n ");
     scanf ( "%lf%lf%lf", &(P.P1.X), &(P.P1.Y), &(P.P1.Z));
     getchar( ); // limpar a entrada de dados
     printf ( "\n ENTRE COM O SEGUNDO PONTO : \n ");
     scanf ( "%lf%lf%lf", &(P.P2.X), &(P.P2.Y), &(P.P2.Z));
     getchar( ); // limpar a entrada de dados
     D = sqrt ( pow(P.P2.X-P.P1.X, 2.0) +
     pow(P.P2.Y-P.P1.Y, 2.0) +
     pow(P.P2.Z-P.P1.Z, 2.0) );
     printf ( "\n DISTANCIA = %lf", D );
     printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
     getchar ( ); // para esperar
     //return ( EXIT_SUCCESS );

     //saida
     /*
        EXEMPLO810 - DISTANCIA ENTRE PONTOS

         ENTRE COM O PRIMEIRO PONTO :
         1
        1
        1

         ENTRE COM O SEGUNDO PONTO :
         9
        9
        9

         DISTANCIA = 13.856406

        PRESSIONAR <Enter> PARA TERMINAR
     */
}

int main(void){
    int opcao;
    do{
        printf("\n\tMenu de opcoes: \n");
        printf("\t0) Sair\n");
        printf("\t1) Exemplo 801\n");
        printf("\t2) Exemplo 802\n");
        printf("\t3) Exemplo 803\n");
        printf("\t4) Exemplo 804\n");
        printf("\t5) Exemplo 805\n");
        printf("\t6) Exemplo 806\n");
        printf("\t7) Exemplo 807\n");
        printf("\t8) Exemplo 808\n");
        printf("\t9) Exemplo 809\n");
        printf("\t10) Exemplo 810\n");
        printf("\tDigite a opcao desejada: \n");
        scanf("%d", &opcao);

        switch(opcao){
            case 0: break;
            case 1:
                exemplo801();
                break;
            case 2:
                exemplo802();
                break;
            case 3:
                exemplo803();
                break;
            case 4:
                exemplo804();
                break;
            case 5:
                exemplo805();
                break;
            case 6:
                exemplo806();
                break;
            case 7:
                exemplo807();
                break;
            case 8:
                exemplo808();
                break;
            case 9:
                exemplo809();
                break;
            case 10:
                exemplo810();
                break;


            default:
                printf("Opcao invalida...");
                break;
        }


    } while(opcao != 0);
return 0;
}
