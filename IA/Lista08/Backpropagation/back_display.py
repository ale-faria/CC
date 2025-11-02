import numpy as np
import random

# -------------------------------------------------------------------
# Classe da Rede Neural
# -------------------------------------------------------------------

class RedeNeural:
    def __init__(self, neuronios_entrada, neuronios_oculta, neuronios_saida, taxa_aprendizado):
        self.neuronios_entrada = neuronios_entrada
        self.neuronios_oculta = neuronios_oculta
        self.neuronios_saida = neuronios_saida
        self.taxa_aprendizado = taxa_aprendizado

        # Inicialização dos pesos e biases
        self.pesos_ih = np.random.rand(self.neuronios_oculta, self.neuronios_entrada) - 0.5
        self.pesos_ho = np.random.rand(self.neuronios_saida, self.neuronios_oculta) - 0.5
        self.bias_h = np.random.rand(self.neuronios_oculta, 1) - 0.5
        self.bias_o = np.random.rand(self.neuronios_saida, 1) - 0.5

    def sigmoid(self, x):
        return 1 / (1 + np.exp(-x))

    def sigmoid_derivada(self, x):
        return x * (1 - x)

    def feedforward(self, lista_entrada):
        entradas = np.array(lista_entrada, ndmin=2).T

        # Camada Oculta
        net_oculta = np.dot(self.pesos_ih, entradas) + self.bias_h
        saida_oculta = self.sigmoid(net_oculta)

        # Camada de Saída
        net_saida = np.dot(self.pesos_ho, saida_oculta) + self.bias_o
        saida_final = self.sigmoid(net_saida)

        return saida_oculta, saida_final

    def treinar(self, lista_entrada, lista_target):
        entradas = np.array(lista_entrada, ndmin=2).T
        targets = np.array(lista_target, ndmin=2).T

        # --- 1. Feedforward ---
        saida_oculta, saida_final = self.feedforward(lista_entrada)

        # --- 2. Cálculo do Erro (Backpropagation) ---
        erro_saida = targets - saida_final
        erro_oculta = np.dot(self.pesos_ho.T, erro_saida)

        # --- 3. Cálculo dos Gradientes (Deltas) ---
        gradiente_saida = self.sigmoid_derivada(saida_final)
        delta_saida = erro_saida * gradiente_saida

        gradiente_oculta = self.sigmoid_derivada(saida_oculta)
        delta_oculta = erro_oculta * gradiente_oculta

        # --- 4. Ajuste dos Pesos e Biases ---
        self.pesos_ho += self.taxa_aprendizado * np.dot(delta_saida, saida_oculta.T)
        self.bias_o += self.taxa_aprendizado * delta_saida
        self.pesos_ih += self.taxa_aprendizado * np.dot(delta_oculta, entradas.T)
        self.bias_h += self.taxa_aprendizado * delta_oculta

# -------------------------------------------------------------------
# Dados do Display de 7 Segmentos (Baseado na Tabela do PDF)
# -------------------------------------------------------------------

# Entradas (segmentos a, b, c, d, e, f, g)
entradas_display = [
    [1, 1, 1, 1, 1, 1, 0], # 0
    [0, 1, 1, 0, 0, 0, 0], # 1
    [1, 1, 0, 1, 1, 0, 1], # 2
    [1, 1, 1, 1, 0, 0, 1], # 3
    [0, 1, 1, 0, 0, 1, 1], # 4
    [1, 0, 1, 1, 0, 1, 1], # 5
    [1, 0, 1, 1, 1, 1, 1], # 6
    [1, 1, 1, 0, 0, 0, 0], # 7
    [1, 1, 1, 1, 1, 1, 1], # 8
    [1, 1, 1, 1, 0, 1, 1]  # 9
]

# Saídas (One-Hot com 10 posições)
targets_display = [
    [1, 0, 0, 0, 0, 0, 0, 0, 0, 0], # 0
    [0, 1, 0, 0, 0, 0, 0, 0, 0, 0], # 1
    [0, 0, 1, 0, 0, 0, 0, 0, 0, 0], # 2
    [0, 0, 0, 1, 0, 0, 0, 0, 0, 0], # 3
    [0, 0, 0, 0, 1, 0, 0, 0, 0, 0], # 4
    [0, 0, 0, 0, 0, 1, 0, 0, 0, 0], # 5
    [0, 0, 0, 0, 0, 0, 1, 0, 0, 0], # 6
    [0, 0, 0, 0, 0, 0, 0, 1, 0, 0], # 7
    [0, 0, 0, 0, 0, 0, 0, 0, 1, 0], # 8
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 1]  # 9
]

