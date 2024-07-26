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

const ll mxN = 5e5 + 5;
const ll mxQ = 5e5 + 5;

ll N, Q;
ll A[mxN];

ll pref[mxN];

int main () {
    setIO("ys_static_range_sum");	
    cin >> N >> Q;
    for (ll i = 1; i <= N; i++) {
	cin >> A[i];
	pref[i] = A[i] + pref[i - 1];
    } 

    while (Q--) {
	ll l, r;
	cin >> l >> r;
	
	cout << pref[r] - pref[l] << '\n';
    }
}
