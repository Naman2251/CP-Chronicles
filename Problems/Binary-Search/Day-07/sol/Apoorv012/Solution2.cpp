/*

Link: https://codeforces.com/contest/1777/submission/356094799

Approach:
we dont care about duplicates, so keep unique
it is a sliding window problem, we sort them based on their smartness, and have a precomuted array of factors
we go through each one of them, and see if we cover all the topics... 
if we do, we start removing the students to the left side... if less, then add from right side

*/

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
vector<vector<int>> factors(MAX_N);

void generateFactors() {
    for (int x = 2; x < MAX_N; x++) {
        for (int y = x; y < MAX_N; y += x) {
            factors[y].push_back(x);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x: a) cin >> x;

    vector<int> curr(m+1);
    int cnt = 0;

    if (m == 1) {
        cout << 0 << endl;
        return;
    }

    sort(a.begin(), a.end());
    // cout << "sorted a\n";
    auto it = std::unique(a.begin(), a.end());
    a.erase(it, a.end());

    n = a.size();

    int l = 0, r = 0, best = INT_MAX;
    while (r < n) {
        // cout << "l, r: " << l << " " << r << endl;
        for (auto factor: factors[a[r]]) {
            if (factor > m) break;
            if (curr[factor] == 0) cnt++;
            curr[factor]++;
        }
        while (cnt == m-1) {
            best = min(best, a[r] - a[l]);
            for (auto factor: factors[a[l]]) {
                if (factor > m) break;
                curr[factor]--;
                if (curr[factor] == 0) cnt--;
            }
            l++;
        }
        r++;
    }

    // for (auto x: a) cout << x << " ";
    cout << (best == INT_MAX ? -1 : best) << endl;
}

int main() {
    generateFactors();
    // cout << "generated factors\n";

    int t;
    cin >> t;
    while (t--) {
        // cout << "t: " << t << endl;
        solve();
    }
}