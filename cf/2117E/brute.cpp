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
        vector<int> a(n), b(n);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;
        int best = 0;

        for (int rem = -1; rem < n; ++rem) {            // -1 means no removal
            vector<int> A, B;
            for (int i = 0; i < n; ++i)
                if (i != rem) {
                    A.push_back(a[i]);
                    B.push_back(b[i]);
                }
            int m = A.size();

            auto encode = [](const vector<int> &x, const vector<int> &y) {
                string s;
                for (int v : x) { s += to_string(v); s.push_back(','); }
                s.push_back('|');
                for (int v : y) { s += to_string(v); s.push_back(','); }
                return s;
            };

            queue<pair<vector<int>, vector<int>>> q;
            unordered_set<string> seen;
            q.push({A, B});
            seen.insert(encode(A, B));

            while (!q.empty()) {
                auto cur = q.front();
                q.pop();
                const vector<int> &ca = cur.first;
                const vector<int> &cb = cur.second;

                int matches = 0;
                for (int i = 0; i < m; ++i)
                    if (ca[i] == cb[i]) ++matches;
                best = max(best, matches);

                for (int i = 0; i < m - 1; ++i) {
                    // ai := b_{i+1}
                    {
                        auto na = ca;
                        auto nb = cb;
                        na[i] = nb[i + 1];
                        string key = encode(na, nb);
                        if (seen.insert(key).second) q.push({move(na), move(nb)});
                    }
                    // bi := a_{i+1}
                    {
                        auto na = ca;
                        auto nb = cb;
                        nb[i] = na[i + 1];
                        string key = encode(na, nb);
                        if (seen.insert(key).second) q.push({move(na), move(nb)});
                    }
                }
            }
        }

        cout << best << '\n';
    }
    return 0;
}
