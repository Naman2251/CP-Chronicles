#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

/*
PROBLEM STATEMENT:
There are n people living in the town. Just now, the wealth of the i-th person was ai

gold. But guess what? The richest person has found an extra pot of gold!

More formally, find an aj=max(a1,a2,…,an)
, change aj to aj+x, where x

is a non-negative integer number of gold found in the pot. If there are multiple maxima, it can be any one of them.

A person is unhappy if their wealth is strictly less than half of the average wealth∗

.

If strictly more than half of the total population n

are unhappy, Robin Hood will appear by popular demand.

Determine the minimum value of x
for Robin Hood to appear, or output −1 if it is impossible.


APPROACH:
just following the conditions of the ques after sorting the array we get
that x>2*n*a[mid]- sum where mid=n/2 and sum is sum of elements of array;
the reason to sort them was that if the largest element satisfied the condition then all the subsequent
smaller will do so automatically;
and if n==1||n==2 ans would -1 reason simple most of them will be richer
and if x is less than zero ans zero.


TIME COMPLEXITY:O(n +nlogn(for sorting))so O(nlogn);
SPACE COMPLEXITY:O(n);



SUBMISSION LINK:https://codeforces.com/contest/2014/submission/356057548


*/





ll solve(){
	int n;cin>>n;int a[n];ll sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];sum+=a[i];
	}
	if(n==1||n==2)return -1;
	else{
		sort(a,a+n);
		int mid=n/2;
		ll ans=(ll)2*n*a[mid]-sum+1;
		if(ans>0)return ans;
		else return 0;
	}
}

int main(){
    int t;cin>>t;
    while(t--){
    	cout<<solve()<<endl;
    }

	
}
