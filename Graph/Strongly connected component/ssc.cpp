//Kosaraju algorithm
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
    while(edges-->0) {
        cin >> u >> v;
        graph[u].push_back(v);
    }
    return graph;
}

vector<vector<int>> reverseGraph(vector<vector<int>>& graph) {
    int v = graph.size(), i, j;
    vector<vector<int>> revGraph(v);
    for(i=0; i<v; i++) {
        for(j=0; j<graph[i].size(); j++) {
            revGraph[graph[i][j]].push_back(i);
        }
    }
    return revGraph;
}

void topoSort(vector<vector<int>>& graph, vector<bool>& visited, int curr, stack<int>& st) {
    if(visited[curr]) {
        return ;
    }
    visited[curr] = true;
    for(int i=0; i<graph[curr].size(); i++) {
        if(!visited[graph[curr][i]]) {
            topoSort(graph, visited, graph[curr][i], st);
        }
    }    
    st.push(curr);
}

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int curr) {
    if(visited[curr]) {
        return;
    }
    visited[curr] = true;
    cout << curr << " ";
    for(int i=0; i<graph[curr].size(); i++) {
        if(!visited[graph[curr][i]]) {
            dfs(graph, visited, graph[curr][i]);
        }
    }
}

void kosarajuAlgo(vector<vector<int>>& graph, vector<bool>& visited, stack<int>& st) {
    while(!st.empty()) {
        if(!visited[st.top()]) {
            dfs(graph, visited, st.top());
            cout << "\n";
        }
        st.pop();
    }
}

int main() {
    vector<vector<int>>graph, revGraph;
    graph = generateGraph();
    vector<bool>visited(graph.size(),false);
    stack<int>st;
    for(int i=0; i<graph.size(); i++) {
        if(!visited[i]) {
            topoSort(graph, visited, i, st);
        }
    }
    revGraph = reverseGraph(graph);
    visited = vector<bool>(graph.size(),false);
    cout << "Strongly connected components are: \n";
    kosarajuAlgo(revGraph, visited, st);
    
}