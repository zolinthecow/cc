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

#define CHECK_BIT(var,pos) ((var) & ((ll)1<<(pos)))

const int INF = 1061109567;

const int mxN = 1e5 + 5;
const int mxBits = 60;

int N, Q;
int a[mxN];

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin); 
    //freopen((name+".out").c_str(), "w", stdout);
}

int main () {
    setIO("1903D1");

    set<int> naturalZero;

    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        naturalZero.insert(i);
    }

    ll bitFlipCost[mxBits][mxN] = { 0 };
    ll colCost[mxBits] = { 0 };
    int colZeros[mxBits] = { 0 };

    for (int i = mxBits - 1; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            if (!CHECK_BIT(a[j], i)) {
                bitFlipCost[i][j] = ((ll) 1 << i) - (a[j] & (((ll) 1 << i) - 1));
                colCost[i] += bitFlipCost[i][j];
                colZeros[i]++;
            }
        }
    }

    while (Q--) {
        ll k; 
        cin >> k;

        ll sum = 0;

        // memset(clearedBits, 0, sizeof(clearedBits));
        set<int> clearedBits;

        for (ll i = mxBits - 1; i >= 0; i--) {
            ll totalCost = 0;
            vi bitsToClear;
            // for (int j = 0; j < N; j++) {
            //     if (totalCost > k) break;

            //     // cout << a[j] << "at " << i << ": " << CHECK_BIT(a[j], i) << '\n';
            //     if (clearedBits.find(j) == clearedBits.end() && !CHECK_BIT(a[j], i)) {
            //         totalCost += ((ll) 1 << i) - (a[j] & (((ll) 1 << i) - 1));
            //         bitsToClear.pb(j);
            //     }
            // }
            totalCost += ((ll) 1 << i) * clearedBits.size();

            if (colCost[i] <= k) {
                totalCost += colCost[i];
            }
            for (auto it : bits[i]) {
                totalCost += ((ll) 1 << i) - (it & (((ll) 1 << i) - 1));
                bitsToClear.pb(it);
            }

            cout << i << ": " << totalCost << ' ' << k << '\n';
            if (k >= totalCost) {
                // cout << i << ": ";
                sum += ((ll) 1 << i);
                // cout << sum << '\n'; 
                k -= totalCost;
                for (auto it : bitsToClear) {
                    clearedBits.insert(it);
                    naturalZero.erase(it);
                }
            }
        }

        cout << sum << '\n';
    }
}
