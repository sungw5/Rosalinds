#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(){
    FILE *inputF = fopen("rosalind_bfs.txt", "r");
    assert(inputF != NULL);
    int n,m;


    fscanf(inputF, "%d %d\n", &n, &m);
    printf("n: %d m: %d\n", n,m);

    int *degrees;
    int *num_edges;
    int *adj;

    degrees = (int *)malloc(n * sizeof(int));
    num_edges = (int *)malloc((n+1) * sizeof(int));
    adj = (int *)malloc(m *sizeof(int));
    assert(degrees !=NULL);
    assert(num_edges !=NULL);
    assert(adj !=NULL);

    for(int i=0;i<n;i++){
        degrees[i] =0;
    }

    for(int i=0; i<m; i++){
        int u,v;
        fscanf(inputF, "%d %d\n", &u, &v);
        u--; 
        v--; 
        degrees[u]++;
    }

    num_edges[0] = 0;
    for(int i=0; i<=n; i++){
        num_edges[i] = num_edges[i-1] + degrees[i-1];
    }
    //reuse the array
    for(int i=0;i<n;i++){
        degrees[i] =0;
    }
    rewind(inputF); //go back to beginning of the file

    int n2,m2;
    fscanf(inputF, "%d %d\n", &n2, &m2);
    assert(n2 == n);
    assert(m2 == m);

    for(int i=0; i<m; i++){
        int u,v;
        fscanf(inputF, "%d %d\n", &u, &v);
        u--; 
        v--; 
        int vpos = num_edges[u] + degrees[u]++;
        adj[vpos] = v;
    }
    fclose(inputF);
    free(degrees);
    

    int *D =(int *) malloc (n*sizeof(int));
    assert(D != NULL);

    for(int i=0; i<n;i++){
        D[i] = -1;
    }
    D[0] = 0;

    int *Q = (int *)malloc(sizeof(int) * n);
    assert(Q != NULL);
    Q[0] = 0;
    int current = 0;
    int numvisited = 1;

    // actual traversal
    while(current < numvisited){
        int u = Q[current];
        for(int j=num_edges[u]; j<num_edges[u+1]; j++){
            int v = adj[j];
            if(D[v] == -1){
                D[v] = D[u]+1;
                Q[numvisited++] = v;
            }
        }
        current++;
    }

    printf("number of vertices visited: %d ", numvisited);

    //write output
    FILE *outputP = fopen("bfsoutput.txt", "w");
    for(int i=0;i<n;i++){
        fprintf(outputP, "%d ", D[i]);
    }
    fprintf(outputP, "\n");
    fclose(outputP);

    free(num_edges);
    free(adj);
    free(D);
    free(Q);

    return 0;
}