#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll gaus(ll n){
    if(n<=0)return 0;
    return n*(n+1)/2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while (t--) {
        ll n,k,q;cin>>n>>k>>q;
        vll arr(n);for(auto &a:arr)cin>>a;
        ll res = 0;
        for (int i = 0; i < n;)
        {
            if(arr[i]<=q){
                ll cnt = 0;
                while(i<n && arr[i]<=q){
                    i++;
                    cnt++;
                }
                res+= gaus(cnt-k+1);
            }else{
                i++;
            }
        }
        cout<<res<<"\n";
    }
}