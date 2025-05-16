/*
    AED1 - ED13
    AUTORIA: ALESSANDRA FARIA RODRIGUES
    NUM. MATRICULA: 828333
*/

#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

class Contato{
private:
    std::string nome;
    std::string telefone;
    std::string telefone2;
    int numTelefones;

    // Método privado para verificar se o telefone é válido
    bool isPhoneValid(const std::string phone){
        for(char c : phone){
            if(!isdigit(c) && c != '-'){
                return false; // Retorna falso se encontrar um caractere inválido
            }
        }
        return true; // Retorna verdadeiro se todos os caracteres forem dígitos ou '-'
    }

public:
    Contato () { numTelefones = 0; }

    Contato(std::string nome, std::string telefone){
        this->nome = nome;
        this->telefone = telefone;

        numTelefones = 0;
        if (!telefone.empty()) {
            numTelefones++;
        }
    }

    Contato(std::string nome, std::string telefone, std::string telefone2){
        this->nome = nome;
        this->telefone = telefone;
        this->telefone2 = telefone2;

        numTelefones = 0;
        if (!telefone.empty()) {
            numTelefones++;
        }
        if (!telefone2.empty()) {
            numTelefones++;
        }
    }

    // Método para ler o nome do teclado e atribuir ao atributo nome
    void readName(const std::string prompt){
        std::string input;
        std::cout << prompt;
        std::getline(std::cin, input);

        //verificando se o nome nao esta vazio
        if(!input.empty()){
            this->nome = input;
        } else {
            std::cerr << "Erro: O nome nao pode estar vazio." << std::endl;
        }
    }

    // Método para testar a leitura do nome
    void printName() const {
        if (!nome.empty()) {
            std::cout << "Nome: " << nome << std::endl;
        } else {
            std::cerr << "O nome ainda nao foi definido." << std::endl;
        }
    }

    // Método para ler o telefone do teclado e atribuir ao atributo telefone
    void readPhone(const std::string prompt1){
        std::string input1;
        std::cout << prompt1;
        std::getline(std::cin, input1);

        numTelefones = 0;
        if (!input1.empty() && isPhoneValid(input1)) {
            telefone = input1;
            numTelefones++;
        } else {
            std::cerr << "Erro: O primeiro telefone é inválido ou está vazio." << std::endl;
        }

    }

    void readPhone(const std::string prompt1, const std::string prompt2){
        std::string input1, input2;
        std::cout << prompt1;
        std::getline(std::cin, input1);
        std::cout << prompt2;
        std::getline(std::cin, input2);

        numTelefones = 0;
        if (!input1.empty() && isPhoneValid(input1)) {
            telefone = input1;
            numTelefones++;
        } else {
            std::cerr << "Erro: O primeiro telefone é inválido ou está vazio." << std::endl;
        }

        if (!input2.empty() && isPhoneValid(input2)) {
            telefone2 = input2;
            numTelefones++;
        } else {
            std::cerr << "Erro: O segundo telefone é inválido ou está vazio." << std::endl;
        }
    }

    // Método para testar a leitura do telefone
    void printPhone() const {
        if (!telefone.empty()) {
            std::cout << "Telefone: " << telefone << std::endl;
        } else {
            std::cerr << "O telefone ainda nao foi definido." << std::endl;
        }

        if (!telefone2.empty()) {
            std::cout << "Telefone 2: " << telefone2 << std::endl;
        } else {
            std::cerr << "O segundo telefone ainda nao foi definido." << std::endl;
        }
    }

    // Método para testar a validade do telefone diretamente
    void testPhoneValidity(const std::string phone) {
        if (!telefone.empty()) {
            std::cout << "Telefone 1: " << telefone << std::endl;
        } else {
            std::cerr << "O primeiro telefone ainda nao foi definido." << std::endl;
        }

        if (!telefone2.empty()) {
            std::cout << "Telefone 2: " << telefone2 << std::endl;
        } else {
            std::cerr << "O segundo telefone ainda nao foi definido." << std::endl;
        }
    }

    // Método para ler dados de um arquivo
    void readFromFile(const std::string fileName){
        std::ifstream file(fileName);

        if(!file){
            std::cerr << "Erro: Nao foi possivel abrir o arquivo " << fileName << std::endl;
            return;
        }

        numTelefones = 0;
        std::string line;
        if(std::getline(file, line) && !line.empty()){
            this->nome = line;
        } else {
            std::cerr << "Erro: O nome no arquivo esta vazio." << std::endl;
            return;
        }

        if (std::getline(file, line) && !line.empty() && isPhoneValid(line)) {
            telefone = line;
            numTelefones++;
        } else {
            std::cerr << "Erro: O primeiro telefone no arquivo e invalido ou esta vazio." << std::endl;
        }

        if (std::getline(file, line) && !line.empty() && isPhoneValid(line)) {
            telefone2 = line;
            numTelefones++;
        } else {
            std::cerr << "Erro: O segundo telefone no arquivo e invalido ou esta vazio." << std::endl;
        }

        file.close();
        std::cout << "Arquivo lido!" << std::endl;
    }

    // Método para gravar dados em um arquivo
    void writeToFile(const std::string& fileName) const {
        std::ofstream file(fileName);

        if (!file) {
            std::cerr << "Erro: Não foi possível abrir o arquivo " << fileName << std::endl;
            return;
        }

        std::string data = nome + "\n" + telefone + "\n" + telefone2 + "\n";
        size_t dataSize = data.size();

        file << dataSize << "\n";
        file << data;

        file.close();
        std::cout<< "Gravado no arquivo!" << std::endl;
    }

    // Método para obter o número de telefones associados ao objeto
    int phones(){
        return numTelefones;
    }

