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

const int mxN = 3e5 + 5;
const int mxK = 3e5 + 5;
const int mxA = 1e9 + 5;

int T, N, K;
string goal;
int penalities[mxN];

bool check(int max_pen) {
    int num_strips = 0;
    bool is_blue_strip = false;
    for (int i = 0; i < N; i++) {
	if (penalities[i] > max_pen) {
	    if (!is_blue_strip && goal[i] == 'B') {
		is_blue_strip = true;
		num_strips++;
	    } else if (is_blue_strip && goal[i] == 'R') {
		is_blue_strip = false;
	    }
	}	
    }
    return num_strips <= K;
}

int main () {
    // setIO("2070C");	
    cin >> T;
    while(T--) {
	cin >> N >> K >> goal;
	for (int i = 0; i < N; i++) {
	    cin >> penalities[i];
	}

	int lo = 0;
	int hi = mxA;
	while (lo < hi) {
	    int mid = lo + (hi - lo) / 2;
	    if (check(mid)) {
		hi = mid;
	    } else {
		lo = mid + 1;
	    }
	}
	
	cout << lo << endl;
    }
}
