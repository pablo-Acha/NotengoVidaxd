#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll gaus(ll n){return n*(n+1) /2;}
struct Node{
    ll w;
    ll x;
    ll ind;
    bool operator<(const Node& other) const {
        return w < other.w;
    }
};
struct Node1{
    ll x;
    ll ind;
    bool operator<(const Node1& other) const {
        return x < other.x; 
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;cin>>n;
    vll arr(n);for(auto &a:arr)cin>>a;
    priority_queue<ll> pq;
    ll sum = 0;
    ll cnt = 0; 
    for (int i = n - 1; i >= 0; i--)
    {
        if(arr[i]<0){
            pq.push(arr[i]);
        }else{  
            cnt++;
            sum+= arr[i];
        }
        while(!pq.empty() && sum>=(-1*pq.top())){
            sum+=pq.top();
            cnt++;
            pq.pop();
        }
    }
    cout<<cnt<<"\n";
    return 0;
}