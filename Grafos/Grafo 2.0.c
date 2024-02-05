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
    newList->vertex = NULL;
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
        if (graph->list_vertex->vertex == vertex_ID)
        {
            printf("Vertex already added, no action made\n");
            return;
        }
    }

    graph->qnt_vertex++;

    graph->list_vertex = realloc(graph->list_vertex, sizeof(List) * graph->qnt_vertex);

    
    
    
}



int main()
{

    return 0;
}
