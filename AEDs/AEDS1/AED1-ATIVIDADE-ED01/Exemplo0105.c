/*
 Exemplo0100 - v0.5. - 27 / 02 / 2024
 Author: ALESSANDRA FARIA RODRIGUES

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0100 exemplo0100.c
 Windows: gcc -o exemplo0100 exemplo0100.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0100
 Windows: exemplo0100
*/
// dependencias
#include <stdio.h> // para as entradas e saidas
#include <stdlib.h> // para outras funcoes de uso geral
#include <stdbool.h>
#include <string.h> // para cadeias de caracteres

/**
 Method_01.
*/
void method_01 ( void )
{
    // definir dado
 int x = 0; // definir variavel com valor inicial
 // identificar
 printf ( "%s\n", "Method_01" );
 // mostrar valor inicial
 printf ( "\n%s%d\n", "x = ", x );
// OBS.: O formato para int -> %d (ou %i)
 printf ( "&%s%p\n" , "x = ", &x );
// OBS.: O formato para endereco -> %p)
// ler do teclado
 printf ( "Entrar com um valor inteiro: " );
 scanf ( "%d", &x );
// OBS.: Necessario indicar o endereco -> &
 getchar ( ); // OBS.: Limpar a entrada de dados
// mostrar valor lido
 printf ( "%s%i\n", "x = ", x );
 // encerrar
 printf ( "\nApertar ENTER para continuar.\n" );
 getchar ( );
} // end method_01 ( )

/**
 Method_02.
*/
void method_02 ( void )
{
// definir dado
 double x = 0.0; // definir variavel com valor inicial
// OBS.: Definir a parte fracionaria e' util
// identificar
 printf ( "\n%s\n", "Method_02 - Programa - v0.0" );
// mostrar valor inicial
 printf ( "\n%s%lf\n", "x = ", x );
// OBS.: O formato para double -> %lf
// ler do teclado
 printf ( "Entrar com um valor real: " );
 scanf ( "%lf", &x );
// OBS.: Necessario indicar o endereco -> &
 getchar ( ); // OBS.: Limpar a entrada de dados
// mostrar valor lido
 printf ( "%s%lf\n", "x = ", x );
// encerrar
 printf ( "\n\nApertar ENTER para continuar.\n" );
 getchar( ); // aguardar por ENTER
} // end method_02 ( )

/**
 Method_03.
*/
void method_03 ( void )
{
// definir dado
 char x = 'A'; // definir variavel com valor inicial
// OBS.: Indispensavel usar apostrofos
// identificar
 printf ( "\n%s\n", "Method_03 - Programa - v0.0" );
// mostrar valor inicial
 printf ( "\n%s%c\n", "x = ", x );
// OBS.: O formato para char -> %c
// ler do teclado
 printf ( "Entrar com um caractere: " );
 scanf ( "%c", &x );
// OBS.: Necessario indicar o endereco -> &
 getchar ( ); // OBS.: Limpar a entrada de dados
// mostrar valor lido
 printf ( "%s%c\n", "x = ", x );
// encerrar
 printf ( "\n\nApertar ENTER para continuar.\n" );
 getchar( ); // aguardar por ENTER
 //return ( 0 ); // voltar ao SO (sem erros) //|89|warning: 'return' with a value, in function returning void|
} // end main( )

/**
 Method_04.
*/
void method_04 ( void )
{
// definir dado
 bool x = false; // definir variavel com valor inicial
// OBS.: Indispensavel usar minusculas
 int y = 0; // definir variavel auxiliar
// identificar
 printf ( "\n%s\n", "EXEMPLO0104 - Programa - v0.0" );
// mostrar valor inicial
 printf ( "\n%s%d\n", "x = ", x );
// OBS.: O formato para equivalente inteiro -> %d
// ler do teclado
 printf ( "Entrar com um valor logico: " );
 scanf ( "%d", &y );
// OBS.: Usar equivalente inteiro -> 0 = false
 getchar ( ); // OBS.: Limpar a entrada de dados
// garantir valor logico no intervalo [0:1]
 x = (y!=0);
// mostrar valor lido
 printf ( "%s%d\n", "x = ", x );
// encerrar
 printf ( "\n\nApertar ENTER para continuar.\n" );
 getchar( ); // aguardar por ENTER
} // end method_04 ( )

