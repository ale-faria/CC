//Guia_1405.v

module twisted_ring_shift_register (
    input wire clk,
    input wire reset,
    input wire LD,
    input wire data_in,
    output reg [5:0] q
);

always @(posedge clk or posedge reset) begin
    if (reset) begin
        q <= 6'b000000; // Inicializa o registrador em 0
    end else if (LD) begin
        q[0] <= data_in; // Carrega o bit no primeiro estágio
        q[5:1] <= q[4:0]; // Desloca os valores para a esquerda
    end else begin
        q <= {q[4:0], ~q[5]}; // Deslocamento circular em anel torcido para a esquerda
    end
end

endmodule
