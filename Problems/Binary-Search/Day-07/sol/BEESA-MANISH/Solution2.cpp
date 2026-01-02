/*
Submission link: https://codeforces.com/contest/1777/submission/356097157
- Tc: O(n log n + n√max(a))
- Sc: O(m)

Approach : 
Sort the students by smartness so they are in increasing order.
Use two pointers to form a window of students, adding one student at a time from the right.
Each student can cover some topics, and we keep track of which topics are covered inside the window.
When all topics are covered, try removing students from the left to make the smartness difference as small as possible.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAXA = 100005;
vector<int> divisors[MAXA];
void precompute() {
    for (int i = 1; i < MAXA; i++) {
        for (int j = i; j < MAXA; j += i) {
            divisors[j].push_back(i);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    sort(a.begin(), a.end());
    
    vector<int> count(m + 1, 0);
    int covered_topics = 0;
    int min_diff = 1e9;
    int left = 0;

    for (int right = 0; right < n; right++) {
        for (int d : divisors[a[right]]) {
            if (d > m) break; 
            if (count[d] == 0) covered_topics++;
            count[d]++;
        }
        while (covered_topics == m) {
            min_diff = min(min_diff, a[right] - a[left]);

            for (int d : divisors[a[left]]) {
                if (d > m) break;
                count[d]--;
                if (count[d] == 0) covered_topics--;
            }
            left++;
        }
    }

    if (min_diff == 1e9) cout << -1 << "\n";
    else cout << min_diff << "\n";
}

int main() {
    precompute();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}