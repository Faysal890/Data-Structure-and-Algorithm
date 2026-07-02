#include<bits/stdc++.h>
using namespace std;
class DSU{
	int size;
	vector<int> par, rank;
public:
	DSU(int n) {
		size = n;
		for(int i = 0; i < n; i++) {
			par.push_back(i);
			rank.push_back(0);
		}
	}
	int find(int x) {
		if(par[x] == x) return x;
		return par[x] = find(par[x]);
	}
	void unionByRank(int x, int y) {
		int par_x = find(x);
		int par_y = find(y);
		if(par_x == par_y) return;
		if(rank[par_x] == rank[par_y]) {
			par[par_y] = par_x;
			rank[par_x]++;
		}
		else if(rank[par_x] > rank[par_y]) {
			par[par_y] = par[par_x];
		}
		else {
			par[par_x] = par[par_y];
		}
	}
};

class Edge{
public:
	int u, v, w;
};

bool cmp(Edge& a, Edge& b) {
	return a.w < b.w;
}

int kruskal(int n, vector<Edge>& edges) {
	DSU dsu(n);
	vector<pair<int, int>> mstEdge;
	sort(edges.begin(), edges.end(), cmp);
	int count = n - 1, mst = 0;
	for(int i = 0; i < edges.size(); i++) {
		int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
		int par_u = dsu.find(u);
		int par_v = dsu.find(v);
		if(par_u != par_v) {
			dsu.unionByRank(u, v);
			mst += w;
			mstEdge.push_back({u, v});
			if(--count == 0) break;
		}
	}
	return mst;
}

int main() {
	int i, n, u, v, w, edge, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> graph(n);
	vector<Edge> edges;
	for(i = 0; i < m; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
		edges.push_back({u, v, w});
	}
	int mst = kruskal(n, edges);
	cout << mst << '\n';
}