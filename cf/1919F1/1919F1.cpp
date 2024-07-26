#include <bits/stdc++.h>
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

#define left(S) (S << 1)
#define right(S) ((S << 1) + 1)

const int INF = 1061109567;
const ll INF_LL = 9223372036854775807;

const ll mxN = 5e5 + 5;

// Initially calculate the total overflow, and each segement of overflow. A segment of overflow
// is defined by either a subsequence with overflow 0, or a subsequence ending at N. The solution
// is the sum of A minus the sum of the last overflow segment (the overflow segment that ends at
// N). On update, update a segment tree holding the value of A with the value of A_x, and a segment
// tree holding the value of B with the value of B_y, and then recalculate the overflow segment sum
// containing the index updated (p). If overflow(seg begin, p) <= 0, split the segment. Otherwise,
// join the segment with its adjacent non-zero segments. 

class FenwickTree {
private: vi ft; // recall that vi is: typedef vector<ll> vi;
public: FenwickTree(ll n) { ft.assign(n + 1, 0); } // init n + 1 zeroes
ll rsq(ll b) { // returns RSQ(1, b)
ll sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
return sum; } // note: LSOne(S) (S & (-S))
ll rsq(ll a, ll b) { // returns RSQ(a, b)
return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }
// adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
void adjust(int k, ll v) { // note: n = ft.size() - 1
for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; }
};

ll N, Q;
ll a[mxN], b[mxN], c[mxN];

FenwickTree ftA(mxN);
FenwickTree ftB(mxN);

// pair<start index, end index>
struct Segment {
    ll first;
    ll second;
};
struct Compare {
    using is_transparent = void;

    bool operator () (Segment const l, Segment const r) const {
        return l.second < r.first;
    }

    bool operator () (ll const l, Segment const r) const {
        return l < r.first;
    }

    bool operator () (Segment const l, ll const r) const {
        return l.second < r;
    }
};

set<Segment, Compare> overflowSegments;

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin); 
    //freopen((name+".out").c_str(), "w", stdout);
}

// ll findOverflowSegmentIdx(ll idx, ll L, ll R) {
//     ll M = (L + R) / 2;

//     // cout << overflowSegments[M].first << ' ' << overflowSegments[M].second << ' ' << idx << ";\n";

//     ii seg = overflowSegments.begin() + M;
//     if (idx >= overflowSegments[M].first && idx <= overflowSegments[M].second) {
//         return M;
//     } else if (idx > overflowSegments[M].second) {
//         return findOverflowSegmentIdx(idx, M, R);
//     } else {
//         return findOverflowSegmentIdx(idx, 0, M);
//     }
// }

ll findZeroSplitIdx(ll L, ll R) {
    if (L == R) return L;

    ll M = (L + R) / 2;

    ll overflow = ftA.rsq(M) - ftB.rsq(M);

    // cout << "USING " << L << " AND " << R << ", OVERFLOW FROM 0 TO " << M << ": " << overflow << endl;

    if (overflow <= 0) {
        return findZeroSplitIdx(L, M);
    } else {
        return findZeroSplitIdx(M + 1, R);
    }
}

int main () {
    // setIO("1919F1");	

    cin >> N >> Q;

    for (ll i = 1; i <= N; i++) {
        cin >> a[i];
        ftA.adjust(i, a[i]);
    }
    for (ll i = 1; i <= N; i++) {
        cin >> b[i];
        ftB.adjust(i, b[i]);
    }
    for (ll i = 1; i < N; i++) cin >> c[i];

    ll curOverflow = 0, segStartIdx = 1;
    for (ll i = 1; i <= N; i++) {
        curOverflow += a[i] - b[i];
        if (curOverflow <= 0 || i == N) {
            Segment seg; seg.first = segStartIdx; seg.second = i;
            overflowSegments.insert(seg);
            segStartIdx = i + 1;
            curOverflow = 0;
        }
    }

    while (Q--) {
        ll p, x, y, z;
        cin >> p >> x >> y >> z;

        // cout << p << ' ' << x << ' ' << y << ' ' << z << endl;

        ftA.adjust(p, x - a[p]);
        ftB.adjust(p, y - b[p]);

        // if its a net increase in overflow at position p, check if you need to join segments
        if (x - y > a[p] - b[p]) {
            
        }
        a[p] = x;
        b[p] = y;

        // ll segAdjusted = findOverflowSegmentIdx(p, 0, sz(overflowSegments) - 1);

        // cout << "SEG ADJUSTED " << segAdjusted << endl; 

        set<Segment, Compare>::iterator overflowSegIt = overflowSegments.find(p);
        Segment overflowSeg = *overflowSegIt;

        ll newSegBreakpoint = findZeroSplitIdx(overflowSeg.first, overflowSeg.second);

        // cout << "NEW SEG BREAKPOINT " << newSegBreakpoint << endl;

        Segment firstSeg; firstSeg.first = overflowSeg.first; firstSeg.second = newSegBreakpoint;
        // overflowSegments.insert(overflowSegments.begin() + segAdjusted + 1, ii(overflowSeg.first, newSegBreakpoint));
        overflowSegments.insert(firstSeg);
        if (newSegBreakpoint + 1 <= overflowSeg.second) {
            // overflowSegments.insert(overflowSegments.begin() + segAdjusted + 2, ii(newSegBreakpoint + 1, overflowSeg.second));
            Segment secondSeg; secondSeg.first = newSegBreakpoint + 1; secondSeg.second = overflowSeg.second;
            overflowSegments.insert(secondSeg);
        }
        // overflowSegments.erase(overflowSegments.begin() + segAdjusted);

        // cout << "NEW SEGMENTS:" << endl;
        // for (auto it : overflowSegments) cout << it.first << ' ' << it.second << "; ";
        // cout << endl;
        
        // ii lastOverflowSeg = overflowSegments[overflowSegments.size() - 1];
        Segment lastOverflowSeg = *(overflowSegments.rbegin());

        cout << ftA.rsq(1, N) - max(0LL, ftA.rsq(lastOverflowSeg.first, lastOverflowSeg.second) - ftB.rsq(lastOverflowSeg.first, lastOverflowSeg.second)) << '\n';
        // if (Q == 1) break;
    }
}
