#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include "my_bib_matrix.hpp"

using namespace std;

/*Matrix readMatrixFromFile(std::string fileName){
    //abrindo arquivo no modo de leitura
    std::ifstream arquivo;
    arquivo.open(fileName);

    if(arquivo.is_open()){
        int linha, coluna, valor;

        arquivo >> linha >> coluna;
        Matrix matrix(linha, coluna);

        if(linha <= 0 || coluna <= 0){
            std::cout << "Dimensoes invalidas da matriz..." << std::endl;
            exit(1);
        }

        //matrix.setRow(linha);
        //matrix.setColumn(coluna);
        for(int i = 0; i < linha; i++){
            for(int j = 0; j < coluna; j++){
                arquivo >> valor;
                //cout<< valor << endl;
                matrix.setValue(i, j, valor);
            }
        }
        std::cout << "Arquivo lido..." << std::endl;
        //fecha arquivo
        arquivo.close();

        return matrix;
    } else {
        std::cout << "Erro ao abrir arquivo..." << std::endl;
        exit(1);
    }

}*/

Matrix readMatrixFromFile(const std::string& fileName) {
    std::ifstream arquivo(fileName);

    if (!arquivo.is_open()) {
        throw std::runtime_error("Erro ao abrir arquivo...");
    }

    int linha, coluna, valor;
    arquivo >> linha >> coluna;

    if (linha <= 0 || coluna <= 0) {
        throw std::invalid_argument("Dimensoes invalidas da matriz...");
    }

    Matrix matrix(linha, coluna);

    for (int i = 0; i < linha; ++i) {
        for (int j = 0; j < coluna; ++j) {
            if (!(arquivo >> valor)) {
                throw std::runtime_error("Erro ao ler valor da matriz...");
            }
            matrix.setValue(i, j, valor);
        }
    }

    std::cout << "Arquivo lido..." << std::endl;
    return matrix;
}

void metodo1211(){
    std::cout << "METODO 1211\n" << std::endl;
    int linha, coluna, inicio, fim;

    do{
        std::cout << "Digite o numero de linhas: ";
        std::cin >> linha;
        getchar();
        std::cout << "Digite o numero de colunas: ";
        std::cin >> coluna;
        getchar();
    } while(linha <= 0 || coluna <= 0);

    do{
        std::cout << "Digite o limite de inicio: ";
        std::cin >> inicio;
        getchar();
        std::cout << "Digite o limite de fim: ";
        std::cin >> fim;
        getchar();
    } while(inicio >= fim);

    if(linha > 0 && coluna > 0 && inicio < fim){
        Matrix matrix(linha, coluna);
        matrix.randomIntGenerate(inicio, fim);
        matrix.printMatrix();
        matrix.filePrintMatrix("DADOS.txt");
    } else {
        std::cout << "Valores invalidos..." << std::endl;
    }

    std::cout << "\nAperte enter para finalizar METODO 1211" << std::endl;
    getchar();
}

void metodo1212(){
    std::cout << "METODO 1212\n" << std::endl;

    int constante;
    std::cout << "Digite o valor da constante: ";
    std::cin >> constante;
    getchar();

    Matrix matrix, matrix2;
    matrix = readMatrixFromFile("DADOS1.txt");
    matrix.printMatrix();

    matrix2 = matrix.scalar(constante);
    matrix2.printMatrix();

    std::cout << "\nAperte enter para finalizar METODO 1212" << std::endl;
    getchar();
}

void metodo1213(){
    std::cout << "METODO 1213\n" << std::endl;

    Matrix matrix;
    matrix = readMatrixFromFile("DADOS1.txt");

    bool teste;
    teste = matrix.identidade();
    if(teste){
        std::cout << "A matriz e identidade" << std::endl;
    } else {
        std::cout << "A matriz NAO e identidade" << std::endl;
    }

    std::cout << "\nAperte enter para finalizar METODO 1213" << std::endl;
    getchar();
}

