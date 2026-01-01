Submission Link: https://cses.fi/problemset/result/15799460/

/*
-> I made a vector which stores pair(pair(arrival, departue), person no.).
-> I sorted so that person coming first gets room first.
-> I made a priority queue min-heap(element with lower value have higher priority) and stored element as 
   pair(departure, room no.)
-> Now I compared each incoming element with the top one only as it has been emptied first. If a[i].first.first then remove 
   first element and pushed the incoming element and in ans vector put the room else I would add no. of room and push the element 
   in pq and in ans vector put the room. Now I printed rm(no. of room) and vector ans(in which room each person stays). 
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<pair<pair<int,int>,int>>a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i].first.first;
        cin>>a[i].first.second;
        a[i].second=i;
    }
    sort(a.begin(),a.end());
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int rm=1;
    pq.push({a[0].first.second,rm});
    vector <int> ans(n);
    ans[a[0].second]=1;
    for(int i=1;i<n;i++) {
        int d=pq.top().first;
        int r=pq.top().second;
        if(a[i].first.first>d) {
            pq.pop();
            pq.push({a[i].first.second,r});
            ans[a[i].second]=r;
        }  
        else {
            rm++;
            pq.push({a[i].first.second,rm});
            ans[a[i].second]=rm;
        }
    }
    cout<<rm<<endl;
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<endl;
}
