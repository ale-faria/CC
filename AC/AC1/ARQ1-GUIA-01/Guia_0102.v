//Guia_0102.v

/*
 Guia_0102.v
 828333 - Alessandra Faria Rodrigues
*/
module Guia_0102;
// define data
 integer x = 0; // decimal
 reg [7:0] b = 0; // binary (bits - little endian)
// actions
 initial
 begin : main
 $display ( "Guia_0102 - Tests" );
 b = 8'b10101;
 x = b;
 $display ( "x = %d" , x );
 $display ( "b = %8b", b );

 b = 8'b11011;
 x = b;
 $display ( "x = %d" , x );
 $display ( "b = %8b", b );

 b = 8'b10010;
 x = b;
 $display ( "x = %d" , x );
 $display ( "b = %8b", b );

b = 8'b101011;
 x = b;
 $display ( "x = %d" , x );
 $display ( "b = %8b", b );

b = 8'b110111;
 x = b;
 $display ( "x = %d" , x );
 $display ( "b = %8b", b );
 end // main
endmodule // Guia_0102

/*
SAÍDA: 
Guia_0102 - Tests
x =          21
b = 00010101
x =          27
b = 00011011
x =          18
b = 00010010
x =          43
b = 00101011
x =          55
b = 00110111
*/