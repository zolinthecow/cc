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
    setIO("b");	

    int N, M;
    cin >> N >> M;
    vector<vi> grid;
    while (N--) {
	vi r;
	for (int i = 0; i < M; i++) {
	    int v;
	    cin >> v;
	    r.pb(v);
	}
	grid.pb(r);
    }

    int l = 1001, r = -1, t = -1, b = -1;
    for (int i = 0; i < (int) grid.size(); i++) {
	int leftmost = -1, rightmost = -1;
	for (int j = 0; j < (int) grid[i].size(); j++) {
	    if (grid[i][j] == 1) {
		if (leftmost == -1) leftmost = j;
		rightmost = j;
	    }
	}
	if (rightmost != -1) {
	    if (t == -1) {
		t = i;
	    }
	    b = i;
	    l = min(l, leftmost);
	    r = max(r, rightmost);
	}
    }

    int ans = (r - l + 1) * (b - t + 1);
    cout << ans << endl;
}
