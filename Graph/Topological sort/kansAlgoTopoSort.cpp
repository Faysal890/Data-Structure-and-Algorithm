#include<bits/stdc++.h>
using namespace std;
int main() {
	int u, v, edge, n;
	cin >> n >> edge;
	vector<vector<int>> graph(n);
	vector<int> indeg(n, 0);
	for(int i = 0; i < edge; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		indeg[v]++;
	}
	queue<int> q;
	for(int i = 0; i < n; i++) {
		if(indeg[i] == 0) q.push(i);
	}
	while(!q.empty()) {
		u = q.front();
		cout << u << ' ';
		q.pop();
		for(int v : graph[u]) {
			indeg[v]--;
			if(indeg[v] == 0) q.push(v);
		}
	}
	
}