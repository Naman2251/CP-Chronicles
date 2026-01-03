/*
DAY 7
Q1

*/
/*
Sort the array.
Use two-pointers to count pairs with sum ≤ R, and again for sum ≤ L−1.
Answer = count(≤R) − count(≤L−1).
*/

#include <bits/stdc++.h>
using namespace std;
 
long long count_leq(vector<long long>& a, long long x) {
    long long n = a.size(), ans = 0;
    int i = 0, j = n - 1;
    while (i < j) {
        if (a[i] + a[j] <= x) {
            ans += j - i;
            ++i;
        } else {
            --j;
        }
    }
    return ans;
}
 
int main() {
 
 
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long L, R;
        cin >> n >> L >> R;
        vector<long long> a(n);
        for (auto &v : a) cin >> v;
        sort(a.begin(), a.end());
        long long res = count_leq(a, R) - count_leq(a, L - 1);
        cout << res << "\n";
    }
    return 0;
}





// TC = O(nlogn) SC = O(1)
/*
My submission : https://codeforces.com/contest/1538/submission/356103180
*/