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

template <class T, std::size_t SZ>
class OffBIT2D {
public:
    /** Record an update (works only before init() is called). */
    void upd(int x, int y, T delta) {
        if (!built_) {
            pending_.emplace_back(x, y);
            deltas_.push_back(delta);          // keep delta in the same order
        } else {
            for (int xi = x; xi < static_cast<int>(SZ); xi += xi & -xi) {
                updateInternal(xi, y, delta);
            }
        }
    }

    /** One-time build: allocate and compress the inner BITs. */
    void init() {
        assert(!built_ && "init() may only be called once");
        built_ = true;

        // Step 1: sort by y so duplicates per x-node can be counted quickly.
        std::vector<std::pair<int, int>> toSort = pending_;
        std::sort(toSort.begin(), toSort.end(),
                  [](const auto& a, const auto& b) { return a.second < b.second; });

        // Step 2: count distinct y's for every x-ancestor.
        std::array<int, SZ> lastY{};
        lastY.fill(0);
        counts_.fill(0);
        for (const auto& [x, y] : toSort) {
            for (int xi = x; xi < static_cast<int>(SZ); xi += xi & -xi) {
                if (lastY[xi] != y) {
                    lastY[xi] = y;
                    ++counts_[xi];
                }
            }
        }

        // Step 3: prefix sum to assign slices inside a single big vector.
        int total = 0;
        for (std::size_t i = 0; i < SZ; ++i) {
            starts_[i] = total;
            total += counts_[i];
        }
        ys_.assign(total, 0);
        bit_.assign(total, T{});

        // Step 4: fill each slice with its sorted y-list (reverse traversal).
        lastY.fill(0);
        for (auto it = pending_.rbegin(); it != pending_.rend(); ++it) {
            int x = it->first, y = it->second;
            for (int xi = x; xi < static_cast<int>(SZ); xi += xi & -xi) {
                if (lastY[xi] != y) {
                    lastY[xi] = y;
                    ys_[--starts_[xi]] = y; // fill from the back so the slice ends sorted
                }
            }
        }

        // Step 5: replay the recorded updates to populate bit_.
        for (std::size_t idx = 0; idx < pending_.size(); ++idx) {
            const auto& [x, y] = pending_[idx];
            T delta = deltas_[idx];
            for (int xi = x; xi < static_cast<int>(SZ); xi += xi & -xi) {
                updateInternal(xi, y, delta);
            }
        }

        // We no longer need the raw logs.
        pending_.clear();
        deltas_.clear();
    }

    /** Rectangle sum: [xl, xr] × [yl, yr]  (inclusive, 1-based). */
    T query(int xl, int xr, int yl, int yr) const {
        assert(built_);
        return prefixQuery(xr, yr) - prefixQuery(xl - 1, yr)
             - prefixQuery(xr, yl - 1) + prefixQuery(xl - 1, yl - 1);
    }

private:
    /* ---------- helpers ---------- */

    /** Rank of y within slice [l, r) (upper_bound – 1-based). */
    static int rank(const std::vector<int>& vec, int y, int l, int r) {
        return static_cast<int>(
            std::upper_bound(vec.begin() + l, vec.begin() + r, y) - (vec.begin() + l));
    }

    /** Inner BIT update for a fixed x-node (1-based y index inside its slice). */
    void updateInternal(int x, int y, T delta) {
        int sliceStart = starts_[x];
        int k = rank(ys_, y, sliceStart, sliceStart + counts_[x]); // local 1-based idx
        for (int idx = k; idx <= counts_[x]; idx += idx & -idx) {
            bit_[sliceStart + idx - 1] += delta;
        }
    }

    /** Inner BIT prefix query for a fixed x-node. */
    T queryInternal(int x, int y) const {
        int sliceStart = starts_[x];
        int k = rank(ys_, y, sliceStart, sliceStart + counts_[x]);
        T res{};
        for (int idx = k; idx > 0; idx -= idx & -idx) {
            res += bit_[sliceStart + idx - 1];
        }
        return res;
    }

    /** 2-D prefix sum over rectangle [1..x] × [1..y]. */
    T prefixQuery(int x, int y) const {
        T res{};
        for (int xi = x; xi > 0; xi -= xi & -xi) {
            res += queryInternal(xi, y);
        }
        return res;
    }

    /* ---------- data members ---------- */

    bool built_ = false;

    std::vector<std::pair<int, int>> pending_; // raw (x,y) pairs recorded pre-build
    std::vector<T>                    deltas_; // matching deltas for pending_

    std::array<int, SZ> counts_{}; // length of each inner y-slice
    std::array<int, SZ> starts_{}; // starting index of each slice in ys_/bit_

    std::vector<int> ys_; // concatenated y-coordinate lists (sorted per slice)
    std::vector<T>   bit_; // concatenated Fenwick arrays (same slicing as ys_)
};

const int mxN = 2e5 + 5;

int T;
int N, Q;

int colors[mxN];

int main () {
    setIO("2126F");	
    cin >> T;
    while (T--) {
	vii adjList[mxN];
	OffBIT2D<int, mxN> bit;	

	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
	    cin >> colors[i];
	}
	for (int i = 0; i < N - 1; i++) {
	    int u, v, c;
	    cin >> u >> v >> c;
	    adjList[u].pb(mp(v, c));
	    adjList[v].pb(mp(u, c));

	    int sortedU = min(u, v);
	    int sortedV = max(u, v);
	    if (colors[sortedU] != colors[sortedV]) {
		bit.upd(sortedU, sortedV, c);
	    }
	}

	bit.init();

	while (Q--) {
	    int v, x;
	    cin >> v >> x;
	    for (auto it : adjList[v]) {

	    }
	}
    }
}
