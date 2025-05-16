//Guia_1303.v

module contador_decadico (
    input clk,         // Clock externo
    input reset,       // Reset assíncrono
    output [3:0] q     // Saída de 4 bits
);

    reg [3:0] q_reg;   // Registrador para armazenar o estado do contador
    wire reset_dec;    // Sinal de reset para contagem decádica

    // Inicialização
    initial begin
        q_reg = 4'b0000; // Inicia em 0
    end

    // Detectar condição de reset decádico (Q3 e Q1 ativos: 1010)
    assign reset_dec = (q_reg == 4'b1010);

    // Flip-flop JK - Comportamento de toggle para cada bit
    always @(posedge clk or posedge reset) begin
        if (reset || reset_dec) begin
            q_reg <= 4'b0000; // Reset para 0
        end else begin
            q_reg[0] <= ~q_reg[0]; // Toggle do bit menos significativo
        end
    end

    always @(negedge q_reg[0] or posedge reset) begin
        if (reset || reset_dec)
            q_reg[1] <= 1'b0;
        else
            q_reg[1] <= ~q_reg[1]; // Toggle do segundo bit
    end

    always @(negedge q_reg[1] or posedge reset) begin
        if (reset || reset_dec)
            q_reg[2] <= 1'b0;
        else
            q_reg[2] <= ~q_reg[2]; // Toggle do terceiro bit
    end

    always @(negedge q_reg[2] or posedge reset) begin
        if (reset || reset_dec)
            q_reg[3] <= 1'b0;
        else
            q_reg[3] <= ~q_reg[3]; // Toggle do quarto bit
    end

    // Conectar saída
    assign q = q_reg;

endmodule
