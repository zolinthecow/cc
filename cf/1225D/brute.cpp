#include <bits/stdc++.h>
#include <unordered_map>
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

const int mxN = 1e5 + 5, mxK = 1e2 + 5;

int N, K;
int a[mxN];

unordered_map<int, int> pfs[mxN];

unordered_map<int, int> factor (int n) {
    unordered_map<int, int> ret;
    for (int i = 2; i * i <= n; i++) {
	while (n % i == 0) {
	    if (ret.find(i) == ret.end()) ret.insert(mp(i, 0));
	    ret[i]++;
	    n /= i;
	}
    }
    if (n > 1) ret.insert(mp(n, 1));
    return ret;
}

int main () {
    setIO("1225D");	

    cin >> N >> K;

    int ans = 0;

    for (int i = 0; i < N; i++) {
	cin >> a[i];

	unordered_map<int, int> factors = factor(a[i]);
	pfs[i] = factors;
	cout << "Factors of " << a[i] << '\n';
	 for (auto kv : factors) {
	     cout << kv.first << '^' << kv.second << ' ';
	 }
	cout << '\n';
	
	for (int j = 0; j < i; j++) {
	    bool works = true;
	    for (auto kv : factors) {
		if ((pfs[j][kv.first] + kv.second) % K != 0) {
		    works = false;
		    break;
		}
	    }
	    if (works) {
		for (auto kv : pfs[j]) {
		    if ((kv.second + factors[kv.first]) % K != 0) {
			works = false;
			break;
		    }
		}
	    }
	    if (works) {
		cout << a[j] << ' ' << a[i] << "\n\n";
		ans++;
	    }
	}
    }

    cout << ans << '\n';
}
