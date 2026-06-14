#include<bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& st) {
	if(visited[u]) return ;
	visited[u] = true;
	for(int v : graph[u]) {
		if(!visited[v]) {
			dfs(v, graph, visited, st);
		}
	}
	st.push(u);
}

void topoSort(int n, vector<vector<int>>& graph) {
	vector<bool> visited(n, false);
	stack<int> st;
	for(int i = 0; i < n; i++) {
		if(!visited[i]) {
			dfs(i, graph, visited, st);
		}
	}
	while(!st.empty()) {
		cout << st.top() << ' ';
        st.pop();
	}
	cout << '\n';
}

int main() {
	int i, n, u, v, e;
	cin >> n >> e;
	vector<vector<int>> graph(n);
	for(i = 0; i < e; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
	}
	topoSort(n, graph);
}