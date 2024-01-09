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

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin); 
    //freopen((name+".out").c_str(), "w", stdout);
}

template<typename T>
struct MinQueue {
    stack< pair<T, T> > s1, s2;
    queue<T> q;

    void push(T a) {
        T mini = s1.empty() ? a : min(a, s1.top().second);
        s1.push(mp(a, mini));
        q.push(a);
    }

    void pop() {
        if (s2.empty()) {
            while (sz(s1)) {
                T element = s1.top().first;
                s1.pop();
                T mini = s2.empty() ? element : min(element, s2.top().second);
                s2.push(mp(element, mini));
            }
        }
        s2.pop();
        q.pop();
    }

    T front() {
        return q.front();
    }

    T back() {
        return q.back();
    }

    T min_val() {
        if (s1.empty() || s2.empty())
            return s1.empty() ? s2.top().second : s1.top().second;
        else 
            return min(s1.top().second, s2.top().second); 
    }

    int size() {
        return sz(s1) + sz(s2);
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main () {

}
