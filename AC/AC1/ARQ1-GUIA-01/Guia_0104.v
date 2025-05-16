//Guia_0104.v

/*
Guia_0104.v
 828333 - Alessandra Faria Rodrigues
*/
module Guia_0104;
// define data
 integer x = 13; // decimal
 reg [7:0] b = 0; // binary
// actions
 initial
 begin : main
 $display ( "Guia_0104 - Tests" );
 $display ( "x = %d" , x );
 $display ( "b = %8b", b );
 b = x;
 $display ( "b = [%4b] [%4b] = %x %x", b[7:4], b[3:0], b[7:4], b[3:0] );

 b = 8'b11010;
 $display ( "b = [%3b] [%3b] = %o %o", b[5:3], b[2:0], b[5:3], b[2:0] );

 b = 8'b100111;
 $display ( "b = [%4b] [%4b] = %x %x", b[7:4], b[3:0], b[7:4], b[3:0] );

 b = 8'b100101;
 $display ( "b = [%3b] [%3b] = %o %o", b[5:3], b[2:0], b[5:3], b[2:0] );
 end // main
endmodule // Guia_0104
