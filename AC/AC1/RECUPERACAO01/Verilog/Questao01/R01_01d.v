//R01_01d.v
//d.) simplificação de MAXTERMOS por mapa de Veitch-Karnaug

module PoS_simplificado (
    input wire A, B, C, D,
    output wire f
);

    assign f = (A | B)      &   // Quadra (12,8,13,9
    		   (~C | ~D)    &
    		   (B | ~C)     &
    		   (A | ~C)     &
    		   (A | ~D)
               
endmodule
