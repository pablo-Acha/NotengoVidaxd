#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}

const ll MOD = 998244353;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        priority_queue<ll,vector<ll>,greater<>> arr;
        for (int i = 0; i < n; i++)
        {
            ll a;cin>>a;
            arr.push(a);
        }        
        vll z(m),y(m);
        for(auto &r:z)cin>>r;
        for(auto &r:y)cin>>r;
        priority_queue<pair<ll,ll>,vector<pair<ll, ll>>, greater<pair<ll, ll>>> brr,crr;
        for (int i = 0; i < m; i++)
        {
            ll a = z[i],b = y[i];
            if(b>0){
                brr.emplace(a,b);
            }else{
                crr.emplace(a,b);
            }
        }
        ll res = 0;
        vll aux;
        while(!brr.empty() && !arr.empty()){
            auto [a,b] = brr.top();
            ll x = arr.top();
            arr.pop();
            brr.pop();
            if(x>=a){
                x= max(x,b);
                res++;
                arr.push(x);
            }else{
                aux.push_back(x);
                brr.emplace(a,b);
            }
        }
        for(auto a:aux)arr.push(a);
        
        while(!crr.empty() && !arr.empty()){
            auto [a,b] = crr.top();
            ll x = arr.top();
            arr.pop();
            crr.pop();
            if(x>=a){
                res++;
            }else{

                crr.emplace(a,b);
            }
        }
         cout<<res<<"\n";
    }
    return 0;
}