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
const ll MOD = 998244353;

const int mxN = 3e5 + 5;
const int mxBits = 30;

ll N;
int a[mxN];

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin); 
    //freopen((name+".out").c_str(), "w", stdout);
}

int main () {
    // setIO("1879D");	

    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];

    ll sum = 0;

    ll mult = 1;

    for (int i = 0; i < mxBits; i++) {
        ll numOdd = 0;
        ll numContributed = 0;

        bool isOdd = false;
        for (int j = 0; j < N; j++) {
            // if the i'th bit is 1
            if ((a[j] & 1 << i) > 0) {
                isOdd = !isOdd;
            }
            if (isOdd) {
                numOdd++;
                numContributed += j + 1;
            }
        }

        for (ll j = 0; j < N; j++) {
            sum = (sum + (mult % MOD) * (numContributed % MOD)) % MOD;

            // if the i'th bit is 1
            if ((a[j] & 1 << i) > 0) {
                numOdd = N - j - numOdd;
                numContributed = (N - j) * (N - j + 1) / 2 - numContributed;
            }
            numContributed -= numOdd;
        }

        mult *= 2;
    }

    cout << sum << '\n';
}
