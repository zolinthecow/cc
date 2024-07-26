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
    setIO("c");	

    int N;
    cin >> N;
    vi nums;
    while (N--) {
	int n; cin >> n;
	nums.pb(n);
    }

    int dp[10005][2];
    dp[0][0] = 0; dp[0][1] = -100000;
    for (int i = 1; i <= (int) nums.size(); i++) {
	dp[i][0] = max(dp[i - 1][0] + nums[i], dp[i - 1][1] + nums[i]);
	
    }
}
