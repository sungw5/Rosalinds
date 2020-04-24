#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(){
    FILE *inputF = fopen("rosalind_deg.txt", "r");
    assert(inputF != NULL);
    int n,m;
    int *degrees;

    // get n(# of vertices) and m(# of edges)
    fscanf(inputF, "%d %d\n", &n, &m);
    printf("n: %d m: %d\n", n,m);

    // allocate and initialize
    degrees = (int *)malloc(n * sizeof(int));
    assert(degrees !=NULL);
    for(int i=0;i<n;i++){
        degrees[i] =0;
    }

    // get inputs
    for(int i=0; i<m; i++){
        int u,v;
        fscanf(inputF, "%d %d\n", &u, &v);
        u--; 
        v--; 
        degrees[u]++;
        degrees[v]++;
    }
    fclose(inputF);

    // write output
    FILE *outputP = fopen("degoutput.txt", "w");
    for(int i=0;i<n;i++){
        fprintf(outputP, "%d ", degrees[i]);
    }
    fprintf(outputP, "\n");

    // close and free
    fclose(outputP);
    free(degrees);

    return 0;
}