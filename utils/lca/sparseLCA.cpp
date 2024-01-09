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
const int logN = 14;

int L[2*mxN], E[2*mxN], H[mxN], idx;

class RMQ {                                          // Range Minimum Query
private:
  int _A[mxN], SpT[mxN][logN];
public:
  RMQ(int n, int A[]) {    // constructor as well as pre-processing routine
    for (int i = 0; i < n; i++) {
      _A[i] = A[i];
      SpT[i][0] = i; // RMQ of sub array starting at index i + length 2^0=1
    }
    // the two nested loops below have overall time complexity = O(n log n)
    for (int j = 1; (1<<j) <= n; j++) // for each j s.t. 2^j <= n, O(log n)
      for (int i = 0; i + (1<<j) - 1 < n; i++)    // for each valid i, O(n)
        if (_A[SpT[i][j-1]] < _A[SpT[i+(1<<(j-1))][j-1]])            // RMQ
          SpT[i][j] = SpT[i][j-1];    // start at index i of length 2^(j-1)
        else                  // start at index i+2^(j-1) of length 2^(j-1)
          SpT[i][j] = SpT[i+(1<<(j-1))][j-1];
  }

  int query(int i, int j) {
    int k = (int)floor(log((double)j-i+1) / log(2.0));    // 2^k <= (j-i+1)
    if (_A[SpT[i][k]] <= _A[SpT[j-(1<<k)+1][k]]) return SpT[i][k];
    else                                         return SpT[j-(1<<k)+1][k];
} 
  int lca(int a, int b) {
	return E[query(min(H[a], H[b]), max(H[a], H[b]))];
  }
};

int N;
vector<int> adjList[mxN]; //children

//void dfs1() {
    //stack<ii> st; st.push(ii(1, 1));
    //visited[1] = true;
    //int cont = false;
    //while (!st.empty()) {
		//ii top = st.top();
		//int u = top.first, p = top.second;
		//visited[u] = true;
		//cont = false;
		//if (!tin[u]) {
			//tin[u] = ++timer;
			//anc[u][0] = p;
			//for (int i = 1; i < 18; i++)
				//anc[u][i] = anc[anc[u][i - 1]][i - 1];
		//}
		//for (auto v : adjList[u]) {
			//if (!visited[v]) {
				//st.push(ii(v, u));
				//cont = true;
				//break;
			//}
		//}
		//if (!cont) {
			//tout[u] = ++timer;
			//st.pop();
		//}
	//}
//}

void dfs(int cur, int depth, int p = -1) {
  H[cur] = idx;
  E[idx] = cur;
  L[idx++] = depth;
  for (int i = 0; i < (int) adjList[cur].size(); i++) {
	  if (adjList[cur][i] == p) continue;
    dfs(adjList[cur][i], depth+1, cur);
    E[idx] = cur;                              // backtrack to current node
    L[idx++] = depth;
  }
}

void dfs2() {
	stack<ii> st; st.push(ii(0, 0));
	
}

void buildRMQ() {
  idx = 0;
  memset(H, -1, sizeof H);
  dfs(0, 0);                       // we assume that the root is at index 0
}

int main() {
	setIO("test.in")
	cin >> N;
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		a--, b--;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}
	buildRMQ();
	RMQ rmq(20, L);
	cout << rmq.lca(2, 3) << endl;
	return 0;
}
