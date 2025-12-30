/*
Short problem statement:
find for each element find the nearest left poistion having value less than it.

Approach:
maintain a stack with pair of (vlaue, index),
such as for each element if stack is empty(no value less than current) print 0,
else print the index of the left less element.

Complexity:
Time: O(n)
Space: O(n)- for the stack.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define out(x) cout << (x) << endl

void solve()
{
    ll n;
    cin >> n;
    vll a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    stack<pair<ll, ll>> st;
    for (ll i = 0; i < n; i++)
    {
        while (!st.empty() && st.top().first >= a[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            cout << 0 << " ";
        }
        else
        {
            cout << st.top().second + 1 << " ";
        }

        st.push({a[i], i});
    }
    cout << endl;
}

int main()
{
    solve();
}

//submission link: https://cses.fi/problemset/result/15779251/