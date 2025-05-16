#include <iostream>

// Função para obter o tamanho de um array dinâmico
int array_size(int* array) {
    int size = 0;
    while (array[size] != '\0') {
        size++;
    }
    return size;
}

/**
 Funcao para acrescentar valor ao final
 de um arranjo, por meio de apontador.
 @return apontador para arranjo atualizado
 @param array - apontador para arranjo
 @param value - valor a ser inserido
 */
int* array_push_back(int *array, int value) {
    int size = array_size(array);
    int* new_array = new int[size + 2]; // +1 para o novo elemento, +1 para o terminador nulo
    for (int i = 0; i < size; ++i) {
        new_array[i] = array[i];
    }
    new_array[size] = value;
    new_array[size + 1] = '\0';
    delete[] array;
    return new_array;
}

/**
 Funcao para remover valor do final
 de um arranjo, por meio de apontador.
 @return apontador para arranjo atualizado
 @param array - apontador para arranjo
 */
int* array_pop_back(int *array) {
    int size = array_size(array);
    if (size == 0) {
        return array; // Nenhum elemento para remover
    }
    int* new_array = new int[size];
    for (int i = 0; i < size - 1; ++i) {
        new_array[i] = array[i];
    }
    new_array[size - 1] = '\0';
    delete[] array;
    return new_array;
}

