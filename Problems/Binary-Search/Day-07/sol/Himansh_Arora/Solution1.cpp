//problem link- https://codeforces.com/problemset/problem/1538/C
//submission link- https://codeforces.com/problemset/submission/1538/356104640
//approach- for every index find a lower index where possible pair value starts and ends unsing binary searches
//time complexity- O(nlogn)
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
    int n,l,r;
    cin>>n>>l>>r;
    vi a(n);
    inputv(a);
    int ans=0;
    sort(all(a));
    for(int i=0;i<n;i++){
        
        auto it=lower_bound(a.begin(),a.begin()+i,l-a[i]);
        int low=-1;
        if (it!=a.begin()+i) {
            low=it-a.begin();
        } 

        it =upper_bound(a.begin(),a.begin()+i,r-a[i]);
        int high=-1;
        if(it!=a.begin()) {
            high=it-a.begin()-1;
        } 
        if(high!=-1&&low!=-1&&high>=low){
            ans+=high-low+1;
        }
    }

     cout<<ans<<endl;
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