void metodo1214(){
    std::cout << "METODO 1214\n" << std::endl;

    Matrix matrix1, matrix2;
    matrix1 = readMatrixFromFile("DADOS1.txt");
    matrix2 = readMatrixFromFile("DADOS2.txt");
    matrix1.printMatrix();
    matrix2.printMatrix();

    bool teste;
    teste = (matrix1==matrix2);
    if(teste){
        std::cout << "As matrizes sao iguais" << std::endl;
    } else {
        std::cout << "As matrizes sao diferentes" << std::endl;
    }

    std::cout << "\nAperte enter para finalizar METODO 1214" << std::endl;
    getchar();
}

void metodo1215(){
    std::cout << "METODO 1215\n" << std::endl;

    Matrix matrix1, matrix2, matrixSoma;
    matrix1 = readMatrixFromFile("DADOS1.txt");
    matrix2 = readMatrixFromFile("DADOS2.txt");

    matrixSoma = matrix1.add(matrix2);

    matrix1.printMatrix();
    matrix2.printMatrix();
    std::cout << "Soma = " << std::endl;
    matrixSoma.printMatrix();

    std::cout << "\nAperte enter para finalizar METODO 1215" << std::endl;
    getchar();
}

void metodo1216(){
    std::cout << "METODO 1216\n" << std::endl;

    int linha1, linha2, constante;
    Matrix matrix1;
    matrix1 = readMatrixFromFile("DADOS1.txt");
    matrix1.printMatrix();

    std::cout << "Digite a primeira linha: ";
    std::cin >> linha1;
    getchar();
    std::cout << "Digite a segunda linha: ";
    std::cin >> linha2;
    getchar();
    std::cout << "Digite a constante: ";
    std::cin >> constante;
    getchar();

    matrix1.addRows(linha1, linha2, constante);
    matrix1.printMatrix();

    std::cout << "\nAperte enter para finalizar METODO 1216" << std::endl;
    getchar();
}

void metodo1217(){
    std::cout << "METODO 1217\n" << std::endl;

    int linha1, linha2, constante;
    Matrix matrix1;
    matrix1 = readMatrixFromFile("DADOS1.txt");
    matrix1.printMatrix();

    std::cout << "Digite a primeira linha: ";
    std::cin >> linha1;
    getchar();
    std::cout << "Digite a segunda linha: ";
    std::cin >> linha2;
    getchar();
    std::cout << "Digite a constante: ";
    std::cin >> constante;
    getchar();

    matrix1.subtractRows(linha1, linha2, constante);
    matrix1.printMatrix();

    std::cout << "\nAperte enter para finalizar METODO 1217" << std::endl;
    getchar();
}

void metodo1218(){
    std::cout << "METODO 1218\n" << std::endl;

    int procurado;
    std::cout << "Digite o valor procurado: ";
    std::cin >> procurado;
    getchar();

    Matrix matrix1;
    matrix1 = readMatrixFromFile("DADOS1.txt");
    matrix1.printMatrix();

    int teste;
    teste = matrix1.searchRows(procurado);
    if(teste != -1){
        std::cout << "O numero procurado " << procurado << " foi encontrado na linha " << teste << std::endl;
    } else{
        std::cout << "O numero procurado " << procurado << " nao foi encontrado " << std::endl;
    }


    std::cout << "\nAperte enter para finalizar METODO 1218" << std::endl;
    getchar();
}

void metodo1219(){
    std::cout << "METODO 1219\n" << std::endl;

    int procurado;
    std::cout << "Digite o valor procurado: ";
    std::cin >> procurado;
    getchar();

    Matrix matrix1;
    matrix1 = readMatrixFromFile("DADOS1.txt");
    matrix1.printMatrix();

    int teste;
    teste = matrix1.searchColumns(procurado);
    if(teste != -1){
        std::cout << "O numero procurado " << procurado << " foi encontrado na coluna " << teste << std::endl;
    } else{
        std::cout << "O numero procurado " << procurado << " nao foi encontrado " << std::endl;
    }

    std::cout << "\nAperte enter para finalizar METODO 1219" << std::endl;
    getchar();
}

