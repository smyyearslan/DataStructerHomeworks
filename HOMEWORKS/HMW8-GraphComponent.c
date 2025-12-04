#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100 

typedef struct AdjListNode {
    int dest;
    struct AdjListNode* next;
} AdjListNode;

typedef struct Graph {
    int V;             
    AdjListNode* array[MAX_NODES];
    int visited[MAX_NODES];   
} Graph;

AdjListNode* newAdjListNode(int dest) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    if (newNode == NULL) {
        perror("Bellek ayýrma hatasý");
        exit(EXIT_FAILURE);
    }
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

void initializeGraph(Graph* graph, int V) {
    graph->V = V;
    for (int i = 0; i < V; ++i) {
        graph->array[i] = NULL;
        graph->visited[i] = 0;
    }
}

void addEdge(Graph* graph, int src, int dest) {
    AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src];
    graph->array[src] = newNode;

    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest];
    graph->array[dest] = newNode;
}

void DFS(Graph* graph, int v) {
    graph->visited[v] = 1;
    printf("%d ", v); 

    AdjListNode* pCrawl = graph->array[v];
    while (pCrawl != NULL) {
        int dest = pCrawl->dest;
        
        if (!graph->visited[dest]) {
            DFS(graph, dest);
        }
        pCrawl = pCrawl->next;
    }
}

void findConnectedComponents(Graph* graph) {
    int component_count = 0;
    
    for (int i = 0; i < graph->V; i++) {
        if (graph->visited[i] == 0) {
            component_count++;
            printf("\n--- Bileþen %d (Düðüm %d'den Baþladý) ---\n", component_count, i);
            
            DFS(graph, i);
        }
    }
    printf("\n\nToplam Baðlantýlý Bileþen Sayýsý: %d\n", component_count);
}

void destroyGraph(Graph* graph) {
    for (int i = 0; i < graph->V; ++i) {
        AdjListNode* current = graph->array[i];
        AdjListNode* next;
        while (current != NULL) {
            next = current->next;
            free(current);
            current = next;
        }
    }
}

int main() {
	
    int V = 9;
    Graph graph;
    
    initializeGraph(&graph, V);

    addEdge(&graph, 0, 1); // V1-V2
    addEdge(&graph, 1, 3); // V2-V4
    addEdge(&graph, 1, 2); // V2-V3
    addEdge(&graph, 2, 4); // V3-V5
    addEdge(&graph, 3, 2); // V4-V3
    addEdge(&graph, 3, 4); // V4-V5

    addEdge(&graph, 5, 6); // V6-V7
    addEdge(&graph, 6, 7); // V7-V8
    addEdge(&graph, 5, 8); // V6-V9
    addEdge(&graph, 7, 8); // V8-V9
    

    printf("--- Graf Baðlantýlý Bileþen Arama (DFS Kullanarak) ---\n");
    
    findConnectedComponents(&graph);
    
    destroyGraph(&graph);
    
    return 0;
}

