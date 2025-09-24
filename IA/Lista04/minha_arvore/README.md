# minha_arvore 🌳

Biblioteca em Python que implementa **árvores de decisão do zero**, sem uso de bibliotecas prontas de machine learning. 

Inclui os algoritmos:
- **ID3** → baseado em ganho de informação (entropia)
- **C4.5** → baseado em *gain ratio*
- **CART** → baseado em índice Gini, com divisões binárias

---

## 🚀 Instalação

1. Clone o repositório:
```bash
git clone [https://github.com/seu-usuario/minha_arvore.git](https://github.com/seu-usuario/minha_arvore.git)
cd minha_arvore
```
2. Instale a biblioteca localmente:
```bash
pip install .
```

## 📂 Estrutura do Projeto
```text
minha_arvore/
│
├── minha_arvore/
│   ├── __init__.py
│   ├── no.py
│   ├── funcoes.py
│   ├── id3.py
│   ├── c45.py
│   ├── cart.py
│   ├── util.py
│
├── setup.py
└── README.md
```

## ✨ Funcionalidades
- Construção de árvores ID3, C4.5 e CART
- Impressão da árvore no terminal
- Suporte a atributos categóricos e numéricos
- Implementação educacional, ideal para estudos

## 📌 Requisitos
- Python 3.7+
- pandas
- numpy

## 📄 Licença
Este projeto é de uso livre para fins acadêmicos e de aprendizado.

## 👩‍💻 Autora
Alessandra Faria Rodrigues  
Estudante de Ciência da Computação (PUC Minas)