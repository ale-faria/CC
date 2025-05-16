//R01_01e.v

module sop_nand(
  input a, b, c, d,
  output y
);
  wire not_c, not_d, term1, term2, term3;

  nand(not_c, c, c); // not_c = ~c
  nand(not_d, d, d); // not_d = ~d

  nand(term1, a, not_c); // term1 = a & ~c (dupla negação implícita)
  nand(term2_nand, b, not_c); // intermed Nand
  nand(term2, term2_nand, not_d); // term2 = b & ~c & ~d (dupla negação implícita)
  nand(term3, a, b, not_d); // term3 = a & b & ~d (dupla negação implícita)

  // Combinação dos termos usando portas NAND
  wire result_nand;
  nand(result_nand, term1, term2, term3);

  // Saída final (dupla negação)
  nand(y, result_nand, result_nand); // y = (term1 | term2 | term3)
endmodule
