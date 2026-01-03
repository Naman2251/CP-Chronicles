//problem link- https://codeforces.com/contest/2014/problem/C
//submission link- https://codeforces.com/contest/2014/submission/356102395
//approach- (sum+x)/2*n needs to be greater than median for valid x
//          so I wrote binary search to find minimum x such that sum+x>median*2*n 
//          as x will follow predicate function(FFFFTTTTTT)
//Time complexity- O(nlogn)









#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define sp << " " <<
#define int long long
#define fora(a) for(auto i:a)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define forn(i,n) for(int i=0; i<n; i++)
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define inputv(a) {for(int i=0;i<n;i++) cin>>a[i];}
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define all(x) x.begin(),x.end()

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}


const int MOD = 1e9 + 7;
ll addMod(ll a, ll b) { return (a + b) % MOD; }
ll subMod(ll a, ll b) { return (a - b + MOD) % MOD; }
ll mulMod(ll a, ll b) { return (a * b) % MOD; }

ll powerMod(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = mulMod(res, a);
        a = mulMod(a, a);
        b >>= 1;
    }
    return res;
}





void solve() {
    int n;
    cin>>n;
    vi a(n);
    inputv(a);
    sort(all(a));
    int sum=accumulate(all(a),0LL);
    if(n==1||n==2){cout<<-1<<endl;return;}
    int low=0;
    int high=2*n*a[n/2];
    while(high-low>=0){
        int mid=low+(high-low)/2;
        if(sum+mid>a[n/2]*2*n){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }


     cout<<low<<endl;
}





signed main() {
    fast_io();
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
