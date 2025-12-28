#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long mn = *min_element(a.begin(), a.end());
        long long mx = *max_element(a.begin(), a.end());

        long long cntMin = 0, cntMax = 0;

        for (long long x : a) {
            if (x == mn) cntMin++;
            if (x == mx) cntMax++;
        }

        // Each (min, max) and (max, min)
        long long result = cntMin * cntMax * 2;
        cout << result << "\n";
    }

    return 0;
}
