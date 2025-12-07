import heapq
import time
from collections import deque
from puzzle_logic import PuzzleState
from heuristics import Heuristics 

class Solver:
    def __init__(self):
        pass

    def get_path(self, state):
        """Reconstrói o caminho do estado final até o inicial seguindo os pais."""
        path = []
        current = state
        while current:
            path.append(current)
            current = current.parent
        return path[::-1] # Inverte para ficar do início ao fim

    def bfs(self, initial_state):
        """Busca em Largura (Breadth-First Search)"""
        start_time = time.time()
        
        # Fila FIFO para BFS
        queue = deque([initial_state])
        visited = set()
        visited.add(initial_state)
        
        nodes_visited = 0

        while queue:
            current_state = queue.popleft()
            nodes_visited += 1

            if current_state.is_goal():
                end_time = time.time()
                return {
                    "success": True,
                    "path": self.get_path(current_state),
                    "time": end_time - start_time,
                    "nodes": nodes_visited,
                    "depth": current_state.depth
                }

            for child in current_state.get_successors():
                if child not in visited:
                    visited.add(child)
                    queue.append(child)
        
        return {"success": False}

    def greedy(self, initial_state, heuristic_func):
        """Busca Gulosa (Greedy Search)"""
        # Na Gulosa, f(n) = h(n). Ignoramos o custo g(n).
        start_time = time.time()
        
        # Calcula heurística inicial
        initial_state.heuristic = heuristic_func(initial_state.board)
        
        initial_state.cost = 0 
        
        priority_queue = []
        heapq.heappush(priority_queue, initial_state)
        
        visited = set()
        visited.add(initial_state)
        
        nodes_visited = 0

        while priority_queue:
            current_state = heapq.heappop(priority_queue)
            nodes_visited += 1

            if current_state.is_goal():
                end_time = time.time()
                return {
                    "success": True,
                    "path": self.get_path(current_state),
                    "time": end_time - start_time,
                    "nodes": nodes_visited,
                    "depth": current_state.depth
                }

            for child in current_state.get_successors():
                if child not in visited:
                    # Na gulosa, o custo acumulado não importa para a prioridade, só a heurística
                    child.cost = 0 
                    child.heuristic = heuristic_func(child.board)
                    visited.add(child)
                    heapq.heappush(priority_queue, child)
                    
        return {"success": False}

    def a_star(self, initial_state, heuristic_func):
        """Algoritmo A* (A-Star)"""
        # No A*, f(n) = g(n) + h(n)
        start_time = time.time()
        
        initial_state.heuristic = heuristic_func(initial_state.board)
        
        priority_queue = []
        heapq.heappush(priority_queue, initial_state)
        
        visited = set()
        visited.add(initial_state)
        
        nodes_visited = 0

        while priority_queue:
            current_state = heapq.heappop(priority_queue)
            nodes_visited += 1

            if current_state.is_goal():
                end_time = time.time()
                return {
                    "success": True,
                    "path": self.get_path(current_state),
                    "time": end_time - start_time,
                    "nodes": nodes_visited,
                    "depth": current_state.depth
                }

            for child in current_state.get_successors():
                # Calcula a heurística para o filho
                child.heuristic = heuristic_func(child.board)
                
                if child not in visited:
                    visited.add(child)
                    heapq.heappush(priority_queue, child)
                    
        return {"success": False}