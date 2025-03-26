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

const int mxN = 32;

int T, N;
ii gates[mxN][2];

int main () {
    // setIO("2078D");	
    cin >> T;
    while (T--) {
	cin >> N;
	for (int i = 0; i < N; i++) {
	    string a, b, c, d;
	    cin >> a >> b >> c >> d;
	    if (a == "+") gates[i][0].first = 0;
	    else gates[i][0].first = 1;
	    gates[i][0].second = stoi(b);
	    if (c == "+") gates[i][1].first = 0;
	    else gates[i][1].first = 1;
	    gates[i][1].second = stoi(d);
	}

	ll l = 1, r = 1;
	for (int i = 0; i < N; i++) {
	    ll amt_gained = 0;
	    if (!gates[i][0].first) {
		amt_gained += gates[i][0].second;
	    } else {
		amt_gained += (gates[i][0].second - 1) * l;
	    }
	    if (!gates[i][1].first) {
		amt_gained += gates[i][1].second;
	    } else {
		amt_gained += (gates[i][1].second - 1) * r;
	    }

	    bool go_left = false;
	    for (int j = i + 1; j < N; j++) {
		if (!gates[j][0].first && gates[j][1].first) {
		    break;
		} else if (gates[j][0].first && !gates[j][1].first) {
		    go_left = true;
		    break;
		} else if (gates[j][0].first && gates[j][1].first) {
		    if (gates[j][0].second == gates[j][1].second) continue;
		    else {
			go_left = gates[j][0].second > gates[j][1].second;
			break;
		    }
		}
	    }

	    if (go_left) {
		l += amt_gained;
	    } else {
		r += amt_gained;
	    }
	}

	cout << l + r << endl;
    }
}
