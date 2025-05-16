//RAM_8x8.v

module RAM_8x8 (
    input wire CLK,
    input wire R_W,              // Read/Write: 1 para escrita, 0 para leitura
    input wire [2:0] ADDR,       // Endereço (3 bits)
    input wire CLR,              // Clear
    input wire [7:0] DATA_IN,    // Dados de entrada (8 bits)
    output reg [7:0] DATA_OUT    // Dados de saída (8 bits)
);
    // Sinais intermediários para RAMs
    wire [7:0] RAM_0_DATA_OUT;
    wire [7:0] RAM_1_DATA_OUT;

    // Instâncias de RAM 4x8
    RAM_4x8 RAM_0 (
        .CLK(CLK),
        .R_W(R_W),
        .ADDR(ADDR[1:0]),         // Menor parte do endereço
        .CLR(CLR),
        .DATA_IN(DATA_IN),
        .DATA_OUT(RAM_0_DATA_OUT)
    );

    RAM_4x8 RAM_1 (
        .CLK(CLK),
        .R_W(R_W),
        .ADDR(ADDR[1:0]),         // Menor parte do endereço
        .CLR(CLR),
        .DATA_IN(DATA_IN),
        .DATA_OUT(RAM_1_DATA_OUT)
    );

    // Seleção da RAM ativa
    always @(*) begin
        if (ADDR[2] == 1'b0)
            DATA_OUT = RAM_0_DATA_OUT;  // Seleciona saída da RAM 0
        else
            DATA_OUT = RAM_1_DATA_OUT;  // Seleciona saída da RAM 1
    end
endmodule
