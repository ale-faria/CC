//Guia_0205.v

/*
 Guia_0205.v
*/
module Guia_0205;
// define data
 reg [7:0] a1 = 8'b0101_1100 ; // binary
 reg [7:0] a2 = 8'b0010_0110 ; // binary
 reg [7:0] b1 = 8'b1000_1010 ;
 reg [7:0] b2 = 8'b0010_0100 ;
 reg [7:0] c1 = 8'b0101_1010 ;
 reg [7:0] c2 = 8'b0010_1010 ;
 reg [7:0] d1 = 8'b1011101 ;
 reg [7:0] d2 = 8'b11011 ;
 reg [7:0] e1 = 8'b1101011 ;
 reg [7:0] e2 = 8'b1101 ;
 reg [7:0] c;
// actions
 initial
 begin : main
 $display ( "Guia_0205 - Tests" );
 $display ( "a = %8b", a1 );
 $display ( "b = %8b", a2 );
 c = a1+a2;
 $display ( "c = a+b = %8b", c );

 $display ( "a = %8b", b1 );
 $display ( "b = %8b", b2 );
 c = b1-b2;
 $display ( "c = a-b = %8b", c );

 $display ( "a = %8b", c1 );
 $display ( "b = %8b", c2 );
 c = c1*c2;
 $display ( "c = a*b = %8b", c );

 $display ( "a = %8b", d1 );
 $display ( "b = %8b", d2 );
 c = d1/d2;
 $display ( "c = b/a = %8b", c );

 $display ( "a = %8b", e1 );
 $display ( "b = %8b", e2 );
 c = e1%e2;
 $display ( "c = b%%a = %8b", c );
 end // main
endmodule // Guia_0205

/*
Guia_0205 - Tests
a = 01011100
b = 00100110
c = a+b = 10000010
a = 10001010
b = 00100100
c = a-b = 01100110
a = 01011010
b = 00101010
c = a*b = 11000100
a = 01011101
b = 00011011
c = b/a = 00000011
a = 01101011
b = 00001101
c = b%a = 00000011
*/