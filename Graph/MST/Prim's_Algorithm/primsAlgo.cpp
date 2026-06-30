#include<bits/stdc++.h>
using namespace std;

int primsAlgo(int n, vector<vector<pair<int, int>>>& graph) {
	int u, v, w, mst = 0;
	vector<bool> visited(n, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, 0});
	while(!pq.empty()) {
		auto [w, u] = pq.top();
		pq.pop();
        if(visited[u]) continue;
		visited[u] = true;
		mst += w;
		for(auto [v, w] : graph[u]) {
			if(!visited[v]) {
				pq.push({w, v});
			}
		}
	}
	return mst;
}

int main() {
	int i, n, u, v, w, edge;
	cin >> n >> edge;
	vector<vector<pair<int, int>>> graph(n);
	for(i = 0; i < edge; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}
	int mst = primsAlgo(n, graph);
	cout << mst << '\n';
}