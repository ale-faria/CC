#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define NULO -1
#define TAM_TAB 21


char *strsep(char **stringp, const char *delim) {
    char *start = *stringp;
    char *p;

    if (start == NULL) {
        return NULL;
    }

    p = strpbrk(start, delim);
    if (p) {
        *p = '\0';
        *stringp = p + 1;
    } else {
        *stringp = NULL;
    }

    return start;
}

typedef struct {
    int id;
    int generation;
    char name[50];
    char description[200];
    char types[2][20];
    int quantTypes;
    char abilities[6][30];
    int quantAbilities;
    double weight;
    double height;
    int captureRate;
    int isLegendary;
    char captureDate[11];
} Pokemon;

typedef struct {
    Pokemon *pokemons;
    int size;
} PokemonList;

void imprimirPokemon(Pokemon *pokemon) {

    printf("[#%d -> %s: %s - ['%s'", pokemon->id, pokemon->name, pokemon->description, pokemon->types[0]);

    // Tipos (types)
    if(pokemon->quantTypes == 2){
        printf(", '%s']", pokemon->types[1]);
    }

    if(pokemon->quantTypes == 1){
        printf("]");
    }

    // Habilidades (abilities)
    printf(" - ");
    int i = 0, j = 1;
    while(i < pokemon->quantAbilities){
        if(j >= 0 && j < pokemon->quantAbilities)
        printf("%s, ", pokemon->abilities[i]);
        if(j == pokemon->quantAbilities){
            printf("%s", pokemon->abilities[i]);
        }
        i++;
        j++;
    }

    printf(" - %.1fkg - %.1fm - %d%% - %s - %d gen] - %s\n", pokemon->weight, pokemon->height, pokemon->captureRate, pokemon->isLegendary ? "true" : "false",
           pokemon->generation, pokemon->captureDate);
}

PokemonList readPokemonCSV(char *filePath) {

    //printf("entrou na leitura de arquivo\n");
    FILE *file = fopen(filePath, "r");
    if (!file) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    PokemonList pokemonList;
    pokemonList.size = 0;
    pokemonList.pokemons = malloc(1000* sizeof(Pokemon)); // Alocacao inicial

    char line[1024];
    fgets(line, sizeof(line), file); // Pular o cabecalho

    while (fgets(line, sizeof(line), file)) {
        Pokemon pokemon;
        char abilitiesStr[200];
        char typesStr[200];

        char *token = NULL;
        char *lineCopy = line;

        // Parse ID
        token = strsep(&lineCopy, ",");
        pokemon.id = atoi(token);

        // Parse generation
        token = strsep(&lineCopy, ",");
        pokemon.generation = atoi(token);

        // Parse name
        token = strsep(&lineCopy, ",");
        strcpy(pokemon.name, token);

        // Parse description
        token = strsep(&lineCopy, ",");
        strcpy(pokemon.description, token);

        // Parse types
        token = strsep(&lineCopy, "\"");
        strcpy(typesStr, token);

        // Parse abilities
        token = strsep(&lineCopy, "\"");
        strcpy(abilitiesStr, token);

        // Parse weight
        token = strsep(&lineCopy, ",");
        token = strsep(&lineCopy, ",");
        if (token == NULL) {
            pokemon.weight = 0;
        } else {
            pokemon.weight = atof(token);
        }

        // Parse height
        token = strsep(&lineCopy, ",");
        if (token == NULL) {
            pokemon.height = 0;
        } else {
            pokemon.height = atof(token);
        }

        // Parse captureRate
        token = strsep(&lineCopy, ",");
        pokemon.captureRate = atoi(token);

        // Parse isLegendary
        token = strsep(&lineCopy, ",");
        pokemon.isLegendary = atoi(token);

        // Parse captureDate
        token = strsep(&lineCopy, "\n");
        if (token != NULL) {
            strcpy(pokemon.captureDate, token);
        } else {
            strcpy(pokemon.captureDate, "N/A");
        }

        // Parse types
        char *tokenTypes = strtok(typesStr, ",");
        int i = 0;
        while(tokenTypes != NULL && i < 2){
            strcpy(pokemon.types[i++], tokenTypes);
            tokenTypes = strtok(NULL, ",");
        }
        pokemon.quantTypes = i;

        // Parse abilities
        char *tokenAbilities = strtok(abilitiesStr, ",");
        i = 0;
        while (tokenAbilities != NULL && i < 7) {
            strcpy(pokemon.abilities[i++], tokenAbilities);
            tokenAbilities = strtok(NULL, ",");
        }
        pokemon.quantAbilities = i;

        // Adicionar o pokemon na lista
        pokemonList.pokemons[pokemonList.size++] = pokemon;
    }

    fclose(file);
    return pokemonList;
}

