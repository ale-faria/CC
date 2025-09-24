# util.py (versão final corrigida)

def imprimir_arvore(no, espaco=""):
    # Se o nó for uma folha, imprime o resultado e para.
    if no.eh_folha():
        print(espaco + "Resultado:", no.resultado)
        return

    # Caso 1: Nó do CART com divisão categórica (critério é um conjunto)
    if isinstance(no.criterio_divisao, set):
        print(espaco + f"Decisão: {no.atributo} in {no.criterio_divisao}?")
        print(espaco + "--> True:")
        imprimir_arvore(no.filhos["in"], espaco + "  ")
        print(espaco + "--> False:")
        imprimir_arvore(no.filhos["not in"], espaco + "  ")
        
    # Caso 2: Nó do CART com divisão numérica (critério é um número)
    elif isinstance(no.criterio_divisao, (int, float)):
        print(espaco + f"Decisão: {no.atributo} <= {no.criterio_divisao:.2f}?")
        print(espaco + "--> True:")
        imprimir_arvore(no.filhos["esquerda"], espaco + "  ")
        print(espaco + "--> False:")
        imprimir_arvore(no.filhos["direita"], espaco + "  ")
        
    # Caso 3: Nó do ID3 ou C4.5 (não usa criterio_divisao)
    else:
        print(espaco + f"Decisão: {no.atributo}")
        for valor, filho in no.filhos.items():
            print(espaco + f"--> Se = {valor}:")
            imprimir_arvore(filho, espaco + "  ")