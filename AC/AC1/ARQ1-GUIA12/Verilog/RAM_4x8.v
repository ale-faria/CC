//RAM_4x8.v

module RAM_4x8 (
    input wire CLK,
    input wire R_W,              // Read/Write: 1 para escrita, 0 para leitura
    input wire [1:0] ADDR,       // Endereço (2 bits)
    input wire CLR,              // Clear
    input wire [7:0] DATA_IN,    // Dados de entrada (8 bits)
    output reg [7:0] DATA_OUT    // Dados de saída (8 bits)
);
    // Instâncias de RAM 2x8
    reg [7:0] RAM_0_DATA_OUT;
    reg [7:0] RAM_1_DATA_OUT;

    // Instâncias de RAM 2x8
    RAM_2x8 RAM_0 (
        .CLK(CLK),
        .R_W(R_W),
        .ADDR(ADDR[0]),          // Menor bit do endereço
        .CLR(CLR),
        .DATA_IN(DATA_IN),
        .DATA_OUT(RAM_0_DATA_OUT)
    );

    RAM_2x8 RAM_1 (
        .CLK(CLK),
        .R_W(R_W),
        .ADDR(ADDR[0]),          // Menor bit do endereço
        .CLR(CLR),
        .DATA_IN(DATA_IN),
        .DATA_OUT(RAM_1_DATA_OUT)
    );

    // Controle de saída e seleção de RAM
    always @(*) begin
        if (ADDR[1] == 1'b0)
            DATA_OUT = RAM_0_DATA_OUT;  // Seleciona saída da RAM 0
        else
            DATA_OUT = RAM_1_DATA_OUT;  // Seleciona saída da RAM 1
    end
endmodule
