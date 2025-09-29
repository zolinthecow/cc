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
const ll INF_LL = 9223372036854775807;

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen((name+".in").c_str(), "r", stdin); 
    //freopen((name+".out").c_str(), "w", stdout);
}

const int mxN = 2e5 + 5;

vi K[mxN];

int main () {
    setIO("2148F");	
    int T;
    cin >> T;
    while (T--) {
	int n;
	cin >> n;

	int max_seq_len = -1;
	for (int i = 0; i < n; i++) {
	    K[i].clear();
	    
	    int k;
	    cin >> k;
	    max_seq_len = max(max_seq_len, k);
	    for (int j = 0; j < k; j++) {
		int ki;
		cin >> ki;
		K[i].pb(ki);
	    }
	}

	vi ans;
	unordered_set<int> avail;
	for (int i = 0; i < n; i++) avail.insert(i);

	while (ans.size() < max_seq_len) {
	    unordered_set<int> candidates = avail;
	    // cout << "NEW IT: " << ans.size() << endl;
	    // cout << "Candidates: ";
	    // for (auto it : candidates) cout << it << " ";
	    // cout << endl;

	    int to_use = -1;
	    int on = ans.size();
	    while (to_use == -1) {
		priority_queue<ii, vii, greater<ii>> comp;

		for (auto it : candidates) {
		    if (K[it].size() <= on) {
			avail.erase(avail.find(it));
			// cout << "Row " << it << " out, removing from avail" << endl;
		    } else {
			// cout << "To compare row " << it << " at pos " << on << ": " << K[it][on] << endl;
			comp.push(mp(K[it][on], it));
		    }
		}

		unordered_set<int> new_candidates;
		int cur_min = comp.top().first;
		// cout << "Lowest val: " << cur_min << endl;
		while (comp.size() && comp.top().first == cur_min) {
		    new_candidates.insert(comp.top().second);
		    comp.pop();
		}
		// cout << "New candidate set: ";
		// for (auto it : new_candidates) cout << it << " ";
		// cout << endl;

		if (new_candidates.size() == 1) {
		    to_use = *new_candidates.begin();
		    // cout << "Only one candidate, using row " << to_use << endl;
		} else {
		    for (auto it : new_candidates) {
			if (K[it].size() == (on + 1)) {
			    to_use = it;
			    // cout << " Row " << it << " ending, will use" << endl;
			    break;
			}
		    }
		}
		candidates = new_candidates;
		on++;
		if (on >= max_seq_len) {
		    to_use = *candidates.begin();
		    // cout << "Reached end, using row " << to_use << endl;
		}
	    }

	    // cout << "Starting at idx " << ans.size() << " going to " << K[to_use].size() << endl;
	    for (int i = ans.size(); i < K[to_use].size(); i++) {
		ans.pb(K[to_use][i]);
	    }
	    // cout << "New partial ans: ";
	    // for (auto it : ans) cout << it << " ";
	    // cout << endl;
	    avail.erase(avail.find(to_use));
	}

	for (int i = 0; i < ans.size(); i++) {
	    cout << ans[i];
	    if (i != ans.size() - 1) {
		cout << ' ' ;
	    }
	}
	cout << endl;
	// cout << "----------" << endl;
    }
}
