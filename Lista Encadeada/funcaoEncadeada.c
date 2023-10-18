#include "tadEncadeada.h"

/**
 * @brief Cria uma nova lista encadeada vazia.
 *
 * Esta função aloca memória para uma nova lista encadeada e a inicializa.
 *
 * @return Um ponteiro para a lista encadeada recém-criada ou NULL se a alocação de memória falhar.
 */
Linked * createList()
{
    Linked *newList = (Linked *) malloc(sizeof(Linked));

    if (newList == NULL)
        return NULL;

    newList->beginning = NULL;

    return newList;
}

/**
 * @brief Adiciona um novo nó no início de uma lista encadeada.
 *
 * Esta função cria um novo nó contendo os dados especificados e o insere no início da lista encadeada.
 *
 * @param list Um ponteiro para a lista encadeada à qual o nó será adicionado.
 * @param data Os dados a serem armazenados no novo nó.
 * @return SUCCESS se o nó foi adicionado com sucesso, INVALID_POINTER se o ponteiro da lista for inválido, ou FAIL se a alocação de memória falhar.
 */
int prepend(Linked *list, Data data)
{
    if (list == NULL)
        return INVALID_POINTER;
        
    Node *node = (Node *) malloc(sizeof(Node));

    if (node == NULL)
        return FAIL;
    
    node->data = data;

    node->next = list->beginning;
    list->beginning = node;
    
    return SUCCESS;
}


/**
 * @brief Adiciona um novo nó ao final de uma lista encadeada.
 *
 * Esta função cria um novo nó contendo os dados especificados e o insere ao final da lista encadeada.
 *
 * @param list Um ponteiro para a lista encadeada à qual o nó será adicionado.
 * @param data Os dados a serem armazenados no novo nó.
 * @return SUCCESS se o nó foi adicionado com sucesso, INVALID_POINTER se o ponteiro da lista for inválido, ou FAIL se a alocação de memória falhar.
 */
int append(Linked *list, Data data)
{
    if (list == NULL)
        return INVALID_POINTER;
        
    Node *node = (Node *) malloc(sizeof(Node));
    Node *aux = list->beginning;

    if (node == NULL)
        return FAIL;
    
    node->data = data;

    if (aux == NULL)
    {
        node->next = list->beginning;
        list->beginning = node;
        return SUCCESS;
    }
    
    while (aux->next != NULL)
        aux = aux->next;
    
    node->next = aux->next;
    aux->next = node;
    
    return SUCCESS;
}

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
int insert(Linked *list, Data data, int position)
{
    if (list == NULL)
        return INVALID_POINTER;
        
    Node *node = (Node *) malloc(sizeof(Node));
    Node *aux = list->beginning;
    if (node == NULL)
        return FAIL;

    node->data = data;

    if (position < 1 || list->beginning == NULL)
    {
        node->next = list->beginning;
        list->beginning = node;
        return SUCCESS;    
    }
    
    int counter = 1;
    position--;
    while ((counter < position) && (aux->next != NULL))
    {
        aux = aux->next;
        counter++;
    }

    if (aux == NULL)
        return FAIL;
    
    node->next = aux->next;
    aux->next = node;
    
    return SUCCESS;
}

/**
 * @brief Remove o nó no início da lista encadeada.
 *
 * Esta função remove o nó localizado no início da lista encadeada e libera a memória associada a ele.
 *
 * @param list Um ponteiro para a lista encadeada da qual o nó será removido.
 * @return SUCCESS se o nó foi removido com sucesso, INVALID_POINTER se o ponteiro da lista for inválido ou se a lista estiver vazia.
 */
int removeFront(Linked *list)
{
    if (list == NULL || list->beginning == NULL)
        return INVALID_POINTER;
    
    Node *aux = list->beginning;
    list->beginning = list->beginning->next;
    free(aux);
        
    return SUCCESS;
}

/**
 * @brief Remove o nó no final da lista encadeada.
 *
 * Esta função remove o nó localizado no final da lista encadeada e libera a memória associada a ele.
 *
 * @param list Um ponteiro para a lista encadeada da qual o nó será removido.
 * @return SUCCESS se o nó foi removido com sucesso, INVALID_POINTER se o ponteiro da lista for inválido ou se a lista estiver vazia.
 */
