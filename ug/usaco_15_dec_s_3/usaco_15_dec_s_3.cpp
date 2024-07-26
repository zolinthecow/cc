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

const int INF = 1061109567;
const ll INF_LL = 9223372036854775807;

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin); 
    freopen((name+".out").c_str(), "w", stdout);
}

const int mxN = 1e5+5;
const int mxQ = 1e5+5;

int N, Q;
int H[mxN], G[mxN], J[mxN];

int main () {
    setIO("bcount");	
    cin >> N >> Q;
    int c;
    for (int i = 1; i <= N; i++) {
	cin >> c;
	H[i] = H[i - 1];
	G[i] = G[i - 1];
	J[i] = J[i - 1];
	switch (c) {
	case 1:
	    H[i]++;
	    break;
	case 2:
	    G[i]++;
	    break;
	case 3:
	    J[i]++;
	    break;
	default:
	    cout << "THE IMPOSSIBLE HAPPENED\n";
	}
    }
    while (Q--) {
	int a, b;	
	cin >> a >> b;
	cout << H[b] - H[a - 1] << ' ' << G[b] - G[a - 1] << ' ' << J[b] - J[a - 1] << '\n';
    }
}
