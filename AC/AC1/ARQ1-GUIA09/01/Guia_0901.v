//Guia_0901.v

// ---------------------------
// -- test clock generator (2)
// ---------------------------

module clock (output clk);
    reg clk;
    initial
    begin
        clk = 1'b0;         // Inicializa o clock em nível lógico baixo
    end
    always
    begin
        #12 clk = ~clk;     // Inverte o estado do clock a cada 12 unidades de tempo
    end
endmodule // clock

module pulse (output signal, input clock);
    reg signal;
    always @(clock)
    begin
        signal = 1'b1;      // Pulso em nível alto
        #3 signal = 1'b0;   // Pulso em nível baixo após 3 unidades de tempo
        #3 signal = 1'b1;   // Pulso em nível alto novamente
        #3 signal = 1'b0;   // Finaliza o pulso após 3 unidades de tempo
    end
endmodule // pulse

module trigger (output signal, input on, input clock);
    reg signal;
    always @(posedge clock & on) // Gera gatilho apenas se 'on' estiver ativo
    begin
        #60 signal = 1'b1;   // Ativa o gatilho após 60 unidades de tempo
        #60 signal = 1'b0;   // Desativa o gatilho após mais 60 unidades de tempo
    end
endmodule // trigger

module Guia_0901;
    wire clk;                  // Sinal de clock gerado pelo módulo clock
    wire p_signal;             // Sinal gerado pelo módulo pulse
    wire t_signal;             // Sinal gerado pelo módulo trigger
    reg t_on;                  // Controle para ativar o gatilho

    // Instâncias dos módulos
    clock CLK1 (clk);          // Gera o clock
    pulse PULSE1 (p_signal, clk); // Gera os pulsos
    trigger TRIGGER1 (t_signal, t_on, clk); // Gera os gatilhos

    initial begin
        // Configurações para simulação
        $dumpfile("Guia_0901.vcd"); // Arquivo de saída para o GTKWave
        $dumpvars;

        // Simulação do gatilho
        t_on = 1'b0;           // Inicialmente, o gatilho está desativado
        #30 t_on = 1'b1;       // Ativa o gatilho após 30 unidades de tempo
        #120 t_on = 1'b0;      // Desativa o gatilho após 120 unidades de tempo
        #180 $finish;          // Finaliza a simulação
    end
endmodule // Guia_0901

//iverilog -o Guia_0901 Guia_0901.v
//vvp Guia_0901
//gtkwave Guia_0901.vcd

