#include <iostream>
#include <cstdio>
#include <vector>
#include <assert.h>

using namespace std;

vector<int> adj[1000];
int visited[1000];
bool nocycle;

void dfs(int u){
    nocycle = true;
    visited[u] = 1;
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        // if not visited, run DFS
        if(visited[v] == 0){
            dfs(v);
        }
        // if visited, there's a cycle
        else if(visited[v] == 1){
            nocycle = false;
            return;
        }
    }
    // reset array
    visited[u] = -1;
}


int main(){
    int i,k;
    int n,m;
    int u,v;

    FILE *inputP = fopen("rosalind_acyclic.txt", "r");
    assert(inputP != NULL);
    
    fscanf(inputP, "%d\n", &k);
    // get multiple input trials
    for(int ki=0; ki<k; ki++){
        bool isdag = true;
        for(i=0; i<n; i++){
            fill(adj[i].begin(), adj[i].end(), 0);
            visited[i] = 0;
        }

        fscanf(inputP, "%d %d", &n, &m); // get # of vertices and # of edges
        for(i=0; i<m; i++){
            fscanf(inputP, "%d %d", &u, &v);
            adj[u].push_back(v); // connect edge
        }

        for(i=1; i<=n && isdag; i++){
            
            // if not visited, run DFS
            if(visited[i] == 0){
                dfs(i);
                isdag = nocycle;
            }   
        }
        // print result
        if(isdag) printf("1 ");
        else printf("-1 ");
    }

    printf("\n");
    return 0;
}