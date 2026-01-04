/*
Problem: Quiz Master
Link: https://codeforces.com/contest/1777/problem/C
Author: Krishna200608 (github)

/*
Short Problem Statement:
Choose a subset of array 'a' such that every number from 1 to m
divides at least one element in the subset.
Minimize (max element − min element) of the subset.

Approach:
Precompute factors up to 10^5 using a sieve.
Sort the array.
Use two pointers to form a sliding window.
Expand r and mark factors of a[r] that are <= m.
Track how many numbers from 1 to m are covered.
When all are covered, shrink l to minimize (a[r] - a[l]).
Keep updating the minimum difference.

Time Complexity: =>  O(Nlog N + M log M)

Space : O(M log M)
*/

/*
Submission Link:
https://codeforces.com/contest/1777/submission/356174598
*/

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define in(a) for(int i = 0; i<a.size(); i++) cin>>a[i];


const int N = 100005;
vector<int> fact[N];

void init()
{
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            fact[j].push_back(i);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vi a(n);
    in(a);

    sort(a.begin(), a.end());

    vector<int> F(m + 1, 0);
    int c = 0;
    int ans = 1e9;
    int l = 0;

    for (int r = 0; r < n; r++)
    {
        for (int x : fact[a[r]])
        {

            if (x > m)
                break;

            if (F[x] == 0)
                c++;
            F[x]++;
        }

        while (c == m)
        {
            ans = min(ans, a[r] - a[l]);

            for (int x : fact[a[l]])
            {
                if (x > m)
                    break;
                F[x]--;
                if (F[x] == 0)
                    c--;
            }
            l++;
        }
    }

    if (ans == 1e9)
        cout << -1 << "\n";
    else
        cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

