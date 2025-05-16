//R01_01b.v
//b.) expressão canônica para PoS(A,B,C,D)

module PoS_expression (
    input wire A, B, C, D,
    output wire f
);

    assign f = (A | B | C | D) &           // Maxtermo 0
               (A | B | C | ~D) &          // Maxtermo 1
               (A | B | ~C | D) &          // Maxtermo 2
               (A | B | ~C | ~D) &         // Maxtermo 3
               (A | ~B | C | ~D) &         // Maxtermo 5
               (A | ~B | ~C | D) &         // Maxtermo 6
               (A | ~B | ~C | ~D) &        // Maxtermo 7
               (~A | B | ~C | D) &         // Maxtermo 10
               (~A | B | ~C | ~D) &        // Maxtermo 11
               (~A | ~B | ~C | ~D);        // Maxtermo 15

endmodule
