// link : https://codeforces.com/problemset/submission/2098/356146586

#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define vi vector<int>
 
void solve() {
    int n, k;
    cin >> n >> k;
 
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
 
    sort(a.begin(), a.end());
 
    int L = (n - k - 1) / 2;
    int R = (n + k) / 2;
 
    cout << a[R] - a[L] + 1 << '\n';
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

- The sum f(x) = sum |x - y| is minimized at the median of bar positions.
- Sasha can close at most k bars, which allows the median to shift left or right.
- Sort the bar positions a[], n bars total.
- The leftmost possible median: L = (n - k - 1)/2
- The rightmost possible median: R = (n + k)/2
- Any house between a[L] and a[R] can be chosen.
- Answer = a[R] - a[L] + 1

- Time Complexity: O(n log n) 
- Space: O(n)

*/