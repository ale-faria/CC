import pandas as pd
from minha_arvore import id3, c45, cart, imprimir_arvore

# Carregar dataset
dados = pd.read_csv("play_tennis.csv")

# Definir atributos preditores e alvo
atributos = list(dados.columns[1:-1])  # Começa do índice 1 (segunda coluna) e vai até o final, exceto o último
alvo = dados.columns[-1]              # última coluna é o alvo

print("=== ID3 ===")
arvore_id3 = id3(dados, atributos, alvo)
imprimir_arvore(arvore_id3)

print("\n=== C4.5 ===")
arvore_c45 = c45(dados, atributos, alvo)
imprimir_arvore(arvore_c45)

print("\n=== CART ===")
arvore_cart = cart(dados, atributos, alvo)
imprimir_arvore(arvore_cart)
