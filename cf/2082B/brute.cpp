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
    freopen((name+".in").c_str(), "r", stdin); 
    //freopen((name+".out").c_str(), "w", stdout);
}

int T, X, N, M;

void generateBitstrings(int zeros, int ones, std::string current, std::vector<std::string> &results) {
    if (zeros == 0 && ones == 0) {
        results.push_back(current);
        return;
    }

    if (zeros > 0)
        generateBitstrings(zeros - 1, ones, current + "0", results);
    
    if (ones > 0)
        generateBitstrings(zeros, ones - 1, current + "1", results);
}

std::vector<std::string> getAllBitstrings(int n, int m) {
    std::vector<std::string> results;
    generateBitstrings(n, m, "", results);
    return results;
}

int main () {
    // setIO("2082B");	
    cin >> T;
    while (T--) {
	cin >> X >> N >> M;
	int ans_min = (int)(1e9+5), ans_max = -1;

	vector<string> combs = getAllBitstrings(N, M);

	for (auto it : combs) {
	    int cur = X;
	    for (auto itr : it) {
		if (itr == '0') {
		    cur /= 2;
		} else {
		    cur = (cur + 1) / 2;
		}
	    }
	    ans_min = min(ans_min, cur);
	    ans_max = max(ans_max, cur);
	}

	cout << ans_min << " " << ans_max << endl;
    }
}
