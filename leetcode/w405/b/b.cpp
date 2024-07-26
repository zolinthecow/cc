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

int main () {
    setIO("b");	

    int n;
    cin >> n;

    set<string> ans = { "0", "1" };

    for (int i = 1; i < n; i++) {
	set<string> newAns;
	for (auto str : ans) {
	    if (str[i - 1] == '1') {
		newAns.insert(str + "0");
		newAns.insert(str + "1");
	    } else {
		newAns.insert(str + "1");
	    }
	}
	ans = newAns;
    }

    vector<string> ret;
    for (auto str : ans) {
	ret.push_back(str);
    }
}
