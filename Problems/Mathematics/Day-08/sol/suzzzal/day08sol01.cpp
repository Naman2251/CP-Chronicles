//submission - https://codeforces.com/problemset/submission/2098/356196573


/*
Okay, so first we put all the bar locations in order from smallest to biggest!
Then we look at how many bars we actually keep and find where the middle would be.
We calculate the range between the leftmost possible middle and the rightmost possible middle.
The answer is just counting how many house numbers fit in that space!
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
   
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        
        int m = n - k;
        int idx = (m - 1) / 2;
        
        long long ans = (long long)a[n - 1 - idx] - a[idx] + 1;
        cout << ans << "\n";
    }
    return 0;
}
