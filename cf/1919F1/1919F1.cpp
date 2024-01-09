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

#define left(S) (S << 1)
#define right(S) ((S << 1) + 1)

const int INF = 1061109567;
const ll INF_LL = 9223372036854775807;

const int mxN = 5e5 + 5;

int seg[mxN * 4];

int N, Q;
int a[mxN], b[mxN], c[mxN];

int build(int pos, int L, int R, int overflowAmt) {
    if (L == R) {
        seg[pos] = min(a[L], b[L]);
        return max(0, a[L] - b[L]);
    } else {
        int leftOverflowAmt = build(left(pos)  , L,               (L + R) / 2, 0);
        build (right(pos), (L + R) / 2 + 1, R          );

        int valLeft = seg[left(pos)];
        int valRight = seg[right(pos)];

        seg[pos] = valLeft * 1LL * valRight % MOD;
    }
}

void update (int pos, int update_idx, int val, int L, int R) {
    if (L == R) {
        seg[pos] = val;
    } else {
        int L1 = L;
        int L2 = (L + R) / 2;
        int R1 = (L + R) / 2 + 1;
        int R2 = R;

        if (L1 <= update_idx && update_idx <= L2) {
            update(left(pos), update_idx, val, L1, L2);
        } else {
            update(right(pos), update_idx, val, R1, R2);
        }

        int valLeft = seg[left(pos)];
        int valRight = seg[right(pos)];

        seg[pos] = valLeft * 1LL * valRight % MOD;
    }
}

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin); 
    //freopen((name+".out").c_str(), "w", stdout);
}

int main () {
    setIO("1919F1");	

}
