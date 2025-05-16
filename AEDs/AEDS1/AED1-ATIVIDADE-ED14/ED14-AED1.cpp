 /*
    AED1 - ED14
    AUTORIA: ALESSANDRA FARIA RODRIGUES
    NUM. MATRICULA: 828333
*/

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

/**
 * Função para converter conteúdo de string para valor inteiro, se possível.
 * @param str String a ser convertida para inteiro.
 * @return valor inteiro equivalente, se válido;
 *         (-1), caso contrário.
 */
int getInt(const std::string &str) {
    int result = 0;
    bool negative = false;
    size_t start = 0;

    if (str.empty()) {
        return -1;
    }

    if (str[0] == '-') {
        negative = true;
        start = 1;
    }

    for (size_t i = start; i < str.length(); ++i) {
        if (!std::isdigit(str[i])) {
            return -1;
        }
        result = result * 10 + (str[i] - '0');
    }

    return negative ? -result : result;
}

/**
 * Função para converter conteúdo de string para valor real, se possível.
 * @param str String a ser convertida para real.
 * @return valor real equivalente, se válido;
 *         (0.0), caso contrário.
 */
double getDouble(const std::string &str) {
    double result = 0.0;
    bool negative = false;
    bool decimalPointSeen = false;
    double decimalFactor = 0.1;
    size_t start = 0;

    if (str.empty()) {
        return 0.0;
    }

    if (str[0] == '-') {
        negative = true;
        start = 1;
    }

    for (size_t i = start; i < str.length(); ++i) {
        if (std::isdigit(str[i])) {
            if (decimalPointSeen) {
                result += (str[i] - '0') * decimalFactor;
                decimalFactor *= 0.1;
            } else {
                result = result * 10 + (str[i] - '0');
            }
        } else if (str[i] == '.') {
            if (decimalPointSeen) {
                return 0.0;
            }
            decimalPointSeen = true;
        } else {
            return 0.0;
        }
    }

    return negative ? -result : result;
}

/**
 * Função para converter conteúdo de string para valor lógico, se possível.
 * Nota: Considerar válidos: { true, false, T, F, 0, 1 }
 * @param str String a ser convertida para valor lógico.
 * @return valor lógico equivalente, se válido;
 *         false, caso contrário.
 */
bool getBoolean(const std::string &str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);

    if (lowerStr == "true" || lowerStr == "t" || lowerStr == "1") {
        return true;
    } else if (lowerStr == "false" || lowerStr == "f" || lowerStr == "0") {
        return false;
    }

    return false;
}

/**
 * Função para verificar se o parâmetro está contido no conteúdo.
 * @param texto String a ser verificada.
 * @param substr Substring a ser procurada no texto.
 * @return true, se contiver (em qualquer posição);
 *         false, caso contrário.
 */
bool contains(const std::string &texto, const std::string &substr) {
    if (substr.empty() || texto.size() < substr.size()) {
        return false;
    }

    for (size_t i = 0; i <= texto.size() - substr.size(); ++i) {
        if (texto.substr(i, substr.size()) == substr) {
            return true;
        }
    }

    return false;
}

/**
 * Função para converter letras de uma string para maiúsculas.
 * @param str String a ser convertida para maiúsculas.
 * @return valor equivalente em maiúsculas, se houver;
 *         o próprio valor, caso contrário.
 */
std::string toUpperCase(const std::string &str) {
    std::string upperStr = str;
    for (char &c : upperStr) {
        if (c >= 'a' && c <= 'z') {
            c = c - ('a' - 'A');
        }
    }
    return upperStr;
}

/**
 * Função para converter letras de uma string para minúsculas.
 * @param str String a ser convertida para minúsculas.
 * @return valor equivalente em minúsculas, se houver;
 *         o próprio valor, caso contrário.
 */
std::string toLowerCase(const std::string &str) {
    std::string lowerStr = str;
    for (char &c : lowerStr) {
        if (c >= 'A' && c <= 'Z') {
            c = c + ('a' - 'A');
        }
    }
    return lowerStr;
}

/**
 * Função para trocar todas as ocorrências de certo caractere por outro novo.
 * @param str String onde as trocas serão feitas.
 * @param original Caractere a ser substituído.
 * @param novo Novo caractere que substituirá o original.
 * @return valor com substituições, se houver;
 *         o próprio valor, caso contrário.
 */
