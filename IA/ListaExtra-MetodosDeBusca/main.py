import tkinter as tk
from tkinter import ttk, messagebox
import threading
import time
import random

from puzzle_logic import PuzzleState
from heuristics import Heuristics
from solver import Solver

class PuzzleApp:
    def __init__(self, root):
        self.root = root
        self.root.title("15-Puzzle Solver - Trabalho IA")
        self.root.geometry("600x450")
        self.root.configure(bg="#2C3E50") 

        self.solver = Solver()
        
        # Estado inicial (Objetivo)
        self.goal_board = [[1, 2, 3, 4], 
                           [5, 6, 7, 8], 
                           [9, 10, 11, 12], 
                           [13, 14, 15, 0]]
        self.current_state = PuzzleState(self.goal_board)
        
        # Configuração da Interface
        self.create_widgets()
        self.draw_board(self.current_state.board)

    def create_widgets(self):
        # Frame Principal
        main_frame = tk.Frame(self.root, padx=10, pady=10, bg="#2C3E50")
        main_frame.pack(expand=True, fill="both")

        # --- Área do Tabuleiro (Esquerda) ---
        self.canvas = tk.Canvas(main_frame, width=300, height=300, bg="#e397bf")
        self.canvas.grid(row=0, column=0, rowspan=10, padx=10, pady=10)

        # --- Área de Controle (Direita) ---
        controls_frame = tk.Frame(main_frame, bg="#2C3E50")
        controls_frame.grid(row=0, column=1, sticky="n")

        # Campo de Seed (Semente) para tabuleiro igual para os testes
        tk.Label(controls_frame, text="Seed (Opcional para Testes):", 
                 font=("Arial", 10), bg="#2C3E50", fg="white").pack(pady=(10, 0))
        
        self.seed_entry = tk.Entry(controls_frame)
        self.seed_entry.pack(pady=5)

        # Botão Embaralhar (Mantenha o botão, mas ele usará a seed agora)
        self.btn_shuffle = tk.Button(controls_frame, text="Embaralhar", 
                                     bg="#95A5A6", fg="black", font=("Arial", 10, "bold"),
                                     command=self.shuffle_board)
        self.btn_shuffle.pack(fill="x", pady=5)

        # Botão Embaralhar
        #tk.Label(controls_frame, text="Configuração:", font=("Arial", 10, "bold"), bg="#2C3E50", fg="white").pack(pady=(0, 5))
        #self.btn_shuffle = tk.Button(controls_frame, text="Embaralhar (Gerar Novo Jogo)", bg="#B0C2C4", command=self.shuffle_board)
        #self.btn_shuffle.pack(fill="x", pady=5)

        #tk.Frame(controls_frame, height=10).pack() # Espaçador

        # Seleção de Algoritmo
        tk.Label(controls_frame, text="Algoritmo de Busca:", font=("Arial", 10, "bold"), bg="#2C3E50", fg="white").pack(pady=(0, 5))
        self.algo_var = tk.StringVar(value="A*")
        algo_options = ["A*", "Gulosa", "BFS (Largura)"]
        self.algo_menu = ttk.Combobox(controls_frame, textvariable=self.algo_var, values=algo_options, state="readonly")
        self.algo_menu.pack(fill="x", pady=5)
        self.algo_menu.bind("<<ComboboxSelected>>", self.toggle_heuristics)

        # Seleção de Heurística
        tk.Label(controls_frame, text="Heurística (A* / Gulosa):", font=("Arial", 10, "bold"), bg="#2C3E50", fg="white").pack(pady=(10, 5))
        self.heur_var = tk.StringVar(value="Manhattan")
        heur_options = ["Manhattan", "Euclidiana", "Peças Fora (Misplaced)"]
        self.heur_menu = ttk.Combobox(controls_frame, textvariable=self.heur_var, values=heur_options, state="readonly")
        self.heur_menu.pack(fill="x", pady=5)

        tk.Frame(controls_frame, height=20).pack() # Espaçador

        # Botão Resolver
        self.btn_solve = tk.Button(controls_frame, text="RESOLVER", bg="#27ae60", fg="white", font=("Arial", 12, "bold"), command=self.start_solving)
        self.btn_solve.pack(fill="x", pady=10)

        # Labels de Estatísticas
        self.stats_label = tk.Label(controls_frame, text="Aguardando...", justify="left", bg="#2C3E50", fg="#f0e2ee")
        self.stats_label.pack(pady=10)

    def toggle_heuristics(self, event=None):
        """Desativa a seleção de heurística se for BFS"""
        if self.algo_var.get() == "BFS (Largura)":
            self.heur_menu.config(state="disabled")
        else:
            self.heur_menu.config(state="readonly")

    def draw_board(self, board):
        """Desenha o grid 4x4 no Canvas"""
        self.canvas.delete("all")
        cell_size = 75

        for r in range(4):
            for c in range(4):
                val = board[r][c]
                x1 = c * cell_size
                y1 = r * cell_size
                x2 = x1 + cell_size
                y2 = y1 + cell_size

                if val != 0: # Não desenha o espaço vazio
                    self.canvas.create_rectangle(x1, y1, x2, y2, fill="#db3b86", outline="#e397bf")
                    self.canvas.create_text(x1 + cell_size/2, y1 + cell_size/2, text=str(val), font=("Arial", 20, "bold"), fill="#f0e2ee")
                else:
                    self.canvas.create_rectangle(x1, y1, x2, y2, fill="#f0e2ee", outline="white")

    def shuffle_board(self):
        """
        Embaralha o tabuleiro. 
        Se houver uma Seed, o embaralhamento é reproduzível (para testes).
        Se não, é aleatório.
        """
        seed_value = self.seed_entry.get()
        
        if seed_value.strip(): # Se o campo não estiver vazio
            try:
                # Fixa a aleatoriedade com o número digitado
                random.seed(int(seed_value))
                print(f"Usando Seed fixa: {seed_value}") # Para debug
            except ValueError:
                messagebox.showwarning("Aviso", "A Seed deve ser um número inteiro!")
                return
        else:
            # Garante aleatoriedade total (limpa qualquer seed anterior)
            random.seed(None)
            print("Usando aleatoriedade normal")

        # Lógica de embaralhamento (Idêntica à anterior)
        state = PuzzleState(self.goal_board) 
        
        # Dica: Para testes consistentes, mantenha o número de movimentos fixo também
        moves = 30 
        
        for _ in range(moves):
            successors = state.get_successors()
            # O random.choice agora obedecerá a seed configurada acima
            state = random.choice(successors)
        
        self.current_state = state
        self.draw_board(self.current_state.board)
        
        # Reset visual
        self.stats_label.config(text="Tabuleiro Embaralhado!\nPronto para resolver.")
        
        # IMPORTANTE: Voltar a seed para None para não afetar outras partes do programa
        # (caso você adicione outras funcionalidades aleatórias no futuro)
        if seed_value.strip():
            random.seed(None)
    """
    def shuffle_board(self):
        
        #Embaralha fazendo movimentos válidos a partir do objetivo.
        #Isso garante que o puzzle gerado seja sempre solucionável.
        
        state = PuzzleState(self.goal_board) # Começa do resolvido
        
        # 30 a 50 movimentos aleatórios é suficiente para ficar difícil
        # CUIDADO: Se usar BFS, não embaralhe muito (ex: 10 a 15), ou a RAM vai estourar!
        moves = 30 
        
        for _ in range(moves):
            successors = state.get_successors()
            state = random.choice(successors)
        
        self.current_state = state
        self.draw_board(self.current_state.board)
        self.stats_label.config(text="Tabuleiro Embaralhado!\nPronto para resolver.")
    """
    def start_solving(self):
        """Inicia a thread de resolução para não travar a interface"""
        self.btn_solve.config(state="disabled", text="Calculando...")
        self.stats_label.config(text="Buscando solução...\nAguarde.")
        
        # Rodar em thread separada
        thread = threading.Thread(target=self.run_solver)
        thread.start()

    def run_solver(self):
        algorithm = self.algo_var.get()
        heuristic_name = self.heur_var.get()
        
        # Mapear nome da heurística para função
        h_func = None
        if heuristic_name == "Manhattan":
            h_func = Heuristics.manhattan_distance
        elif heuristic_name == "Euclidiana":
            h_func = Heuristics.euclidean_distance
        else:
            h_func = Heuristics.misplaced_tiles

        result = None
        
        # Executar algoritmo escolhido
        if algorithm == "BFS (Largura)":
            result = self.solver.bfs(self.current_state)
        elif algorithm == "Gulosa":
            result = self.solver.greedy(self.current_state, h_func)
        else: # A*
            result = self.solver.a_star(self.current_state, h_func)

        # Voltar para a thread principal para atualizar UI
        self.root.after(0, self.show_results, result)

    def show_results(self, result):
        self.btn_solve.config(state="normal", text="RESOLVER")
        
        if result["success"]:
            # Mostrar estatísticas
            stats_text = (f"Tempo: {result['time']:.4f}s\n"
                          f"Nós visitados: {result['nodes']}\n"
                          f"Profundidade: {result['depth']}\n"
                          f"Passos: {len(result['path']) - 1}")
            self.stats_label.config(text=stats_text, fg="#27AE60")
            
            # Iniciar animação
            self.animate_solution(result["path"])
        else:
            self.stats_label.config(text="Falha ao encontrar solução!", fg="red")
            messagebox.showerror("Erro", "Não foi possível encontrar uma solução (talvez tempo/memória esgotados).")

    def animate_solution(self, path):
        """Anima a lista de estados retornada pelo solver"""
        if not path:
            return

        next_state = path.pop(0)
        self.draw_board(next_state.board)
        self.current_state = next_state
        
        if path:
            # Chama o próximo passo em 300ms
            self.root.after(300, lambda: self.animate_solution(path))
        else:
             messagebox.showinfo("Sucesso", "Puzzle Resolvido!")

if __name__ == "__main__":
    root = tk.Tk()
    app = PuzzleApp(root)
    root.mainloop()