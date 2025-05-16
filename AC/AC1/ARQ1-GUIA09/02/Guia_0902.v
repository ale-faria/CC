//Guia_0902.v

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
// -- Pulse generators with different periods
// ---------------------------
//`include "clock.v"

module pulse1 (output reg signal, input clock);
    always @(posedge clock)
    begin
        signal = 1'b1;       // Pulso em nível alto
        #4 signal = 1'b0;    // Alterna entre 1 e 0 em períodos de 4 unidades
        #4 signal = 1'b1;
        #4 signal = 1'b0;
        #4 signal = 1'b1;
        #4 signal = 1'b0;
    end
endmodule // pulse1

module pulse2 (output reg signal, input clock);
    always @(posedge clock)
    begin
        signal = 1'b1;       // Pulso com duração de 5 unidades em nível alto
        #5 signal = 1'b0;
    end
endmodule // pulse2

module pulse3 (output reg signal, input clock);
    always @(negedge clock)
    begin
        signal = 1'b1;       // Pulso alternando com período de 15 unidades
        #15 signal = 1'b0;
        #15 signal = 1'b1;
    end
endmodule // pulse3

module pulse4 (output reg signal, input clock);
    always @(negedge clock)
    begin
        signal = 1'b1;       // Pulso alternando com períodos de 20 unidades
        #20 signal = 1'b0;
        #20 signal = 1'b1;
        #20 signal = 1'b0;
    end
endmodule // pulse4

module Guia_0902;
    wire clock;               // Sinal de clock gerado
    clock CLK (clock);        // Instância do módulo clock

    wire p1, p2, p3, p4;      // Sinais gerados pelos módulos de pulso
    pulse1 PLS1 (p1, clock);  // Instância de pulse1
    pulse2 PLS2 (p2, clock);  // Instância de pulse2
    pulse3 PLS3 (p3, clock);  // Instância de pulse3
    pulse4 PLS4 (p4, clock);  // Instância de pulse4

    initial begin
        $dumpfile("Guia_0902.vcd"); // Arquivo de saída para simulação
        $dumpvars(1, clock, p1, p2, p3, p4); // Habilita sinais para captura
        #480 $finish;             // Finaliza a simulação após 480 unidades de tempo
    end
endmodule // Guia_0902


//iverilog -o Guia_0902 Guia_0902.v 
//vvp Guia_0902
//gtkwave Guia_0902.vcd