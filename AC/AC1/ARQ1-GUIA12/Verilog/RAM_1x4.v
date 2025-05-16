//RAM_1x4.v

module RAM_1x4 (
    input wire CLK,
    input wire R_W,        // Read/Write: 1 para escrita, 0 para leitura
    input wire ADDR,       // Endereço (1 bit)
    input wire CLR,        // Clear
    input wire [3:0] input_data, // Dados de entrada
    output reg [3:0] output_data // Dados de saída
);
    reg [3:0] memory;      // Memória de 4 bits

    always @(posedge CLK or posedge CLR) begin
        if (CLR) 
            memory <= 4'b0; // Limpa a memória quando CLR for 1
        else if (R_W && ADDR)
            memory <= input_data; // Escrita na borda de subida
    end

    always @(negedge CLK) begin
        if (!R_W && ADDR)
            output_data <= memory; // Leitura na borda de descida
        else
            output_data <= 4'bx; // Saída indefinida se endereço não habilitado
    end
endmodule
