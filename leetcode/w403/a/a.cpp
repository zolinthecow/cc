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
    setIO("a");	

    int N;
    vi nums;
    cin >> N;
    while (N--) {
	int num;
	cin >> num;
	nums.push_back(num);
    }
    sort(nums.begin(), nums.end());

    double ans = 1061109567;
    for (int i = 0; i < ((int) nums.size()) / 2; i++) {
	double a = nums[i], b = nums[(int) nums.size() - 1 - i];
	double avg = (a + b) / 2;
	ans = min(ans, avg);	
    }
    
    cout << ans << endl;
}
