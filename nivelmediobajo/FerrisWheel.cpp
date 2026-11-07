#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;

ll gaus(ll n){
    return (n*(n+1))/2;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;cin>>n>>m;
    deque<ll> arr(n);for(auto &a:arr)cin>>a;
    sort(arr.begin(),arr.end());
    ll res = 0;
    while(!arr.empty()){
        auto x = arr[arr.size()-1];
        if(arr.size()!=1 && x+arr[0]<=m){
            arr.pop_front();
        }
        arr.pop_back();
        res++;
    }
    
    cout<<res<<"\n";
    return 0;
}