// Função para imprimir o arranjo
void print_array(int* array) {
    int size = array_size(array);
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

/**
 Funcao para acrescentar valor ao início
 de um arranjo, por meio de apontador.
 @return apontador para arranjo atualizado
 @param array - apontador para arranjo
 @param value - valor a ser inserido
 */
 int* array_push_front(int value, int *array) {
    int size = array_size(array);
    int* new_array = new int[size + 2]; // +1 para o novo elemento, +1 para o terminador nulo
    new_array[0] = value;
    for (int i = 0; i < size; ++i) {
        new_array[i + 1] = array[i];
    }
    new_array[size + 1] = '\0';
    delete[] array;
    return new_array;
}

 /**
 Funcao para remover valor do início
 de um arranjo, por meio de apontador.
 @return apontador para arranjo atualizado
 @param array - apontador para arranjo
 */
 int* array_pop_front(int *array) {
    int size = array_size(array);
    if (size == 0) {
        return array; // Nenhum elemento para remover
    }
    int* new_array = new int[size];
    for (int i = 1; i < size; ++i) {
        new_array[i - 1] = array[i];
    }
    new_array[size - 1] = '\0';
    delete[] array;
    return new_array;
}

/**
 Funcao para acrescentar valor no meio (aproximadamente)
 de um arranjo, por meio de apontador.
 @return apontador para arranjo atualizado
 @param array - apontador para arranjo
 @param value - valor a ser inserido
 */
 int* array_push_mid(int *array, int value) {
    int size = array_size(array);
    int mid = (size % 2 == 0) ? size / 2 : size / 2 + 1;
    int* new_array = new int[size + 2]; // +1 para o novo elemento, +1 para o terminador nulo
    for (int i = 0; i < mid; ++i) {
        new_array[i] = array[i];
    }
    new_array[mid] = value;
    for (int i = mid; i < size; ++i) {
        new_array[i + 1] = array[i];
    }
    new_array[size + 1] = '\0';
    delete[] array;
    return new_array;
}

/**
 Funcao para remover valor do meio (aproximadamente)
 de um arranjo, por meio de apontador.
 @return apontador para arranjo atualizado
 @param array - apontador para arranjo
 */
 int* array_pop_mid(int *array) {
    int size = array_size(array);
    if (size == 0) {
        return array; // Nenhum elemento para remover
    }
    int mid = size / 2;
    int* new_array = new int[size]; // -1 para o elemento removido, +1 para o terminador nulo
    for (int i = 0; i < mid; ++i) {
        new_array[i] = array[i];
    }
    for (int i = mid + 1; i < size; ++i) {
        new_array[i - 1] = array[i];
    }
    new_array[size - 1] = '\0';
    delete[] array;
    return new_array;
}

// --------------------------------

typedef struct s_intArray {
    int length;
    int *data;
} intArray;

typedef intArray* ref_intArray;

/**
 * Funcao para comparar arranjos de inteiros por meio de apontadores.
 * @return zero , se forem iguais;
 *         negativo, se o valor da diferenca for menor e estiver no primeiro arranjo;
 *         positivo , se o valor da diferenca for maior e estiver no primeiro arranjo.
 * @param p - apontador para inicio do primeiro arranjo.
 * @param q - apontador para inicio do segundo arranjo.
 */
int intArray_cmp(ref_intArray p, ref_intArray q) {
    int min_length = (p->length < q->length) ? p->length : q->length;
    for (int i = 0; i < min_length; ++i) {
        if (p->data[i] != q->data[i]) {
            return p->data[i] - q->data[i];
        }
    }
    return p->length - q->length;
}

/**
 * Funcao para juntar arranjos de inteiros por meio de apontadores.
 * @return apontador para inicio do arranjo com a uniao.
 * @param p - apontador para inicio do primeiro arranjo.
 * @param q - apontador para inicio do segundo arranjo.
 */
ref_intArray intArray_cat(ref_intArray p, ref_intArray q) {
    ref_intArray result = new intArray;
    result->length = p->length + q->length;
    result->data = new int[result->length];
    for (int i = 0; i < p->length; ++i) {
        result->data[i] = p->data[i];
    }
    for (int i = 0; i < q->length; ++i) {
        result->data[p->length + i] = q->data[i];
    }
    return result;
}

void print_intArray(ref_intArray array) {
    if (array == nullptr) {
        std::cout << "nullptr" << std::endl;
        return;
    }
    for (int i = 0; i < array->length; ++i) {
        std::cout << array->data[i] << " ";
    }
    std::cout << std::endl;
}

/**
 * Funcao para procurar pela primeira ocorrencia de valor em arranjo
 * por meio de apontador.
 * @return apontador para a primeira ocorrência; nullptr, caso contrario
 * @param a - apontador para arranjo de inteiros
 * @param x - valor ser procurado
 */
ref_intArray intArray_seek(ref_intArray a, int x) {
    for (int i = 0; i < a->length; ++i) {
        if (a->data[i] == x) {
            return new intArray{1, &a->data[i]};
        }
    }
    return nullptr;
}

/**
 * Funcao para separar sequencia de valores em arranjo
 * por meio de apontador.
 * @return apontador para inicio da sequencia de inteiros; nullptr, caso contrario
 * @param a - apontador para arranjo de inteiros
 * @param start - posicao inicial
 * @param size - quantidade de dados
 */
ref_intArray intArray_sub(ref_intArray a, int start, int size) {
    if (start < 0 || start >= a->length || size <= 0 || (start + size) > a->length) {
        return nullptr;
    }
    ref_intArray sub_array = new intArray;
    sub_array->length = size;
    sub_array->data = new int[size];
    for (int i = 0; i < size; ++i) {
        sub_array->data[i] = a->data[start + i];
    }
    return sub_array;
}

/**
 * Funcao para intercalar arranjos de inteiros por meio de apontadores.
 * @return apontador para inicio do arranjo com a uniao.
 * @param p - apontador para inicio do primeiro arranjo.
 * @param q - apontador para inicio do segundo arranjo.
 */
ref_intArray intArray_merge(ref_intArray p, ref_intArray q) {
    int total_length = p->length + q->length;
    ref_intArray merged_array = new intArray;
    merged_array->length = total_length;
    merged_array->data = new int[total_length];
    int i = 0, j = 0, k = 0;

    // Intercala os elementos dos dois arrays
    while (i < p->length && j < q->length) {
        merged_array->data[k++] = p->data[i++];
        merged_array->data[k++] = q->data[j++];
    }

    // Copia os elementos restantes do array p
    while (i < p->length) {
        merged_array->data[k++] = p->data[i++];
    }

    // Copia os elementos restantes do array q
    while (j < q->length) {
        merged_array->data[k++] = q->data[j++];
    }

    return merged_array;
}

/**
 * Funcao para intercalar arranjos de inteiros em ordem crescente por meio de apontadores.
 * @return apontador para inicio do arranjo com a uniao.
 * @param p - apontador para inicio do primeiro arranjo.
 * @param q - apontador para inicio do segundo arranjo.
 */
ref_intArray intArray_mergeUp(ref_intArray p, ref_intArray q) {
    int total_length = p->length + q->length;
    ref_intArray merged_array = new intArray;
    merged_array->length = total_length;
    merged_array->data = new int[total_length];
    int i = 0, j = 0, k = 0;

    // Intercala os elementos dos dois arrays em ordem crescente
    while (i < p->length && j < q->length) {
        if (p->data[i] <= q->data[j]) {
            merged_array->data[k++] = p->data[i++];
        } else {
            merged_array->data[k++] = q->data[j++];
        }
    }

    // Copia os elementos restantes do array p
    while (i < p->length) {
        merged_array->data[k++] = p->data[i++];
    }

    // Copia os elementos restantes do array q
    while (j < q->length) {
        merged_array->data[k++] = q->data[j++];
    }

    return merged_array;
}

void test01(){
    std::cout << "\nINICIO TESTE 01 [array_push_back]\n" <<std::endl;

    int* array = new int[1];
    array[0] = '\0'; // Inicializa com terminador nulo

    // Teste array_push_back
    array = array_push_back(array, 10);
    print_array(array);
    array = array_push_back(array, 20);
    print_array(array);
    array = array_push_back(array, 30);
    print_array(array);

    // Liberação da memória
    delete[] array;

    std::cout << "\nFIM TESTE 01" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();
}

void test02(){
    std::cout << "\nINICIO TESTE 02 [array_pop_back]\n" <<std::endl;

    int* array = new int[1];
    array[0] = '\0'; // Inicializa com terminador nulo

    array = array_push_back(array, 10);
    //print_array(array);
    array = array_push_back(array, 20);
    //print_array(array);
    array = array_push_back(array, 30);
    //print_array(array);

    // Teste array_pop_back
    array = array_pop_back(array);
    print_array(array);
    array = array_pop_back(array);
    print_array(array);
    array = array_pop_back(array);
    print_array(array);

    // Liberação da memória
    delete[] array;

    std::cout << "\nFIM TESTE 02" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();
}

void test03(){
    std::cout << "\nINICIO TESTE 03 [array_push_front]\n" <<std::endl;

    int* array = new int[1];
    array[0] = '\0'; // Inicializa com terminador nulo

    // Teste array_push_front
    array = array_push_front(40, array);
    print_array(array);
    array = array_push_front(50, array);
    print_array(array);
    array = array_push_front(60, array);
    print_array(array);


    // Liberação da memória
    delete[] array;

    std::cout << "\nFIM TESTE 03" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();
}

void test04(){
    std::cout << "\nINICIO TESTE 04 [array_pop_front]\n" <<std::endl;

    int* array = new int[1];
    array[0] = '\0'; // Inicializa com terminador nulo

    array = array_push_front(40, array);
    //print_array(array);
    array = array_push_front(50, array);
    //print_array(array);
    array = array_push_front(60, array);
    print_array(array);

     // Teste array_pop_front
    array = array_pop_front(array);
    print_array(array);
    array = array_pop_front(array);
    print_array(array);
    array = array_pop_front(array);
    print_array(array);

    // Liberação da memória
    delete[] array;

    std::cout << "\nFIM TESTE 04" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();
}

void test05_06(){
    std::cout << "\nINICIO TESTE 05 e 06 [array_push_mid e array_pop_mid]\n" <<std::endl;

    int* array = new int[1];
    array[0] = '\0'; // Inicializa com terminador nulo

    // Teste array_push_mid
    array = array_push_mid(array, 10);
    print_array(array);
    array = array_push_mid(array, 20);
    print_array(array);
    array = array_push_mid(array, 30);
    print_array(array);

    std::cout << "\n";
    print_array(array);

    // Teste array_pop_mid
    array = array_pop_mid(array);
    print_array(array);
    array = array_pop_mid(array);
    print_array(array);
    array = array_pop_mid(array);
    print_array(array);

    // Liberação da memória
    delete[] array;

    std::cout << "\nFIM TESTE 05 e 06" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();
}

void test07(){
    std::cout << "\nINICIO TESTE 07 [intArray_cmp]\n" <<std::endl;

// Teste para intArray_cmp
    intArray arr1 = {3, new int[3]{1, 2, 3}};
    intArray arr2 = {3, new int[3]{1, 2, 4}};
    intArray arr3 = {3, new int[3]{1, 2, 3}};

    std::cout << "Comparacao arr1 e arr2: " << intArray_cmp(&arr1, &arr2) << std::endl; // Deve retornar negativo
    std::cout << "Comparacao arr1 e arr3: " << intArray_cmp(&arr1, &arr3) << std::endl; // Deve retornar zero

    // Liberação da memória
    delete[] arr1.data;
    delete[] arr2.data;
    delete[] arr3.data;

    std::cout << "\nFIM TESTE 07" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();
}

void test08(){
    std::cout << "\nINICIO TESTE 08 [intArray_cat]\n" <<std::endl;

    // Teste para intArray_cat
    intArray arr1 = {3, new int[3]{1, 2, 3}};
    intArray arr4 = {2, new int[2]{5, 6}};
    ref_intArray result = intArray_cat(&arr1, &arr4);

    std::cout << "Concatenacao de arr1 e arr4: ";
    print_intArray(result); // Deve retornar 1 2 3 5 6

     delete[] arr4.data;
     delete[] result->data;
     delete result;

    std::cout << "\nFIM TESTE 08" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();
}

void test09_10(){
    std::cout << "\nINICIO TESTE 09 e 10 [intArray_seek e intArray_sub]\n" <<std::endl;

    intArray arr = {5, new int[5]{10, 20, 30, 40, 50}};

    // Teste para intArray_seek
    ref_intArray result = intArray_seek(&arr, 30);
    std::cout << "Busca por 30: ";
    if (result) {
        std::cout << *(result->data) << std::endl;
    } else {
        std::cout << "nullptr" << std::endl;
    }

    result = intArray_seek(&arr, 60);
    std::cout << "Busca por 60: ";
    if (result) {
        std::cout << *(result->data) << std::endl;
    } else {
        std::cout << "nullptr" << std::endl;
    }

    // Teste para intArray_sub
    ref_intArray sub_result = intArray_sub(&arr, 1, 3);
    std::cout << "Subarray de 1 a 3: ";
    print_intArray(sub_result);

    ref_intArray invalid_sub_result = intArray_sub(&arr, 3, 5);
    std::cout << "Subarray invalido de 3 a 5: ";
    print_intArray(invalid_sub_result);

    // Liberação da memória
    delete[] arr.data;
    delete[] sub_result->data;
    delete sub_result;

    std::cout << "\nFIM TESTE 09 e 10" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();
}

void testExtra01(){
    std::cout << "\nINICIO TESTE EXTRA 01[intArray_merge]\n" <<std::endl;

    intArray arr1 = {5, new int[5]{1, 3, 5, 7, 9}};
    intArray arr2 = {5, new int[5]{2, 4, 6, 8, 10}};

    // Teste para intArray_merge
    ref_intArray merged = intArray_merge(&arr1, &arr2);
    std::cout << "Merge de arr1 e arr2: ";
    print_intArray(merged);

    delete[] arr1.data;
    delete[] arr2.data;
    delete[] merged->data;
    delete merged;

    std::cout << "\nFIM TESTE EXTRA 01" <<std::endl;
    std::cout << "Aperte <enter> para continuar..." << std::endl;
    getchar();
}

void testExtra02(){
    std::cout << "\nINICIO TESTE EXTRA 02[intArray_mergeUp]\n" <<std::endl;

    intArray arr1 = {5, new int[5]{1, 3, 5, 7, 9}};
    intArray arr2 = {5, new int[5]{2, 4, 6, 8, 10}};

    // Teste para intArray_mergeUp
    ref_intArray mergedUp = intArray_mergeUp(&arr1, &arr2);
    std::cout << "MergeUp de arr1 e arr2: ";
    print_intArray(mergedUp);

    // Liberação da memória
    delete[] arr1.data;
    delete[] arr2.data;
    delete[] mergedUp->data;
    delete mergedUp;

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
            test05_06();
            break;
        case 6:
            test05_06();
            break;
        case 7:
            test07();
            break;
        case 8:
            test08();
            break;
        case 9:
            test09_10();
            break;
        case 10:
            test09_10();
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
