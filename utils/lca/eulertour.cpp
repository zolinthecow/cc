#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi; 
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define f first
#define s second
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

template<class T> void remDup(vector<T>& v) { 
	sort(all(v)); v.erase(unique(all(v)),end(v)); }
	
template<class T> struct RMQ { // floor(log_2(x))
	int level(int x) { return 31-__builtin_clz(x); } 
	vector<T> v; vector<vi> jmp;
	int comb(int a, int b) { // index of min
		return v[a]==v[b]?min(a,b):(v[a]<v[b]?a:b); } 
	void init(const vector<T>& _v) {
		v = _v; jmp = {vi(sz(v))}; iota(all(jmp[0]),0);
		for (int j = 1; 1<<j <= sz(v); ++j) {
			jmp.pb(vi(sz(v)-(1<<j)+1));
			F0R(i,sz(jmp[j])) jmp[j][i] = comb(jmp[j-1][i],
									jmp[j-1][i+(1<<(j-1))]);
		}
	}
	int index(int l, int r) { // get index of min element
		int d = level(r-l+1);
		return comb(jmp[d][l],jmp[d][r-(1<<d)+1]); }
	T query(int l, int r) { return v[index(l,r)]; }
};

const int mxN = 1e5 + 5;

int N; 
vi adjList[mxN];
vi depth, pos;
vii tmp; RMQ<ii> r;

void init(int _N) { N = _N; depth = pos = vi(N); }

void ae(int x, int y) { adjList[x].pb(y), adjList[y].pb(x); }

void dfs(int x, int p) {
	pos[x] = sz(tmp); tmp.eb(depth[x],x); 
	trav(y,adjList[x]) if (y != p) {
		depth[y] = depth[x]+1;
		dfs(y,x), tmp.eb(depth[x],x);
	}
}

void gen(int R) { dfs(R,-1); r.init(tmp); }

int lca(int u, int v){
	u = pos[u], v = pos[v]; if (u > v) swap(u,v);
	return r.query(u,v).s; }
	
int dist(int u, int v) {
	return depth[u]+depth[v]-2*depth[lca(u,v)]; }
	
/*Compress takes a subset $S$ of nodes 
 	* and computes the minimal subtree that contains all the nodes 
	* pairwise LCA's and compressing edges. Returns a list of
	* \texttt{(par, orig\_index)} representing a tree rooted at 0. 
	* The root points to itself. Not sure how useful this will be */
	
vii compress(vi S) {
	static vi rev; rev.rsz(N);
	auto cmp = [&](int a, int b) { return pos[a] < pos[b]; };
	sort(all(S),cmp); R0F(i,sz(S)-1) S.pb(lca(S[i],S[i+1]));
	sort(all(S),cmp); remDup(S);
	vii ret{{0,S[0]}}; F0R(i,sz(S)) rev[S[i]] = i;
	F0R(i,sz(S)-1) ret.eb(rev[lca(S[i],S[i+1])],S[i+1]);
	return ret;
}


int main() {
	
}
