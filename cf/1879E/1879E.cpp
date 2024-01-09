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
const int ASCII_START = 32;

const int mxN = 1e2 + 5;

int N;
vector<vi> adjList;

vi vertexParentColor = vi(mxN);

map<string, int> vertexColorParents;

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin); 
    //freopen((name+".out").c_str(), "w", stdout);
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // setIO("1879E");	

    cin >> N;
    adjList = vector<vi>(N + 1);

    for (int i = 2; i <= N; i++) {
        int p;
        cin >> p;
        adjList[p].pb(i);
    }

    queue<int> q;

    for (auto v : adjList[1]) {
        vertexParentColor[v] = 1;
        cout << "EDGE " << 1 << ' ' << v << ": 1\n";
        q.push(v);
    }

    int numColors = 1;

    while (q.size()) {
        int p = q.front();
        q.pop();

        int parentColor = vertexParentColor[p];
        int childColor = parentColor == 1 ? 2 : 1;
        string vertexColors(mxN, ASCII_START + 101);
        vertexColors[parentColor] = ASCII_START + 1;
        if (adjList[p].size())
            vertexColors[childColor] = ASCII_START + adjList[p].size();

        cout << "COLORS BEFORE:\n";
        for (auto it : vertexColorParents) {
            cout << it.first << ' ' << it.second << '\n';
        }
        cout << '\n';

        while (adjList[p].size() && vertexColorParents[vertexColors] && vertexColorParents[vertexColors] != parentColor) {
            vertexColors[childColor] = ASCII_START + 101;
            do {
                childColor++;
            } while (childColor == parentColor);

            vertexColors[childColor] = ASCII_START + adjList[p].size();
        }

        if (adjList[p].size())
            numColors = max(numColors, childColor);

        vertexColorParents[vertexColors] = parentColor;

        cout << "COLORS AFTER:\n";
        for (auto it : vertexColorParents) {
            cout << it.first << ' ' << it.second << '\n';
        }
        cout << '\n';

        for (auto v : adjList[p]) {
            if (v == p) continue;

            cout << "EDGE " << p << ' ' << v << ": " << childColor << '\n';
            vertexParentColor[v] = childColor;

            q.push(v);
        }
        cout << '\n';
    }

    cout << numColors << '\n';
    for (int i = 2; i <= N; i++) {
        cout << vertexParentColor[i] << ' ';
    }
    cout << '\n' << flush;

    int in;
    while (true) {
        cin >> in;
        if (in == 1 || in == -1) return 0;

        int color;
        vi colors(mxN, 0);
        string colorString(mxN, ASCII_START + 101);

        for (int i = 1; i <= numColors; i++) {
            cin >> colors[i];
        }

        for (int i = 1; i < mxN; i++) {
            if (colors[i] != 0) {
                colorString[i] = ASCII_START + colors[i];
            }
        }

        cout << vertexColorParents[colorString] << '\n' << flush;
    }
}
