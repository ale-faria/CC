//RAM_1x8.v

module RAM_1x8 (
    input wire CLK,
    input wire R_W,              // Read/Write: 1 para escrita, 0 para leitura
    input wire ADDR,             // Endereço (1 bit)
    input wire CLR,              // Clear
    input wire [7:0] DATA_IN,    // Dados de entrada (8 bits)
    output reg [7:0] DATA_OUT    // Dados de saída (8 bits)
);
    // Instância de duas RAMs 1x4
    reg [3:0] RAM_L;             // RAM inferior (4 bits)
    reg [3:0] RAM_H;             // RAM superior (4 bits)

    // Escrita na borda de subida do clock
    always @(posedge CLK or posedge CLR) begin
        if (CLR) begin
            RAM_L <= 4'b0;
            RAM_H <= 4'b0;
        end else if (R_W && ADDR) begin
            RAM_L <= DATA_IN[3:0];  // Escreve nos 4 bits menos significativos
            RAM_H <= DATA_IN[7:4];  // Escreve nos 4 bits mais significativos
        end
    end

    // Leitura na borda de descida do clock
    always @(negedge CLK) begin
        if (!R_W && ADDR) begin
            DATA_OUT[3:0] <= RAM_L;  // Lê os 4 bits menos significativos
            DATA_OUT[7:4] <= RAM_H;  // Lê os 4 bits mais significativos
        end else begin
            DATA_OUT <= 8'bx;        // Saída indefinida se endereço não habilitado
        end
    end
endmodule
