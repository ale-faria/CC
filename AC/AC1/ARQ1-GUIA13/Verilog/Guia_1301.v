//Guia_1301.v

module contador_decrescente (
    input clk,      // Clock externo
    input reset,    // Reset assíncrono
    output [4:0] q  // Saída de 5 bits
);

    reg [4:0] q_reg; // Registrador para armazenar o estado atual

    // Inicialização do contador
    initial q_reg = 5'b11111;

    // Sempre que houver borda de clock ou reset
    always @(negedge clk or posedge reset) begin
        if (reset) begin
            q_reg <= 5'b11111; // Reset para 11111
        end else begin
            q_reg <= q_reg - 1'b1; // Decremento
        end
    end

    assign q = q_reg; // Conectar saída
endmodule