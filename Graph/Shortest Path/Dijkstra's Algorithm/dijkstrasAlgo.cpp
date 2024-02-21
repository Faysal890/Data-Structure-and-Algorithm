//Dijkstra's Algorithm
//Time complexity : O(V + E logV)
#include<bits/stdc++.h>
using namespace std;
class cmp{
public:
    bool operator()(pair<int,int>& a, pair<int,int>& b) {
        return a.second>b.second;
    }
};

vector<vector<pair<int,int>>> generateGraph() {
    int i, vertex, edges, u, v, w;
    cout << "Enter number of vertex : ";
    cin >> vertex;
    vector<vector<pair<int,int>>> graph(vertex);
    cout << "Enter number of edges : ";
    cin >> edges;
    cout << "Enter edges(u,v) and weights(w) :\nu v w\n";
    while(edges-- > 0) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    return graph;
}

void dijkstra(vector<vector<pair<int,int>>>& graph, vector<int>& dest, int startPoint) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp>pq;
    vector<bool>visited(graph.size(), false);
    pq.push({startPoint,0});
    int u, w, i;
    while(!pq.empty()) {
        u = pq.top().first;
        w = pq.top().second;
        pq.pop();
        if(visited[u]) {
            continue;
        }
        visited[u] = true;
        dest[u] = w;
        for(i=0; i<graph[u].size(); i++) {
            pq.push({graph[u][i].first, w+graph[u][i].second});
        }
    }
}

int main() {
    vector<vector<pair<int,int>>>graph;
    graph = generateGraph();
    vector<bool>visited(graph.size(),false);
    vector<int>dest(graph.size(), INT_MAX);
    int startPoint;
    cout << "Enter start point: ";
    cin >> startPoint;
    dijkstra(graph, dest, startPoint);
    cout << "Vertex    distance\n";
    for(int i=0; i<graph.size(); i++) {
        if(dest[i]==INT_MAX) {
            cout << i << "         " << "Infinity" << "\n";
        }
        else {
            cout << i << "         " << dest[i] << "\n";
        }
    }
}