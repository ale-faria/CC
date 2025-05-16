#ifndef MY_BIB_MATRIX_HPP
#define MY_BIB_MATRIX_HPP


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

class Matrix{
private:
    int linha;
    int coluna;
    int **valores;

    void allocateMatrix() {
        valores = new int*[linha];
        for (int i = 0; i < linha; i++) {
            valores[i] = new int[coluna]();
        }
    }

     void deallocateMatrix() {
        if (valores) {
            for (int i = 0; i < linha; i++) {
                delete[] valores[i];
            }
            delete[] valores;
            valores = nullptr;
        }
    }
public:
    //contrutor
    Matrix(){
        this->linha = 0;
        this->coluna = 0;
        valores = nullptr;
    }

    //contrutor
    Matrix(int linha, int coluna){
        this->linha = linha;
        this->coluna = coluna;
        valores = new int*[linha];
        for(int i = 0; i < linha; i++){
            valores[i] = new int[coluna];
        }
    }

    // Construtor de cópia
    Matrix(const Matrix &outra) : linha(outra.linha), coluna(outra.coluna) {
        allocateMatrix();
        for (int i = 0; i < linha; i++) {
            for (int j = 0; j < coluna; j++) {
                valores[i][j] = outra.valores[i][j];
            }
        }
    }

    // Operador de atribuição de cópia
    Matrix& operator=(const Matrix &outra) {
        if (this != &outra) {
            deallocateMatrix();
            linha = outra.linha;
            coluna = outra.coluna;
            allocateMatrix();
            for (int i = 0; i < linha; i++) {
                for (int j = 0; j < coluna; j++) {
                    valores[i][j] = outra.valores[i][j];
                }
            }
        }
        return *this;
    }

    // Construtor de movimentação
    Matrix(Matrix &&outra) noexcept : linha(outra.linha), coluna(outra.coluna), valores(outra.valores) {
        outra.linha = 0;
        outra.coluna = 0;
        outra.valores = nullptr;
    }

    // Operador de atribuição de movimentação
    Matrix& operator=(Matrix &&outra) noexcept {
        if (this != &outra) {
            deallocateMatrix();
            linha = outra.linha;
            coluna = outra.coluna;
            valores = outra.valores;
            outra.linha = 0;
            outra.coluna = 0;
            outra.valores = nullptr;
        }
        return *this;
    }



    // Destrutor
    ~Matrix() {
        for (int i = 0; i < linha; i++) {
            delete[] valores[i];
        }
        delete[] valores;
    }

    void setValue(int i, int j, int valor){
        if(i >= 0 && i < linha && j >= 0 && j < coluna){
            valores[i][j] = valor;
        } else {
            std::cout << "Posicao invalida..." << std::endl;
        }
    }

    void setRow(int linha){
        if(linha > 0){
            this->linha = linha;
            valores = new int*[linha];
        }
    }

    void setColumn(int coluna){
        if(coluna > 0){
            this->coluna = coluna;
            for(int i = 0; i < linha; i++){
            valores[i] = new int[coluna];
        }
        }
    }

    int getRow(){
        return linha;
    }

    int getColumn(){
        return coluna;
    }

    int getValue(int i, int j){
        int val = valores[i][j];
        return val;
    }

    void randomIntGenerate(int inicio, int fim){
        int numeroAleatorio;
        for(int i = 0; i < linha; i++){
            for(int j = 0; j < coluna; j++){
                numeroAleatorio = inicio + (rand() % (fim - inicio));
                valores[i][j] = numeroAleatorio;
            }
    }
    }

