# -*- coding: utf-8 -*-
"""
Este script é uma adaptação do notebook 'Lendo_e_tratando_arquivo_v2.ipynb'.
Ele realiza a leitura, tratamento e preparação de dados para um modelo de Machine Learning,
com uma codificação manual para a coluna 'Cliente'.
"""

# ---------------------------------------------------------------------------
# 1. IMPORTAÇÃO DE BIBLIOTECAS
# ---------------------------------------------------------------------------
import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
import plotly.express as px
from sklearn.preprocessing import LabelEncoder, OneHotEncoder
from sklearn.compose import ColumnTransformer
from sklearn.model_selection import train_test_split
import pickle

print("Bibliotecas importadas com sucesso.")

# ---------------------------------------------------------------------------
# 2. ABRINDO E EXPLORANDO O ARQUIVO CSV
# ---------------------------------------------------------------------------
try:
    base = pd.read_csv('restaurante.csv', sep=';')
    print("\n--- Dados originais carregados com sucesso ---")
    print(base)
except FileNotFoundError:
    print("\nERRO: O arquivo 'restaurante.csv' não foi encontrado.")
    print("Por favor, coloque o arquivo na mesma pasta que este script.")
    exit()

print("\n--- Primeiras 3 linhas ---")
print(base.head(3))

print("\n--- Últimas 2 linhas ---")
print(base.tail(2))


# ---------------------------------------------------------------------------
# 3. ANÁLISE INICIAL
# ---------------------------------------------------------------------------
Classificacao = base.columns[-1]
print(f"\n--- Contagem de valores para a coluna '{Classificacao}' ---")
print(np.unique(base[Classificacao], return_counts=True))

print("\nGerando gráfico de contagem de classes...")
sns.countplot(x=base[Classificacao])
plt.title('Distribuição da Variável Alvo (Conclusao)')
plt.show()


# ---------------------------------------------------------------------------
# 4. TRATAMENTO DE DADOS CATEGÓRICOS
# ---------------------------------------------------------------------------

# 4.1. Mapeamento Manual: Codificação personalizada para a coluna 'Cliente'
print("\nAplicando Mapeamento Manual para a coluna 'Cliente'...")
mapeamento_cliente = {
    'Nenhum': 0,
    'Algum': 1,
    'Cheio': 2
}
base['Cliente'] = base['Cliente'].map(mapeamento_cliente)
print("\n--- Dados após mapeamento da coluna 'Cliente' ---")
print(base)


# 4.2. LabelEncoder: Transforma as outras categorias em números
print("\nAplicando LabelEncoder para as outras colunas categóricas...")
# A coluna 'Cliente' foi removida desta lista pois já foi tratada
cols_label_encode = ['Alternativo', 'Bar', 'SexSab', 'fome', 'Preco', 'Chuva', 'Res', 'Tempo']
base[cols_label_encode] = base[cols_label_encode].apply(LabelEncoder().fit_transform)
print("\n--- Dados após LabelEncoder ---")
print(base)

# 4.3. OneHotEncoder: Binariza atributos não ordinais (coluna 'Tipo')
print("\nAplicando OneHotEncoder na coluna 'Tipo'...")
cols_onehot_encode = ['Tipo']

onehot = OneHotEncoder(sparse_output=False)
df_onehot = onehot.fit_transform(base[cols_onehot_encode])
nomes_das_colunas = onehot.get_feature_names_out(cols_onehot_encode)
df_onehot = pd.DataFrame(df_onehot, columns=nomes_das_colunas)

base_encoded = pd.concat([df_onehot, base.drop(columns=cols_onehot_encode)], axis=1)

print("\n--- Dados finais após OneHotEncoder (base_encoded) ---")
print(base_encoded)
print("\nFormato do DataFrame final:", base_encoded.shape)


# ---------------------------------------------------------------------------
# 5. DIVISÃO DO DATASET (VARIÁVEIS E CLASSE)
# ---------------------------------------------------------------------------
X_prev = base_encoded.iloc[:, :-1]
y_classe = base_encoded.iloc[:, -1]

print("\n--- Variáveis de previsão (X_prev) ---")
print(X_prev)
print("\n--- Variável alvo (y_classe) ---")
print(y_classe)


# ---------------------------------------------------------------------------
# 6. AMOSTRAGEM (HOLDOUT) - DIVISÃO EM TREINO E TESTE
# ---------------------------------------------------------------------------
X_treino, X_teste, y_treino, y_teste = train_test_split(X_prev, y_classe, test_size=0.20, random_state=42)

print("\n--- Divisão dos dados em treino e teste ---")
print("Tamanho de X_treino:", X_treino.shape)
print("Tamanho de X_teste:", X_teste.shape)
print("Tamanho de y_treino:", y_treino.shape)
print("Tamanho de y_teste:", y_teste.shape)


# ---------------------------------------------------------------------------
# 7. SALVANDO OS DADOS PROCESSADOS
# ---------------------------------------------------------------------------
# O nome do arquivo foi mantido para compatibilidade com o notebook
with open('restaurante.pkl', mode='wb') as f:
    pickle.dump([X_treino, X_teste, y_treino, y_teste], f)

print("\nProcessamento concluído!")
print("Os conjuntos de treino e teste foram salvos no arquivo 'restaurante.pkl' com a nova codificação.")