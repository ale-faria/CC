//R01_01a.v
//a.) expressão canônica para SoP(a,b,c,d)

module SoP_expression (
    input wire a, b, c, d,
    output wire f
);

    assign f = (~a & b & ~c & ~d) |  // Mintermo 4
               (a & ~b & ~c & ~d) |  // Mintermo 8
               (a & ~b & ~c & d)  |  // Mintermo 9
               (a & b & ~c & ~d)  |  // Mintermo 12
               (a & b & ~c & d)   |  // Mintermo 13
               (a & b & c & ~d);     // Mintermo 14

endmodule
