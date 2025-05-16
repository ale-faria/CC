//Guia_1302.v

module contador_crescente (
    input clk,        // Clock externo
    input reset,      // Reset assíncrono
    output [4:0] q    // Saída de 5 bits
);

    wire [4:0] clk_ff; // Sinais de clock para os flip-flops
    reg [4:0] q_reg;   // Registradores para armazenar os estados dos flip-flops

    // Inicialização do contador
    initial begin
        q_reg = 5'b00000; // Estado inicial
    end

    // Gerar clocks para os flip-flops
    assign clk_ff[0] = clk;          // Flip-flop menos significativo usa o clock externo
    assign clk_ff[1] = q_reg[0];    // O próximo flip-flop usa Q do anterior
    assign clk_ff[2] = q_reg[1];
    assign clk_ff[3] = q_reg[2];
    assign clk_ff[4] = q_reg[3];

    // Flip-flops JK com lógica de toggle
    always @(posedge clk_ff[0] or posedge reset) begin
        if (reset) q_reg[0] <= 1'b0; // Reset para 0
        else       q_reg[0] <= ~q_reg[0]; // Toggle
    end

    always @(posedge clk_ff[1] or posedge reset) begin
        if (reset) q_reg[1] <= 1'b0;
        else       q_reg[1] <= ~q_reg[1];
    end

    always @(posedge clk_ff[2] or posedge reset) begin
        if (reset) q_reg[2] <= 1'b0;
        else       q_reg[2] <= ~q_reg[2];
    end

    always @(posedge clk_ff[3] or posedge reset) begin
        if (reset) q_reg[3] <= 1'b0;
        else       q_reg[3] <= ~q_reg[3];
    end

    always @(posedge clk_ff[4] or posedge reset) begin
        if (reset) q_reg[4] <= 1'b0;
        else       q_reg[4] <= ~q_reg[4];
    end

    // Conectar as saídas
    assign q = q_reg;

endmodule
