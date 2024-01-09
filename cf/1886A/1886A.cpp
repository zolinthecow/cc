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

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin); 
    //freopen((name+".out").c_str(), "w", stdout);
}

// 1 2 x => subtract 3
// 1 4 x => subtract 5
// 1 5 x or 2 4 x => subtract 6
// 2 5 x => subtract 7
// 1 7 x => subtract 8
// 1 8 x or 2 7 x or 4 5 x => subtract 9
// 2 8 x => subtract 10
// 1 10 x or 4 7 x => subtract 11 (like subtracting 1)
// 2 10 x or 4 8 x or 5 7 x => subtract 12 (like subtracting 2)
// 1 13 x or 4 10 x => subtract 14 (like subtracting 4)
map<int, vector<vi>> lookup {
    { 3, {{ 1, 2 }} },
    { 5, {{ 1, 4 }} },
    { 6, {{ 1, 5 }, { 2, 4 }} },
    { 7, {{ 2, 5 }} },
    { 8, {{ 1, 7 }} },
    { 9, {{ 1, 8 }, { 2, 7 }, { 4, 5 }} },
    { 10, {{ 2, 8}} },
    { 11, {{ 1, 10 }, { 4, 7 } } },
    { 12, {{ 2, 10 }, { 4, 8 }, { 5, 7 }} },
    { 14, {{ 1, 13 }, { 4, 10 }}},
};

int T;

int main () {
    // setIO("1886A");	

    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        bool solved = false;

        for (auto it : lookup) {
            int sub = N - it.first;
            if (sub <= 0 || sub % 3 == 0) continue;
            for (auto jt : it.second) {
                if (find(jt.begin(), jt.end(), sub) != jt.end()) continue;
                solved = true;
                cout << "YES\n" << sub << " " << jt[0] << " " << jt[1] << '\n';
                break;
            }
            if (solved) break;
        }

        if (!solved) cout << "NO\n";
    }
}
