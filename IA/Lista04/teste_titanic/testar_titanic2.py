import pandas as pd
import numpy as np
from graphviz import Digraph
from collections import Counter

# Importe as funções da sua biblioteca
from minha_arvore import id3, c45 

# --- Função de Previsão (igual à anterior) ---
def prever_id3_c45(arvore, amostra):
    no_atual = arvore
    while not no_atual.eh_folha():
        atributo_decisao = no_atual.atributo
        valor_amostra = amostra[atributo_decisao]
        if valor_amostra in no_atual.filhos:
            no_atual = no_atual.filhos[valor_amostra]
        else:
            return None
    return no_atual.resultado

# --- Função de Visualização (igual à anterior) ---
# (Pode ser omitida se você não quiser gerar os gráficos toda vez)
def visualizar_arvore_id3_c45(no, dot=None, parent_name=None, edge_label=""):
    # ... (código da função de visualização)
    if dot is None:
        dot = Digraph(comment='Árvore de Decisão', format='png')
        dot.attr('node', shape='box', style='rounded,filled', fontname='helvetica')
        dot.attr('edge', fontname='helvetica')
        dot.attr(rankdir='TB', size='20,15')
    node_name = str(id(no))
    if no.eh_folha():
        label = f"Sobreviveu: {no.resultado}"
        color = '#c8e6c9' if no.resultado == 1 else '#ffcdd2'
        dot.node(node_name, label, shape='ellipse', fillcolor=color)
    else:
        label = str(no.atributo)
        dot.node(node_name, label, fillcolor='lightblue')
    if parent_name is not None:
        dot.edge(parent_name, node_name, label=str(edge_label))
    if not no.eh_folha():
        for valor_do_galho, filho in no.filhos.items():
            visualizar_arvore_id3_c45(filho, dot, node_name, valor_do_galho)
    return dot

# --- SCRIPT PRINCIPAL ---

# 1. Carregar e Processar Dados
# ... (código de processamento igual ao anterior) ...
url = 'https://raw.githubusercontent.com/datasciencedojo/datasets/master/titanic.csv'
dados = pd.read_csv(url)
colunas_uteis = ['Survived', 'Pclass', 'Sex', 'Age', 'Fare', 'Embarked']
dados_cat = dados[colunas_uteis].copy()
mediana_idade = dados_cat['Age'].median()
dados_cat['Age'].fillna(mediana_idade, inplace=True)
moda_embarque = dados_cat['Embarked'].mode()[0]
dados_cat['Embarked'].fillna(moda_embarque, inplace=True)
dados_cat.dropna(inplace=True)
bins_idade = [0, 12, 18, 60, 100]; labels_idade = ['Criança', 'Jovem', 'Adulto', 'Idoso']
dados_cat['Age'] = pd.cut(dados_cat['Age'], bins=bins_idade, labels=labels_idade, right=False)
bins_tarifa = [-1, 10, 50, 100, 600]; labels_tarifa = ['Baixa', 'Média', 'Alta', 'Muito Alta']
dados_cat['Fare'] = pd.cut(dados_cat['Fare'], bins=bins_tarifa, labels=labels_tarifa)
dados_cat['Pclass'] = dados_cat['Pclass'].astype(str)

# 2. Particionar os Dados
dados_aleatorios = dados_cat.sample(frac=1, random_state=42).reset_index(drop=True)
ponto_corte = int(len(dados_aleatorios) * 0.8)
dados_treino = dados_aleatorios[:ponto_corte]
dados_teste = dados_aleatorios[ponto_corte:]

# 3. Treinar os Modelos
alvo = 'Survived'
atributos = list(dados_treino.columns); atributos.remove(alvo)
resultados = {}

arvore_id3 = id3(dados_treino, atributos, alvo, max_depth=5)
arvore_c45 = c45(dados_treino, atributos, alvo, max_depth=5)

# --- 4. AVALIAÇÃO DETALHADA DOS MODELOS ---
print("\n--- Avaliando os Modelos no Conjunto de Teste ---")

modelos = {'ID3': arvore_id3, 'C4.5': arvore_c45}

for nome_modelo, arvore_modelo in modelos.items():
    # Faz as previsões (removendo casos onde a previsão não foi possível)
    previsoes = np.array([prever_id3_c45(arvore_modelo, linha) for _, linha in dados_teste.iterrows()])
    reais = dados_teste[alvo].values
    
    # Filtra apenas as previsões válidas
    indices_validos = [p is not None for p in previsoes]
    previsoes_validas = previsoes[indices_validos].astype(int)
    reais_validos = reais[indices_validos]

    # Calcular Acurácia
    acertos = np.sum(previsoes_validas == reais_validos)
    acuracia = (acertos / len(reais_validos)) * 100 if len(reais_validos) > 0 else 0
    
    # --- NOVO: Calcular Precisão ---
    # TP: Previu 1, era 1. FP: Previu 1, era 0.
    verdadeiros_positivos = np.sum((previsoes_validas == 1) & (reais_validos == 1))
    falsos_positivos = np.sum((previsoes_validas == 1) & (reais_validos == 0))
    
    # Evita divisão por zero se o modelo nunca previu a classe positiva
    if (verdadeiros_positivos + falsos_positivos) > 0:
        precisao = (verdadeiros_positivos / (verdadeiros_positivos + falsos_positivos)) * 100
    else:
        precisao = 0.0

    resultados[nome_modelo] = {'Acurácia': acuracia, 'Precisão': precisao}


# --- 5. Exibir Resultados Finais ---
print("\n" + "="*45)
print("---   RESULTADO FINAL DA COMPARAÇÃO   ---")
print("="*45)
for modelo, metricas in resultados.items():
    print(f"Modelo: {modelo}")
    for nome_metrica, valor_metrica in metricas.items():
        print(f"  - {nome_metrica}: {valor_metrica:.2f}%")
    print("-" * 20)
print("="*45)