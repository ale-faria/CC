import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.cluster import KMeans, DBSCAN
from sklearn.metrics import silhouette_score
from sklearn.preprocessing import RobustScaler

# Tenta importar o MiniSom (necessário: pip install minisom)
try:
    from minisom import MiniSom
except ImportError:
    print("A biblioteca MiniSom não está instalada. Rode: pip install minisom")
    MiniSom = None

# --- Preparação dos Dados (Reaproveitando o pré-processamento) ---

# IMPORTANTE: Vamos usar uma AMOSTRA para o Agrupamento.
# Rodar DBSCAN e Silhouette em 280k linhas pode travar computadores comuns.
SAMPLE_SIZE = 10000 
X_sample = X_test.sample(n=SAMPLE_SIZE, random_state=42) # Usando o X_test normalizado da Q1

print(f"Rodando algoritmos de agrupamento em uma amostra de {SAMPLE_SIZE} registros.")

# =============================================================================
# 1. K-MEANS
# =============================================================================
print("\n--- 1. K-Means ---")
# O enunciado pede para verificar se existem 2 grupos
kmeans = KMeans(n_clusters=2, random_state=42, n_init=10)
kmeans_labels = kmeans.fit_predict(X_sample)

# Avaliação
sil_kmeans = silhouette_score(X_sample, kmeans_labels)
print(f"K-Means (k=2) - Silhouette Score: {sil_kmeans:.4f}")

# Visualização (usando as duas componentes principais V1 e V2 para plotar)
plt.figure(figsize=(8, 6))
plt.scatter(X_sample['V1'], X_sample['V2'], c=kmeans_labels, cmap='viridis', s=10, alpha=0.5)
plt.title(f'K-Means (k=2) - Silhouette: {sil_kmeans:.2f}')
plt.xlabel('V1')
plt.ylabel('V2')
plt.show()

# =============================================================================
# 2. DBSCAN
# =============================================================================
print("\n--- 2. DBSCAN ---")
# DBSCAN precisa de ajuste fino no 'eps' e 'min_samples'.
# Como os dados são de alta dimensão, o eps precisa ser testado. 
# Valores comuns para dados normalizados variam entre 0.5 e 5.0.
dbscan = DBSCAN(eps=3.0, min_samples=10) # Hiperparâmetros de exemplo
dbscan_labels = dbscan.fit_predict(X_sample)

# O DBSCAN gera labels -1 para ruído (outliers). 
n_clusters_db = len(set(dbscan_labels)) - (1 if -1 in dbscan_labels else 0)
print(f"DBSCAN encontrou {n_clusters_db} grupos.")

if n_clusters_db > 1:
    sil_dbscan = silhouette_score(X_sample, dbscan_labels)
    print(f"DBSCAN - Silhouette Score: {sil_dbscan:.4f}")
    
    plt.figure(figsize=(8, 6))
    # Plotando, destacando ruído em preto
    unique_labels = set(dbscan_labels)
    colors = [plt.cm.Spectral(each) for each in np.linspace(0, 1, len(unique_labels))]
    for k, col in zip(unique_labels, colors):
        if k == -1:
            col = [0, 0, 0, 1] # Preto para ruído

        class_member_mask = (dbscan_labels == k)
        xy = X_sample[class_member_mask]
        plt.plot(xy['V1'], xy['V2'], 'o', markerfacecolor=tuple(col), markeredgecolor='k', markersize=6)
    
    plt.title(f'DBSCAN (eps=3.0) - Grupos: {n_clusters_db}')
    plt.show()
else:
    print("DBSCAN não encontrou grupos suficientes para calcular a silhueta com estes parâmetros.")

# =============================================================================
# 3. SOM (Self-Organizing Maps)
# =============================================================================
print("\n--- 3. Self-Organizing Maps (SOM) ---")

if MiniSom:
    # Configuração do mapa (ex: 10x10 neurônios)
    som_x, som_y = 10, 10
    n_features = X_sample.shape[1]
    
    som = MiniSom(x=som_x, y=som_y, input_len=n_features, sigma=1.0, learning_rate=0.5)
    som.random_weights_init(X_sample.values)
    
    print("Treinando SOM...")
    som.train_random(X_sample.values, 5000) # 5000 iterações
    print("Treinamento concluído.")

    # Para usar métricas de cluster no SOM, geralmente transformamos os neurônios vencedores em clusters
    # ou analisamos o U-Matrix (distância entre neurônios).
    
    plt.figure(figsize=(8, 6))
    plt.pcolor(som.distance_map().T, cmap='bone_r')  # U-Matrix
    plt.colorbar()
    plt.title('SOM - U-Matrix (Distância entre neurônios)')
    plt.show()
    
    print("Nota: O SOM é mais usado para visualização de topologia. A 'silhueta' direta não é métrica padrão sem uma etapa extra de clusterização sobre os pesos do SOM.")