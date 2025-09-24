# no.py (versão atualizada)

class NoArvore:
    def __init__(self, atributo=None, criterio_divisao=None, resultado=None, filhos=None):
        """
        Um nó na árvore de decisão.
        - atributo: O nome do atributo usado para a decisão neste nó.
        - criterio_divisao: A regra para dividir os dados.
            - Para numérico: um float (limiar).
            - Para categórico: um set de valores.
        - resultado: A classe prevista se este for um nó folha.
        - filhos: Dicionário com os nós filhos.
        """
        self.atributo = atributo
        self.criterio_divisao = criterio_divisao
        self.resultado = resultado
        self.filhos = filhos if filhos is not None else {}

    def eh_folha(self):
        """Retorna True se o nó for uma folha."""
        return self.resultado is not None