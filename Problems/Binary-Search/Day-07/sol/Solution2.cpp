//link : https://codeforces.com/contest/1777/submission/356090789

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

using ll = long long;
using vi = vector<int>;

void solve() {
    int n, m;
    cin >> n >> m;

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    vi cnt(m + 1, 0);
    int covered = 0;

    auto add = [&](int x) {
        for (int d = 1; d * d <= x; d++) {
            if (x % d == 0) {
                if (d <= m) {
                    if (cnt[d] == 0) covered++;
                    cnt[d]++;
                }
                int other = x / d;
                if (other != d && other <= m) {
                    if (cnt[other] == 0) covered++;
                    cnt[other]++;
                }
            }
        }
    };

    auto remove = [&](int x) {
        for (int d = 1; d * d <= x; d++) {
            if (x % d == 0) {
                if (d <= m) {
                    cnt[d]--;
                    if (cnt[d] == 0) covered--;
                }
                int other = x / d;
                if (other != d && other <= m) {
                    cnt[other]--;
                    if (cnt[other] == 0) covered--;
                }
            }
        }
    };

    ll ans = LLONG_MAX;
    int l = 0;

    for (int r = 0; r < n; r++) {
        add(a[r]);

        while (covered == m) {
            ans = min(ans, (ll)a[r] - a[l]);
            remove(a[l]);
            l++;
        }
    }

    if (ans == LLONG_MAX) cout << -1 << '\n';
    else cout << ans << '\n';
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

Approach:
- Sort the students by smartness.
- Use a sliding window (two pointers) on the sorted array.
- A student with smartness x covers all topics T ≤ m such that T divides x.
- Maintain a count array for topics and a variable tracking how many topics
  are currently covered.
- Expand the right pointer to add students, and once all topics are covered,
  shrink from the left to minimize the smartness difference.

Complexity:
- Time: O(n log n + n√max(a))
- Space: O(m)

*/