//Guia_0304.v

/*
 Guia_0304.v
 828333 - Alessandra Faria Rodrigues
*/
module Guia_0304;
// define data
 reg signed [7:0] a1 = 8'b00011001; // binary
 reg signed [7:0] a2 = 8'b001101; // binary
 reg signed [7:0] b1 = 8'b00000101 ; // binary
 reg signed [7:0] b2 = 8'b0000010 ; // binary
 reg signed [7:0] c1 = 8'b00100110 ; // binary
 reg signed [7:0] c2 = 8'b00101101 ; // binary
 reg signed [7:0] d1 = 8'b11111110 ; // binary
 reg signed [7:0] d2 = 8'b10110111 ; // binary
 //reg signed [7:0] e1 = 8'b00011111010010 ; // binary
 //reg signed [7:0] e2 = 8'b00101001010001 ; // binary
 reg signed [7:0] f = 0 ; // binary
// actions
 initial
 begin : main
 $display ( "Guia_0304 - Tests" );
 f = a1-a2;
 $display ( "a = a1-a2 = %8b-%8b = %8b = %d", a1, a2, f, f );
 f = b1-b2;
 $display ( "b = b1-b2 = %8b-%8b = %8b = %d", b1, b2, f, f );
 b1 = 8'b00001101;
 b2 = 8'b00000001;
 f = b1-b2; 
 $display ( "b = b1-b2 = %8b-%8b = %8b = %d", b1, b2, f, f );

 f = c1-c2;
 $display ( "c = c1-c2 = %8b-%8b = %8b = %d", c1, c2, f, f );

 f = d1-d2;
 $display ( "d = d1-d2 = %8b-%8b = %8b = %d", d1, d2, f, f );

 //f = e1-e2;
 //$display ( "e = e1-e2 = %8b-%8b = %8b = %d", e1, e2, f, f );
 end // main
endmodule // Guia_0304

/*
Guia_0304 - Tests
a = a1-a2 = 00011001-00001101 = 00001100 =   12
b = b1-b2 = 00000101-00000010 = 00000011 =    3
b = b1-b2 = 00001101-00000001 = 00001100 =   12
c = c1-c2 = 00100110-00101101 = 11111001 =   -7
d = d1-d2 = 11111110-10110111 = 01000111 =   71

*/