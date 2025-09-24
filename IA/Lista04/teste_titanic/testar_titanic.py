import pandas as pd
import numpy as np
from graphviz import Digraph

# Importe as funções da sua biblioteca
from minha_arvore import cart

# --- FUNÇÃO DE PREVISÃO PARA A ÁRVORE CART ---
def prever_cart(arvore, amostra):
    """Navega na árvore CART para prever a classe de uma única amostra."""
    no_atual = arvore
    while not no_atual.eh_folha():
        atributo_decisao = no_atual.atributo
        valor_amostra = amostra[atributo_decisao]
        
        # Como o CART foi treinado com dados numéricos, a lógica é sempre esta
        if valor_amostra <= no_atual.criterio_divisao:
            no_atual = no_atual.filhos["esquerda"]
        else:
            no_atual = no_atual.filhos["direita"]
            
    return no_atual.resultado

# --- Função de Visualização (mantida como antes) ---
def visualizar_arvore(no, dot=None, parent_name=None, edge_label=""):
    if dot is None:
        dot = Digraph(comment='Árvore de Decisão', format='png')
        dot.attr('node', shape='box', style='rounded,filled', fontname='helvetica')
        dot.attr('edge', fontname='helvetica')
        dot.attr(rankdir='TB', size='15,15')
    node_name = str(id(no))
    if no.eh_folha():
        label = f"Sobreviveu: {no.resultado}"
        color = '#c8e6c9' if no.resultado == 1 else '#ffcdd2'
        dot.node(node_name, label, shape='ellipse', fillcolor=color)
    else:
        label = f"{no.atributo}\n<= {no.criterio_divisao:.2f}?"
        dot.node(node_name, label, fillcolor='lightblue')
    if parent_name is not None:
        dot.edge(parent_name, node_name, label=edge_label)
    if not no.eh_folha():
        visualizar_arvore(no.filhos["esquerda"], dot, node_name, "Sim (True)")
        visualizar_arvore(no.filhos["direita"], dot, node_name, "Não (False)")
    return dot

# --- CÓDIGO PRINCIPAL ---

# 1. Carregar e Processar Dados
# ... (código de processamento igual ao anterior) ...
url = 'https://raw.githubusercontent.com/datasciencedojo/datasets/master/titanic.csv'
dados = pd.read_csv(url)
print("--- Processando os Dados ---")
colunas_para_remover = ['PassengerId', 'Name', 'Ticket', 'Cabin']
dados_processados = dados.drop(columns=colunas_para_remover)
dados_processados['Sex'] = dados_processados['Sex'].map({'male': 0, 'female': 1})
mediana_idade = dados_processados['Age'].median()
dados_processados['Age'].fillna(mediana_idade, inplace=True)
moda_embarque = dados_processados['Embarked'].mode()[0]
dados_processados['Embarked'].fillna(moda_embarque, inplace=True)
dados_processados = pd.get_dummies(dados_processados, columns=['Embarked'], drop_first=True)
dados_processados.dropna(inplace=True)

# 2. Particionar os dados
dados_aleatorios = dados_processados.sample(frac=1, random_state=42).reset_index(drop=True)
ponto_corte = int(len(dados_aleatorios) * 0.8)
dados_treino = dados_aleatorios[:ponto_corte]
dados_teste = dados_aleatorios[ponto_corte:]

# 3. Treinar o Modelo
alvo = 'Survived'
atributos = list(dados_treino.columns); atributos.remove(alvo)
print("\n--- Treinando a Árvore de Decisão (CART) ---")
arvore_titanic = cart(dados_treino, atributos, alvo, max_depth=4, min_samples_leaf=10)

# --- NOVA SEÇÃO: 4. AVALIAÇÃO DETALHADA DO MODELO ---
print("\n--- Avaliando o Modelo CART no Conjunto de Teste ---")

# Faz as previsões para todo o conjunto de teste
previsoes = np.array([prever_cart(arvore_titanic, linha) for _, linha in dados_teste.iterrows()])
reais = dados_teste[alvo].values

# Calcular Acurácia
acertos = np.sum(previsoes == reais)
acuracia = (acertos / len(reais)) * 100

# Calcular Precisão
verdadeiros_positivos = np.sum((previsoes == 1) & (reais == 1))
falsos_positivos = np.sum((previsoes == 1) & (reais == 0))
if (verdadeiros_positivos + falsos_positivos) > 0:
    precisao = (verdadeiros_positivos / (verdadeiros_positivos + falsos_positivos)) * 100
else:
    precisao = 0.0

# --- 5. Exibir Resultados Finais ---
print("\n" + "="*35)
print("---   RESULTADO DA AVALIAÇÃO   ---")
print("="*35)
print(f"Acurácia do modelo CART: {acuracia:.2f}%")
print(f"Precisão do modelo CART: {precisao:.2f}%")
print("="*35)


# --- 6. Gerar o Gráfico Final (Opcional) ---
print("\nGerando o gráfico da árvore de decisão...")
grafico_arvore = visualizar_arvore(arvore_titanic)
grafico_arvore.render('arvore_titanic_final', view=False, cleanup=True)
print("Gráfico salvo como 'arvore_titanic_final.png'")