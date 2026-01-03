/*
DAY 6
Q1 Robin hood in the town
.*/
/*
We need more than half the people to have wealth
< half of the new average.

Adding gold only increases the average, so poor people become “unhappy” first.

So we find the smallest 
𝑥
x such that the poorest majority are still below:
half-average= (S + x)/2*n

Solve for 
x, and if it’s negative → answer is 0.
If 𝑛≤2
 it’s impossible → -1.

That’s it.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        long long S = 0;
        for (auto &x : a) {
            cin >> x;
            S += x;
        }

        if (n <= 2) {
            cout << -1 << '\n';
            continue;
        }

        sort(a.begin(), a.end());
        int m = n / 2 + 1;
        long long v = a[m - 1];

        long long x = 2LL * n * v - S + 1;
        if (x < 0) x = 0;

        cout << x << '\n';
    }
    return 0;
}





//TC =O(Nlog(N)) and SC = O(N)
/*
My submission : https://codeforces.com/contest/2014/submission/356052582
*/