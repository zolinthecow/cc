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

int rand(int a, int b) {
	return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
	srand(atoi(argv[1]));
	
	cout << 1 << endl;
	int n = rand(1, 1000);
	cout << n << endl;
	for (int i = 0; i < n; i++) {
		int k = rand(1, 500);
		cout << k << " ";
		for (int j = 0; j < k; j++) {
			cout << rand(1, 10000);
			if (j != k - 1) cout << " ";
		}
		cout << endl;
	}
}