Pokemon *procuraPokemonPorId(PokemonList *pokemonList, int id) {
    for (int i = 0; i < pokemonList->size; i++) {
        if (pokemonList->pokemons[i].id == id) {
            return &pokemonList->pokemons[i];
        }
    }
    return NULL;
}

/*
--------------------------------------
Tabela Hash Indireta com Lista Simples
--------------------------------------
*/

// Definicao da celula da lista encadeada
typedef struct Celula {
    Pokemon *pokemon;
    struct Celula *prox;
} Celula;

// Funcao para criar uma nova celula
Celula* novaCelula(Pokemon *pokemon) {
    Celula* nova = (Celula*) malloc(sizeof(Celula));
    nova->pokemon = pokemon;
    nova->prox = NULL;
    return nova;
}

// Definicao da lista encadeada
typedef struct Lista {
    Celula *primeiro;
    Celula *ultimo;
} Lista;

// Funcao para inicializar uma nova lista
void inicializarLista(Lista *lista) {
    lista->primeiro = novaCelula(NULL);
    lista->ultimo = lista->primeiro;
}

// Funcao para inserir um Pokemon no inicio da lista
void inserirInicio(Lista *lista, Pokemon *pokemon) {
    Celula *nova = novaCelula(pokemon);
    nova->prox = lista->primeiro->prox;
    lista->primeiro->prox = nova;

    if (lista->primeiro == lista->ultimo) {
        lista->ultimo = nova;
    }
}

// Funcao para pesquisar um Pokemon pelo nome
int pesquisar(Lista *lista, const char *nome) {
    int pos = 0;
    for (Celula *i = lista->primeiro->prox; i != NULL; i = i->prox) {
        if (i->pokemon != NULL && strcmp(i->pokemon->name, nome) == 0) {
            //printf("(Posicao: %d) ", );
            return pos;
        }
        pos++;
    }
    return -1;
}

// Definicao da Tabela Hash Indireta com Lista Encadeada
typedef struct HashIndiretoLista {
    Lista tabela[TAM_TAB];
} HashIndiretoLista;

// Funcao para inicializar a tabela hash
void inicializarHash(HashIndiretoLista *hash) {
    for (int i = 0; i < TAM_TAB; i++) {
        inicializarLista(&hash->tabela[i]);
    }
}

// Funcao hash
int h(const char *nome) {
    int soma = 0;
    for (int i = 0; nome[i] != '\0'; i++) {
        soma += nome[i];
    }
    return soma % TAM_TAB;
}

// Funcao para inserir um Pokemon na tabela hash
void inserirHash(HashIndiretoLista *hash, Pokemon *pokemon) {
    int pos = h(pokemon->name);
    inserirInicio(&hash->tabela[pos], pokemon);
}

// Funcao para pesquisar um Pokemon na tabela hash
int pesquisarHash(HashIndiretoLista *hash, const char *nome) {
    int pos = h(nome);
    int posLista = pesquisar(&hash->tabela[pos], nome);
    if (posLista != -1) {
        printf("(Posicao: %d) SIM",  pos);
    } else {
        printf(" NAO");
    }
    return posLista;

}

/*
--------------------------------------
Tabela Hash Indireta com Lista Simples
--------------------------------------
*/

int main(void) {
    char *filePath;
    //filePath = "pokemon.csv";
    filePath = "/tmp/pokemon.csv"; // Caminho no Verde

    PokemonList pokemonList = readPokemonCSV(filePath); // Leitura do arquivo csv

    HashIndiretoLista hash;
    inicializarHash(&hash);

    char entrada[30];

    while (1) {
        scanf("%s", entrada);

        if (strcmp(entrada, "FIM") == 0) {
            break;
        }

        int id = atoi(entrada);
        Pokemon *pokemon = procuraPokemonPorId(&pokemonList, id);
        if (pokemon != NULL) {
            inserirHash(&hash, pokemon);
        }
    }

    while(1){
        scanf("%s", entrada);

        if (strcmp(entrada, "FIM") == 0) {
            break;
        }

        printf("=> %s: ", entrada);
        int pesquisa = pesquisarHash(&hash, entrada);


        printf("\n");
    }

    return 0;
}
