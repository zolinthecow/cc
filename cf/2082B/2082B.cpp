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

int T, X, N, M;

int main () {
    // setIO("2082B");	
    cin >> T;
    while (T--) {
	cin >> X >> N >> M;
	int ans_min = X, ans_max = X;
	int floor_ops = 0, ciel_ops = 0;
	while (floor_ops + ciel_ops < N + M && ans_min > 0) {
	    if (ciel_ops < M) {
		if (ans_min == 1) {
		    ciel_ops = M;
		} else {
		    ans_min = (ans_min + 1) / 2;
		    ciel_ops++;
		}
	    } else {
		ans_min /= 2;
		floor_ops++;
	    }
	}
	floor_ops = 0, ciel_ops = 0;
	while (floor_ops + ciel_ops < N + M && ans_max > 0) {
	    if (floor_ops < N) {
		ans_max /= 2;
		floor_ops++;
	    } else {
		if (ans_max == 1) {
		    ciel_ops = M;
		} else {
		    ans_max = (ans_max + 1) / 2;
		    ciel_ops++;
		}
	    }
	}
	cout << ans_min << " " << ans_max << endl;
    }
}
