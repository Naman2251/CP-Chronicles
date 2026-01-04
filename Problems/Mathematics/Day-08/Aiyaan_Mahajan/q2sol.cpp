/*
DAY 8
Q2 F. Expected Median

*/
/*


For an odd-length subsequence, its median is **1** iff it has at least ((k+1)/2) ones (because the array is binary).
So the answer equals the number of subsequences of length (k) that contain at least ((k+1)/2) ones.
Count subsequences with exactly (t) ones using (\binom{c1}{t}\binom{c0}{k-t}) and sum over all (t \ge (k+1)/2), modulo (10^9+7).


*/
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1'000'000'007;
const int MAXN = 200000 * 2 + 5;

long long fact[MAXN], invfact[MAXN];

long long power(long long a, long long b) {
    long long r = 1;
    while (b) {
        if (b & 1) r = r * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return r;
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}

int main() {
    

    
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) fact[i] = fact[i - 1] * i % MOD;
    invfact[0] = 1;
    invfact[MAXN - 1] = power(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 1; i--)
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int c1 = 0, c0 = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (x) c1++;
            else c0++;
        }

        int m = (k + 1) / 2;
        long long ans = 0;

        for (int t = m; t <= k && t <= c1; t++) {
            ans = (ans + nCr(c1, t) * nCr(c0, k - t)) % MOD;
        }

        cout << ans % MOD << "\n";
    }

    return 0;
}

//Tc =O(n+k) per test  SC = O(n)
/*
My submission : https://codeforces.com/contest/1999/submission/356297537
*/