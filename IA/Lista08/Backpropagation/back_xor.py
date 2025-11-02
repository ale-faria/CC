import numpy as np
import random

# -------------------------------------------------------------------
# Classe da Rede Neural
# -------------------------------------------------------------------

class RedeNeural:
    def __init__(self, neuronios_entrada, neuronios_oculta, neuronios_saida, taxa_aprendizado):
        # 1. Inicialização da arquitetura da rede
        self.neuronios_entrada = neuronios_entrada
        self.neuronios_oculta = neuronios_oculta
        self.neuronios_saida = neuronios_saida
        self.taxa_aprendizado = taxa_aprendizado

        # 2. Inicialização dos pesos e biases
        # Pesos entre a camada de entrada e a camada oculta
        # Usamos np.random.rand(linhas, colunas) - 0.5 para valores entre -0.5 e 0.5
        self.pesos_ih = np.random.rand(self.neuronios_oculta, self.neuronios_entrada) - 0.5
        
        # Pesos entre a camada oculta e a camada de saída
        self.pesos_ho = np.random.rand(self.neuronios_saida, self.neuronios_oculta) - 0.5

        # Biases (vieses) para as camadas oculta e de saída
        # Inicializados da mesma forma
        self.bias_h = np.random.rand(self.neuronios_oculta, 1) - 0.5
        self.bias_o = np.random.rand(self.neuronios_saida, 1) - 0.5

    # 3. Função de Ativação: Sigmoide 
    def sigmoid(self, x):
        return 1 / (1 + np.exp(-x))

    # 4. Derivada da Sigmoide (para o backpropagation)
    # Note que x aqui é a *saída* da sigmoide, não a entrada
    def sigmoid_derivada(self, x):
        return x * (1 - x)

    # 5. Feedforward (Propagação Direta)
    # Propaga a entrada pela rede e retorna a previsão
    def feedforward(self, lista_entrada):
        # Converte a lista de entrada em um vetor coluna (matriz 2D)
        entradas = np.array(lista_entrada, ndmin=2).T

        # --- Camada Oculta ---
        # Cálculo da entrada ponderada (net) da camada oculta
        net_oculta = np.dot(self.pesos_ih, entradas) + self.bias_h
        # Aplicação da função de ativação
        saida_oculta = self.sigmoid(net_oculta)

        # --- Camada de Saída ---
        # Cálculo da entrada ponderada (net) da camada de saída
        net_saida = np.dot(self.pesos_ho, saida_oculta) + self.bias_o
        # Aplicação da função de ativação
        saida_final = self.sigmoid(net_saida)

        # Retorna as saídas de ambas as camadas (precisamos da oculta para o backprop)
        return saida_oculta, saida_final

    # 6. Backpropagation e Treinamento
    # Realiza um passo de feedforward, calcula o erro e ajusta os pesos
    def treinar(self, lista_entrada, lista_target):
        # Converte as listas de entrada e alvo em vetores coluna
        entradas = np.array(lista_entrada, ndmin=2).T
        targets = np.array(lista_target, ndmin=2).T

        # --- 1. Feedforward ---
        saida_oculta, saida_final = self.feedforward(lista_entrada)

        # --- 2. Cálculo do Erro (Backpropagation) ---
        
        # Erro na camada de saída (y_k - y_hat_k)
        erro_saida = targets - saida_final
        
        # Erro na camada oculta (propagado para trás)
        # (erro_saida * pesos_ho)
        erro_oculta = np.dot(self.pesos_ho.T, erro_saida)

        # --- 3. Cálculo dos Gradientes (Deltas) ---
        
        # Gradiente (delta) da camada de saída
        # delta_k = (y_k - y_hat_k) * sigmoid'(net_k)
        # Usamos o erro_saida e a derivada da saida_final
        gradiente_saida = self.sigmoid_derivada(saida_final)
        delta_saida = erro_saida * gradiente_saida

        # Gradiente (delta) da camada oculta
        # delta_j = (sum(delta_k * w_jk)) * sigmoid'(net_j)
        # Usamos o erro_oculta e a derivada da saida_oculta
        gradiente_oculta = self.sigmoid_derivada(saida_oculta)
        delta_oculta = erro_oculta * gradiente_oculta

        # --- 4. Ajuste dos Pesos e Biases ---
        
        # Ajuste dos pesos (Oculta -> Saída)
        # w_jk(novo) = w_jk(antigo) + eta * delta_k * a_j
        # (a_j é a saida_oculta)
        self.pesos_ho += self.taxa_aprendizado * np.dot(delta_saida, saida_oculta.T)
        
        # Ajuste do bias (Saída)
        self.bias_o += self.taxa_aprendizado * delta_saida
        
        # Ajuste dos pesos (Entrada -> Oculta)
        # w_ij(novo) = w_ij(antigo) + eta * delta_j * x_i
        # (x_i é a entrada)
        self.pesos_ih += self.taxa_aprendizado * np.dot(delta_oculta, entradas.T)
        
        # Ajuste do bias (Oculta)
        self.bias_h += self.taxa_aprendizado * delta_oculta

# -------------------------------------------------------------------
# Treinamento da Rede para o Problema XOR 
# -------------------------------------------------------------------

print("--- Iniciando Treinamento da Rede Neural para o XOR ---")

# 1. Definição dos parâmetros da rede
neuronios_entrada = 2
neuronios_oculta = 3  # 3 neurônios na camada oculta 
neuronios_saida = 1
taxa_aprendizado = 0.1
epocas = 15000

# 2. Dados de Treinamento (XOR)
# (Entrada, Saída Esperada)
data_xor = [
    ([0, 0], [0]),
    ([0, 1], [1]),
    ([1, 0], [1]),
    ([1, 1], [0])
]

# 3. Instanciação da Rede Neural
nn = RedeNeural(neuronios_entrada, neuronios_oculta, neuronios_saida, taxa_aprendizado)

# 4. Loop de Treinamento
for e in range(epocas):
    # Embaralha os dados a cada época para evitar viés
    random.shuffle(data_xor)
    
    # Treina com cada exemplo
    for entradas, targets in data_xor:
        nn.treinar(entradas, targets)

    # Opcional: Calcular e imprimir o Erro Quadrático Médio (MSE) [cite: 41, 42]
    if (e + 1) % 1000 == 0:
        erro_total = 0
        for entradas, targets in data_xor:
            _, previsao = nn.feedforward(entradas)
            erro_total += np.sum((np.array(targets) - previsao)**2)
        mse = erro_total / len(data_xor)
        print(f"Época {e + 1}/{epocas} - MSE: {mse:.8f}")

print("\n--- Treinamento Concluído ---")

# -------------------------------------------------------------------
# Teste da Rede Pós-Treinamento
# -------------------------------------------------------------------

print("\n--- Testando a Rede Treinada ---")

for entradas, target in data_xor:
    _, previsao = nn.feedforward(entradas)
    
    # O .flatten()[0] apenas formata a saída de [[0.98]] para 0.98
    print(f"Entrada: {entradas} -> Esperado: {target[0]} -> Previsto: {previsao.flatten()[0]:.4f}")