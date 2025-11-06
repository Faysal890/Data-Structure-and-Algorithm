#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int v[N];

class SegTree{
public:
	int t[4 * N];
	void build(int node, int l, int r) {
		if(l == r) {
			t[node] =  v[l];
			return;
		}
		int a = 2 * node, b = (2 * node) + 1, mid = (l + r) / 2;
		build(a, l, mid);
		build(b, mid + 1, r);
		t[node] = t[a] + t[b];
	}

	int query(int node, int l, int r, int i, int j) {
		if(l > j || r < i) return 0;
		if(i <= l && r <= j) return t[node];
		int a = node * 2, b = (node * 2 + 1), mid = (l + r) / 2;
		return query(a, l, mid, i, j) + query(b, mid + 1, r, i, j);
	}

	void update(int node, int l, int r, int i, int x) {
		if(i > r || l > i) return;
		if(l == r && l == i) {
			v[i] = x;
			t[node] = x;
			return;
		}
		int a = node * 2, b = node * 2 + 1, mid = (l + r) / 2;
		update(a, l, mid, i, x);
		update(b, mid + 1, r, i, x);
		t[node] = t[a] + t[b];
	}
};
int main() {
	cout << "Hello World" << endl;
	
}