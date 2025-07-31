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

const int mxN = 2e5 + 5;

int T;
int N;
int A[mxN], B[mxN];

int main () {
    // setIO("2117E");	
    cin >> T;

    while (T--) {
	// [even,odd]
	unordered_set<int> seenA[2];
	unordered_set<int> seenB[2];
	cin >> N;
	for (int i = 0; i < N; i++) {
	    cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
	    cin >> B[i];
	}

	int prevA = -1, prevB = -1;
	int ans = -1;
	for (int i = N - 1; i >= 0; i--) {
	    // if a_i and b_i are equal then ur done
	    if (A[i] == B[i]) {
		ans = i;
		break;
	    }

	    // if youve seen this number in your row at pos +1, +3, +5, etc then ur done
	    // this corresponds to same row, other parity
	    int otherParity = !(i % 2 == 0);
	    if (
		seenA[otherParity].find(A[i]) != seenA[otherParity].end() ||
		A[i] == prevA ||
		seenB[otherParity].find(B[i]) != seenB[otherParity].end() ||
		B[i] == prevB	
	    ) {
		ans = i;
		break;
	    }

	    // or if youve seen this number in the other row at pos +2, +4, +6 etc then ur done
	    // this corresponds to other row, same parity
	    int sameParity = !!(i % 2 == 0);
	    if (seenA[sameParity].find(B[i]) != seenA[sameParity].end() || seenB[sameParity].find(A[i]) != seenB[sameParity].end()) {
		ans = i;
		break;
	    }

	    // or if youve seen this number in the other row at pos +3, +5, +7, etc then ur done
	    // because you can delete a single column and it turns into the above case
	    // this corresponds to other row, other parity and NOT +1
	    if (seenA[otherParity].find(B[i]) != seenA[otherParity].end() || seenB[otherParity].find(A[i]) != seenB[otherParity].end()) {
		ans = i;
		break;
	    }

	    // or if youve seen this number in the same row at pos +2, +4, etc then ur done
	    // because you can delete a single column and turn it into the very first case
	    // this corresponds to same row, same parity
	    if (seenA[sameParity].find(A[i]) != seenA[sameParity].end() || seenB[sameParity].find(B[i]) != seenB[sameParity].end()) {
		ans = i;
		break;
	    }

	    if (prevA != -1) {
		seenA[otherParity].insert(prevA);
		seenB[otherParity].insert(prevB);
	    }
	    prevA = A[i];
	    prevB = B[i];
	}

	ans++;

	cout << ans << endl;
    }
}
