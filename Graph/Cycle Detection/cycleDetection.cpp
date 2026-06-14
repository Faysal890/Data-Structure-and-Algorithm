#include<bits/stdc++.h>
using namespace std;
bool hasCycle(int u, vector<vector<int>>& graph, vector<bool>& visited, int parent) {
    visited[u] = true;
    for(int v : graph[u]) {
        if(!visited[v]) {
            if(hasCycle(v, graph, visited, u)) {
                return true;
            }
        }
        else if(v != parent) {
            return true;
        }
    }
    return false;
}
bool isCyclicDFS(vector<vector<int>>& graph, int n) {
    vector<bool> visited(n, false);
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(hasCycle(i, graph, visited, -1)) {
                return true;
            }
        }
    }
    return false;
}

bool bfsCycleCheck(int u, vector<vector<int>>& graph, vector<bool>& visited) {
    queue<pair<int, int>> q;
    q.push({u, -1});
    visited[u] = true;
    while(!q.empty()) {
        int u = q.front().first;
        int parU = q.front().second;
        q.pop();
        for(int v : graph[u]) {
            if(!visited[v]) {
                visited[v] = true;
                q.push({v, u});
            }
            else if(v != parU) return true;
        }
    }
    return false;
}

bool isCyclicBFS(vector<vector<int>>& graph, int n) {
    vector<bool> visited(n, false);
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(bfsCycleCheck(i, graph, visited)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int i, u, v, n, e;
    cin >> n >> e;
    vector<vector<int>> graph(n);
    for(i = 0; i < e; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    if(isCyclicDFS(graph, n)) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
    if(isCyclicBFS(graph, n)) {
        cout << "Cyclic\n";
    }
    else {
        cout << "Acyclic\n";
    }
}