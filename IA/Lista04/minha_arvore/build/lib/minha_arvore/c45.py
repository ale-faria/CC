import pandas as pd
from .funcoes import gain_ratio, ganho_informacao
from .no import NoArvore
from collections import Counter # Adicionar import

def c45(dados, atributos, alvo, max_depth=10, min_samples_leaf=1, depth=0):
    """
    Constrói a árvore de decisão C4.5 com parâmetros de poda.
    """
    classes = Counter(dados[alvo]) # Usar Counter para consistência

    # --- NOVAS CONDIÇÕES DE PARADA (PODA) ---
    if (len(dados[alvo].unique()) == 1 or 
        not atributos or
        len(dados) < min_samples_leaf or
        depth >= max_depth):

        if dados.empty: return NoArvore(resultado=0) # Caso de nó vazio
        return NoArvore(resultado=dados[alvo].mode()[0])

    melhor_atributo = max(atributos, key=lambda att: gain_ratio(dados, att, alvo, ganho_informacao))
    raiz = NoArvore(atributo=melhor_atributo)
    
    novos_atributos = [a for a in atributos if a != melhor_atributo]
    
    for valor in dados[melhor_atributo].unique():
        subconjunto = dados[dados[melhor_atributo] == valor]
        if subconjunto.empty:
            raiz.filhos[valor] = NoArvore(resultado=dados[alvo].mode()[0])
        else:
            # Passa os parâmetros e incrementa a profundidade na chamada recursiva
            raiz.filhos[valor] = c45(subconjunto, novos_atributos, alvo, max_depth, min_samples_leaf, depth + 1)

    return raiz