    // Método para atribuir valor ao segundo telefone
    void setPhone2a(const std::string phone) {
        if (isPhoneValid(phone)) {
            if (telefone2.empty()) {
                std::string response;
                std::cout << "Voce so tem um telefone. Deseja adicionar o segundo telefone? (s/n): ";
                std::getline(std::cin, response);
                if (response == "s" || response == "S") {
                    telefone2 = phone;
                    numTelefones++;
                    std::cout << "Segundo telefone adicionado com sucesso!" << std::endl;
                } else {
                    std::cout << "Operacao cancelada." << std::endl;
                }
            } else {
                telefone2 = phone;
                std::cout << "Segundo telefone atualizado com sucesso!" << std::endl;
            }
        } else {
            std::cerr << "Erro: O telefone fornecido é inválido." << std::endl;
        }
    }

    // Método para alterar o valor do segundo telefone
    void setPhone2b(const std::string phone) {
        if (numTelefones < 2) {
            std::cerr << "Erro: O contato nao possui dois telefones." << std::endl;
        } else if (!isPhoneValid(phone)) {
            std::cerr << "Erro: O telefone fornecido é inválido." << std::endl;
        } else {
            telefone2 = phone;
            std::cout << "Segundo telefone alterado com sucesso!" << std::endl;
        }
    }

    // Método para remover o valor do segundo telefone
    void setPhone2c() {
        if (numTelefones < 2) {
            std::cerr << "Erro: O contato so possui um telefone." << std::endl;
        } else {
            telefone2.clear();
            numTelefones--;
            std::cout << "Segundo telefone removido com sucesso!" << std::endl;
        }
    }

};

void metodo1311(){
    std::cout << "METODO 1311\n" <<std::endl;
    Contato contato1;
    contato1.readName("Digite o nome: ");
    contato1.printName();
}

void metodo1312(){
    std::cout << "METODO 1312\n" <<std::endl;
    Contato contato1;
    contato1.readPhone("Digite o telefone: ");
    contato1.printPhone();
}

void metodo1313(){
    std::cout << "METODO 1313\n" <<std::endl;
    Contato contato1;
    contato1.testPhoneValidity("123-456-7890"); // válido
    contato1.testPhoneValidity("123-ABC-7890"); // inválido

}

void metodo1314(){
    std::cout << "METODO 1314\n" <<std::endl;
    Contato contato1;
    contato1.readFromFile("Pessoa1.txt");
    contato1.printName();
    contato1.printPhone();
}

void metodo1315(){
    std::cout << "METODO 1315\n" <<std::endl;
    Contato contato1;
    contato1.readName("Digite o nome: ");
    contato1.readPhone("Digite o telefone: ");
    contato1.writeToFile("Pessoa2.txt");
}

void metodo1316(){
    std::cout << "METODO 1316\n" <<std::endl;
    Contato contato1( "nome1", "99999-1111", "98888-2222" );
    contato1.printName();
    contato1.printPhone();
}

void metodo1317(){
    std::cout << "METODO 1317\n" <<std::endl;
    Contato contato1( "nome1", "99999-1111" );
    contato1.printName();
    contato1.printPhone();
    std::cout << "Numero de telefones: " << contato1.phones() << "\n" << std::endl;

    Contato contato2( "nome2", "99999-1111",  "98888-2222" );
    contato2.printName();
    contato2.printPhone();
    std::cout << "Numero de telefones: " << contato2.phones() << std::endl;
}

void metodo1318(){
    std::cout << "METODO 1318\n" <<std::endl;
    Contato contato1( "nome1", "99999-1111" );
    contato1.setPhone2a("97777-3333");
    contato1.printPhone();
    std::cout << "Numero de telefones: " << contato1.phones() << "\n" << std::endl;
}

void metodo1319(){
    std::cout << "METODO 1319\n" <<std::endl;
    Contato contato1( "nome1", "99999-1111", "97777-3333" );
    contato1.printPhone();
    contato1.setPhone2b("97777-4444");
    contato1.printPhone();
    std::cout << "Numero de telefones: " << contato1.phones() << std::endl;
}

void metodo1320(){
    std::cout << "METODO 1320\n" <<std::endl;
    Contato contato1( "nome1", "99999-1111", "97777-3333" );
    contato1.printName();
    contato1.printPhone();
    contato1.setPhone2c();
    contato1.printPhone();
}

int main(void){
    int opcao;
  do{
    std::cout << "\n\nEscolha uma das opcoes abaixo: \n";
    std::cout << "\n\t0: Sair";
    std::cout << "\n\t1: Metodo1311";
    std::cout << "\n\t2: Metodo1312";
    std::cout << "\n\t3: Metodo1313";
    std::cout << "\n\t4: Metodo1314";
    std::cout << "\n\t5: Metodo1315";
    std::cout << "\n\t6: Metodo1316";
    std::cout << "\n\t7: Metodo1317";
    std::cout << "\n\t8: Metodo1318";
    std::cout << "\n\t9: Metodo1319";
    std::cout << "\n\t10: Metodo1320\n";
    std::cin >> opcao;
    getchar();

    switch(opcao){
        case 0:
            break;
        case 1:
            metodo1311();
            break;
        case 2:
            metodo1312();
            break;
        case 3:
            metodo1313();
            break;
        case 4:
            metodo1314();
            break;
        case 5:
            metodo1315();
            break;
        case 6:
            metodo1316();
            break;
        case 7:
            metodo1317();
            break;
        case 8:
            metodo1318();
            break;
        case 9:
            metodo1319();
            break;
        case 10:
            metodo1320();
            break;


        default:
            std::cout << "Opcao invalida!\n";
            break;
    }

  } while(opcao != 0);

return 0;
}
