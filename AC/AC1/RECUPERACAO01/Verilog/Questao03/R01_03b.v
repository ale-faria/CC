//R01_03b.v
//(x'.y)'.(x'.y')'

module expression(
  input wire x,
  input wire y,
  output wire z
);
  wire not_y;
  wire term1;
  wire term2;

  // Calcular ~y
  not (not_y, y);

  // Calcular os termos (x + ~y) e (x + y)
  or (term1, x, not_y);
  or (term2, x, y);

  // Calcular a saída final z = term1 & term2
  and (z, term1, term2);

endmodule
