#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<assert.h>

#define INF 987654321
using namespace std;

vector<pair<int, int> > adj[1000];
int dist[1000]; 


void dijkstra(int start, int n){
    // initialize the distance of starting point to zero
    dist[start] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push(make_pair(0, start));
    
    while(!pq.empty()){
        //pop the vertex with shortest distance
        int cost = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        // if there's shorter path, then ignore what we just popped (skip this index)
        if(cost > dist[current]) continue;
        // check all neighbor vertices
        for(int i=0; i<adj[current].size(); i++){

            int next = adj[current][i].first; // next vertex
            int nextcost = adj[current][i].second; // distance to next vertex
            // relaxation
            if(dist[next] > dist[current] + nextcost){
                dist[next] = dist[current] + nextcost;   // dist(u) = dist(u) + l(u,v)  #from textbook
                pq.push(make_pair(dist[next], next));    // push the info to the queue
            }
        }
    }
}

int main(){
    int n,m;
    int u,v,w;
    int i;
    
    // open input file
    FILE *inputP = fopen("rosalind_dijkstra.txt", "r");
    assert(inputP != NULL);

    // get # of vertices and # of edges
    fscanf(inputP, "%d %d", &n, &m);

    // initialize dist with infinity
    for(i=0; i<=n; i++){
        dist[i] = INF;
    }

    //get input values u, v, weight
    for(i=0; i<m; i++){
        fscanf(inputP, "%d %d %d", &u, &v, &w);
        adj[u].push_back(make_pair(v,w)); // adjacency list update
    }
    ///////////////////////////

    dijkstra(1, n);

    ///////////////////////////
    FILE *outputP = fopen("dijkstraoutput.txt", "w");

    for(i=1; i<=n; i++){
        if(dist[i] == INF){
            dist[i] = -1;
        }
        fprintf(outputP, "%d ", dist[i]);
    }
    fprintf(outputP, "\n");

    fclose(inputP);
    fclose(outputP);

    return 0;
}