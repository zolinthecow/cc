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

const int mxX = 1e6 + 5;
int max_prime[mxX];

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin); 
    //freopen((name+".out").c_str(), "w", stdout);
}

int main () {
//    setIO("1713");

    for (int i = 2; i < mxX; i++) {
        if (max_prime[i] == 0) {
            for (int j = i; j < mxX; j += i) max_prime[j] = i;
        }
    }

    int N;
    cin >> N;

    while (N--) {
        int x;
        cin >> x;

        int ans = 1;
        while (x != 1) {
            int cnt = 0, prime = max_prime[x];
            while (x % prime == 0) {
                x /= prime;
                cnt++;
            }
            ans *= cnt + 1;
        }
        cout << ans << '\n';
    }
}
