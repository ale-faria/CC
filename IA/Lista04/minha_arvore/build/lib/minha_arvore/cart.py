# cart.py

from collections import Counter
from .no import NoArvore
from .funcoes import melhor_divisao_cart, indice_gini
import pandas as pd

def cart(dados, atributos, alvo, max_depth=10, min_samples_leaf=1, min_impurity_decrease=0.001, depth=0):
    classes = Counter(dados[alvo])
    gini_atual = indice_gini(dados[alvo]) # Gini do nó atual

    if (len(classes) == 1 or not atributos or len(dados) < min_samples_leaf or depth >= max_depth):
        return NoArvore(resultado=classes.most_common(1)[0][0] if classes else 0)

    # Agora a função retorna 3 valores
    atributo, criterio, gini_da_divisao = melhor_divisao_cart(dados, atributos, alvo, indice_gini)
    
    # --- NOVA CONDIÇÃO DE PARADA (PODA) ---
    # Se a divisão não melhora a pureza o suficiente, cria uma folha.
    if atributo is None or (gini_atual - gini_da_divisao) < min_impurity_decrease:
        return NoArvore(resultado=classes.most_common(1)[0][0])

    raiz = NoArvore(atributo=atributo, criterio_divisao=criterio)
    
    # Prepara a lista de atributos para a recursão (correção anterior mantida)
    novos_atributos = list(atributos)
    if isinstance(criterio, set):
        novos_atributos.remove(atributo)
    
    # O resto da função continua igual...
    if isinstance(criterio, set):
        grupo1 = dados[dados[atributo].isin(criterio)]
        grupo2 = dados[~dados[atributo].isin(criterio)]
        chave1, chave2 = "in", "not in"
    else:
        grupo1 = dados[dados[atributo] <= criterio]
        grupo2 = dados[dados[atributo] > criterio]
        chave1, chave2 = "esquerda", "direita"

    raiz.filhos[chave1] = cart(grupo1, novos_atributos, alvo, max_depth, min_samples_leaf, min_impurity_decrease, depth + 1)
    raiz.filhos[chave2] = cart(grupo2, novos_atributos, alvo, max_depth, min_samples_leaf, min_impurity_decrease, depth + 1)

    return raiz