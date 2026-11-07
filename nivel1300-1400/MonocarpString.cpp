#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll f(ll n, string s){
    vll arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] += (s[i] == 'a'?-1:1) + (i>0?arr[i-1]:0);
    }
    map<ll,ll> ultimo;
    
    
    ll r = arr[n-1];
    ll j = n-1;
    ll res = n;
    if(r == 0)return 0;
    for (int i = 0; i < n; i++)
    {   
        if(ultimo.find(arr[i]-r) !=ultimo.end()){
            res = min(i-ultimo[arr[i]-r],res);
        }
        ultimo[arr[i]] = i;
    }
    return res;
}


ll guas(ll n){return n*(n+1) /2;}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        string s;cin>>s;
        string c = s;
        reverse(c.begin(),c.end());
        ll res = min(f(n,s),f(n,c));
        cout<<(res==n?-1:res)<<"\n";
    }
    return 0;
}