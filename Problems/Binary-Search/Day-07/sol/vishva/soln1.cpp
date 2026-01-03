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


// submission link :- 
//https://codeforces.com/contest/1538/submission/352943894
// C_Number_of_Pairs.cpp






void solve(){

//-------------INPUT-------------
    ll n; 
    cin >> n;
    ll l,r;
    cin >> l >> r;
    vll v(n); input(v);
    map<ll,ll>mp1;
    map<ll,ll>mp2;
    map<ll,ll>mp;
    ll count=0;
    as(v);
    vll temp;
    
    for(ll i=0;i<n;i++)
    {
        ll req1 = l-v[i];
        ll a,b;
        ll req2 = r-v[i];
        // apply lowerbound to find req1
        auto it = lower_bound(temp.begin(),temp.end(),req1);

        // using binary search to find the req1 index
    

        if( it!=temp.end() && *it>=req1)
        {
            a = mp[*it];
        }
        else
        {
            a =-1;
        }
        
        //cout << a << endl;

        // if got a particular a then try to find b

        if(a!=-1 && !temp.empty())
        {
            
            auto it = lower_bound(temp.begin(),temp.end(),req2);
            //cout << req2 << " " << mp2[*it] << " " << *it << endl;
            //cout << mp1[*it];
            if(it == temp.end() && !temp.empty())
            {
                b = mp2[*(it-1)]; 
                //cout << "j";
            }
            else if(*it>req2)
            {
                b = mp[*it]-1;
                //cout << "l";
            }
            else{
                b= mp2[*it];
                //cout << "lf";
            }
            if(b>=a)
            {
                // this will be total pairs
                count = count+b-a+1;
            }
        }
        //cout << "b" << " " << b << endl;

        temp.push_back(v[i]);
        if(mp[v[i]]==0 && v[i]!=v[0])
        {

            mp[v[i]] = i;
        }
        mp2[v[i]] = i;
    }
  
    cout << count << endl;



//time complexity o(nlogn)
//-------------CODE--------------
    


}


int main(){
    int tt; cin >> tt; while(tt--)
{solve();};
}
