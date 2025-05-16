//Guia_1305.v

module contador_modulo7 (
    input clk,         // Clock externo
    input reset,       // Reset assíncrono
    output [2:0] q     // Saída de 3 bits
);

    reg [2:0] q_reg;   // Registrador para armazenar o estado do contador
    wire toggle_2, toggle_1; // Sinais de habilitação para flip-flops T

    // Inicialização
    initial begin
        q_reg = 3'b000; // Estado inicial
    end

    // Lógica para habilitar o toggle dos flip-flops
    assign toggle_1 = q_reg[0];             // Q_1 alterna quando Q_0 = 1
    assign toggle_2 = q_reg[1] & q_reg[0]; // Q_2 alterna quando Q_1 e Q_0 = 1

    // Contador síncrono com flip-flops tipo T
    always @(posedge clk or posedge reset) begin
        if (reset || q_reg == 3'b111) begin
            q_reg <= 3'b000; // Reinicia quando atinge o estado 7
        end else begin
            q_reg[0] <= ~q_reg[0];                   // Toggle do bit menos significativo
            q_reg[1] <= toggle_1 ? ~q_reg[1] : q_reg[1]; // Toggle do segundo bit
            q_reg[2] <= toggle_2 ? ~q_reg[2] : q_reg[2]; // Toggle do terceiro bit
        end
    end

    // Conectar saída
    assign q = q_reg;

endmodule
