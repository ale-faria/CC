/*
    AED1 - ED15
    AUTORIA: ALESSANDRA FARIA RODRIGUES
    NUM. MATRICULA: 828333
*/

#include <iostream>
#include <cstring>

/**
 Funcao para acrescentar caractere ao final
 de uma cadeia de caracteres, por meio de apontador.
 @return apontador para a cadeia atualizada
 @param s - apontador para cadeia de caracteres
 @param c - caractere a ser inserido
 */
char* str_push_back(char *s, char c) {
    // Encontrar o tamanho da cadeia de caracteres original
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }

    // Alocar nova cadeia de caracteres com tamanho maior
    char* new_str = new char[length + 2]; // +1 para novo caractere e +1 para '\0'

    // Copiar cadeia original para a nova cadeia
    for (int i = 0; i < length; i++) {
        new_str[i] = s[i];
    }

    // Adicionar novo caractere ao final
    new_str[length] = c;
    new_str[length + 1] = '\0';

    return new_str;
}

/**
 Funcao para remover caractere do final
 de uma cadeia de caracteres, por meio de apontador.
 @return apontador para a cadeia atualizada
 @param s - apontador para cadeia de caracteres
 */
 char* str_pop_back(char *s) {
    // Encontrar o tamanho da cadeia de caracteres original
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }

    // Se a cadeia estiver vazia, retornar um ponteiro para uma nova cadeia vazia
    if (length == 0) {
        char* new_str = new char[1];
        new_str[0] = '\0';
        return new_str;
    }

    // Alocar nova cadeia de caracteres com tamanho menor
    char* new_str = new char[length];

    // Copiar cadeia original para a nova cadeia, exceto o último caractere
    for (int i = 0; i < length - 1; i++) {
        new_str[i] = s[i];
    }

    // Adicionar o caractere nulo no final
    new_str[length - 1] = '\0';

    return new_str;
}

/**
 Funcao para acrescentar caractere ao início
 de uma cadeia de caracteres, por meio de apontador.
 @return apontador para a cadeia atualizada
 @param c - caractere a ser inserido
 @param s - apontador para cadeia de caracteres
 */
 char* str_push_front(char c, char *s) {
    // Encontrar o tamanho da cadeia de caracteres original
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }

    // Alocar nova cadeia de caracteres com tamanho maior
    char* new_str = new char[length + 2]; // +1 para novo caractere e +1 para '\0'

    // Adicionar novo caractere na primeira posição
    new_str[0] = c;

    // Copiar cadeia original para a nova cadeia a partir da segunda posição
    for (int i = 0; i < length; i++) {
        new_str[i + 1] = s[i];
    }

    // Adicionar o caractere nulo no final
    new_str[length + 1] = '\0';

    return new_str;
}

/**
 Funcao para remover caractere do início
 de uma cadeia de caracteres, por meio de apontador.
 @return apontador para a cadeia atualizada
 @param s - apontador para cadeia de caracteres
 */
 char* str_pop_front(char *s) {
    // Encontrar o tamanho da cadeia de caracteres original
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }

    // Se a cadeia estiver vazia, retornar um ponteiro para uma nova cadeia vazia
    if (length == 0) {
        char* new_str = new char[1];
        new_str[0] = '\0';
        return new_str;
    }

    // Alocar nova cadeia de caracteres com tamanho menor
    char* new_str = new char[length];

    // Copiar cadeia original para a nova cadeia, começando do segundo caractere
    for (int i = 1; i < length; i++) {
        new_str[i - 1] = s[i];
    }

    // Adicionar o caractere nulo no final
    new_str[length - 1] = '\0';

    return new_str;
}

/**
 Funcao para inserir caractere no meio (aproximadamente)
 de uma cadeia de caracteres, por meio de apontador,
 se houver pelo menos dois caracteres.
 @return apontador para a cadeia atualizada
 @param s - apontador para cadeia de caracteres
 @param c - caractere a ser inserido
 */
 char* str_push_mid(char *s, char c) {
    // Encontrar o tamanho da cadeia de caracteres original
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }

    // Alocar nova cadeia de caracteres com tamanho maior
    char* new_str = new char[length + 2]; // +1 para novo caractere e +1 para '\0'

    // Encontrar a posição do meio
    int mid = length / 2;

    // Copiar primeira metade da cadeia original para a nova cadeia
    for (int i = 0; i < mid; i++) {
        new_str[i] = s[i];
    }

    // Inserir o novo caractere
    new_str[mid] = c;

    // Copiar a segunda metade da cadeia original para a nova cadeia
    for (int i = mid; i < length; i++) {
        new_str[i + 1] = s[i];
    }

    // Adicionar o caractere nulo no final
    new_str[length + 1] = '\0';

    return new_str;
}

