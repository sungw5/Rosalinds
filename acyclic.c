#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct node{
    int vertex;
    struct node *next;
}node;

typedef struct{
    int n;
    node **adjList;
}Graph;

node *createNode(int v){
    node *newNode = malloc(sizeof(node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
// create graph and adj list
Graph *makeGraph(int N){
    Graph *graph = malloc(sizeof(Graph));
    graph->n = N;
    graph->adjList = malloc(sizeof(node*) * N);
    int i;
    for(i=0; i<N; i++){
        graph->adjList[i] = NULL;
    }
    return graph;
}
// create edge
void addEdge(Graph *graph, int x, int y){
    node *newNode = createNode(y);
    newNode->next = graph->adjList[x];
    graph->adjList[x] = newNode;

    newNode = createNode(x);
    newNode->next = graph->adjList[y];
    graph->adjList[y] = newNode;

}

void printGraph(Graph *graph){
    int i;
    for(i=0; i<graph->n; i++){
        node *temp = graph->adjList[i];
        printf("\n Adjacency list of vertex %d\n ", i);
        while(temp){
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");

    }
}

int main(){
    int i;
    FILE *inputP;
    int k, n, m;
    int u,v;
    
    inputP = fopen("rosalind_acyclic.txt", "r");
    assert(inputP != NULL);
    // get number of trials
    fscanf(inputP, "%d\n", &k);
    
    for(int ki=0; ki<k; ki++){

        Graph *graph = makeGraph(n); // create vertices with n vertices
        fscanf(inputP, "%d %d", &n, &m); // get # of vertices and # of edges
        for(i=0; i<m; i++){
            fscanf(inputP, "%d %d", &u, &v);
            addEdge(graph, u, v); // add edges to vertices
        }
        printGraph(graph);
    }
    
    
    fclose(inputP);
    



    return 0;
}