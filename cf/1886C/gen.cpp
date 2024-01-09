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
	
	cout << 10 << '\n';
	for (int i = 0; i < 10; i++) {
		int len = rand(1, 10);
		for (int j = 0; j < len; j++) {
			cout << char(rand(97, 122));
		}
		cout << '\n' << rand(1, len * (len + 1) / 2) << '\n';
	}
}
