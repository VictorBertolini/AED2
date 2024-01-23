#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAIL 1
#define INVALID_POINTER -1

typedef struct node
{
    int num; // usado como o ID do vértice
    struct node *prox; // proximo nó da lista
} Node;

typedef struct list
{
    Node *beggin; // Ponteiro para o nó inicial
    int token; // ID da lista (método de localização dela)
} List;


typedef struct graph
{
    List *arrayVertex; // Vetor onde se guarda os vértices e a partir deles suas conexões
    int numVertex; // Número de vértices existentes
} Graph;

// Função para criar um grafo
Graph * createGraph()
{
    Graph *newGraph = (Graph *) malloc(sizeof(Graph));
    newGraph->arrayVertex = NULL;
    newGraph->numVertex = 0;

    return newGraph;
}

// Função para criar uma lista
List * createList()
{
    List *newList = (List *) malloc(sizeof(List));
    newList->beggin = NULL;
    newList->token = -1;

    return newList;
}

// Função para adicionar um vértice ao grafo
int addVertex(Graph *graph, int token)
{
    if (graph == NULL)
        return INVALID_POINTER;
    
    // Verificar se o token já existe
    for (int i = 0; i < graph->numVertex; i++)
    {
        if (graph->arrayVertex[i].token == token)
        {
            printf("The token [ %d ] is already added\n", token);
            return FAIL;
        }
    }
    
    // Vai verificar se é a primeira vez que está lidando com o vetor de ponteiros para lista
    // Se não for a primeira vez ele dará um realloc
    if (graph->numVertex != 0)
    {
        graph->numVertex++;
        graph->arrayVertex = realloc(graph->arrayVertex, graph->numVertex * sizeof(List));
    }
    // Se for a primeira vez então ele vai criar/alocar o vetor de listas encadeadas
    else 
    {
        graph->numVertex++;
        graph->arrayVertex = (List *) malloc(sizeof(List));
    }

    // Vai deixar a lista limpa (NULL) e adicionar o token (ID do vértice)
    graph->arrayVertex[graph->numVertex - 1].beggin = NULL;
    graph->arrayVertex[graph->numVertex - 1].token = token;
    

    return SUCCESS;
}

// Ver todos os vértices do conjunto
int viewVertex(Graph *graph)
{
    if (graph == NULL)
        return INVALID_POINTER;
    
    // Printar na tela os vértices
    for (int i = 0; i < graph->numVertex; i++)
        printf("%d - [ %d ]\n", i + 1, graph->arrayVertex[i].token);
    
    return 0;
}

// Adicionar um nó em uma lista encadeada
int addNode(List *list, int token)
{
    if (list == NULL)
        return INVALID_POINTER;
    
    Node *node = (Node *) malloc(sizeof(Node));
    node->num = token;
    node->prox = list->beggin;
    list->beggin = node;

    return SUCCESS;
}

// Adicionar um arco (conexão/aresta) entre dois vértices
int addArc(Graph *graph, int starterVertex, int destinyVertex)
{
    // Verificação se o grafo é válido para ser utilizado
    if (graph == NULL || graph->arrayVertex == NULL)
        return INVALID_POINTER;
    
    
    int 
        starterPosition = -1, // Armazena a posição do vértice de saída no vetor
        destinyPosition = -1, // Armazena a posição do vértice de chegada no vetor
        count = 0; // Variável para finalizar o 'for' quando já encontrar as 2 informações (poupar memória e processamento)


    // Pegar a posição dos vértices no vetor para puxar as informações do destino e colocar na lista de início
    for (int i = 0; i < graph->numVertex && count != 2; i++)
    {
        if (graph->arrayVertex[i].token == starterVertex)
        {
            starterPosition = i;
            count++;
        }

        if (graph->arrayVertex[i].token == destinyVertex)
        {
            destinyPosition = i;
            count++;
        }
    }

    // Caso não encontre algum dos vértices mostra uma mensagem na tela indicando qual é inválido
    if (count != 2)
    {
        if (starterPosition == -1)
            printf("There are a invalid token in %d startedVertex!\n", starterVertex);
        else
            printf("There are a invalid token in %d destinyVertex!\n", destinyVertex);
        
        return FAIL;
    }

    // Ver se a conexão entre os vértices já existe
    for (Node *aux = graph->arrayVertex[starterPosition].beggin; aux != NULL; aux = aux->prox)
    {
        if (aux->num == destinyVertex)
        {
            printf("The arc between %d and %d already exist!\n", starterVertex, destinyVertex);
            return FAIL;
        }
    }
    
    // Adiciona o nó na lista do grafo de saída
    addNode(&graph->arrayVertex[starterPosition], graph->arrayVertex[destinyPosition].token);

    return SUCCESS;
}

// Ver a lista de arestas de um dos vértices
int viewArc(Graph *graph, int vertexToken)
{
    if (graph == NULL || graph->arrayVertex == NULL)
        return INVALID_POINTER;

    // Vai procurar a posição do vértice requerido e colocar em 'position'
    int position = -1;
    for (int i = 0; i < graph->numVertex; i++)
    {
        if (graph->arrayVertex[i].token == vertexToken)
        {
            position = i;
            break;
        } 
    }

    // Se não encontrar o vértice requerido retorna invalido
    if (position == -1)
    {
        printf("Invalid VertexToken!\n");
        return FAIL;
    }
    
    // Caso ache o vértice então vai colcoar ele na tela 
    printf("| %d | ", graph->arrayVertex[position].token);
    for (Node *node = graph->arrayVertex[position].beggin; node != NULL; node = node->prox)
    {
        printf("[ %d ] ", node->num);
    }
    
    return SUCCESS;
}

// Função para ver o grafo inteiro 
int viewGraph(Graph *graph)
{
    if (graph == NULL || graph->arrayVertex == NULL)
        return INVALID_POINTER;

    for (int i = 0; i < graph->numVertex; i++)
    {
        printf("\n| %d | -", graph->arrayVertex[i].token);

        for (Node *aux = graph->arrayVertex[i].beggin; aux != NULL; aux = aux->prox)
            printf("-> [ %d ] ", aux->num);
    }

    return SUCCESS;
}

int main()
{
    Graph *graph = createGraph();

    addVertex(graph, 10);
    addVertex(graph, 20);
    addVertex(graph, 30);
    addVertex(graph, 20);

    viewVertex(graph);

    addArc(graph, 10, 20);
    addArc(graph, 10, 30);
    addArc(graph, 10, 10);

    addArc(graph, 20, 20);
    addArc(graph, 20, 10);


    addArc(graph, 30, 10);



    viewGraph(graph);

    return 0;
}