void metodo1220(){
    std::cout << "METODO 1220\n" << std::endl;

    Matrix matrix1, matrixT;
    matrix1 = readMatrixFromFile("DADOS1.txt");
    matrix1.printMatrix();

    matrixT = matrix1.transpose();
    matrixT.printMatrix();

    std::cout << "\nAperte enter para finalizar METODO 1220" << std::endl;
    getchar();

}

int extra01(Matrix matrix1){
    int lin, col;
    lin = matrix1.getRow();
    col = matrix1.getColumn();
    if(lin != col){
        return -1;
    }

    int cont = 1;
    int val;
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            val = matrix1.getValue(j, i);
            //cout<< val << " ";
            if(val != cont){
                return -1;
            }
            cont++;
        }
    }
    return 1;
}

void metodo12E1(){
    std::cout << "METODO 12E1\n" << endl;

    Matrix matrix1;
    matrix1 = readMatrixFromFile("DADOS1.txt");
    matrix1.printMatrix();

    int result;
    result = extra01(matrix1);
    if(result == 1){
        std::cout << "Esta dentro das caracteristicas desejadas" << std::endl;
    } else {
        std::cout << "Nao esta dentro das caracteristicas" << std::endl;
    }

    std::cout << "\nAperte enter para finalizar METODO 12E1" << std::endl;
    getchar();
}

int extra02(Matrix matrix1){
    int lin, col;
    lin = matrix1.getRow();
    col = matrix1.getColumn();
    if(lin != col){
        return -1;
    }

    int cont = lin*col;
    int val;
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            val = matrix1.getValue(j, i);
            if(val != cont){
                return -1;
            }
            cont--;
        }
    }
    return 1;
}

void metodo12E2(){
    std::cout << "METODO 12E2\n" << endl;

    Matrix matrix1;
    matrix1 = readMatrixFromFile("DADOS1.txt");
    matrix1.printMatrix();

    int result;
    result = extra02(matrix1);
    if(result == 1){
        std::cout << "Esta dentro das caracteristicas desejadas" << std::endl;
    } else {
        std::cout << "Nao esta dentro das caracteristicas" << std::endl;
    }

    std::cout << "\nAperte enter para finalizar METODO 12E2" << std::endl;
    getchar();
}

int main(void){
       int opcao;
  do{
    std::cout << "\n\nEscolha uma das opcoes abaixo: \n";
    std::cout << "\n\t0: Sair";
    std::cout << "\n\t1: Metodo1211";
    std::cout << "\n\t2: Metodo1212";
    std::cout << "\n\t3: Metodo1213";
    std::cout << "\n\t4: Metodo1214";
    std::cout << "\n\t5: Metodo1215";
    std::cout << "\n\t6: Metodo1216";
    std::cout << "\n\t7: Metodo1217";
    std::cout << "\n\t8: Metodo1218";
    std::cout << "\n\t9: Metodo1219";
    std::cout << "\n\t10: Metodo1220";
    std::cout << "\n\t11: Metodo12E1";
    std::cout << "\n\t12: Metodo12E2\n";
    std::cin >> opcao;
    getchar();

    switch(opcao){
        case 0:
            break;
        case 1:
            metodo1211();
            break;
        case 2:
            metodo1212();
            break;
        case 3:
            metodo1213();
            break;
        case 4:
            metodo1214();
            break;
        case 5:
            metodo1215();
            break;
        case 6:
            metodo1216();
            break;
        case 7:
            metodo1217();
            break;
        case 8:
            metodo1218();
            break;
        case 9:
            metodo1219();
            break;
        case 10:
            metodo1220();
            break;
        case 11:
            metodo12E1();
            break;
        case 12:
            metodo12E2();
            break;

        default:
            std::cout << "Opcao invalida!\n";
            break;
    }

  } while(opcao != 0);

return 0;
}
