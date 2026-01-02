
/*
submission link - https://codeforces.com/contest/1999/submission/356191329

TC - O(N+K)
SC - O(N)

Approach 
Count the total number of 1s in the array.
We select k elements such that at least half (more than half) of them are 1s.
So, the number of 1s chosen must be between (k+1)/2 and min(k, total ones).
For each valid choice, pick i 1s from all 1s and k - i 0s from all 0s, and multiply the combinations.
Add all these values to get the answer, using precomputed factorials and inverse factorials for speed
*/

#include <iostream>
#include <vector>

using namespace std;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= 1000000007;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % 1000000007;
        base = (base * base) % 1000000007;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, 1000000007 - 2);
}

long long fact[200005];
long long invFact[200005];

void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        fact[i] = (fact[i - 1] * i) % 1000000007;
        invFact[i] = modInverse(fact[i]);
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return (((fact[n] * invFact[r]) % 1000000007) * invFact[n - r]) % 1000000007;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int c1 = 0, c0 = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 1) c1++;
        else c0++;
    }

    long long ans = 0;
    int min_ones = (k + 1) / 2;

    for (int i = min_ones; i <= min(k, c1); i++) {
        int zeros_needed = k - i;
        if (zeros_needed <= c0) {
            long long ways = (nCr(c1, i) * nCr(c0, zeros_needed)) % 1000000007;
            ans = (ans + ways) % 1000000007;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}