# funcoes.py (versão atualizada)

import math
from collections import Counter
import numpy as np
import pandas as pd
from itertools import chain, combinations # Importa ferramentas para combinações

# As funções entropia, indice_gini, ganho_informacao e gain_ratio continuam iguais...
def entropia(coluna):
    contador = Counter(coluna)
    total = len(coluna)
    return -sum((qtd/total) * math.log2(qtd/total) for qtd in contador.values() if qtd > 0)

#def indice_gini(coluna):
 #   contador = Counter(coluna)
 #   total = len(coluna)
#    return 1 - sum((qtd/total) ** 2 for qtd in contador.values())

def ganho_informacao(dados, atributo, alvo, entropia_func):
    entropia_total = entropia_func(dados[alvo])
    valores = dados[atributo].unique()
    entropia_cond = 0
    for valor in valores:
        subset = dados[dados[atributo] == valor]
        peso = len(subset) / len(dados)
        entropia_cond += peso * entropia_func(subset[alvo])
    return entropia_total - entropia_cond

def gain_ratio(dados, atributo, alvo, ganho_informacao_func):
    from .funcoes import entropia
    ganho = ganho_informacao_func(dados, atributo, alvo, entropia)
    valores = dados[atributo].unique()
    split_info = 0
    for valor in valores:
        subconjunto = dados[dados[atributo] == valor]
        proporcao = len(subconjunto) / len(dados)
        split_info -= proporcao * np.log2(proporcao) if proporcao > 0 else 0
    return ganho / split_info if split_info != 0 else 0

def indice_gini(coluna):
    contador = Counter(coluna)
    total = len(coluna)
    if total == 0: return 0
    return 1 - sum((qtd/total) ** 2 for qtd in contador.values())

def melhor_divisao_cart(dados, atributos, alvo, indice_gini_func):
    """
    Versão simplificada que assume que todos os atributos são numéricos.
    Retorna: (melhor_atributo, melhor_limiar, melhor_gini_da_divisao)
    """
    melhor_atributo, melhor_limiar, melhor_gini = None, None, float("inf")

    for atributo in atributos:
        valores = sorted(dados[atributo].unique())
        for i in range(1, len(valores)):
            limiar = (valores[i-1] + valores[i]) / 2
            esquerda = dados[dados[atributo] <= limiar]
            direita = dados[dados[atributo] > limiar]
            
            if esquerda.empty or direita.empty:
                continue
            
            gini_ponderado = ((len(esquerda) / len(dados)) * indice_gini_func(esquerda[alvo]) +
                              (len(direita) / len(dados)) * indice_gini_func(direita[alvo]))

            if gini_ponderado < melhor_gini:
                melhor_gini = gini_ponderado
                melhor_atributo = atributo
                melhor_limiar = limiar
            
    return melhor_atributo, melhor_limiar, melhor_gini