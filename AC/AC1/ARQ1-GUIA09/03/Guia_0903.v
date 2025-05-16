//Guia_0903.v

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
// -- Pulse generator (1/3 frequency)
// ---------------------------


module pulse (output reg signal, input clock);
    reg [1:0] counter;        // Contador para dividir a frequência do clock

    initial begin
        counter = 2'b00;      // Inicializa o contador em 0
        signal = 1'b0;        // Inicializa o sinal em 0
    end

    always @(posedge clock) begin
        if (counter == 2'b10) begin // Verifica se atingiu a terceira contagem
            signal = ~signal;       // Alterna o sinal do pulso
            counter = 2'b00;        // Reseta o contador
        end else begin
            counter = counter + 1;  // Incrementa o contador
        end
    end
endmodule // pulse

module Guia_0903;
    wire clock;               // Sinal de clock gerado pelo módulo clock
    wire pulse_signal;        // Sinal do gerador de pulso

    clock CLK (clock);        // Instância do módulo clock
    pulse PLS (pulse_signal, clock); // Instância do módulo pulse

    initial begin
        $dumpfile("Guia_0903.vcd"); // Arquivo de saída para o GTKWave
        $dumpvars(1, clock, pulse_signal); // Habilita os sinais para captura
        #480 $finish;            // Finaliza a simulação após 480 unidades de tempo
    end
endmodule // Guia_0903

//iverilog -o Guia_0903 Guia_0903.v
//vvp Guia_0903
//gtkwave Guia_0903.vcd