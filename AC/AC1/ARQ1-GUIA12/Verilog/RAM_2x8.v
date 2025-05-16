//RAM_2x8.v

module RAM_2x8 (
    input wire CLK,
    input wire R_W,              // Read/Write: 1 para escrita, 0 para leitura
    input wire [0:0] ADDR,       // Endereço (1 bit)
    input wire CLR,              // Clear
    input wire [7:0] DATA_IN,    // Dados de entrada (8 bits)
    output reg [7:0] DATA_OUT    // Dados de saída (8 bits)
);
    // Memória RAM 1x8 (2 instâncias)
    reg [7:0] RAM_0;             // RAM para ADDR = 0
    reg [7:0] RAM_1;             // RAM para ADDR = 1

    // Escrita na borda de subida do clock
    always @(posedge CLK or posedge CLR) begin
        if (CLR) begin
            RAM_0 <= 8'b0;       // Limpa a RAM 0
            RAM_1 <= 8'b0;       // Limpa a RAM 1
        end else if (R_W) begin
            if (ADDR == 1'b0)
                RAM_0 <= DATA_IN; // Escrita na RAM 0
            else
                RAM_1 <= DATA_IN; // Escrita na RAM 1
        end
    end

    // Leitura na borda de descida do clock
    always @(negedge CLK) begin
        if (!R_W) begin
            if (ADDR == 1'b0)
                DATA_OUT <= RAM_0; // Leitura da RAM 0
            else
                DATA_OUT <= RAM_1; // Leitura da RAM 1
        end else begin
            DATA_OUT <= 8'bx;      // Saída indefinida se leitura não habilitada
        end
    end
endmodule
