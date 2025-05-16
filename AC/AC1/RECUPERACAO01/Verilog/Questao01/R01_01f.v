//R01_01f.v

module pos_nor(
  input A, B, C, D,
  output Y
);
  wire nor_AB, nor_CD, nor_BC, nor_AC, nor_AD;
  
  // Inversões usando NOR
  nor(nor_A, A, A);
  nor(nor_B, B, B);
  nor(nor_C, C, C);
  nor(nor_D, D, D);
  
  // Termos intermediários
  nor(nor_AB, A, B); // ~(A + B)
  nor(nor_CD, nor_C, nor_D); // ~(C' + D')
  nor(nor_BC, B, nor_C); // ~(B + C')
  nor(nor_AC, A, nor_C); // ~(A + C')
  nor(nor_AD, A, nor_D); // ~(A + D')
  
  // Combinação dos termos usando NOR (dupla negação)
  wire result_nor1, result_nor2;
  nor(result_nor1, nor_AB, nor_CD);
  nor(result_nor2, nor_BC, nor_AC, nor_AD);

  // Saída final (dupla negação)
  nor(Y, result_nor1, result_nor2); // Y = (A + B)(C' + D')(B + C')(A + C')(A + D')
endmodule
