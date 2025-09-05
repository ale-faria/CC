import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier, plot_tree
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix
import seaborn as sns
import matplotlib.pyplot as plt

# --- 1. CARREGAR OS DADOS PROCESSADOS ---
try:
    X = pd.read_csv('train_final.csv')
    y = pd.read_csv('train_target.csv').squeeze() # .squeeze() transforma o DataFrame de uma coluna em uma Series
    X_test_final = pd.read_csv('test_final.csv')
    # Carregar o test.csv original para pegar os PassengerIds para o arquivo de submissão
    test_ids = pd.read_csv('test.csv')['PassengerId']
except FileNotFoundError:
    print("Erro: Verifique se os arquivos 'train_final.csv', 'train_target.csv' e 'test_final.csv' existem.")
    exit()

# --- 2. DIVIDIR OS DADOS DE TREINO EM TREINO E VALIDAÇÃO ---
# 80% para treino, 20% para validação
X_train, X_val, y_train, y_val = train_test_split(X, y, test_size=0.2, random_state=42, stratify=y)

print(f"Dados de treino divididos em: {len(X_train)} para treino e {len(X_val)} para validação.\n")

# --- 3. TREINAR O MODELO DE ÁRVORE DE DECISÃO ---
# Instanciar o modelo. max_depth limita a profundidade da árvore para evitar superajuste (overfitting).
# random_state garante que o resultado seja sempre o mesmo.
model = DecisionTreeClassifier(max_depth=5, random_state=42)

# Treinar o modelo com os dados de treino
model.fit(X_train, y_train)
print("Modelo de Árvore de Decisão treinado com sucesso.\n")

# --- 4. AVALIAR O MODELO NO CONJUNTO DE VALIDAÇÃO ---
# Fazer previsões no conjunto de validação
y_pred_val = model.predict(X_val)

# Calcular a acurácia
accuracy = accuracy_score(y_val, y_pred_val)
print("--- Avaliação no Conjunto de Validação ---")
print(f"Acurácia: {accuracy * 100:.2f}%\n")

# Exibir o Relatório de Classificação
print("Relatório de Classificação:")
# 0 = Não Sobreviveu, 1 = Sobreviveu
print(classification_report(y_val, y_pred_val, target_names=['Não Sobreviveu', 'Sobreviveu']))

# Exibir a Matriz de Confusão
print("Matriz de Confusão:")
cm = confusion_matrix(y_val, y_pred_val)
print(cm)

# Plotar a Matriz de Confusão para melhor visualização
plt.figure(figsize=(8, 6))
sns.heatmap(cm, annot=True, fmt='d', cmap='Blues', xticklabels=['Não Sobreviveu', 'Sobreviveu'], yticklabels=['Não Sobreviveu', 'Sobreviveu'])
plt.xlabel('Previsto')
plt.ylabel('Verdadeiro')
plt.title('Matriz de Confusão - Validação')
plt.savefig('confusion_matrix.png')
plt.close()


# ---  GERAR A VISUALIZAÇÃO DA ÁRVORE DE DECISÃO ---

# Nomes das features (colunas) e das classes (alvo)
feature_names = X_train.columns.tolist()
class_names = ['Não Sobreviveu', 'Sobreviveu']

# Criar a figura para o plot. Usamos um tamanho grande para a árvore ser legível.
plt.figure(figsize=(30, 15))

# Usar a função plot_tree para desenhar a árvore
plot_tree(
    model,
    feature_names=feature_names,
    class_names=class_names,
    filled=True,  # Colore os nós para indicar a classe majoritária
    rounded=True, # Usa caixas com cantos arredondados
    fontsize=10   # Tamanho da fonte
)

# Salvar a imagem da árvore em um arquivo
plt.savefig('decision_tree.png')
plt.close()

print("A imagem da Árvore de Decisão foi gerada e salva como 'decision_tree.png'.")


# --- 5. FAZER PREVISÕES FINAIS E CRIAR ARQUIVO DE SUBMISSÃO ---
# Usar o modelo treinado para prever os resultados do conjunto de teste final
final_predictions = model.predict(X_test_final)

# Criar um DataFrame para a submissão
submission_df = pd.DataFrame({
    'PassengerId': test_ids,
    'Survived': final_predictions
})

# Salvar o arquivo de submissão em formato CSV
submission_df.to_csv('submission_decision_tree.csv', index=False)
print("\n--- Previsões Finais ---")
print("Previsões para o conjunto de teste foram realizadas.")
print("Arquivo 'submission_decision_tree.csv' foi gerado com sucesso.")
print("\nCabeçalho do arquivo de submissão:")
print(submission_df.head())