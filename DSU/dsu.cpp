#include<bits/stdc++.h>
using namespace std;
class DSU {
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
		if(par_x == par_y) {
			return;
		}
		if(rank[par_x] == rank[par_y]) {
			par[par_y] = par_x;
			rank[par_x]++;
		}
		else if(rank[par_x] > rank[par_y]) {
			par[par_y] = par_x;
		}
		else {
			par[par_x] = par[par_y];
		}
	}
};

int main() {
	int i, n, x, y, op, numOp;
	cin >> n >> numOp;
	DSU dsu(n);
	for(i = 0; i < numOp; i++) {
		cin >> op;
		if(op == 1) {
			cin >> x >> y;
			dsu.unionByRank(x, y);
		}
		else {
			cin >> x;
		    cout <<	dsu.find(x) << '\n';
		}
	}
}