int removeEnd(Linked *list)
{
    if (list == NULL || list->beginning == NULL)
        return INVALID_POINTER;
    
    Node *aux = list->beginning;
    Node *node = list->beginning;

    if (node->next == NULL)
    {
        list->beginning = node->next;
        free(node);
        return SUCCESS;
    }
    

    while (node->next != NULL)
    {
        aux = node;
        node = node->next;
    }
    
    aux->next = node->next;
    free(node);

    return SUCCESS;
}

/**
 * @brief Remove o nó em uma posição específica da lista encadeada.
 *
 * Esta função remove o nó localizado em uma posição específica da lista encadeada e libera a memória associada a ele.
 *
 * @param list Um ponteiro para a lista encadeada da qual o nó será removido.
 * @param Position A posição do nó a ser removido (começando em 1 para o primeiro nó).
 * @return SUCCESS se o nó foi removido com sucesso, INVALID_POINTER se o ponteiro da lista for inválido, ou FAIL se a posição for inválida.
 */
int removePosition(Linked *list, int Position)
{
    if (list == NULL || list->beginning == NULL)
        return INVALID_POINTER;

    Node *aux = list->beginning;
    Node *node = list->beginning;
    int count = 1;

    if (Position == 1)
    {
        list->beginning = list->beginning->next;
        free(node);
        return SUCCESS;
    }

    while ((node != NULL) && (count < Position)) 
    {
        aux = node;
        node = node->next;
        count++;
    }

    if (node == NULL)
        return FAIL;
    
    aux->next = node->next;
    free(node);

    return SUCCESS;
}

/**
 * @brief Exibe os elementos da lista encadeada no console.
 *
 * Esta função percorre a lista encadeada e exibe os elementos armazenados no console.
 *
 * @param list Um ponteiro para a lista encadeada a ser exibida.
 * @return SUCCESS se a lista foi exibida com sucesso ou INVALID_POINTER se o ponteiro da lista for inválido.
 */
int showList(Linked *list)
{
    if (list == NULL)
        return INVALID_POINTER;
    
    Node *aux = list->beginning;

    while (aux != NULL)
    {
        printf("[ %d ] ", aux->data.value);
        aux = aux->next;
    }

    printf("\n");
    
    return SUCCESS;
}

/**
 * @brief Retorna o tamanho da lista encadeada.
 *
 * Esta função calcula e retorna o número de elementos na lista encadeada.
 *
 * @param list Um ponteiro para a lista encadeada da qual se deseja saber o tamanho.
 * @return O tamanho da lista encadeada (número de elementos) ou 0 se a lista estiver vazia, ou INVALID_POINTER se o ponteiro da lista for inválido.
 */
int listSize(Linked *list)
{
    if (list == NULL)
        return INVALID_POINTER;
    if (list->beginning == NULL)
        return 0;
    
    int counter = 0;
    Node *aux = list->beginning;

    while (aux != NULL)
    {
        aux = aux->next;
        counter++;    
    }

    return counter;
}

/**
 * @brief Verifica se a lista encadeada está vazia.
 *
 * Esta função verifica se a lista encadeada está vazia, ou seja, se não contém nenhum elemento.
 *
 * @param list Um ponteiro para a lista encadeada a ser verificada.
 * @return 1 se a lista estiver vazia, 0 se a lista contiver elementos, ou INVALID_POINTER se o ponteiro da lista for inválido.
 */
int emptyList(Linked *list)
{
    if (list == NULL)
        return INVALID_POINTER;
    
    if (list->beginning == NULL)
        return 1;
    
    return 0;
}

/**
 * @brief Destrói a lista encadeada e libera toda a memória associada a ela.
 *
 * Esta função libera a memória de todos os nós da lista encadeada, bem como a memória da própria lista.
 *
 * @param list Um ponteiro para a lista encadeada a ser destruída.
 * @return SUCCESS se a lista foi destruída com sucesso, ou INVALID_POINTER se o ponteiro da lista for inválido.
 */
int destroyList(Linked *list)
{
    if (list == NULL || list->beginning == NULL)
        return INVALID_POINTER;
    
    Node *aux;
    while (list->beginning != NULL)
    {
        aux = list->beginning;
        list->beginning = list->beginning->next;
        free(aux);
    }
    
    free(list);
    return SUCCESS;
}

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
int findElement(Linked *list, Data data)
{
    if (list == NULL)
        return INVALID_POINTER;
    
    if (list->beginning == NULL)
        return FAIL;
    
    Node *aux = list->beginning;
    int counter = 1;

    while (aux != NULL)
    {
        if (aux->data.value == data.value)
            return counter;

        aux = aux->next;
        counter++;
    }

    return -1;
}

