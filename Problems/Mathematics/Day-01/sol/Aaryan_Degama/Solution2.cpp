// link : https://codeforces.com/problemset/submission/1225/355484586

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    map<vector<pair<int, int>>, long long> mp;
    long long res = 0;

    for (int x : a) {
        int t = x;
        vector<pair<int, int>> current_factors, required_factors;

        for (int p = 2; p * p <= t; p++) {
            if (t % p == 0) {
                int count = 0;
                while (t % p == 0) {
                    t /= p;
                    count++;
                }
                count %= k;
                if (count > 0) {
                    current_factors.push_back({p, count});
                    required_factors.push_back({p, k - count});
                }
            }
        }

        if (t > 1) {
            int count = 1 % k;
            if (count > 0) {
                current_factors.push_back({t, count});
                required_factors.push_back({t, k - count});
            }
        }

        if (mp.count(required_factors)) {
            res += mp[required_factors];
        }
        
        mp[current_factors]++;
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
