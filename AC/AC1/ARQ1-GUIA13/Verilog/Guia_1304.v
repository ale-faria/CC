//Guia_1304.v

module contador_decrescente (
    input clk,         // Clock externo
    input reset,       // Reset assíncrono
    output [3:0] q     // Saída de 4 bits
);

    reg [3:0] q_reg;   // Registrador para armazenar o estado do contador
    wire reset_dec;    // Sinal de reset para reiniciar a contagem

    // Inicialização
    initial begin
        q_reg = 4'b1001; // Começa em 1001 (9)
    end

    // Detectar condição de reset decádico (quando Q = 0000)
    assign reset_dec = (q_reg == 4'b0000);

    // Flip-flops JK - Comportamento de toggle para contagem decrescente
    always @(negedge clk or posedge reset) begin
        if (reset || reset_dec) begin
            q_reg <= 4'b1001; // Reinicia para 1001
        end else begin
            q_reg[0] <= ~q_reg[0]; // Toggle do bit menos significativo
        end
    end

    always @(negedge q_reg[0] or posedge reset) begin
        if (reset || reset_dec)
            q_reg[1] <= 1'b1; // Configuração para reiniciar corretamente
        else
            q_reg[1] <= ~q_reg[1]; // Toggle do segundo bit
    end

    always @(negedge q_reg[1] or posedge reset) begin
        if (reset || reset_dec)
            q_reg[2] <= 1'b0; // Configuração para reiniciar corretamente
        else
            q_reg[2] <= ~q_reg[2]; // Toggle do terceiro bit
    end

    always @(negedge q_reg[2] or posedge reset) begin
        if (reset || reset_dec)
            q_reg[3] <= 1'b1; // Configuração para reiniciar corretamente
        else
            q_reg[3] <= ~q_reg[3]; // Toggle do quarto bit
    end

    // Conectar saída
    assign q = q_reg;

endmodule
