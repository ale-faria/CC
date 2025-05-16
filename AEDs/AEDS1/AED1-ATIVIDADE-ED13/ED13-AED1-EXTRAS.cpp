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

    // Método privado para verificar se o telefone é válido
    bool isPhoneValid(const std::string& phone) const {
        for (char c : phone) {
            if (!std::isdigit(c) && c != '-') {
                return false;
            }
        }
        return true;
    }

public:
    // Construtor padrão
    Contato() : numTelefones(0) {}

    // Construtor com parâmetros
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

    // Método para ler o nome do teclado e atribuir ao atributo nome
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

    // Método para testar a leitura do nome
    void printName() const {
        if (!nome.empty()) {
            std::cout << "Nome: " << nome << std::endl;
        } else {
            std::cerr << "O nome ainda nao foi definido." << std::endl;
        }
    }

    // Método para ler os telefones do teclado e atribuir ao array de telefones
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

    // Método para testar a leitura dos telefones
    void printPhones() const {
        for (int i = 0; i < numTelefones; i++) {
            std::cout << "Telefone " << (i + 1) << ": " << telefones[i] << std::endl;
        }
    }

    // Método para ler dados de um arquivo
    void readFromFile(const std::string& fileName) {
        std::ifstream file(fileName);

        if (!file) {
            std::cerr << "Erro: Nao foi possível abrir o arquivo " << fileName << std::endl;
            return;
        }

        std::string line;
        numTelefones = 0;

        if (std::getline(file, line) && !line.empty()) {
            nome = line;
        } else {
            std::cerr << "Erro: O nome no arquivo está vazio." << std::endl;
            return;
        }

        while (std::getline(file, line) && numTelefones < 10) {
            if (!line.empty() && isPhoneValid(line)) {
                telefones[numTelefones++] = line;
            } else {
                std::cerr << "Erro: Telefone inválido ou linha vazia no arquivo." << std::endl;
            }
        }

        if (std::getline(file, line) && !line.empty()) {
            enderecoResidencial = line;
        } else {
            std::cerr << "Erro: Endereço residencial inválido ou linha vazia no arquivo." << std::endl;
        }

        if (std::getline(file, line) && !line.empty()) {
            enderecoProfissional = line;
        } else {
            std::cerr << "Erro: Endereço profissional inválido ou linha vazia no arquivo." << std::endl;
        }

        file.close();
    }

    // Método para gravar dados em um arquivo
    void writeToFile(const std::string& fileName) const {
        std::ofstream file(fileName);

        if (!file) {
            std::cerr << "Erro: Não foi possível abrir o arquivo " << fileName << std::endl;
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

    // Método para obter o número de telefones associados ao objeto
    int phones() const {
        return numTelefones;
    }

    // Método para adicionar um telefone
    void addPhone(const std::string& phone) {
        if (numTelefones >= 10) {
            std::cerr << "Erro: Não é possível adicionar mais telefones. Limite atingido." << std::endl;
        } else if (isPhoneValid(phone)) {
            telefones[numTelefones++] = phone;
            std::cout << "Telefone adicionado com sucesso!" << std::endl;
        } else {
            std::cerr << "Erro: O telefone fornecido é inválido." << std::endl;
        }
    }

    // Método para alterar o valor de um telefone específico
    void setPhone(int index, const std::string& phone) {
        if (index < 1 || index > numTelefones) {
            std::cerr << "Erro: Índice inválido." << std::endl;
        } else if (!isPhoneValid(phone)) {
            std::cerr << "Erro: O telefone fornecido é inválido." << std::endl;
        } else {
            telefones[index - 1] = phone;
            std::cout << "Telefone " << index << " alterado com sucesso!" << std::endl;
        }
    }

    // Método para remover o valor de um telefone específico
    void removePhone(int index) {
        if (index < 1 || index > numTelefones) {
            std::cerr << "Erro: Índice inválido." << std::endl;
        } else {
            for (int i = index - 1; i < numTelefones - 1; i++) {
                telefones[i] = telefones[i + 1];
            }
            telefones[--numTelefones].clear();
            std::cout << "Telefone " << index << " removido com sucesso!" << std::endl;
        }
    }

    // Método para definir o endereço residencial
    void setEnderecoResidencial(const std::string& endereco) {
        enderecoResidencial = endereco;
        std::cout << "Endereço residencial atualizado com sucesso!" << std::endl;
    }

    // Método para obter o endereço residencial
    std::string getEnderecoResidencial() const {
        return enderecoResidencial;
    }

    // Método para definir o endereço profissional
    void setEnderecoProfissional(const std::string& endereco) {
        enderecoProfissional = endereco;
        std::cout << "Endereço profissional atualizado com sucesso!" << std::endl;
    }

    // Método para obter o endereço profissional
    std::string getEnderecoProfissional() const {
        return enderecoProfissional;
    }

    // Método para testar a leitura dos endereços
    void printEnderecos() const {
        std::cout << "Endereço Residencial: " << enderecoResidencial << std::endl;
        std::cout << "Endereço Profissional: " << enderecoProfissional << std::endl;
    }
};

int main(void) {
    // Criando um objeto Contato usando o novo construtor
    Contato contato1("nome1", {"99999-1111", "98888-2222", "97777-3333"}, "Rua A, 123", "Av. B, 456");
    contato1.printName();
    contato1.printPhones();
    contato1.printEnderecos();
    std::cout << "Número de telefones: " << contato1.phones() << std::endl;

    // Criar um novo objeto e ler dados do teclado
    Contato contato2;
    contato2.readName("Digite o nome: ");
    contato2.readPhones("Digite o telefone");
    contato2.printName();
    contato2.printPhones();
    contato2.printEnderecos();
    std::cout << "Número de telefones: " << contato2.phones() << std::endl;

    // Testar a funcionalidade de adicionar um telefone
    contato2.addPhone("96666-4444");
    contato2.printPhones();
    std::cout << "Número de telefones: " << contato2.phones() << std::endl;

    // Testar a funcionalidade de alterar um telefone
    contato2.setPhone(2, "95555-5555");
    contato2.printPhones();
    std::cout << "Número de telefones: " << contato2.phones() << std::endl;

    // Testar a funcionalidade de remover um telefone
    contato2.removePhone(2);
    contato2.printPhones();
    std::cout << "Número de telefones: " << contato2.phones() << std::endl;

    // Testar a funcionalidade de definir endereços
    contato2.setEnderecoResidencial("Rua C, 789");
    contato2.setEnderecoProfissional("Av. D, 101");
    contato2.printEnderecos();

    // Testar a funcionalidade de obter endereços
    std::cout << "Endereço Residencial: " << contato2.getEnderecoResidencial() << std::endl;
    std::cout << "Endereço Profissional: " << contato2.getEnderecoProfissional() << std::endl;

    return 0;
}
