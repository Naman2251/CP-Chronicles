//submission: https://cses.fi/paste/dcc99ae97fc9eb1ef1b84d/

// P.S.: Given salaries of n persons (from 1 to n) and queries in form of !,a,b or ?,a,b. If ! is there, then update salary of a person to a as b, if ? is there then find no.
// of people having salary in range [a,b] and print it
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Core PBDS header
//We use a Policy based Data Structure, specifically: Tree (Red Black) with entries in ascending order so that all operations take logk time
using namespace std;
using namespace __gnu_pbds; // PBDS lives in this namespace

using ll = long long;
#define all(x) (x).begin(), (x).end()

template<class T>
using Tree=tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int inf=1e9+7;
int sal[200005];


void solve() {
    int n,q;
    cin>>n>>q;
    Tree<pair<int,int>> ost;
    for(int i=1;i<=n;i++){
        cin>>sal[i];
        ost.insert({sal[i],i});
    }

    while(q--){
        char c; ll p,r;
        cin>>c>>p>>r;
        if(c=='!'){
            ost.erase({sal[p],p});
            ost.insert({r,p});
            sal[p]=r;
        }
//order_of_key funtion gives elements count less than the element
        else{
            int count_upto_r=ost.order_of_key({r,inf});
            int count_lessthan_p=ost.order_of_key({p,-1});
            cout<<count_upto_r-count_lessthan_p<<endl;
        }
    }
}
// T.C.: O(Q*logn)
//S.C: O(n)
int main() {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
