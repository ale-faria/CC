#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;


 class RandArrayGenerator{
private:
    int tamanho;
    int *valores;
public:
    //construtor
    RandArrayGenerator(){
        tamanho = 0;
        valores = nullptr;
    }

    // Destrutor
    ~RandArrayGenerator() {
        delete[] valores; // Liberando memória alocada
    }

    // Define os valores do array
    void setValues(int* arr, int size) {
        delete[] valores; // Libera qualquer memória alocada anteriormente
        tamanho = size;
        valores = new int[size];
        for (int i = 0; i < size; ++i) {
            valores[i] = arr[i];
        }
    }


    // Define o tamanho do array
    void setSize(int size) {
        tamanho = size;
    }

    int* getValue(){
        return valores;
    }

    // Retorna o tamanho do array
    int getSize(){
        return tamanho;
    }

    //gera numero aleatório e coloca no array
    void randomIntGenerate(int n, int inicio, int fim){
        int numeroAleatorio;
        tamanho = n;
        valores = new int[n];
        for(int i = 0; i < tamanho; i++){
            numeroAleatorio = inicio + (rand() % (fim - inicio));
            valores[i] = numeroAleatorio;
        }

    }

    // Imprime o array no arquivo
    void printArrayFile(std::string fileName){
        std::ofstream arquivo(fileName); //abrindo arquivo no modo de escrita
        if(arquivo.is_open()){
            arquivo << tamanho << endl;
            for(int i = 0; i < tamanho; i++){
                arquivo << valores[i] << endl;
            }
            arquivo.close();
            std::cout << "Gravado no arquivo!" << endl;

        } else {
            std::cout << "Erro ao abrir arquivo..." << endl;
        }
    }

        //retorna o maior valor par de um arranjo
        int searchFirstOdd(){
            int maiorPar = -1;
            for(int i = 0; i < tamanho; i++){
                if(valores[i]%2 == 0 && valores[i] > maiorPar){
                    maiorPar = valores[i];
                }
            }
            return maiorPar;
        }

        //retorna o menor valor impar de um arranjo
        int searchFirstOddx3(){
            int menorImpar = -1;
            //procurando pelo menor valor impar
            for(int i = 0; i < tamanho; i++){
                if (valores[i] % 2 != 0) { // Verifica se é ímpar
                    if (menorImpar == -1 || valores[i] < menorImpar) {
                        menorImpar = valores[i]; // Atualiza menor ímpar encontrado
            }
        }
            }

        return menorImpar;

        }

        //retorna a soma dos valores do array - posicao de inicio e fim sao indicadas como paramentro
        int addInterval(int inicio, int fim){
            int soma = 0;
            if(inicio >= 0 && fim < tamanho && inicio < fim){
                for(int i = inicio; i <= fim; i++){
                    soma += valores[i];
                }
            }
        return soma;
}

        //retorna a media dos valores do array - posicao de inicio e fim sao indicadas como paramentro
        double averageInterval(int inicio, int fim){
            double media = 0;
            for(int i = inicio; i <= fim; i++){
                media += valores[i];
            }
            media = media/tamanho;
            return media;
        }

        //verica se todos os valores do array sao negativos
        int negatives(){
            int cont = 0;
            for(int i = 0; i < tamanho; i++){
                if(valores[i] < 0){
                    cont++;
                }
            }

            if(cont == tamanho){
                return 1;//retorna 1 se forem todos negativos
            } else {
                return 0;//retorna 0 se tiver valores positivos ou zero
            }
        }

        //verifica se os valores do array estao em ordem crescente
        int isCrescent(){
            int cont = 0;
            for(int i = 0; i < tamanho-1; i++){
                if(valores[i] > valores[i+1]){
                    cont++;
                }
            }

            if(cont == 0){
                return 1;//retorna 1 se estiver em ordem crescente
            } else {
                return 0;//retorna 0 se estiver desordenado
            }
        }

        //função para procurar um valor no array
        int searchInterval(int procurado, int inicio, int fim){
            if(inicio >= 0 && fim < tamanho && inicio < fim){
                for(int i = inicio; i < fim; i++){
                    if(valores[i] == procurado){
                        return 1;//retorna 1 se encontrar o valor procurado
                    }
                }
            }

            return 0;//retorna 0 se nao encontrar o valor procurado
        }

        //multiplica o array por uma constante
        void scalar(int contante, int inicio, int fim){
            if(inicio >= 0 && fim < tamanho && inicio < fim){
                int *temp = new int[tamanho];
                for(int i = 0; i < tamanho; i++){
                    if(i >= inicio && i <= fim){
                        temp[i] = valores[i] * contante;
                    } else {
                        temp[i] = valores[i];
                    }
                }

                setValues(temp, tamanho);
            }
        }

        void sortDown(){
            int temp;
            for(int i = 0; i < tamanho-1; i++){
                for(int j = i + 1; j < tamanho; j++){
                    if(valores[i] < valores[j]){
                        temp = valores[i];
                        valores[i] = valores[j];
                        valores[j] = temp;
                    }
                }
            }
        }

 };

 //para ler array do arquivo
 RandArrayGenerator readArrayFromFile(std::string fileName){
    RandArrayGenerator array;
    std::ifstream arquivo(fileName); //abrindo arquivo no modo de leitura
    if(arquivo.is_open()){
        int tamanho;
        arquivo >> tamanho; //lê a primeira linha do arquivo tamanho do array
        array.setSize(tamanho);
        int *temp = new int[tamanho];
        for(int i = 0; i < tamanho; i++){
            arquivo >> temp[i]; //lê os valores do arquivo
        }
        array.setValues(temp, tamanho); //coloca os valores lidos no objeto da classe
        delete [] temp; //libera memoria alocada
        arquivo.close(); //fecha arquivo
        std::cout << "Arquivo lido!" << endl;
    } else {
        std::cout << "Erro ao abrir arquivo..." << endl;
    }

    return array;
 }

 void printArray(RandArrayGenerator array){
     int tamanho = array.getSize();
    int *temp = new int[tamanho];
    temp = array.getValue();
    for(int i = 0; i < tamanho; i++){
        std::cout << temp[i] << " ";
    }
    std::cout << "\n";
 }

 void metodo1111(){
    std::cout << "METODO 1111\n" << endl;
    RandArrayGenerator array;
    int n, inicio, fim;

     do{
        std::cout << "Digite a quantidade n: ";
        std::cin >> n;
        getchar();
     } while (n <= 0);

     do{
         std::cout << "Digite o limite de inicio: ";
         std::cin >> inicio;
         getchar();
         std::cout << "Digite o limite de fim: ";
         std::cin >> fim;
         getchar();
     } while(inicio >= fim);

    array.randomIntGenerate(n, inicio, fim);
    array.printArrayFile("DADOS.txt");

    std::cout << "\nAperte enter para finalizar METODO 1111" << endl;
    getchar();
 }

 void metodo1112(){
    std::cout << "METODO 1112\n" << endl;

    RandArrayGenerator array;
    array = readArrayFromFile("DADOS.txt");

    int maiorPar;
    maiorPar = array.searchFirstOdd();

    if(maiorPar != -1){
        std::cout << "O maior valor par encontrado no arranjo foi " << maiorPar << endl;
    } else {
        std::cout << "Nao foi encontrado valores pares no arranjo" << endl;
    }

    std::cout << "\nAperte enter para finalizar METODO 1112" << endl;
    getchar();
 }

 void metodo1113(){
    std::cout << "METODO 1113\n" << endl;
    RandArrayGenerator array;
    array = readArrayFromFile("DADOS.txt");

    int menorImpar;
    menorImpar = array.searchFirstOddx3();

    if(menorImpar != -1){
        std::cout << "O menor valor impar encontrado no arranjo foi " << menorImpar << endl;
    } else {
        std::cout << "Nao foi encontrado valores impares no arranjo" << endl;
    }

    std::cout << "\nAperte enter para finalizar METODO 1113" << endl;
    getchar();
 }

