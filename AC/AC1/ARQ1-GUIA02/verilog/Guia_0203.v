//Guia_0203.v

/*
 Guia_0203.v
 828333 - Alessandra Faria Rodrigues 
*/
module Guia_0203;
// define data
 //real x = 0.51; // decimal
 reg [7:0] b1 = 8'b10100100 ; // binary
 reg [7:0] b2 = 8'b10011000;
 reg [7:0] b3 = 8'b11101100;
 reg [7:0] b4 = 8'b10010000;
// actions
 initial
 begin : main
 $display ( "Guia_0203 - Tests" );
 //$display ( "x = %f" , x );
 $display ( "b1 = 0.%8b", b1 );
 $display ( "b1 = 0.%x%x (16)", b1[7:4],b1[3:0] );
 $display ( "b1 = 0.%o%o%o (8) ", b1[7:5],b1[4:2],b1[1:0] );

$display ( "b2 = 0.%8b", b2 );
 $display ( "b2 = 0.%x%x (16)", b2[7:4],b2[3:0] );
 $display ( "b2 = 0.%o%o%o (8) ", b2[7:5],b2[4:2],b2[1:0] );

 $display ( "b3 = 0.%8b", b3 );
 $display ( "b3 = 0.%x%x (16)", b3[7:4],b3[3:0] );
 $display ( "b3 = 0.%o%o%o (8) ", b3[7:5],b3[4:2],b3[1:0] );

 $display ( "b4 = 0.%8b", b4 );
 $display ( "b4 = 0.%x%x (16)", b4[7:4],b4[3:0] );
 $display ( "b4 = 0.%o%o%o (8) ", b4[7:5],b4[4:2],b4[1:0] );
 end // main
endmodule // Guia_0203

/*
Guia_0203 - Tests
b1 = 0.10100100
b1 = 0.a4 (16)
b1 = 0.510 (8)
b2 = 0.10011000
b2 = 0.98 (16)
b2 = 0.460 (8)
b3 = 0.11101100
b3 = 0.ec (16)
b3 = 0.730 (8)
b4 = 0.10010000
b4 = 0.90 (16)
b4 = 0.440 (8)
*/