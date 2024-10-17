#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b){
    return a[2] < b[2]; // cmp edge weights
}

void makeset(vector<int>& parent, vector<int>& rank, int n){
    for (int i = 0; i < n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int find_parent(vector<int>& parent, int node){
    if (parent[node] != node){
        parent[node] = find_parent(parent, parent[node]); // Path compression logic
    }
    return parent[node];
}

void union_set(int u, int v, vector<int>& parent, vector<int>& rank){
    u = find_parent(parent, u);
    v = find_parent(parent, v);

    if (rank[u] < rank[v]){
        parent[u] = v;
    } 
    else if (rank[v] < rank[u]){
        parent[v] = u;
    } 
    else{
        parent[v] = u;
        rank[u]++;
    }
}

int minimum_spanning_tree(vector<vector<int> >& edges, int n){

    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    makeset(parent, rank, n);

    int minWeight = 0;

    for (int i = 0; i < edges.size(); i++){
        int u = find_parent(parent, edges[i][0]);
        int v = find_parent(parent, edges[i][1]);
        int wt = edges[i][2];

        if (u != v) {
            minWeight += wt;
            union_set(u, v, parent, rank);
            cout << edges[i][0]<<" -- "<< edges[i][1]<<" == "<<edges[i][2]<<endl;
        }
    }
    return minWeight;
}

int main() {
    int n = 4; // vertices
    vector<vector<int> > edges;

    edges.push_back({0, 1, 10});
    edges.push_back({0, 2, 6});
    edges.push_back({0, 3, 5});
    edges.push_back({1, 3, 15});
    edges.push_back({2, 3, 4});

    int result = minimum_spanning_tree(edges, n);
    cout << "weight of the mst: " <<result<<endl;

}