void metodo1114(){
    std::cout << "METODO 1114\n" << endl;
    int inicio, fim;
    RandArrayGenerator array;
    array = readArrayFromFile("DADOS.txt");

    int tamanho = array.getSize();
    std::cout << "Tamanho do array = " << tamanho << endl;
    std::cout << "Digite a posicao de inicio: ";
    std::cin >> inicio;
    getchar();
    std::cout << "Digite a posicao de fim: ";
    std::cin >> fim;
    getchar();

    if((inicio >= 0 && fim < tamanho) && inicio < fim){
        int soma;
        soma = array.addInterval(inicio, fim);
        //std::cout << soma;
        std::cout << "A soma dos valores entre o intervalo [" << inicio << "," << fim << "] = " << soma << endl;
    } else {
        std::cout << "Valores invalidos..." << endl;
    }

    std::cout << "\nAperte enter para finalizar METODO 1114" << endl;
    getchar();
}

void metodo1115(){
    std::cout << "METODO 1115\n" << endl;
    int inicio, fim;
    RandArrayGenerator array;
    array = readArrayFromFile("DADOS.txt");

    int tamanho = array.getSize();
    std::cout << "Tamanho do array = " << tamanho << endl;
    std::cout << "Digite a posicao de inicio: ";
    std::cin >> inicio;
    getchar();
    std::cout << "Digite a posicao de fim: ";
    std::cin >> fim;
    getchar();

    if((inicio >= 0 && fim < tamanho) && inicio < fim){
        double media;
        media = array.averageInterval(inicio, fim);
        std::cout << "A media dos valores entre o intervalo [" << inicio << "," << fim << "] = " << media << endl;
    } else {
        std::cout << "Valores invalidos..." << endl;
    }

    std::cout << "\nAperte enter para finalizar METODO 1115" << endl;
    getchar();
}

