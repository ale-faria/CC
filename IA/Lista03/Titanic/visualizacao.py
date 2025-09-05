import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Carregar o conjunto de dados de treino
try:
    df_train = pd.read_csv("train.csv")

    # Colunas a serem analisadas
    # Colunas categóricas ou com poucas categorias
    categorical_cols = ['Survived', 'Pclass', 'Sex', 'Embarked', 'SibSp', 'Parch']
    # Colunas numéricas contínuas
    continuous_cols = ['Age', 'Fare']
    # Colunas com muitos valores únicos (alta cardinalidade)
    high_cardinality_cols = ['Cabin', 'Ticket'] # 'Name' e 'PassengerId' são praticamente todos únicos

    # 1. Gráficos para colunas categóricas
    for col in categorical_cols:
        plt.figure(figsize=(10, 6))
        # Usar dropna=False para incluir contagem de nulos (NaN)
        counts = df_train[col].value_counts(dropna=False).sort_index()
        
        # Renomear o índice NaN para melhor visualização
        counts.index = counts.index.map(lambda x: 'Ausente' if pd.isna(x) else x)

        counts.plot(kind='bar', color='skyblue')
        plt.title(f'Distribuição de Valores para a Coluna: {col}', fontsize=16)
        plt.xlabel(col, fontsize=12)
        plt.ylabel('Contagem', fontsize=12)
        plt.xticks(rotation=0)
        plt.grid(axis='y', linestyle='--', alpha=0.7)
        plt.tight_layout()
        plt.savefig(f'distribuicao_{col}.png')
        plt.close()

    # 2. Gráficos para colunas contínuas
    for col in continuous_cols:
        # Histograma da distribuição dos valores existentes
        plt.figure(figsize=(10, 6))
        df_train[col].dropna().plot(kind='hist', bins=30, color='coral', edgecolor='black')
        plt.title(f'Histograma da Distribuição da Coluna: {col}', fontsize=16)
        plt.xlabel(col, fontsize=12)
        plt.ylabel('Frequência', fontsize=12)
        plt.grid(axis='y', linestyle='--', alpha=0.7)
        plt.tight_layout()
        plt.savefig(f'histograma_{col}.png')
        plt.close()

        # Gráfico de barras para valores presentes vs. ausentes
        missing_count = df_train[col].isnull().sum()
        present_count = df_train[col].notnull().sum()
        
        plt.figure(figsize=(8, 5))
        counts = pd.Series([present_count, missing_count], index=['Presente', 'Ausente'])
        counts.plot(kind='bar', color=['lightgreen', 'salmon'])
        plt.title(f'Contagem de Valores Presentes vs. Ausentes para: {col}', fontsize=16)
        plt.ylabel('Contagem', fontsize=12)
        plt.xticks(rotation=0)
        plt.grid(axis='y', linestyle='--', alpha=0.7)
        plt.tight_layout()
        plt.savefig(f'ausentes_{col}.png')
        plt.close()

    # 3. Gráficos para colunas de alta cardinalidade
    for col in high_cardinality_cols:
        unique_count = df_train[col].nunique()
        missing_count = df_train[col].isnull().sum()
        
        plt.figure(figsize=(8, 5))
        counts = pd.Series([unique_count, missing_count], index=['Valores Únicos', 'Valores Ausentes'])
        counts.plot(kind='bar', color=['dodgerblue', 'salmon'])
        plt.title(f'Contagem de Valores Únicos vs. Ausentes para: {col}', fontsize=16)
        plt.ylabel('Contagem', fontsize=12)
        plt.xticks(rotation=0)
        plt.grid(axis='y', linestyle='--', alpha=0.7)
        plt.tight_layout()
        plt.savefig(f'unicos_vs_ausentes_{col}.png')
        plt.close()

    print("Gráficos gerados com sucesso.")

except FileNotFoundError:
    print("Erro: O arquivo train.csv não foi encontrado.")
except Exception as e:
    print(f"Ocorreu um erro ao gerar os gráficos: {e}")