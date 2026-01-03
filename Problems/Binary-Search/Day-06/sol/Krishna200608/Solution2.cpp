/*
====================================================
Problem: Rudolf and Snowflakes (Hard Version)
Link: https://codeforces.com/contest/1846/problem/E2
Author: Krishna Sikheriya (Krishna200608)
====================================================

-------------------------
Short Problem Statement
-------------------------
You are given an integer n.
Your task is to determine whether n can be written as a geometric series:

    n = 1 + k + k² + ... + kᵖ

where:
- k ≥ 2 (the common ratio)
- p ≥ 2 (so the series has at least 3 terms)

In simpler terms, check if n can be formed by summing powers of some integer k,
starting from 1, with at least three terms.

-------------------------
Approach (Length Fixing + Binary Search)
-------------------------
Key Observations:
- The sum of a geometric series is:
      n = (k^(p+1) - 1) / (k - 1)
- Since n ≤ 10¹⁸, the maximum possible exponent is small.
  For example, 2⁶⁰ already exceeds 10¹⁸.

Strategy:
1. Fix the number of terms in the series (terms = p + 1).
   - Minimum terms = 3 (1 + k + k²)
   - Maximum terms ≈ 60 (because 2⁶⁰ > 10¹⁸)
2. For a fixed number of terms:
   - The sum strictly increases as k increases.
   - This allows binary search over possible values of k.
3. For each candidate k, compute the geometric sum safely.
   - Use __int128 to avoid overflow.
   - Stop early if the sum exceeds n.
4. If any combination produces exactly n, output "YES".
   Otherwise, after all checks, output "NO".

-------------------------
Time & Space Complexity
-------------------------
Time Complexity:
- Outer loop over possible terms: O(log n)
- Binary search on k: O(log n)
- Total per test case: O((log n)²)

Space Complexity:
- O(1), only constant extra space is used.

-------------------------
Example I/O (Optional)
-------------------------
Input:
9
1
2
3
6
13
15
255
27
4805

Output:
NO
NO
NO
NO
YES
NO
YES
NO
YES

-------------------------
Submission Link
-------------------------
https://codeforces.com/contest/1846/submission/356083531
====================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Safely computes: 1 + k + k^2 + ... + k^(terms - 1)
// If the sum exceeds 'limit', returns a value greater than limit
__int128 geometric_sum(__int128 k, int terms, __int128 limit) {
    __int128 sum = 1;
    __int128 current = 1;

    for (int i = 1; i < terms; i++) {
        // Prevent overflow while multiplying
        if (current > limit / k) return limit + 1;
        current *= k;

        // Prevent overflow while adding
        if (sum > limit - current) return limit + 1;
        sum += current;
    }
    return sum;
}

void solve() {
    long long n_input;
    cin >> n_input;
    __int128 n = n_input;

    // Smallest valid snowflake: 1 + 2 + 4 = 7
    if (n < 7) {
        cout << "NO\n";
        return;
    }

    // Try all possible lengths of the series (at least 3 terms)
    for (int terms = 3; terms <= 62; terms++) {
        long long low = 2;
        long long high = 2000000000LL; // Safe upper bound for k

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            __int128 val = geometric_sum(mid, terms, n);

            if (val == n) {
                cout << "YES\n";
                return;
            } else if (val < n) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
