#include <stdio.h>
#include <stdlib.h>

typedef struct info
{
    char vertex_ID;
    int arrayVertexPosition;
    int peso;
} Info;


typedef struct node
{
    Info information;
    struct node *next;
} Node;

typedef struct list
{
    char vertex;
    Node *inicio;
    Node *fim;
} List;

typedef struct graph
{
    List *list_vertex;
    int qnt_vertex;
} Graph;

List *createList()
{
    List *newList = (List *) malloc(sizeof(List));

    newList->inicio = NULL;
    newList->fim = NULL;
    newList->vertex = ' ';
    return newList;
}

Graph * createGraph()
{
    Graph *newGraph = (Graph *) malloc(sizeof(Graph));

    newGraph->list_vertex = createList();
    newGraph->qnt_vertex = 0;

    return newGraph;
}

void addVertex(Graph *graph, char vertex_ID)
{
    if (graph == NULL || graph->list_vertex == NULL)
        return;
    
    // Procurar se o vertice ja existe
    for (int i = 0; i < graph->qnt_vertex; i++)
    {
        if (graph->list_vertex[i].vertex == vertex_ID)
        {
            printf("Vertex [ %c ] already added, no action made\n", vertex_ID);
            return;
        }
    }

    graph->qnt_vertex++;

    // Aloca espaço no vetor para um novo vertice
    if (graph->qnt_vertex != 1)
        graph->list_vertex = realloc(graph->list_vertex, sizeof(List) * graph->qnt_vertex);
    
    else
        graph->list_vertex = (List *) malloc(sizeof(List));
    
    // Inicializa o novo vertice colocando o ID e deixando como NULL os ponteiros
    graph->list_vertex[graph->qnt_vertex - 1].vertex = vertex_ID;
    graph->list_vertex[graph->qnt_vertex - 1].inicio = NULL;
    graph->list_vertex[graph->qnt_vertex - 1].fim = NULL;
}

void viewVertex(Graph *graph)
{
    if (graph == NULL)
        return;
    
    for (int i = 0; i < graph->qnt_vertex; i++)
        printf("[ %c ]\n", graph->list_vertex[i].vertex);
}


int main()
{
    Graph *graph = createGraph();

    addVertex(graph, 'A');
    addVertex(graph, 'B');
    addVertex(graph, 'C');
    addVertex(graph, 'B');
    addVertex(graph, 'D');
    addVertex(graph, 'A');
    addVertex(graph, 'C');
    addVertex(graph, 'E');
    addVertex(graph, 'F');
    addVertex(graph, 'D');

    viewVertex(graph);

    return 0;
}
