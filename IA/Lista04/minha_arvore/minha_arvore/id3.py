from collections import Counter
from .no import NoArvore
from .funcoes import ganho_informacao, entropia

def id3(dados, atributos, alvo, max_depth=10, min_samples_leaf=1, depth=0):
    """
    Constrói a árvore de decisão ID3 com parâmetros de poda.
    """
    classes = Counter(dados[alvo])
    
    # --- NOVAS CONDIÇÕES DE PARADA (PODA) ---
    if (len(classes) == 1 or 
        not atributos or 
        len(dados) < min_samples_leaf or 
        depth >= max_depth):
        
        # Retorna a classe majoritária se uma condição de parada for atingida
        if not classes: return NoArvore(resultado=0) # Caso de nó vazio
        return NoArvore(resultado=classes.most_common(1)[0][0])

    melhor_atributo = max(atributos, key=lambda att: ganho_informacao(dados, att, alvo, entropia))
    raiz = NoArvore(atributo=melhor_atributo)
    
    novos_atributos = [att for att in atributos if att != melhor_atributo]

    for valor in dados[melhor_atributo].unique():
        subset = dados[dados[melhor_atributo] == valor]
        if subset.empty:
            raiz.filhos[valor] = NoArvore(resultado=classes.most_common(1)[0][0])
        else:
            # Passa os parâmetros e incrementa a profundidade na chamada recursiva
            raiz.filhos[valor] = id3(subset, novos_atributos, alvo, max_depth, min_samples_leaf, depth + 1)

    return raiz