void metodo1116(){
    std::cout << "METODO 1116\n" << endl;
    RandArrayGenerator array;
    array = readArrayFromFile("DADOS.txt");

    int teste;
    teste = array.negatives();

    if(teste){
        std::cout << "Todos os elementos do array sao negativos" << endl;
    } else {
        std::cout << "Ha elementos que nao sao negativos no array" << endl;
    }

    std::cout << "\nAperte enter para finalizar METODO 1116" << endl;
    getchar();
}

void metodo1117(){
    std::cout << "METODO 1117\n" << endl;
    RandArrayGenerator array;
    array = readArrayFromFile("DADOS.txt");

    int teste;
    teste = array.isCrescent();
    if(teste){
        std::cout << "O arranjo esta ordenado em ordem crescente" << endl;
    } else {
        std::cout << "O arranjo nao esta ordenado" << endl;
    }

    std::cout << "\nAperte enter para finalizar METODO 1117" << endl;
    getchar();
}

void metodo1118(){
    std::cout << "METODO 1118\n" << endl;
    int procurado, inicio, fim;
    RandArrayGenerator array;
    array = readArrayFromFile("DADOS.txt");

    std::cout <<"Tamanho do arranjo = " << array.getSize() << endl;
    std::cout << "Digite o valor procurado: ";
    std::cin >> procurado;
    getchar();
    std::cout << "Digite a posicao de inicio: ";
    std::cin >> inicio;
    getchar();
    std::cout << "Digite a posicao de fim: ";
    std::cin >> fim;
    getchar();

    if(inicio >= 0 && fim < array.getSize() && inicio < fim){
        int existe;
        existe = array.searchInterval(procurado, inicio, fim);
        if(existe){
            std::cout << "Valor encontrado" << endl;
        } else {
            std::cout << "Valor NAO encontrado" << endl;
        }
    } else {
        std::cout << "Valor invalido..." << endl;
    }

    std::cout << "\nAperte enter para finalizar METODO 1118" << endl;
    getchar();
}

void metodo1119(){
    std::cout << "METODO 1119\n" << endl;
    int constante, inicio, fim;
    RandArrayGenerator array;
    array = readArrayFromFile("DADOS.txt");

    std::cout <<"Tamanho do arranjo = " << array.getSize() << endl;
    std::cout << "Digite o valor da constante: ";
    std::cin >> constante;
    getchar();
    std::cout << "Digite a posicao de inicio: ";
    std::cin >> inicio;
    getchar();
    std::cout << "Digite a posicao de fim: ";
    std::cin >> fim;
    getchar();

    printArray(array);

    if(inicio >= 0 && fim < array.getSize() && inicio < fim){
        array.scalar(constante, inicio, fim);
        printArray(array);
    } else {
        std::cout << "Valor invalido..." << endl;
    }

    std::cout << "\nAperte enter para finalizar METODO 1119" << endl;
    getchar();
}

void metodo1120(){
    std::cout << "METODO 1120\n" << endl;
    RandArrayGenerator array;
    array = readArrayFromFile("DADOS.txt");

    printArray(array);
    array.sortDown();
    printArray(array);

    std::cout << "\nAperte enter para finalizar METODO 1120" << endl;
    getchar();
}

