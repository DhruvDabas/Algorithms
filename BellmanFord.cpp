#include <iostream>
#include <vector>
using namespace std;

int bellman_ford(int n, int m, int src, int dest, vector<vector<int>>& edges){
    vector<int> dist(n + 1, 1e9);
    dist[src] = 0; // initial distance from src

    for (int i = 1; i < n; i++){ // traverse all edge
        for (int j = 0; j < m; j++){ // for n-1 time relax
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != 1e9 && (dist[u] + wt) < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }

    // check for negative cycles if any present
    bool flag = false;
    
    for (int i = 1; i < n; i++){
        for (int j = 0; j < m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != 1e9 && (dist[u] + wt) < dist[v]){
                flag = true;
            }
        }
    }

    if (flag == true){
        cout << "Graph has a negative cycle" <<endl;
        return -1;
    } 
    else{
        cout << "no negative cycles" <<endl;
        return dist[dest];
    }
}

int main(){

    int n = 3; // vertices
    int m = 3; // edges

    vector<vector<int>> edges;

    edges.push_back({1, 2, 2});
    edges.push_back({2, 3, -1});
    edges.push_back({3, 1, 2});

    int src = 1;
    int dest = 3;
    int distance = bellman_ford(n, m, src, dest, edges);

    if (distance != -1){
        cout << "distance from "<<src<<" to "<<dest<<" is "<<distance<<endl;
    }
}