/**
 Funcao para remover caractere do meio (aproximadamente)
 de uma cadeia de caracteres, por meio de apontador.
 Se houver ao menos dois caracteres, remover o primeiro.
 @return apontador para a cadeia atualizada
 @param s - apontador para cadeia de caracteres
*/
char* str_pop_mid(char *s) {
    // Encontrar o tamanho da cadeia de caracteres original
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }

    // Se a cadeia estiver vazia ou com um único caractere, retornar um ponteiro para uma nova cadeia vazia
    if (length == 0 || length == 1) {
        char* new_str = new char[1];
        new_str[0] = '\0';
        return new_str;
    }

    // Alocar nova cadeia de caracteres com tamanho menor
    char* new_str = new char[length];

    // Encontrar a posição do meio
    int mid = length / 2;

    // Copiar primeira metade da cadeia original para a nova cadeia
    for (int i = 0; i < mid; i++) {
        new_str[i] = s[i];
    }

    // Copiar a segunda metade da cadeia original para a nova cadeia, pulando o caractere do meio
    for (int i = mid + 1; i < length; i++) {
        new_str[i - 1] = s[i];
    }

    // Adicionar o caractere nulo no final
    new_str[length - 1] = '\0';

    return new_str;
}

/**
 Funcao para inserir caractere em certa posição válida
 de uma cadeia de caracteres, por meio de apontador.
 @return apontador para a cadeia atualizada
 @param s - apontador para cadeia de caracteres
 @param c - caractere a ser inserido
 @param index - posicao onde inserir
 */
 char* str_insert(char *s, char c, int index) {
    // Encontrar o tamanho da cadeia de caracteres original
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }

    // Verificar se a posição é válida
    if (index < 0 || index > length) {
        return nullptr; // Retorna nullptr se a posição for inválida
    }

    // Alocar nova cadeia de caracteres com tamanho maior
    char* new_str = new char[length + 2]; // +1 para novo caractere e +1 para '\0'

    // Copiar cadeia original para a nova cadeia, inserindo o novo caractere na posição especificada
    for (int i = 0; i < index; i++) {
        new_str[i] = s[i];
    }
    new_str[index] = c;
    for (int i = index; i < length; i++) {
        new_str[i + 1] = s[i];
    }

    // Adicionar o caractere nulo no final
    new_str[length + 1] = '\0';

    return new_str;
}

/**
 Funcao para remover caractere de certa posição válida
 de uma cadeia de caracteres, por meio de apontador.
 @return apontador para a cadeia atualizada
 @param s - apontador para cadeia de caracteres
 @param index - posicao de onde remover
 */
 char* str_remove(char *s, int index) {
    // Encontrar o tamanho da cadeia de caracteres original
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }

    // Verificar se a posição é válida
    if (index < 0 || index >= length) {
        return nullptr; // Retorna nullptr se a posição for inválida
    }

    // Alocar nova cadeia de caracteres com tamanho menor
    char* new_str = new char[length];

    // Copiar cadeia original para a nova cadeia, pulando o caractere na posição especificada
    for (int i = 0; i < index; i++) {
        new_str[i] = s[i];
    }
    for (int i = index + 1; i < length; i++) {
        new_str[i - 1] = s[i];
    }

    // Adicionar o caractere nulo no final
    new_str[length - 1] = '\0';

    return new_str;
}

/**
 Funcao para procurar pela primeira ocorrencia de certo símbolo
 em uma cadeia de caracteres, por meio de apontador.
 @return apontador para a primeira ocorrência; NULL, caso contrario
 @param s - apontador para cadeia de caracteres
 @param c - caractere a ser procurado
*/
char* str_chr(char *s, char c) {
    while (*s != '\0') {
        if (*s == c) {
            return s; // Retorna o ponteiro para a primeira ocorrência
        }
        s++;
    }
    return nullptr; // Retorna NULL se o caractere não for encontrado
}

/**
 Funcao para separar caracteres ate' a ocorrencia de delimitador
 em uma cadeia de caracteres, por meio de apontador.
 @return apontador para caracteres; NULL, caso contrario
 @param s - apontador para cadeia de caracteres
 @param delimiter - caractere a ser procurado
*/
char* str_tok(char *s, char delimiter) {
    char* start = s; // Apontador para o início da cadeia
    while (*s != '\0') {
        if (*s == delimiter) {
            *s = '\0'; // Substitui o delimitador por nulo para terminar a cadeia
            return start; // Retorna o ponteiro para os caracteres antes do delimitador
        }
        s++;
    }
    return nullptr; // Retorna NULL se o delimitador não for encontrado
}

