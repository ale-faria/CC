import math

class Heuristics:
    """
    Classe responsável por calcular as estimativas de custo (h(n))
    para o problema do 15-puzzle.
    O estado meta é:
    [[1, 2, 3, 4],
     [5, 6, 7, 8],
     [9, 10, 11, 12],
     [13, 14, 15, 0]]
    """

    @staticmethod
    def get_goal_position(value):
        """
        Retorna a coordenada (linha, coluna) onde o valor DEVERIA estar.
        Ex: valor 1 deve estar em (0, 0), valor 5 em (1, 0).
        """
        if value == 0:
            return (3, 3)
        return ((value - 1) // 4, (value - 1) % 4)

    @staticmethod
    def misplaced_tiles(board):
        """
        Heurística 1: Peças fora do lugar.
        Conta quantas peças não estão na posição correta (ignora o espaço vazio 0).
        """
        count = 0
        for r in range(4):
            for c in range(4):
                value = board[r][c]
                if value != 0:  
                    goal_r, goal_c = Heuristics.get_goal_position(value)
                    if (r, c) != (goal_r, goal_c):
                        count += 1
        return count

    @staticmethod
    def manhattan_distance(board):
        """
        Heurística 2: Distância de Manhattan.
        Soma das distâncias verticais e horizontais de cada peça até seu objetivo.
        """
        distance = 0
        for r in range(4):
            for c in range(4):
                value = board[r][c]
                if value != 0:
                    goal_r, goal_c = Heuristics.get_goal_position(value)
                    # |x1 - x2| + |y1 - y2|
                    distance += abs(r - goal_r) + abs(c - goal_c)
        return distance

    @staticmethod
    def euclidean_distance(board):
        """
        Heurística 3: Distância Euclidiana.
        Calcula a distância em linha reta (hipotenusa) de cada peça até seu objetivo.
        """
        distance = 0
        for r in range(4):
            for c in range(4):
                value = board[r][c]
                if value != 0:
                    goal_r, goal_c = Heuristics.get_goal_position(value)
                    # sqrt((x1 - x2)^2 + (y1 - y2)^2)
                    d = math.sqrt((r - goal_r)**2 + (c - goal_c)**2)
                    distance += d
        return distance