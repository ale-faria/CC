//R01_03a.v
// (~a|b) & (b|~c)

module expression(
  input wire a,
  input wire b,
  input wire c,
  output wire y
);
  wire not_a;
  wire not_c;
  wire term1;
  wire term2;

  // Calcular ~a e ~c
  not (not_a, a);
  not (not_c, c);

  // Calcular (not_a | b) e (b | not_c)
  or (term1, not_a, b);
  or (term2, b, not_c);

  // Calcular y = term1 & term2
  and (y, term1, term2);

endmodule
