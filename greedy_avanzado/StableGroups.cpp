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
        ll n,k,x;cin>>n>>k>>x;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll aux;
        sort(arr.begin(),arr.end());
        for (int i = 1; i < n; i++)
        {
            ll diff = arr[i]-arr[i-1];
            if(diff>x)aux.push_back(diff-1);
        }
        sort(aux.begin(),aux.end());
        ll ind = 0;
        ll cnt = 0;
        for (int i = 0; i < aux.size()&& k; i++)
        {
            ll ref = aux[i]/x;
            if(k<ref){
                break;
            }else{
                cnt++;
                k-= ref;
            }
        }
        cout<<aux.size()-cnt +1<<"\n";
        
    

    return 0;
}