# Combinar os dados para embaralhar
dados_treino = list(zip(entradas_display, targets_display))

# -------------------------------------------------------------------
# Treinamento da Rede para o Display
# -------------------------------------------------------------------

print("--- Iniciando Treinamento da Rede Neural para o Display 7-Seg ---")

# 1. Definição dos parâmetros da rede (conforme PDF, com correção na saída)
neuronios_entrada = 7
neuronios_oculta = 5
neuronios_saida = 10
taxa_aprendizado = 0.1
epocas = 50000

# 2. Instanciação da Rede Neural
nn_display = RedeNeural(neuronios_entrada, neuronios_oculta, neuronios_saida, taxa_aprendizado)

# 3. Loop de Treinamento
for e in range(epocas):
    random.shuffle(dados_treino)
    
    erro_total = 0
    for entradas, targets in dados_treino:
        nn_display.treinar(entradas, targets)
        # Calcular o erro
        _, previsao = nn_display.feedforward(entradas)
        # Usamos .flatten() para transformar o vetor coluna [[...]] em um vetor linha [...]
        erro_total += np.sum((np.array(targets) - previsao.flatten())**2)

    # Imprimir o MSE a cada 1000 épocas
    if (e + 1) % 1000 == 0:
        mse = erro_total / len(dados_treino)
        print(f"Época {e + 1}/{epocas} - MSE: {mse:.8f}")

print("\n--- Treinamento Concluído ---")

# -------------------------------------------------------------------
# Teste da Rede Pós-Treinamento (Entradas Perfeitas)
# -------------------------------------------------------------------

print("\n--- Testando a Rede Treinada (Entradas Perfeitas) ---")

acertos = 0
for i in range(len(entradas_display)):
    entradas = entradas_display[i]
    target_vetor = targets_display[i]
    
    _, previsao = nn_display.feedforward(entradas)
    
    # Encontrar o dígito previsto (o índice do neurônio com maior ativação)
    digito_previsto = np.argmax(previsao)
    digito_esperado = np.argmax(target_vetor)
    
    status = "CORRETO"
    if digito_previsto != digito_esperado:
        status = "INCORRETO"
    else:
        acertos += 1

    print(f"Entrada: {digito_esperado} -> Previsto: {digito_previsto} ({status})")

print(f"\nTaxa de Acerto (dados perfeitos): {acertos / len(entradas_display) * 100:.2f}%")

# -------------------------------------------------------------------
# Teste de Robustez (Adicionando Ruído)
# -------------------------------------------------------------------

print("\n--- Testando a Rede Treinada (Adicionando Ruído) ---")

def adicionar_ruido(entrada_original, num_bits_ruido=1):
    """
    Inverte aleatoriamente 'num_bits_ruido' bits da entrada.
    Ex: 1 vira 0, ou 0 vira 1.
    """
    entrada_ruidosa = list(entrada_original)
    indices_ruido = random.sample(range(len(entrada_ruidosa)), num_bits_ruido)
    
    for i in indices_ruido:
        entrada_ruidosa[i] = 1 - entrada_ruidosa[i] # Inverte o bit (1->0 ou 0->1)
        
    return entrada_ruidosa

# Testar com ruído
acertos_ruido = 0
num_testes_ruido = 50 # Testar 50 vezes com ruído aleatório

for _ in range(num_testes_ruido):
    # Pega um dígito aleatório para testar
    indice_teste = random.randint(0, len(entradas_display) - 1)
    
    entrada_original = entradas_display[indice_teste]
    digito_esperado = np.argmax(targets_display[indice_teste])
    
    # Adiciona 1 bit de ruído (simulando 1 segmento falhando)
    entrada_ruidosa = adicionar_ruido(entrada_original, num_bits_ruido=1)
    
    # Faz a previsão

    saida_oculta_teste, previsao = nn_display.feedforward(entrada_ruidosa) 
    digito_previsto = np.argmax(previsao)
    
    if digito_previsto == digito_esperado:
        acertos_ruido += 1
    
    if _ < 10: # Imprime os 10 primeiros testes
        print(f"Dígito: {digito_esperado} | Entrada Ruidosa: {entrada_ruidosa} | Previsto: {digito_previsto}")

print(f"\nTaxa de Acerto (com 1 bit de ruído): {acertos_ruido / num_testes_ruido * 100:.2f}%")