#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<ii>
#define pb push_back
#define INF 2000000000
#define LSOne(S) (S & (-S))

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	//freopen((s + ".out").c_str(), "w", stdout);
}

const int mxN = 1e5 + 5;

int N, M;
vi adjList[mxN];

bool visited[mxN];

int timer = 0, tin[mxN], tout[mxN];
int anc[mxN][18];

void dfs1() {
    stack<ii> st; st.push(ii(1, 1));
    visited[1] = true;
    int cont = false;
    while (!st.empty()) {
		ii top = st.top();
		int u = top.first, p = top.second;
		visited[u] = true;
		cont = false;
		if (!tin[u]) {
			tin[u] = ++timer;
			anc[u][0] = p;
			for (int i = 1; i < 18; i++)
				anc[u][i] = anc[anc[u][i - 1]][i - 1];
		}
		for (auto v : adjList[u]) {
			if (!visited[v]) {
				st.push(ii(v, u));
				cont = true;
				break;
			}
		}
		if (!cont) {
			tout[u] = ++timer;
			st.pop();
		}
	}
}

bool is_anc(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_anc(u, v))
		return u;
	if (is_anc(v, u)) 
		return v;
	for (int i = 17; i >= 0; i--) {
		if (!is_anc(anc[u][i], v))
			u = anc[u][i];
	}
	return anc[u][0];
}

int main() {
	setIO("test");
	cin >> N;
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		adjList[a].pb(b);
		adjList[b].pb(a);
	}
	dfs1();
	cout << lca(3, 4) << endl;
}
