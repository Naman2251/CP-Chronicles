/*
Submission Link: https://codeforces.com/contest/1538/submission/356110702

Instead of finding the pairs to be greater than equal to L, and less than equal to R
I found the pairs that were less than equal to R separately, and less than L separately.
and the answer was the difference of it.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, L, R;
        cin >> n >> L >> R;
        vector<long long> v(n);
        for (auto &x: v) cin >> x;
        sort(v.begin(), v.end());
        long long lteR = 0, ltL = 0;
        
        long long l = 0, r = n-1;
        while (l < r) {
            long long s = v[l] + v[r];
            // 1 2 3 4 5 ; 3-5
            if (s <= R) {
                lteR += r-l;
                l++;
            }
            else {
                r--;
            }
        }
        l = 0, r = n-1;
        while (l < r) {
            long long s = v[l] + v[r];
            // 1 2 3 4 5 ; 3-5
            if (s < L) {
                ltL += r-l;
                l++;
            }
            else {
                r--;
            }
        }
        cout << (lteR - ltL) << endl;
        // cout << lteR << " " << ltL << " " << (lteR - ltL) << endl;
    }
}