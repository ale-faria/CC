//R01_01c.v
//c.) simplificação de mintermos por mapa de Veitch-Karnaugh

module SoP_simplificado (
    input wire a, b, c, d,
    output wire f
);

    assign f = (a & ~c)      |   // Quadra (12,8,13,9)
    		   (b & ~c & ~d) |   // Dupla (4,12)
    		   (a & b & ~d) // Dupla (12,14)
               
endmodule
