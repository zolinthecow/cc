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

const int mxN = 5e5 + 5;

int N;
int mods[8];

int main () {
    // setIO("2");	
    setIO("div7");	
    cin >> N;
    int sum = 0;
    int ans = 0;
    for (int i = 1; i < 7; i++) mods[i] = INF;
    for (int i = 0; i < N; i++) {
	int cur;
	cin >> cur;
	sum += cur;
	sum %= 7;
	if (mods[sum] == INF) mods[sum] = i;
	if (sum == 0) mods[sum] = 0;
	ans = max(ans, i - mods[sum]);
    }
    cout << ans << endl;
}
