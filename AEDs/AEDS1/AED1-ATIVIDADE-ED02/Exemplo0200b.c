/*
 Exemplo0200 - v0.2. - 10 / 03 /2024
 Author: ALESSANDRA FARIA RODRIGUES

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0200 exemplo0200.c
 Windows: gcc -o exemplo0200 exemplo0200.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0200
 Windows: exemplo0200
*/
// dependencias
#include "io.h" // bibliotecas e outras definicoes
/**
 Method_01.
*/
/**
 Method_01.
*/
void method_01 ( void )
{
// definir dado
 int x = 0; // definir variavel com valor inicial
// identificar
 IO_id ( "Method_01 - Programa - v0.2" );
// ler do teclado
 x = IO_readint ( "Entrar com um valor inteiro: " );
// testar valor
 if ( x == 0 )
 {
 IO_printf ( "%s (%d)\n", "Valor igual a zero", x );
 }
 if ( x != 0 )
 {
 IO_printf ( "%s (%d)\n", "Valor diferente de zero ", x );
 } // end if
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )
//SAIDA
/*Exemplo0200 - Programa = v0.2
Autor: ALESSANDRA


Opcoes:

0 - Terminar
1 - Method_01
2 - Method_02

Opcao = 1

Opcao = 1Method_01 - Programa - v0.2
Autor: ________________________

Entrar com um valor inteiro: 0
Valor igual a zero (0)

Apertar ENTER para continuar*/

/*
 Method_02.
*/
void method_02 ( void )
{
// definir dado
 int x = 0; // definir variavel com valor inicial
// identificar
 IO_id ( "Method_02 - Programa - v0.2" );
// ler do teclado
 x = IO_readint ( "Entrar com um valor inteiro: " );
// testar valor
 if ( x == 0 )
 {
 IO_printf ( "%s (%d)\n", "Valor igual a zero", x );
 }
 else // equivalente a "caso diferente do já' testado"
 {
 IO_printf ( "%s (%d)\n", "Valor diferente de zero ", x );
 } // end if
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )
//SAIDA
/*Exemplo0200 - Programa = v0.2
Autor: ALESSANDRA


Opcoes:

0 - Terminar
1 - Method_01
2 - Method_02

Opcao = 2

Opcao = 2Method_02 - Programa - v0.2
Autor: ________________________

Entrar com um valor inteiro: 5
Valor diferente de zero  (5)

Apertar ENTER para continuar
*/

/*
 Method_03.
*/
void method_03 ( void )
{
// definir dado
 int x = 0; // definir variavel com valor inicial
// identificar
 IO_id ( "Method_03 - Programa - v0.0" );
// ler do teclado
 x = IO_readint ( "Entrar com um valor inteiro: " );
// testar valor
 if ( x == 0 )
 {
 IO_printf ( "%s (%d)\n", "Valor igual a zero", x );
 }
 else
 {
 IO_printf ( "%s (%d)\n", "Valor diferente de zero ", x );
 if ( x > 0 )
 {
 IO_printf ( "%s (%d)\n", "Valor maior que zero", x );
 }
 else
 {
 IO_printf ( "%s (%d)\n", "Valor menor que zero", x );
 } // end if
 } // end if
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )
//SAIDA
/*
Opcoes:

0 - Terminar
1 - Method_01
2 - Method_02

Opcao = 3

Opcao = 3Method_03 - Programa - v0.0
Autor: ________________________

Entrar com um valor inteiro: -5
Valor diferente de zero  (-5)
Valor menor que zero (-5)

Apertar ENTER para continuar

*/

/*
 Method_04.
*/
void method_04 ( void )
{
// definir dado
 double x = 0.0; // definir variavel com valor inicial
// identificar
 IO_id ( "EXEMPLO0204 - Programa - v0.0" );
// ler do teclado
 x = IO_readdouble ( "Entrar com um valor real: " );
// testar valor
 if ( 1.0 <= x && x <= 10.0 )
 {
 IO_printf ( "%s (%lf)\n", "Valor dentro do intervalo [1:10] ", x );
 }
 else
 {
 IO_printf ( "%s (%lf)\n", "Valor fora do intervalo [1:10] ", x );
 if ( x < 1.0 )
 {
 IO_printf ( "%s (%lf)\n", "Valor abaixo do intervalo [1:10] ", x );
 }
 else
 {
 IO_printf ( "%s (%lf)\n", "Valor acima do intervalo [1:10]", x );
 } // end if
 } // end if
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )
//SAIDA
/*
Opcao = 4

Opcao = 4EXEMPLO0204 - Programa - v0.0
Autor: ________________________

Entrar com um valor real: 100.0
Valor fora do intervalo [1:10]  (100.000000)
Valor acima do intervalo [1:10] (100.000000)

Apertar ENTER para continuar
*/

