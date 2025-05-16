//Guia_1101.v

// --------------
// --- Moore FSM
// --------------
`define found 1
`define notfound 0

module guia_1101 (y, x, clk, reset);
  output reg y;
  input x, clk, reset;

  // Identificadores de estado
  parameter start = 3'b000,
            id1   = 3'b001,
            id10  = 3'b010,
            id100 = 3'b011,
            id1001 = 3'b100;

  reg [2:0] E1, E2; // Estado atual e próximo estado

  // Lógica de transição de estados
  always @(x or E1) begin
    case (E1)
      start:  E2 = (x) ? id1 : start;
      id1:    E2 = (x) ? start : id10;
      id10:   E2 = (x) ? start : id100;
      id100:  E2 = (x) ? id1001 : start;
      id1001: E2 = id1001; // Estado final
      default: E2 = 3'bxxx;
    endcase
  end

  // Atualização do estado
  always @(posedge clk or posedge reset) begin
    if (reset)
      E1 <= start;
    else
      E1 <= E2;
  end

  // Lógica de saída
  always @(E1) begin
    y = (E1 == id1001) ? 1 : 0;
  end
endmodule
