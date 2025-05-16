//Guia_0302.v

/*
 Guia_0302.v
 828333 - Alessandra Faria Rodrigues
*/
module Guia_0302;
// define data
 reg [7:0] a = 8'b111001 ; 
 reg [7:0] b = 8'hb2 ; // hexadecimal
 reg [7:0] c = 8'b101101 ; 
 reg [6:0] d = 8'o146 ; // octal
 reg [7:0] e = 8'h6f ; // hexadecimal
 //reg [5:0] c = 13 ; // decimal
 reg [6:0] f = 0 ; // binary
 reg [8:0] g = 0 ; // binary
 reg [10:0] h = 0 ; // binary
// actions
 initial
 begin : main
 $display ( "Guia_0302 - Tests" );
 f = ~a+1;
 $display ( "a = %8b -> C1(a) = %8b -> C2(a) = %8b", a, ~a, f );
 g = ~b+1;
 $display ( "b = %7b -> C1(b) = %7b -> C2(b) = %7b", b, ~b, g );
 f = ~c+1;
 $display ( "c = %6b -> C1(c) = %6b -> C2(c) = %6b", c, ~c, f );
 h = ~d+1;
 $display ( "d = %6b -> C1(d) = %6b -> C2(d) = %6b", d, ~d, h );
 g = ~e+1;
 $display ( "e = %6b -> C1(e) = %6b -> C2(e) = %6b", e, ~e, g );
 end // main
endmodule // Guia_0302

/*
Guia_0302 - Tests
a = 00111001 -> C1(a) = 11000110 -> C2(a) =  1000111
b = 10110010 -> C1(b) = 01001101 -> C2(b) = 101001110
c = 00101101 -> C1(c) = 11010010 -> C2(c) = 1010011
d = 1100110 -> C1(d) = 0011001 -> C2(d) = 11110011010
e = 01101111 -> C1(e) = 10010000 -> C2(e) = 110010001
*/