
/*

Submission link: https://codeforces.com/contest/1538/submission/356096805

TC - O(N \log N)
SC - O(N)

Approach :
Sort the numbers first so they are in increasing order. This makes searching easier.
Take one number and look for another number after it such that their sum lies between l and r.
Find the range of numbers that can be added to the current number to stay within l and r.
Count how many numbers fall in that range and add this count to the answer.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long countPairsUnder(const vector<int>& a, int limit) {
    long long count = 0;
    int left = 0;
    int right = a.size() - 1;
    while (left < right) {
        if (a[left] + a[right] <= limit) {
            count += (right - left);
            left++;
        } else {
            right--;
        }
    }
    return count;
}

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long result = countPairsUnder(a, r) - countPairsUnder(a, l - 1);
    cout << result << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}