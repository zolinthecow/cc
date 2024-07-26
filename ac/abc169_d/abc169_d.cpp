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
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((name + ".in").c_str(), "r", stdin);
  // freopen((name+".out").c_str(), "w", stdout);
}

int main() {
  // setIO("abc169_d");

  ll N, N2;
  cin >> N;
  N2 = N;

  set<ll> factors;
  for (ll i = 2; i * i <= N; i++) {
    while (N % i == 0) {
      factors.insert(i);
      N /= i;
    }
  }
  if (N > 1)
    factors.insert(N);

  ll ans = 0;

  for (auto it : factors) {
    ll divisor = it;
    while (N2 >= divisor && N2 % divisor == 0) {
      ans++;
      // cout << N2 << " / " << divisor << endl;
      N2 /= divisor;
      divisor *= it;
    }
  }
  cout << ans << '\n';
}
