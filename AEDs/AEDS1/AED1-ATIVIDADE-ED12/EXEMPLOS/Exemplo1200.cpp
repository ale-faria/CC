#include "io.hpp"
#include "mymatrix.hpp"

/**
 Method_01 - Mostrar certa quantidade de valores.
*/
void method_01() {
  // definir dados
  Matrix<int> int_matrix(2, 2, 0);
  int_matrix.set(0, 0, 1);
  int_matrix.set(0, 1, 2);
  int_matrix.set(1, 0, 3);
  int_matrix.set(1, 1, 4);
  // identificar
  cout << "\nMethod_01 - v0.0\n" << endl;
  // mostrar dados
  int_matrix.print();
  // encerrar
  // pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

/*saida metodo 01:
Method_01 - v0.0


1       2
3       4
*/

/**
 Method_02.
*/
void method_02() {
  // definir dados
  Matrix<int> matrix(2, 2, 0);
  // identificar
  cout << endl << "Method_02 - v0.0" << endl;
  // ler dados
  matrix.read();
  // mostrar dados
  matrix.print();
  // encerrar
  // pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )

// saida metodo 02
/*Method_02 - v0.0

 0,  0 : 9
 0,  1 : 8
 1,  0 : 7
 1,  1 : 6


9       8
7       6*/

/**
 Method_03.
*/
void method_03() {
  // definir dados
  Matrix<int> matrix(2, 2, 0);
  // identificar
  cout << endl << "Method_03 - v0.0" << endl;
  // ler dados
  matrix.read();
  // mostrar dados
  matrix.print();
  // gravar dados
  matrix.fprint("MATRIX1.TXT");
  // encerrar
  // pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )

// saida metodo 03
/*Method_03 - v0.0

 0,  0 : 9
 0,  1 : 8
 1,  0 : 7
 1,  1 : 6


9       8
7       6*/

/**
 Method_04.
*/
void method_04() {
  // definir dados
  Matrix<int> matrix(1, 1, 0);
  // identificar
  cout << endl << "Method_04 - v0.0" << endl;
  // ler dados
  matrix.fread("MATRIX1.TXT");
  // mostrar dados
  matrix.print();
  // encerrar
  // pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )

// lê os dados do arquivo
// saida metodo 04
/*
Method_04 - v0.0

9       8
7       6*/

/**
 Method_05.
*/
void method_05() {
  // definir dados
  Matrix<int> int_matrix1(1, 1, 0);
  Matrix<int> int_matrix2(1, 1, 0);
  // identificar
  cout << endl << "Method_05 - v0.0" << endl;
  // ler dados
  int_matrix1.fread("MATRIX1.TXT");
  // mostrar dados
  cout << "\nOriginal\n" << endl;
  int_matrix1.print();
  // copiar dados
  int_matrix2 = int_matrix1;
  // mostrar dados
  cout << "\nCopia\n" << endl;
  int_matrix2.print();
  // encerrar
  // pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )

// saida metodo 05:
/*Method_05 - v0.0

Original


9       8
7       6


Copia


9       8
7       6
*/

/**
 Method_06.
*/
void method_06() {
  // definir dados
  Matrix<int> int_matrix(2, 2, 0);
  int_matrix.set(0, 0, 0);
  int_matrix.set(0, 1, 0);
  int_matrix.set(1, 0, 0);
  int_matrix.set(1, 1, 0);
  // identificar
  cout << endl << "Method_06 - v0.0" << endl;
  // mostrar dados
  int_matrix.print();
  // testar condicao
  cout << "Zeros = " << int_matrix.isZeros() << endl;
  // ler dados
  int_matrix.fread("MATRIX1.TXT");
  // mostrar dados
  int_matrix.print();
  // testar condicao
  cout << "Zeros = " << int_matrix.isZeros() << endl;
  // encerrar
  // pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )

// saida metodo 06:
/*Method_06 - v0.0

0       0
0       0

Zeros = 1

9       8
7       6

Zeros = 0*/

/**
 Method_07.
*/
void method_07() {
  // definir dados
  Matrix<int> int_matrix1(1, 1, 0);
  Matrix<int> int_matrix2(1, 1, 0);
  // identificar
  cout << endl << "Method_07 - v0.0" << endl;
  // ler dados
  int_matrix1.fread("MATRIX1.TXT");
  // mostrar dados
  cout << "\nMatrix_1\n";
  int_matrix1.print();
  // copiar dados
  int_matrix2 = int_matrix1;
  // mostrar dados
  cout << "\nMatrix_2\n";
  int_matrix2.print();
  // testar condicao
  cout << "Diferentes = " << (int_matrix1 != int_matrix2) << endl;
  // alterar dados
  int_matrix2.set(0, 0, (-1));
  // mostrar dados
  cout << "\nMatrix_1\n";
  int_matrix1.print();
  // mostrar dados
  cout << "\nMatrix_2\n";
  int_matrix2.print();
  // testar condicao
  cout << "Diferentes = " << (int_matrix1 != int_matrix2) << endl;
  // encerrar
  // pause ( "Apertar ENTER para continuar" );
} // end method_07 ( )

// saida metodo 07:
/*Method_07 - v0.0

Matrix_1

9       8
7       6


Matrix_2

9       8
7       6

Diferentes = 0

Matrix_1

9       8
7       6


Matrix_2

-1      8
7       6

Diferentes = 1*/

/**
 Method_08.
*/
void method_08 ( )
{
// definir dados
 Matrix <int> int_matrix1 ( 1, 1, 0 );
 Matrix <int> int_matrix2 ( 1, 1, 0 );
 Matrix <int> int_matrix3 ( 1, 1, 0 );
// identificar
 cout << endl << "Method_08 - v0.0" << endl;
// ler dados
 int_matrix1.fread ( "MATRIX1.TXT" );
// mostrar dados
 cout << "\nMatrix_1\n";
 int_matrix1.print ( );
// copiar dados
 int_matrix2 = int_matrix1;
// mostrar dados
 cout << "\nMatrix_2\n";
 int_matrix2.print ( );
// operar dados
 int_matrix3 = int_matrix1 - int_matrix2;
// mostrar dados
 cout << "\nMatrix_3\n";
 int_matrix3.print ( );
// encerrar
// pause ( "Apertar ENTER para continuar" );
} // end method_08 ( )

//saida metodo 08:
/*Method_08 - v0.0

Matrix_1

9       8
7       6


Matrix_2

9       8
7       6


Matrix_3

0       0
0       0*/

/**
 Method_09.
*/
void method_09 ( )
{
// definir dados
 Matrix <int> int_matrix1 ( 2, 2, 0 );
 int_matrix1.set ( 0, 0, 1 );
 int_matrix1.set ( 0, 1, 0 );
 int_matrix1.set ( 1, 0, 0 );
 int_matrix1.set ( 1, 1, 1 );
 Matrix <int> int_matrix2 ( 1, 1, 0 );
 Matrix <int> int_matrix3 ( 1, 1, 0 );
// identificar
 cout << endl << "Method_09 - v0.0" << endl;
// ler dados
 int_matrix2.fread ( "MATRIX1.TXT" );
// mostrar dados
 cout << "\nMatrix_1\n";
 int_matrix1.print ( );
// mostrar dados
 cout << "\nMatrix_2\n";
 int_matrix2.print ( );
// operar dados
 int_matrix3 = int_matrix1 * int_matrix2;
// mostrar dados
 cout << "\nMatrix_3\n";
 int_matrix3.print ( );
// encerrar
// pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )

//saida metodo 09:
/*Method_09 - v0.0

Matrix_1

1       0
0       1


Matrix_2

9       8
7       6


Matrix_3

9       8
7       6
*/

/**
 Method_10.
*/
void method_10 ( )
{
// definir dados
 Matrix <int> int_matrix ( 3, 3, 0 );
 int x = 0;
 int y = 0;
// identificar
 cout << endl << "Method_10 - v0.0" << endl;
// ler dados
 int_matrix.fread ( "MATRIX1.TXT" );
// mostrar dados
 cout << "\nMatrix\n";
 int_matrix.print ( );
// operar dados
 for ( int x = 0; x < int_matrix.getRows ( ); x=x+1 )
 {
 for ( int y = 0; y < int_matrix.getColumns ( ); y=y+1 )
 {
 int_matrix.set ( x, y, int_matrix.get ( x, y ) * (-1) );
 } // end for
 } // end for
// mostrar dados
 cout << "\nMatrix\n";
 int_matrix.print ( );
// encerrar
// pause ( "Apertar ENTER para continuar" );
} // end method_10 ( )

//saida metodo 10:
/*Method_10 - v0.0

Matrix

9       8
7       6


Matrix

-9      -8
-7      -6
*/

int main(void) {
    int opcao;
  do{
    std::cout << "\n\nEscolha uma das opcoes abaixo: \n";
    std::cout << "\n\t0: Sair";
    std::cout << "\n\t1: Metodo01";
    std::cout << "\n\t2: Metodo02";
    std::cout << "\n\t3: Metodo03";
    std::cout << "\n\t4: Metodo04";
    std::cout << "\n\t5: Metodo05";
    std::cout << "\n\t6: Metodo06";
    std::cout << "\n\t7: Metodo07";
    std::cout << "\n\t8: Metodo08";
    std::cout << "\n\t9: Metodo09";
    std::cout << "\n\t10: Metodo10\n";
    std::cin >> opcao;
    getchar();

    switch(opcao){
        case 0:
            break;
        case 1:
            method_01();
            break;
        case 2:
            method_02();
            break;
        case 3:
            method_03();
            break;
        case 4:
            method_04();
            break;
        case 5:
            method_05();
            break;
        case 6:
            method_06();
            break;
        case 7:
            method_07();
            break;
        case 8:
            method_08();
            break;
        case 9:
            method_09();
            break;
        case 10:
            method_10();
            break;

        default:
            std::cout << "Opcao invalida!\n";
            break;
    }

  } while(opcao != 0);

return 0;
}