int arrayDiferente(RandArrayGenerator array1, RandArrayGenerator array2){
    if(array1.getSize() != array2.getSize()){
        return -1;
    }

    int tamanho = array1.getSize();
    int * arrayTemp1 = new int[tamanho];
    int * arrayTemp2 = new int[tamanho];
    arrayTemp1 = array1.getValue();
    arrayTemp2 = array2.getValue();
    for(int i = 0; i < tamanho; i++){
        if(arrayTemp1[i] != arrayTemp2[i]){
            return 1;
        }
    }

    return 0;
}

void metodo11E1(){
    std::cout << "METODO 11E1\n" << endl;
    RandArrayGenerator array1, array2;
    array1 = readArrayFromFile("DADOS.txt");

    //criando arranjo para comparar com o array do arquivo - apenas para teste
    int tamanho = array1.getSize();
    int *tempArray = new int[tamanho];
    for(int i = 0; i < tamanho; i++){
        tempArray[i] = i+1;
    }

    array2.setValues(tempArray, tamanho);

    printArray(array1);
    printArray(array2);

    int diferente;
    diferente = arrayDiferente(array1, array2);
    if(diferente == 1){
        std::cout << "Sao diferentes" << endl;
    } else if(diferente == 0){
        std::cout << "Sao iguais" << endl;
    } else {
        std::cout << "Invalido" << endl;
    }

    std::cout << "\nAperte enter para finalizar METODO 11E1" << endl;
    getchar();
}

RandArrayGenerator arraySubtracao(RandArrayGenerator array1, RandArrayGenerator array2){
    if(array1.getSize() != array2.getSize()){
        exit(1);
    }

    int tamanho = array1.getSize();
    int *temp = new int[tamanho];
    int *tempArray1 = array1.getValue();
    int *tempArray2 = array2.getValue();
    RandArrayGenerator array3;
    for(int i = 0; i < tamanho; i++){
          temp[i] = tempArray1[i] - tempArray2[i];
    }
    array3.setValues(temp, tamanho);
    return array3;
}

void metodo11E2(){
    std::cout << "METODO 11E2\n" << endl;
    RandArrayGenerator array1, array2, array3;
    array1 = readArrayFromFile("DADOS.txt");

    //criando arranjo para comparar com o array do arquivo - apenas para teste
    int tamanho = array1.getSize();
    int *tempArray = new int[tamanho];
    for(int i = 0; i < tamanho; i++){
        tempArray[i] = i;
    }

    array2.setValues(tempArray, tamanho);

    printArray(array1);
    printArray(array2);

    array3 = arraySubtracao(array1, array2);
    printArray(array3);

    std::cout << "\nAperte enter para finalizar METODO 11E2" << endl;
    getchar();
}

 int main(void){
    int opcao;
  do{
    std::cout << "\n\nEscolha uma das opcoes abaixo: \n";
    std::cout << "\n\t0: Sair";
    std::cout << "\n\t1: Metodo1111";
    std::cout << "\n\t2: Metodo1112";
    std::cout << "\n\t3: Metodo1113";
    std::cout << "\n\t4: Metodo1114";
    std::cout << "\n\t5: Metodo1115";
    std::cout << "\n\t6: Metodo1116";
    std::cout << "\n\t7: Metodo1117";
    std::cout << "\n\t8: Metodo1118";
    std::cout << "\n\t9: Metodo1119";
    std::cout << "\n\t10: Metodo1120";
    std::cout << "\n\t11: Metodo11E1";
    std::cout << "\n\t12: Metodo11E2\n";
    std::cin >> opcao;
    getchar();

    switch(opcao){
        case 0:
            break;
        case 1:
            metodo1111();
            break;
        case 2:
            metodo1112();
            break;
        case 3:
            metodo1113();
            break;
        case 4:
            metodo1114();
            break;
        case 5:
            metodo1115();
            break;
        case 6:
            metodo1116();
            break;
        case 7:
            metodo1117();
            break;
        case 8:
            metodo1118();
            break;
        case 9:
            metodo1118();
            break;
        case 10:
            metodo1118();
            break;
        case 11:
            metodo11E1();
            break;
        case 12:
            metodo11E2();
            break;

        default:
            std::cout << "Opcao invalida!\n";
            break;
    }

  } while(opcao != 0);

return 0;
 }

//substituto de getchar (mas tambem pode usar getchar)
//getchar funciona melhor
//std::cin.get()
