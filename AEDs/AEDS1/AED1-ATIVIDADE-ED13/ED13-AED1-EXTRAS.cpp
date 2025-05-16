#include <iostream>
#include <fstream>
#include <string>
#include <array>

class Contato {
private:
    std::string nome;
    std::array<std::string, 10> telefones;
    int numTelefones;
    std::string enderecoResidencial;
    std::string enderecoProfissional;

    // M�todo privado para verificar se o telefone � v�lido
    bool isPhoneValid(const std::string& phone) const {
        for (char c : phone) {
            if (!std::isdigit(c) && c != '-') {
                return false;
            }
        }
        return true;
    }

public:
    // Construtor padr�o
    Contato() : numTelefones(0) {}

    // Construtor com par�metros
    Contato(const std::string& nome, const std::initializer_list<std::string>& tels, const std::string& enderecoRes, const std::string& enderecoProf)
        : nome(nome), numTelefones(0), enderecoResidencial(enderecoRes), enderecoProfissional(enderecoProf) {
        for (const auto& tel : tels) {
            if (numTelefones < 10 && isPhoneValid(tel)) {
                telefones[numTelefones++] = tel;
            } else if (numTelefones >= 10) {
                std::cerr << "Erro: Numero maximo de telefones excedido." << std::endl;
            }
        }
    }

    // M�todo para ler o nome do teclado e atribuir ao atributo nome
    void readName(const std::string& prompt) {
        std::string input;
        std::cout << prompt;
        std::getline(std::cin, input);

        if (!input.empty()) {
            nome = input;
        } else {
            std::cerr << "Erro: O nome nao pode estar vazio." << std::endl;
        }
    }

    // M�todo para testar a leitura do nome
    void printName() const {
        if (!nome.empty()) {
            std::cout << "Nome: " << nome << std::endl;
        } else {
            std::cerr << "O nome ainda nao foi definido." << std::endl;
        }
    }

    // M�todo para ler os telefones do teclado e atribuir ao array de telefones
    void readPhones(const std::string& prompt) {
        std::string input;
        numTelefones = 0;
        for (int i = 0; i < 10; i++) {
            std::cout << prompt << " " << (i + 1) << ": ";
            std::getline(std::cin, input);
            if (!input.empty() && isPhoneValid(input)) {
                telefones[numTelefones++] = input;
            } else if (input.empty()) {
                break;
            } else {
                std::cerr << "Erro: O telefone " << (i + 1) << " e invalido." << std::endl;
            }
        }
    }

    // M�todo para testar a leitura dos telefones
    void printPhones() const {
        for (int i = 0; i < numTelefones; i++) {
            std::cout << "Telefone " << (i + 1) << ": " << telefones[i] << std::endl;
        }
    }

    // M�todo para ler dados de um arquivo
    void readFromFile(const std::string& fileName) {
        std::ifstream file(fileName);

        if (!file) {
            std::cerr << "Erro: Nao foi poss�vel abrir o arquivo " << fileName << std::endl;
            return;
        }

        std::string line;
        numTelefones = 0;

        if (std::getline(file, line) && !line.empty()) {
            nome = line;
        } else {
            std::cerr << "Erro: O nome no arquivo est� vazio." << std::endl;
            return;
        }

        while (std::getline(file, line) && numTelefones < 10) {
            if (!line.empty() && isPhoneValid(line)) {
                telefones[numTelefones++] = line;
            } else {
                std::cerr << "Erro: Telefone inv�lido ou linha vazia no arquivo." << std::endl;
            }
        }

        if (std::getline(file, line) && !line.empty()) {
            enderecoResidencial = line;
        } else {
            std::cerr << "Erro: Endere�o residencial inv�lido ou linha vazia no arquivo." << std::endl;
        }

        if (std::getline(file, line) && !line.empty()) {
            enderecoProfissional = line;
        } else {
            std::cerr << "Erro: Endere�o profissional inv�lido ou linha vazia no arquivo." << std::endl;
        }

        file.close();
    }

    // M�todo para gravar dados em um arquivo
    void writeToFile(const std::string& fileName) const {
        std::ofstream file(fileName);

        if (!file) {
            std::cerr << "Erro: N�o foi poss�vel abrir o arquivo " << fileName << std::endl;
            return;
        }

        file << nome << "\n";
        for (int i = 0; i < numTelefones; i++) {
            file << telefones[i] << "\n";
        }
        file << enderecoResidencial << "\n";
        file << enderecoProfissional << "\n";

        file.close();
    }

