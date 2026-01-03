#include<bits/stdc++.h>
#include<queue>
using namespace std;
typedef unordered_map<int, int> umii;
typedef unordered_map<long long, long long> umll;
typedef unordered_map<char, long long> umci;
typedef vector<pair<int, int>> vpi;
typedef vector<int> vi;
typedef long long ll;
typedef vector<long long> vll;
typedef unordered_map<int , bool> umib;
#define sum(v) accumulate(v.begin(), v.end(), 0)
#define endl '\n'
#define f0(i, n) for(long long i = 0; i < n; i++)
#define f1(i, n) for(long long i = 1; i < n; i++)
#define as(v) sort(v.begin(), v.end())
#define all(x) (x).begin(), (x).end()
#define pb push_back
template<class T> umll frequency(vector<T> &v) {umll freq;for(auto &x:v) freq[x]++; return freq;}
template<class T> umci S_frequency(vector<T> &v) {umci freq;for(auto &x:v) freq[x]++; return freq;}
template <class T> void input(vector<T> &v){for(auto &x:v)cin>>x;}
ll power(ll x, ll y){ ll res = 1; while (y > 0){ if (y & 1) res = (ll)(res*x); y = y>>1; x = (ll)(x*x); } return res; }
void pvll(const vector<long long> &arr){for(auto it : arr){cout << it << " ";}cout << endl;}
void pvi(const vector<int> &arr){for(auto it : arr){cout << it << " ";}cout << endl;}


// SUBMISSION LINK:- https://codeforces.com/contest/1846/submission/356198833


//global set
set<ll>st;

void solve(){

//-------------INPUT-------------
    ll n; 
    cin >> n;
    if(n<3)
    {
        //not possible
        cout << "NO" << endl;
        return;
    }
    ll a = 4*n-3;
    ll sqrt_a = sqrt(a);
    bool flag = false;

    for(ll i=max(0ll,sqrt_a-5);i<=sqrt_a+5;i++)
    {
        if(i*i==a)
        {
            if ((i-1)%2==0 && (i-1)/2 >1) {
            flag=true;
            break;
            }
        }
    }
    // if not found using the formula,check in set
    if(flag || st.count(n))
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
    return;


//-------------CODE--------------
    
// if 4n-3 is a prefect squaare and fint the form (2*k+1)^2

}


int main(){
    //precompute this entire shit

    for(ll k=2;k<=1e6;k++)
    {
        ll sum = k+1;
        ll power = k*k;
        for(ll i=3;i<=63;i++)
        {
            // till 63 only

            sum+=power;
            if(sum>1e18)break;
            st.insert(sum);
            if(power>1e18/ k)break;
            power*=k;
        }
    }
    int tt; cin >> tt; while(tt--)
{solve();};
}

// time complexity  o(nlogn)
