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
        ll n;cin>>n;

        ll par = 0;
        vll impar;
        for (int i = 0; i < n; i++)
        {
            ll a;cin>>a;
            if(a&1)impar.push_back(a);
            else par++;
        }
        ll res = gaus(n-1)-gaus(n-par-1);
        // cout<<res<<"\n";
        for (int i = 0; i < impar.size(); i++)
        {
            for (int j = i+1; j < impar.size(); j++)
            {
                if(gcd(impar[i],impar[j])>1)res++;   
            }
        }
        cout<<res<<"\n";

    }
        
    

    return 0;
}