int N;
vi adjList[mxN], res;
int in[mxN];

void ae(int x, int y) { adjList[x].pb(y), in[y] ++; }

bool sort(int _N) {
	N = _N; queue<int> todo;
	for (int i = 1; i <= N + 1; i++)
		if (!in[i]) todo.push(i);
	while (sz(todo)) {
		int x = todo.front(); todo.pop(); res.pb(x);
		trav(i,adj[x]) if (!(--in[i])) todo.push(i);
	}
	return sz(res) == N;
}
