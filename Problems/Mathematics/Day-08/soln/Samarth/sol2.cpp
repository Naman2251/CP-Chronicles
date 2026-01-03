#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

/*
PROBLEM STATMENT:
Arul has a binary array∗ a of length n

.

He will take all subsequences†
of length k (k is odd) of this array and find their median.‡

What is the sum of all these values?

As this sum can be very large, output it modulo 109+7
. In other words, print the remainder of this sum when divided by 109+7.

APPROACH:
to get the ans we just needed the different combinations of sequence where the median would be one;
our ans was nothing but diff combinations so for median one (k+1)/2th element must be one so that means there must atleast (k+1)/2 ones 
and atmost k ones now then we have to calculte no of ways of selecting ones and zero from given ones;

now as we would have to compute ncr many times we used precomputation of fac,and inv fac
to trade off memory for speed.

TIME COMPLEXITY:O(MAXN);
SPACE COMPLEXITY:O(MAXN);

SUBMISSION LINK:
https://codeforces.com/contest/1999/submission/356201034

*/

const ll h=1e9+7;
const ll maxn=2*(1e5)+1;

ll fac[maxn],inv[maxn];

ll binexp(int a,int b){
	if(b==0)return 1;
	
	ll set=binexp(a,b/2);
	
	set=(set*set)%h;
	if (b&1)
		return (set*a)%h;
	else 
		return set;

}


void precomp(){
	fac[0]=1;
	for(int i=1;i<maxn;i++)fac[i]=(fac[i-1]*i)%h;
	inv[maxn-1]=binexp(fac[maxn-1],h-2);
	for(int i=maxn-2;i>=0;i--)inv[i]=(inv[i+1]*(i+1))%h;
}



long long comb(int s,int t){
	ll a= fac[s];
	ll b=inv[s-t];
	ll c=inv[t];
	return (((a*b)%h)*c)%h;
}




void solve(){
	int n,k;cin>>n>>k;int y;int x=0;ll ans=0;
	for(int i=0;i<n;i++){
		cin>>y;
		if(y==1)x++;
	}


	for(int i=max((k+1)/2,k-n+x);i<=min(x,k);i++)
		ans=(ans +(comb(x,i)*comb(n-x,k-i))%h)%h;

	cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	int t;cin>>t;
	precomp();
	while(t--)
		solve();
	
}
