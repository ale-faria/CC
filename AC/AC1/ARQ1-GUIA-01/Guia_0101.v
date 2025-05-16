//Guia_0101.v


/*
 Guia_0101.v
 828333 - Alessandra Faria Rodrigues
*/
module Guia_0101;
// define data
 integer x = 13; // decimal
 reg [10:0] b = 0; // binary (bits - little endian)
// actions
 initial
 begin : main
 $display ( "Guia_0101 - Tests" );
 x = 26;
 b = x;
 $display ( "x = %d" , x );
 $display ( "b = %8b", b );
 x = 53;
 b = x;
 $display ( "x = %d" , x );
 $display ( "b = %8b", b );
 x = 713;
 b = x;
 $display ( "x = %d" , x );
 $display ( "b = %8b", b );
 x = 213;
 b = x;
 $display ( "x = %d" , x );
 $display ( "b = %8b", b );
 x = 365;
 b = x;
 $display ( "x = %d" , x );
 $display ( "b = %8b", b );
 end // main
endmodule // Guia_0101

/*
SAÍDA:
Guia_0101 - Tests
x =          26
b = 00000011010
x =          53
b = 00000110101
x =         713
b = 01011001001
x =         213
b = 00011010101
x =         365
b = 00101101101
*/