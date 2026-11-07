#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
ll guas(ll n){return n*(n+1) /2;}
int main(){
        ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        vll brr(m);
        priority_queue<ll> pI,pP;
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            ll c;cin>>c;
            if(i&1){
                pP.push(c);
            }else{
                pI.push(c);
            }
            sum+=c;
        }
        for (int i = 0; i < m; i++)
        {
            cin>>brr[i];
        }
        bool imp  = 0,par = 0; 
        for (int i = 0; i < m; i++)
        {
            
            if(brr[i]&1){
                if(pI.empty())continue;
                auto x = pI.top();
                if(imp &&x <0)continue;
                imp = 1;
                sum-=x;
                pI.pop();
            }else{
                if(pP.empty())continue;
                auto x = pP.top();
                if(par &&x <0)continue;
                par = 1;
                sum-=x;
                pP.pop();
            }
        }
        cout<<sum<<"\n";
    }   
    return 0;
}