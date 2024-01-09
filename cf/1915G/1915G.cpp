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
const ll INF_LL = 9223372036854775807;

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
    // setIO("1915G");	
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < mxN; i++) adjList[i] = vii();
        memset(memo, 0xF, sizeof(memo));

        cin >> N >> M;

        for (int i = 0; i < M; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--; v--;
            adjList[u].pb(ii(v, w));
            adjList[v].pb(ii(u, w));
        }
        
        for (int i = 0; i < N; i++) {
            cin >> bikes[i];
        }

        // ii<cur node, fastest bike>
        queue<ii> q;
        q.push(ii(0, bikes[0]));
        memo[0][bikes[0]] = 0;

        while (q.size()) {
            int u = q.front().first, s = q.front().second;
            // cout << "VISIT " << u + 1 << " WITH SPEED " << s << " AND TIME " << memo[u][s] << '\n';
            q.pop();

            for (auto it : adjList[u]) {
                ll fastestSpeed = min(s, bikes[it.first]);
                ll nxt = memo[u][s] + (ll) it.second * (ll) s;

                if (memo[it.first][fastestSpeed] <= nxt) continue;

                memo[it.first][fastestSpeed] = nxt;
                q.push(ii(it.first, fastestSpeed));
            } 
        }

        ll ans = INF_LL;
        for (auto it : memo[N - 1]) ans = min(ans, it);

        cout << ans << '\n';
    }
}