/*
 Method_05.
*/
void method_05 ( void )
{
// definir dado
 char x = '_'; // definir variavel com valor inicial
// identificar
 IO_id ( "Method_05 - Programa - v0.0" );
// ler do teclado
 x = IO_readchar ( "Entrar com um caractere: " );
// testar valor
 if ( ('a' <= x) && (x <= 'z') )
 {
 IO_printf ( "%s (%c)\n", "Letra minuscula", x );
 }
 else
 {
 IO_printf ( "%s (%c)\n", "Valor diferente de minuscula", x );
 if ( ('A' <= x) && (x <= 'Z') )
 {
 IO_printf ( "%s (%c)\n", "Letra maiuscula", x );
 }
 else
 {
 if ( ('0' <= x) && (x <= '9') )
 {
 IO_printf ( "%s (%c)\n", "Algarismo", x );
 }
 else
 {
 IO_printf ( "%s (%c)\n", "Valor diferente de algarismo", x );
 } // end if
 } // end if
 } // end if
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )
//SAIDA
/*
Opcao = 5

Opcao = 5Method_05 - Programa - v0.0
Autor: ________________________

Entrar com um caractere: A
Valor diferente de minuscula (A)
Letra maiuscula (A)

Apertar ENTER para continuar
*/

/*
 Method_06.
*/
void method_06 ( void )
{
// definir dado
 char x = '_'; // definir variavel com valor inicial
// identificar
 IO_id ( "Method_06 - Programa - v0.0" );
// ler do teclado
 x = IO_readchar ( "Entrar com um caractere: " );
// testar valor
 if ( ( 'a' <= x && x <= 'z' ) || // minuscula OU
 ( 'A' <= x && x <= 'Z' ) ) // maiuscula
 {
 IO_printf ( "%s (%c)\n", "Letra", x );
 }
 else
 {
 IO_printf ( "%s (%c)\n", "Valor diferente de letra", x );
 } // end if
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )
//SAIDA
/*
Opcao = 6

Opcao = 6Method_06 - Programa - v0.0
Autor: ________________________

Entrar com um caractere: A
Letra (A)

Apertar ENTER para continuar*/

