/*
Problem Name: Robin Hood in Town

Short Problem Statement:
There are n people in a town, each having some amount of gold.
The richest person finds an extra pot of gold containing x gold and adds it
to their wealth.

A person is considered unhappy if their wealth is strictly less than
half of the average wealth of all people.

If strictly more than half of the population becomes unhappy,
Robin Hood appears.

The task is to determine the minimum value of x such that Robin Hood appears.
If it is impossible, output -1.

Approach:
1. If n <= 2, it is impossible for more than half of the people to be unhappy,
   so return -1.
2. Sort the array of wealth values.
3. Compute the initial total sum of wealth.
4. Use Binary Search on x (extra gold added to the richest person):
   - For a candidate x, compute the new total wealth.
   - Count how many people have wealth strictly less than half of the average.
   - If unhappy people > n/2, the condition is satisfied.
5. Minimize x using binary search.

Binary search works because increasing x increases the average wealth,
which monotonically increases the number of unhappy people.

Time Complexity:
O(n log M) per test case  
(where M is the search range for x, up to 1e18)

Space Complexity:
O(n)

Question Link:
https://codeforces.com/contest/2014/problem/C

Submission Link:
https://codeforces.com/submissions/amansharma264
*/

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define ll long long
#define endl '\n'

int main() {
    fastio();

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (n <= 2) {
            cout << -1 << endl;
            continue;
        }

        sort(a.begin(), a.end());

        ll sum = 0;
        for (ll x : a) sum += x;

        ll low = 0, high = 1e18, ans = -1;

        while (low <= high) {
            ll mid = low + (high - low) / 2;
            ll totalSum = sum + mid;

            ll unhappy = 0;
            for (ll i = 0; i < n; i++) {
                if (2LL * n * a[i] < totalSum) {
                    unhappy++;
                }
            }

            if (unhappy > n / 2) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