std::string replace(const std::string &str, char original, char novo) {
    std::string replacedStr = str;
    for (char &c : replacedStr) {
        if (c == original) {
            c = novo;
        }
    }
    return replacedStr;
}

/**
 * Função para codificar o conteúdo segundo a cifra de César.
 * @param texto Texto a ser codificado.
 * @param shift Quantidade de posições a serem deslocadas no alfabeto.
 * @return valor equivalente codificado, se houver;
 *         o próprio valor, caso contrário.
 */
std::string encrypt(const std::string &texto, int shift) {
    std::string resultado = texto;

    for (char &c : resultado) {
        if (isalpha(c)) { // Verifica se o caractere é uma letra
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + shift) % 26 + base;
        }
    }

    return resultado;
}

/**
 * Função para decodificar o conteúdo previamente cifrado pela função acima.
 * @param texto Texto a ser decodificado.
 * @param shift Quantidade de posições a serem deslocadas no alfabeto.
 * @return valor equivalente decodificado, se houver;
 *         o próprio valor, caso contrário.
 */
std::string decrypt(const std::string &texto, int shift) {
    // Para decodificar, usamos o deslocamento negativo
    return encrypt(texto, 26 - shift);
}

/**
 * Função para separar todas as sequências de caracteres separadas por espaços em branco.
 * @param str String a ser separada.
 * @param sequencia Arranjo para armazenar possíveis cadeias de caracteres identificadas.
 * @return Quantidade de sequências de caracteres identificadas, se houver;
 *         zero, caso contrário.
 */
int split(const std::string &str, std::string sequencia[]) {
    int count = 0;
    size_t start = 0, end = 0;
    size_t len = str.length();

    while (start < len) {
        // Ignora espaços iniciais
        while (start < len && str[start] == ' ') {
            start++;
        }

        // Encontra o próximo espaço
        end = start;
        while (end < len && str[end] != ' ') {
            end++;
        }

        // Se encontrar uma palavra, adiciona ao array
        if (start < end) {
            sequencia[count++] = str.substr(start, end - start);
            start = end;
        }
    }

    return count;
}

/**
 * Função para separar todas as sequências de caracteres separadas por um delimitador.
 * @param str String a ser separada.
 * @param sequencia Arranjo para armazenar possíveis cadeias de caracteres identificadas.
 * @param delimitador Caractere usado como delimitador.
 * @return Quantidade de sequências de caracteres identificadas, se houver;
 *         zero, caso contrário.
 */
int split2(const std::string &str, std::string sequencia[], char delimitador) {
    int count = 0;
    size_t start = 0, end = 0;
    size_t len = str.length();

    while (start < len) {
        // Encontra o próximo delimitador
        end = str.find(delimitador, start);

        // Se não encontrar mais delimitadores, ajusta o final para o final da string
        if (end == std::string::npos) {
            end = len;
        }

        // Se encontrar uma palavra, adiciona ao array
        if (start < end) {
            sequencia[count++] = str.substr(start, end - start);
        }

        // Ajusta start para o próximo caractere após o delimitador
        start = end + 1;
    }

    return count;
}

/**
 * Função para inverter a ordem dos símbolos na cadeia de caracteres.
 * @param str String a ser invertida.
 * @return String com os símbolos em ordem inversa.
 */
std::string reverse(const std::string &str) {
    std::string resultado;
    for (int i = str.length() - 1; i >= 0; --i) {
        resultado += str[i];
    }
    return resultado;
}


//procedimento para testar a função getDouble
void test01(){
    //TESTES
    std::cout << "INICIO TESTE 01 [getInt]\n" <<std::endl;
    std::string test1 = "123";
    std::string test2 = "-456";
    std::string test3 = "78a9";
    std::string test4 = "";
    std::string test5 = "0";

    std::cout << "Teste 1: " << test1 << " -> " << getInt(test1) << std::endl;
    std::cout << "Teste 2: " << test2 << " -> " << getInt(test2) << std::endl;
    std::cout << "Teste 3: " << test3 << " -> " << getInt(test3) << std::endl;
    std::cout << "Teste 4: " << test4 << " -> " << getInt(test4) << std::endl;
    std::cout << "Teste 5: " << test5 << " -> " << getInt(test5) << std::endl;

    std::cout << "\nFIM TESTE 01" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();
}

