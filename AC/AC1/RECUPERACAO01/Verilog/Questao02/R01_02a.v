//R01_02a.v
//mux (a, not(a), c)

module mux(
  input wire a,
  input wire c,
  output wire y
);
  wire not_a;

  // Calcular not(a)
  not (not_a, a);

  // Multiplexador usando c como seleção
  assign y = (c) ? not_a : a;

endmodule

