#include <bits/stdc++.h>
#include <unordered_set>
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

int main () {
    setIO("d");	

    /* string target = "zyctznq";
    vector<string> words = { "ctznq", "zy" };
    vector<int> costs = { 13, 3}; */
    string target = "abcdef";
    vector<string> words = { "abdef", "abc", "d", "def", "ef" };
    vector<int> costs = { 100, 1, 1, 10, 5 };

    unordered_map<string, int> wordCosts;
    for (int i = 0; i < (int) words.size(); i++) {
	if (wordCosts.find(words[i]) != wordCosts.end() && wordCosts[words[i]] <= costs[i]) continue;
	wordCosts[words[i]] = costs[i];
    }
    
    unordered_map<int, vector<string>> possiblePostfixes;

    unordered_map<int, unordered_set<string>> wordsLengths;
    for (auto word : words) {
	if (wordsLengths.find((int) word.length()) == wordsLengths.end()) {
	    wordsLengths[(int) word.length()] = unordered_set<string>();
	}
	wordsLengths[(int) word.length()].insert(word);
    }

    for (auto it : wordsLengths) {
	int windowSize = it.first;
	
	string window = target.substr(0, windowSize);
	if (it.second.find(window) != it.second.end()) {
	    if (possiblePostfixes.find(windowSize - 1) == possiblePostfixes.end()) {
		possiblePostfixes[windowSize - 1] = vector<string>();
	    }
	    possiblePostfixes[windowSize - 1].push_back(window);
	}

	for (int i = windowSize; i < (int) target.length(); i++) {
	    // cout << "WINDOW BEF: " << window << '\n';
	    window = window.substr(1);
	    window += target[i];

	    // cout << "WINDOW: " << window << '\n';

	    if (it.second.find(window) != it.second.end()) {
		if (possiblePostfixes.find(i) == possiblePostfixes.end()) {
		    possiblePostfixes[i] = vector<string>();
		}
		possiblePostfixes[i].push_back(window);
	    }
	}
    }

    /* for (auto it : possiblePostfixes) {
	cout << it.first << ":\n";
	for (auto itr : it.second) {
	    cout << itr << ", ";
	}
	cout << '\n';
    } */

    int dp[50005];
    dp[0] = 0;
    for (int i = 1; i < 50005; i++) dp[i] = 1061109567;

    for (int i = 1; i <= (int) target.size(); i++) {
	for (auto postfix : possiblePostfixes[i - 1]) {
	    int prevDp = dp[i - ((int) postfix.size())];
	    if (prevDp == -1) continue;
	    dp[i] = min(dp[i], prevDp + wordCosts[postfix]);
	}
    }

    cout << dp[(int) target.size()] << endl;
}
