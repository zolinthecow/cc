#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<ii>
#define pb push_back
#define INF 2000000000
#define LSOne(S) (S & (-S))
#define MOD 1000000007

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen((s + ".in").c_str(), "r", stdin);
	//freopen((s + ".out").c_str(), "w", stdout);
}

int rand(int a, int b) {
	return a + rand() % (b - a + 1);
}

vii edges;
int colors[11];

bool works(int v, int c) {
	for (auto edge : edges) {
		if (edge.first == v) {
			if (colors[edge.second] == c) return false;
		} else if (edge.second == v) {
			if (colors[edge.first] == c) return false;
		}
	}
	return true;
}

int main(int argc, char* argv[]) {
	setIO("barnpainting");
	srand(atoi(argv[1]));
	int n = rand(1, 10);
	int k = rand(0, n);
	cout << n << " " << k << endl;
	if (n == 1) {
		edges.emplace_back(1, 1);
	} else {
		for (int i = 2; i <= n; i++) {
			edges.emplace_back(rand(1, i - 1), i);
		}
	}
	vi perm(n + 1);
	for (int i = 1; i <= n; i++) {
		perm[i] = i;
	}
	random_shuffle(perm.begin() + 1, perm.end());
	
	random_shuffle(edges.begin(), edges.end());
	for (auto edge : edges) {
		int a = edge.first, b = edge.second;
		if (rand() % 2) {
			swap(a, b);
		}
		cout << a << " " << b << endl;
	}
	set<int> used;
	for (int i = 0; i < k; i++) {
		int v = rand(1, n);
		while (used.find(v) != used.end()) {
			v = rand(1, n);
		}
		int c = rand(1, 3);
		while (!works(v, c)) {
			c = rand(1, 3);
		}
		colors[v] = c;
		cout << v << " " << c << endl;
		used.insert(v);
	}
}
