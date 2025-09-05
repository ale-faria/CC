import pandas as pd

# --- ETAPA 1: CARREGAR OS DADOS BRUTOS ---
try:
    df_train_raw = pd.read_csv("train.csv")
    df_test_raw = pd.read_csv("test.csv")
    print("Dados brutos carregados com sucesso.")
except FileNotFoundError:
    print("Erro: Verifique se 'train.csv' e 'test.csv' estão no diretório correto.")
    exit()


# --- ETAPA 2: LIMPEZA E IMPUTAÇÃO DE DADOS AUSENTES ---

# Guardar os IDs dos passageiros do teste para uma possível submissão futura
passenger_ids_test = df_test_raw['PassengerId']

# Remover colunas irrelevantes
cols_to_drop = ['PassengerId', 'Name', 'Ticket', 'Cabin']
df_train_processed = df_train_raw.drop(columns=cols_to_drop)
df_test_processed = df_test_raw.drop(columns=cols_to_drop)
print(f"Colunas removidas: {cols_to_drop}")

# Imputação para colunas numéricas (usando a média do CONJUNTO DE TREINO)
age_mean = df_train_processed['Age'].mean()
df_train_processed['Age'].fillna(age_mean, inplace=True)
df_test_processed['Age'].fillna(age_mean, inplace=True)
print(f"Valores ausentes em 'Age' preenchidos com a média: {age_mean:.2f}")

fare_mean = df_train_processed['Fare'].mean()
df_test_processed['Fare'].fillna(fare_mean, inplace=True)
print(f"Valores ausentes em 'Fare' (no teste) preenchidos com a média: {fare_mean:.2f}")

# Imputação para colunas categóricas (usando a moda do CONJUNTO DE TREINO)
embarked_mode = df_train_processed['Embarked'].mode()[0]
df_train_processed['Embarked'].fillna(embarked_mode, inplace=True)
print(f"Valores ausentes em 'Embarked' preenchidos com a moda: '{embarked_mode}'")


# --- ETAPA 3: TRANSFORMAÇÃO DE VARIÁVEIS (ONE-HOT ENCODING) ---

# Separar a variável alvo (Survived) do restante do conjunto de treino
X = df_train_processed.drop('Survived', axis=1)
y = df_train_processed['Survived']

# Unir os dataframes de treino (sem o alvo) e teste para garantir consistência
combined_df = pd.concat([X, df_test_processed], axis=0)

# Aplicar One-Hot Encoding em colunas categóricas
categorical_cols = ['Sex', 'Embarked', 'Pclass']
combined_df_encoded = pd.get_dummies(combined_df, columns=categorical_cols, drop_first=True)
print("Colunas categóricas transformadas em numéricas.")

# Separar novamente em treino e teste
X_train_final = combined_df_encoded.iloc[:len(df_train_raw)]
X_test_final = combined_df_encoded.iloc[len(df_train_raw):]


# --- ETAPA 4: SALVAR OS DADOS FINAIS ---

X_train_final.to_csv('train_final.csv', index=False)
y.to_csv('train_target.csv', index=False)
X_test_final.to_csv('test_final.csv', index=False)

print("\nProcessamento concluído!")
print("Arquivos finais prontos para o modelo foram salvos:")
print("- 'train_final.csv' (dados de treino)")
print("- 'train_target.csv' (alvo do treino)")
print("- 'test_final.csv' (dados de teste)")