/**
 Method_05.
*/
void method_05 ( void )
{
// definir dado
 char x [80] = "abc"; // definir variavel com tamanho e valor inicial
 char *px = &x[0]; // definir alternativa para acesso via endereco
// identificar
 printf ( "\n%s\n", "Method_05 - Programa - v0.0" );
// mostrar valor inicial
 printf ( "\n%s%s\n", "x = ", x );
// OBS.: O formato para caracteres -> %s
// ler do teclado
 printf ( "Entrar com uma cadeia de caracteres: " );
 scanf ( "%s", x );
// OBS.: Nao devera' ser usado o endereco dessa vez !
// O tamanho do valor NAO devera' ultrapassar 80 s�mbolos.
 getchar ( ); // OBS.: Limpar a entrada de dados
// mostrar valor lido
 printf ( "%s%s\n", "x = ", x );
// ler do teclado (forma alternativa para acesso via endereco)
 printf ( "Entrar com outra cadeia de caracteres: " );
 scanf ( "%s", px );
 getchar ( ); // OBS.: Limpar a entrada de dados
// mostrar valor lido (forma alternativa para acesso via endereco)
 printf ( "%s%s\n", "x = ", px );
// encerrar
 printf ( "\n\nApertar ENTER para continuar.\n" );
 getchar( ); // aguardar por ENTER
} // end method_05 ( )



/*
 Funcao principal.
 @return codigo de encerramento
 @param argc - quantidade de parametros na linha de comandos
 @param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main ( int argc, char* argv [ ] )
{
// definir dado
 int opcao = 0; //expected ',' or ';' before 'printf'|
// identificar
 printf ( "%s\n", "Exemplo0100 - Programa = v0.0" );
 printf ( "%s\n", "Autor: ALESSANDRA FARIA RODRIGUES " );
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
 printf ( "\n" );
 // ler a opcao do teclado
 printf ( "\n%s", "Opcao = " );
 scanf ( "%d", &opcao );
 getchar( ); // para limpar a entrada de dados
 // para mostrar a opcao lida
 printf ( "\n%s%d", "Opcao = ", opcao );
 //|56|error: expected expression before '.' token|
 // escolher acao dependente da opcao
 switch ( opcao )
 {
 case 0: // nao fazer nada
 break;
 case 1: // executar method_01
 method_01 ( );
 break;
 case 2: // executar method_02
 method_02 ( );
 break;
 case 3: // executar method_03
 method_03 ( );
 break;
 case 4: // executar method_04
 method_04 ( );
 break;
 case 5: // executar method_05
 method_05 ( );
 break;
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
a.) 0.5
b.) -0.5
c.) 1.23456789
---------------------------------------------- historico
Versao Data Modificacao
0.1 __/__ esboco
0.2 __/__ mudanca de versao
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) identificacao de programa
leitura e exibicao de inteiro
0.2 02. ( ok ) identificacao de programa
*/

/*
SAIDA
Exemplo0100 - Programa = v0.0
Autor: ALESSANDRA FARIA RODRIGUES


Opcoes:

0 - Terminar
1 - Method_01
2 - Method_02
3 - Method_03
4 - Method_04
5 - Method_05

Opcao = 5

Opcao = 5
Method_05 - Programa - v0.0

x = abc
Entrar com uma cadeia de caracteres: ale
x = ale
Entrar com outra cadeia de caracteres: ola
x = ola


Apertar ENTER para continuar.


Opcoes:

0 - Terminar
1 - Method_01
2 - Method_02
3 - Method_03
4 - Method_04
5 - Method_05

Opcao = 0

Opcao = 0

Apertar ENTER para terminar.

*/
