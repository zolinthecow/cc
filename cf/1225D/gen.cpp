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
	
	// int N = rand(1, 10), K = rand (1, 10);
	int N = 10000, K = 100;
	cout << N << ' ' << K << endl;

	for (int i = 0; i < N; i++) {
		// cout << rand(1, 100);
		cout << 1;
		if (i < N - 1) cout << ' ';
	}
	cout << endl;
}
