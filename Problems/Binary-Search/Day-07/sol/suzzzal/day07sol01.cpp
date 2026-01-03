// submisiion link - https://codeforces.com/problemset/submission/1538/356092904

/*
 * APPROACH:
 * First, sort all the numbers from smallest to largest so it's easier to find pairs.
 * Then, for each number, search quickly (using binary search) for other bigger numbers 
 * that can be added to it to make a sum between 'l' and 'r'. Count them up!
 */

 
#include <bits/stdc++.h>
using namespace std;
 
 
void solve() {
    int n;
    long long l, r;
    cin >> n >> l >> r;
 
 
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    sort(a.begin(), a.end());
    long long count = 0;
 
    for (int i = 0; i < n; i++) {
 
        auto start_ptr = a.begin() + i + 1;
        auto end_ptr = a.end();
        auto low = lower_bound(start_ptr, end_ptr, l - a[i]);
        auto high = upper_bound(start_ptr, end_ptr, r - a[i]);
 
        count += (high - low);
 
    }
 
    cout << count << endl;
 
}
 
 
 
int main() {
 
    int t;
    cin >> t;
    while (t--) {
        solve();
 
    }
 
 
 
    return 0;
 
}