/**
 Funcao para procurar por certo prefixo
 em cadeia de caracteres, por meio de apontador.
 @return apontador para a primeira ocorrência; NULL, caso contrario
 @param prefix - prefixo a ser procurado
 @param s - apontador para cadeia de caracteres
*/
char* str_prefix(char *prefix, char *s) {
    while (*s != '\0' && *prefix != '\0') {
        if (*s != *prefix) {
            return nullptr;
        }
        s++;
        prefix++;
    }
    return (*prefix == '\0') ? s : nullptr; // Retorna s se prefixo estiver no início, caso contrário, NULL
}

/**
 Funcao para procurar por certo sufixo
 em cadeia de caracteres, por meio de apontador.
 @return apontador para a primeira ocorrência; NULL, caso contrario
 @param s - apontador para cadeia de caracteres
 @param sufix - sufixo a ser procurado
*/
char* str_suffix(char *s, char *suffix) {
    int s_length = strlen(s);
    int suffix_length = strlen(suffix);

    if (suffix_length > s_length) {
        return nullptr;
    }

    char* start = s + s_length - suffix_length;
    while (*start != '\0' && *suffix != '\0') {
        if (*start != *suffix) {
            return nullptr;
        }
        start++;
        suffix++;
    }
    return (*suffix == '\0') ? (s + s_length - suffix_length) : nullptr; // Retorna s + posição do início do sufixo, caso contrário, NULL
}

void test01(){
    std::cout << "\nINICIO TESTE 01 [str_push_back]\n" <<std::endl;

    char original_str[] = "Hello";
    char new_char = '!';

    // Imprimir cadeia original
    std::cout << "Cadeia original: " << original_str << std::endl;

    // Chamar função str_push_back
    char* updated_str = str_push_back(original_str, new_char);

    // Imprimir cadeia atualizada
    std::cout << "Cadeia atualizada: " << updated_str << std::endl;

    // Liberar memória alocada
    delete[] updated_str;

    std::cout << "\nFIM TESTE 01" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();
}

void test02(){
    std::cout << "\nINICIO TESTE 02 [str_pop_back]\n" <<std::endl;

    char original_str[] = "Hello!";

    // Imprimir cadeia original
    std::cout << "Cadeia original: " << original_str << std::endl;

    // Chamar função str_pop_back
    char* updated_str = str_pop_back(original_str);

    // Imprimir cadeia atualizada
    std::cout << "Cadeia atualizada: " << updated_str << std::endl;

    // Liberar memória alocada
    delete[] updated_str;

    std::cout << "\nFIM TESTE 02" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();
}

void test03(){
    std::cout << "\nINICIO TESTE 03 [str_push_front]\n" <<std::endl;

    char original_str[] = "World";
    char new_char = 'H';

    // Imprimir cadeia original
    std::cout << "Cadeia original: " << original_str << std::endl;

    // Chamar função str_push_front
    char* updated_str = str_push_front(new_char, original_str);

    // Imprimir cadeia atualizada
    std::cout << "Cadeia atualizada: " << updated_str << std::endl;

    // Liberar memória alocada
    delete[] updated_str;

    std::cout << "\nFIM TESTE 03" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();
}

void test04(){
    std::cout << "\nINICIO TESTE 04 [str_pop_front]\n" <<std::endl;

    char original_str[] = "Hello!";

    // Imprimir cadeia original
    std::cout << "Cadeia original: " << original_str << std::endl;

    // Chamar função str_pop_front
    char* updated_str = str_pop_front(original_str);

    // Imprimir cadeia atualizada
    std::cout << "Cadeia atualizada: " << updated_str << std::endl;

    // Liberar memória alocada
    delete[] updated_str;

    std::cout << "\nFIM TESTE 04" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();
}

void test05(){
    std::cout << "\nINICIO TESTE 05 [str_push_mid]\n" <<std::endl;

    char original_str1[] = "Hello";
    char new_char = 'X';

    // Testar str_push_mid
    std::cout << "Teste str_push_mid:" << std::endl;
    std::cout << "Cadeia original: " << original_str1 << std::endl;
    char* updated_str1 = str_push_mid(original_str1, new_char);
    std::cout << "Cadeia atualizada: " << updated_str1 << std::endl;
    delete[] updated_str1;

    std::cout << "\nFIM TESTE 05" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();
}