//procedimento para testar a função getInt
void test02(){
    std::cout << "\nINICIO TESTE 02 [getDouble]\n" <<std::endl;
    std::string test1 = "123.456";
    std::string test2 = "-456.789";
    std::string test3 = "78.9a";
    std::string test4 = "";
    std::string test5 = "0.0";
    std::string test6 = "3.14159";
    std::string test7 = "-0.001";

    std::cout << "Teste 1: " << test1 << " -> " << getDouble(test1) << std::endl;
    std::cout << "Teste 2: " << test2 << " -> " << getDouble(test2) << std::endl;
    std::cout << "Teste 3: " << test3 << " -> " << getDouble(test3) << std::endl;
    std::cout << "Teste 4: " << test4 << " -> " << getDouble(test4) << std::endl;
    std::cout << "Teste 5: " << test5 << " -> " << getDouble(test5) << std::endl;
    std::cout << "Teste 6: " << test6 << " -> " << getDouble(test6) << std::endl;
    std::cout << "Teste 7: " << test7 << " -> " << getDouble(test7) << std::endl;

    std::cout << "\nFIM TESTE 02" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();
}

//procedimento para testar a função getBoolean
void test03(){
    std::cout << "\nINICIO TESTE 03 [getBoolean]\n" <<std::endl;

    std::string test1 = "true";
    std::string test2 = "false";
    std::string test3 = "T";
    std::string test4 = "F";
    std::string test5 = "1";
    std::string test6 = "0";
    std::string test7 = "yes";
    std::string test8 = "no";
    std::string test9 = "";
    std::string test10 = "TRUE";
    std::string test11 = "FALSE";
    std::string test12 = "tRuE";
    std::string test13 = "FaLsE";

    std::cout << "Test 1: " << test1 << " -> " << getBoolean(test1) << std::endl;
    std::cout << "Test 2: " << test2 << " -> " << getBoolean(test2) << std::endl;
    std::cout << "Test 3: " << test3 << " -> " << getBoolean(test3) << std::endl;
    std::cout << "Test 4: " << test4 << " -> " << getBoolean(test4) << std::endl;
    std::cout << "Test 5: " << test5 << " -> " << getBoolean(test5) << std::endl;
    std::cout << "Test 6: " << test6 << " -> " << getBoolean(test6) << std::endl;
    std::cout << "Test 7: " << test7 << " -> " << getBoolean(test7) << std::endl;
    std::cout << "Test 8: " << test8 << " -> " << getBoolean(test8) << std::endl;
    std::cout << "Test 9: " << test9 << " -> " << getBoolean(test9) << std::endl;
    std::cout << "Test 10: " << test10 << " -> " << getBoolean(test10) << std::endl;
    std::cout << "Test 11: " << test11 << " -> " << getBoolean(test11) << std::endl;
    std::cout << "Test 12: " << test12 << " -> " << getBoolean(test12) << std::endl;
    std::cout << "Test 13: " << test13 << " -> " << getBoolean(test13) << std::endl;

    std::cout << "\nFIM TESTE 03" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();
}

//procedimento para testar a função contains
void test04(){
    std::cout << "\nINICIO TESTE 04 [contains]\n" <<std::endl;

    std::string text1 = "Hello, world!";
    std::string substr1 = "world";
    std::string substr2 = "WORLD";
    std::string substr3 = "!";
    std::string substr4 = "Hello";
    std::string substr5 = "lo, w";
    std::string substr6 = "goodbye";

    std::cout << "\nTextos:\n";
    std::cout << "Test 1: " << "Texto: " << text1 << ", Substring: " << substr1 << " -> " << contains(text1, substr1) << std::endl;
    std::cout << "Test 2: " << "Texto: " << text1 << ", Substring: " << substr2 << " -> " << contains(text1, substr2) << std::endl;
    std::cout << "Test 3: " << "Texto: " << text1 << ", Substring: " << substr3 << " -> " << contains(text1, substr3) << std::endl;
    std::cout << "Test 4: " << "Texto: " << text1 << ", Substring: " << substr4 << " -> " << contains(text1, substr4) << std::endl;
    std::cout << "Test 5: " << "Texto: " << text1 << ", Substring: " << substr5 << " -> " << contains(text1, substr5) << std::endl;
    std::cout << "Test 6: " << "Texto: " << text1 << ", Substring: " << substr6 << " -> " << contains(text1, substr6) << std::endl;


    std::cout << "\nFIM TESTE 04" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();
}

