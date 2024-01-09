#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using ii = pair<ll, ll>;
using vii = vector<ii>;

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()

#define mp make_pair

#define LSOne(S) (S & (-S))

const ll INF = 1061109567;

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin); 
    //freopen((name+".out").c_str(), "w", stdout);
}

ll T;

// to find the order that it will descend, you need to find the first point where it goes
// backwards, then delete everything in order from back to front. then continue.
// examples:
// bcdabc -> bcabc -> babc -> abc -> ab -> a
// cab -> ab -> a
// abcd -> abc -> ab -> a

int main () {
    // setIO("1886C");	

    // Get rid of any descending characters from front to back then remove back to from

    cin >> T;
    while (T--) {
        string S_1;
        cin >> S_1;

        ll pos;
        cin >> pos;

        vector<pair<char, ii>> s;
        for (ll i = 0; i < (ll) S_1.length(); i++) {
            s.pb({S_1[i], {i, i - 1}});
        }

        vi order_to_delete;
        for (ll i = 1; i < (ll) s.size(); i++) {
            // while the previous linked list item is greater than the current item
            while (s[i].second.second >= 0 && s[s[i].second.second].first > s[i].first) {
                // remove the previous link's index
                order_to_delete.pb(s[s[i].second.second].second.first);
                // relink the current link's prev to the previous link's prev
                s[i].second.second = s[s[i].second.second].second.second;
            }
            // then if you're at the end take the remaining ones and push them into 
            // order_to_delete from back to front
            if (i == (ll) s.size() - 1) {
                ll j = i;
                while (s[j].second.second >= 0) {
                    order_to_delete.pb(s[j].second.first);
                    j = s[j].second.second;
                }
            }
        }
        // cout << '\n';
        // cout << "ORDER TO DELETE:\n";
        // for (auto it : order_to_delete) cout << it << ", ";
        // cout << '\n';

        vi s_segments = {0, (ll) S_1.length()};
        for (ll i = 1; i < (ll) S_1.length(); i++) {
            s_segments.pb(s_segments[i] + ((ll) S_1.length()) - i);
        }

        // cout << "SEGMENTS:\n";
        // for (auto it : s_segments) cout << it << ", ";
        // cout << '\n';

        ll segment_to_use = s_segments.size() - 1;
        for (ll i = 1; i < (ll) s_segments.size(); i++) {
            if (pos <= s_segments[i]) {
                segment_to_use = i;
                break;
            }
        }

        // cout << "SEGMENT TO USE: " << segment_to_use << '\n';

        set<ll> chars_to_erase;
        for (ll i = 0; i < segment_to_use - 1; i++) {
            chars_to_erase.insert(order_to_delete[i]);
        }

        // cout << "CHARS TO ERASE:\n";
        // for (auto it : chars_to_erase) cout << it << ", ";
        // cout << '\n';

        auto chars_to_erase_it = chars_to_erase.begin();
        vector<char> constructed_s_segment;
                
        for (ll i = 0; i < (ll) S_1.length(); i++) {
            if (chars_to_erase.size() > 0 && chars_to_erase_it != chars_to_erase.end() && i == *chars_to_erase_it) {
                chars_to_erase_it++;
            } else {
                constructed_s_segment.pb(S_1[i]);
            }
        }

        ll char_to_return_pos = pos - s_segments[segment_to_use - 1] - 1;
        cout << constructed_s_segment[char_to_return_pos];
    }
}
