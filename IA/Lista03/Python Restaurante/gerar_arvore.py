# ---------------------------------------------------------------------------
# 1. IMPORTAÇÃO DE BIBLIOTECAS
# ---------------------------------------------------------------------------
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import accuracy_score, confusion_matrix, classification_report
from yellowbrick.classifier import ConfusionMatrix
from sklearn import tree
import pickle

print("Bibliotecas importadas com sucesso.")

# ---------------------------------------------------------------------------
# 2. CARREGANDO OS DADOS DO ARQUIVO .pkl
# ---------------------------------------------------------------------------
try:
    with open('restaurante.pkl', 'rb') as f:
      X_treino, X_teste, y_treino, y_teste = pickle.load(f)
    print("\nDados de treino e teste carregados.")
except FileNotFoundError:
    print("\nERRO: O arquivo 'restaurante.pkl' não foi encontrado.")
    print("Por favor, execute o script 'processamento_restaurante.py' primeiro.")
    exit()

# ---------------------------------------------------------------------------
# 3. TREINAMENTO DO MODELO DE ÁRVORE DE DECISÃO
# ---------------------------------------------------------------------------
modelo = DecisionTreeClassifier(criterion='entropy', random_state=42)
modelo.fit(X_treino, y_treino)
print("Modelo de árvore de decisão treinado.")

# ---------------------------------------------------------------------------
# 4. AVALIAÇÃO DO MODELO
# ---------------------------------------------------------------------------
previsoes = modelo.predict(X_teste)
print("\n--- Vamos testar o modelo? ---")
print("Previsões:", previsoes)
print("\n--- Será se o modelo acertou? ---")
print("Valores Reais (y_teste):\n", y_teste.values)

acuracia = accuracy_score(y_teste, previsoes)
matriz_confusao = confusion_matrix(y_teste, previsoes)
relatorio_classificacao = classification_report(y_teste, previsoes)

print("\n--- Métricas de Avaliação ---")
print(f"Acurácia: {acuracia:.4f}")
print("\nMatriz de Confusão:\n", matriz_confusao)
print("\nRelatório de Classificação:\n", relatorio_classificacao)

# ---------------------------------------------------------------------------
# 5. VISUALIZAÇÃO DOS RESULTADOS (GRÁFICOS)
# ---------------------------------------------------------------------------
# 5.1. Matriz de Confusão com Yellowbrick
print("\nGerando gráfico da Matriz de Confusão (abrirá em uma nova janela)...")
cm = ConfusionMatrix(modelo, classes=['Nao', 'Sim'])
cm.fit(X_treino, y_treino)
cm.score(X_teste, y_teste)
cm.show()

# 5.2. Visualização da Árvore de Decisão (VERSÃO MELHORADA)
print("Gerando gráfico da Árvore de Decisão...")
nomes_previsores = X_treino.columns
figura, eixos = plt.subplots(nrows=1, ncols=1, figsize=(20, 18))
tree.plot_tree(
    modelo,
    feature_names=nomes_previsores,
    class_names=modelo.classes_,
    filled=True,
    fontsize=10
)
plt.savefig('arvore_decisao.png', dpi=300)
print("A imagem da árvore foi salva como 'arvore_decisao.png'.")
plt.show()

print("\nProcesso finalizado. As janelas com os gráficos podem ser fechadas.")