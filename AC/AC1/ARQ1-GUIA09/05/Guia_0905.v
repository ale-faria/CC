//Guia_0905.v

// ---------------------------
// -- Clock generator
// ---------------------------
module clock (output reg clk);
    initial
    begin
        clk = 1'b0;          // Inicializa o clock em nível baixo
    end
    always
    begin
        #12 clk = ~clk;      // Alterna o estado do clock a cada 12 unidades de tempo
    end
endmodule // clock

// ---------------------------
// -- Pulse generator with 4-time-unit mark
// ---------------------------

module pulse (output reg signal, input clock);
    initial begin
        signal = 1'b0; // Inicializa o sinal do pulso em 0
    end

    always @(posedge clock) begin
        signal = 1'b1; // Ativa o sinal na borda de subida
        #4 signal = 1'b0; // Desativa o sinal após 4 unidades de tempo
    end
endmodule // pulse

module Guia_0905;
    wire clock;               // Sinal de clock gerado pelo módulo clock
    wire pulse_signal;        // Sinal do gerador de pulso

    clock CLK (clock);        // Instância do módulo clock
    pulse PLS (pulse_signal, clock); // Instância do módulo pulse

    initial begin
        $dumpfile("Guia_0905.vcd"); // Arquivo de saída para o GTKWave
        $dumpvars(1, clock, pulse_signal); // Habilita os sinais para captura
        #240 $finish;            // Finaliza a simulação após 240 unidades de tempo
    end
endmodule // Guia_0905

//iverilog -o Guia_0905 Guia_0905.v 
//vvp Guia_0905
//gtkwave Guia_0905.vcd