//Guia_0103.v

/*
 Guia_0103.v
 828333 - Alessandra Faria Rodrigues
*/
module Guia_0103;
// define data
 integer x = 13; // decimal
 reg [7:0] b = 0; // binary
// actions
 initial
 begin : main
 $display ( "Guia_0103 - Tests" );
 $display ( "x = %d" , x );
 $display ( "b = %8b", b );
 b = x;
 $display ( "b = %B (2) = %o (8) = %x (16) = %X (16)", b, b, b, b );

x = 61;
b = x;
 $display ( "x = %d" , x );
 $display ( "b = %8b", b );
 $display ( "b = %B (2) = %o (8) = %x (16) = %X (16)", b, b, b, b );

 x = 53;
b = x;
 $display ( "x = %d" , x );
 $display ( "b = %8b", b );
 $display ( "b = %B (2) = %o (8) = %x (16) = %X (16)", b, b, b, b );

 x = 77;
b = x;
 $display ( "x = %d" , x );
 $display ( "b = %8b", b );
 $display ( "b = %B (2) = %o (8) = %x (16) = %X (16)", b, b, b, b );

 x = 153;
b = x;
 $display ( "x = %d" , x );
 $display ( "b = %8b", b );
 $display ( "b = %B (2) = %o (8) = %x (16) = %X (16)", b, b, b, b );

 x = 753;
b = x;
 $display ( "x = %d" , x );
 $display ( "b = %8b", b );
 $display ( "b = %B (2) = %o (8) = %x (16) = %X (16)", b, b, b, b );
 end // main
endmodule // Guia_0103


/*
SAÍDA:
Guia_0103 - Tests
x =          13
b = 00000000
b = 00001101 (2) = 015 (8) = 0d (16) = 0d (16)
x =          61
b = 00111101
b = 00111101 (2) = 075 (8) = 3d (16) = 3d (16)
x =          53
b = 00110101
b = 00110101 (2) = 065 (8) = 35 (16) = 35 (16)
x =          77
b = 01001101
b = 01001101 (2) = 115 (8) = 4d (16) = 4d (16)
x =         153
b = 10011001
b = 10011001 (2) = 231 (8) = 99 (16) = 99 (16)
x =         753
b = 11110001
b = 11110001 (2) = 361 (8) = f1 (16) = f1 (16)
*/