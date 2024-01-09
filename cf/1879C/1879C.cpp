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

const int mxN = 4e5 + 5;

const ll MOD = 998244353;

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin); 
    //freopen((name+".out").c_str(), "w", stdout);
}

ll fact[mxN];

int T;

ll nChoosek(ll n, ll k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    ll result = n;
    for( ll i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

int main () {
    // setIO("1879C");

    fact[0] = 1;
    for (ll i = 1; i < mxN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }


    cin >> T;
    while (T--) {
        vector<ll> seqLens;

        string s;
        cin >> s;

        s += '-';

        int minOps = 0;

        ll curSeqLen = 1;
        for (int i = 1; i < (int) s.length(); i++) {
            if (s[i - 1] == s[i]) curSeqLen++;
            else {
                minOps += curSeqLen - 1;
                seqLens.pb(curSeqLen);
                curSeqLen = 1;
            }
        }

        // for (auto it : seqLens) cout << it << ' ';
        // cout << '\n';

        ll numSeqs = 1;

        for (int i = 0; i < (int) seqLens.size(); i++) {
            numSeqs = numSeqs * nChoosek(seqLens[i], seqLens[i] - 1) % MOD;
        }

        // cout << numSeqs << '\n';
        // cout << s << ' ' << s.length() - 1 << ' ' << seqLens.size() << ' ' << fact[s.length() - 1 - seqLens.size()] << '\n';

        numSeqs = numSeqs * fact[s.length() - 1 - seqLens.size()] % MOD;
        
        cout << minOps << ' ' << numSeqs << '\n';
    }
}
