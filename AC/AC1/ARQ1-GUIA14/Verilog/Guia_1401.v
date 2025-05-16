//Guia_1401.v

module registrador_deslocamento (
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
        q[5:1] <= q[4:0]; // Desloca para a esquerda
    end else begin
        q <= {q[4:0], 1'b0}; // Desloca para a esquerda com 0
    end
end

endmodule