    void printMatrix()const{
        std::cout << std::endl;
        for(int i = 0; i < linha; i++){
            for(int j = 0; j < coluna; j++){
                std::cout << valores[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void filePrintMatrix(std::string fileName){
        //abrindo arquivo no modo de escrita
        std::ofstream arquivo;
        arquivo.open(fileName);

        if(arquivo.is_open()){
            //primeira linha do arquivo recebe a quantidade de linhas
            arquivo << linha << std::endl;
            //segubda linha do arquivo recebe quantidade de colunas
            arquivo << coluna << std::endl;
            //demais linhas do arquivo recebe os valores da matriz
            for(int i = 0; i < linha; i++){
                for(int j = 0; j < coluna; j++){
                    arquivo << valores[i][j] << std::endl;
                }
            }

            //fecha arquivo
            arquivo.close();

            std::cout << "Gravado no arquivo..." << std::endl;
        } else {
            std::cout << "Erro ao abrir arquivo..." << std::endl;
        }
    }

    Matrix scalar(const int constante){
        Matrix matrixResult(linha, coluna);
        int valor;
        for(int i = 0; i < linha; i++){
            for(int j = 0; j < coluna; j++){
                valor = valores[i][j] * constante;
                matrixResult.setValue(i, j, valor);
            }
        }
        return matrixResult;
    }

    bool identidade(){
        //tem que ser quadrada pra ser identidade
        if(linha == coluna){
            for(int i = 0; i < linha; i++){
                if(valores[i][i] != 1){
                    return false;
                }
            for(int j = 0; j < coluna; j++){
                if(i != j && valores[i][j] != 0){
                    return false;
                }
            }
        }
            return true;
        } else {
            return false;
        }
    }

        bool operator==(const Matrix &outra){
            if(linha != outra.linha || coluna != outra.coluna){
                return false; //tamanhos diferentes
            }

            for(int i = 0; i < linha; i++){
                for(int j = 0; j < coluna; j++){
                    if(valores[i][j] != outra.valores[i][j]){
                        return false; //elementos diferentes
                    }
                }
            }

            return true; //elementos sao iguais
        }

        Matrix add(const Matrix &matrix2){
            if(linha != matrix2.linha || coluna != matrix2.coluna){
                std::cout << "Matrizes de tamanhos diferentes" << std::endl;
                exit(1); //tamanhos diferentes
            }

            Matrix matrixSoma(linha, coluna);
            int valor;
            for(int i = 0; i < linha; i++){
                for(int j = 0; j < coluna; j++){
                    valor = (valores[i][j] + matrix2.valores[i][j]);
                    matrixSoma.setValue(i, j, valor);
                }
            }
            return matrixSoma;
        }

        void addRows(int linha1, int linha2, int constante){
            if(linha1 < 0 || linha1 >= linha || linha2 < 0 || linha2 >= linha){
                std::cout << "Indices da linha invalido..." << std::endl;
                return;
            }

            for(int j = 0; j < coluna; j++){
                valores[linha1][j] = ((valores[linha1][j] + valores[linha2][j]) * constante);
            }
        }

        void subtractRows(int linha1, int linha2, int constante){
            if(linha1 < 0 || linha1 >= linha || linha2 < 0 || linha2 >= linha){
                std::cout << "Indices da linha invalido..." << std::endl;
                return;
            }

            for(int j = 0; j < coluna; j++){
                valores[linha1][j] = ((valores[linha1][j] - valores[linha2][j]) * constante);
            }
        }

        int searchRows(int procurado){
            for(int i = 0; i < linha; i++){
                for(int j = 0; j < coluna; j++){
                    if(valores[i][j] == procurado){
                        return i;//retorna a linha do numero procurado
                    }
                }
            }

            return -1;//retorna -1 se não encontrar o numero procurado
        }

        int searchColumns(int procurado){
            for(int i = 0; i < linha; i++){
                for(int j = 0; j < coluna; j++){
                    if(valores[i][j] == procurado){
                        return j;//retorna a coluna do numero procurado
                    }
                }
            }

            return -1;//retorna -1 se não encontrar o numero procurado
        }

        Matrix transpose(){
            Matrix matrixT(coluna, linha);
            int valor;
            for(int i = 0; i < coluna; i++){
                for(int j = 0; j < linha; j++){
                    valor = valores[j][i];
                    matrixT.setValue(i, j, valor);
                }
            }
            return matrixT;
        }

};


#endif // MY_BIB_MATRIX_HPP
