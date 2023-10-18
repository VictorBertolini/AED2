#include <stdio.h>
#include <stdlib.h>


#define SUCCESS 1
#define FAIL 0
#define INVALID_POINTER -1

typedef struct data
{
    int value;
} Data;

typedef struct node
{  
    Data data;
    struct node *next;
} Node;

typedef struct list
{
    Node *beginning;
} Linked;

/**
 * @brief Cria uma nova lista encadeada vazia.
 *
 * Esta função aloca memória para uma nova lista encadeada e a inicializa.
 *
 * @return Um ponteiro para a lista encadeada recém-criada ou NULL se a alocação de memória falhar.
 */
Linked * createList();

/**
 * @brief Adiciona um novo nó no início de uma lista encadeada.
 *
 * Esta função cria um novo nó contendo os dados especificados e o insere no início da lista encadeada.
 *
 * @param list Um ponteiro para a lista encadeada à qual o nó será adicionado.
 * @param data Os dados a serem armazenados no novo nó.
 * @return SUCCESS se o nó foi adicionado com sucesso, INVALID_POINTER se o ponteiro da lista for inválido, ou FAIL se a alocação de memória falhar.
 */
int prepend(Linked *list, Data data);

/**
 * @brief Adiciona um novo nó ao final de uma lista encadeada.
 *
 * Esta função cria um novo nó contendo os dados especificados e o insere ao final da lista encadeada.
 *
 * @param list Um ponteiro para a lista encadeada à qual o nó será adicionado.
 * @param data Os dados a serem armazenados no novo nó.
 * @return SUCCESS se o nó foi adicionado com sucesso, INVALID_POINTER se o ponteiro da lista for inválido, ou FAIL se a alocação de memória falhar.
 */
int append(Linked *list, Data data);

/**
 * @brief Insere um novo nó com dados em uma posição específica da lista encadeada.
 *
 * Esta função cria um novo nó contendo os dados especificados e o insere em uma posição específica da lista encadeada.
 *
 * @param list Um ponteiro para a lista encadeada à qual o nó será adicionado.
 * @param data Os dados a serem armazenados no novo nó.
 * @param position A posição desejada para inserção do novo nó (começando em 1 para o primeiro nó).
 * @return SUCCESS se o nó foi adicionado com sucesso, INVALID_POINTER se o ponteiro da lista for inválido, ou FAIL se a alocação de memória falhar.
 */
int insert(Linked *list, Data data, int position);

/**
 * @brief Remove o nó no início da lista encadeada.
 *
 * Esta função remove o nó localizado no início da lista encadeada e libera a memória associada a ele.
 *
 * @param list Um ponteiro para a lista encadeada da qual o nó será removido.
 * @return SUCCESS se o nó foi removido com sucesso, INVALID_POINTER se o ponteiro da lista for inválido ou se a lista estiver vazia.
 */
int removeFront(Linked *list);

/**
 * @brief Remove o nó no final da lista encadeada.
 *
 * Esta função remove o nó localizado no final da lista encadeada e libera a memória associada a ele.
 *
 * @param list Um ponteiro para a lista encadeada da qual o nó será removido.
 * @return SUCCESS se o nó foi removido com sucesso, INVALID_POINTER se o ponteiro da lista for inválido ou se a lista estiver vazia.
 */
int removeEnd(Linked *list);

/**
 * @brief Remove o nó em uma posição específica da lista encadeada.
 *
 * Esta função remove o nó localizado em uma posição específica da lista encadeada e libera a memória associada a ele.
 *
 * @param list Um ponteiro para a lista encadeada da qual o nó será removido.
 * @param Position A posição do nó a ser removido (começando em 1 para o primeiro nó).
 * @return SUCCESS se o nó foi removido com sucesso, INVALID_POINTER se o ponteiro da lista for inválido, ou FAIL se a posição for inválida.
 */
int removePosition(Linked *list, int Position);

/**
 * @brief Exibe os elementos da lista encadeada no console.
 *
 * Esta função percorre a lista encadeada e exibe os elementos armazenados no console.
 *
 * @param list Um ponteiro para a lista encadeada a ser exibida.
 * @return SUCCESS se a lista foi exibida com sucesso ou INVALID_POINTER se o ponteiro da lista for inválido.
 */
int showList(Linked *list);

/**
 * @brief Retorna o tamanho da lista encadeada.
 *
 * Esta função calcula e retorna o número de elementos na lista encadeada.
 *
 * @param list Um ponteiro para a lista encadeada da qual se deseja saber o tamanho.
 * @return O tamanho da lista encadeada (número de elementos) ou 0 se a lista estiver vazia, ou INVALID_POINTER se o ponteiro da lista for inválido.
 */
int listSize(Linked *list);

/**
 * @brief Verifica se a lista encadeada está vazia.
 *
 * Esta função verifica se a lista encadeada está vazia, ou seja, se não contém nenhum elemento.
 *
 * @param list Um ponteiro para a lista encadeada a ser verificada.
 * @return 1 se a lista estiver vazia, 0 se a lista contiver elementos, ou INVALID_POINTER se o ponteiro da lista for inválido.
 */
int emptyList(Linked *list);

/**
 * @brief Destrói a lista encadeada e libera toda a memória associada a ela.
 *
 * Esta função libera a memória de todos os nós da lista encadeada, bem como a memória da própria lista.
 *
 * @param list Um ponteiro para a lista encadeada a ser destruída.
 * @return SUCCESS se a lista foi destruída com sucesso, ou INVALID_POINTER se o ponteiro da lista for inválido.
 */
int destroyList(Linked *list);

/**
 * @brief Procura um elemento na lista encadeada e retorna a posição da primeira ocorrência.
 *
 * Esta função percorre a lista encadeada e procura um elemento com os dados especificados. 
 * Se encontrar, retorna a posição (começando em 1) da primeira ocorrência. Se não encontrar, retorna -1.
 *
 * @param list Um ponteiro para a lista encadeada na qual se deseja buscar o elemento.
 * @param data Os dados que estão sendo procurados.
 * @return A posição do elemento encontrado (começando em 1), -1 se o elemento não for encontrado, ou INVALID_POINTER se o ponteiro da lista for inválido.
 */
int findElement(Linked *list, Data data);




