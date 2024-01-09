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

const int MX = 3 * 10e5 + 4;
const int MOD = 998244353;

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin); 
    //freopen((name+".out").c_str(), "w", stdout);
}

int seg[4 * MX];

int N, M;
string S;

int s_vals[MX];

void build(int pos, int L, int R) {
    if (L == R) {
        seg[pos] = s_vals[L];
    } else {
        build(left(pos)  , L,               (L + R) / 2);
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

int main () {
    // setIO("1886D");	
    cin >> N >> M >> S;

    for (int i = 0; i < (int) S.length(); i++) {
        if (S[i] == '>' || S[i] == '<') s_vals[i] = 1;
        else s_vals[i] = i;
    }

    build(1, 0, N - 2);

    cout << seg[1] << '\n';

    while (M--) {
        int I; string C;
        cin >> I >> C;
        I--;

        int new_val;
        if (C == ">" || C == "<") new_val = 1;
        else new_val = I;

        update(1, I, new_val, 0, N - 2);

        cout << seg[1] << '\n';
    }
}
