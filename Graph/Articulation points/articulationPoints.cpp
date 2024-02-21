//Tarjan's Algorithm
//Time complexity : O(V+E)

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> generateGraph() {
    int i, vertex, edges, u, v;
    cout << "Enter number of vertex : ";
    cin >> vertex;
    vector<vector<int>> graph(vertex);
    cout << "Enter number of edges : ";
    cin >> edges;
    cout << "Enter edges :\nu v\n";
    while(edges-- > 0) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    return graph;
}

void tarjanAlgo(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& dis, vector<int>& low, int curr, int parent, int& time, vector<int>& ap) {
    if(visited[curr]) {
        return ;
    }
    visited[curr] = true;
    dis[curr] = low[curr] = ++time;
    int child = 0;
    for(int i=0; i<graph[curr].size(); i++) {
        if(graph[curr][i]==parent) {
            continue;
        }
        else if(visited[graph[curr][i]]) {
            low[curr] = min(low[curr], dis[graph[curr][i]]);
        }
        else{
            tarjanAlgo(graph, visited, dis, low, graph[curr][i], curr, time, ap);
            low[curr] = min(low[curr], low[graph[curr][i]]);
            if(dis[curr]<=low[graph[curr][i]] && parent!=-1) {
                ap[curr] = 1;
            }
            child++;
            if(child>=2 && parent == -1 ) {
                ap[curr] = 1;
            }
        }
    }
}

int main() {
    vector<vector<int>>graph;
    graph = generateGraph();
    vector<bool>visited(graph.size(),false);
    vector<int>dis(graph.size()), low(graph.size()), ap(graph.size(),0);
    int time = 0, i;
    cout << "Articulation Points : ";
    for(i=0; i<graph.size(); i++) {
        if(!visited[i]) {
            tarjanAlgo(graph, visited, dis, low, i, -1, time, ap);
        }
    }
    for(i=0; i<graph.size(); i++) {
        if(ap[i] == 1) {
            cout << i << " ";
        }
    }
}
