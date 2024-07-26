#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <string>
#include <unordered_map>
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
const ll INF_LL = 9223372036854775807;

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin); 
    //freopen((name+".out").c_str(), "w", stdout);
}

const ll mxN = 1e5 + 5, mxK = 1e2 + 5;

ll N, K;

/*
 * For each num, prime factorize it and store it in a hashmap with key [power % K][factor]. All numbers that can be
 * represented as x^k will be the set of numbers whos factors either all are ^K themselves or ^(K - cur_power).
 * Basically for each number I can start off saying all prev numbers work, then for each prime factor, take out the numbers
 * that dont have the a factor factor^(K - cur_power). For somethign thats ^ 0 (is a factor of K or is 1) you want to take out
 * all the numbers that are not a factor of K or 1
 */

// [prime factorization string minus powers of K]
unordered_map<string, ll> pfs;

map<ll, ll> factor (ll n) {
    map<ll, ll> ret;
    
    for (ll i = 2; i * i <= n; i++) {
	while (n % i == 0) {
	    if (ret.find(i) == ret.end()) ret.insert(mp(i, 0));
	    ret[i]++;
	    n /= i;
	}
    }
    if (n > 1) ret.insert(mp(n, 1));
    return ret;
}

bool isPowerOfK(ll toTest) {
    double res = pow((double) toTest, 1.0 / (double) K);
    if (fabs(res - round(res)) < 1e-10) return true;
    else return false;
}

int main () {
    // setIO("1225D");	

    cin >> N >> K;

    ll ans = 0;

    ll numPowersOfKOrOnes = 0;

    for (ll i = 0; i < N; i++) {
	ll a;
	cin >> a;

	// cout << "PROCESSING " << a << endl;

	if (a == 1 || isPowerOfK(a)) {
	    // cout << "IS 1 OR POWER OF K, ADDING " << numPowersOfKOrOnes << endl;
	    ans += numPowersOfKOrOnes;
	    numPowersOfKOrOnes++;
	    continue;
	}

	map<ll, ll> factors = factor(a);
	string factorString = "";
	string correspondingFactorString = "";

	for (auto kv : factors) {
	    ll power = kv.second % K;
	    if (power == 0) continue;
	    factorString += to_string(kv.first) + "^" + to_string(power) + ",";
	    correspondingFactorString += to_string(kv.first) + "^" + to_string(K - power) + ",";
	}
	/* cout << "FACTOR STRING: " << factorString << endl;
	cout << "NEEDS: " << correspondingFactorString << endl << endl;
	
	cout << "CURRENT FACTOR STRINGS:" << endl;
	for (auto kv : pfs) {
	    cout << kv.first << ", " << kv.second << endl;
	}
	cout << endl; */
	
	if (pfs.find(correspondingFactorString) != pfs.end()) {
	    // cout << "ADDING " << pfs[correspondingFactorString] << endl << endl << endl;
	    ans += pfs[correspondingFactorString];
	}
	if (pfs.find(factorString) == pfs.end()) {
	    pfs[factorString] = 0;
	}
	pfs[factorString]++;
    }

    cout << ans << '\n';
}
