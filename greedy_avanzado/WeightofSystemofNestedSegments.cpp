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
    ll t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        vector<Node> arr(m);
        for (int i = 1; i <= m; i++)
        {
            ll x,w;cin>>x>>w;
            arr[i-1] = {w,x,i};
        }
        sort(arr.begin(),arr.end());
        vector<Node1> brr;
        ll sum = 0;
        for (int i = 0; i <2*n; i++)
        {
            sum+= arr[i].w;
            brr.push_back({arr[i].x,arr[i].ind});
        }
        sort(brr.begin(),brr.end());
        cout<<sum<<"\n";
        for (int i = 0,j = (2*n)-1; i < n; i++,j--)
        {
            cout<<brr[i].ind<<" "<<brr[j].ind<<"\n";
        }
        
    }

    return 0;
}