#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n);
        size_t m = 0;
        for (int i = 0; i < n; ++i) {
            int k; cin >> k;
            a[i].resize(k);
            for (int j = 0; j < k; ++j) cin >> a[i][j];
            m = max(m, a[i].size());
        }

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        vector<int> best;
        bool hasBest = false;

        sort(idx.begin(), idx.end());
        do {
            vector<int> res(m, 0);
            for (size_t c = 0; c < m; ++c) {
                for (int rpos = n - 1; rpos >= 0; --rpos) {
                    int r = idx[rpos];
                    if (a[r].size() > c) {
                        res[c] = a[r][c];
                        break;
                    }
                }
            }
            if (!hasBest || res < best) {
                best = res;
                hasBest = true;
            }
        } while (next_permutation(idx.begin(), idx.end()));

        for (size_t i = 0; i < best.size(); ++i) {
            cout << best[i] << (i + 1 == best.size() ? '\n' : ' ');
        }
    }
    return 0;
}
