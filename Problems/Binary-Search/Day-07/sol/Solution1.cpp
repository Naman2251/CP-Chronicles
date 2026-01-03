//link : https://codeforces.com/problemset/submission/1538/356089286


#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

using ll = long long;
using vi = vector<ll>;

void solve() {
    int n;
    ll l, r;
    cin >> n >> l >> r;

    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ll low = l - a[i];
        ll high = r - a[i];

        int left = lower_bound(a.begin() + i + 1, a.end(), low) - a.begin();
        int right = upper_bound(a.begin() + i + 1, a.end(), high) - a.begin();

        ans += max(0, right - left);
    }

    cout << ans << '\n';
}

int main() {
    fastio

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}



/*

Explaination:
1. Sort the array.
2. For each index i, we want to count indices j > i such that:
      l ≤ a[i] + a[j] ≤ r
   This can be rewritten as:
      l - a[i] ≤ a[j] ≤ r - a[i]
3. Since the array is sorted, use binary search:
   - lower_bound to find the first j where a[j] ≥ (l - a[i])
   - upper_bound to find the first j where a[j] > (r - a[i])
4. The number of valid pairs for index i is (right - left).
5. Sum this for all i.

Complexity:
- Time complexity: O(n log n)
- Space complexity: O(n)

*/