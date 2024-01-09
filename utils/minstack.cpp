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
struct MinStack {
    stack< pair<T, T> > st;
    
    void push(T a) {
        T newMin = st.empty() ? a : min(a, st.top().second);
        st.push(mp(a, newMin));
    }

    void pop() {
        st.pop();
    }

    T top() {
        return st.top().first;
    }

    T min_val() {
        return st.top().second;
    }

    bool empty() {
        return st.empty();
    }

    int size() {
        return st.size();
    }
};

int main () {
    MinStack<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(0);
    a.push(5);
    cout << a.top() << " " << a.min_val() << "\n";
}
