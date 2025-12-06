import random
import copy

class PuzzleState:
    def __init__(self, board, parent=None, move="", depth=0, cost=0):
        # board é uma lista de listas, ex: [[1, 2, 3, 4], [5, 6, 7, 8], ...]
        # 0 representa o espaço vazio
        self.board = board
        self.parent = parent  # Para reconstruir o caminho [cite: 25]
        self.move = move      # Qual movimento levou a este estado
        self.depth = depth    # Profundidade da solução [cite: 24]
        self.cost = cost      # Custo acumulado (g(n))
        self.heuristic = 0    # Heurística (h(n))
        
        # Encontra a posição do vazio (0)
        self.blank_pos = self.find_blank()

    def find_blank(self):
        for r in range(4):
            for c in range(4):
                if self.board[r][c] == 0:
                    return (r, c)
    
    def is_goal(self):
        # O objetivo é: [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 0]]
        expected = 1
        for r in range(4):
            for c in range(4):
                if r == 3 and c == 3:
                    if self.board[r][c] != 0: return False
                elif self.board[r][c] != expected:
                    return False
                else:
                    expected += 1
        return True

    def get_successors(self):
        successors = []
        r, c = self.blank_pos
        # Movimentos possíveis: Cima, Baixo, Esquerda, Direita
        directions = {
            'Cima': (-1, 0),
            'Baixo': (1, 0),
            'Esquerda': (0, -1),
            'Direita': (0, 1)
        }

        for action, (dr, dc) in directions.items():
            nr, nc = r + dr, c + dc
            if 0 <= nr < 4 and 0 <= nc < 4:
                # Cria uma cópia do tabuleiro e troca as peças
                new_board = copy.deepcopy(self.board)
                new_board[r][c], new_board[nr][nc] = new_board[nr][nc], new_board[r][c]
                
                new_state = PuzzleState(new_board, self, action, self.depth + 1, self.cost + 1)
                successors.append(new_state)
        
        return successors

    # Métodos necessários para comparação e uso em sets/filas de prioridade
    def __eq__(self, other):
        return self.board == other.board

    def __hash__(self):
        # Transforma lista de listas em tupla de tuplas para ser "hashable"
        return hash(tuple(tuple(row) for row in self.board))

    def __lt__(self, other):
        # Necessário para a fila de prioridade do A* (compara f(n) = g(n) + h(n))
        return (self.cost + self.heuristic) < (other.cost + other.heuristic)

    def __str__(self):
        return '\n'.join([str(row) for row in self.board])