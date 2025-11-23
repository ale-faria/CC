import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler, RobustScaler
from sklearn.impute import SimpleImputer
from imblearn.over_sampling import SMOTE
from collections import Counter

# Configuração de estilo dos gráficos
sns.set(style="whitegrid")

# --- Carregamento da Base de Dados ---
try:
    df = pd.read_csv('creditcard.csv')
    print(f"Base de dados carregada com sucesso! Dimensões: {df.shape}")
except FileNotFoundError:
    print("Erro: Arquivo 'creditcard.csv' não encontrado. Por favor, faça o download no Kaggle.")

# =============================================================================
# 1) Visualização dos dados
# =============================================================================
print("\n--- 1. Visualização dos Dados ---")

# Distribuição da Classe (Target)
plt.figure(figsize=(6, 4))
sns.countplot(x='Class', data=df)
plt.title('Distribuição das Classes (0: Normal, 1: Fraude)')
plt.show()

normal = df['Class'].value_counts()[0]
fraude = df['Class'].value_counts()[1]

print(f"Transações normais: {normal}")
print(f"Transações fraudulentas: {fraude}")

percentual = df['Class'].value_counts(normalize=True) * 100
print(percentual)

# Distribuição do Montante (Amount)
plt.figure(figsize=(10, 4))
sns.histplot(df['Amount'], bins=50, kde=True)
plt.title('Distribuição do Valor das Transações (Amount)')
plt.yscale('log') # Escala logarítmica para visualizar melhor
plt.show()

# Distribuição do Tempo (Time)
plt.figure(figsize=(10, 4))
sns.histplot(df['Time'], bins=50, kde=True, color='green')
plt.title('Distribuição do Tempo das Transações')
plt.show()


# =============================================================================
# 2) Seleção de atributos e Análise de correlação
# =============================================================================
print("\n--- 2. Análise de Correlação ---")

# Matriz de correlação
plt.figure(figsize=(14, 12))
corr = df.corr()
sns.heatmap(corr, cmap='coolwarm_r', annot=False, center=0)
plt.title('Matriz de Correlação (Heatmap)')
plt.show()

# Observação: As variáveis V1-V28 são PCAs, então tendem a não ter correlação entre si.
# Focamos na correlação com a variável 'Class' e 'Amount'.

# =============================================================================
# 3) Detecção e eliminação de redundância e inconsistência
# =============================================================================
print("\n--- 3. Redundância e Inconsistência ---")
dup_count = df.duplicated().sum()
print(f"Número de linhas duplicadas encontradas: {dup_count}")

if dup_count > 0:
    df.drop_duplicates(inplace=True)
    print("Duplicatas removidas.")
print(f"Dimensões atuais: {df.shape}")

# =============================================================================
# 4) Codificação de variáveis
# =============================================================================
print("\n--- 4. Codificação de Variáveis ---")
# Verificando tipos
print(df.dtypes)


# =============================================================================
# 5) Detecção e tratamento de outliers
# =============================================================================
print("\n--- 5. Tratamento de Outliers ---")
# Focaremos na variável 'Amount', pois V1-V28 já são transformadas.
# Usando o método IQR (Intervalo Interquartil)
Q1 = df['Amount'].quantile(0.25)
Q3 = df['Amount'].quantile(0.75)
IQR = Q3 - Q1
lower_bound = Q1 - 1.5 * IQR
upper_bound = Q3 + 1.5 * IQR

outliers = df[(df['Amount'] < lower_bound) | (df['Amount'] > upper_bound)]
print(f"Outliers detectados em 'Amount': {len(outliers)}")

# Tratamento: Remover outliers extremos pode ser perigoso em fraude (pois fraude é outlier),
# mas para o exercício, vamos remover os outliers extremos do 'Amount' para limpar a base.
df_clean = df[~((df['Amount'] < lower_bound) | (df['Amount'] > upper_bound))]
print(f"Base após remoção de outliers em Amount: {df_clean.shape}")

# =============================================================================
# 6) Divisão Treino-Teste (Estratificada)
# =============================================================================
print("\n--- 6. Divisão Treino-Teste ---")
X = df_clean.drop('Class', axis=1)
y = df_clean['Class']

# Stratify é crucial aqui devido ao desbalanceamento severo
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42, stratify=y
)
print(f"Tamanho Treino: {X_train.shape}, Tamanho Teste: {X_test.shape}")

# =============================================================================
# 7) Verificação e tratamento de valores ausentes
# =============================================================================
print("\n--- 7. Valores Ausentes ---")
# Verifica se há nulos
print("Nulos no treino antes:", X_train.isnull().sum().max())

# Tratamento: Inputação pela Mediana (fit no treino, transform no teste)
imputer = SimpleImputer(strategy='median')
X_train = pd.DataFrame(imputer.fit_transform(X_train), columns=X.columns)
X_test = pd.DataFrame(imputer.transform(X_test), columns=X.columns)

# =============================================================================
# 8) Normalização/Padronização
# =============================================================================
print("\n--- 8. Normalização/Padronização ---")
# A variável 'Time' e 'Amount' têm escalas muito diferentes das V1-V28.
# RobustScaler é bom quando há outliers, StandardScaler é padrão. Vamos usar RobustScaler.
scaler = RobustScaler()

X_train = pd.DataFrame(scaler.fit_transform(X_train), columns=X.columns)
X_test = pd.DataFrame(scaler.transform(X_test), columns=X.columns)

print("Dados normalizados (Exemplo das primeiras linhas):")
print(X_train[['Time', 'Amount']].head())

# =============================================================================
# 9) Balanceamento da classe (Somente no Treino)
# =============================================================================
print("\n--- 9. Balanceamento de Classe ---")
print("Contagem de classes antes do SMOTE (Treino):", Counter(y_train))

smote = SMOTE(random_state=42)
X_train_resampled, y_train_resampled = smote.fit_resample(X_train, y_train)

print("Contagem de classes após SMOTE (Treino):", Counter(y_train_resampled))
print("Nota: O conjunto de teste permanece desbalanceado para refletir a realidade.")

print("\n--- Fim do Pré-processamento ---")