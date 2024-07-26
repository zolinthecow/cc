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
    //freopen((name+".out").c_str(), "w", stdout);
}

int main () {
    setIO("d");	
    int N, M;
    cin >> N >> M;
    vector<vi> grid;
    while (N--) {
	vi r;
	for (int i = 0; i < M; i++) {
	    int n; cin >> n;
	    r.pb(n);
	}
	grid.pb(r);
    }

    int fixedOneR = -1, fixedOneC = -1;
    for (int i = 0; i < (int) grid.size(); i++) {
	for (int j = 0; j < (int) grid.size(); j++) {
	    if (grid[i][j] == 1 && fixedOneR == -1) {
		fixedOneR = i, fixedOneC = j;
		break;
	    }
	}
    }


}
