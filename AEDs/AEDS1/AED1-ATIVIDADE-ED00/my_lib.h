#ifndef MY_LIB_H
#define MY_LIB_H

// ------------------------------------ my_lib.h
// bibliotecas de funcoes auxiliares
#include <stdio.h> // para entradas e saídas
#include <stdlib.h> // para outras funcoes de uso geral
void pause ( char message [ ] )
{
 printf ( "\n%s", message );
 fflush ( stdin ); // limpar a entrada de dados
 getchar ( ); // para esperar
} // fim pause ( )
void println ( char text [ ] )
{ printf ( "%s\n", text ); }


#endif // MY_LIB_H
