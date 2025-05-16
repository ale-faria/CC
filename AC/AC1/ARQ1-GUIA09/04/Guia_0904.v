//Guia_0904.v

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
// -- Pulse generator (4x frequency)
// ---------------------------

module pulse (output reg signal, input clock);
    reg [2:0] counter;        // Contador de 3 bits para dividir o clock

    initial begin
        counter = 3'b000;     // Inicializa o contador em 0
        signal = 1'b0;        // Inicializa o sinal do pulso em 0
    end

    always @(posedge clock) begin
        if (counter == 3'b001) begin // Muda o estado do sinal a cada 2 ciclos do clock
            signal = ~signal;       // Alterna o estado do pulso
            counter = 3'b000;       // Reseta o contador
        end else begin
            counter = counter + 1;  // Incrementa o contador
        end
    end
endmodule // pulse

module Guia_0904;
    wire clock;               // Sinal de clock gerado pelo módulo clock
    wire pulse_signal;        // Sinal do gerador de pulso

    clock CLK (clock);        // Instância do módulo clock
    pulse PLS (pulse_signal, clock); // Instância do módulo pulse

    initial begin
        $dumpfile("Guia_0904.vcd"); // Arquivo de saída para o GTKWave
        $dumpvars(1, clock, pulse_signal); // Habilita os sinais para captura
        #240 $finish;            // Finaliza a simulação após 240 unidades de tempo
    end
endmodule // Guia_0904

//iverilog -o Guia_0904 Guia_0904.v 
//vvp Guia_0904
//gtkwave Guia_0904.vcd