/*
 Method_07.
*/
void method_07 ( void )
{
// definir dado
 char x = '_'; // definir variavel com valor inicial
// identificar
 IO_id ( "Method_07 - Programa - v0.0" );
// ler do teclado
 x = IO_readchar ( "Entrar com um caractere: " );
// testar valor
 if ( ! ( ( 'a' <= x && x <= 'z' ) || // NAO (minuscula OU
 ( 'A' <= x && x <= 'Z' ) ) ) // maiuscula)
 {
 IO_printf ( "%s (%c)\n", "Valor diferente de letra", x );
 }
 else
 {
 IO_printf ( "%s (%c)\n", "Letra", x );
 } // end if
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_07 ( )
//SAIDA
/*
Opcao = 7

Opcao = 7Method_07 - Programa - v0.0
Autor: ________________________

Entrar com um caractere: A
Letra (A)

Apertar ENTER para continuar
*/

/*
 Method_08.
*/
void method_08 ( void )
{
// definir dado
 char x = '_'; // definir variavel com valor inicial
// identificar
 IO_id ( "Method_08 - Programa - v0.0" );
// ler do teclado
 x = IO_readchar ( "Entrar com um caractere ['0','A','a']: " );
// testar valor
 switch ( x )
 {
 case '0':
 IO_printf ( "%s (%c=%d)\n", "Valor igual do simbolo zero", x, x );
 break;
 case 'A':
 IO_printf ( "%s (%c=%d)\n", "Valor igual 'a letra A", x, x );
 break;
 case 'a':
 IO_printf ( "%s (%c=%d)\n", "Valor igual 'a letra a", x, x );
 break;
 default: // se nao alguma das opcoes anteriores
 IO_printf ( "%s (%c=%d)\n", "Valor diferente das opcoes ['0','A','a']", x, x );
 } // end switch
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_08 ( )
//SAIDA
/*
Opcao = 8

Opcao = 8Method_08 - Programa - v0.0
Autor: ________________________

Entrar com um caractere ['0','A','a']: A
Valor igual 'a letra A (A=65)

Apertar ENTER para continuar
*/

/*
 Method_09.
*/
void method_09 ( void )
{
// definir dado
 int x = 0; // definir variavel com valor inicial
// identificar
 IO_id ( "Method_09 - Programa - v0.0" );
// ler do teclado
 x = IO_readint ( "Entrar com um inteiro [0,1,2,3]: " );
// testar valor
 switch ( x )
 {
 case 0:
 IO_printf ( "%s (%d)\n", "Valor igual a zero", x );
 break;
 case 1:
 IO_printf ( "%s (%d)\n", "Valor igual a um ", x );
 break;
 case 2:
 IO_printf ( "%s (%d)\n", "Valor igual a dois", x );
 break;
 case 3:
 IO_printf ( "%s (%d)\n", "Valor igual a tres", x );
 break;
 default: // se nao for alguma das opcoes anteriores
 IO_printf ( "%s (%d)\n", "Valor diferente das opcoes [0,1,2,3]", x );
 } // end switch
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )
//SAIDA
/*
Opcao = 9

Opcao = 9Method_09 - Programa - v0.0
Autor: ________________________

Entrar com um inteiro [0,1,2,3]: 1
Valor igual a um  (1)

Apertar ENTER para continuar*/

/*
 Method_10.
*/
void method_10 ( void )
{
// definir dado
 int x = 0; // definir variavel com valor inicial
// identificar
 IO_id ( "Method_09 - Programa - v0.0" );
// ler do teclado
 x = IO_readint ( "Entrar com um inteiro [0,1,2,3]: " );
// testar valor
 switch ( x )
 {
 case 0:
 IO_println ( IO_concat ( "Valor igual a zero (",
 IO_concat ( IO_toString_d ( x ), ")\n" ) ) );
 break;
 case 1:
 IO_println ( IO_concat ( "Valor igual a um (",
 IO_concat ( IO_toString_d ( x ), ")\n" ) ) );
 break;
 case 2:
 IO_println ( IO_concat ( "Valor igual a dois (",
 IO_concat ( IO_toString_d ( x ), ")\n" ) ) );
 break;
 case 3:
 IO_println ( IO_concat ( "Valor igual a três (",
 IO_concat ( IO_toString_d ( x ), ")\n" ) ) );
 break;
 default: // se nao for alguma das opcoes anteriores
 IO_println ( IO_concat ( "Valor diferente das opcoes [0,1,2,3] (",
 IO_concat ( IO_toString_d ( x ), ")" ) ) );
 } // end switch
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_10 ( )
//SAIDA
/*
Opcao = 10

Opcao = 10Method_09 - Programa - v0.0
Autor: ________________________

Entrar com um inteiro [0,1,2,3]: 3
Valor igual a trÛs (3)


Apertar ENTER para continuar*/




/*
 Funcao principal.
 @return codigo de encerramento
*/
int main ( void )
{
// definir dado
 int opcao = 0; //|33|error: expected ',' or ';' before 'printf'|
// identificar
 printf ( "%s\n", "Exemplo0200 - Programa = v0.2" );
 printf ( "%s\n", "Autor: ALESSANDRA" );
 printf ( "\n" ); // mudar de linha
// acoes
// repetir
 do
 {
 // para mostrar opcoes
 printf ( "\n%s\n", "Opcoes:" );
 printf ( "\n%s" , "0 - Terminar" );
 printf ( "\n%s" , "1 - Method_01" );
 printf ( "\n%s" , "2 - Method_02" );
 printf ( "\n%s" , "3 - Method_03" );
 printf ( "\n%s" , "4 - Method_04" );
 printf ( "\n%s" , "5 - Method_05" );
 printf ( "\n%s" , "6 - Method_06" );
 printf ( "\n%s" , "7 - Method_07" );
 printf ( "\n%s" , "8 - Method_08" );
 printf ( "\n%s" , "9 - Method_09" );
 printf ( "\n%s" , "10 - Method_10" );
 printf ( "\n" );
 // ler a opcao do teclado
 printf ( "\n%s", "Opcao = " );
 scanf ( "%d", &opcao );
 getchar( ); // para limpar a entrada de dados
 // para mostrar a opcao lida
 printf ( "\n%s%d", "Opcao = ", opcao );
 //. |51|error: expected expression before '.' token|// escolher acao dependente da opcao
 switch ( opcao )
 {
 case 0: /* nao fazer nada */ break;
 case 1: method_01 ( ); break;
 case 2: method_02 ( ); break;
 case 3: method_03 ( ); break;
 case 4: method_04 ( ); break;
 case 5: method_05 ( ); break;
 case 6: method_06 ( ); break;
 case 7: method_07 ( ); break;
 case 8: method_08 ( ); break;
 case 9: method_09 ( ); break;
 case 10: method_10 ( ); break;
 default: // comportamento padrao
 printf ( "\nERRO: Opcao invalida.\n" );
 break;
 } // end switch
 }
 while ( opcao != 0 );
// encerrar
 printf ( "\n\nApertar ENTER para terminar." );
 getchar( ); // aguardar por ENTER
 return ( 0 ); // voltar ao SO (sem erros)
} // end main ( )
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 0
b.) 5
c.) -5
---------------------------------------------- historico
Versao Data Modificacao
 0.1 __/__ esboco
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) identificacao de programa
*/

//SAIDA
/*Exemplo0200 - Programa = v0.2
Autor: ALESSANDRA


Opcoes:

0 - Terminar
1 - Method_01
2 - Method_02

Opcao = 2

Opcao = 2Method_02 - Programa - v0.2
Autor: ________________________

Entrar com um valor inteiro: 3
Valor diferente de zero  (3)

Apertar ENTER para continuar


Opcoes:

0 - Terminar
1 - Method_01
2 - Method_02

Opcao = 0

Opcao = 0

Apertar ENTER para terminar.

Process returned 0 (0x0)   execution time : 119.688 s
Press any key to continue.*/
