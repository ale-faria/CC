//Guia_0303.v

/*
 Guia_0303.v
 828333 - Alessandra Faria Rodrigues
*/
module Guia_0303;
// define data
 reg signed [7:0] a = 8'b11110110; // binary
 reg signed [6:0] b = 8'b11110011 ; // binary
 reg signed [5:0] c = 8'b11100100 ; // binary
 reg signed [5:0] d = 8'b11011011 ; // binary
 reg signed [5:0] e = 8'b11110011 ; // binary
 reg signed [7:0] f = 0 ; // binary
 reg signed [6:0] g = 0 ; // binary
// actions
 initial
 begin : main
 $display ( "Guia_0303 - Tests" );
 f = ~a+1;
 g = ~(a-1);
 $display ( "a = %8b -> C1(a) = %8b -> C2(a) = %8b = %d = %d", a, ~a, f, f, g );
 f = ~b+1;
 g = ~(b-1);
 $display ( "b = %8b -> C1(b) = %8b -> C2(b) = %8b = %d = %d", b, ~b, f, f, g );
 f = ~c+1;
 g = ~(c-1);
 $display ( "c = %8b -> C1(c) = %8b -> C2(c) = %8b = %d = %d", c, ~c, f, f, g );
 f = ~d+1;
 g = ~(d-1);
 $display ( "d = %8b -> C1(d) = %8b -> C2(d) = %8b = %d = %d", d, ~d, f, f, g );
 f = ~e+1;
 g = ~(e-1);
 $display ( "e = %8b -> C1(e) = %8b -> C2(e) = %8b = %d = %d", e, ~e, f, f, g );
 end // main end // main
endmodule // Guia_0303

/*
Guia_0303 - Tests
a = 11110110 -> C1(a) = 00001001 -> C2(a) = 00001010 =   10 =  10
b =  1110011 -> C1(b) =  0001100 -> C2(b) = 00001101 =   13 =  13
c =   100100 -> C1(c) =   011011 -> C2(c) = 00011100 =   28 =  28
d =   011011 -> C1(d) =   100100 -> C2(d) = 11100101 =  -27 = -27
e =   110011 -> C1(e) =   001100 -> C2(e) = 00001101 =   13 =  13
*/