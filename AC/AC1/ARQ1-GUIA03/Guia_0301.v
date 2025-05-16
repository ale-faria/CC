//Guia_0301.v

/*
 Guia_0301.v
 828333 - Alessandra Faria Rodrigues
*/
module Guia_0301;
// define data
 reg [7:0] a = 8'b000_1010 ; // binary
 reg [6:0] b = 8'b000_1101 ; // binary
 reg [5:0] c = 8'b00101001 ; // binary
 reg [7:0] d = 8'b00101111 ; // binary
 reg [6:0] e = 8'b00110100 ; // binary
 reg [5:0] f = 0 ; // binary
// actions
 initial
 begin : main
 $display ( "Guia_0301 - Tests" );
 f = ~a+1;
 $display ( "a = %8b -> C1(a) = %8b -> C2(a) = %8b", a, ~a, f );
 f = ~b+1;
 $display ( "b = %7b -> C1(b) = %7b -> C2(b) = %7b", b, ~b, f );
 f = ~c+1;
 $display ( "c = %6b -> C1(c) = %6b -> C2(c) = %6b", c, ~c, f );
 f = ~d+1;
 $display ( "d = %6b -> C1(d) = %6b -> C2(d) = %6b", d, ~d, f );
 f = ~e+1;
 $display ( "e = %6b -> C1(e) = %6b -> C2(e) = %6b", e, ~e, f );
 end // main
endmodule // Guia_0301

/*
Guia_0301 - Tests
a = 00001010 -> C1(a) = 11110101 -> C2(a) =   110110
b = 0001101 -> C1(b) = 1110010 -> C2(b) =  110011
c = 101001 -> C1(c) = 010110 -> C2(c) = 010111
d = 00101111 -> C1(d) = 11010000 -> C2(d) = 010001
e = 0110100 -> C1(e) = 1001011 -> C2(e) = 001100
*/