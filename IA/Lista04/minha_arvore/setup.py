from setuptools import setup, find_packages

setup(
    name="minha_arvore",              # nome do pacote
    version="0.1.0",                  # versão inicial
    author="Alessandra",              # seu nome
    description="Implementação de árvores de decisão (ID3, C4.5, CART) do zero",
    long_description=open("README.md", encoding="utf-8").read(),
    long_description_content_type="text/markdown",
    packages=find_packages(),
    install_requires=["pandas", "numpy"],  # dependências
    python_requires=">=3.7",
)
