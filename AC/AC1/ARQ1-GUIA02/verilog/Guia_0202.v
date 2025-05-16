//Guia_0202.v

/*
 Guia_0202.v
 828333 - Alessandra Faria Rodrigues
*/
module Guia_0202;
// define data
 real x = 0.75; // decimal
 integer y = 7 ; // counter
 reg [7:0] b = 0 ; // binary
// actions
 initial
 begin : main
 $display ( "Guia_0202 - Tests" );
 $display ( "x = %f" , x );
 $display ( "b = 0.%8b", b );
 while ( x > 0 && y >= 0 )
 begin
 if ( x*2 >= 1 )
 begin
 b[y] = 1;
 x = x*2.0 - 1.0;
 end
 else
 begin
 b[y] = 0;
 x = x*2.0;
 end // end if
 $display ( "b = 0.%8b", b );
 y=y-1;
 end // end while
 end // main
endmodule // Guia_0202


/*SAIDAS:
PARA x = 0.375
Guia_0202 - Tests
x = 0.375000
b = 0.00000000
b = 0.00000000
b = 0.01000000
b = 0.01100000

PARA x = 0.125 (apenas a parte fracionaria)
Guia_0202 - Tests
x = 0.125000
b = 0.00000000
b = 0.00000000
b = 0.00000000
b = 0.00100000

PARA x = 0.625
Guia_0202 - Tests
x = 0.625000
b = 0.00000000
b = 0.10000000
b = 0.10000000
b = 0.10100000

PARA x = 0.03125
Guia_0202 - Tests
x = 0.031250
b = 0.00000000
b = 0.00000000
b = 0.00000000
b = 0.00000000
b = 0.00000000
b = 0.00001000

PARA x = 0.75
Guia_0202 - Tests
x = 0.750000
b = 0.00000000
b = 0.10000000
b = 0.11000000
*/