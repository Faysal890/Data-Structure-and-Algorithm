#include<bits/stdc++.h>
using namespace std;
void bellmanFord(int src, int dst, vector<vector<pair<int, int>>>& graph, int n) {
    int i, u, v, inf = 1e9;
    vector<int> dest(n, inf);
    dest[src] = 0;
    for(i = 0; i < n - 1; i++) {
        for(u = 0; u < n; u++) {
            for(auto [v, w] : graph[u]) {
                if(dest[v] > dest[u] + w) {
                    dest[v] = dest[u] + w;
                }
            }
        }
    }
    for(i = 0; i < n; i++) {
        cout << dest[i] << ' ';
    }
    cout << endl;
    cout << "Src: " << src << " Dst: " << dst << " Dist: " << dest[dst] << endl;
}
int main() {
    int i, u, v, n, edge, w, src, dest;
    cin >> n >> edge;
    vector<vector<pair<int, int>>> graph(n);
    for(i = 0; i < edge; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    cin >> src >> dest;
    bellmanFord(src, dest, graph, n);
}