//procedimento para testar a função toUpperCase
void test05(){
    std::cout << "\nINICIO TESTE 05 [toUpperCase]\n" <<std::endl;

    std::string upperCaseTest1 = "hello";
    std::string upperCaseTest2 = "WORLD";
    std::string upperCaseTest3 = "Hello, World!";
    std::string upperCaseTest4 = "123abc";
    std::string upperCaseTest5 = "";

    std::cout << "Test 1: " << upperCaseTest1 << " -> " << toUpperCase(upperCaseTest1) << std::endl;
    std::cout << "Test 2: " << upperCaseTest2 << " -> " << toUpperCase(upperCaseTest2) << std::endl;
    std::cout << "Test 3: " << upperCaseTest3 << " -> " << toUpperCase(upperCaseTest3) << std::endl;
    std::cout << "Test 4: " << upperCaseTest4 << " -> " << toUpperCase(upperCaseTest4) << std::endl;
    std::cout << "Test 5: " << upperCaseTest5 << " -> " << toUpperCase(upperCaseTest5) << std::endl;

    std::cout << "\nFIM TESTE 05" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();
}

//procedimento para testar a função toLowerCase
void test06(){
    std::cout << "\nINICIO TESTE 06 [toLowerCase]\n" <<std::endl;

    std::string lowerCaseTest1 = "HELLO";
    std::string lowerCaseTest2 = "world";
    std::string lowerCaseTest3 = "Hello, World!";
    std::string lowerCaseTest4 = "123ABC";
    std::string lowerCaseTest5 = "";

    std::cout << "\ntoLowerCase Tests:\n";
    std::cout << "Test 1: " << lowerCaseTest1 << " -> " << toLowerCase(lowerCaseTest1) << std::endl;
    std::cout << "Test 2: " << lowerCaseTest2 << " -> " << toLowerCase(lowerCaseTest2) << std::endl;
    std::cout << "Test 3: " << lowerCaseTest3 << " -> " << toLowerCase(lowerCaseTest3) << std::endl;
    std::cout << "Test 4: " << lowerCaseTest4 << " -> " << toLowerCase(lowerCaseTest4) << std::endl;
    std::cout << "Test 5: " << lowerCaseTest5 << " -> " << toLowerCase(lowerCaseTest5) << std::endl;

    std::cout << "\nFIM TESTE 06" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();
}

//procedimento para testar a função replace
void test07(){
    std::cout << "\nINICIO TESTE 07 [replace]\n" <<std::endl;

     std::string testStr1 = "banana";
    char original1 = 'a';
    char novo1 = 'o';

    std::string testStr2 = "Hello, world!";
    char original2 = 'o';
    char novo2 = '*';

    std::cout << "Test 1: " << testStr1 << " (replace '" << original1 << "' -> '" << novo1 << "') -> " << replace(testStr1, original1, novo1) << std::endl;
    std::cout << "Test 2: " << testStr2 << " (replace '" << original2 << "' -> '" << novo2 << "') -> " << replace(testStr2, original2, novo2) << std::endl;

    std::cout << "\nFIM TESTE 07" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();

}

//procedimento para testar a função encrypt e decrypt
void test08_09(){
    std::cout << "\nINICIO TESTE 08 e 09 [encrypt e decrypt]\n" <<std::endl;

    std::string textoOriginal = "Hello, World!";
    int deslocamento = 3;

    std::cout << "Texto original: " << textoOriginal << std::endl;
    std::string textoCodificado = encrypt(textoOriginal, deslocamento);
    std::cout << "Texto codificado com deslocamento " << deslocamento << ": " << textoCodificado << std::endl;

     std::string textoDecodificado = decrypt(textoCodificado, deslocamento);
    std::cout << "Texto decodificado: " << textoDecodificado << std::endl;

    std::cout << "\nFIM TESTE 08 e 09" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();
}

