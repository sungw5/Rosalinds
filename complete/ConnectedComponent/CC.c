#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int Graph[1000][1000];
int *visited;
int ccnum = 0;

void dfs(int *visited, int u, int n){
    int v;
    if(visited[u]) return;
    visited[u] = 1;
    for(v=1; v<=n; v++){
        if(Graph[u][v] == 1 && !visited[v]){
            dfs(visited, v, n);
        }
    }
}

int main(){
    int i,j;
    FILE *inputP, *outputP;
    int n,m;
    int x,y;

    inputP = fopen("rosalind_CC.txt", "r");
    assert(inputP != NULL);
    
    fscanf(inputP, "%d %d", &n, &m);

    // initialize graph
    for(i=0; i<=n; i++){
        for(j=0; j<=n; j++){
            Graph[i][j] = 0;
        }
    }

    // initialize visited array
    visited = (int *)malloc(sizeof(int) * n);
    for(i=0; i<=n; i++){
        visited[i] = 0;
    }

    // get input values and fill it in adj matrix
    for(i=0; i<m; i++){
        fscanf(inputP, "%d %d", &x, &y);
        Graph[x][y] = 1;
        Graph[y][x] = 1;
    }
    fclose(inputP);

     // print adj matrix
    for(i=0; i<=n; i++){
        for(j=0; j<=n; j++){
            printf("%d ", Graph[i][j]);
            if(j==n){
                printf("\n");
            }
        }
    }

    // run DFS and record ccnum each time dfs is run
    for(i=1; i<=n; i++){
        if(!visited[i]){
            dfs(visited, i, n);
            ccnum++;
        }
    }


    outputP = fopen("CCoutput.txt", "w");
    
   

    fprintf(outputP, "%d\n", ccnum);


////////////////////////////////////////
    fclose(outputP);
    free(visited);

    return 0;
}