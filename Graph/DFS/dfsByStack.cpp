//Depth First Search
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
        graph[v].push_back(u);
    }
    return graph;
}

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int curr) {
    stack<int>st;
    st.push(curr);
    while(!st.empty()) {
        curr = st.top();
        st.pop();
        if(visited[curr]){
            continue;
        }
        cout << curr << " ";
        visited[curr] = true;
        for(int i=0; i<graph[curr].size(); i++) {
            if(!visited[graph[curr][i]]) {
                st.push(graph[curr][i]);
            }
        }
    }
}

int main() {
    vector<vector<int>>graph;
    graph = generateGraph();
    vector<bool>visited(graph.size(),false);
    cout << "Following Depth First Search :\n";
    for(int i=0; i<graph.size(); i++) {
        if(!visited[i]) {
            dfs(graph, visited, i);
        }
    }
}