    // M�todo para obter o n�mero de telefones associados ao objeto
    int phones() const {
        return numTelefones;
    }

    // M�todo para adicionar um telefone
    void addPhone(const std::string& phone) {
        if (numTelefones >= 10) {
            std::cerr << "Erro: N�o � poss�vel adicionar mais telefones. Limite atingido." << std::endl;
        } else if (isPhoneValid(phone)) {
            telefones[numTelefones++] = phone;
            std::cout << "Telefone adicionado com sucesso!" << std::endl;
        } else {
            std::cerr << "Erro: O telefone fornecido � inv�lido." << std::endl;
        }
    }

    // M�todo para alterar o valor de um telefone espec�fico
    void setPhone(int index, const std::string& phone) {
        if (index < 1 || index > numTelefones) {
            std::cerr << "Erro: �ndice inv�lido." << std::endl;
        } else if (!isPhoneValid(phone)) {
            std::cerr << "Erro: O telefone fornecido � inv�lido." << std::endl;
        } else {
            telefones[index - 1] = phone;
            std::cout << "Telefone " << index << " alterado com sucesso!" << std::endl;
        }
    }

    // M�todo para remover o valor de um telefone espec�fico
    void removePhone(int index) {
        if (index < 1 || index > numTelefones) {
            std::cerr << "Erro: �ndice inv�lido." << std::endl;
        } else {
            for (int i = index - 1; i < numTelefones - 1; i++) {
                telefones[i] = telefones[i + 1];
            }
            telefones[--numTelefones].clear();
            std::cout << "Telefone " << index << " removido com sucesso!" << std::endl;
        }
    }

    // M�todo para definir o endere�o residencial
    void setEnderecoResidencial(const std::string& endereco) {
        enderecoResidencial = endereco;
        std::cout << "Endere�o residencial atualizado com sucesso!" << std::endl;
    }

    // M�todo para obter o endere�o residencial
    std::string getEnderecoResidencial() const {
        return enderecoResidencial;
    }

    // M�todo para definir o endere�o profissional
    void setEnderecoProfissional(const std::string& endereco) {
        enderecoProfissional = endereco;
        std::cout << "Endere�o profissional atualizado com sucesso!" << std::endl;
    }

    // M�todo para obter o endere�o profissional
    std::string getEnderecoProfissional() const {
        return enderecoProfissional;
    }

    // M�todo para testar a leitura dos endere�os
    void printEnderecos() const {
        std::cout << "Endere�o Residencial: " << enderecoResidencial << std::endl;
        std::cout << "Endere�o Profissional: " << enderecoProfissional << std::endl;
    }
};

int main(void) {
    // Criando um objeto Contato usando o novo construtor
    Contato contato1("nome1", {"99999-1111", "98888-2222", "97777-3333"}, "Rua A, 123", "Av. B, 456");
    contato1.printName();
    contato1.printPhones();
    contato1.printEnderecos();
    std::cout << "N�mero de telefones: " << contato1.phones() << std::endl;

    // Criar um novo objeto e ler dados do teclado
    Contato contato2;
    contato2.readName("Digite o nome: ");
    contato2.readPhones("Digite o telefone");
    contato2.printName();
    contato2.printPhones();
    contato2.printEnderecos();
    std::cout << "N�mero de telefones: " << contato2.phones() << std::endl;

    // Testar a funcionalidade de adicionar um telefone
    contato2.addPhone("96666-4444");
    contato2.printPhones();
    std::cout << "N�mero de telefones: " << contato2.phones() << std::endl;

    // Testar a funcionalidade de alterar um telefone
    contato2.setPhone(2, "95555-5555");
    contato2.printPhones();
    std::cout << "N�mero de telefones: " << contato2.phones() << std::endl;

    // Testar a funcionalidade de remover um telefone
    contato2.removePhone(2);
    contato2.printPhones();
    std::cout << "N�mero de telefones: " << contato2.phones() << std::endl;

    // Testar a funcionalidade de definir endere�os
    contato2.setEnderecoResidencial("Rua C, 789");
    contato2.setEnderecoProfissional("Av. D, 101");
    contato2.printEnderecos();

    // Testar a funcionalidade de obter endere�os
    std::cout << "Endere�o Residencial: " << contato2.getEnderecoResidencial() << std::endl;
    std::cout << "Endere�o Profissional: " << contato2.getEnderecoProfissional() << std::endl;

    return 0;
}