//procedimento para testar a função split
void test10(){
    std::cout << "\nINICIO TESTE 10 [split]\n" <<std::endl;

    std::string texto = "This is a test string";
    std::string palavras[10]; // Supondo que não haverá mais de 10 palavras
    int quantidade = split(texto, palavras);

    std::cout << "Texto original: \"" << texto << "\"" << std::endl;
    std::cout << "Quantidade de palavras: " << quantidade << std::endl;
    std::cout << "Palavras:" << std::endl;
    for (int i = 0; i < quantidade; ++i) {
        std::cout << palavras[i] << std::endl;
    }

    std::cout << "\nFIM TESTE 10" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();
}

//procedimento para testar a função split2
void testExtra01(){
    std::cout << "\nINICIO TESTE EXTRA 01 [split2]\n" <<std::endl;

// Testes com vírgula como delimitador
    std::string texto2 = "apple,banana,orange,grape";
    std::string palavras2[10]; // Supondo que não haverá mais de 10 palavras
    int quantidade2 = split2(texto2, palavras2, ',');

    std::cout << "\nTexto original: \"" << texto2 << "\"" << std::endl;
    std::cout << "Quantidade de palavras: " << quantidade2 << std::endl;
    std::cout << "Palavras:" << std::endl;
    for (int i = 0; i < quantidade2; ++i) {
        std::cout << palavras2[i] << std::endl;
    }

    // Testes com ponto e vírgula como delimitador
    std::string texto3 = "John;Doe;Jane;Smith";
    std::string palavras3[10]; // Supondo que não haverá mais de 10 palavras
    int quantidade3 = split2(texto3, palavras3, ';');

    std::cout << "\nTexto original: \"" << texto3 << "\"" << std::endl;
    std::cout << "Quantidade de palavras: " << quantidade3 << std::endl;
    std::cout << "Palavras:" << std::endl;
    for (int i = 0; i < quantidade3; ++i) {
        std::cout << palavras3[i] << std::endl;
    }

    std::cout << "\nFIM TESTE EXTRA 01" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();
}

//procedimento para testar a função reverse
void testExtra02(){
    std::cout << "\nINICIO TESTE EXTRA 02 [reverse]\n" <<std::endl;

    std::string texto4 = "abcdef";
    std::string textoReverso = reverse(texto4);

    std::cout << "\nTexto original: \"" << texto4 << "\"" << std::endl;
    std::cout << "Texto invertido: \"" << textoReverso << "\"" << std::endl;

    std::cout << "\nFIM TESTE EXTRA 02" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();

}

int main() {
   int opcao;
  do{
    std::cout << "\n\nEscolha uma das opcoes abaixo: \n";
    std::cout << "\n\t0: Sair";
    std::cout << "\n\t1: Teste 01";
    std::cout << "\n\t2: Teste 02";
    std::cout << "\n\t3: Teste 03";
    std::cout << "\n\t4: Teste 04";
    std::cout << "\n\t5: Teste 05";
    std::cout << "\n\t6: Teste 06";
    std::cout << "\n\t7: Teste 07";
    std::cout << "\n\t8: Teste 08";
    std::cout << "\n\t9: Teste 09";
    std::cout << "\n\t10: Teste 10";
    std::cout << "\n\t11: Teste Extra01";
    std::cout << "\n\t12: Teste Extra02\n";
    std::cin >> opcao;
    getchar();

    switch(opcao){
        case 0:
            break;
        case 1:
            test01();
            break;
        case 2:
            test02();
            break;
        case 3:
            test03();
            break;
        case 4:
            test04();
            break;
        case 5:
            test05();
            break;
        case 6:
            test06();
            break;
        case 7:
            test07();
            break;
        case 8:
            test08_09();
            break;
        case 9:
            test08_09();
            break;
        case 10:
            test10();
            break;
        case 11:
            testExtra01();
            break;
        case 12:
            testExtra02();
            break;


        default:
            std::cout << "Opcao invalida!\n";
            break;
    }

  } while(opcao != 0);

return 0;
}
