#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

#define mp make_pair

#define LSOne(S) (S & (-S))

//kruskul/boruvka
struct DSU {
	vi e; void init(int N) { e = vi(N,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};

const int mxN = 1e5 + 5;

int N, M;
vi adjList[mxN];

DSU d;
vi queries[mxN];
int ancestor[mxN];
bool visited[mxN];

map<ii, int> lcas;

void dfs1(int u) {
	visited[u] = true;
	ancestor[u] = u;
	for (auto v : adjList[u]) {
		if (!visited[v]) {
			dfs1(v);
			d.unite(u, v);
			ancestor[d.get(u)] = u;
		}
	}
	for (auto v : queries[u]) {
		if (visited[v]) {
			lcas[ii(u, v)] = ancestor[d.get(v)];
			lcas[ii(v, u)] = ancestor[d.get(v)];
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		adjList[a].pb(b);
		adjList[b].pb(a);
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		queries[a].pb(b);
		queries[b].pb(a);
	}
	dfs1(1);
}
