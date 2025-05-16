//Guia_0201.v

/*
 Guia_0201.v
 828333 - Alessandra Faria Rodrigues
*/
module Guia_0201;
// define data
 real x = 0 ; // decimal
 real power2 = 1.0; // power of 2
 integer y = 7 ; // counter
 reg [7:0] b = 8'b11001000; // binary (only fraction part, Big Endian)
// actions
 initial
 begin : main
 $display ( "Guia_0201 - Tests" );
 $display ( "x = %f" , x );
 $display ( "b = 0.%8b", b );
 while ( y >= 0 )
 begin
 power2 = power2 / 2.0;
 if ( b[y] == 1 )
 begin
 x = x + power2;
 end
 $display ( "x = %f", x );
 y=y-1;
 end // end while
 end // main
endmodule // Guia_0201

/*SAIDAS:
PARA b = 8'b00011000;
Guia_0201 - Tests
x = 0.000000
b = 0.00011000
x = 0.000000
x = 0.000000
x = 0.000000
x = 0.062500
x = 0.093750
x = 0.093750
x = 0.093750
x = 0.093750

PARA b = 8'b01001000;
Guia_0201 - Tests
x = 0.000000
b = 0.01001000
x = 0.000000
x = 0.250000
x = 0.250000
x = 0.250000
x = 0.281250
x = 0.281250
x = 0.281250
x = 0.281250

PARA b = 8'b10101000;
Guia_0201 - Tests
x = 0.000000
b = 0.10101000
x = 0.500000
x = 0.500000
x = 0.625000
x = 0.625000
x = 0.656250
x = 0.656250
x = 0.656250
x = 0.656250

PARA b = 8'b11101000;
Guia_0201 - Tests
x = 0.000000
b = 0.11101000
x = 0.500000
x = 0.750000
x = 0.875000
x = 0.875000
x = 0.906250
x = 0.906250
x = 0.906250
x = 0.906250

PARA b = 8'b11001000;
Guia_0201 - Tests
x = 0.000000
b = 0.11001000
x = 0.500000
x = 0.750000
x = 0.750000
x = 0.750000
x = 0.781250
x = 0.781250
x = 0.781250
x = 0.781250
*/