void test06(){
    std::cout << "\nINICIO TESTE 06 [str_pop_mid]\n" <<std::endl;

    char original_str2[] = "World!";
    char new_char = 'X';

    // Testar str_pop_mid
    std::cout << "\nTeste str_pop_mid:" << std::endl;
    std::cout << "Cadeia original: " << original_str2 << std::endl;
    char* updated_str2 = str_pop_mid(original_str2);
    std::cout << "Cadeia atualizada: " << updated_str2 << std::endl;
    delete[] updated_str2;

    std::cout << "\nFIM TESTE 06" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();
}

void test07(){
    std::cout << "\nINICIO TESTE 07 [str_insert]\n" <<std::endl;

    char original_str1[] = "Hello, World!";
    char new_char = 'X';
    int insert_index = 7;

    // Testar str_insert
    std::cout << "Teste str_insert:" << std::endl;
    std::cout << "Cadeia original: " << original_str1 << std::endl;
    char* updated_str1 = str_insert(original_str1, new_char, insert_index);
    if (updated_str1) {
        std::cout << "Cadeia atualizada: " << updated_str1 << std::endl;
        delete[] updated_str1;
    } else {
        std::cout << "Posicao de insercao invalida." << std::endl;
    }

    std::cout << "\nFIM TESTE 07" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();
}

void test08(){
    std::cout << "\nINICIO TESTE 08 [str_remove]\n" <<std::endl;

    char original_str2[] = "Hello, World!";
    char new_char = 'X';
    int remove_index = 5;

    // Testar str_remove
    std::cout << "\nTeste str_remove:" << std::endl;
    std::cout << "Cadeia original: " << original_str2 << std::endl;
    char* updated_str2 = str_remove(original_str2, remove_index);
    if (updated_str2) {
        std::cout << "Cadeia atualizada: " << updated_str2 << std::endl;
        delete[] updated_str2;
    } else {
        std::cout << "Posicao de remocao invalida." << std::endl;
    }

    std::cout << "\nFIM TESTE 08" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();
}

void test09(){
    std::cout << "\nINICIO TESTE 09 [str_chr]\n" <<std::endl;

    char original_str1[] = "Hello, World!";
    char search_char = 'o';

    // Testar str_chr
    std::cout << "Teste str_chr:" << std::endl;
    char* result1 = str_chr(original_str1, search_char);
    if (result1) {
        std::cout << "Primeira ocorrencia de '" << search_char << "': " << result1 << std::endl;
    } else {
        std::cout << "Caractere '" << search_char << "' não encontrado." << std::endl;
    }

    std::cout << "\nFIM TESTE 09" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();
}

void test10(){
    std::cout << "\nINICIO TESTE 10 [str_tok]\n" <<std::endl;

    char original_str2[] = "Hello, World!";
    char delimiter = ',';

    // Testar str_tok
    std::cout << "\nTeste str_tok:" << std::endl;
    char* result2 = str_tok(original_str2, delimiter);
    if (result2) {
        std::cout << "Cadeia antes do delimitador '" << delimiter << "': " << result2 << std::endl;
    } else {
        std::cout << "Delimitador '" << delimiter << "' não encontrado." << std::endl;
    }

    std::cout << "\nFIM TESTE 10" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();
}

void testExtra01(){
    std::cout << "\nINICIO TESTE EXTRA 01 [str_prefix]\n" <<std::endl;

    char original_str1[] = "Hello, World!";
    char prefix[] = "Hello";

    // Testar str_prefix
    std::cout << "Teste str_prefix:" << std::endl;
    char* result1 = str_prefix(prefix, original_str1);
    if (result1) {
        std::cout << "Prefixo '" << prefix << "' encontrado no inicio: " << original_str1 << std::endl;
    } else {
        std::cout << "Prefixo '" << prefix << "' nao encontrado no inicio." << std::endl;
    }

    std::cout << "\nFIM TESTE EXTRA 01" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();
}

void testExtra02(){
    std::cout << "\nINICIO TESTE EXTRA 02 [str_suffix]\n" <<std::endl;

    char original_str1[] = "Hello, World!";
    char suffix[] = "World!";

    // Testar str_suffix
    std::cout << "\nTeste str_suffix:" << std::endl;
    char* result2 = str_suffix(original_str1, suffix);
    if (result2) {
        std::cout << "Sufixo '" << suffix << "' encontrado no final: " << result2 << std::endl;
    } else {
        std::cout << "Sufixo '" << suffix << "' nao encontrado no final." << std::endl;
    }

    std::cout << "\nFIM TESTE EXTRA 02" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();

}

int main(void){
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
            test08();
            break;
        case 9:
            test09();
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
