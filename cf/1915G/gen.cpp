#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using ii = pair<ll, ll>;
using vii = vector<ii>;

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

#define mp make_pair

#define LSOne(S) (S & (-S))

const int INF = 1061109567;

const int mxN = 1e3 + 5;

int N, M;

vii adjList[mxN];
int bikes[mxN];

ll memo[mxN][mxN];

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin); 
    //freopen((name+".out").c_str(), "w", stdout);
}

int main () {
    int N = 1000, M = 999;
    cout << 1 << endl << N << ' ' << M << endl;

    for (int i = 1; i <= M; i++) {
        cout << i << ' ' << i + 1 << ' ' << 10000 << endl;
    }
    for (int i = 0; i < N; i++) {
        cout << 1000;
        if (i != N - 1) cout << ' ';
    }
    cout << endl;
}