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

int T;

double dist (double Ax, double Ay, double Bx, double By) {
    return sqrt(pow(Ax - Bx, 2) + pow(Ay - By, 2));
}

bool circleContains (double Ox, double Oy, double radius, double Px, double Py) {
    return dist(Ox, Oy, Px, Py) <= radius;
}

int main () {
    // setIO("1886B");	

    cin >> T;
    while (T--) {
        double Px, Py, Ax, Ay, Bx, By;
        cin >> Px >> Py >> Ax >> Ay >> Bx >> By;

        // If only using A (first lantern)

        double distOriginA = dist(Ax, Ay, 0, 0);
        double distHouseA = dist (Ax, Ay, Px, Py);

        bool originContainsHouseA = circleContains(Ax, Ay, distOriginA, Px, Py);
        bool houseContainsOriginA = circleContains(Ax, Ay, distHouseA, 0, 0);

        double ansA;

        if (originContainsHouseA && houseContainsOriginA) {
            ansA = min(distOriginA, distHouseA);
        } else if (originContainsHouseA && !houseContainsOriginA) {
            ansA = distOriginA;
        } else {
            ansA = distHouseA;
        }
        // If only using B (second lantern)

        double distOriginB = dist(Bx, By, 0, 0);
        double distHouseB = dist (Bx, By, Px, Py);

        bool originContainsHouseB = circleContains(Bx, By, distOriginB, Px, Py);
        bool houseContainsOriginB = circleContains(Bx, By, distHouseB, 0, 0);

        double ansB;

        if (originContainsHouseB && houseContainsOriginB) {
            ansB = min(distOriginB, distHouseB);
        } else if (originContainsHouseB && !houseContainsOriginB) {
            ansB = distOriginB;
        } else {
            ansB = distHouseB;
        }
        // If using both

        // radius must be at least half of this
        double distAB = dist(Ax, Ay, Bx, By);

        double ansAB;

        // If B is closer to the origin, then we'll use the distance from A to the house
        if (distOriginA > distOriginB) {
            ansAB = max(distAB / 2, max(distOriginB, distHouseA));
        } else {
            ansAB = max(distAB / 2, max(distOriginA, distHouseB));
        }

        double ans = min(ansAB, min(ansA, ansB));

        cout << setprecision(7) << ans << '\n';
    }
}
