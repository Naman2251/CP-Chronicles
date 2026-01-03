/*
Problem: Robin Hood in Town
Link: https://codeforces.com/contest/2014/problem/C
Author: Krishna200608

Short Problem Statement:=>
Find minimum x to add to the richest person so that strictly more than half the population
has wealth less than half the average.

Approach:
    If n <= 2, it's impossible (-1).
    Sort the array. The target person to become "poor" is at index n/2.
    Binary Search for x in range [0, 1e18].
    Condition: 2 * n * a[n/2] < current-sum + x.

Time : O(N log N)
Space Complexity: O(1)
*/

/*
Submission Link:
https://codeforces.com/contest/2014/submission/356175570
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define in(a) for(int i = 0; i<a.size(); i++) cin>>a[i];
typedef vector<int> vi;
typedef vector<ll> vll;

void solve() {
    int n;
    cin >> n;
    vll a(n);

    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    if(n <= 2) {
        cout << "-1\n";
        return;
    }

    sort(a.begin(), a.end());

    ll l = 0, r = 1e18; 
    ll ans = -1;

    while(l <= r) {
        ll mid = l + (r - l) / 2;
        if(2LL * n * a[n/2] < sum + mid) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

